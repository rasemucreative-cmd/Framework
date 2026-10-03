#include <stdlib.h>
#include "Scene.h"
#include "../00_Common/common.h"

PtrSceneFunctions gPtrSceneFunctions = NULL;

WPtrSceneFunctions GameInitialize(){
    int result = SceneInitialize(&gPtrSceneFunctions);
    CUSTOM_ASSERT(result != 0,"SceneInitialzeで初期化に失敗しました。");
    CUSTOM_ASSERT(gPtrSceneFunctions == NULL,"gPtrSceneFunctionsを初期化出来ませんでした。");
    return &gPtrSceneFunctions;
}

