/**
 * @file Timer.c
 * @author Rasemu
 * @brief ゲーム内時間管理
 * @version 0.1.0
 * @date 2026-09-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <time.h>
#include <stdlib.h>
#include <assert.h>

#include "Timer.h"
#include "../00_Common/Common.h"
#include "../01_Application/Application.h"

/**
 * @struct Timer
 * 
 * @brief ゲーム時間の管理用構造体
 * 
 */
struct Timer{
    /** 直前のフレームから現在のフレームまでに経過した時間（秒）のこと */
    double deltaTime;   

    /** 経過時間 */
    double elapsedTime; 

    /** 1フレーム/秒 */
    double fps;         

    /** 1秒間の動画が何枚の静止画（フレーム）で構成されているかを示す単位のこと */
    double frameRate;   

    /** プログラムやアニメーションの実行が始まってから、画面が更新 */
    unsigned long frameCount; 

    /**「直前の時刻」や「1つ前のフレームの処理時刻」を保持するための変数 */
    clock_t previousTime; 

    /** 画面の更新頻度（FPS：Frames Per Second）を一定に保つ、または計測するために使用される */
    clock_t fpsTimer;  
    
    /**「FPS（フレームレート）の計測や計算のために経過した時間」を保持する変数 */
    clock_t fpsElapsed;
};

typedef struct Timer GameTimer;
typedef struct Timer* PtrGameTimer;
typedef struct Timer** WPtrGameTimer;

void initializeGameTimer(PtrGameTimer _ptrTimer){
    CUSTOM_ASSERT(_ptrTimer == NULL,"タイマーのアドレスが不正です。");

    _ptrTimer->deltaTime = 0.0;
    _ptrTimer->elapsedTime = 0.0;

    _ptrTimer->fps = 0.0;
    _ptrTimer->frameRate = 0.0;

    _ptrTimer->previousTime = 0;
    _ptrTimer->fpsTimer = 0;
    _ptrTimer->fpsElapsed = 0;
}

PtrGameTimer createGameTimer()
{
    PtrGameTimer ptrTime = NULL;
    CUSTOM_ASSERT(ptrTime != NULL,"このポインタはすでにアドレスを保持しています。");
    ptrTime = malloc(sizeof(struct Timer));
    CUSTOM_ASSERT(ptrTime == NULL,"ptrTimeの生成に失敗しました。");
    initializeGameTimer(ptrTime);
    return ptrTime;
}

void deleteGameTimer(WPtrGameTimer _wptrTimer){
    CUSTOM_ASSERT(_wptrTimer == NULL, "_wptrTimerはどこのアドレスも指していません。");
    CUSTOM_ASSERT((*_wptrTimer) == NULL,"*_wptrTimerの指すアドレスが不正です。");
    free(*_wptrTimer);
    (*_wptrTimer) = NULL;
    _wptrTimer = NULL;
}

void updateTimer(PtrGameTimer _ptrTimer){
    CUSTOM_ASSERT(_ptrTimer == NULL,"タイマーのアドレスが不正です。");

    clock_t currentTime = clock();

    if(_ptrTimer->previousTime == 0){
        _ptrTimer->previousTime = currentTime;
        _ptrTimer->fpsTimer = currentTime;
        _ptrTimer->deltaTime = 0.0;
        return;
    }

    _ptrTimer->deltaTime = (double)(currentTime - _ptrTimer->previousTime) / (double)CLOCKS_PER_SEC;
    _ptrTimer->previousTime = currentTime;
    _ptrTimer->elapsedTime += _ptrTimer->deltaTime;
    _ptrTimer->frameCount++;
    _ptrTimer->fpsElapsed = currentTime - _ptrTimer->fpsTimer;
    
    if(_ptrTimer->fpsElapsed >= CLOCKS_PER_SEC){
        double second = (double)_ptrTimer->fpsElapsed / (double)CLOCKS_PER_SEC;
        _ptrTimer->fps = (double)_ptrTimer->frameCount / second;
        _ptrTimer->frameRate = second / (double)_ptrTimer->frameCount;
        _ptrTimer->frameCount = 0;
        _ptrTimer->fpsElapsed = currentTime;
    }

}
double getFPSTimer(const PtrGameTimer _cptrTimer){
    return _cptrTimer->fps;
}
double getFrameRate(const PtrGameTimer _cptrTimer){
    return _cptrTimer->frameRate;
}
double getDeltaTime(const PtrGameTimer _cptrTimer){
    return _cptrTimer->deltaTime;
}
