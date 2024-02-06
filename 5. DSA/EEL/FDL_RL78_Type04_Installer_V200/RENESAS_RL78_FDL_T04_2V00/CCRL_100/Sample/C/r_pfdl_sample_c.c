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
#pragma interrupt r_pfdl_samIntWdt (vect=INTWDTI)  /* WDT割り込み            */


/******************************************************/
/* サンプルプログラム・プログラムスイッチ用シンボル   */
/******************************************************/
#if 0
/* QB-R5F100LE-TB単体使用時に設定可能 */
#define __QB_R5F100LE_TB__

#else
/* その他ボード */
#define __NON_TARGET__
#endif


/******************************************************************************
 Include <System Includes>, "Project Includes"
******************************************************************************/
/* 標準ライブラリ(ランタイム・ライブラリ使用) */
#include <string.h>

/* データ・フラッシュ・ライブラリ */
#include "pfdl.h"                /* ライブラリ・ヘッダファイル               */
#include "pfdl_types.h"          /* ライブラリ・ヘッダファイル               */

/******************************************************************************
 Typedef definitions
******************************************************************************/


/******************************************************************************
 Macro definitions
******************************************************************************/
/* 標準定義 */
#define TRUE                    1
#define FALSE                   0

/* 処理切り替え用定義 */
#define R_PFDL_SAM_TARGET_ERASE TRUE    /* 事前消去設定(TRUEで実行)           */
#define R_PFDL_SAM_DIRECT_READ  TRUE    /* データ・フラッシュ直接読込設定     */
                                        /* ※データ・フラッシュメモリへの     */
                                        /* アクセス許可状態でバイト・         */
                                        /* アクセス実行時のみ可能             */
/* 基本データ */
#define R_PFDL_SAM_BLOCK_SIZE   0x400l  /* 標準ブロック・サイズ               */
#define R_PFDL_SAM_TARGET_BLOCK 0       /* 書き込み開始ブロック(0x0:F1000H)   */
#define R_PFDL_SAM_WRITE_SIZE   10      /* 書き込みデータサイズ               */
#define R_PFDL_SAM_DREAD_OFSET  0x1000  /* 直接読み込みオフセット・アドレス   */

/* PFDL初期設定値 */
#define R_PFDL_SAM_FDL_FRQ      32      /* 周波数設定(32MHz)                  */
#define R_PFDL_SAM_FDL_VOL      0x00    /* 電圧モード(フルスピードモード)設定 */

/* サンプルプログラム用、制御マクロ */
#define R_PFDL_SAM_WDT_RESET()  WDTE = 0xAC /* ウォッチドッグタイマのリセット */

/*********************************************************/
/* QB-R5F100LE-TB用書き込みシンボル定義                  */
/*********************************************************/
#ifdef __QB_R5F100LE_TB__
/* QB-R5F100LE-TB, LED制御マクロ */
#define R_PFDL_SAM_LED1_INIT() P6_bit.no2 = 1, PM6_bit.no2 = 0
                                              /* オンボードのLED1を初期化(非点灯) */
#define R_PFDL_SAM_LED1_ON()   P6_bit.no2 = 0 /* オンボードのLED1を点灯           */
#define R_PFDL_SAM_LED1_OFF()  P6_bit.no2 = 1 /* オンボードのLED1を消灯           */

#define R_PFDL_SAM_LED2_INIT() P6_bit.no3 = 1, PM6_bit.no3 = 0
                                              /* オンボードのLED2を初期化(非点灯) */
#define R_PFDL_SAM_LED2_ON()   P6_bit.no3 = 0 /* オンボードのLED2を点灯           */
#define R_PFDL_SAM_LED2_OFF()  P6_bit.no3 = 1 /* オンボードのLED2を消灯           */

/*************************************/
/* 通常の書き込み設定用 シンボル定義 */
/*************************************/
#else 
/* LEDは処理無し(無効コード) */
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
/* ターゲットボード用サンプル関数 */
void    r_pfdl_samTargetInit( void );       /* ターゲットボード初期化処理 */
void    r_pfdl_samTargetEnd ( void );       /* ターゲットボード終了処理   */

/* 書き込みプログラム用サンプル関数 */
pfdl_status_t r_pfdl_samFdlStart ( void );  /* pfdl初期化処理             */
void          r_pfdl_samFdlEnd   ( void );  /* pfdl終了処理               */


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
    /* 低電圧検出回路の設定 */
    /************************/
    LVIM = 0x00;                /* 低電圧検出レジスタの設定を初期化           */
    LVIS = 0x00;                /* 低電圧検出レベル選択レジスタの設定を初期化 */
    
#if 0
/* QB-R5F100LE-TB用、外部クロックの20MHz発振への切替設定 */
    /****************************************************************/
    /* クロック制御レジスタの初期化                                 */
    /* 動作クロックを内蔵発振からX1(20MHzを想定)発振に変更          */
    /* ※R_PFDL_SAM_FDL_FRQ(周波数)を20に設定する                   */
    /****************************************************************/
    /* サブシステム・クロック供給モード制御レジスタ */
    OSMC = 0b00000000;          /* 周辺機能へのサブシステム・クロック供給許可に設定         */
    
    /* クロック動作モード制御レジスタ       */
    CMC  = 0b01010001;          /* X1,XT1端子発振モード、X1周波数を10MHz＜fMX≦20MHzに設定  */
    
    /* X1発振安定時間選択レジスタ           */
    OSTS = 0b00000011;          /* X1発振安定時間を設定 ( fx = 20 MHz時 / 102.4 μ s以上 )  */
    
    /* クロック動作ステータス制御レジスタ   */
    CSC  = 0b00000000;          /* X1,XT1発振開始                                           */
    
    /* 発振安定時間カウンタ状態レジスタ     */
    while( ( 0xF0 & OSTC ) != 0xF0 );       /* X1発振安定時間待ち                           */
    
    /* システム・クロック制御レジスタ       */
    CKC  = 0b00010000;          /* メイン・システム・クロックを内蔵発振からX1発振に変更     */
    
    while( MCS  == 0 );         /* メイン・システム・クロック（fMAIN）のステータス確認      */
                                /* ※発振回路切替確認 ( MCS : CKCレジスタ 5bit目  )         */
    
    /* クロック動作ステータス制御レジスタ : 高速オンチップ・オシレータ動作制御              */
    /* HIOSTOP = 1; */          /* CSC = 0b00000001 : 高速オンチップオシレータ停止          */
    /* RL78のデータ・フラッシュ書き換え時に高速オンチップ・オシレータの発振が必要なため、   */
    /* 高速オンチップ・オシレータは停止させない。                                           */
    
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
    /* 共通変数宣言 */
    pfdl_status_t   dtyFdlResult;       /* リターン値                       */
    pfdl_request_t  dtyRequester;       /* PFDL制御用変数(リクエスタ)       */
    pfdl_u08        dubWriteBuffer[ R_PFDL_SAM_WRITE_SIZE ] = {0,1,2,3,4,5,6,7,8,9};
                                        /* 書き込みデータ入力バッファ(初期値を設定) */
    
    /* ターゲットボード初期化処理 */
    r_pfdl_samTargetInit();
    
    /* 割り込み許可         */
    __EI();
    
    /* FDLの初期化処理      */
    dtyFdlResult = r_pfdl_samFdlStart();
    
    /* リクエスタ初期化処理 */
    dtyRequester.index_u16     = 0;
    dtyRequester.data_pu08     = dubWriteBuffer;
    dtyRequester.bytecount_u16 = 0;
    dtyRequester.command_enu   = PFDL_CMD_READ_BYTES; /* PFDL_CMD_READ_BYTES(= 0)で初期化 */
    
#if R_PFDL_SAM_TARGET_ERASE
/* 事前消去を行う場合は、対象ブロック全体のブランクチェックを行い、消去する。 */
    if( dtyFdlResult == PFDL_OK )
    {
        /* 対象ブロック全体のブランクチェック処理/ブランクチェック・コマンドを設定する */
        dtyRequester.command_enu   = PFDL_CMD_BLANKCHECK_BYTES;
        
        /* 開始アドレスと実行範囲を400H(1024)バイトに設定する */
        dtyRequester.index_u16     = R_PFDL_SAM_TARGET_BLOCK * R_PFDL_SAM_BLOCK_SIZE;
        dtyRequester.bytecount_u16 = R_PFDL_SAM_BLOCK_SIZE;
        
        /* コマンド実行処理 */
        dtyFdlResult = PFDL_Execute( &dtyRequester );
        
        /* コマンド終了待ち */
        while( dtyFdlResult == PFDL_BUSY )
        {
            /* 何か行いたい作業があれば行う(バック・グラウンド・オペレーション) */
            __nop();
            __nop();
            
            /* 終了確認処理 */
            dtyFdlResult = PFDL_Handler();
        }
        
        /* 対象ブロックがブランク状態でない場合は消去コマンドを実行 */
        if( dtyFdlResult == PFDL_ERR_MARGIN )
        {
            /* 対象ブロックの消去処理/消去コマンドを設定する */
            dtyRequester.command_enu = PFDL_CMD_ERASE_BLOCK;
            
            /* 対象ブロックのブロック番号を設定する */
            dtyRequester.index_u16   = R_PFDL_SAM_TARGET_BLOCK;
            
            /* コマンド実行処理 */
            dtyFdlResult = PFDL_Execute( &dtyRequester );
            
            /* コマンド終了待ち */
            while( dtyFdlResult == PFDL_BUSY )
            {
                /* 何か行いたい作業があれば行う(バック・グラウンド・オペレーション) */
                __nop();
                __nop();
                
                /* 終了確認処理 */
                dtyFdlResult = PFDL_Handler();
            }
        }
    }
#endif
    
    /* データ書き込み処理 */
    if( dtyFdlResult == PFDL_OK )
    {
        /* 書き込み用変数定義 */
        pfdl_u16    duhWriteAddress;
        
        /* 書き込みを行う前に対象領域のブランクチェックを行う */
        /* ブランクチェック・コマンドを設定する               */
        dtyRequester.command_enu   = PFDL_CMD_BLANKCHECK_BYTES;
        /* 書き込みデータサイズを設定する                     */
        dtyRequester.bytecount_u16 = R_PFDL_SAM_WRITE_SIZE;
        
        /* 書き込みチェックループ(ブランクチェックをし、書き込み可能な領域を探す) */
        for( duhWriteAddress  = R_PFDL_SAM_TARGET_BLOCK * R_PFDL_SAM_BLOCK_SIZE         ;
             duhWriteAddress  < ( R_PFDL_SAM_TARGET_BLOCK + 1 ) * R_PFDL_SAM_BLOCK_SIZE ;
             duhWriteAddress += R_PFDL_SAM_WRITE_SIZE )
        {
            /* 書き込み開始アドレスを設定する */
            dtyRequester.index_u16 = duhWriteAddress;
            
            /* コマンド実行処理 */
            dtyFdlResult = PFDL_Execute( &dtyRequester );
            
            /* コマンド終了待ち */
            while( dtyFdlResult == PFDL_BUSY )
            {
                /* 何か行いたい作業があれば行う(バック・グラウンド・オペレーション) */
                __nop();
                __nop();
                
                /* 終了確認処理 */
                dtyFdlResult = PFDL_Handler();
            }
            
            /* ブランク状態であれば書き込みを行う */
            if( dtyFdlResult == PFDL_OK )
            {
                /* 書き込みコマンドを設定する(書き込みデータとバッファは既に設定済み) */
                dtyRequester.command_enu = PFDL_CMD_WRITE_BYTES;
                
                /* コマンド実行処理 */
                dtyFdlResult = PFDL_Execute( &dtyRequester );
                
                /* コマンド終了待ち */
                while( dtyFdlResult == PFDL_BUSY )
                {
                    /* 何か行いたい作業があれば行う(バック・グラウンド・オペレーション) */
                    __nop();
                    __nop();
                    
                    /* 終了確認と1バイト書き込み毎のトリガー処理 */
                    dtyFdlResult = PFDL_Handler();
                }
                
                /* 書き込みが正常終了したら内部ベリファイ処理を実行 */
                if( dtyFdlResult == PFDL_OK )
                {
                    /* 内部ベリファイコマンドを設定する */
                    dtyRequester.command_enu = PFDL_CMD_IVERIFY_BYTES;
                    
                    /* コマンド実行処理 */
                    dtyFdlResult = PFDL_Execute( &dtyRequester );
                    
                    /* コマンド終了待ち */
                    while( dtyFdlResult == PFDL_BUSY )
                    {
                        /* 何か行いたい作業があれば行う(バック・グラウンド・オペレーション) */
                        __nop();
                        __nop();
                        
                        /* 終了確認処理 */
                        dtyFdlResult = PFDL_Handler();
                    }
                }

#if R_PFDL_SAM_DIRECT_READ
/* 直接読み込みでデータの確認(データ・フラッシュメモリがアクセス可能な状態で、Byteアクセスのみ実行可能) */
/* なお、データ・フラッシュへ書き込み等を行っている場合は正常に読み込む事はできません。                 */
                /* データの確認処理 */
                if( dtyFdlResult == PFDL_OK )
                {
                    /* 読み込み用の変数定義 */
                    unsigned short        duh_i;        /* ループ変数定義 */
                    __near unsigned char *pubReadData;  /* 直接読み込み用ポインタ(Byteアクセスのみ可能) */
                    
                    pubReadData = (__near unsigned char *) duhWriteAddress + R_PFDL_SAM_DREAD_OFSET;
                    
                    /* 読み込みデータと書き込みデータの比較 */
                    for( duh_i = 0 ; duh_i < R_PFDL_SAM_WRITE_SIZE ; duh_i++ )
                    {
                        if( dubWriteBuffer[ duh_i ] != pubReadData[ duh_i ] )
                        {
                            /* 読み込みデータと書き込みデータに差分があった場合はエラーとする。 */
                            dtyFdlResult = PFDL_ERR_PARAMETER;
                            break;
                        }
                    }
                }
#else
/* データ・フラッシュ・ライブラリの読み込み機能を利用 */
                /* データの確認処理 */
                if( dtyFdlResult == PFDL_OK )
                {
                    /* 読み込み用の変数定義 */
                    pfdl_u16    duh_i;      /* ループ変数定義 */
                    pfdl_u08    dubReadBuffer [ R_PFDL_SAM_WRITE_SIZE ];
                                            /* 読み込みデータ入力バッファ */
                    
                    /* 読み込みコマンドを設定する */
                    dtyRequester.command_enu = PFDL_CMD_READ_BYTES;
                    
                    /* 読み込み開始アドレスを設定する */
                    dtyRequester.index_u16   = duhWriteAddress;
                    
                    /* 読み込みデータ入力バッファのアドレスを設定する */
                    dtyRequester.data_pu08   = dubReadBuffer;
                    
                    /* コマンド実行処理 */
                    dtyFdlResult = PFDL_Execute( &dtyRequester );
                    
                    /* 読み込みデータと書き込みデータの比較 */
                    for( duh_i = 0 ; duh_i < R_PFDL_SAM_WRITE_SIZE ; duh_i++ )
                    {
                        if( dubWriteBuffer[ duh_i ] != dubReadBuffer[ duh_i ] )
                        {
                            /* 読み込みデータと書き込みデータに差分があった場合はエラーとする。 */
                            dtyFdlResult = PFDL_ERR_PARAMETER;
                            break;
                        }
                    }
                }
#endif
                break;
            }
            /* 不可避なエラーが発生した場合は処理を中断する。 */
            else if( dtyFdlResult != PFDL_ERR_MARGIN ) {
                break;
            }
        }
    }
    
    /* FDL終了処理 */
    r_pfdl_samFdlEnd();
    
    /* ターゲットボード終了処理 */
    r_pfdl_samTargetEnd();
    
    /* 終了ループ */
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
    /* ウォッチドッグタイマ */
    /************************/
    R_PFDL_SAM_WDT_RESET();        /* ウォッチドッグタイマのリセット */
    
    /*******************/
    /* LEDの初期化処理 */
    /*******************/
    R_PFDL_SAM_LED1_INIT();        /* LED1初期化(消灯) */
    R_PFDL_SAM_LED2_INIT();        /* LED2初期化(消灯) */
    R_PFDL_SAM_LED1_ON();          /* LED1点灯         */
    R_PFDL_SAM_LED2_ON();          /* LED2点灯         */
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
    R_PFDL_SAM_LED1_OFF();         /* LED1消灯         */
    R_PFDL_SAM_LED2_OFF();         /* LED2消灯         */
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
    
    /* 初期値入力 */
    dtyDescriptor.fx_MHz_u08            = R_PFDL_SAM_FDL_FRQ;  /* 周波数設定     */
    dtyDescriptor.wide_voltage_mode_u08 = R_PFDL_SAM_FDL_VOL;  /* 電圧モード設定 */
    
    /* PFDL初期化関数実行 */
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
    /* データ・フラッシュ・ライブラリ終了処理 */
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

