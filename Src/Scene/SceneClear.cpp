#include "DxLib.h"
#include "SceneClear.h"
#include "Scene.h"

//タイトルハンドル
int clear_buckGround_image_handle;
int Select_Hundle;

//クリア初期化
void InitClear()
{
	//画像読み込み
	//背景
	clear_buckGround_image_handle = LoadGraph(CLEAR_BUCKGROUND_PATH);
	Select_Hundle = LoadGraph(SELECT_PATH);

	//クリア通常処理に移動
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//クリア通常処理
void StepClear()
{


	//エンターキーでクリア後処理に移動
	if (IsKeyPush(KEY_INPUT_RETURN))
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

	DrawRotaGraph(330, 600, 2.0f, 0.0f, Select_Hundle, true, false, false);
}

//クリア後処理
void FinClear()
{
	//画像破棄
	//背景
	DeleteGraph(clear_buckGround_image_handle);

	DeleteGraph(Select_Hundle);

	//タイトルシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}