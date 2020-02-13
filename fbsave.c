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

    window_t window;

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

    // printf("Bitmap pixels: %d x %d\n", bitmap.width, bitmap.height);
    // printf("BPP: %d\n", bitmap.bitcount);

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

    for (y = window.height-1; y >= 0 ; y--) {
        for (x = 0; x < window.width; x++) {

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
            }
        }
    }

    // fclose(img);

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}