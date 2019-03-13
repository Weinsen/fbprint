# FBPrint

Print images directly to the frame buffer.

## Status

Image is save icon from header.

## ToDo

  Read bmp;
  Read gif;

## Compilation

Compile using:

```
gcc *.c -o fbprint -lm
./fbprint [args]
```

To run, use the tty1 (Ctrl + Alt + F1 on most Linux).
*Will not work on Gnome Terminal*

## Options

**Option** | **Value** | **Description**
--- | --- | ---
color | unsigned char | Color applied to icons
x | integer | X position on screen of left-top corner of image
y | integer | Y position on screen of left-top corner of image

**Flags** | **Description**
--- | ---
icon | Use icon