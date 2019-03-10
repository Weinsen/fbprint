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
    short unsigned int cycle = 0;
    long int location = 0;

    uint8_t i = 0;

    int xpos = 0;
    int ypos = 0;
    int radius = 0;
    unsigned char step = 0;
    short unsigned int count = 0;

    uint8_t color = 0;

    window_t window;
    window.x = 900;
    window.y = 300;
    window.width = 64;
    window.height = 64;

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

    for(i=1; i<argc; i++) {
        if(!strcmp(argv[i], "color")) {
            color = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "x")) {
            window.x = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "y")) {
            window.y = atoi(argv[++i]);
        }
        printf("%s\n", argv[i]);
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



    unsigned int mem[200][200];

    // Save current fb slice on memory
    for (y = 0; y < window.height; y++) {
        for (x = 0; x < window.width; x++) {
            location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                       (y+vinfo.yoffset+window.y) * finfo.line_length;
            mem[x][y] = *((unsigned int *)(fbp + location)) & 0xFFFFFFFF;
        }
    }

    for (y = 0; y < window.height; y++) {
        for (x = 0; x < window.width; x++) {

            location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                       (y+vinfo.yoffset+window.y) * finfo.line_length;

            if (vinfo.bits_per_pixel == 32) {
                if (save_logo[x][y/8] & 1<<(y%8)) {
                    if (x==0 || x==63 || y==0 || y==63 ||
                        !(save_logo[x-1][y/8] & 1<<(y%8)) || !(save_logo[x+1][y/8] & 1<<(y%8)) ||
                        !(save_logo[x][(y-1)/8] & 1<<((y-1)%8)) || !(save_logo[x+1][(y+1)/8] & 1<<((y+1)%8))) {
                        *(fbp + location) = color;        // Some blue
                        *(fbp + location + 1) = 0x00;     // A little green
                        *(fbp + location + 2) = 0x00;    // A lot of red
                        *(fbp + location + 3) = 0x00;      // No transparency
                    } else {
                        *(fbp + location) = color;        // Some blue
                        *(fbp + location + 1) = x + y;     // A little green
                        *(fbp + location + 2) = y;    // A lot of red
                        *(fbp + location + 3) = 0x00;      // No transparency
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

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}