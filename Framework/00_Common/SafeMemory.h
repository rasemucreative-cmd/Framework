/**
 * @file SafeMemory.h
 * @author rasemu
 * @brief addtogroup SafeMemory
 * @brief メモリを安全に確保するための関数の宣言
 * @version 0.2
 * @date 2026-10-03
 * @par 変更履歴:
 *      - 2026-10-03: 新規作成
 *      - 2026-10-04: SafeFree関数の修正
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef __SAFEMEMORY_H__
#define __SAFEMEMORY_H__

typedef struct _PointerPools PointerPools;

/**
 * @brief メモリを安全に確保するための関数です
 * 
 * @param[in] _size 確保するメモリのサイズ
 * @param[in] _cprFileName ファイル名
 * @param[in] _lineNumber 行番号
 * @return void* 確保したメモリのアドレス
 */
void* SafeMalloc(unsigned long long _size, const char* _cptrFileName, const int _lineNumber);

/**
 * @brief メモリを安全に解放するための関数です
 * 
 * @param[in] _wptr 解放するメモリのアドレスを指すポインタのアドレス
 */
void SafeFree(void **_wptr);

#if _DEBUG
#else
#endif



#endif /* __SAFEMEMORY_H__ */