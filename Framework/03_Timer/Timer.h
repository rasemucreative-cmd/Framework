/**
 * @file Timer.h
 * @author Rasemu
 * @brief ゲーム内時間管理
 * @version 0.1.0
 * @date 2026-09-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef __TIMER_H__
#define __TIMER_H__

/**
 * @brief ゲーム時間管理構造体
 * 
 * @{
 */
struct Timer; /**!< タイマーの基本型 */
typedef struct Timer GameTimer; /**!< Timerのエイリアス */
typedef struct Timer *PtrGameTimer;/**!< GameTimerへのポインタ */
typedef struct Timer **WPtrGameTimer; /**!< PtrGameTimerへのポインタ */
/**
 * @}
 */

 /**
  * @brief GameTimerを生成
  * 
  * @return PtrGameTimer 
  */
PtrGameTimer createGameTimer();

/**
 * @brief GameTimerを削除
 * 
 * @param[in] GameTimerの実体へのダブルポインタ
 */
void deleteGameTimer(WPtrGameTimer);

/**
 * @brief タイマーの更新
 * @param[in] GameTimerへのポインタ
 */
void updateTimer(PtrGameTimer);

/**
 * @{
 */
/**
 * @brief FPSを取得する
 * 
 * @return double (FPS)
 */
double getFPSTimer(const PtrGameTimer);

/**
 * @brief FrameRateを取得する
 * 
 * @return double (FrameRate)
 */
double getFrameRate(const PtrGameTimer);

/**
 * @brief DeltaTimeを取得する
 * 
 * @return double (DeltaTime)
 */
double getDeltaTime(const PtrGameTimer);

/**
 * @}
 */

#endif /* __TIMER_H__ */