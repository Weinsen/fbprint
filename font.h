#ifndef font_h
#define font_h

#include <stdint.h>
#include "icon.h"

const uint8_t font_0[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xfe, 0xff, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x80, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0x07, 0x00, 0xfe, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x38, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x38, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf8, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0x07, 0x00, 0xfc, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xfe, 0xff, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t font_1[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x01, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xc0, 0x03, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xe0, 0x03, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xe0, 0x01, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xe0, 0x01, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf8, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
	0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
	0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
	0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t font_2[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x80, 0x07, 0x00, 0xf0, 0x01, 0x00, 0x00,
	0x00, 0xc0, 0x07, 0x00, 0xf8, 0x01, 0x00, 0x00,
	0x00, 0xe0, 0x07, 0x00, 0xfc, 0x01, 0x00, 0x00,
	0x00, 0xe0, 0x07, 0x00, 0xfc, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0x01, 0x00, 0xfe, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0x00, 0x00, 0xff, 0x01, 0x00, 0x00,
	0x00, 0x70, 0x00, 0x80, 0xef, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0xc0, 0xe7, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0xe0, 0xe3, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0xf0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0xf8, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x70, 0x00, 0x7c, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0x00, 0x3c, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0x00, 0x3f, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xe0, 0x83, 0x1f, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xe0, 0xff, 0x07, 0xfe, 0x01, 0x00, 0x00,
	0x00, 0xc0, 0xff, 0x03, 0xfe, 0x01, 0x00, 0x00,
	0x00, 0x00, 0xff, 0x01, 0xfe, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x3c, 0x00, 0xfe, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t font_3[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
	0x00, 0x60, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0x01, 0x00, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x38, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0x3c, 0x80, 0x07, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x3c, 0x80, 0x07, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x3c, 0x80, 0x07, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x3c, 0x80, 0x07, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x38, 0x80, 0x07, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0xc0, 0x07, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0xf8, 0xe0, 0x0f, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0xff, 0x0f, 0xf0, 0x01, 0x00, 0x00,
	0x00, 0xe0, 0xff, 0x3f, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x7f, 0xfe, 0x7f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0xfc, 0x3f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t font_4[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xc0, 0xef, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0xe3, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xfc, 0xe0, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x7e, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0x80, 0x1f, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0xc0, 0x07, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0x03, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0xfc, 0x00, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
	0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
	0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
	0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xe0, 0xe1, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t font_5[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0xff, 0x03, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0xff, 0x07, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf8, 0xff, 0x07, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf8, 0xff, 0x07, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0xc0, 0x03, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0xc0, 0x01, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0xe0, 0x01, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0xe0, 0x01, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0xe0, 0x01, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0xe0, 0x01, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0xe0, 0x01, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0xc0, 0x01, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0xc0, 0x03, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0xc0, 0x07, 0xf0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x80, 0x0f, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x78, 0x00, 0xff, 0x7f, 0x00, 0x00, 0x00,
	0x00, 0x78, 0x00, 0xfe, 0x3f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xfc, 0x0f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t font_6[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0xff, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xfc, 0xff, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x1f, 0x1f, 0xfc, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x87, 0x0f, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0x81, 0x07, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf0, 0x80, 0x03, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0x70, 0xc0, 0x03, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0xc0, 0x03, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x38, 0xc0, 0x03, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x38, 0xc0, 0x03, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x38, 0x80, 0x07, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x3c, 0x80, 0x07, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0xfe, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


const uint8_t font_7[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0xff, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0xe0, 0xff, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00,
	0x00, 0x78, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x78, 0xe0, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x78, 0xfc, 0x1f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t font_8[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x1e, 0xe0, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0xff, 0xf8, 0x7f, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xff, 0xfd, 0xff, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0xff, 0x7f, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0xe0, 0x1f, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x80, 0x1f, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x38, 0x80, 0x0f, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x0f, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x0f, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x0f, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x0f, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x38, 0x80, 0x0f, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x78, 0x80, 0x1f, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0xf8, 0xe0, 0x7f, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xff, 0xf9, 0x7f, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x7f, 0xf0, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x1e, 0x80, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t font_9[] = {
	0x00, 0x40, 0x00, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x3c, 0x00, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x80, 0xff, 0x01, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0xe0, 0xff, 0x03, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0xf0, 0xff, 0x07, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0xf0, 0x81, 0x0f, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x1e, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x1e, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x3c, 0xc0, 0x01, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x3c, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x3c, 0xe0, 0x01, 0x00, 0x00,
	0x00, 0x3c, 0x00, 0x3c, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x38, 0x00, 0x1c, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x1e, 0x78, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0x00, 0x1f, 0x3e, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0x83, 0x8f, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00,
	0x00, 0x80, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xfe, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif
