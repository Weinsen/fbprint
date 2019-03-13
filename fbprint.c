#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include "icon.h"
#include "bitmap.h"
#include <string.h>

typedef struct window_t {
    unsigned int x;
    unsigned int y;
    unsigned int height;
    unsigned int width;
} window_t;

int main(int argc, char *argv[])
{
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    int x = 0, y = 0;
    long int location = 0;

    uint32_t i = 0;

    uint8_t header[200];
    uint8_t buffer[4];
    uint8_t color;

    uint8_t icon = 0;

    window_t window;
    bitmap_t bitmap;

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    // Get arguments
    for(i=1; i<argc; i++) {
        if(!strcmp(argv[i], "color")) {
            color = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "x")) {
            window.x = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "y")) {
            window.y = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "img")) {
            strcpy(header, argv[++i]);
        } else if(!strcmp(argv[i], "icon")) {
            icon = 1;
            i++;
        }
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    // Save current fb slice on memory
    // unsigned int mem[200][200];
    // for (y = 0; y < window.height; y++) {
    //     for (x = 0; x < window.width; x++) {
    //         location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
    //                    (y+vinfo.yoffset+window.y) * finfo.line_length;
    //         mem[x][y] = *((unsigned int *)(fbp + location)) & 0xFFFFFFFF;
    //     }
    // }

    if (icon) {

        window.width = 64;
        window.height = 64;

        for (y = 0; y < window.height; y++) {
            for (x = 0; x < window.width; x++) {

                location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                           (y+vinfo.yoffset+window.y) * finfo.line_length;

                if (vinfo.bits_per_pixel == 32) {
                    if (save_logo[x][y/8] & 1<<(y%8)) {
                        if (x==0 || x==63 || y==0 || y==63 ||
                            !(save_logo[x-1][y/8] & 1<<(y%8)) || !(save_logo[x+1][y/8] & 1<<(y%8)) ||
                            !(save_logo[x][(y-1)/8] & 1<<((y-1)%8)) || !(save_logo[x+1][(y+1)/8] & 1<<((y+1)%8))) {
                            *(fbp + location) = color;      // Blue
                            *(fbp + location + 1) = 0x00;   // Green
                            *(fbp + location + 2) = 0x00;   // Red
                            *(fbp + location + 3) = 0x00;   // Alpha
                        } else {
                            *(fbp + location) = color;      // Blue
                            *(fbp + location + 1) = x + y;  // Green
                            *(fbp + location + 2) = y;      // Red
                            *(fbp + location + 3) = 0x00;   // Alpha
                        }
                    }
                } else {
                    if (save_logo[x][y/8] & 1<<(y%8)) {
                        if (x==0 || x==63 || y==0 || y==63 ||
                            !(save_logo[x-1][y/8] & 1<<(y%8)) || !(save_logo[x+1][y/8] & 1<<(y%8)) ||
                            !(save_logo[x][(y-1)/8] & 1<<((y-1)%8)) || !(save_logo[x+1][(y+1)/8] & 1<<((y+1)%8))) {
                            *((unsigned short int*)(fbp + location)) = 0x10FF;
                        } else {
                            *((unsigned short int*)(fbp + location)) = 0xFFFF;
                        }
                    }
                }
            }
        }

    } else {

        FILE *img = fopen(header, "rb");
        fread(header, 0x34, 1, img);
        get_bitmap_info(header, &bitmap);

        window.width = bitmap.width;
        window.height = bitmap.height;

        printf("Bitmap pixels: %d x %d\n", bitmap.width, bitmap.height);
        printf("BPP: %d\n", bitmap.bitcount);

        uint8_t step = bitmap.bitcount / 8;
        fseek(img, bitmap.offset, SEEK_SET);

        for (y = window.height-1; y >= 0 ; y--) {
            for (x = 0; x < window.width; x++) {

                fread(buffer, step, 1, img);

                location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                           (y+vinfo.yoffset+window.y) * finfo.line_length;

                i = 0;

                if (bitmap.bitcount == 32) {
                    *(fbp + location + 3) = buffer[i++];
                    *(fbp + location + 0) = buffer[i++];   // Blue
                    *(fbp + location + 1) = buffer[i++];   // Red
                    *(fbp + location + 2) = buffer[i++];   // Green
                } else if (bitmap.bitcount == 24) {
                    *(fbp + location + 0) = buffer[i++];   // Blue
                    *(fbp + location + 1) = buffer[i++];   // Red
                    *(fbp + location + 2) = buffer[i++];   // Green
                } else if (bitmap.bitcount == 16) {
                    *(fbp + location + 0) = ((*(uint16_t *)(&buffer[i])) & 0x001F) << 3;   // Blue
                    *(fbp + location + 1) = ((*(uint16_t *)(&buffer[i])) & 0x07E0) >> 3;   // Red
                    *(fbp + location + 2) = ((*(uint16_t *)(&buffer[i])) & 0xF800) >> 8;   // Green
                }

                // printf("Pixel: %d:%d\n", x, y);
            }
        }

        fclose(img);

    }

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}