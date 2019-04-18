INCLUDE=./include/
CC=gcc
CFLAGS=-I $(INCLUDE) -lm

TARGET=fbprint
SRC=fbprint.c bitmap.c

make:
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

bmp2header:
	$(CC) bitmap.c bmp2header.c -o bmp2header $(CFLAGS)
