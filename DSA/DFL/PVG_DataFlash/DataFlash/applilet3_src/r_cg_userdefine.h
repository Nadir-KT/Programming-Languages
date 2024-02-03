/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012, 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_userdefine.h
* Version      : Applilet3 for RL78/D1A V2.04.05.02 [08 Nov 2021]
* Device(s)    : R5F10DPJ
* Tool-Chain   : CCRL
* Description  : This file includes user definition.
* Creation Date: 18-10-2022
***********************************************************************************************************************/

#ifndef _USER_DEF_H
#define _USER_DEF_H

/***********************************************************************************************************************
User definitions
***********************************************************************************************************************/

/* Start user code for function. Do not edit comment generated here */

#define FLASH_START_ADDRESS     (0xF1000U)                              /* Start address of data flash               */
#define TARGET_BLOCK            (0U)                                    /* Block number of target(0 ~ 7)             */
#define BLOCK_SIZE              (0x400U)                                /* Block size : 1024 Bytes (page)                               */
#define WRITE_SIZE              (10U)                                    /* Size of data to be written at once        */
#define READ_SIZE               (10U)                                    /* Size of data to be written at once        */
#define MAX_VALUE               (0xFFU)                                 /* Maximum value of writing                  */
#define MAX_ADDRESS             ((TARGET_BLOCK + 8U) * BLOCK_SIZE - 1U) /* Maximum address of writing: 0xF2FFF       */
#define PFDL_NG                 (1U)                                    /* Failure to Data Flash                     */
#define FDL_FRQ                 (8U)                                   /* Setting frequency (MHz)                   */
#define FDL_VOL                 (0x00U)                                 /* Voltage mode                              */
/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/
#define TRUE            (1)
#define FALSE           (0)

uint8_t Memory_Process(uint8_t sw_status);
void    New_Data_Record(void);
void    R_FDL_Init(void);


uint8_t  R_FDL_ExecuteRead(unsigned char page_no, unsigned char *R_Buffer);
uint8_t  R_FDL_BlankCheck(uint16_t Bnk_chk_address, uint16_t blk_size);
uint8_t  R_FDL_Erase(uint16_t blk_size);
uint8_t  R_FDL_Write(uint16_t write_addr, uint16_t write_size, char *write_buffer);
uint8_t  R_FDL_Read(uint16_t read_addr, uint16_t read_size, char *read_buffer);
uint8_t  R_FDL_Verify(uint16_t mem_addr, uint16_t mem_size);
uint8_t  R_FDL_ExecuteWrite(uint16_t write_addr, uint16_t write_size, char *write_buffer);
/*********************************************************************************************************************/

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
