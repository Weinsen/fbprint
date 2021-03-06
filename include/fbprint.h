#ifndef fbprint_h
#define fbprint_h

#define FBP_VERSION "0.2.8"

#define CHECK_X_BONDARIES if (x + window.x >= vinfo.xres || x + window.x < 0) { continue; }
#define CHECK_Y_BONDARIES if (y + window.y >= vinfo.yres || y + window.y < 0) { continue; }

#define IS_BORDER 	(x==0 || x==window.width-1 || y==0 || y==window.height-1 || \
                   	!(icon_image[y/8 + (window.height/8)*(x-1) + index] & 1<<(y%8)) || !(icon_image[y/8 + (window.height/8)*(x+1) + index] & 1<<(y%8)) || \
                    !(icon_image[(y-1)/8 + (window.height/8)*x + index] & 1<<((y-1)%8)) || !(icon_image[(y+1)/8 + (window.height/8)*x + index] & 1<<((y+1)%8)))

#define INCLUDE_ICON(x) {#x, x}

typedef struct icon_t {
    const uint8_t *name;
    const uint8_t *img;
} icon_t;

enum {
    FB_IMAGE = 0,
    FB_ICON,
    FB_TEXT,
    FB_FILL
};

typedef struct window_t {
    unsigned int x;
    unsigned int y;
    unsigned int height;
    unsigned int width;
    unsigned int row_size;
    unsigned int byte_height;
} window_t;

typedef union color_t {
    uint32_t pixel;
    uint16_t pix16[2];
    uint8_t rgb[4];
} color_t;

typedef struct option_t {
    uint8_t invert;
    uint8_t border;
    uint8_t background;
    uint8_t mode;
    uint8_t rotation;
} option_t;

#endif