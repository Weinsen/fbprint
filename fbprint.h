#ifndef fbprint_h
#define fbprint_h

#define CHECK_X_BONDARIES if (x + window.x >= vinfo.xres || x + window.x < 0) { continue; }
#define CHECK_Y_BONDARIES if (y + window.y >= vinfo.yres || y + window.y < 0) { continue; }

#define IS_BORDER 	(x==0 || x==window.width-1 || y==0 || y==window.height-1 || \
                   	!(icon_image[y/8 + (window.height/8)*(x-1) + index] & 1<<(y%8)) || !(icon_image[y/8 + (window.height/8)*(x+1) + index] & 1<<(y%8)) || \
                    !(icon_image[(y-1)/8 + (window.height/8)*x + index] & 1<<((y-1)%8)) || !(icon_image[(y+1)/8 + (window.height/8)*x + index] & 1<<((y+1)%8)))

typedef struct window_t {
    unsigned int x;
    unsigned int y;
    unsigned int height;
    unsigned int width;
} window_t;

typedef union color_t {
    uint32_t pixel;
    uint16_t pix16[2];
    uint8_t rgb[4];
} color_t;

typedef struct option_t {
    uint8_t invert;
    uint8_t border;
    uint8_t icon;
} option_t;

#endif