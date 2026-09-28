cmake_minimum_required(VERSION 3.10.0)
project(Framework VERSION 0.1.0 LANGUAGES C)

add_executable(Framework main.c
    Framework/01_Application/Applecation.c
    Framework/02_GameLoop/GameLoop.c)

