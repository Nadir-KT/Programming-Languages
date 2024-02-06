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
* Copyright (C) 2011, 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G14 V2.05.04.02 [20 Nov 2019]
* Device(s)    : R5F104PJ
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 06-01-2021
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
/* Start user code for include. Do not edit comment generated here */

/* Standard library (runtime library is used) */
#include <string.h>

/* Data flash library */
#include "pfdl.h"                /* Library header file */
#include "pfdl_types.h"          /* Library header file */

/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */


/* Standard definitions */
#define TRUE                    1
#define FALSE                   0

/* Definitions for process switching */
#define R_PFDL_SAM_TARGET_ERASE TRUE    /* Pre-erase setting (executed for TRUE)       */
#define R_PFDL_SAM_DIRECT_READ  TRUE    /* Setting for direct reading of data flash    */
                                        /* Note: This is possible only at byte access  */
                                        /* with accesses to data flash memory enabled. */
/* Basic data */
#define R_PFDL_SAM_BLOCK_SIZE   0x400l  /* Standard block size(0x400l = 1KB)       */
#define R_PFDL_SAM_TARGET_BLOCK 0       /* Writing start block (0x0:F1000H)        */
#define R_PFDL_SAM_WRITE_SIZE   300     /* Write data size                         */
#define R_PFDL_SAM_DREAD_OFSET  0x1000  /* Direct reading offset address           */

/* PFDL initial settings */
#define R_PFDL_SAM_FDL_FRQ      32      /* Sets the frequency (32 MHz)             */
#define R_PFDL_SAM_FDL_VOL      0x00    /* Sets the voltage mode (full-speed mode) */

/* Control macro for sample program */
#define R_PFDL_SAM_WDT_RESET()  WDTE = 0xAC /* Watchdog timer reset                */

#define DATA_FLASH_IS_BLANK 1
#define DATA_FLASH_IS_NOT_BLANK 0
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

/* Sample functions for writing program */
pfdl_status_t r_pfdl_samFdlStart ( void );  /* pfdl initialization processing */
void          r_pfdl_samFdlEnd   ( void );  /* pfdl end processing            */

unsigned char written_data = 0;
unsigned char read_data = 0;
unsigned char DataFlashBlankCheckStatus = 0;
pfdl_u08 dubWriteBuffer[ R_PFDL_SAM_WRITE_SIZE ] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

void DataFlashInit();
unsigned char DataFlashBlankCheck();
void DataFlashErase(unsigned int DataFlashTargetBlockNumber);
void DataFlashWrite(unsigned int DataFlashTargetBlockNumber);
unsigned char SingleByteDataFlashRead(pfdl_u16 AddressInDataFlash);

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
    unsigned char c = 0;	
    pfdl_status_t   dtyFdlResult;       /* Return value                      */
    pfdl_request_t  dtyRequester;       /* PFDL control variable (requester) */
    //pfdl_u08        dubWriteBuffer[ R_PFDL_SAM_WRITE_SIZE ] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */

    /* Common variable declaration */
    
                                        /* Write data input buffer (initial value is set) */
    
    /* Target board initialization processing */
    //r_pfdl_samTargetInit();
    
    
    /* FDL initialization processing */
    //dtyFdlResult = r_pfdl_samFdlStart();
    DataFlashInit();
    
    DataFlashBlankCheckStatus = DataFlashBlankCheck();
    if(DataFlashBlankCheckStatus == DATA_FLASH_IS_BLANK)
    {
      NOP(); // Break Point // Will reaach here if dataflash is Blank
    } 
    else
    {
      NOP(); // Break Point // Will reaach here if dataflash is not Blank
      DataFlashErase(R_PFDL_SAM_TARGET_BLOCK);
    }
    
    DataFlashWrite(R_PFDL_SAM_TARGET_BLOCK);
    c = SingleByteDataFlashRead(3);
    
    NOP();
    dtyFdlResult = PFDL_OK;
    /* Requester initialization processing */
    dtyRequester.index_u16     = 0;
    dtyRequester.data_pu08     = dubWriteBuffer;
    dtyRequester.bytecount_u16 = 0;
    dtyRequester.command_enu   = PFDL_CMD_READ_BYTES; /* Initializes with PFDL_CMD_READ_BYTES(= 0) */
    
    
    
#if R_PFDL_SAM_TARGET_ERASE
/* If pre-erase is to be performed, perform blank check of the entire target block and then erase the block. */
    if( dtyFdlResult == PFDL_OK )
    {
        /* Performs blank check process for the entire block. Sets the blank check command */
        dtyRequester.command_enu   = PFDL_CMD_BLANKCHECK_BYTES;
        
        /* Sets the start address and execution range to 400H (1024) bytes */
        dtyRequester.index_u16     = R_PFDL_SAM_TARGET_BLOCK * R_PFDL_SAM_BLOCK_SIZE;
        dtyRequester.bytecount_u16 = R_PFDL_SAM_BLOCK_SIZE;
        
        /* Command execution process */
        dtyFdlResult = PFDL_Execute( &dtyRequester );
        
        /* Waiting for command to end */
        while( dtyFdlResult == PFDL_BUSY )
        {
            /* Perform any desired process (background operation) */
            __nop();
            __nop();
            
            /* End confirmation process */
            dtyFdlResult = PFDL_Handler();
        }
        
        /* If the target block is not in the blank state, executes the erase command */
        if( dtyFdlResult == PFDL_ERR_MARGIN )
        {
            /* Performs erase process for the target block. Sets the erase command */
            dtyRequester.command_enu = PFDL_CMD_ERASE_BLOCK;
            
            /* Sets the block number of the target block */
            dtyRequester.index_u16   = R_PFDL_SAM_TARGET_BLOCK;
            
            /* Command execution process */
            dtyFdlResult = PFDL_Execute( &dtyRequester );
            
            /* Waiting for command to end */
            while( dtyFdlResult == PFDL_BUSY )
            {
                /* Perform any desired process (background operation) */
                __nop();
                __nop();
                
                /* End confirmation process */
                dtyFdlResult = PFDL_Handler();
            }
        }
    }
#endif
    
    /* Data writing process */
    if( dtyFdlResult == PFDL_OK )
    {
        /* Variable definition for writing */
        pfdl_u16    duhWriteAddress;
        
        /* Before writing, performs blank check for the target area. */
        /* Sets the blank check command                              */
        dtyRequester.command_enu   = PFDL_CMD_BLANKCHECK_BYTES;
        /* Sets the write data size                                  */
        dtyRequester.bytecount_u16 = R_PFDL_SAM_WRITE_SIZE;
        
        /* Write check loop (performs blank check and searches for an area which can be written to) */
        for( duhWriteAddress  = R_PFDL_SAM_TARGET_BLOCK * R_PFDL_SAM_BLOCK_SIZE         ;
             duhWriteAddress  < ( R_PFDL_SAM_TARGET_BLOCK + 1 ) * R_PFDL_SAM_BLOCK_SIZE ;
             duhWriteAddress += R_PFDL_SAM_WRITE_SIZE )
        {
            /* Sets the start address for writing */
            dtyRequester.index_u16 = duhWriteAddress;
            
            /* Command execution process */
            dtyFdlResult = PFDL_Execute( &dtyRequester );
            
            /* Waiting for command to end */
            while( dtyFdlResult == PFDL_BUSY )
            {
                /* Perform any desired process (background operation) */
                __nop();
                __nop();
                
                /* End confirmation process */
                dtyFdlResult = PFDL_Handler();
            }
            
            /* If in the blank state, performs writing */
            if( dtyFdlResult == PFDL_OK )
            {
                /* Sets the write command (write data and buffer have already been set) */
                dtyRequester.command_enu = PFDL_CMD_WRITE_BYTES;
                
                /* Command execution process */
                dtyFdlResult = PFDL_Execute( &dtyRequester );
                
                /* Waiting for command to end */
                while( dtyFdlResult == PFDL_BUSY )
                {
                    /* Perform any desired process (background operation) */
                    __nop();
                    __nop();
                    
                    /* End confirmation process and trigger process for each 1-byte writing */
                    dtyFdlResult = PFDL_Handler();
                }
                
                /* If writing has been completed normally, executes the internal verification process */
                if( dtyFdlResult == PFDL_OK )
                {
                    /* Sets the internal verification command */
                    dtyRequester.command_enu = PFDL_CMD_IVERIFY_BYTES;
                    
                    /* Command execution process */
                    dtyFdlResult = PFDL_Execute( &dtyRequester );
                    
                    /* Waiting for command to end */
                    while( dtyFdlResult == PFDL_BUSY )
                    {
                        /* Perform any desired process (background operation) */
                        __nop();
                        __nop();
                        
                        /* End confirmation process */
                        dtyFdlResult = PFDL_Handler();
                    }
                }
#if R_PFDL_SAM_DIRECT_READ
/* Confirms data by direct reading (this is possible only at byte access with accesses */
/* to data flash memory enabled)                                                       */
/* Note that data cannot be read correctly when data flash memory is being written to. */
                /* Data confirmation process */
                if( dtyFdlResult == PFDL_OK )
                {
                    /* Variable definitions for reading */
                    unsigned short        duh_i;        /* Loop variable definition */
                    __near unsigned char *pubReadData;  /* Pointer for direct reading (only byte access is possible) */
                    
                    pubReadData = (__near unsigned char *) duhWriteAddress + R_PFDL_SAM_DREAD_OFSET;
                    
                    /* Compares read data and write data */
                    for( duh_i = 0 ; duh_i < R_PFDL_SAM_WRITE_SIZE ; duh_i++ )
                    {

			    written_data = dubWriteBuffer[duh_i];  // Break Point to read the value that was initially written by us in the Flash. Already stored above
			    read_data = pubReadData[duh_i];        // Break Point to read the value that was extracted after the Data Flash Read operation. Note :  It should match the above written value of the "written_data" Variable.
                        if( dubWriteBuffer[ duh_i ] != pubReadData[ duh_i ] )
                        {
                            /* Error is generated when read data and write data do not match. */
                            dtyFdlResult = PFDL_ERR_PARAMETER;
                            break;
                        }
                    }
                }
#else
/* Uses the reading function for data flash libraries */
                /* Data confirmation process */
                if( dtyFdlResult == PFDL_OK )
                {
                    /* Variable definitions for reading */
                    pfdl_u16    duh_i;      /* Loop variable definition */
                    pfdl_u08    dubReadBuffer [ R_PFDL_SAM_WRITE_SIZE ];
                                            /* Read data input buffer */
                    
                    /* Sets the read command */
                    dtyRequester.command_enu = PFDL_CMD_READ_BYTES;
                    
                    /* Sets the read start address */
                    dtyRequester.index_u16   = duhWriteAddress;
                    
                    /* Sets the address for the read data input buffer */
                    dtyRequester.data_pu08   = dubReadBuffer;
                    
                    /* Command execution process */
                    dtyFdlResult = PFDL_Execute( &dtyRequester );
                    
                    /* Compares read data and write data */
                    for( duh_i = 0 ; duh_i < R_PFDL_SAM_WRITE_SIZE ; duh_i++ )
                    {
                        if( dubWriteBuffer[ duh_i ] != dubReadBuffer[ duh_i ] )
                        {
                            /* Error is generated when read data and write data do not match. */
                            dtyFdlResult = PFDL_ERR_PARAMETER;
                            break;
                        }
                    }
                }
#endif
                break;
            }
            /* Processing is aborted when an unsolvable error has occurred. */
            else if( dtyFdlResult != PFDL_ERR_MARGIN ) {
                break;
            }
        }
    }
    
    /* FDL end processing */
    r_pfdl_samFdlEnd();
    
    /* Target board end processing */
    //r_pfdl_samTargetEnd();
    
    /* End loop */
    while( 1 )
    {
        __nop();
        __nop();
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

/******************************************************************************
* Outline           : PFDL start function
* Include           : pfdl.h, pfdl_types.h
* Declaration       : pfdl_status_t r_pfdl_samFdlStart( void )
* Description       : Start of the pfdl.
* Argument          : none
* Return Value      : pfdl_status_t
* Calling Functions : main
******************************************************************************/
pfdl_status_t r_pfdl_samFdlStart( void )
{
    pfdl_status_t       dtyFdlResult;
    pfdl_descriptor_t   dtyDescriptor;
    
    /* Inputs the initial values */
    dtyDescriptor.fx_MHz_u08            = R_PFDL_SAM_FDL_FRQ;  /* Sets the frequency    */
    dtyDescriptor.wide_voltage_mode_u08 = R_PFDL_SAM_FDL_VOL;  /* Sets the voltage mode */
    
    /* Executes the PFDL initialization function */
    dtyFdlResult = PFDL_Open( &dtyDescriptor );
    
    return dtyFdlResult;
}

/******************************************************************************
* Outline           : PFDL end function
* Include           : pfdl.h
* Declaration       : void r_pfdl_samFdlEnd( void )
* Description       : End of the pfdl.
* Argument          : none
* Return Value      : none
* Calling Functions : main
******************************************************************************/
void r_pfdl_samFdlEnd( void )
{
    /* Data flash library end processing */
    PFDL_Close();
}



void DataFlashInit()
{
   pfdl_status_t   dtyFdlResult;       /* Return value                      */
	 	
   dtyFdlResult = r_pfdl_samFdlStart();
   if(dtyFdlResult == PFDL_OK)  // if Datalash got initialized properly or not
   {
     NOP(); //Break point //Will reaach here if dataflash working properly.
   }
   
   else
   {
     NOP(); //Break point //Will reaach here if dataflash is not working properly.
     while(1)
     {
       NOP();  // will remain here forever
     }
   }
   return;
}


unsigned char DataFlashBlankCheck()
{
  pfdl_status_t   dtyFdlResult;       /* Return value                      */
  pfdl_request_t  dtyRequester;       /* PFDL control variable (requester) OR Structure variable */	
  	
  

        /* Performs blank check process for the entire block. Sets the blank check command */
        dtyRequester.command_enu   = PFDL_CMD_BLANKCHECK_BYTES;
        
        /* Sets the start address and execution range to 400H (1024) bytes */
        dtyRequester.index_u16     = R_PFDL_SAM_TARGET_BLOCK * R_PFDL_SAM_BLOCK_SIZE;  // DataFlash starting address
        dtyRequester.bytecount_u16 = R_PFDL_SAM_BLOCK_SIZE;   // Dataflash bytes number serves the purpose of final address upto our code will check in blank check. 
        
        /* Command execution process */
        dtyFdlResult = PFDL_Execute( &dtyRequester );
        
        /* Waiting for command to end */
        while( dtyFdlResult == PFDL_BUSY )
        {
            /* Perform any desired process (background operation) */
            __nop();
            __nop();
            
            /* End confirmation process */
            dtyFdlResult = PFDL_Handler();
        }

       if(dtyFdlResult == PFDL_OK)
       {
         NOP(); // break point //Will reaach here if dataflash is blank
         return 1; // returns 1 if not blank
       }
       
       else
       {
         NOP(); // break point //Will reaach here if dataflash is not blank 
	 return 0; // returns 0 if not blank
       }
}

void DataFlashErase(unsigned int DataFlashTargetBlockNumber)
{
	pfdl_status_t   dtyFdlResult;       /* Return value                      */
        pfdl_request_t  dtyRequester;       /* PFDL control variable (requester) */
     
	
            /* Performs erase process for the target block. Sets the erase command */
            dtyRequester.command_enu = PFDL_CMD_ERASE_BLOCK;
            /* Sets the block number of the target block */
            //dtyRequester.index_u16   = R_PFDL_SAM_TARGET_BLOCK;
            dtyRequester.index_u16 = DataFlashTargetBlockNumber;
            /* Command execution process */
            dtyFdlResult = PFDL_Execute( &dtyRequester );
            
            /* Waiting for command to end */
            while( dtyFdlResult == PFDL_BUSY )
            {
                /* Perform any desired process (background operation) */
                __nop();
                __nop();
                
                /* End confirmation process */
                dtyFdlResult = PFDL_Handler();
            }
	    
}

void DataFlashWrite(unsigned int DataFlashTargetBlockNumber)
{
	pfdl_status_t   dtyFdlResult;       /* Return value                      */
        pfdl_request_t  dtyRequester;       /* PFDL control variable (requester) */
	
	/*Give Address of the data pointer to be stored in the Data Flash.
	The data will be saved in a global array, which can be updated anywhere in the code.*/
	dtyRequester.data_pu08 = dubWriteBuffer;
	
        /* Sets the start address and execution range to 400H (1024) bytes */
        //dtyRequester.index_u16     = R_PFDL_SAM_TARGET_BLOCK * R_PFDL_SAM_BLOCK_SIZE;
        dtyRequester.index_u16     = DataFlashTargetBlockNumber * R_PFDL_SAM_BLOCK_SIZE;
	dtyRequester.bytecount_u16 = R_PFDL_SAM_BLOCK_SIZE;
	
        /* Sets the write command (write data and buffer have already been set) */
        dtyRequester.command_enu = PFDL_CMD_WRITE_BYTES;
        
        /* Command execution process */
        dtyFdlResult = PFDL_Execute( &dtyRequester );
        
        /* Waiting for command to end */
        while( dtyFdlResult == PFDL_BUSY )
        {
            /* Perform any desired process (background operation) */
            __nop();
            __nop();
            
            /* End confirmation process and trigger process for each 1-byte writing */
            dtyFdlResult = PFDL_Handler();
        }
        
        /* If writing has been completed normally, executes the internal verification process */
        if( dtyFdlResult == PFDL_OK )
        {
	  NOP(); //Break Point //Code reaches here if data is written successfully
	}
	else
	{
	  NOP(); //Break Point //Code reaches here if data is not written successfully
	  while(1); // Wait here forever as code is crashed.
	}
            /* Sets the internal verification command */
            dtyRequester.command_enu = PFDL_CMD_IVERIFY_BYTES;
            
            /* Command execution process */
            dtyFdlResult = PFDL_Execute( &dtyRequester );
            
            /* Waiting for command to end */
            while( dtyFdlResult == PFDL_BUSY )
            {
                /* Perform any desired process (background operation) */
                __nop();
                __nop();
                
                /* End confirmation process */
                dtyFdlResult = PFDL_Handler();
            }
	
	if( dtyFdlResult == PFDL_OK )
	{
	  NOP();  //Break Point //Code reaches here when writing process crosschecked and data is saved properly
	}
	else
	{
	  NOP();  //Break Point //Code reaches here when data is not saved correctly
	}
}


unsigned char SingleByteDataFlashRead(pfdl_u16 AddressInDataFlash)
{
     
     	
     /* Variable definitions for reading */
     unsigned short duh_i;        /* Loop variable definition */
    __near unsigned char *pubReadData;  /* Pointer for direct reading (only byte access is possible) */
    
    //pubReadData = (__near unsigned char *) AddressInDataFlash + R_PFDL_SAM_DREAD_OFSET;
    pubReadData = (__near unsigned char *) AddressInDataFlash + 0xF1000;    
    return (unsigned char)pubReadData[0];
}

/* End user code. Do not edit comment generated here */
