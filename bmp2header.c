#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <sys/mman.h>
#include <stdint.h>
#include "bitmap.h"
#include <string.h>

int main(int argc, char *argv[])
{
    long int screensize = 0;
    int x = 0, y = 0;

    uint32_t i = 0;
    uint32_t color = 0;

    uint8_t header[200];
    uint8_t filename[200];
    uint8_t buffer[4];

    uint32_t threshhold = 64;

    bitmap_t bitmap;
    // printf("The framebuffer device was mapped to memory successfully.\n");

    // Get arguments
    for(i=1; i<argc; i++) {
        if(!strcmp(argv[i], "-t")) {
            threshhold = atoi(argv[++i]);
        } else {
            strcpy(filename, argv[i]);
        }
    }

    char *ptr = strstr(filename, ".bmp");
    if(ptr == NULL) {
        printf("File must be 24bpp bmp!\n");
        exit(1);
    }


    FILE *img = fopen(filename, "rb");

    memset(header, 0, sizeof(header));
    memcpy(header, filename, ptr - (char *)filename);
    strcpy(filename, header);

    FILE *head = fopen("output.h", "a");
    fread(header, 0x34, 1, img);
    get_bitmap_info(header, &bitmap);

    fseek(img, bitmap.offset, SEEK_SET);

    uint8_t step = bitmap.bitcount / 8;

    if(bitmap.bitcount != 24) {
        printf("File must be 24bpp bmp!\n");
        exit(1);
    }

    printf("Converting: %s\n", filename);

    sprintf(header, "const uint8_t %s[] = {\r\n", filename);
    fputs(header, head);
    sprintf(header, "\t0x%02x, 0x%02x, 0x%02x, 0x%02x", (bitmap.height >> 8) & 0xFF, bitmap.height & 0xFF, (bitmap.width >> 8) & 0xFF, bitmap.width & 0xFF);
    fputs(header, head);

    uint8_t out[bitmap.width][bitmap.height/8];

    for (y = 0; y < bitmap.height/8; y++) {
        for (x = 0; x < bitmap.width; x++) {
            out[x][y] = 0;
        }
    }

    for (y = bitmap.height-1; y >= 0 ; y--) {
        for (x = 0; x < bitmap.width; x++) {

            fread(buffer, step, 1, img);

            i = 0;
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
    }

    for (x = 0; x < bitmap.width; x++) {
        fputs(",\r\n\t", head);
        for (y = 0; y < bitmap.height/8; y++) {
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

    fclose(img);
    fclose(head);
    return 0;
}

