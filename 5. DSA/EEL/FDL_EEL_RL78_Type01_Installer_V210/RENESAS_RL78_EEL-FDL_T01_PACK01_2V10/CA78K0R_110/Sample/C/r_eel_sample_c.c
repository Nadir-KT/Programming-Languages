/*******************************************************************************
* DISCLAIMER                                                                   *
* This software is supplied by Renesas Electronics Corporation and is only     *
* intended for use with Renesas products. No other uses are authorized. This   *
* software is owned by Renesas Electronics Corporation and is protected under  *
* all applicable laws, including copyright laws.                               *
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING  *
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT      *
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE   *
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.          *
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS       *
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  *
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR   *
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE  *
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.                             *
* Renesas reserves the right, without notice, to make changes to this software *
* and to discontinue the availability of this software. By using this software,*
* you agree to the additional terms and conditions found by accessing the      *
* following link:                                                              *
* http://www.renesas.com/disclaimer                                            *
*                                                                              *
* Copyright (C) 2012-2017 Renesas Electronics Corporation. All rights reserved.*
*******************************************************************************/
/*******************************************************************************
* File Name     : r_eel_sample_c.c                                             *
* Version       : 1.04                                                         *
* Device(s)     : RL78/G13   ( R5F100LEA )                                     *
* Tool-Chain    : CS+ ( V3.00 )                                                *
* OS            : none                                                         *
* H/W Platform  : QB-R5F100LE-TB                                               *
* Description   : This is the EEL sample code.                                 *
* Operation     :                                                              *
* Limitations   :                                                              *
*******************************************************************************/
/*******************************************************************************
* History       : Version Description                                          *
*               : 06.16.2011 1.00 First Release                                *
*               : 11.02.2011 1.01 ���N�G�X�^�̏�����������ǉ�                 *
*               : 03.05.2012 1.02 10�i�萔�}�N����(__RL78_)�̌����C��        *
*               : 01.29.2016 1.03 Tool-Chain��ύX                             *
*               : 10.03.2017 1.04 �R�����g���C��                               *
*******************************************************************************/

/******************************************************************************
 Expanded function
******************************************************************************/
#pragma sfr                             /* SFR(���背�W�X�^�S)�̈旘�p�錾   */
#pragma DI                              /* ���荞�݋@�\(�֎~)���p�錾        */
#pragma EI                              /* ���荞�݋@�\(����)���p�錾        */
#pragma NOP                             /* CPU���䖽�� (NOP )���p�錾        */


/******************************************************************************
 interrupt function
******************************************************************************/
#pragma interrupt INTWDTI samIntWdt     /* WDT���荞��                      */


/******************************************************************************
 section and switch
******************************************************************************/
/**************************************/
/* �T���v���v���O�����̃Z�N�V�����ݒ� */
/**************************************/
/* �R�[�h(�v���O����)�̃Z�N�V�������̐ݒ�(�ύX) */
#ifdef __78K0R_SMALL__
  #pragma section @@CODE  SAM_CODE
#else
  #pragma section @@CODEL SAM_CODE
#endif 

/* �Œ�l�e�[�u��(const)�̃Z�N�V�������̐ݒ�(�ύX) */
#ifdef __78K0R_LARGE__
  #pragma section @@CNSTL SAM_CNST
#else
  #pragma section @@CNST  SAM_CNST
#endif

/* �f�[�^(�ϐ�)�̃Z�N�V�������̐ݒ�(�ύX) */
/*
#ifdef __78K0R_LARGE__
  #pragma section @@DATAL SAM_DATA
#else
  #pragma section @@DATA  SAM_DATA
#endif
*/

/******************************************************/
/* �T���v���E�v���O�����E�v���O�����X�C�b�`�p�V���{�� */
/******************************************************/
/* QB-R5F100LE-TB�P�̎g�p��ON�\ */
#if 0
#define __QB_R5F100LE_TB__      /*  */


/* ���̑��{�[�h(�������U�ݒ�) */
#else
#define __NON_TARGET__          /*  */

#endif


/******************************************************************************
 Include <System Includes>, "Project Includes"
******************************************************************************/
/* �W�����C�u����(�����^�C���E���C�u�����g�p) */
#include <string.h>             /* memcpy�p */

/* FDL,EEL���C�u�����p�w�b�_�[�t�@�C��          */
#include "fdl.h"                    /* FDL���C�u�����E�w�b�_�[�t�@�C��          */
#include "fdl_descriptor.h"         /* FDL�f�B�X�N���v�^�E�w�b�_�[�t�@�C��      */
#include "eel.h"                    /* EEL���C�u�����E�w�b�_�[�t�@�C��          */
#include "eel_descriptor.h"         /* EEL�f�B�X�N���v�^�E�w�b�_�[�t�@�C��      */
#include "eel_user_types.h"         /* EEL���[�U�[��`�E�w�b�_�[�t�@�C��        */

/******************************************************************************
 Typedef definitions
******************************************************************************/


/******************************************************************************
 Macro definitions
******************************************************************************/
/**************************/
/* EEL����p �V���{����` */
/**************************/
/* �R�}���h�̎��s���[�h                 */
#define SAM_EEL_MODE_ENFORCED   0xFF    /* Enforced���[�h(0xFF)         */
#define SAM_EEL_MODE_TIMEOUT    0x10    /* Timeout ���[�h(0x01�`0xFE)   */
#define SAM_EEL_MODE_POLLING    0x00    /* Polling ���[�h(0x00)         */

/* ���̑��p�����[�^                     */
#define SAM_EEL_BUFFER_SIZE     0xFF    /* �T���v���p�̃o�b�t�@�T�C�Y   */
#define SAM_EEL_MAINTE_END      0x04    /* EEL_Handler�֐��̃����e�i���X�I�����[�v��  */

/* �T���v���v���O�����p�A����}�N�� */
#define SAM_WDT_RESET()         WDTE = 0xAC 
                                        /* �E�H�b�`�h�b�O�^�C�}���Z�b�g */

/*********************************************************/
/* QB-R5F100LE-TB, �������݃V���{����`                  */
/*********************************************************/
#ifdef __QB_R5F100LE_TB__
/* QB-R5F100LE-TB, LED����}�N�� */
#define SAM_LED1_INIT() P6.2 = 1, PM6.2 = 0
                                        /* �I���{�[�h��LED1��������(��_��) */
#define SAM_LED1_ON()   P6.2 = 0        /* �I���{�[�h��LED1��_��           */
#define SAM_LED1_OFF()  P6.2 = 1        /* �I���{�[�h��LED1������           */

#define SAM_LED2_INIT() P6.3 = 1, PM6.3 = 0
                                        /* �I���{�[�h��LED2��������(��_��) */
#define SAM_LED2_ON()   P6.3 = 0        /* �I���{�[�h��LED2��_��           */
#define SAM_LED2_OFF()  P6.3 = 1        /* �I���{�[�h��LED2������           */

/*************************************/
/* �ʏ�̏������ݐݒ�p �V���{����` */
/*************************************/
#else 
/* LED�͏�������(�����R�[�h) */
#define SAM_LED1_INIT()
#define SAM_LED1_ON()
#define SAM_LED1_OFF()
#define SAM_LED2_INIT()
#define SAM_LED2_ON()
#define SAM_LED2_OFF()

#endif

/******************************************************************************
 External reference parameter
******************************************************************************/


/******************************************************************************
 Prototype declarations
******************************************************************************/
/* �^�[�Q�b�g�p�T���v���֐� */
void samTargetInit( void );     /* �^�[�Q�b�g����������     */
void samTargetEnd ( void );     /* �^�[�Q�b�g�I������       */

/* �����e�i���X�֐� */
void samMaintenance( eel_request_t *ptyRequester );

/*############################################################################*/
/******************************************************************************
* Outline           : hdwinit
* Include           : none
* Declaration       : void hdwinit(void)
* Function Name     : main
* Description       : Main function and set some SFR registers.
* Argument          : none
* Return Value      : none
* Calling Functions : none
******************************************************************************/
void hdwinit( void )
{
    /************************/
    /* ��d�����o��H�̐ݒ� */
    /************************/
    LVIM = 0x00;                /* ��d�����o���W�X�^�̐ݒ��������             */
    LVIS = 0x00;                /* ��d�����o���x���I�����W�X�^�̐ݒ��������   */
    
/* QB-R5F100LE-TB�p�O��20Mhz���U�ؑ֐ݒ� */
#if 0
    /****************************************************************/
    /* �N���b�N���䃌�W�X�^�̏�����                                 */
    /* ����N���b�N��������U����X1(20Mhz��z��)���U�ɕύX          */
    /* �����̂܂܎g�p����ꍇ��fsl_user.h��20Mhz�ݒ�ɂ��Ă�������  */
    /****************************************************************/
    /* ����X�s�[�h�E���[�h���䃌�W�X�^     */
    OSMC = 0b00000001;          /* 10 MHz���z������g���ł̓���ݒ�                         */
    
    /* �N���b�N���샂�[�h���䃌�W�X�^       */
    CMC  = 0b01010001;          /* X1,XT1�[�q���U���[�h�AX1���g����10MHz��fMX��20MHz�ɐݒ�  */
    
    /* �N���b�N����X�e�[�^�X���䃌�W�X�^   */
    CSC  = 0b00000000;          /* X1,XT1���U�J�n                                           */
    
    /* X1���U���莞�ԑI�����W�X�^           */
    OSTS = 0b11110000;          /* X1���U���莞�Ԃ�ݒ� ( fx = 20 MHz�� / 102.4 �� s�ȏ� )  */
    
    /* ���U���莞�ԃJ�E���^��ԃ��W�X�^     */
    while( OSTC == 0 );         /* X1���U���莞�ԑ҂� ( ALL 0 )                             */
    
    /* �V�X�e���E�N���b�N���䃌�W�X�^       */
    CKC  = 0b00011000;          /* ���C���E�V�X�e���E�N���b�N��������U����X1���U�ɕύX     */
    
    while( MCS  == 0 );         /* ���C���E�V�X�e���E�N���b�N�ifMAIN�j�̃X�e�[�^�X�m�F      */
                                /* �����U��H�ؑ֊m�F ( MCS : CKC���W�X�^ 5bit��  )         */
    
    /* �N���b�N����X�e�[�^�X���䃌�W�X�^ : �����������U�N���b�N�̓��쐧��                  */
    /* HIOSTOP = 1; */          /* CSC = 0b00000001 : �����������U��H��~                  */
    /* RL78�̃Z���t�����s����ꍇ��OCO���K�v�̂��߁A�������U��H�͒�~�����Ȃ��B            */
    
#endif
}


/*==============================================================================*/
/* Function name : main                                                         */
/* IN            : void                                                         */
/* OUT           : void                                                         */
/* Description   : ���C���֐�                                                   */
/* Date          : 06,08,2011                                                   */
/*==============================================================================*/
void main( void )
{
    /* �ϐ���` */
    fal_status_t    dteFalResult;       /* FDL�p�p�����[�^�ϐ�  */
    eel_request_t   dtyRequester;       /* EEL�p�p�����[�^�ϐ�  */
    eel_u08         dubDataBuffer[ SAM_EEL_BUFFER_SIZE ];
                                        /* �f�[�^���͗p�o�b�t�@ */
    eel_u08         dubReadBuffer[ SAM_EEL_BUFFER_SIZE ];
                                        /* �f�[�^�擾�p�o�b�t�@ */
    
    /* �o�b�t�@�̏��������� */
    memset( dubDataBuffer, 0x00, SAM_EEL_BUFFER_SIZE );
    memset( dubReadBuffer, 0x00, SAM_EEL_BUFFER_SIZE );
    
    /* �^�[�Q�b�g���������� */
    samTargetInit();
    
    /* ���荞�݋���         */
    EI();
    
    /* ���N�G�X�^���������� */
    dtyRequester.status_enu     = 0;
    dtyRequester.address_pu08   = 0;
    dtyRequester.identifier_u08 = 0;
    dtyRequester.command_enu    = 0;
    dtyRequester.timeout_u08    = 0;
    
    /*== -> uninitialized -> ( EEPROM Emulation state ) ====================*/
    /************************************************************************/
    /* EEPROM�G�~�����[�V�������������� ( state : uninitialized -> closed ) */
    /************************************************************************/
    /* FAL(FDL)�p�����[�^����������      */
    /* ��fdl_descriptor.h��FDL_SYSTEM_FREQUENCY�C�y��EEL_POOL_SIZE�����g����*/
    /*   ���ɍ������ݒ�l(���g���AEEL�u���b�N��)��ݒ肵�Ă��������B      */
    dteFalResult = FAL_Init( &fal_descriptor_str );
    
    /* FAL������������I���̏ꍇ    */
    if( dteFalResult == FAL_OK )
    {
        /* EEL�p�����[�^����������  */
        dtyRequester.status_enu = EEL_Init();
    }
    
    /*== -> closed -> ( EEPROM Emulation state ) =====================================*/
    /**********************************************************************************/
    /* EEPROM�G�~�����[�V������������ ( state : closed -> opened )                    */
    /* ��EEL_Open���s�ȍ~��STOP���[�h�CHALT���[�h, �t���b�V���E�Z���t�E���C�u�����֎~ */
    /**********************************************************************************/
    if( dtyRequester.status_enu == EEL_OK )
    {
        /* EEL */
        EEL_Open();
    }
    
    /*== -> opened -> ( EEPROM Emulation state ) =====================================*/
    /**********************************************************************************/
    /* EEPROM�G�~�����[�V�����J�n���� ( state : opened -> started )                   */
    /**********************************************************************************/
    if( dtyRequester.status_enu == EEL_OK )
    {
        do {
            /* EEL_CMD_STARTUP�R�}���h���s�p�̃p�����[�^��ݒ�  */
            dtyRequester.command_enu = EEL_CMD_STARTUP;        /* EEL_CMD_STARTUP�R�}���h  */
            dtyRequester.timeout_u08 = SAM_EEL_MODE_ENFORCED;  /* Enforced���[�h           */
            
            /* EEL_CMD_STARTUP�R�}���h���s( Enforced���[�h )    */
            EEL_Execute( &dtyRequester );
            
            /* EEPROM�G�~�����[�V�����E�u���b�N�s�����G���[(�u���b�N��������)�̏ꍇ */
            if( dtyRequester.status_enu == EEL_ERR_POOL_INCONSISTENT )
            {
                /* EEL_CMD_FORMAT�R�}���h���s�p�̃p�����[�^��ݒ�   */
                dtyRequester.command_enu = EEL_CMD_FORMAT;         /* EEL_CMD_FORMAT�R�}���h   */
                dtyRequester.timeout_u08 = SAM_EEL_MODE_ENFORCED;  /* Enforced���[�h           */
                
                /* EEL_CMD_STARTUP�R�}���h���s( Enforced���[�h )    */
                EEL_Execute( &dtyRequester );
            }
            
        /* EEL_CMD_FORMAT�R�}���h������������EEL_CMD_STARTUP�R�}���h���ēx���s */
        } while( ( dtyRequester.command_enu == EEL_CMD_FORMAT ) && 
                 ( dtyRequester.status_enu  == EEL_OK         )  );
    }
    
    
    /* EEL_CMD_STARTUP�R�}���h�͐���I���������H */
    if( dtyRequester.status_enu == EEL_OK )
    {
        /*== -> started -> ( EEPROM Emulation state ) ===============================*/
        /*****************************************************************************/
        /* EEL_Handler�֐��ɂ��u���b�N�̐����i�����e�i���X�E���[�h�j: �J�n���ɐ��� */
        /*****************************************************************************/
        samMaintenance( &dtyRequester );
        
        /**********************/
        /* �f�[�^�������ݏ��� */
        /**********************/
        if( dtyRequester.status_enu == EEL_OK )
        {
            /* �������݃f�[�^�̐ݒ� */
            dubDataBuffer[0x00] = 0xFD;
            dubDataBuffer[0x01] = 0xD0;
        
            /* EEL_CMD_WRITE�R�}���h���s�p�̃p�����[�^��ݒ�    */
            dtyRequester.address_pu08   = dubDataBuffer;           /* �g�p����o�b�t�@�̐ݒ�   */
            dtyRequester.identifier_u08 = 'a';                     /* �Ώۃf�[�^��ID��ݒ�     */
            dtyRequester.command_enu    = EEL_CMD_WRITE;           /* EEL_CMD_WRITE�R�}���h    */
            dtyRequester.timeout_u08    = SAM_EEL_MODE_ENFORCED;   /* Enforced���[�h           */
        
            /* EEL_CMD_WRITE�R�}���h���s( Enforced���[�h )      */
            EEL_Execute( &dtyRequester );
        }
        
        /*********************************************************************************/
        /* EEL_Handler�֐��ɂ��u���b�N�̐����i�����e�i���X�E���[�h�j: �������݌�ɐ��� */
        /*********************************************************************************/
        if( dtyRequester.status_enu == EEL_OK )
        {
            samMaintenance( &dtyRequester );
        }
        
        /**********************/
        /* �f�[�^�ǂݍ��ݏ��� */
        /**********************/
        if( dtyRequester.status_enu == EEL_OK )
        {
            /* EEL_CMD_READ�R�}���h���s�p�̃p�����[�^��ݒ�     */
            dtyRequester.address_pu08   = dubReadBuffer;           /* �g�p����o�b�t�@�̐ݒ�   */
            dtyRequester.identifier_u08 = 'a';                     /* �Ώۃf�[�^��ID��ݒ�     */
            dtyRequester.command_enu    = EEL_CMD_READ;            /* EEL_CMD_READ�R�}���h     */
            dtyRequester.timeout_u08    = SAM_EEL_MODE_ENFORCED;   /* Enforced���[�h           */
            
            /* EEL_CMD_READ�R�}���h���s( Enforced���[�h )       */
            EEL_Execute( &dtyRequester );
        }
        
        /************************************************************************************/
        /* EEPROM�G�~�����[�V������~���� ( state : started -> opened )                     */
        /************************************************************************************/
        /* EEL_CMD_SHUTDOWN�R�}���h���s�p�̃p�����[�^��ݒ�     */
        dtyRequester.command_enu = EEL_CMD_SHUTDOWN;       /* EEL_CMD_SHUTDOWN�R�}���h */
        dtyRequester.timeout_u08 = SAM_EEL_MODE_ENFORCED;  /* Enforced���[�h           */
        
        /* EEL_CMD_SHUTDOWN�R�}���h���s( Enforced���[�h )   */
        EEL_Execute( &dtyRequester );
        
    }
    
    /*== -> opened -> ( EEPROM Emulation state ) =======================================*/
    /************************************************************************************/
    /* EEPROM�G�~�����[�V�����I������ ( state : opened -> closed )                      */
    /************************************************************************************/
    EEL_Close();
    
    
    /*== -> closed -> ( EEPROM Emulation state ) =======================================*/
    /************************************************************************************/
    /* EEPROM�G�~�����[�V�����I����� ( state : closed )                                */
    /* �ESTOP���[�h�CHALT���[�h���s�\                                                 */
    /* �E�t���b�V���E�Z���t�E�v���O���~���O�E���C�u�����A���̑��f�[�^�E�t���b�V���֘A   */
    /*   ���C�u�������s�\                                                             */
    /*   �����̑����C�u���������s�����ꍇ ( state : closed -> uninitialized )           */
    /************************************************************************************/
    
    
    /* �^�[�Q�b�g�I������   */
    samTargetEnd();
    
    /*== �I�����[�v ==*/
    while( 1 )
    {
        NOP();
        NOP();
    }
}


/*##############################################################################*/
/*------------------------------------------------------------------------------*/
/* common functions                                                             */
/*------------------------------------------------------------------------------*/
/*==============================================================================*/
/* Function name : samTargetInit                                                */
/* IN            : void                                                         */
/* OUT           : void                                                         */
/* Description   : �^�[�Q�b�g����������                                         */
/* Date          : 07,02,2010                                                   */
/*==============================================================================*/
void samTargetInit( void )
{
    /************************/
    /* �E�H�b�`�h�b�O�^�C�} */
    /************************/
    SAM_WDT_RESET();        /* �E�H�b�`�h�b�O�^�C�}�̃��Z�b�g   */
    
    /*******************/
    /* LED�̏��������� */
    /*******************/
    SAM_LED1_INIT();        /* LED1������(����) */
    SAM_LED2_INIT();        /* LED2������(����) */
    SAM_LED1_ON();          /* LED1�_��         */
    SAM_LED2_ON();          /* LED2�_��         */
}


/*==============================================================================*/
/* Function name : samTargetEnd                                                 */
/* IN            : void                                                         */
/* OUT           : void                                                         */
/* Description   : �^�[�Q�b�g�I������                                           */
/* Date          : 07,02,2010                                                   */
/*==============================================================================*/
void samTargetEnd( void )
{
    SAM_LED1_OFF();         /* LED1����         */
    SAM_LED2_OFF();         /* LED2����         */
}


/*##############################################################################*/
/*------------------------------------------------------------------------------*/
/* sub functions                                                                */
/*------------------------------------------------------------------------------*/
/*==============================================================================*/
/* Function name : samMaintenance                                               */
/* IN            : ptyRequester / ���s�p�����[�^                                */
/* OUT           : void          / ����                                         */
/* Description   : �����e�i���X�֐�( �R�}���h�I����Ɏ��s )                     */
/* Date          : 08,23,2010                                                   */
/*==============================================================================*/
void samMaintenance( eel_request_t *ptyRequester  )
{
    /* �ϐ���` */
    __near eel_driver_status_t  dteDriverStatus;
    eel_u16                     duhMainteCounter;
    
    /* �����e�i���X���I������܂Ń��[�v */
    for( duhMainteCounter = 0 ; duhMainteCounter < SAM_EEL_MAINTE_END ; )
    {
        /* �����e�i���X���� */
        EEL_Handler( SAM_EEL_MODE_POLLING );        /* �����e�i���X���s     */
        EEL_GetDriverStatus( &dteDriverStatus );    /* ���C�u������Ԋm�F   */
        
        /* �����e�i���X�E���[�h�I�����(�ꎞ�I�ȏI�����܂�) */
        if( ( ptyRequester->status_enu            == EEL_OK             ) &&
            ( dteDriverStatus.operationStatus_enu == EEL_OPERATION_IDLE ) )
        {
            /* �����e�i���X�E���[�h�I����Ԋm�F�񐔂��C���N�������g */
            duhMainteCounter++;
        }
        /* �����e�i���X�� */
        else if( ( ptyRequester->status_enu == EEL_OK   ) ||
                 ( ptyRequester->status_enu == EEL_BUSY ) )
        {
            /* �����e�i���X���Ȃ̂ŏI����Ԋm�F�񐔂�0�N���A */
            duhMainteCounter = 0;
        }
        /* �G���[�����̂��߁A�����e�i���X�������I�� */
        else {
            break;
        }
    }
}


/*##############################################################################*/
/*------------------------------------------------------------------------------*/
/* interrupt functions                                                          */
/*------------------------------------------------------------------------------*/
/*==============================================================================*/
/* Function name : samIntWdt                                                    */
/* IN            : void                                                         */
/* OUT           : void                                                         */
/* Description   : WDT���Z�b�g�֐�                                              */
/* Date          : 07,02,2010                                                   */
/*==============================================================================*/
void samIntWdt( void )
{
    SAM_WDT_RESET();
}


