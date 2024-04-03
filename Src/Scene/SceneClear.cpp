#include "DxLib.h"
#include "SceneClear.h"
#include "Scene.h"
#include "../Input/Input.h"

//タイトルハンドル
int clear_buckGround_image_handle;

//クリア初期化
void InitClear()
{
	//画像読み込み
	//背景
	clear_buckGround_image_handle = LoadGraph(CLEAR_BUCKGROUND_PATH);

	//クリア通常処理に移動
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//クリア通常処理
void StepClear()
{
	//エンターキーでクリア後処理に移動
	if (IsKeyRelease(KEY_INPUT_RETURN))
	{
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}
}

//クリア描画処理
void DrawClear()
{
	//画像表示
	//背景
	DrawGraph(0, 0, clear_buckGround_image_handle, true);
}

//クリア後処理
void FinClear()
{
	//画像破棄
	//背景
	DeleteGraph(clear_buckGround_image_handle);
}