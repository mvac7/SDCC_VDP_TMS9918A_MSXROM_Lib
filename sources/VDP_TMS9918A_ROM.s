; ============================================================================== 
;  SDCC MSX ROM VDP TMS9918A Functions Library (object type)
;  Version: 1.1
;  Author: mvac7/303bcn
;  Architecture: MSX
;  Format: C Object (SDCC .rel)
;  Programming language: C
;  WEB: 
;  mail: mvac7303b@gmail.com
;
;  Description:
;    Open Source library of functions to work with the TMS9918A video processor
;    using BIOS functions 
;    
;  History of versions:
;    v1.1 (14/02/2014) current version                             
; ============================================================================== 
	.area _DATA


  .area _CODE


;system vars
LINL40 = 0xF3AE ;Screen width per line in SCREEN 0
FORCLR = 0xF3E9 ;Foreground colour
BAKCLR = 0xF3EA ;Background colour
BDRCLR = 0xF3EB ;Border colour 


;BIOS (info by MSX Assembly Page)
;http://map.grauw.nl/resources/msxbios.php
DISSCR = 0x0041 ;inhibits the screen display
ENASCR = 0x0044 ;displays the screen
WRTVDP = 0x0047 ;write data in the VDP-register
RDVRM  = 0x004A ;Reads the content of VRAM
WRTVRM = 0x004D ;Writes data in VRAM
SETRD  = 0x0050 ;Enable VDP to read
SETWRT = 0x0053 ;Enable VDP to write
FILVRM = 0x0056 ;fill VRAM with value
LDIRMV = 0x0059 ;Block transfer to memory from VRAM
LDIRVM = 0x005C ;Block transfer to VRAM from memory
CHGMOD = 0x005F ;Switches to given screenmode
CHGCLR = 0x0062 ;Changes the screencolors
CLRSPR = 0x0069 ;Initialises all sprites
INITXT = 0x006C ;Switches to SCREEN 0 (text screen with 40 * 24 characters)
INIT32 = 0x006F ;Switches to SCREEN 1 (text screen with 32*24 characters)
INIGRP = 0x0072 ;Switches to SCREEN 2 (high resolution screen with 256*192 pixels)
INIMLT = 0x0075 ;Switches to SCREEN 3 (multi-color screen 64*48 pixels)
SETTXT = 0x0078 ;Switches to VDP in SCREEN 0 mode
SETT32 = 0x007B ;Switches VDP in SCREEN mode 1
SETGRP = 0x007E ;Switches VDP to SCREEN 2 mode
SETMLT = 0x0081 ;Switches VDP to SCREEN 3 mode
CALPAT = 0x0084 ;Returns the address of the sprite pattern table
CALATR = 0x0087 ;Returns the address of the sprite attribute table
GSPSIZ = 0x008A ;Returns current sprite size
GRPPRT = 0x008D ;Displays a character on the graphic screen
;




;===============================================================================
; SCREEN
; Sets the screen mode.
;
; void SCREEN(char mode)
; ==============================================================================
_SCREEN::
  push IX
  ld   IX,#0
  add  IX,SP

  ld   A,4(IX)
  or   A
  jr   NZ,setSCR
  
  ;screen 0 > 40 columns mode
  ld   A,#39  ;default value
  ld   (#LINL40),A 
  
  xor  A
  
setSCR:
  call CHGMOD
  
  pop  IX
  ret
    
  

;===============================================================================
; COLOR
; Function : Specifies the ink, foreground and background colors. 
; Input    : (char) - ink color
;            (char) - background color
;            (char) - border color     
;
; void COLOR(char ink, char background, char border)
;===============================================================================
_COLOR::
  push IX
  ld   IX,#0
  add  IX,SP

  ld   A,4(IX)
  ld   (FORCLR),A
  
  ld   A,5(IX)
  ld   (BAKCLR),A
  
  ld   A,6(IX)
  ld   (BDRCLR),A 
  
  call CHGCLR

  pop  IX
  ret



;===============================================================================
; VPOKE
; Function : Writes a byte to the video RAM. 
; Input    : (uint)  - VRAM address
;            (byte) - value 
;
; void VPOKE(uint address, byte value)
;===============================================================================
_VPOKE::
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   L,4(IX)
  ld   H,5(IX)
   
  ld   A,6(IX)
  
  call WRTVRM
  
  pop  IX
  ret



;===============================================================================
; VPEEK
; Function : Reads data from the video RAM. 
; Input    : (uint) - VRAM address
; Output   : (byte) - value
;
; byte VPEEK(uint address)
;===============================================================================
_VPEEK::
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   L,4(IX)
  ld   H,5(IX) 
   
  call RDVRM
  
  ld   L,A
  
  pop  IX
  ret



;===============================================================================
; FillVRAM                                
; Function : Fill a large area of the VRAM of the same byte.
; Input    : (uint) - VRAM address
;            (uint) - length
;            (byte) - value
;
; void FillVRAM (uint vaddress, uint size, byte value)
;===============================================================================
_FillVRAM::
  push IX
  ld   IX,#0
  add  IX,SP
      
  ld   L,4(IX) ; vaddress
  ld   H,5(IX)
    
  ld   C,6(IX) ;length
  ld   B,7(IX)
    
  ld   A,8(IX) ;value
  
  call FILVRM
    
  pop  IX
  ret



;===============================================================================
; CopyToVRAM
; Function : Block transfer from memory to VRAM
; Input    : (uint) - source RAM address 
;            (uint) - target VRAM address
;            (uint) - length
;
; void CopyToVRAM(uint address, uint vaddress, uint length)
;===============================================================================
_CopyToVRAM::
  push IX
  ld   IX,#0
  add  IX,SP 

  ld   L,4(IX) ;ram address 
  ld   H,5(IX)
      
  ld   E,6(IX) ;VRAM address
  ld   D,7(IX)
  
  ld   C,8(IX) ;length
  ld   B,9(IX)
  
  call LDIRVM
  
  pop  IX
  ret



;===============================================================================
; CopyFromVRAM
; Function : Block transfer from VRAM to memory.
; Input    : (uint) - source VRAM address
;            (uint) - target RAM address
;            (uint) - length
;
; void CopyFromVRAM(uint vaddress, uint address, uint length)
;===============================================================================
_CopyFromVRAM::
  push IX
  ld   IX,#0
  add  IX,SP
      
  ld   L,4(IX) ;vaddress
  ld   H,5(IX)
  
  ld   E,6(IX) ;address 
  ld   D,7(IX)     
  
  ld   C,8(IX) ;length
  ld   B,9(IX)
    
  call LDIRMV
    
  pop  IX
  ret
  


;===============================================================================
; SetVDP
; Function : writes a data in VDP register
; Input    : (byte) - VDP reg
;            (byte) - value
;
; void SetVDP(byte, byte)
;===============================================================================
_SetVDP::
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   C,4(IX) ;VDP reg    
  ld   B,5(IX)
  
  call WRTVDP
    
  pop  IX
  ret
