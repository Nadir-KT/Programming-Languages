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
* File Name    : r_main.c
* Version      : Applilet3 for RL78/D1A V2.04.05.02 [08 Nov 2021]
* Device(s)    : R5F10DPJ
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 18-10-2022
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
#include "pfdl.h"
#include "pfdl_types.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint16_t g_write_address = TARGET_BLOCK * BLOCK_SIZE; // 0xF2FFFH
//float odo=25;  
//char modo = odo;
//unsigned char write_set_buffer[13] = {'R','E','N','E','S','A','S','-','I','N','D','I','A'};
unsigned char  write_set_buffer[4] = {0};
volatile uint16_t write_set_addr = 0x0000U;
volatile uint16_t write_set_size = 4U;
//uint16_t write_set_size = 13U;
unsigned char Read_Buffer_DF[4] = {0};

void data_flash_Read(void);
/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
{
    uint8_t sw_status    = 0U;
    uint8_t ret          = PFDL_OK;
	    
    //write_set_size = 13U;
    write_set_addr = 0x0000U;	
            write_set_buffer[0]  = 254;
	    write_set_buffer[1]  = 254;
	    write_set_buffer[2]  = 254;
	    write_set_buffer[3]  = 254;
    __nop();
    
    DI(); /* Disable all interrupts while using of flash read/ write functions */
    /* **** Read data at first **** */
    R_FDL_Init();                       /* Initialize EEL */
    data_flash_Read();			/* Data read */     
    PFDL_Close(); 
    
    //write_set_size = 13U;
    write_set_addr = 0x0000U;

    
    __nop();
    R_FDL_Init();
    R_FDL_ExecuteWrite( /*write_set_addr*/ 0X0000,write_set_size ,write_set_buffer );  /* Write value to selected address */
    PFDL_Close();
    
    __nop();
        /* **** Read data after flash write **** */
    R_FDL_Init();                       /* Initialize EEL */
    data_flash_Read();			/* Data read */     
    PFDL_Close(); 
    
    EI(); /* Enable interrupts */
    R_TAU0_Channel0_Start();
    P13_bit.no2 = 0;
    P13_bit.no3 = 0;
    P13_bit.no4 = 0;
    while (1U)
    {
        ;
    }
}
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    EI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void data_flash_Read(void)
{
	uint16_t Read_Addr_DF = 0x00;
	uint16_t Read_Size_DF = 0x13;
		
	DI();
	R_FDL_Init();
	R_FDL_Read(Read_Addr_DF, Read_Size_DF, Read_Buffer_DF);
	PFDL_Close();
	__nop();
	//EI();
	
}
/* End user code. Do not edit comment generated here */
