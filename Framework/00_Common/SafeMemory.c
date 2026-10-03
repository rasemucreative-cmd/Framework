/**
 * @file SafeMemory.c
 * @author rasemu
 * @brief メモリを安全に確保するための関数の実装です
 * @version 0.2
 * @date 2026-10-03
 * @par 変更履歴:
 *      - 2026-10-03: 新規作成 
 *      - 2026-10-04: SafeFree関数の修正
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "SafeMemory.h"

typedef struct _PointerPools
{
    void* dataInfo; //!< pointarPoolでデータのアドレスを保持する
    char* _cptrFileName; //!< データを確保したファイル名
    int lineNumber; //!< データを確保した行番号
    long long usedIndex; //!< ポインタプールのこの要素を使用している場合のインデックス
    unsigned char isUsed; //!< ポインタプールのこの要素をを使用しているかどうか
                          //!< 0:使用していない / 1:使用している
} PointerPools;


/** @brief ポインタプール */
PointerPools gPointerPoolInfo[500] = { 0 };

/**
 * @brief メモリを安全に確保する関数です
 * 
 * @param _size 確保するメモリのサイズ
 * @param _cptrFileName ファイル名
 * @param lineNumber 行番号
 * @return void* 確保したメモリのアドレス
 */
void* SafeMalloc(unsigned long long _size, const char* _cptrFileName, int lineNumber) {
    static long long index = 0;
    static long long startIndex = 0;

    while (gPointerPoolInfo[index].isUsed == 1) {
        index++;
        if (index >= 500) {
            break;
        }
    }

    if(index >= 500) {
        fprintf(stderr, "Pointer pool is full. Cannot allocate more memory.\n");
        index = startIndex; // Reset index to start searching from the beginning
        return NULL;
    }

    void* ptr = malloc(_size);
    if (ptr == NULL) {  
        fprintf(stderr, "Memory allocation failed in file %s at line %d\n", _cptrFileName, lineNumber);
        return NULL;
    }

    gPointerPoolInfo[index].dataInfo = ptr;
    gPointerPoolInfo[index].usedIndex = index;
    gPointerPoolInfo[index]._cptrFileName = (char*)malloc(strlen(_cptrFileName) + 1);
    strncpy_s( (char*)_cptrFileName,strlen(_cptrFileName) + 1,
        gPointerPoolInfo[index]._cptrFileName, 
        sizeof(gPointerPoolInfo[index]._cptrFileName) / sizeof(gPointerPoolInfo[index]._cptrFileName[0]));
    gPointerPoolInfo[index].lineNumber = lineNumber;
    gPointerPoolInfo[index].isUsed = 1;
    startIndex = index + 1;
    return ptr;
}

/**
 * @brief メモリを安全に解放する関数です
 * 
 * @param ptr 解放するメモリのアドレスを指すポインタのアドレス
 * 
 */
void SafeFree(void **ptr)
{
    static long long index = 0;
    static long long startIndex = 0;
    index = startIndex;
    while (gPointerPoolInfo[gPointerPoolInfo[index].usedIndex].isUsed == 1
        && gPointerPoolInfo[gPointerPoolInfo[index].usedIndex].dataInfo != *ptr) {
        index++;
        if (index >= 500) {
            fprintf(stderr, "Pointer not found in pool. Cannot free memory.\n");
            return;
        }
    }

    free(gPointerPoolInfo[gPointerPoolInfo[index].usedIndex].dataInfo);
    free(gPointerPoolInfo[gPointerPoolInfo[index].usedIndex]._cptrFileName);
    gPointerPoolInfo[gPointerPoolInfo[index].usedIndex].dataInfo = NULL;
    gPointerPoolInfo[gPointerPoolInfo[index].usedIndex]._cptrFileName = NULL;
    gPointerPoolInfo[gPointerPoolInfo[index].usedIndex].lineNumber = 0;
    gPointerPoolInfo[gPointerPoolInfo[index].usedIndex].isUsed = 0;

    free(*ptr); // Free the memory pointed to by ptr
    *ptr = NULL; // Set the pointer to NULL after freeing
    free(ptr); // Free the pointer itself
    ptr = NULL; // Set the pointer to NULL after freeing
}
