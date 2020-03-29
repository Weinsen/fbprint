#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <string.h>
#include "icons.h"
#include "bitmap.h"
#include "fbprint.h"

#include "Consolas_16.h"

int main(int argc, char *argv[])
{
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

    int32_t x = 0, y = 0;
    uint32_t i = 0;

    uint8_t header[200];

    const uint8_t *icon_image = NULL;

    color_t color, background;
    option_t options = {
        .invert = 0,
        .border = 0,
        .background = 0,
        .rotation = 0,
        #ifdef FB_ICON_SET
            .mode = FB_ICON
        #else
            .mode = FB_IMAGE
        #endif
    };

    bitmap_t bitmap;
    window_t window = {
        .x = 0,
        .y = 0,
        .width = 48,
        .height = 48
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
                color.pix16[0] = ((color.rgb[0] >> 3) << 0 ) | ((color.rgb[2] >> 3) << 11 ) | ((color.rgb[1] >> 2) << 5 );
            }
        } else if(!strcmp(argv[i], "-x")) {
            if(++i>=argc) exit(5);
            window.x = atoi(argv[i]);
        } else if(!strcmp(argv[i], "-y")) {
            if(++i>=argc) exit(5);
            window.y = atoi(argv[i]);
        } else if(!strcmp(argv[i], "-r")) {
            if(++i>=argc) exit(5);
            options.rotation = atoi(argv[i]);
        } else if(!strcmp(argv[i], "-I")) {
            options.invert = 1;
        } else if(!strcmp(argv[i], "-B")) {
            options.border = 1;
        } else if(!strcmp(argv[i], "-F") ) {
            options.mode = FB_FILL;
        } else if(!strcmp(argv[i], "-bg")) {
            options.background = 1;
            if(++i>=argc) exit(5);
            background.pixel = (uint32_t)strtol(argv[++i], NULL, 16);
            if (vinfo.bits_per_pixel == 16) {
                background.pix16[0] = ((background.rgb[0] >> 3) << 0 ) | ((background.rgb[2] >> 3) << 11 ) | ((background.rgb[1] >> 2) << 5 );
            }
        } else if(!strcmp(argv[i], "-f") ) {
            if(++i>=argc) exit(5);
            strcpy(header, argv[i]);
            options.mode = FB_IMAGE;
        } else if(!strcmp(argv[i], "-t") ) {
            if(++i>=argc) exit(5);
            strcpy(header, argv[i]);
            options.mode = FB_TEXT;
        #ifdef FB_ICON_SET
        } else if(!strcmp(argv[i], "-i")) {
            // strcpy(header, argv[++i]);
            if(++i < argc) {
                for (x=0; x<(sizeof(icon_list)/sizeof(icon_t)); x++) {
                    if (!strcmp(argv[i], icon_list[x].name)) {
                        icon_image = icon_list[x].img;
                        break;
                    }
                }
                options.mode = FB_ICON;
            } else {
                printf("Invalid parameters!\n");
                exit(5);
            }
        #endif
        } else if(!strcmp(argv[i], "-v")) {
            printf("Version: %s\r\n", FBP_VERSION);
        }
    }

    if (options.mode == FB_TEXT) {

        uint8_t** font = Consolas_16;
        uint16_t text = 0;

        while(header[text]) {

            icon_image = font[header[text] - 'A'];
            // printf("C:%c I:%d", header[text], header[text] - 'A');

            uint32_t index = 0;

            window.height = (icon_image[index++] << 8) | icon_image[index++];
            window.width = (icon_image[index++] << 8) | icon_image[index++];

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
                            *(uint32_t *)(fbp + location) = color.pixel;
                        } else {
                            *(uint16_t *)(fbp + location) = color.pix16[0];
                        }
                    }
                    i++;
                }
            }

            window.x += window.width;
            text++;
        }

    #ifdef FB_ICON_SET
    } else if (options.mode == FB_ICON) {

        uint32_t index = 0;

        if(!icon_image) {
            printf("Icon not selected! Available options:\r\n");
            for(index=0; index<(sizeof(icon_list) / sizeof(icon_t)); index++) {
                printf("\t- %s\r\n", icon_list[index].name);
            }
            exit(5);
        }

        window.height = (icon_image[index++] << 8) | icon_image[index++];
        window.width = (icon_image[index++] << 8) | icon_image[index++];

        x = 0;
        y = 0;
        i = 0;

        long int location = 0;

        for (x = 0; x < window.width; x++) {

            CHECK_X_BONDARIES;

            for (y = 0; y < window.height; y++) {

                switch (options.rotation) {

                    case 0:
                        location =  (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                                    (y+vinfo.yoffset+window.y) * finfo.line_length;
                        break;

                    case 1:
                        location =  (y+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                                    (window.height-x+vinfo.yoffset+window.y) * finfo.line_length;
                        break;

                    case 2:
                        location =  (window.width-x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                                    (window.height-y+vinfo.yoffset+window.y) * finfo.line_length;
                        break;

                    case 3:
                        location =  (window.width-y+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                                    (x+vinfo.yoffset+window.y) * finfo.line_length;
                        break;

                    case 4:
                        location =  (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                                    (window.height-y+vinfo.yoffset+window.y) * finfo.line_length;
                        break;

                    case 5:
                        location =  (y+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                                    (x+vinfo.yoffset+window.y) * finfo.line_length;
                        break;

                    case 6:
                        location =  (window.width-x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                                    (y+vinfo.yoffset+window.y) * finfo.line_length;
                        break;

                    case 7:
                        location =  (window.width-y+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                                    (window.height-x+vinfo.yoffset+window.y) * finfo.line_length;
                        break;

                    default:
                        location =  (x+vinfo.xoffset+window.x) * (vinfo.bits_per_pixel/8) +
                                    (y+vinfo.yoffset+window.y) * finfo.line_length;
                        break;

                }

                CHECK_Y_BONDARIES;

                if ( (icon_image[y/8 + (window.height/8)*x + index] & 1<<(y%8)) > 0 ^ options.invert ) {
                    if (vinfo.bits_per_pixel == 32) {
                        if (options.border) {
                            if (IS_BORDER)
                                *(uint32_t *)(fbp + location) = color.pixel;
                            else if (options.background)
                                *(uint32_t *)(fbp + location) = background.pixel;
                        } else {
                            *(uint32_t *)(fbp + location) = color.pixel;
                        }
                    } else {
                        if (options.border) {
                            if (IS_BORDER) {
                                *(uint16_t *)(fbp + location) = color.pix16[0];
                            }
                        } else {
                            *(uint16_t *)(fbp + location) = color.pix16[0];
                        }
                    }
                }
                i++;
            }
        }
    #endif

    } else if (options.mode == FB_IMAGE) {

        FILE *img = fopen(header, "rb");
        if(!img) {
            exit(5);
        }

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
                        *(fbp + location + 3) = 0x00;
                    } else if (bitmap.bitcount == 8) {
                        *(fbp + location + 0) = color.rgb[i];   // Blue
                        *(fbp + location + 1) = color.rgb[i];   // Red
                        *(fbp + location + 2) = color.rgb[i];   // Green
                        *(fbp + location + 3) = 0x00;
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
                    } else if (bitmap.bitcount == 8) {
                        *((uint16_t*)(fbp + location)) = ((color.rgb[i] >> 3) << 0 ) | ((color.rgb[i] >> 3) << 11 ) | ((color.rgb[i] >> 2) << 5 );
                    }
                }
            }
        }

        fclose(img);

    } else {

        window.height = vinfo.yres;
        window.width = vinfo.xres;
        window.x = 0;
        window.y = 0;

        x = 0;
        y = 0;
        i = 0;

        long int location = 0;
        long int step = (vinfo.bits_per_pixel/8);

        for (y = 0; y < window.height; y++) {

            // CHECK_Y_BONDARIES;

            for (x = 0; x < window.width; x++) {

                location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                           (y+vinfo.yoffset) * finfo.line_length;

                // CHECK_X_BONDARIES;

                if (vinfo.bits_per_pixel == 32) {
                    *(uint32_t *)(fbp + location) = color.pixel;
                } else {
                    *(uint16_t *)(fbp + location) = color.pix16[0];
                }

            }
        }

    }

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}

