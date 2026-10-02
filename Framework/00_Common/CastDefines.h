/**
 * @file castDefines.h
 * @author rasemu
 * @brief データを安全に変換するためのマクロ関数や変換関数です
 * @version 0.1
 * @date 2026-10-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef __CASTDEFINES_H__
#define __CASTDEFINES_H__

/**
 * @brief ユーザーが定義した情報をvoid*にアドレスを格納し型の名前から
 * 　　　　変換した識別用IDをキャスト時に使います
 * 
 */
typedef struct {
    unsigned long long typeID; //!< 保持しているデータ型の名前から生成したID
    void* this; //!< ユーザーデータをアドレスとして保持するアドレスの中身は知らない
}TypeData;

/**
 * @brief 渡された文字列をリトルエンディアンかビッグエンディアンに変換します。
 * 
 * @param[in] mode //!< 0:リトルエンディアン / 1:ビッグエンディアン
 * @param src      //!< 変換元の文字列
 * @param srcSize  //!< 変換元の文字列の長さ
 * @return unsigned long long //!< 変換後の数値
 */
unsigned long long convertEndian(
    unsigned char mode,
    unsigned char src[], 
    unsigned long long srcSize
);

/**
 * @brief Xに格納されたものを文字列に置き換えます
 * 
 */
#define STRINGFY(x) (#x)

/**
 * @brief typeに格納された型の名前からIDに変換する
 * 
 */
#define TYPE_ID(type)\
_Generic(((type*)0),\
type*: convertEndian(0,STRINGFY(type),strlen(STRINGFY(type))),\
default: 0)

/**
 * @brief ユーザー定義された変数をTypeDataにIDとアドレスで保持させる
 * @param[in] userType ユーザー定義の型の名前に置き換える
 * @param[in] userData ユーザー定義の変数の名前に置き換える
 * @param[in] dataName TypeDataの変数名に置き換える
 * @param[in] ...      ユーザー定義の型を初期化するための可変長引数
 * @return dataName
 */
#define TYPE_DATA_INITIALIZE(userType,userData,dataName, ...)\
    ((userData) = (userType){__VA_ARGS__});\
    TypeData dataName = { TYPE_ID(userType), (void*)(&userData) };

/**
 * @brief 安全に型の変換をするためのマクロ
 * 　　　　IDが合わない場合NULLポインタが返る
 * 
 */
#define SAFE_CAST(type,typeID,typedData)\
((TYPE_ID(type) == (typeID)) ? \
    (type*)((typedData)) : NULL)


#endif /* __CASTDEFINES_H__ */