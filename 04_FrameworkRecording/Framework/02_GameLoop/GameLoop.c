/**
 * @file GameLoop.c
 * @author RasemuCreative
 * @brief ゲームの進行を管理する
 * @version 0.1.0
 * @date 2026-09-27
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "GameLoop.h"
#include "../01_Application/Application.h"

#define FRAMECOUNT_MAX (5000)

int initialize(){
    return 1;
}

void gameLoop(struct Application* _ptrApplication)
{
    CUSTOM_ASSERT(_ptrApplication == NULL,"Applicationの実体がありません");

    int result = initialize();
    if(result < 0) return;

    long frameCount = 0;

    while(applicationIsRunning(_ptrApplication)){
        frameCount++;
        printf("FrameCount: %ld\n",frameCount);
        if(frameCount >= FRAMECOUNT_MAX){
            applicationNoticeShutdown(_ptrApplication);
        }
    }
}
