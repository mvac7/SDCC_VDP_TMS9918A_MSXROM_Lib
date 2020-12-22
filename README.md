# VDP TMS9918A MSX ROM SDCC Library (fR3eL Project)

```
Author: mvac7 [mvac7303b@gmail.com]
Architecture: MSX
Format: C Object (SDCC .rel)
Programming language: C and Z80 assembler
```

 

## Description

Open Source library with basic functions to work with the TMS9918A video processor.

It uses the functions from the MSX BIOS, so it is designed to create applications in ROM format.

Use them for developing MSX applications using [Small Device C Compiler (SDCC)](http://sdcc.sourceforge.net/) cross compiler.

The source code includes an application to test or learn how to use the library.

If you need specific functions to manage Sprites, you can use any of the following libraries:
- [SPRITES Small](https://github.com/mvac7/SDCC_VDP_SPRITES_S_MSXROM_Lib) - Basic functions for managing Sprites. It is more compact so it takes up less space in our application.
- [SPRITES](https://github.com/mvac7/SDCC_VDP_SPRITES_MSXROM_Lib) - It includes the same functions as the Small version and adds to access specific parameters (positioning, color, pattern, visibility and EarlyClock).
- [SPRITE 1/2](https://github.com/mvac7/SDCC_VDP_SPRITES_12_MSXROM_Lib) - Same as SPRITES but in the G3 screen mode (V9938), it treats the color parameters in a simplified way. Assign the color parameters and EarlyClock to all the lines of the Sprites.
- SPRITE DUMP (In development) - Uses a buffer in RAM that has to be dumped in each interruption. Includes a Sprite Flicker, to allow viewing up to 8 sprites per line.

This library is part of the [MSX fR3eL Project](https://github.com/mvac7/SDCC_MSX_fR3eL).

Enjoy it!



## History of versions

* v1.2 (22/12/2020) Conversion to source in C and added Sprite initialization functions.
* v1.1 (14/02/2014)
* v1.0 (?)



## Requirements

* Small Device C Compiler (SDCC) v3.9 http://sdcc.sourceforge.net/
* Hex2bin v2.5 http://hex2bin.sourceforge.net/ 



## Acknowledgments
  
I want to give a special thanks to all those who freely share their knowledge with the MSX developer community.

* Avelino Herrera > [WEB](http://msx.atlantes.org/index_es.html)
* Nerlaska > [Blog](http://albertodehoyonebot.blogspot.com.es)
* Marq/Lieves!Tuore > [Marq](http://www.kameli.net/marq/) [Lieves!Tuore](http://www.kameli.net/lt/)
* [Fubukimaru](https://github.com/Fubukimaru) > [Blog](http://www.gamerachan.org/fubu/)
* Andrear > [Blog](http://andrear.altervista.org/home/msxsoftware.php)
* Ramones > [MSXblog](https://www.msxblog.es/tutoriales-de-programacion-en-ensamblador-ramones/) - [MSXbanzai](http://msxbanzai.tni.nl/dev/faq.html)
* Sapphire/Z80ST > [WEB](http://z80st.auic.es/)
* Fernando García > [youTube](https://www.youtube.com/user/bitvision)
* Eric Boez > [gitHub](https://github.com/ericb59)
* MSX Assembly Page > [WEB](http://map.grauw.nl/resources/msxbios.php)
* Portar MSX Tech Doc > [WEB](http://nocash.emubase.de/portar.htm)
* MSX Resource Center > [WEB](http://www.msx.org/)
* Karoshi MSX Community (RIP 2007-2020)
* BlueMSX emulator >> [WEB](http://www.bluemsx.com/)
* OpenMSX emulator >> [WEB](http://openmsx.sourceforge.net/)
* Meisei emulator >> ?



## Functions

* void **SCREEN**(char) - Sets the display mode of the screen.
* void **SetSpritesSize**(char size) - Set size type for the sprites.
* void **SetSpritesZoom**(boolean zoom) - Set zoom type for the sprites.
* void **COLOR**(char, char, char) - Specifies the ink, foreground and background colors.
* void **VPOKE**(unsigned int, char) - Writes a byte to the video RAM.
* char **VPEEK**(unsigned int) - Reads data from the video RAM.
* void **FillVRAM**(unsigned int, unsigned int, char) - Fill a large area of the VRAM of the same byte.
* void **CopyToVRAM**(unsigned int, unsigned int, unsigned int) - Block transfer from memory to VRAM.
* void **CopyFromVRAM**(unsigned int, unsigned int, unsigned int) - Block transfer from VRAM to memory.
* void **SetVDP**(char, char) - Writes a value in VDP registers.
