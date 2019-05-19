# FBPrint

Print images directly into the frame buffer. Works on embedded Linux also!

## Status

	Can print local .bmp files into framebuffer, as well some preconfigured icons.

	Expand the icon library by using the bmp2header utility.

	CMake compatible.

## Dependencies

	Cmake

## Compilation

Compile the whole project using:

```
$ make
$ sudo make install
```

Use example:

```
$ fbprint -x 200 -y 200 -i save_icon -c F0F0F0
$ fbprint -x 200 -y 200 -f image.bmp
$ fbprint -F -c FF00FF
```

To run, use the tty1 (Ctrl + Alt + F1 on most Linux).

*Will not work on Gnome Terminal*

## Options

**Option** | **Value** | **Description**
--- | --- | ---
-c | uint32_t | Color applied to icons
-f | Bitmap file | Path to bitmap file
-i | String | Name of icon to use
-x | int32_t | X position on screen of left-top corner of image
-y | int32_t | Y position on screen of left-top corner of image

**Flags** | **Description**
--- | ---
-B | Border only
-F | Fill screen
-I | Invert filling

## Utils

### bmp2header

Generate a header file containing the converted image. Copy and paste the contents of output.h to your header.

## ToDo

### fbprint

	Fully support 16 and 32 bpp frame buffers.

	Read gif;

### bmp2header

	Install new icon directly into icon.h;

	Header preview;

	More bmp types for convertion (working with 24BPP only);

## Knows Issues

Arguments are not completely checked before run;
