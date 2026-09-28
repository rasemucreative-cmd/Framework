/**
 * @file    Application.h
 * @brief   Frameworkの核の部分
 * @note    Applicationの実装はここでで実装
 * @author  RasemuCreative
 * @date    2026-09-26
 * @version 0.1.0
 */

#include <stdlib.h>
#include <assert.h>

#include "Application.h"
#include "../02_GameLoop/GameLoop.h"

#define APPLICATION_RUNNING  (1)
#define APPLICATION_SHUTDOWN (0)

struct Application{
  unsigned char isRunning : 1;  
};

int applicationInitialize(WPtrApplication _wptrApplication)
{
    CUSTOM_ASSERT(*_wptrApplication != NULL,"すでにこのポインタ変数は実体を持っています。");
    *_wptrApplication = malloc(sizeof(struct Application));
    CUSTOM_ASSERT(*_wptrApplication == NULL,"メモリの確保に失敗しました。");

    (*_wptrApplication)->isRunning = APPLICATION_RUNNING;

    return 0;
}

unsigned char applicationIsRunning(PtrApplication _ptrApplication){
    CUSTOM_ASSERT(_ptrApplication == NULL,"Applicationに実体がありません。");
    return _ptrApplication->isRunning;
}

int applicationRun(PtrApplication _ptrApplication)
{
    CUSTOM_ASSERT(_ptrApplication == NULL, "Applicationに実体がありません。");
    gameLoop(_ptrApplication);
    return 0;
}

int applicationShutdown(WPtrApplication _wptrApplication)
{
    CUSTOM_ASSERT((*_wptrApplication) == NULL,"ポインタ変数に実体がありません。");

    free(*_wptrApplication);
    (*_wptrApplication) = NULL;
    _wptrApplication = NULL;

    return 0;
}

int applicationNoticeShutdown(PtrApplication _ptrApplication)
{
    CUSTOM_ASSERT(_ptrApplication == NULL, "Applicationに実体がありません。");
    _ptrApplication->isRunning = APPLICATION_SHUTDOWN;
    return 0;
}
