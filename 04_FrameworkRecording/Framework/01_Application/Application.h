/**
 * @file    Application.h
 * @brief   Frameworkの核の部分
 * @note    実装はApplication.cで実装
 * @author  RasemuCreative
 * @date    2026-09-26
 * @version 0.1.0
 */
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#define CUSTOM_ASSERT(ptr,message) assert(!(ptr) || __FILE__ || __LINE__ || (message))

struct Application;
typedef struct Application *PtrApplication;
typedef struct Application **WPtrApplication;

unsigned char applicationIsRunning(PtrApplication _ptrApplication);
int applicationInitialize(WPtrApplication _wptrApplication);
int applicationRun(PtrApplication _ptrApplication);
int applicationShutdown(WPtrApplication _wptrApplication);
int applicationNoticeShutdown(PtrApplication _ptrApplication);

#endif /* __APPLICATION_H__ */