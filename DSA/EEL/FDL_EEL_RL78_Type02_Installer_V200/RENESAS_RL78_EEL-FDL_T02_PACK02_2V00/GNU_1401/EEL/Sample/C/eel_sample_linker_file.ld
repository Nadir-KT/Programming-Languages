/*******************************************************************************
* Library       : EEPROM Emulation Library (T02)
*
* File Name     : $Source: eel_sample_linker_file.ld $
* Lib. Version  : $RL78_EEL_LIB_VERSION_T02_GNU: V1.00 $
* Mod. Revision : $Revision: 1.9 $
* Mod. Date     : $Date: 2014/06/17 11:30:27MESZ $
* Device(s)     : RL78/G13 (R5F100LE)
* Description   : Linker sample file, please modify according to your device
*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

OUTPUT_ARCH(rl78)
ENTRY(_start)

MEMORY
{
    VEC : ORIGIN = 0x0, LENGTH = 4
    IVEC : ORIGIN = 0x4, LENGTH = 188
    OPT : ORIGIN = 0xC0, LENGTH = 4
    SEC_ID : ORIGIN = 0xC4, LENGTH = 10
    OCDSTAD : ORIGIN = 0xCE, LENGTH = 10
    OCDROM : ORIGIN = 0xFE00, LENGTH = 512
    ROM : ORIGIN = 0xD8, LENGTH = 64808
    RAM : ORIGIN = 0xFEF00, LENGTH = 4095
    SADDR (w) : ORIGIN = 0xffe20, LENGTH = 160
}


SECTIONS
{
    .vec 0x0 : AT (0x0)
    {
        KEEP(*(.vec))
    } > VEC
    
    .vects 0x4 : AT (0x4)
    {
        KEEP(*(.vects))
    } > IVEC
    
    .option_bytes 0xC0 : AT (0xC0)
    {
        KEEP(*(.option_bytes))
    } > OPT
    
    .security_id 0xC4 : AT (0xC4)
    {
        KEEP(*(.security_id))
    } > SEC_ID

    FDL_CODE 0xD8 : AT (0xD8)
    {
        *(FDL_CODE)
    } > ROM

    EEL_CODE :
    {
        *(EEL_CODE)
    } > ROM

    .rodata MAX(., 0x2000) : 
    {
        . = ALIGN(2);
        *(.rodata)
        *(.rodata.*)
        _erodata = .;
    } > ROM
    
    FDL_CNST : 
    {
        *(FDL_CNST)
    } > ROM

    EEL_CNST : 
    {
        *(EEL_CNST)
    } > ROM
    
/*******************************************************************************
* .text section is intentionally placed after the constants sections in order
* to ensure correct mapping of constants into the mirror area.
* This approach may leave an unused gap in the ROM area before the mirror area.
* If application requires more ROM, then an additional ROM section might be
* defined before the mirror area, but care should be taken that the constants
* sections .rodata, FDL_CNST and EEL_CNST are mapped inside the mirror area.
*******************************************************************************/
    .text :
    {
        *(.text)
        *(.text.*)
        etext = .;
        . = ALIGN(2);
    } > ROM
    
    .init : 
    {
        *(.init)
    } > ROM
    
    .fini : 
    {
        *(.fini)
    } > ROM
    
    .got : 
    {
        *(.got)
        *(.got.plt)
    } > ROM
    
    .eh_frame_hdr : 
    {
        *(.eh_frame_hdr)
    } > ROM
    
    .eh_frame : 
    {
        *(.eh_frame)
    } > ROM
    
    .jcr : 
    {
        *(.jcr)
    } > ROM
    
    .tors : 
    {
        . = ALIGN(2);
        __CTOR_LIST__ = .;
        ___ctors = .;
        *(.ctors)
        ___ctors_end = .;
        __CTOR_END__ = .;
        __DTOR_LIST__ = .;
        ___dtors = .;
        *(.dtors)
        ___dtors_end = .;
        __DTOR_END__ = .;
        . = ALIGN(2);
        _mdata = .;
    } > ROM
    
    .data 0xFF300 : AT (_mdata)
    {
        . = ALIGN(2);
        _data = .;
        *(.data)
        *(.data.*)
        . = ALIGN(2);
        _edata = .;
    } > RAM
    
    .bss : 
    {
        . = ALIGN(2);
        _bss = .;
        *(.bss)
        *(.bss.**)
        . = ALIGN(2);
        *(COMMON)
        . = ALIGN(2);
        _ebss = .;
        _end = .;
    } > RAM
    
    .stack 0xFFE00 (NOLOAD)  : AT (0xFFE00)
    {
        _stack = .;
    } > RAM
    

    FDL_SDAT (NOLOAD) :
    {
        _FDL_SDAT = .;
    } > SADDR  
    
    EEL_SDAT (NOLOAD) :
    {
       _EEL_SDAT = .;
    } > SADDR  

    .saddr : 
     {
     . = ALIGN(2);
     PROVIDE (__saddrstart = .);
     *(.saddr)
     . = ALIGN(2);
     } >SADDR AT>ROM

}
