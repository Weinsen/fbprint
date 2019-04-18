# FBPrint

Print images directly to the frame buffer.

## Status

	Image is save icon from header.

## ToDo

	Fully support 16 and 32 bpp frame buffers.

	Read bmp;

	Read gif;

## Compilation

Compile using:

```
$ gcc *.c -o fbprint -lm -I ./
$ ./fbprint [args]
```

To run, use the tty1 (Ctrl + Alt + F1 on most Linux).

*Will not work on Gnome Terminal*

## Options

**Option** | **Value** | **Description**
--- | --- | ---
-c | unsigned char | Color applied to icons
-x | integer | X position on screen of left-top corner of image
-y | integer | Y position on screen of left-top corner of image
-f | Bitmap file | Path to bitmap file
--icon | String | Name of icon to use

**Flags** | **Description**
--- | ---
-I | Invert filling
-B | Border only

## Utils

### bmp2header

Generate a header file containing the converted image. Copy and paste the contents of output.h to your header.

```
$ gcc bmp2header.c bitmap.c -I ./ -lm -o bmp2header;
$ ./bmp2header -t [threshhold] -i [bitmap]
```
