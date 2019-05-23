# FBPrint

	Print images directly into the frame buffer. Works on embedded Linux!

## Status

	Can print local .bmp files into framebuffer, as well some preconfigured icons.

	Print a text anywhere on the screen.

	Pick a RGB color to your icon or text.

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

**Option** | **Value** | **Description** | **Example**
--- | --- | --- | ---
-c | uint32_t | Color applied to icons | FFED08
-f | Bitmap file | Path to bitmap file | image.bmp
-i | String | Name of icon to use | save_icon
-t | String | Text to be written | "Test text"
-x | int32_t | X position on screen of left-top corner of image | 90
-y | int32_t | Y position on screen of left-top corner of image | 90

**Flags** | **Description**
--- | ---
-B | Border only
-F | Fill screen
-I | Invert filling

## Utils

### bmp2header

Generate a header file containing the converted image. Copy and paste the contents of output.h to your header.

## Log

### v0.2.8

	* Added text support, relies on premade font (-t [TEXT])

### v0.2.7

	* Screen fill flag (-F)

## ToDo

### fbprint

	Fully support 16 and 32 bpp frame buffers.

	Read gif;

	Automatic tool to read bmps on folder and generated custom header files;

	Support system TrueType fonts;

### bmp2header

	Install new icon directly into icon.h;

	Header preview;

	More bmp types for convertion (working with 24BPP only);

## Knows Issues

Arguments are not completely checked before run;
