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
*               : 11.02.2011 1.01 リクエスタの初期化処理を追加                 *
*               : 03.05.2012 1.02 10進定数マクロ名(__RL78_)の誤りを修正        *
*               : 01.29.2016 1.03 Tool-Chainを変更                             *
*               : 10.03.2017 1.04 コメントを修正                               *
*******************************************************************************/

/******************************************************************************
 Expanded function
******************************************************************************/
#pragma sfr                             /* SFR(特定レジスタ郡)領域利用宣言   */
#pragma DI                              /* 割り込み機能(禁止)利用宣言        */
#pragma EI                              /* 割り込み機能(許可)利用宣言        */
#pragma NOP                             /* CPU制御命令 (NOP )利用宣言        */


/******************************************************************************
 interrupt function
******************************************************************************/
#pragma interrupt INTWDTI samIntWdt     /* WDT割り込み                      */


/******************************************************************************
 section and switch
******************************************************************************/
/**************************************/
/* サンプルプログラムのセクション設定 */
/**************************************/
/* コード(プログラム)のセクション名の設定(変更) */
#ifdef __78K0R_SMALL__
  #pragma section @@CODE  SAM_CODE
#else
  #pragma section @@CODEL SAM_CODE
#endif 

/* 固定値テーブル(const)のセクション名の設定(変更) */
#ifdef __78K0R_LARGE__
  #pragma section @@CNSTL SAM_CNST
#else
  #pragma section @@CNST  SAM_CNST
#endif

/* データ(変数)のセクション名の設定(変更) */
/*
#ifdef __78K0R_LARGE__
  #pragma section @@DATAL SAM_DATA
#else
  #pragma section @@DATA  SAM_DATA
#endif
*/

/******************************************************/
/* サンプル・プログラム・プログラムスイッチ用シンボル */
/******************************************************/
/* QB-R5F100LE-TB単体使用時ON可能 */
#if 0
#define __QB_R5F100LE_TB__      /*  */


/* その他ボード(内蔵発振設定) */
#else
#define __NON_TARGET__          /*  */

#endif


/******************************************************************************
 Include <System Includes>, "Project Includes"
******************************************************************************/
/* 標準ライブラリ(ランタイム・ライブラリ使用) */
#include <string.h>             /* memcpy用 */

/* FDL,EELライブラリ用ヘッダーファイル          */
#include "fdl.h"                    /* FDLライブラリ・ヘッダーファイル          */
#include "fdl_descriptor.h"         /* FDLディスクリプタ・ヘッダーファイル      */
#include "eel.h"                    /* EELライブラリ・ヘッダーファイル          */
#include "eel_descriptor.h"         /* EELディスクリプタ・ヘッダーファイル      */
#include "eel_user_types.h"         /* EELユーザー定義・ヘッダーファイル        */

/******************************************************************************
 Typedef definitions
******************************************************************************/


/******************************************************************************
 Macro definitions
******************************************************************************/
/**************************/
/* EEL操作用 シンボル定義 */
/**************************/
/* コマンドの実行モード                 */
#define SAM_EEL_MODE_ENFORCED   0xFF    /* Enforcedモード(0xFF)         */
#define SAM_EEL_MODE_TIMEOUT    0x10    /* Timeout モード(0x01～0xFE)   */
#define SAM_EEL_MODE_POLLING    0x00    /* Polling モード(0x00)         */

/* その他パラメータ                     */
#define SAM_EEL_BUFFER_SIZE     0xFF    /* サンプル用のバッファサイズ   */
#define SAM_EEL_MAINTE_END      0x04    /* EEL_Handler関数のメンテナンス終了ループ回数  */

/* サンプルプログラム用、制御マクロ */
#define SAM_WDT_RESET()         WDTE = 0xAC 
                                        /* ウォッチドッグタイマリセット */

/*********************************************************/
/* QB-R5F100LE-TB, 書き込みシンボル定義                  */
/*********************************************************/
#ifdef __QB_R5F100LE_TB__
/* QB-R5F100LE-TB, LED制御マクロ */
#define SAM_LED1_INIT() P6.2 = 1, PM6.2 = 0
                                        /* オンボードのLED1を初期化(非点灯) */
#define SAM_LED1_ON()   P6.2 = 0        /* オンボードのLED1を点灯           */
#define SAM_LED1_OFF()  P6.2 = 1        /* オンボードのLED1を消灯           */

#define SAM_LED2_INIT() P6.3 = 1, PM6.3 = 0
                                        /* オンボードのLED2を初期化(非点灯) */
#define SAM_LED2_ON()   P6.3 = 0        /* オンボードのLED2を点灯           */
#define SAM_LED2_OFF()  P6.3 = 1        /* オンボードのLED2を消灯           */

/*************************************/
/* 通常の書き込み設定用 シンボル定義 */
/*************************************/
#else 
/* LEDは処理無し(無効コード) */
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
/* ターゲット用サンプル関数 */
void samTargetInit( void );     /* ターゲット初期化処理     */
void samTargetEnd ( void );     /* ターゲット終了処理       */

/* メンテナンス関数 */
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
    /* 低電圧検出回路の設定 */
    /************************/
    LVIM = 0x00;                /* 低電圧検出レジスタの設定を初期化             */
    LVIS = 0x00;                /* 低電圧検出レベル選択レジスタの設定を初期化   */
    
/* QB-R5F100LE-TB用外部20Mhz発振切替設定 */
#if 0
    /****************************************************************/
    /* クロック制御レジスタの初期化                                 */
    /* 動作クロックを内蔵発振からX1(20Mhzを想定)発振に変更          */
    /* ※そのまま使用する場合はfsl_user.hを20Mhz設定にしてください  */
    /****************************************************************/
    /* 動作スピード・モード制御レジスタ     */
    OSMC = 0b00000001;          /* 10 MHzを越える周波数での動作設定                         */
    
    /* クロック動作モード制御レジスタ       */
    CMC  = 0b01010001;          /* X1,XT1端子発振モード、X1周波数を10MHz＜fMX≦20MHzに設定  */
    
    /* クロック動作ステータス制御レジスタ   */
    CSC  = 0b00000000;          /* X1,XT1発振開始                                           */
    
    /* X1発振安定時間選択レジスタ           */
    OSTS = 0b11110000;          /* X1発振安定時間を設定 ( fx = 20 MHz時 / 102.4 μ s以上 )  */
    
    /* 発振安定時間カウンタ状態レジスタ     */
    while( OSTC == 0 );         /* X1発振安定時間待ち ( ALL 0 )                             */
    
    /* システム・クロック制御レジスタ       */
    CKC  = 0b00011000;          /* メイン・システム・クロックを内蔵発振からX1発振に変更     */
    
    while( MCS  == 0 );         /* メイン・システム・クロック（fMAIN）のステータス確認      */
                                /* ※発振回路切替確認 ( MCS : CKCレジスタ 5bit目  )         */
    
    /* クロック動作ステータス制御レジスタ : 高速内蔵発振クロックの動作制御                  */
    /* HIOSTOP = 1; */          /* CSC = 0b00000001 : 高速内蔵発振回路停止                  */
    /* RL78のセルフを実行する場合はOCOが必要のため、内蔵発振回路は停止させない。            */
    
#endif
}


/*==============================================================================*/
/* Function name : main                                                         */
/* IN            : void                                                         */
/* OUT           : void                                                         */
/* Description   : メイン関数                                                   */
/* Date          : 06,08,2011                                                   */
/*==============================================================================*/
void main( void )
{
    /* 変数定義 */
    fal_status_t    dteFalResult;       /* FDL用パラメータ変数  */
    eel_request_t   dtyRequester;       /* EEL用パラメータ変数  */
    eel_u08         dubDataBuffer[ SAM_EEL_BUFFER_SIZE ];
                                        /* データ入力用バッファ */
    eel_u08         dubReadBuffer[ SAM_EEL_BUFFER_SIZE ];
                                        /* データ取得用バッファ */
    
    /* バッファの初期化処理 */
    memset( dubDataBuffer, 0x00, SAM_EEL_BUFFER_SIZE );
    memset( dubReadBuffer, 0x00, SAM_EEL_BUFFER_SIZE );
    
    /* ターゲット初期化処理 */
    samTargetInit();
    
    /* 割り込み許可         */
    EI();
    
    /* リクエスタ初期化処理 */
    dtyRequester.status_enu     = 0;
    dtyRequester.address_pu08   = 0;
    dtyRequester.identifier_u08 = 0;
    dtyRequester.command_enu    = 0;
    dtyRequester.timeout_u08    = 0;
    
    /*== -> uninitialized -> ( EEPROM Emulation state ) ====================*/
    /************************************************************************/
    /* EEPROMエミュレーション初期化処理 ( state : uninitialized -> closed ) */
    /************************************************************************/
    /* FAL(FDL)パラメータ初期化処理      */
    /* ※fdl_descriptor.hのFDL_SYSTEM_FREQUENCY，及びEEL_POOL_SIZEをお使いの*/
    /*   環境に合せた設定値(周波数、EELブロック数)を設定してください。      */
    dteFalResult = FAL_Init( &fal_descriptor_str );
    
    /* FAL初期化が正常終了の場合    */
    if( dteFalResult == FAL_OK )
    {
        /* EELパラメータ初期化処理  */
        dtyRequester.status_enu = EEL_Init();
    }
    
    /*== -> closed -> ( EEPROM Emulation state ) =====================================*/
    /**********************************************************************************/
    /* EEPROMエミュレーション準備処理 ( state : closed -> opened )                    */
    /* ※EEL_Open実行以降はSTOPモード，HALTモード, フラッシュ・セルフ・ライブラリ禁止 */
    /**********************************************************************************/
    if( dtyRequester.status_enu == EEL_OK )
    {
        /* EEL */
        EEL_Open();
    }
    
    /*== -> opened -> ( EEPROM Emulation state ) =====================================*/
    /**********************************************************************************/
    /* EEPROMエミュレーション開始処理 ( state : opened -> started )                   */
    /**********************************************************************************/
    if( dtyRequester.status_enu == EEL_OK )
    {
        do {
            /* EEL_CMD_STARTUPコマンド実行用のパラメータを設定  */
            dtyRequester.command_enu = EEL_CMD_STARTUP;        /* EEL_CMD_STARTUPコマンド  */
            dtyRequester.timeout_u08 = SAM_EEL_MODE_ENFORCED;  /* Enforcedモード           */
            
            /* EEL_CMD_STARTUPコマンド実行( Enforcedモード )    */
            EEL_Execute( &dtyRequester );
            
            /* EEPROMエミュレーション・ブロック不整合エラー(ブロック未初期化)の場合 */
            if( dtyRequester.status_enu == EEL_ERR_POOL_INCONSISTENT )
            {
                /* EEL_CMD_FORMATコマンド実行用のパラメータを設定   */
                dtyRequester.command_enu = EEL_CMD_FORMAT;         /* EEL_CMD_FORMATコマンド   */
                dtyRequester.timeout_u08 = SAM_EEL_MODE_ENFORCED;  /* Enforcedモード           */
                
                /* EEL_CMD_STARTUPコマンド実行( Enforcedモード )    */
                EEL_Execute( &dtyRequester );
            }
            
        /* EEL_CMD_FORMATコマンドが成功したらEEL_CMD_STARTUPコマンドを再度実行 */
        } while( ( dtyRequester.command_enu == EEL_CMD_FORMAT ) && 
                 ( dtyRequester.status_enu  == EEL_OK         )  );
    }
    
    
    /* EEL_CMD_STARTUPコマンドは正常終了したか？ */
    if( dtyRequester.status_enu == EEL_OK )
    {
        /*== -> started -> ( EEPROM Emulation state ) ===============================*/
        /*****************************************************************************/
        /* EEL_Handler関数によるブロックの整理（メンテナンス・モード）: 開始時に整理 */
        /*****************************************************************************/
        samMaintenance( &dtyRequester );
        
        /**********************/
        /* データ書き込み処理 */
        /**********************/
        if( dtyRequester.status_enu == EEL_OK )
        {
            /* 書き込みデータの設定 */
            dubDataBuffer[0x00] = 0xFD;
            dubDataBuffer[0x01] = 0xD0;
        
            /* EEL_CMD_WRITEコマンド実行用のパラメータを設定    */
            dtyRequester.address_pu08   = dubDataBuffer;           /* 使用するバッファの設定   */
            dtyRequester.identifier_u08 = 'a';                     /* 対象データのIDを設定     */
            dtyRequester.command_enu    = EEL_CMD_WRITE;           /* EEL_CMD_WRITEコマンド    */
            dtyRequester.timeout_u08    = SAM_EEL_MODE_ENFORCED;   /* Enforcedモード           */
        
            /* EEL_CMD_WRITEコマンド実行( Enforcedモード )      */
            EEL_Execute( &dtyRequester );
        }
        
        /*********************************************************************************/
        /* EEL_Handler関数によるブロックの整理（メンテナンス・モード）: 書き込み後に整理 */
        /*********************************************************************************/
        if( dtyRequester.status_enu == EEL_OK )
        {
            samMaintenance( &dtyRequester );
        }
        
        /**********************/
        /* データ読み込み処理 */
        /**********************/
        if( dtyRequester.status_enu == EEL_OK )
        {
            /* EEL_CMD_READコマンド実行用のパラメータを設定     */
            dtyRequester.address_pu08   = dubReadBuffer;           /* 使用するバッファの設定   */
            dtyRequester.identifier_u08 = 'a';                     /* 対象データのIDを設定     */
            dtyRequester.command_enu    = EEL_CMD_READ;            /* EEL_CMD_READコマンド     */
            dtyRequester.timeout_u08    = SAM_EEL_MODE_ENFORCED;   /* Enforcedモード           */
            
            /* EEL_CMD_READコマンド実行( Enforcedモード )       */
            EEL_Execute( &dtyRequester );
        }
        
        /************************************************************************************/
        /* EEPROMエミュレーション停止処理 ( state : started -> opened )                     */
        /************************************************************************************/
        /* EEL_CMD_SHUTDOWNコマンド実行用のパラメータを設定     */
        dtyRequester.command_enu = EEL_CMD_SHUTDOWN;       /* EEL_CMD_SHUTDOWNコマンド */
        dtyRequester.timeout_u08 = SAM_EEL_MODE_ENFORCED;  /* Enforcedモード           */
        
        /* EEL_CMD_SHUTDOWNコマンド実行( Enforcedモード )   */
        EEL_Execute( &dtyRequester );
        
    }
    
    /*== -> opened -> ( EEPROM Emulation state ) =======================================*/
    /************************************************************************************/
    /* EEPROMエミュレーション終了処理 ( state : opened -> closed )                      */
    /************************************************************************************/
    EEL_Close();
    
    
    /*== -> closed -> ( EEPROM Emulation state ) =======================================*/
    /************************************************************************************/
    /* EEPROMエミュレーション終了状態 ( state : closed )                                */
    /* ・STOPモード，HALTモード実行可能                                                 */
    /* ・フラッシュ・セルフ・プログラミング・ライブラリ、その他データ・フラッシュ関連   */
    /*   ライブラリ実行可能                                                             */
    /*   ※その他ライブラリを実行した場合 ( state : closed -> uninitialized )           */
    /************************************************************************************/
    
    
    /* ターゲット終了処理   */
    samTargetEnd();
    
    /*== 終了ループ ==*/
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
/* Description   : ターゲット初期化処理                                         */
/* Date          : 07,02,2010                                                   */
/*==============================================================================*/
void samTargetInit( void )
{
    /************************/
    /* ウォッチドッグタイマ */
    /************************/
    SAM_WDT_RESET();        /* ウォッチドッグタイマのリセット   */
    
    /*******************/
    /* LEDの初期化処理 */
    /*******************/
    SAM_LED1_INIT();        /* LED1初期化(消灯) */
    SAM_LED2_INIT();        /* LED2初期化(消灯) */
    SAM_LED1_ON();          /* LED1点灯         */
    SAM_LED2_ON();          /* LED2点灯         */
}


/*==============================================================================*/
/* Function name : samTargetEnd                                                 */
/* IN            : void                                                         */
/* OUT           : void                                                         */
/* Description   : ターゲット終了処理                                           */
/* Date          : 07,02,2010                                                   */
/*==============================================================================*/
void samTargetEnd( void )
{
    SAM_LED1_OFF();         /* LED1消灯         */
    SAM_LED2_OFF();         /* LED2消灯         */
}


/*##############################################################################*/
/*------------------------------------------------------------------------------*/
/* sub functions                                                                */
/*------------------------------------------------------------------------------*/
/*==============================================================================*/
/* Function name : samMaintenance                                               */
/* IN            : ptyRequester / 実行パラメータ                                */
/* OUT           : void          / 無し                                         */
/* Description   : メンテナンス関数( コマンド終了後に実行 )                     */
/* Date          : 08,23,2010                                                   */
/*==============================================================================*/
void samMaintenance( eel_request_t *ptyRequester  )
{
    /* 変数定義 */
    __near eel_driver_status_t  dteDriverStatus;
    eel_u16                     duhMainteCounter;
    
    /* メンテナンスが終了するまでループ */
    for( duhMainteCounter = 0 ; duhMainteCounter < SAM_EEL_MAINTE_END ; )
    {
        /* メンテナンス処理 */
        EEL_Handler( SAM_EEL_MODE_POLLING );        /* メンテナンス実行     */
        EEL_GetDriverStatus( &dteDriverStatus );    /* ライブラリ状態確認   */
        
        /* メンテナンス・モード終了状態(一時的な終了も含む) */
        if( ( ptyRequester->status_enu            == EEL_OK             ) &&
            ( dteDriverStatus.operationStatus_enu == EEL_OPERATION_IDLE ) )
        {
            /* メンテナンス・モード終了状態確認回数をインクリメント */
            duhMainteCounter++;
        }
        /* メンテナンス中 */
        else if( ( ptyRequester->status_enu == EEL_OK   ) ||
                 ( ptyRequester->status_enu == EEL_BUSY ) )
        {
            /* メンテナンス中なので終了状態確認回数を0クリア */
            duhMainteCounter = 0;
        }
        /* エラー発生のため、メンテナンス処理を終了 */
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
/* Description   : WDTリセット関数                                              */
/* Date          : 07,02,2010                                                   */
/*==============================================================================*/
void samIntWdt( void )
{
    SAM_WDT_RESET();
}


