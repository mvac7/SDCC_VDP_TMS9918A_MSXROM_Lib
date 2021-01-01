/* ============================================================================= 
  VDP TMS9918A MSX ROM SDCC Library (fR3eL Project)
  Version: 1.2 (22/12/2020)
  Author: mvac7 [mvac7303b@gmail.com] 
  Architecture: MSX
  Format: C Object (SDCC .rel)
  Programming language: C and Z80 assembler

  Description:
    Open Source library of functions to work with the TMS9918A video processor
    using BIOS functions 
    
  History of versions:
    v1.2 (22/12/2020) Conversion to source in C and added Sprite initialization 
                      functions.
    v1.1 (14/02/2014) 
    v1.0 (11/02/2014)                             
============================================================================= */ 

#include "../include/msxSystemVars.h"
#include "../include/msxBIOS.h"
#include "../include/VDP_TMS9918A.h"




/* =============================================================================
 SCREEN
 Description: Sets the display mode of the screen. 
 Input      : [char] number of screen mode
 Output     : -
============================================================================= */
void SCREEN(char mode) __naked
{
mode;
__asm
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
__endasm;
}    



/* =============================================================================
 SetSpritesSize
 Description: Set size type for the sprites.
 Input:       [char] size: 0=8x8; 1=16x16
 Output:      -
============================================================================= */ 
void SetSpritesSize(char size) __naked
{
size;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   HL,#RG1SAV ; --- read vdp(1) from mem
  ld   B,(HL)

  ld   A,4(ix)    
  cp   #1
  jr   NZ,size8
  set  1,B ; 16x16
  jr   setSize
  
size8:
  res  1,B  ; 8x8    

setSize:  
  ld   C,#0x01
  call WRTVDP
  
  pop  IX
  ret
__endasm;
}
  


/* =============================================================================
 SetSpritesZoom
 Description: Set zoom type for the sprites.
 Input:       [char] zoom: false/0 = x1; true/1 = x2
 Output:      -
============================================================================= */
void SetSpritesZoom(boolean zoom) __naked
{
zoom;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   HL,#RG1SAV ; --- read vdp(1) from mem
  ld   B,(HL)

  ld   A,4(ix)
  or   A
  jr   Z,nozoom
  set  0,B ; zoom
  jr   setZoom
  
nozoom:
  res  0,B  ;nozoom    

setZoom:  
  ld   C,#0x01
  call WRTVDP
  
  pop  IX
  ret
__endasm;
}

  


/* =============================================================================
 COLOR
 Description: Specifies the ink, foreground and background colors. 
 Input      : [char] ink color
              [char] background color
              [char] border color
 Output     : -     
============================================================================= */
void COLOR(char ink, char background, char border) __naked
{
ink;
background; 
border;
__asm
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
__endasm;
}



/* =============================================================================
 VPOKE
 Description: Writes a byte to the video RAM. 
 Input      : [unsigned int] VRAM address
              [char] value
 Output     : - 
============================================================================= */
void VPOKE(unsigned int vaddr, char value) __naked
{
vaddr;
value;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   L,4(IX)
  ld   H,5(IX)
   
  ld   A,6(IX)
  
  call WRTVRM
  
  pop  IX
  ret
__endasm;
}



/* =============================================================================
 VPEEK
 Description: Reads data from the video RAM. 
 Input      : [unsigned int] VRAM address
 Output     : [char] value
============================================================================= */ 
char VPEEK(unsigned int vaddr) __naked
{
vaddr;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   L,4(IX)
  ld   H,5(IX) 
   
  call RDVRM
  
  ld   L,A
  
  pop  IX
  ret
__endasm;
}



/* =============================================================================
 FillVRAM                               
 Description: Fill a large area of the VRAM of the same byte.
 Input      : [unsigned int] address of VRAM
              [unsigned int] blocklength
              [char] Value to fill.
 Output     : - 
============================================================================= */
void FillVRAM(unsigned int vaddr, unsigned int length, char value) __naked
{
vaddr;
length;
value;
__asm
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
__endasm;
}



/* =============================================================================
 CopyToVRAM
 Description: Block transfer from memory to VRAM 
 Input      : [unsigned int] address of RAM
              [unsigned int] address of VRAM
              [unsigned int] blocklength
 Output     : - 
============================================================================= */
void CopyToVRAM(unsigned int addr, unsigned int vaddr, unsigned int length) __naked
{
addr;
vaddr;
length;
__asm
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
__endasm;
}



/* =============================================================================
 CopyFromVRAM
 Description: Block transfer from VRAM to memory
 Input      : [unsigned int] address of VRAM                     
              [unsigned int] address of RAM
              [unsigned int] blocklength
 Output     : -             
============================================================================= */
void CopyFromVRAM(unsigned int vaddr, unsigned int addr, unsigned int length)
{
vaddr;
addr;
length;
__asm
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
  
__endasm;
}
  


/* =============================================================================
 SetVDP
 Description: Writes a value in VDP registers
 Input      : [char] VDP register                     
              [char] value
 Output     : -             
============================================================================= */
void SetVDP(char reg, char value)
{
reg;
value;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   C,4(IX) ;VDP reg    
  ld   B,5(IX)
  
  call WRTVDP
    
  pop  IX
  ret

__endasm;
}