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
  
Use them for developing MSX applications using Small Device C Compiler (SDCC) compilator.

The source code includes an application to test or learn how to use the library.

This library is part of the [MSX fR3eL Project](https://github.com/mvac7/SDCC_MSX_fR3eL).

Enjoy it!



## History of versions

* v1.1 (14/02/2014) current version
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
* void **COLOR**(char, char, char) - Specifies the ink, foreground and background colors.
* void **VPOKE**(unsigned int, char) - Writes a byte to the video RAM.
* char **VPEEK**(unsigned int) - Reads data from the video RAM.
* void **FillVRAM**(unsigned int, unsigned int, char) - Fill a large area of the VRAM of the same byte.
* void **CopyToVRAM**(unsigned int, unsigned int, unsigned int) - Block transfer from memory to VRAM.
* void **CopyFromVRAM**(unsigned int, unsigned int, unsigned int) - Block transfer from VRAM to memory.
* void **SetVDP**(char, char) - Writes a value in VDP registers.
