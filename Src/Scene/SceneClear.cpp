#include "DxLib.h"
#include "SceneClear.h"
#include "Scene.h"

//タイトルハンドル
int clear_buckGround_image_handle;
int Select_Hundle;

//星の背景
int Bg_SterHndl[3] = { 0 };

//星の本体
int Score_SterHndl[3] = { 0 };

//クリア初期化
void InitClear()
{
	//画像読み込み
	//背景
	clear_buckGround_image_handle = LoadGraph(CLEAR_BUCKGROUND_PATH);
	Select_Hundle = LoadGraph(SELECT_PATH);

	//星の背景
	for (int i = 0; i < 3; i++)
	{
		Bg_SterHndl[i] = LoadGraph(BG_STER_PATH);
	}

	//星の本体
	for (int i = 0; i < 3; i++)
	{
		Score_SterHndl[i] = LoadGraph(STER_PATH);
	}

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

	for (int i = 0; i < 3; i++)
	{
		//灰色の星
		DrawGraph(220 * i + 360, 220, Bg_SterHndl[i], true);

		
	}

	//上限'3'を変数に変更する
	for (int a = 0; a < 3; a++)
	{
		//色付きの星
		DrawGraph(220 * a + 360, 220, Score_SterHndl[a], true);
	}
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