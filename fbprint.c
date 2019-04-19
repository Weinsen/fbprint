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
#include "fbprint.h"
#include <string.h>

icon_t icon_list[] = {
    INCLUDE_ICON(save_logo),
    INCLUDE_ICON(ethernet),
    INCLUDE_ICON(nfc_logo)
};

int main(int argc, char *argv[])
{
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

    int32_t x = 0, y = 0;
    uint32_t i = 0;

    uint8_t header[200];

    const uint8_t *icon_image = save_logo;

    color_t color;
    option_t options = {
        .invert = 0,
        .border = 0,
        .icon = 0
    };

    bitmap_t bitmap;
    window_t window = {
        .x = 0,
        .y = 0,
        .width = 64,
        .height = 64
    };

    // Open the file for reading and writing
    int fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framecolor.rgb device");
        exit(1);
    }
    // printf("The framecolor.rgb device was opened successfully.\n");

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

    long int screensize = finfo.smem_len;

    // Map the device to memory
    char *fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framecolor.rgb device to memory");
        exit(4);
    }
    // printf("The framecolor.rgb device was mapped to memory successfully.\n");

    // Get arguments
    for(i=1; i<argc; i++) {
        if(!strcmp(argv[i], "-c")) {
            color.pixel = (uint32_t)strtol(argv[++i], NULL, 16);
            if (vinfo.bits_per_pixel == 16) {
                x=1;
                color.pix16[0] = ((color.rgb[x++] >> 3) << 0 ) | ((color.rgb[x++] >> 3) << 11 ) | ((color.rgb[x++] >> 2) << 5 );
            }
        } else if(!strcmp(argv[i], "-x")) {
            window.x = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "-y")) {
            window.y = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "-I")) {
            options.invert = 1;
        } else if(!strcmp(argv[i], "-B")) {
            options.border = 1;
        } else if(!strcmp(argv[i], "-f") ) {
            strcpy(header, argv[++i]);
        } else if(!strcmp(argv[i], "-i")) {
            // strcpy(header, argv[++i]);
            i++;
            for (x=0; x<(sizeof(icon_list)/sizeof(icon_t)); x++) {
                if (!strcmp(argv[i], icon_list[x].name)) {
                    icon_image = icon_list[x].img;
                    break;
                }
            }
            options.icon = 1;
        } else if(!strcmp(argv[i], "-v")) {
            printf("Version: %s\r\n", FBP_VERSION);
        }
    }

    if (options.icon) {

        uint32_t index = 0;

        window.height = (icon_image[index++] << 8) | icon_image[index++];
        window.width = (icon_image[index++] << 8) | icon_image[index++];

        x = 0;
        y = 0;
        i = 0;

        long int location = 0;

        for (x = 0; x < window.width; x++) {

            CHECK_X_BONDARIES;

            for (y = 0; y < window.height; y++) {

                location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                           (y+vinfo.yoffset+window.y) * finfo.line_length;

                CHECK_Y_BONDARIES;

                if ( (icon_image[y/8 + (window.height/8)*x + index] & 1<<(y%8)) > 0 ^ options.invert ) {
                    if (vinfo.bits_per_pixel == 32) {
                        if (options.border) {
                            if (IS_BORDER)
                                *(uint32_t *)(fbp + location) = color.pixel;
                        } else {
                            *(uint32_t *)(fbp + location) = color.pixel;
                        }
                    } else {
                        if (options.border) {
                            if (IS_BORDER) {
                                *(uint16_t *)(fbp + location) = color.pix16;
                            }
                        } else {
                            *(uint16_t *)(fbp + location) = color.pix16;
                        }
                    }
                }
                i++;
            }
        }

    } else {

        FILE *img = fopen(header, "rb");
        fread(header, 0x34, 1, img);
        get_bitmap_info(header, &bitmap);

        long int location = 0;

        window.width = bitmap.width;
        window.height = bitmap.height;

        fseek(img, bitmap.offset, SEEK_SET);

        uint8_t step = bitmap.bitcount / 8;

        if (vinfo.bits_per_pixel == 32) {
            for (y = window.height-1; y >= 0 ; y--) {

                CHECK_Y_BONDARIES;

                for (x = 0; x < window.width; x++) {

                    CHECK_X_BONDARIES;

                    fread(color.rgb, step, 1, img);

                    location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                               (y+vinfo.yoffset+window.y) * finfo.line_length;

                    i = 0;

                    if (bitmap.bitcount == 32) {
                        *(fbp + location + 3) = color.rgb[i++];
                        *(fbp + location + 0) = color.rgb[i++];   // Blue
                        *(fbp + location + 1) = color.rgb[i++];   // Red
                        *(fbp + location + 2) = color.rgb[i++];   // Green
                    } else if (bitmap.bitcount == 24) {
                        *(fbp + location + 0) = color.rgb[i++];   // Blue
                        *(fbp + location + 1) = color.rgb[i++];   // Red
                        *(fbp + location + 2) = color.rgb[i++];   // Green
                        *(fbp + location + 3) = 0x00;
                    } else if (bitmap.bitcount == 16) {
                        *(fbp + location + 0) = ((*(uint16_t *)(&color.rgb[i])) & 0x001F) << 3;   // Blue
                        *(fbp + location + 1) = ((*(uint16_t *)(&color.rgb[i])) & 0x07E0) >> 3;   // Red
                        *(fbp + location + 2) = ((*(uint16_t *)(&color.rgb[i])) & 0xF800) >> 8;   // Green
                        *(fbp + location + 3) = 0x00;   // Green
                    }

                }
            }

        } else {
            for (y = window.height-1; y >= 0 ; y--) {

                CHECK_Y_BONDARIES;

                for (x = 0; x < window.width; x++) {

                    CHECK_X_BONDARIES;

                    fread(color.rgb, step, 1, img);

                    location = (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                               (y+vinfo.yoffset+window.y) * finfo.line_length;

                    i = 1;

                    if (bitmap.bitcount == 32) {
                        *((uint16_t*)(fbp + location)) = ((color.rgb[i++] >> 3) << 0 ) | ((color.rgb[i++] >> 3) << 11 ) | ((color.rgb[i++] >> 2) << 5 );
                    } else if (bitmap.bitcount == 24) {
                        *((uint16_t*)(fbp + location)) = ((color.rgb[i++] >> 3) << 0 ) | ((color.rgb[i++] >> 3) << 11 ) | ((color.rgb[i++] >> 2) << 5 );
                    } else if (bitmap.bitcount == 16) {
                        *((uint16_t*)(fbp + location)) = *(uint16_t *)(&color.rgb[i]);
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

