#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <sys/mman.h>
#include <stdint.h>
#include <string.h>
#include "bitmap.h"
#include "fbprint.h"

typedef struct options_t {
    uint8_t mode;
} options_t;

enum mode_t {
    MODE_SINGLE,
    MODE_GROUP
};

options_t options = {
    .mode = MODE_SINGLE
};

window_t window = {
    .row_size = 0,
    .byte_height = 0
};

int main(int argc, char *argv[])
{
    long int screensize = 0;
    int x = 0, y = 0;

    uint32_t i = 0;
    uint32_t color = 0;

    uint8_t header[200];
    uint8_t filename[200];

    uint32_t threshhold = 64;

    bitmap_t bitmap;
    // printf("The framebuffer device was mapped to memory successfully.\n");

    // Get arguments
    for(i=1; i<argc; i++) {
        if(!strcmp(argv[i], "-t")) {
            threshhold = atoi(argv[++i]);
        } else if(!strcmp(argv[i], "-G")) {
            options.mode = MODE_GROUP;
        } else {
            strcpy(filename, argv[i]);
        }
    }

    char *ptr = strstr(filename, ".bmp");
    if(ptr == NULL) {
        printf("File must be a bmp file!\n");
        exit(1);
    }


    FILE *img = fopen(filename, "rb");

    memset(header, 0, sizeof(header));
    memcpy(header, filename, ptr - (char *)filename);
    strcpy(filename, header);

    fread(header, 0x34, 1, img);
    get_bitmap_info(header, &bitmap);

    fseek(img, bitmap.offset, SEEK_SET);

    uint8_t step = bitmap.bitcount / 8;

    if(bitmap.bitcount != 24) {
        printf("File must be 24 bpp bmp!\n");
        exit(1);
    }

    printf("Converting: %s\n", filename);

    // Adjust output width to multiples of 8 (byte size)
    window.byte_height = 8 * ((bitmap.height + 7) / 8);
    window.row_size = 4 * ((bitmap.width * bitmap.bitcount + 31) / 32);

    options.mode == MODE_SINGLE;
    FILE *head = NULL;
    if(options.mode == MODE_GROUP) {
        head = fopen("output.h", "a");
    } else {
        if(filename[0] < 'A') {
            sprintf(header, "icon_%s", filename);
            sprintf(filename, "%s", header);
        }
        sprintf(header, "%s.h", filename);
        head = fopen(header, "w");
        sprintf(header, "#ifndef FB_ICON_%s\r\n#define FB_ICON_%s\r\n\r\n", filename, filename);
        fputs(header, head);
    }

    sprintf(header, "const uint8_t %s[] = {\r\n", filename);

    fputs(header, head);
    sprintf(header, "\t0x%02x, 0x%02x, 0x%02x, 0x%02x", (window.byte_height >> 8) & 0xFF, window.byte_height & 0xFF, (bitmap.width >> 8) & 0xFF, bitmap.width & 0xFF);
    fputs(header, head);

    uint8_t out[bitmap.width][window.byte_height/8];

    for (y = 0; y < window.byte_height/8; y++) {
        for (x = 0; x < bitmap.width; x++) {
            out[x][y] = 0;
        }
    }

    printf("%d x %d\r\n", bitmap.width, bitmap.height);
    uint8_t buffer[window.row_size];

    for (y = bitmap.height-1; y >= 0 ; y--) {
        fread(buffer, 1, window.row_size, img);
        i=0;
        for (x = 0; x < bitmap.width; x++) {

            color = 0;

            if (bitmap.bitcount == 24) {
                color += buffer[i++];
                color += buffer[i++];
                color += buffer[i++];
                color /= 3;

                if (color <= threshhold) {
                    out[x][y/8] |= 1<<(y%8);
                }
            }
        }
        printf("\r\n");
    }

    for (x = 0; x < bitmap.width; x++) {
        fputs(",\r\n\t", head);
        for (y = 0; y < window.byte_height/8; y++) {
            if(!y) {
                sprintf(header, "0x%02x", out[x][y]);
                fputs(header, head);
            } else {
                sprintf(header, ", 0x%02x", out[x][y]);
                fputs(header, head);
            }
        }
    }

    fputs("\r\n};\r\n\r\n", head);

    if(options.mode == MODE_SINGLE) {
        fputs("#endif\r\n", head);
    }

    fclose(img);
    fclose(head);
    return 0;
}

