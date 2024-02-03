/*******************************************************************************
* Library       : EEPROM Emulation Library (T01)
*
* File Name     : eel_descriptor.c
* Lib. Version  : V1.15 (for CA78K0R)
* Device(s)     : RL78
* Description   : user defined EEL-variable descriptor
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
* Copyright (C) 2011-2017 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

/*==============================================================================================*/
/* compiler settings                                                                            */
/*==============================================================================================*/
#pragma name EEL_DESCRIPTOR
#pragma sfr


#ifdef __K0R_LARGE__
  #pragma section @@DATAL EEL_UDAT
#else
  #pragma section @@DATA  EEL_UDAT
#endif

#pragma section @@CNSTL EEL_CNST



/*==============================================================================================*/
/* include files list                                                                           */
/*==============================================================================================*/
#define  __EEL_DESCRIPTOR_C
  #include  "eel_types.h"
  #include  "eel_descriptor.h"
#undef   __EEL_DESCRIPTOR_C

#if (EEL_STORAGE_TYPE == 'C')
  #include  "fcl_types.h"
#elif (EEL_STORAGE_TYPE=='D')
  #include  "fdl_types.h"
#else
  #error "EEL: wrong storage type defined !"
#endif


/* definition of variable types registered at EEL */
#include  "EEL_user_types.h"


/*==============================================================================================*/
/* import list                                                                                  */
/*==============================================================================================*/
/* empty */


/*==============================================================================================*/
/* data definition                                                                              */
/*==============================================================================================*/
#if (EEL_STORAGE_TYPE=='C')
  eel_u16   EEL_var_ref[EEL_VAR_NO];
#else
  eel_u16   EEL_var_ref[1];                                    /* dummy address for FDL variant */
#endif



/*********************************************************************************************************/
/*******                                                                                           *******/
/*******      B E G I N    O F    C U S T O M I Z A B L E    D E C L A R A T I O N    A R E A      *******/
/*******                                                                                           *******/
/*********************************************************************************************************/

__far const eel_u08 eel_descriptor[EEL_VAR_NO+1][4] =
            {
            /*  identifier        word-size (1...64)                  byte-size (1..255)         RAM-Ref. */
            /*  ----------------------------------------------------------------------------------------- */
                (eel_u08)'a',     (eel_u08)((sizeof(type_A)+3)/4),    (eel_u08)sizeof(type_A),   0x01,  \
                (eel_u08)'b',     (eel_u08)((sizeof(type_B)+3)/4),    (eel_u08)sizeof(type_B),   0x01,  \
                (eel_u08)'c',     (eel_u08)((sizeof(type_C)+3)/4),    (eel_u08)sizeof(type_C),   0x01,  \
                (eel_u08)'d',     (eel_u08)((sizeof(type_D)+3)/4),    (eel_u08)sizeof(type_D),   0x01,  \
                (eel_u08)'e',     (eel_u08)((sizeof(type_E)+3)/4),    (eel_u08)sizeof(type_E),   0x01,  \
                (eel_u08)'f',     (eel_u08)((sizeof(type_F)+3)/4),    (eel_u08)sizeof(type_F),   0x01,  \
                (eel_u08)'x',     (eel_u08)((sizeof(type_X)+3)/4),    (eel_u08)sizeof(type_X),   0x01,  \
                (eel_u08)'z',     (eel_u08)((sizeof(type_Z)+3)/4),    (eel_u08)sizeof(type_Z),   0x01,  \
                (eel_u08)0x00,    (eel_u08)(0x00),                    (eel_u08)(0x00),           0x00,  \
            };

/*********************************************************************************************************/
/*******                                                                                           *******/
/*******      E N D    O F    C U S T O M I Z A B L E    D E C L A R A T I O N    A R E A          *******/
/*******                                                                                           *******/
/*********************************************************************************************************/





/* ----------------------------------------------------------------------------------------------------- */
/* ------                                                                                          ----- */
/* ------     B E G I N    O F    U N T O U C H A B L E     D E C L A R A T I O N    A R E A       ----- */
/* ------                                                                                          ----- */
/* ----------------------------------------------------------------------------------------------------- */
__far const eel_u08   eel_refresh_bth_u08     = (eel_u08)EEL_REFRESH_BLOCK_THRESHOLD;
__far const eel_u08   eel_storage_type_u08    = (eel_u08)EEL_STORAGE_TYPE;
__far const eel_u08   eel_var_number_u08      = (eel_u08)EEL_VAR_NO;
/* ----------------------------------------------------------------------------------------------------- */
/* ------                                                                                          ----- */
/* ------     E N D    O F    U N T O U C H A B L E     D E C L A R A T I O N    A R E A           ----- */
/* ------                                                                                          ----- */
/* ----------------------------------------------------------------------------------------------------- */
