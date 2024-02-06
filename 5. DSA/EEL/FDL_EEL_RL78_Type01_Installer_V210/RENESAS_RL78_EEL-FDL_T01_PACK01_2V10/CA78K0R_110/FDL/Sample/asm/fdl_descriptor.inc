;*******************************************************************************
; Library       : Data Flash Access Library T01
;
; File Name     : $Source: fdl_descriptor.inc $
; Lib. Version  : $RL78_FDL_LIB_VERSION_T01_REN: V1.12 $
; Mod. Revision : $Revision: 1.7 $
; Mod. Date     : $Date: 2013/05/29 10:20:30MESZ $
; Device(s)     : RL78
; Description   : Contains user configuration of the FAL pool
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



$IF (__FDL_DESCRIPTOR_INC_INCLUDED)

$ELSE
$SET (__FDL_DESCRIPTOR_INC_INCLUDED)


;==============================================================================================
; constant definitions
;==============================================================================================

; specify the CPU frequency in [Hz]
FDL_SYSTEM_FREQUENCY    EQU               20000000

; programming voltage mode
; $SET      FDL_WIDE_VOLTAGE_MODE

; specify the size of the FAL pool expressed in number of blocks
FAL_POOL_SIZE           EQU               4

; specify the size of the EEL pool inside the FAL pool expressed in blocks
EEL_POOL_SIZE           EQU               0


$ENDIF
