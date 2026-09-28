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
#ifndef __GAMELOOP_H__
#define __GAMELOOP_H__

/**
 * @fn gameLoop(struct Application*)
 * 
 * @brief ゲーム進行管理
 * @note シーンの切り替え管理やTimerの通知を各シーンに行う
 * 
 * @param _ptrApplication アプリケーション管理担当
 * 
 * @warning _ptrApplication <-- がNULLの場合assertで即終了するので注意
 * 
 */
void gameLoop(struct Application* _ptrApplication);

#endif /* __GAMELOOP_H__ */