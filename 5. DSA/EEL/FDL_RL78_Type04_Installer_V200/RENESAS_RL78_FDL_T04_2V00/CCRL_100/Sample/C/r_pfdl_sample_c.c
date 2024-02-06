/*==============================================================================*/
/*                                                                              */
/* Project     = Sample program for data flash library.                         */
/* Module      = r_pfdl_sample_c.c                                              */
/* Version     = V1.00(Target FDL Version for CC-RL is V1.05                    */
/* Target CPU  = RL78/G13 ( R5F100LEA / QB-R5F100LE-TB )                        */
/* Tool-Chain  = CS+ for CC-RL (V3.00)                                          */
/*                                                                              */
/* Date        = 10, 31, 2018                                                   */
/*                                                                              */
/*==============================================================================*/
/*                                COPYRIGHT                                     */
/*==============================================================================*/
/* DISCLAIMER                                                                   */
/* This software is supplied by Renesas Electronics Corporation and is only     */
/* intended for use with Renesas products. No other uses are authorized. This   */
/* software is owned by Renesas Electronics Corporation and is protected under  */
/* all applicable laws, including copyright laws.                               */
/* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING  */
/* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT      */
/* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE   */
/* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.          */
/* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS       */
/* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  */
/* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR   */
/* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE  */
/* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.                             */
/* Renesas reserves the right, without notice, to make changes to this software */
/* and to discontinue the availability of this software. By using this software,*/
/* you agree to the additional terms and conditions found by accessing the      */
/* following link:                                                              */
/* http://www.renesas.com/disclaimer                                            */
/*                                                                              */
/* Copyright (C) 2018 Renesas Electronics Corporation. All rights reserved.     */
/*==============================================================================*/
/********************************************************************************/
/* History       : Version Description                                          */
/*               : 10.31.2018 1.00 First Release                                */
/********************************************************************************/

/******************************************************************************
 Expanded function
******************************************************************************/
#include "iodefine.h"
/******************************************************************************
 interrupt function
******************************************************************************/
#pragma interrupt r_pfdl_samIntWdt (vect=INTWDTI)  /* WDT���荞��            */


/******************************************************/
/* �T���v���v���O�����E�v���O�����X�C�b�`�p�V���{��   */
/******************************************************/
#if 0
/* QB-R5F100LE-TB�P�̎g�p���ɐݒ�\ */
#define __QB_R5F100LE_TB__

#else
/* ���̑��{�[�h */
#define __NON_TARGET__
#endif


/******************************************************************************
 Include <System Includes>, "Project Includes"
******************************************************************************/
/* �W�����C�u����(�����^�C���E���C�u�����g�p) */
#include <string.h>

/* �f�[�^�E�t���b�V���E���C�u���� */
#include "pfdl.h"                /* ���C�u�����E�w�b�_�t�@�C��               */
#include "pfdl_types.h"          /* ���C�u�����E�w�b�_�t�@�C��               */

/******************************************************************************
 Typedef definitions
******************************************************************************/


/******************************************************************************
 Macro definitions
******************************************************************************/
/* �W����` */
#define TRUE                    1
#define FALSE                   0

/* �����؂�ւ��p��` */
#define R_PFDL_SAM_TARGET_ERASE TRUE    /* ���O�����ݒ�(TRUE�Ŏ��s)           */
#define R_PFDL_SAM_DIRECT_READ  TRUE    /* �f�[�^�E�t���b�V�����ړǍ��ݒ�     */
                                        /* ���f�[�^�E�t���b�V���������ւ�     */
                                        /* �A�N�Z�X����ԂŃo�C�g�E         */
                                        /* �A�N�Z�X���s���̂݉\             */
/* ��{�f�[�^ */
#define R_PFDL_SAM_BLOCK_SIZE   0x400l  /* �W���u���b�N�E�T�C�Y               */
#define R_PFDL_SAM_TARGET_BLOCK 0       /* �������݊J�n�u���b�N(0x0:F1000H)   */
#define R_PFDL_SAM_WRITE_SIZE   10      /* �������݃f�[�^�T�C�Y               */
#define R_PFDL_SAM_DREAD_OFSET  0x1000  /* ���ړǂݍ��݃I�t�Z�b�g�E�A�h���X   */

/* PFDL�����ݒ�l */
#define R_PFDL_SAM_FDL_FRQ      32      /* ���g���ݒ�(32MHz)                  */
#define R_PFDL_SAM_FDL_VOL      0x00    /* �d�����[�h(�t���X�s�[�h���[�h)�ݒ� */

/* �T���v���v���O�����p�A����}�N�� */
#define R_PFDL_SAM_WDT_RESET()  WDTE = 0xAC /* �E�H�b�`�h�b�O�^�C�}�̃��Z�b�g */

/*********************************************************/
/* QB-R5F100LE-TB�p�������݃V���{����`                  */
/*********************************************************/
#ifdef __QB_R5F100LE_TB__
/* QB-R5F100LE-TB, LED����}�N�� */
#define R_PFDL_SAM_LED1_INIT() P6_bit.no2 = 1, PM6_bit.no2 = 0
                                              /* �I���{�[�h��LED1��������(��_��) */
#define R_PFDL_SAM_LED1_ON()   P6_bit.no2 = 0 /* �I���{�[�h��LED1��_��           */
#define R_PFDL_SAM_LED1_OFF()  P6_bit.no2 = 1 /* �I���{�[�h��LED1������           */

#define R_PFDL_SAM_LED2_INIT() P6_bit.no3 = 1, PM6_bit.no3 = 0
                                              /* �I���{�[�h��LED2��������(��_��) */
#define R_PFDL_SAM_LED2_ON()   P6_bit.no3 = 0 /* �I���{�[�h��LED2��_��           */
#define R_PFDL_SAM_LED2_OFF()  P6_bit.no3 = 1 /* �I���{�[�h��LED2������           */

/*************************************/
/* �ʏ�̏������ݐݒ�p �V���{����` */
/*************************************/
#else 
/* LED�͏�������(�����R�[�h) */
#define R_PFDL_SAM_LED1_INIT()
#define R_PFDL_SAM_LED1_ON()
#define R_PFDL_SAM_LED1_OFF()
#define R_PFDL_SAM_LED2_INIT()
#define R_PFDL_SAM_LED2_ON()
#define R_PFDL_SAM_LED2_OFF()

#endif

/******************************************************************************
 External reference parameter
******************************************************************************/


/******************************************************************************
 Prototype declarations
******************************************************************************/
/* �^�[�Q�b�g�{�[�h�p�T���v���֐� */
void    r_pfdl_samTargetInit( void );       /* �^�[�Q�b�g�{�[�h���������� */
void    r_pfdl_samTargetEnd ( void );       /* �^�[�Q�b�g�{�[�h�I������   */

/* �������݃v���O�����p�T���v���֐� */
pfdl_status_t r_pfdl_samFdlStart ( void );  /* pfdl����������             */
void          r_pfdl_samFdlEnd   ( void );  /* pfdl�I������               */


/*############################################################################*/
/******************************************************************************
* Outline           : hdwinit function
* Include           : none
* Declaration       : void hdwinit(void)
* Description       : Initialization of the hardware.
* Argument          : none
* Return Value      : none
* Calling Functions : start-up routine
******************************************************************************/
void hdwinit( void )
{
    /************************/
    /* ��d�����o��H�̐ݒ� */
    /************************/
    LVIM = 0x00;                /* ��d�����o���W�X�^�̐ݒ��������           */
    LVIS = 0x00;                /* ��d�����o���x���I�����W�X�^�̐ݒ�������� */
    
#if 0
/* QB-R5F100LE-TB�p�A�O���N���b�N��20MHz���U�ւ̐ؑ֐ݒ� */
    /****************************************************************/
    /* �N���b�N���䃌�W�X�^�̏�����                                 */
    /* ����N���b�N��������U����X1(20MHz��z��)���U�ɕύX          */
    /* ��R_PFDL_SAM_FDL_FRQ(���g��)��20�ɐݒ肷��                   */
    /****************************************************************/
    /* �T�u�V�X�e���E�N���b�N�������[�h���䃌�W�X�^ */
    OSMC = 0b00000000;          /* ���Ӌ@�\�ւ̃T�u�V�X�e���E�N���b�N�������ɐݒ�         */
    
    /* �N���b�N���샂�[�h���䃌�W�X�^       */
    CMC  = 0b01010001;          /* X1,XT1�[�q���U���[�h�AX1���g����10MHz��fMX��20MHz�ɐݒ�  */
    
    /* X1���U���莞�ԑI�����W�X�^           */
    OSTS = 0b00000011;          /* X1���U���莞�Ԃ�ݒ� ( fx = 20 MHz�� / 102.4 �� s�ȏ� )  */
    
    /* �N���b�N����X�e�[�^�X���䃌�W�X�^   */
    CSC  = 0b00000000;          /* X1,XT1���U�J�n                                           */
    
    /* ���U���莞�ԃJ�E���^��ԃ��W�X�^     */
    while( ( 0xF0 & OSTC ) != 0xF0 );       /* X1���U���莞�ԑ҂�                           */
    
    /* �V�X�e���E�N���b�N���䃌�W�X�^       */
    CKC  = 0b00010000;          /* ���C���E�V�X�e���E�N���b�N��������U����X1���U�ɕύX     */
    
    while( MCS  == 0 );         /* ���C���E�V�X�e���E�N���b�N�ifMAIN�j�̃X�e�[�^�X�m�F      */
                                /* �����U��H�ؑ֊m�F ( MCS : CKC���W�X�^ 5bit��  )         */
    
    /* �N���b�N����X�e�[�^�X���䃌�W�X�^ : �����I���`�b�v�E�I�V���[�^���쐧��              */
    /* HIOSTOP = 1; */          /* CSC = 0b00000001 : �����I���`�b�v�I�V���[�^��~          */
    /* RL78�̃f�[�^�E�t���b�V�������������ɍ����I���`�b�v�E�I�V���[�^�̔��U���K�v�Ȃ��߁A   */
    /* �����I���`�b�v�E�I�V���[�^�͒�~�����Ȃ��B                                           */
    
#endif
}


/******************************************************************************
* Outline           : main function
* Include           : none
* Declaration       : void main( void )
* Description       : Main cord of the sample.
* Argument          : none
* Return Value      : none
* Calling Functions : start-up routine 
******************************************************************************/
void main( void )
{
    /* ���ʕϐ��錾 */
    pfdl_status_t   dtyFdlResult;       /* ���^�[���l                       */
    pfdl_request_t  dtyRequester;       /* PFDL����p�ϐ�(���N�G�X�^)       */
    pfdl_u08        dubWriteBuffer[ R_PFDL_SAM_WRITE_SIZE ] = {0,1,2,3,4,5,6,7,8,9};
                                        /* �������݃f�[�^���̓o�b�t�@(�����l��ݒ�) */
    
    /* �^�[�Q�b�g�{�[�h���������� */
    r_pfdl_samTargetInit();
    
    /* ���荞�݋���         */
    __EI();
    
    /* FDL�̏���������      */
    dtyFdlResult = r_pfdl_samFdlStart();
    
    /* ���N�G�X�^���������� */
    dtyRequester.index_u16     = 0;
    dtyRequester.data_pu08     = dubWriteBuffer;
    dtyRequester.bytecount_u16 = 0;
    dtyRequester.command_enu   = PFDL_CMD_READ_BYTES; /* PFDL_CMD_READ_BYTES(= 0)�ŏ����� */
    
#if R_PFDL_SAM_TARGET_ERASE
/* ���O�������s���ꍇ�́A�Ώۃu���b�N�S�̂̃u�����N�`�F�b�N���s���A��������B */
    if( dtyFdlResult == PFDL_OK )
    {
        /* �Ώۃu���b�N�S�̂̃u�����N�`�F�b�N����/�u�����N�`�F�b�N�E�R�}���h��ݒ肷�� */
        dtyRequester.command_enu   = PFDL_CMD_BLANKCHECK_BYTES;
        
        /* �J�n�A�h���X�Ǝ��s�͈͂�400H(1024)�o�C�g�ɐݒ肷�� */
        dtyRequester.index_u16     = R_PFDL_SAM_TARGET_BLOCK * R_PFDL_SAM_BLOCK_SIZE;
        dtyRequester.bytecount_u16 = R_PFDL_SAM_BLOCK_SIZE;
        
        /* �R�}���h���s���� */
        dtyFdlResult = PFDL_Execute( &dtyRequester );
        
        /* �R�}���h�I���҂� */
        while( dtyFdlResult == PFDL_BUSY )
        {
            /* �����s��������Ƃ�����΍s��(�o�b�N�E�O���E���h�E�I�y���[�V����) */
            __nop();
            __nop();
            
            /* �I���m�F���� */
            dtyFdlResult = PFDL_Handler();
        }
        
        /* �Ώۃu���b�N���u�����N��ԂłȂ��ꍇ�͏����R�}���h�����s */
        if( dtyFdlResult == PFDL_ERR_MARGIN )
        {
            /* �Ώۃu���b�N�̏�������/�����R�}���h��ݒ肷�� */
            dtyRequester.command_enu = PFDL_CMD_ERASE_BLOCK;
            
            /* �Ώۃu���b�N�̃u���b�N�ԍ���ݒ肷�� */
            dtyRequester.index_u16   = R_PFDL_SAM_TARGET_BLOCK;
            
            /* �R�}���h���s���� */
            dtyFdlResult = PFDL_Execute( &dtyRequester );
            
            /* �R�}���h�I���҂� */
            while( dtyFdlResult == PFDL_BUSY )
            {
                /* �����s��������Ƃ�����΍s��(�o�b�N�E�O���E���h�E�I�y���[�V����) */
                __nop();
                __nop();
                
                /* �I���m�F���� */
                dtyFdlResult = PFDL_Handler();
            }
        }
    }
#endif
    
    /* �f�[�^�������ݏ��� */
    if( dtyFdlResult == PFDL_OK )
    {
        /* �������ݗp�ϐ���` */
        pfdl_u16    duhWriteAddress;
        
        /* �������݂��s���O�ɑΏۗ̈�̃u�����N�`�F�b�N���s�� */
        /* �u�����N�`�F�b�N�E�R�}���h��ݒ肷��               */
        dtyRequester.command_enu   = PFDL_CMD_BLANKCHECK_BYTES;
        /* �������݃f�[�^�T�C�Y��ݒ肷��                     */
        dtyRequester.bytecount_u16 = R_PFDL_SAM_WRITE_SIZE;
        
        /* �������݃`�F�b�N���[�v(�u�����N�`�F�b�N�����A�������݉\�ȗ̈��T��) */
        for( duhWriteAddress  = R_PFDL_SAM_TARGET_BLOCK * R_PFDL_SAM_BLOCK_SIZE         ;
             duhWriteAddress  < ( R_PFDL_SAM_TARGET_BLOCK + 1 ) * R_PFDL_SAM_BLOCK_SIZE ;
             duhWriteAddress += R_PFDL_SAM_WRITE_SIZE )
        {
            /* �������݊J�n�A�h���X��ݒ肷�� */
            dtyRequester.index_u16 = duhWriteAddress;
            
            /* �R�}���h���s���� */
            dtyFdlResult = PFDL_Execute( &dtyRequester );
            
            /* �R�}���h�I���҂� */
            while( dtyFdlResult == PFDL_BUSY )
            {
                /* �����s��������Ƃ�����΍s��(�o�b�N�E�O���E���h�E�I�y���[�V����) */
                __nop();
                __nop();
                
                /* �I���m�F���� */
                dtyFdlResult = PFDL_Handler();
            }
            
            /* �u�����N��Ԃł���Ώ������݂��s�� */
            if( dtyFdlResult == PFDL_OK )
            {
                /* �������݃R�}���h��ݒ肷��(�������݃f�[�^�ƃo�b�t�@�͊��ɐݒ�ς�) */
                dtyRequester.command_enu = PFDL_CMD_WRITE_BYTES;
                
                /* �R�}���h���s���� */
                dtyFdlResult = PFDL_Execute( &dtyRequester );
                
                /* �R�}���h�I���҂� */
                while( dtyFdlResult == PFDL_BUSY )
                {
                    /* �����s��������Ƃ�����΍s��(�o�b�N�E�O���E���h�E�I�y���[�V����) */
                    __nop();
                    __nop();
                    
                    /* �I���m�F��1�o�C�g�������ݖ��̃g���K�[���� */
                    dtyFdlResult = PFDL_Handler();
                }
                
                /* �������݂�����I������������x���t�@�C���������s */
                if( dtyFdlResult == PFDL_OK )
                {
                    /* �����x���t�@�C�R�}���h��ݒ肷�� */
                    dtyRequester.command_enu = PFDL_CMD_IVERIFY_BYTES;
                    
                    /* �R�}���h���s���� */
                    dtyFdlResult = PFDL_Execute( &dtyRequester );
                    
                    /* �R�}���h�I���҂� */
                    while( dtyFdlResult == PFDL_BUSY )
                    {
                        /* �����s��������Ƃ�����΍s��(�o�b�N�E�O���E���h�E�I�y���[�V����) */
                        __nop();
                        __nop();
                        
                        /* �I���m�F���� */
                        dtyFdlResult = PFDL_Handler();
                    }
                }

#if R_PFDL_SAM_DIRECT_READ
/* ���ړǂݍ��݂Ńf�[�^�̊m�F(�f�[�^�E�t���b�V�����������A�N�Z�X�\�ȏ�ԂŁAByte�A�N�Z�X�̂ݎ��s�\) */
/* �Ȃ��A�f�[�^�E�t���b�V���֏������ݓ����s���Ă���ꍇ�͐���ɓǂݍ��ގ��͂ł��܂���B                 */
                /* �f�[�^�̊m�F���� */
                if( dtyFdlResult == PFDL_OK )
                {
                    /* �ǂݍ��ݗp�̕ϐ���` */
                    unsigned short        duh_i;        /* ���[�v�ϐ���` */
                    __near unsigned char *pubReadData;  /* ���ړǂݍ��ݗp�|�C���^(Byte�A�N�Z�X�̂݉\) */
                    
                    pubReadData = (__near unsigned char *) duhWriteAddress + R_PFDL_SAM_DREAD_OFSET;
                    
                    /* �ǂݍ��݃f�[�^�Ə������݃f�[�^�̔�r */
                    for( duh_i = 0 ; duh_i < R_PFDL_SAM_WRITE_SIZE ; duh_i++ )
                    {
                        if( dubWriteBuffer[ duh_i ] != pubReadData[ duh_i ] )
                        {
                            /* �ǂݍ��݃f�[�^�Ə������݃f�[�^�ɍ������������ꍇ�̓G���[�Ƃ���B */
                            dtyFdlResult = PFDL_ERR_PARAMETER;
                            break;
                        }
                    }
                }
#else
/* �f�[�^�E�t���b�V���E���C�u�����̓ǂݍ��݋@�\�𗘗p */
                /* �f�[�^�̊m�F���� */
                if( dtyFdlResult == PFDL_OK )
                {
                    /* �ǂݍ��ݗp�̕ϐ���` */
                    pfdl_u16    duh_i;      /* ���[�v�ϐ���` */
                    pfdl_u08    dubReadBuffer [ R_PFDL_SAM_WRITE_SIZE ];
                                            /* �ǂݍ��݃f�[�^���̓o�b�t�@ */
                    
                    /* �ǂݍ��݃R�}���h��ݒ肷�� */
                    dtyRequester.command_enu = PFDL_CMD_READ_BYTES;
                    
                    /* �ǂݍ��݊J�n�A�h���X��ݒ肷�� */
                    dtyRequester.index_u16   = duhWriteAddress;
                    
                    /* �ǂݍ��݃f�[�^���̓o�b�t�@�̃A�h���X��ݒ肷�� */
                    dtyRequester.data_pu08   = dubReadBuffer;
                    
                    /* �R�}���h���s���� */
                    dtyFdlResult = PFDL_Execute( &dtyRequester );
                    
                    /* �ǂݍ��݃f�[�^�Ə������݃f�[�^�̔�r */
                    for( duh_i = 0 ; duh_i < R_PFDL_SAM_WRITE_SIZE ; duh_i++ )
                    {
                        if( dubWriteBuffer[ duh_i ] != dubReadBuffer[ duh_i ] )
                        {
                            /* �ǂݍ��݃f�[�^�Ə������݃f�[�^�ɍ������������ꍇ�̓G���[�Ƃ���B */
                            dtyFdlResult = PFDL_ERR_PARAMETER;
                            break;
                        }
                    }
                }
#endif
                break;
            }
            /* �s���ȃG���[�����������ꍇ�͏����𒆒f����B */
            else if( dtyFdlResult != PFDL_ERR_MARGIN ) {
                break;
            }
        }
    }
    
    /* FDL�I������ */
    r_pfdl_samFdlEnd();
    
    /* �^�[�Q�b�g�{�[�h�I������ */
    r_pfdl_samTargetEnd();
    
    /* �I�����[�v */
    while( 1 )
    {
        __nop();
        __nop();
    }
}


/******************************************************************************
* Outline           : Initialization start function
* Include           : none
* Declaration       : void r_pfdl_samTargetInit( void )
* Description       : Initialization of the target board.
* Argument          : none
* Return Value      : none
* Calling Functions : main
******************************************************************************/
void r_pfdl_samTargetInit( void )
{
    /************************/
    /* �E�H�b�`�h�b�O�^�C�} */
    /************************/
    R_PFDL_SAM_WDT_RESET();        /* �E�H�b�`�h�b�O�^�C�}�̃��Z�b�g */
    
    /*******************/
    /* LED�̏��������� */
    /*******************/
    R_PFDL_SAM_LED1_INIT();        /* LED1������(����) */
    R_PFDL_SAM_LED2_INIT();        /* LED2������(����) */
    R_PFDL_SAM_LED1_ON();          /* LED1�_��         */
    R_PFDL_SAM_LED2_ON();          /* LED2�_��         */
}


/******************************************************************************
* Outline           : Target board end function
* Include           : none
* Declaration       : void r_pfdl_samTargetEnd( void )
* Description       : End of the target board.
* Argument          : none
* Return Value      : none
* Calling Functions : main
******************************************************************************/
void r_pfdl_samTargetEnd( void )
{
    R_PFDL_SAM_LED1_OFF();         /* LED1����         */
    R_PFDL_SAM_LED2_OFF();         /* LED2����         */
}


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
    
    /* �����l���� */
    dtyDescriptor.fx_MHz_u08            = R_PFDL_SAM_FDL_FRQ;  /* ���g���ݒ�     */
    dtyDescriptor.wide_voltage_mode_u08 = R_PFDL_SAM_FDL_VOL;  /* �d�����[�h�ݒ� */
    
    /* PFDL�������֐����s */
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
    /* �f�[�^�E�t���b�V���E���C�u�����I������ */
    PFDL_Close();
}


/*##############################################################################*/
/*------------------------------------------------------------------------------*/
/* interrupt functions                                                          */
/*------------------------------------------------------------------------------*/
/******************************************************************************
* Outline           : WDT reset function
* Include           : none
* Declaration       : void r_pfdl_samIntWdt( void )
* Description       : Resets the WDT based on a WDT interval interrupt.
* Argument          : none
* Return Value      : none
* Calling Functions : Hardware
******************************************************************************/
__near void r_pfdl_samIntWdt( void )
{
    R_PFDL_SAM_WDT_RESET();
}

