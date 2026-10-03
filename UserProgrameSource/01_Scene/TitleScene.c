#include <stdio.h>
#include "TitleScene.h"

int titleInitialize(PtrSceneFunctions _ptrScene, void *_vptrUserData)
{
    TYPE_DATA_CREATE(int*,testInt,testData);

    printf("Titleの初期化です。\n");
    return 0;
}

PtrSceneFunctions titleUpdate(double _deltaTime, double _elapceTime)
{
    printf("Titleの更新です。\n");
    return NULL;
}

int titleExit(PtrSceneFunctions _ptrScene)
{
    printf("Titleの終了です。\n");
    return 0;
}
