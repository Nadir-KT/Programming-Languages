;******************************************************************************
; Library       : EEPROM Emulation Library (T01)
;
; File Name     : eel_descriptor.asm
; Lib. Version  : V1.15 (for CA78K0R)
; Device(s)     : RL78
; Description   : user defined EEL-variable descriptor
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
; Copyright (C) 2011-2017 Renesas Electronics Corporation. All rights reserved.
;*******************************************************************************

 NAME           EEL_DESCRIPTOR                        ; module name


                                                      ;===========================================
                                                      ; INCLUDE LIST
                                                      ;===========================================
$include    (eel_descriptor.inc)
                                                      ;===========================================
                                                      ; EXPORT LIST
                                                      ;===========================================
 PUBLIC     _eel_descriptor                           ;
 PUBLIC     _eel_refresh_bth_u08                      ;
 PUBLIC     _eel_storage_type_u08                     ;
 PUBLIC     _eel_var_number_u08                       ;
 PUBLIC     _EEL_var_ref                              ;





; ==============================================================================================
;  data definition
; ==============================================================================================
EEL_UDAT    DSEG    BASEP

$_IF ( EEL_STORAGE_TYPE = 'C' )
  _EEL_var_ref: DS  (EEL_VAR_NO * 2)
$ELSE
  _EEL_var_ref: DS  (2)
$ENDIF


;=================================================================================================
; Segment name:  EEL_CNST
; Segment type:  CONST, location of the descriptor
;=================================================================================================
EEL_CNST    CSEG    PAGE64KP
;=================================================================================================

;*******************************************************************************************************
;******                                                                                           ******
;******      B E G I N    O F    C U S T O M I Z A B L E    D E C L A R A T I O N    A R E A      ******
;******                                                                                           ******
;*******************************************************************************************************

; size definition of variables
  VAR_SIZE_A              EQU               2
  VAR_SIZE_B              EQU               3
  VAR_SIZE_C              EQU               4
  VAR_SIZE_D              EQU               5
  VAR_SIZE_E              EQU               6
  VAR_SIZE_F              EQU               10
  VAR_SIZE_X              EQU               20
  VAR_SIZE_Z              EQU               255



; eel descriptor
_eel_descriptor:


;     identifier(1...255),  word-size (1...64),   byte-size (1..255),   RAM-Ref.
; -----------------------------------------------------------------------------------------
  DB  'a',                  (VAR_SIZE_A + 3)/4,   VAR_SIZE_A,           01H
  DB  'b',                  (VAR_SIZE_B + 3)/4,   VAR_SIZE_B,           01H
  DB  'c',                  (VAR_SIZE_C + 3)/4,   VAR_SIZE_C,           01H
  DB  'd',                  (VAR_SIZE_D + 3)/4,   VAR_SIZE_D,           01H
  DB  'e',                  (VAR_SIZE_E + 3)/4,   VAR_SIZE_E,           01H
  DB  'f',                  (VAR_SIZE_F + 3)/4,   VAR_SIZE_F,           01H
  DB  'x',                  (VAR_SIZE_X + 3)/4,   VAR_SIZE_X,           01H
  DB  'z',                  (VAR_SIZE_Z + 3)/4,   VAR_SIZE_Z,           01H
  DB  00H,                                 00H,          00H,           00H

;*******************************************************************************************************
;******                                                                                           ******
;******      E N D    O F    C U S T O M I Z A B L E    D E C L A R A T I O N    A R E A          ******
;******                                                                                           ******
;*******************************************************************************************************





; -----------------------------------------------------------------------------------------------------
; ------                                                                                          -----
; ------     B E G I N    O F    U N T O U C H A B L E     D E C L A R A T I O N    A R E A       -----
; ------                                                                                          -----
; -----------------------------------------------------------------------------------------------------
 _eel_refresh_bth_u08:                    DB  EEL_REFRESH_BLOCK_THRESHOLD
 _eel_storage_type_u08:                   DB  EEL_STORAGE_TYPE
 _eel_var_number_u08:                     DB  EEL_VAR_NO
; -----------------------------------------------------------------------------------------------------
; ------                                                                                          -----
; ------     E N D    O F    U N T O U C H A B L E     D E C L A R A T I O N    A R E A           -----
; ------                                                                                          -----
; -----------------------------------------------------------------------------------------------------


  END


