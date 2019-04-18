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

typedef union color_t {
    uint32_t pixel;
    uint8_t rgb[4];
} color_t;

typedef struct option_t {
    uint8_t invert;
    uint8_t border;
} option_t;

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
    color_t color;

    option_t options = {
        .invert = 0,
        .border = 0
    };

    uint8_t icon = 0;
    const uint8_t *icon_image = save_logo;

    window_t window = {
        .x = 0,
        .y = 0,
        .width = 64,
        .height = 64
    };
    bitmap_t bitmap;

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    // printf("The framebuffer device was opened successfully.\n");

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

    screensize = finfo.smem_len;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    // printf("The framebuffer device was mapped to memory successfully.\n");

    // Get arguments
    for(i=1; i<argc; i++) {
        if(!strcmp(argv[i], "--color") || !strcmp(argv[i], "-c")) {
            color.pixel = (uint32_t)strtol(argv[++i], NULL, 16);
        } else if(!strcmp(argv[i], "-x")) {
            window.x = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "-y")) {
            window.y = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "-I")) {
            options.invert = 1;
        } else if(!strcmp(argv[i], "-B")) {
            options.border = 1;
        } else if(!strcmp(argv[i], "--img") || !strcmp(argv[i], "-i") ) {
            strcpy(header, argv[++i]);
        } else if(!strcmp(argv[i], "--icon")) {
            strcpy(header, argv[++i]);
            icon = 1;
        }
    }

    if (icon) {
        if (!strcmp(header, "save")) {
            icon_image = save_logo;
        } else if (!strcmp(header, "nfc")) {
            icon_image = nfc_logo;
        } else if (!strcmp(header, "link")) {
            icon_image = ethernet;
        } else if (!strcmp(header, "img")) {
            icon_image = IMG;
        }
    }

    // printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Save current fb slice on memory
    // unsigned int mem[200][200];
    // for (y = 0; y < window.height; y++) {
    //     for (x = 0; x < window.width; x++) {
    //         location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
    //                    (y+vinfo.yoffset+window.y) * finfo.line_length;
    //         mem[x][y] = *((unsigned int *)(fbp + location)) & 0xFFFFFFFF;
    //     }
    // }
    //
    //

    if (icon) {

        uint32_t index = 0;

        i = 0;

        // const uint8_t *icon_image = IMG;

        window.height = (icon_image[index++] << 8) | icon_image[index++];
        window.width = (icon_image[index++] << 8) | icon_image[index++];

        x = 0;
        y = 0;

        long int max_location = (vinfo.xres+vinfo.xoffset+window.x-1) * (vinfo.bits_per_pixel/8) +
                                (vinfo.yres+vinfo.yoffset+window.y-1) * finfo.line_length;


        while(i < window.width * window.height) {

            location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                       (y+vinfo.yoffset+window.y) * finfo.line_length;

            if ( x + window.x < vinfo.xres && y + window.y < vinfo.yres && x + window.x > 0 && y + window.y > 0) {
                if ( (icon_image[y/8 + (window.height/8)*x + index] & 1<<(y%8)) > 0 ^ options.invert ) {
                    if (vinfo.bits_per_pixel == 32) {
                        if (options.border) {
                            // if (x==0 || x==63 || y==0 || y==63 ||
                            //     !(icon_image[x-1][y/8] & 1<<(y%8)) || !(icon_image[x+1][y/8] & 1<<(y%8)) ||
                            //     !(icon_image[x][(y-1)/8] & 1<<((y-1)%8)) || !(icon_image[x+1][(y+1)/8] & 1<<((y+1)%8))) {
                            //     *(fbp + location + 0) = color.rgb[0] ^ 0x80;   // Blue
                            //     *(fbp + location + 1) = color.rgb[1] ^ 0x80;   // Green
                            //     *(fbp + location + 2) = color.rgb[2] ^ 0x80;   // Red
                            //     *(fbp + location + 3) = 0x00;   // Alpha
                            // }
                        } else {
                            *(fbp + location + 0) = color.rgb[0];   // Blue
                            *(fbp + location + 1) = color.rgb[1];   // Green
                            *(fbp + location + 2) = color.rgb[2];   // Red
                            *(fbp + location + 3) = 0x00;   // Alpha
                        }
                    } else {
                        if (options.border) {
                            // if (x==0 || x==63 || y==0 || y==63 ||
                            //     !(icon_image[x-1][y/8] & 1<<(y%8)) || !(icon_image[x+1][y/8] & 1<<(y%8)) ||
                            //     !(icon_image[x][(y-1)/8] & 1<<((y-1)%8)) || !(icon_image[x+1][(y+1)/8] & 1<<((y+1)%8))) {
                            //     *((unsigned short int*)(fbp + location)) = color.pixel ^ 0x8410;
                            // }
                        } else {
                            *((unsigned short int*)(fbp + location)) = color.pixel;
                        }
                    }
                }
            }

            y++;
            i++;
            if (y >= window.height) {
                y = 0;
                x++;
            }
        }

    } else {

        FILE *img = fopen(header, "rb");
        fread(header, 0x34, 1, img);
        get_bitmap_info(header, &bitmap);

        window.width = bitmap.width;
        window.height = bitmap.height;

        // printf("Bitmap pixels: %d x %d\n", s);

        fseek(img, bitmap.offset, SEEK_SET);

        uint8_t step = bitmap.bitcount / 8;

        if (vinfo.bits_per_pixel == 32) {
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
                        *(fbp + location + 3) = 0x00;
                    } else if (bitmap.bitcount == 16) {
                        *(fbp + location + 0) = ((*(uint16_t *)(&buffer[i])) & 0x001F) << 3;   // Blue
                        *(fbp + location + 1) = ((*(uint16_t *)(&buffer[i])) & 0x07E0) >> 3;   // Red
                        *(fbp + location + 2) = ((*(uint16_t *)(&buffer[i])) & 0xF800) >> 8;   // Green
                        *(fbp + location + 3) = 0x00;   // Green
                    }

                }
            }

        } else {
            for (y = window.height-1; y >= 0 ; y--) {
                for (x = 0; x < window.width; x++) {

                    fread(buffer, step, 1, img);

                    location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                               (y+vinfo.yoffset+window.y) * finfo.line_length;

                    i = 1;

                    if (bitmap.bitcount == 32) {
                        *((uint16_t*)(fbp + location)) = ((buffer[i++] >> 3) << 0 ) | ((buffer[i++] >> 3) << 11 ) | ((buffer[i++] >> 2) << 5 );
                    } else if (bitmap.bitcount == 24) {
                        *((uint16_t*)(fbp + location)) = ((buffer[i++] >> 3) << 0 ) | ((buffer[i++] >> 3) << 11 ) | ((buffer[i++] >> 2) << 5 );
                    } else if (bitmap.bitcount == 16) {
                        *((uint16_t*)(fbp + location)) = *(uint16_t *)(&buffer[i]);
                    }
                }
            }
        }

        fclose(img);

    }

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}

