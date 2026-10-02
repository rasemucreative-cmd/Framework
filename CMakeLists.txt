cmake_minimum_required(VERSION 3.10.0)
project(Framework VERSION 0.1.0 LANGUAGES C)

add_executable(Framework 
    Framework/main.c
    Framework/00_Common/castDefines.c
    Framework/01_Application/Application.c
    Framework/02_GameLoop/GameLoop.c
    Framework/03_Timer/Timer.c
    Framework/04_Scene/Scene.c
    UserProgrameSource/01_Scene/SceneEntry.c
    UserProgrameSource/01_Scene/TitleScene.c
    )

