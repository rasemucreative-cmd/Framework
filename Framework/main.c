#include <stdio.h>
#include "01_Application/Application.h"

int main(int _argCount, char** _wptrArgList){
    printf("Hello, from Framework!\n");
    PtrApplication ptrApplication = NULL;
    applicationInitialize(&ptrApplication);
    applicationRun(ptrApplication);
    applicationShutdown(&ptrApplication);
    printf("アプリケーション実装完了。おめでとう！！\n");
    return 0;
}
