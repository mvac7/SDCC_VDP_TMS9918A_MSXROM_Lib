# SDCC MSX ROM VDP TMS9918A Functions Library (object type)

Version: 1.1

Author: mvac7/303bcn

Architecture: MSX

Format: C Object (SDCC .rel)

Programming language: C

WEB:
 
mail: mvac7303b@gmail.com




### History of versions:
- v1.1 (14/02/2014) current version


## 1. Introduction

Open Source library with basic functions to work with the TMS9918A video processor.

It uses the functions from the MSX BIOS, so it is designed to create applications in ROM format.
  
Use them for developing MSX applications using Small Device C Compiler (SDCC) compilator.

Include an application for test and learning purposes.



## 2. Acknowledgments
  
Thanks for Info & help, to:

* Avelino Herrera > http://msx.atlantes.org/index_es.html
* Nerlaska > http://albertodehoyonebot.blogspot.com.es
* Fubu > http://www.gamerachan.org/fubu/
* Marq/Lieves!Tuore > http://www.kameli.net/lt/
* Sapphire/Z80ST > http://z80st.auic.es/
* Pentacour > http://pentacour.com/
* JamQue/TPM > http://www.thepetsmode.com/
* Andrear > http://andrear.altervista.org/home/msxsoftware.php
* Konamiman > https://www.konamiman.com
* MSX Assembly Page > http://map.grauw.nl/resources/msxbios.php
* Portar MSX Tech Doc > http://nocash.emubase.de/portar.htm
* MSX Resource Center > http://www.msx.org/
* Karoshi MSX Community > http://karoshi.auic.es/
* BlueMSX >> http://www.bluemsx.com/
* OpenMSX >> http://openmsx.sourceforge.net/
* Meisei  >> ?



## 3. Requirements

* Small Device C Compiler (SDCC) v3.6 http://sdcc.sourceforge.net/
* Hex2bin v2.2 http://hex2bin.sourceforge.net/ 



## 4. Functions

* void SCREEN(char) - Sets the display mode of the screen.
* void COLOR(char, char, char) - Specifies the ink, foreground and background colors.
* void VPOKE(unsigned int, char) - Writes a byte to the video RAM.
* char VPEEK(unsigned int) - Reads data from the video RAM.
* void FillVRAM(unsigned int, unsigned int, char) - Fill a large area of the VRAM of the same byte.
* void CopyToVRAM(unsigned int, unsigned int, unsigned int) - Block transfer from memory to VRAM.
* void CopyFromVRAM(unsigned int, unsigned int, unsigned int) - Block transfer from VRAM to memory.
* void SetVDP(char, char) - Writes a value in VDP registers.
