/**
 * @file castDefines.c
 * @author rasemu
 * @brief リトルエンディアンまたはビッグエンディアンに変換する
 * @version 0.1
 * @date 2026-10-01
 * @par 変更履歴:
 *     - 2026-10-01: 新規作成
 *     - 2026-10-02: convertEndian関数の実装
 *
 * @copyright Copyright (c) 2026
 * 
 */
#include "CastDefines.h"

unsigned long long convertEndian(unsigned char mode,unsigned char src[], unsigned long long srcSize){
    unsigned long long out = 0;
    unsigned long long index = 0;

    if(srcSize > sizeof(unsigned long long)){
        return 0;
    }

    if(mode == 0){
        for(index = 0; index <= srcSize - 1; ++index){
            out |= ((unsigned long long)src[index] << (index * 8));
        }
    }else if(mode == 1){
        for(index = 0; index < srcSize - 1 ; ++index){
            out |= ((unsigned long long)src[srcSize - 1 - index] << (index * 8));
        }
    }else{
        return 0;
    }
    return out;
}
