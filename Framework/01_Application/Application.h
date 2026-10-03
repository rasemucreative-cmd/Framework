/**
 * @file    Application.h
 * @brief   Frameworkの核の部分
 * @note    実装はApplication.cで実装
 * @author  RasemuCreative
 * @date    2026-09-26
 * @version 0.1.0
 */
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "../03_Timer/Timer.h"

/**
 * @struct Applicationの雛形(メンバーは隠蔽).
 * 
 */
struct Application;

/**
 * @brief Applicationのポインタが持つ実体の参照用. 
 * 
 */
typedef struct Application *PtrApplication;

/**
 * @var WPtrApplication.
 * @brief Applicationのポインタのポインタ。メモリ解放などで利用.
 * 
 */
typedef struct Application **WPtrApplication;

/**
 * @var PtrTimer.
 * @brief ゲーム内の時間管理のポインタ.
 * 
 */
typedef struct Timer *PtrGameTimer;
/**
 * @fn applicationNoticedIsRunning.
 *
 * @brief ループを走らせるか止めるかを通知する.
 * 
 * @param _ptrApplication 通知情報を持つ.
 * @return unsigned char 通知 (1：走らせる/0：止める).
 */
unsigned char applicationNoticedIsRunning(PtrApplication _ptrApplication);

/**
 * @brief Applicationを初期化する
 *        
 * @param _wptrApplication 初期化用ダブルポインタ
 *  
 */
void applicationInitialize(WPtrApplication _wptrApplication);

/**
 * @fn applicationRun
 * 
 * @brief GameLoop を呼び出す.
 * 
 * @param _ptrApplication 関連情報を呼び出す.
 */
void applicationRun(PtrApplication _ptrApplication);

/**
 * @fn applicationShutdown
 * 
 * @brief Applicationのメモリ解放処理
 * 
 * @param _wptrApplication freeを使うのでダブルポインタでポインタ自体を変更できるようにする.
 */
void applicationShutdown(WPtrApplication _wptrApplication);

/**
 * @fn applicationNoticeShutdown
 * 
 * @brief GameLoopのループ処理を終了通知を送る
 * 
 * @param _ptrApplication 
 */
void applicationNoticeShutdown(PtrApplication _ptrApplication);

/**
 * @fn getGameTimer
 * 
 * @brief Get the Game Timer object
 * 
 * @param _cptrApplication 
 * @return PtrGameTimer 
 */
PtrGameTimer getGameTimer(PtrApplication _cptrApplication);

#endif /* __APPLICATION_H__ */