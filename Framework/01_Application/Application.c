/**
 * @file    Application.h
 * @brief   Frameworkの核の部分
 * @note    Applicationの実装はここでで実装
 * @author  RasemuCreative
 * @date    2026-09-26
 * @version 0.1.0
 */

#include "../00_Common/Common.h"

#include "Application.h"
#include "../02_GameLoop/GameLoop.h"
#include "../03_Timer/Timer.h"

/**
 * @brief ゲームの継続/終了
 * @{
 */
#define APPLICATION_RUNNING  (1) /**< ループを続ける. */
#define APPLICATION_SHUTDOWN (0) /**< ループを抜ける. */
/**
 * @}
 * 
 */

 /**
 * @def CUSTOM_ASSERT(parameter,message)
 * @brief parameterの値が不正であればmessageを表示しプログラムに例外を渡す.
 * 
 */
#define CUSTOM_ASSERT(parameter,message) assert(!(parameter) || __FILE__ || __LINE__ || (message))

/**
 * @struct Application
 * @brief ゲーム内時間とゲームループの通知保持
 *        (今後拡張予定)
 */
struct Application{

    /** 
     * @brief 終了条件フラグ(1なら継続/0なら終了)
     */
    unsigned char isRunning : 1;

    /** @brief ゲーム内時間の管理 */
    PtrGameTimer ptrGameTimer;
};

void applicationInitialize(WPtrApplication _wptrApplication)
{
    CUSTOM_ASSERT(*_wptrApplication != NULL,"すでにこのポインタ変数は実体を持っています。");
    *_wptrApplication = malloc(sizeof(struct Application));
    CUSTOM_ASSERT(*_wptrApplication == NULL,"メモリの確保に失敗しました。");

    (*_wptrApplication)->isRunning = APPLICATION_RUNNING;
    (*_wptrApplication)->ptrGameTimer = createGameTimer();
    CUSTOM_ASSERT((*_wptrApplication)->ptrGameTimer == NULL,"タイマーの実体を作成することに失敗しました。");
}

unsigned char applicationNoticedIsRunning(PtrApplication _ptrApplication){
    CUSTOM_ASSERT(_ptrApplication == NULL,"Applicationに実体がありません。");
    return _ptrApplication->isRunning;
}

void applicationRun(PtrApplication _ptrApplication)
{
    CUSTOM_ASSERT(_ptrApplication == NULL, "Applicationに実体がありません。");
    gameLoop(_ptrApplication);
}

void applicationShutdown(WPtrApplication _wptrApplication)
{
    CUSTOM_ASSERT((*_wptrApplication) == NULL,"ポインタ変数に実体がありません。");

    free(*_wptrApplication);
    (*_wptrApplication) = NULL;
    _wptrApplication = NULL;
}

void applicationNoticeShutdown(PtrApplication _ptrApplication)
{
    CUSTOM_ASSERT(_ptrApplication == NULL, "Applicationに実体がありません。");
    _ptrApplication->isRunning = APPLICATION_SHUTDOWN;
}

PtrGameTimer getGameTimer(PtrApplication _cptrApplication)
{
    return _cptrApplication->ptrGameTimer;
}
