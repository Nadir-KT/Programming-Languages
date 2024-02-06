;******************************************************************************
; Library       : EEPROM Emulation Library (T01)
;
; File Name     : eel.inc
; Lib. Version  : V1.15 (for CA78K0R)
; Device(s)     : RL78
; Description   : API definition of the EEPROM Emulation Library (EEL)
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

$IF (__EEL_INC_INCLUDED)

$ELSE
$SET (__EEL_INC_INCLUDED)

;---------------------------------------------------------------------------------------------------------------
; Block type:   standard function
;---------------------------------------------------------------------------------------------------------------
; Purpose:      Initialization of the EEPROM Emulation Library (EEL).
;               Internal variables are initialized.
; Input:        -
; Changed:      -
; Output:       -
; Return:       C = status: configuration related status code
;               - EEL_OK:                 initialization done without problems
;               - EEL_ERR_CONFIGURATION:  pool configuration error
;---------------------------------------------------------------------------------------------------------------
EXTRN   _EEL_Init



; ---------------------------------------------------------------------------------------------------------------
; Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
; Purpose:      Acitvates/Deactivates the access to the used flash medium.
;               If data-flash (FDL) is used, the data-flash clock is switched ON/OFF.
;               In case of code-flash (FCL) is used, the FLMD0 pin is controlled herewith.
; Input:        -
; Changed:      -
; Output:       -
; Return:       -
; ---------------------------------------------------------------------------------------------------------------
EXTRN   _EEL_Open
EXTRN   _EEL_Close



;---------------------------------------------------------------------------------------------------------------
; Block type:   standard function
;---------------------------------------------------------------------------------------------------------------
; Purpose:      Starting of execution of the corresponding EEL request.
;               The value of the time-out within the request variable determines the command execution mode.
;               Time-Out=0x00  -> polling mode, returns immediately to the application.
;               Time-Out=0xFF  -> enforced mode, returns to the application after the command is completed.
;               other values   -> counting mode, returns to the application after Time-Out was counted
;                                 down to 0x00 or the command is completed before that.
; Input:        AX - request_pstr - pointer to the EEL request variable
; Changed:      AX
; Output:       error: command related status code
;               - EEL_OK:             command completed without problems
;               - EEL_BUSY:           command accepted and
;               - EEL_ERR_REJECTED:   specified command couldn't be accepted
;               - other:              refer to the documentation.
; Return:       -
;---------------------------------------------------------------------------------------------------------------
EXTRN   _EEL_Execute



;---------------------------------------------------------------------------------------------------------------
; Block type:   standard function
;---------------------------------------------------------------------------------------------------------------
; Purpose:      Normally, this function takes care for the execution of the background process (maintenance).
;               When any command is started in "polling" mode, this function executes it state-by-state
;               When any command is started in "counting" mode, this function executes it time-slice-wise.
;               When starting commands in "enforced" mode, the EEL_Handler is not needed for command execution.
;               Just maintenance on EEL pool and data is realized by it in the idle-time of the application.
;
; Input:        X  - timeout - time-slice for the command execution expressed in time-out ticks
;                         0x00,  polling execution mode without TO supervision, execution state-by-state
;                         other, allocates a time-slice for the EEL command execution
; Changed:      AX
; Output:       -
; Return:       -
;---------------------------------------------------------------------------------------------------------------
EXTRN   _EEL_Handler



;---------------------------------------------------------------------------------------------------------------
; Block type:   standard functions
;---------------------------------------------------------------------------------------------------------------
; Purpose:      This function decrements an internal 8-bit software counter used by the timeout supervision.
;               The time out period (time-slice) is determined by EEL_Execute(....) or EEL_Handler(...)
;               EEL_TimeOut_Count() should be called in any periodical ISR creating the counting time-base.
;               Each time this function is called time-count register is decremented down to zero.
;               When timeout-counter becomes 0x00 an internal timeout-event is generated and the program
;               counter returns back to the user application.
;               Preferable place for EEL_TimeOut_Count() the operating system timer is used for such purpose.
; Input:        -
; Changed:      -
; Output:       -
; Return:       -
;---------------------------------------------------------------------------------------------------------------
EXTRN   _EEL_TimeOut_CountDown




;---------------------------------------------------------------------------------------------------------------
; Block type:   standard function
;---------------------------------------------------------------------------------------------------------------
; Purpose:      Provides the internal status of the EEL.
;               The information is only valid if the returned status is EEL_OK.
; Input:        AX - &driverStatus_pstr - address of the status variable used by the application
; Changed:      -
; Output:       driverStatus_pstr->operationStatus_enu:   operation status of the EEL driver
;                 EEL_OPERATION_PASSIVE:  STARTUP command not yet executed successfully
;                 EEL_OPERATION_IDLE:     no command and no background process is being executed
;                 EEL_OPERATION_BUSY:     a command or any background process is being executed
;               driverStatus_pstr->accessStatus_enu:      access status of the EEL driver
;                 EEL_ACCESS_LOCKED:      any access to the EEL is disabled
;                 EEL_ACCESS_UNLOCKED:    any access to the EEL is possible (after successful startup)
;               driverStatus_pstr->backgroundStatus_enu:  internal status of the background process
; Return:       -
;---------------------------------------------------------------------------------------------------------------
EXTRN   _EEL_GetDriverStatus




;---------------------------------------------------------------------------------------------------------------
; Block type:   standard function
;---------------------------------------------------------------------------------------------------------------
; Purpose:      Provides the currently available space inside the EEL pool.
;               It consists of the space inside the active heading block and all "prepared" blocks in pool.
; Input:        AX - &space_pu16 - address of the space variable used by the application
; Changed:      AX
; Output:       space_pu16 - available space expressed in flash words (here 1 word = 4 bytes)
; Return:       C - returns the execution status of this function
;               EEL_OK - space value is correct
;               EEL_ERR_REJECTED - not able to calculate available space (space_pu16* remains unchanged)
;---------------------------------------------------------------------------------------------------------------
EXTRN   _EEL_GetSpace



;---------------------------------------------------------------------------------------------------------------
; Block type:   standard function
;---------------------------------------------------------------------------------------------------------------
; Purpose:      This function returns the pointer to the "zero-terminated" version string of the library.
; Input:        -
; Changed:      DE, BC
; Output:       -
; Return:       starting pointer to the zero-terminated version string
;               DE - upper address of string
;               BC - lower address of string
;---------------------------------------------------------------------------------------------------------------
EXTRN   _EEL_GetVersionString



$ENDIF
