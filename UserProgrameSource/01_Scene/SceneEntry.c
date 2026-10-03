/**
 * @file Scene.c
 * @author Rasemu
 * @brief シーン処理とシーン構造体
 * @note ユーザーがシーン構造体のフォーマットに沿って自由に処理を実装して
 *       各シーン関数を設定できる
 * 
 * @version 0.1.0
 * @date 2026-09-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdlib.h>

#include "../../Framework/00_Common/Common.h"
#include "../../Framework/04_Scene/Scene.h"
#include "TitleScene.h"

int SceneInitialize(WPtrSceneFunctions _wptrSceneFunctions){

    *_wptrSceneFunctions = malloc(sizeof(struct Functions));
    CUSTOM_ASSERT((*_wptrSceneFunctions) == NULL, "SceneFunctionsの生成に失敗しました");
    (*_wptrSceneFunctions)->initialize = titleInitialize;
    (*_wptrSceneFunctions)->update = titleUpdate;
    (*_wptrSceneFunctions)->exit = titleExit;
    (*_wptrSceneFunctions)->vprtUserData = NULL;
    int result = (*_wptrSceneFunctions)->initialize(*_wptrSceneFunctions,NULL);

    return result;
}

PtrSceneFunctions SceneUpdate(PtrSceneFunctions _ptrSceneFunctions, double _deltaTime, double _elapcedTime)
{
    return _ptrSceneFunctions->update(_deltaTime,_elapcedTime);
}

int SceneExit(WPtrSceneFunctions _wptrSceneFunctions)
{
    return (*_wptrSceneFunctions)->exit(*_wptrSceneFunctions);
}
