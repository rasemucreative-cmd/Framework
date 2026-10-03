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
#include <conio.h>

#include "../00_Common/Common.h"
#include "GameLoop.h"
#include "../01_Application/Application.h"
#include "../04_Scene/Scene.h"
#include "../../UserProgrameSource/01_Scene/TitleScene.h"

#define FRAMECOUNT_MAX (5000) /**< debug フレームをカウント (GameLoopが機能しているか確認) */

PtrSceneFunctions gCurrentScene = NULL;

/**
 * @fn initialize
 * @brief このフレームワークで利用されるApplication以外のAPIの初期化をする
 * 
 * @return (1:初期化成功/0:初期化失敗)
 */
int initialize(){
    gCurrentScene = *GameInitialize();
    if(gCurrentScene == NULL) { return 0; }
    return 1;
}

void gameLoop(struct Application* _ptrApplication)
{
    CUSTOM_ASSERT(_ptrApplication == NULL,"Applicationの実体がありません");

    int result = initialize();
    if(result < 0) return;

    long frameCount = 0;

    while(applicationNoticedIsRunning(_ptrApplication)){
        //frameCount++;
        system("cls");
        if(_kbhit()){
            if(_getch() == 27){
                applicationNoticeShutdown(_ptrApplication);
            }
        }
        PtrGameTimer ptrTimer = getGameTimer(_ptrApplication);
        updateTimer(ptrTimer);
        printf("FPS: %.08lf\n",getFPSTimer(ptrTimer));
    }
}
