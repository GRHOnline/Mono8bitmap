# Mono8bitmap
Convert font data for Atari 8 bit ( probably others too ) . Raw data, monochrome bitmap and assembler code.

The program needs a file called "files.txt" to get the filenames and to set the file types ( see the exe folder for an example ).
Always read / edit this before running.

When loading an image file into the program it expects the following.

Windows Bitmap file format aka .BMP

32 x 256 pixels

Bit depth 1 or 2 colours

Size 1086 bytes

You can generate a test bitmap by setting the the input type as 'W' and the output type as 'M'
