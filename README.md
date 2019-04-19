# FBPrint

Print images directly into the frame buffer. Works on embedded Linux also!

## Status

	Can print local .bmp files into framebuffer, as well some preconfigured icons.

	Expand the icon library by using the bmp2header utility.

## ToDo

### fbprint

	Fully support 16 and 32 bpp frame buffers.

	Read gif;

### bmp2header

	Install new icon directly into icon.h;

	Header preview;

## Compilation

Compile using:

```
$ make
```

Use example:

```
$ ./fbprint -x 200 -y 200 -i save_logo -c F0F0F0
```

To run, use the tty1 (Ctrl + Alt + F1 on most Linux).

*Will not work on Gnome Terminal*

## Options

**Option** | **Value** | **Description**
--- | --- | ---
-c | uint32_t | Color applied to icons
-x | int32_t | X position on screen of left-top corner of image
-y | int32_t | Y position on screen of left-top corner of image
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
$ make bmp2header
```
## Knows Issues

Image mode may result in segmentation fault in some cases;

Arguments are not completely checked before run;
