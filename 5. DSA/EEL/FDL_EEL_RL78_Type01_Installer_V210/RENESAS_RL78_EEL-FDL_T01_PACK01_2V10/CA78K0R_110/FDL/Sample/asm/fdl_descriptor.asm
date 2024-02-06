;*******************************************************************************
; Library       : Data Flash Access Library T01
;
; File Name     : $Source: fdl_descriptor.asm $
; Lib. Version  : $RL78_FDL_LIB_VERSION_T01_REN: V1.12 $
; Mod. Revision : $Revision: 1.7 $
; Mod. Date     : $Date: 2013/05/29 10:20:30MESZ $
; Device(s)     : RL78
; Description   : Contains FAL pool descriptor.
;                 Please do not change this file!!!!
;******************************************************************************
; DISCLAIMER
; This software is supplied by Renesas Electronics Corporation and is only
; intended for use with Renesas products. No other uses are authorized. This
; software is owned by Renesas Electronics Corporation and is protected under
; all applicable laws, including copyright laws.
; THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
; THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
; LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
; AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
; TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
; ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
; FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
; ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
; BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
; Renesas reserves the right, without notice, to make changes to this software
; and to discontinue the availability of this software. By using this software,
; you agree to the additional terms and conditions found by accessing the
; following link:
; http://www.renesas.com/disclaimer
;
; Copyright (C) 2011-2013 Renesas Electronics Corporation. All rights reserved.
;*******************************************************************************


 NAME           fdl_descriptor                        ; module name


                                                      ;===========================================
                                                      ; INCLUDE LIST
                                                      ;===========================================
$include    (fdl_descriptor.inc)
                                                      ;===========================================
                                                      ; EXPORT LIST
                                                      ;===========================================
 PUBLIC     fal_descriptor_str                        ; FDL descriptor
 PUBLIC     _fal_descriptor_str                       ;



;=================================================================================================
; Segment name:  FAL_CNST
; Segment type:  CONST, location of the descriptor
;=================================================================================================
FAL_CNST  CSEG  PAGE64KP
;=================================================================================================



; -----------------------------------------------------------------------------------------------------
; ------                                                                                          -----
; ------     B E G I N    O F    U N T O U C H A B L E     D E C L A R A T I O N    A R E A       -----
; ------                                                                                          -----
; -----------------------------------------------------------------------------------------------------

; specify the flash block size expressed in bytes
FAL_BLOCK_SIZE              EQU               (1*1024)


; data flash start and end address
FAL_DATA_FLASH_START_ADDR   EQU               000F1000H
FAL_DATA_FLASH_END_ADDR     EQU               000F1FFFH



; FAL pool configuration

FAL_POOL_FIRST_BLOCK        EQU               0

$_IF ( FAL_POOL_SIZE > 0 )
  FAL_POOL_LAST_BLOCK       EQU               (FAL_POOL_SIZE - 1)
  FAL_POOL_FIRST_ADDRESS    EQU               FAL_DATA_FLASH_START_ADDR
  FAL_POOL_LAST_ADDRESS     EQU               ( FAL_POOL_FIRST_ADDRESS + (FAL_BLOCK_SIZE*FAL_POOL_LAST_BLOCK) + (FAL_BLOCK_SIZE-1) )
  FAL_POOL_WSIZE            EQU               (FAL_POOL_SIZE*FAL_BLOCK_SIZE/4)
  FAL_POOL_FIRST_WIDX       EQU               0
  FAL_POOL_LAST_WIDX        EQU               (FAL_POOL_WSIZE - 1)
  FAL_BLOCK_WSIZE           EQU               (FAL_BLOCK_SIZE/4)
$ELSE
  FAL_POOL_LAST_BLOCK       EQU               0
  FAL_POOL_FIRST_ADDRESS    EQU               0
  FAL_POOL_LAST_ADDRESS     EQU               0
  FAL_POOL_WSIZE            EQU               0
  FAL_POOL_FIRST_WIDX       EQU               0
  FAL_POOL_LAST_WIDX        EQU               0
  FAL_BLOCK_WSIZE           EQU               0
$ENDIF


; EEL pool configuration

  EEL_POOL_FIRST_BLOCK      EQU               0

$_IF ( EEL_POOL_SIZE > 0 )
  EEL_POOL_LAST_BLOCK       EQU               (EEL_POOL_FIRST_BLOCK + EEL_POOL_SIZE - 1)
  EEL_POOL_FIRST_ADDRESS    EQU               FAL_POOL_FIRST_ADDRESS
  EEL_POOL_LAST_ADDRESS     EQU               ( FAL_POOL_FIRST_ADDRESS + ( FAL_BLOCK_SIZE*EEL_POOL_LAST_BLOCK ) + (FAL_BLOCK_SIZE-1) )
  EEL_POOL_WSIZE            EQU               (EEL_POOL_SIZE*FAL_BLOCK_SIZE/4)
  EEL_POOL_FIRST_WIDX       EQU               0
  EEL_POOL_LAST_WIDX        EQU               (EEL_POOL_WSIZE - 1)
$ELSE
  EEL_POOL_LAST_BLOCK       EQU               0
  EEL_POOL_FIRST_ADDRESS    EQU               0
  EEL_POOL_LAST_ADDRESS     EQU               0
  EEL_POOL_WSIZE            EQU               0
  EEL_POOL_FIRST_WIDX       EQU               0
  EEL_POOL_LAST_WIDX        EQU               0
$ENDIF


; USER pool configuration

  USER_POOL_SIZE            EQU               (FAL_POOL_SIZE - EEL_POOL_SIZE)

$_IF ( USER_POOL_SIZE > 0 )
  USER_POOL_FIRST_BLOCK     EQU               0
  USER_POOL_LAST_BLOCK      EQU               (USER_POOL_FIRST_BLOCK + USER_POOL_SIZE - 1)

  $_IF ( EEL_POOL_SIZE > 0 )
    USER_POOL_FIRST_ADDRESS     EQU           (EEL_POOL_LAST_ADDRESS + 1)
  $ELSE
    USER_POOL_FIRST_ADDRESS     EQU           FAL_POOL_FIRST_ADDRESS
  $ENDIF

  USER_POOL_LAST_ADDRESS    EQU               ( USER_POOL_FIRST_ADDRESS + ( FAL_BLOCK_SIZE*USER_POOL_LAST_BLOCK ) + (FAL_BLOCK_SIZE-1) )
  USER_POOL_WSIZE           EQU               (USER_POOL_SIZE*FAL_BLOCK_SIZE/4)
  USER_POOL_FIRST_WIDX      EQU               0
  USER_POOL_LAST_WIDX       EQU               (USER_POOL_WSIZE - 1)
$ELSE
  USER_POOL_FIRST_BLOCK     EQU               0
  USER_POOL_LAST_BLOCK      EQU               0
  USER_POOL_FIRST_ADDRESS   EQU               0
  USER_POOL_LAST_ADDRESS    EQU               0
  USER_POOL_WSIZE           EQU               0
  USER_POOL_FIRST_WIDX      EQU               0
  USER_POOL_LAST_WIDX       EQU               0
$ENDIF


; calculate f_MHz = round-up(FDL_SYSTEM_FREQUENCY)
  FDL_FX_MHZ                EQU               ((FDL_SYSTEM_FREQUENCY+999999)/1000000)


$IF ( FDL_WIDE_VOLTAGE_MODE )
  FDL_VOLTAGE_MODE          EQU               1
$ELSE
  FDL_VOLTAGE_MODE          EQU               0
$ENDIF

;-------------------------------------------------------------------------------------------------
; descriptor
;-------------------------------------------------------------------------------------------------
fal_descriptor_str:
_fal_descriptor_str:
  DW  LOWW(FAL_POOL_FIRST_ADDRESS),HIGHW(FAL_POOL_FIRST_ADDRESS)
  DW  LOWW(EEL_POOL_FIRST_ADDRESS),HIGHW(EEL_POOL_FIRST_ADDRESS)
  DW  LOWW(USER_POOL_FIRST_ADDRESS),HIGHW(USER_POOL_FIRST_ADDRESS)

  DW  LOWW(FAL_POOL_LAST_ADDRESS),HIGHW(FAL_POOL_LAST_ADDRESS)
  DW  LOWW(EEL_POOL_LAST_ADDRESS),HIGHW(EEL_POOL_LAST_ADDRESS)
  DW  LOWW(USER_POOL_LAST_ADDRESS),HIGHW(USER_POOL_LAST_ADDRESS)

  DW  FAL_POOL_FIRST_BLOCK
  DW  EEL_POOL_FIRST_BLOCK
  DW  USER_POOL_FIRST_BLOCK

  DW  FAL_POOL_LAST_BLOCK
  DW  EEL_POOL_LAST_BLOCK
  DW  USER_POOL_LAST_BLOCK

  DW  FAL_POOL_FIRST_WIDX
  DW  EEL_POOL_FIRST_WIDX
  DW  USER_POOL_FIRST_WIDX

  DW  FAL_POOL_LAST_WIDX
  DW  EEL_POOL_LAST_WIDX
  DW  USER_POOL_LAST_WIDX

  DW  FAL_POOL_WSIZE
  DW  EEL_POOL_WSIZE
  DW  USER_POOL_WSIZE

  DW  FAL_BLOCK_SIZE
  DW  FAL_BLOCK_WSIZE

  DB  FAL_POOL_SIZE
  DB  EEL_POOL_SIZE
  DB  USER_POOL_SIZE

  DB  FDL_FX_MHZ
  DB  FDL_VOLTAGE_MODE

  DB  00H

; -----------------------------------------------------------------------------------------------------
; ------                                                                                          -----
; ------     E N D    O F    U N T O U C H A B L E     D E C L A R A T I O N    A R E A           -----
; ------                                                                                          -----
; -----------------------------------------------------------------------------------------------------

  END


