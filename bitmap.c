#include <bitmap.h>

uint32_t little2big(uint8_t* buff, uint8_t len)
{
	if(len == 2)
		return buff[0] | buff[1]<<8;
	if(len == 4)
		return buff[0] | buff[1]<<8 | buff[2]<<16 | buff[3]<<24;
}

void get_bitmap_info(uint8_t *header, bitmap_t *bitmap)
{
	bitmap->size = little2big(&header[2], 4);
	bitmap->offset = little2big(&header[10], 4);
	bitmap->header = little2big(&header[14], 4);
	bitmap->width = little2big(&header[18], 4);
	bitmap->height = little2big(&header[22], 4);
	bitmap->planes = little2big(&header[26], 2);
	bitmap->bitcount = little2big(&header[28], 2);
	bitmap->compression = little2big(&header[30], 4);
}