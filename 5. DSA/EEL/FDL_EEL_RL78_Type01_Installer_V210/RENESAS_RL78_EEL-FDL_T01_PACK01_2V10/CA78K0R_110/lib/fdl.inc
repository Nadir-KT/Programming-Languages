;*******************************************************************************
; Library       : Data Flash Access Library T01
;
; File Name     : $Source: fdl.inc $
; Lib. Version  : $RL78_FDL_LIB_VERSION_T01_REN: V1.12 $
; Mod. Revision : $Revision: 1.7 $
; Mod. Date     : $Date: 2013/05/29 17:20:26JST $
; Device(s)     : RL78
; Description   : Contains the API definition of the Data Flash Access Library
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



$IF (__FDL_INC_INCLUDED)

$ELSE
$SET (__FDL_INC_INCLUDED)




;==============================================================================================
; constant definitions
;==============================================================================================

; status code definitions returned by the FDL functions
FAL_OK                  EQU       (00H OR 00H)
FAL_BUSY                EQU       (00H OR 01H)
FAL_ERR_PROTECTION      EQU       (10H OR 00H)
FAL_ERR_BLANKCHECK      EQU       (10H OR 01H)
FAL_ERR_VERIFY          EQU       (10H OR 02H)
FAL_ERR_WRITE           EQU       (10H OR 03H)
FAL_ERR_ERASE           EQU       (10H OR 04H)
FAL_ERR_PARAMETER       EQU       (20H OR 00H)
FAL_ERR_CONFIGURATION   EQU       (20H OR 01H)
FAL_ERR_INITIALIZATION  EQU       (20H OR 02H)
FAL_ERR_COMMAND         EQU       (20H OR 03H)
FAL_ERR_REJECTED        EQU       (20H OR 04H)

; FAL command code set
FAL_CMD_UNDEFINED       EQU       (00H OR 00H)
FAL_CMD_BLANKCHECK_WORD EQU       (00H OR 01H)
FAL_CMD_IVERIFY_WORD    EQU       (00H OR 02H)
FAL_CMD_READ_WORD       EQU       (00H OR 03H)
FAL_CMD_WRITE_WORD      EQU       (00H OR 04H)
FAL_CMD_ERASE_BLOCK     EQU       (00H OR 05H)




; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;  Purpose:      Enable data flash access.
;                Pre-condition: The initialization of the library must be done by the FAL_Init function.
;  Input:        -
;  Output:       -
;  Changed:      -
;  Return:       -
; ---------------------------------------------------------------------------------------------------------------
EXTRN FAL_Open


; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;  Purpose:      Disable data flash access.
;                Pre-condition: The initialization of the library must be done by the FAL_Init function.
;  Input:        -
;  Output:       -
;  Changed:      -
;  Return:       -
; ---------------------------------------------------------------------------------------------------------------
EXTRN FAL_Close


; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;   Purpose:      Initialization of the Flash Access Library.
;                 Based on the descriptor data several checks are performed:
;                 - plausibility check of the FAL pool configuration
;                 - initialization of all internal variables
;                 After initialization the FAL remains passive.
;                 FAL_Open() has to be executed to open access to the FAL pool
;  Input:         AX = LOWW(descriptor)
;                 BC = HIGHW(descriptor)
;  Changed:       AX, BC
;  Return:        C  = status: configuration related error code
;                 - FAL_OK:                 initialization done without problems
;                 - FAL_ERR_CONFIGURATION:  FAL pool-configuration error
; ---------------------------------------------------------------------------------------------------------------
EXTRN FAL_Init



; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;  Purpose:      Initiating execution of the FAL request described in the passed request reference.
;                The corresponding request variable has to be defined before starting the execution.
;
;                                                 WCMD (word command)            BCMD (block command)
;                                                 --------------------------------------------------------------
;                my_request->data_u32         :   read/write data                no meaning
;                my_request->index_u16        :   word-index within pool         block index within pool
;                my_request->command_enu      :   command code                   command code
;                my_request->status_enu       :   request status                 request status
;
;                Each client who is using FAL_Execute() has to use two private variables of initiating requests.
;                One of them is exclusively reserved for suspendable block-oriented commands (BCMD).
;                The other one defines the non-suspendable word-oriented commands (WCMD).
;                Please refer to the users manual for details of the suspend-/resume-mechanism.
;
;  Input:        AX - pointer to privat request variable  (WCMD or BCMD)
;  Changed:      AX
;  Output:       status inside the request variable
;  Return:       -
; ---------------------------------------------------------------------------------------------------------------
EXTRN FAL_Execute



; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;  Purpose:      Continuing of not finished commands.
;
;  Input:        -
;  Output:       status inside the request variable for command executed via FAL_Execute
;  Changed:      -
;  Return:       -
; ---------------------------------------------------------------------------------------------------------------
EXTRN FAL_Handler



; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;  Purpose:      Return the start address of the library version string
;
;  Input:        -
;  Output:       -
;  Changed:      DE, BC
;  Return:       starting pointer to the zero-terminated version string
;                DE - upper address of string
;                BC - lower address of string
; ---------------------------------------------------------------------------------------------------------------
EXTRN FAL_GetVersionString





$ENDIF
