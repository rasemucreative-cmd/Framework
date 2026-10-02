#ifndef __TITLESCENE_H__
#define __TITLESCENE_H__
#include "../../Framework/04_Scene/Scene.h"

int titleInitialize(PtrSceneFunctions _ptrScene,void* _vptrUserData);
PtrSceneFunctions titleUpdate(double _deltaTime, double _elapceTime);
int titleExit(PtrSceneFunctions _ptrScene);

#endif /* __TITLESCENE_H__ */

