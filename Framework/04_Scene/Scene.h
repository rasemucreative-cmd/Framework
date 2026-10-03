/**
 * @file Scene.h
 * @author Rasemu
 * @brief シーン処理とシーン構造体
 * @version 0.1
 * @date 2026-09-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef __SCENE_H__
#define __SCENE_H__

typedef struct Functions* PtrSceneFunctions;
typedef struct Functions** WPtrSceneFunctions;

/**
 * @struct Functions
 * @typedef SceneFunctions
 * @brief ゲームシーンの実体に最低限必要なメンバを持たせた構造体
 * @note この構造体では外部にはポインタとアクセス用の関数を用意している
 *       また、構造体の持つメンバに着いては一部ユーザー側が定義しなければ
 *       いけないものもある細かいことはCファイルで.
 * @{
 */
struct Functions{
    /** ユーザー定義のボイドポインタ */
    void* vprtUserData;

    /** ユーザー定義の初期化関数 */
    int (*initialize)(PtrSceneFunctions,void*);

    /** ユーザー定義の更新処理 */
    PtrSceneFunctions (*update)(double,double);

    /** ユーザー定義のvprtUserDataの処理や自身の解放 */
    int (*exit)(PtrSceneFunctions);
};
/**
 * @}
 */

 /**
  * @brief SceneFunctionの初期化
  * 
  * @return PtrSceneFunctions 
  */
WPtrSceneFunctions GameInitialize();

/**
 * @brief シーンの更新とシーン遷移担当
 * @param[in] PtrSceneFunctions シーンの関数ポインタをSceneFunctionsから呼び出す
 * @param[in] _deltaTime 直前のフレームから現在のフレームまでに経過した時間（秒）のこと
 * @param[in] _elapcedTime 経過時間
 * @return PtrSceneFunctions 次のシーンポインタへ
 */
PtrSceneFunctions SceneUpdate(PtrSceneFunctions,double,double);

/**
 * @brief SceneFunctionsが持つ初期化関数を呼び出し自身の構造体を初期化
 * @param[in,out] WPtrSceneFunctions 初期化メンバの呼び出し
 * @param[in] void* SceneFunctionsが持つユーザーデータ
 * @return int (0:成功/0以外：失敗)
 */
int SceneInitialize(WPtrSceneFunctions);

/**
 * @brief SceneFunctionsが持つ解放処理関数を呼び出し自身の構造体の内容を削除する
 * @param[in] PtrSceneFunctions 終了処理メンバの呼び出し
 * @return int (0:成功/0以外：失敗)
 */
int SceneExit(WPtrSceneFunctions);

#endif /* __SCENE_H__ */