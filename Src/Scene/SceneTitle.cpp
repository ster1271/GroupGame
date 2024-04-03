#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//タイトル背景画像のハンドル
int BgTitleHandle;

//タイトル文字画像のハンドル
int TitleTextHandle;

//スタート文字画像のハンドル
int StartTextHandle;

//タイトル初期化
void InitTitle()
{
	//タイトル背景画像の初期化
	BgTitleHandle = LoadGraph(BG_TITLE_PATH);

	//タイトル文字画像の初期化
	TitleTextHandle = LoadGraph(TITLE_TEXT_PATH);

	//スタート文字画像の初期化
	StartTextHandle = LoadGraph(START_TEXT_PATH);

	//タイトルループへ
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//タイトル通常処理
void StepTitle()
{
	//Enterキーが押されたら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//タイトル後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

//タイトル描画処理
void DrawTitle()
{
	//タイトル背景画像の描画
	DrawGraph(0, 0, BgTitleHandle, true);

	//タイトル文字画像の描画
	DrawRotaGraph(320, 150, 1.0f, 0.0f, TitleTextHandle, true);

	//スタート文字画像の描画
	DrawRotaGraph(320, 400, 1.0f, 0.0f, StartTextHandle, true);
}

//タイトル後処理
void FinTitle()
{
	//タイトル背景画像の破棄
	DeleteGraph(BgTitleHandle);

	//タイトル文字画像の破棄
	DeleteGraph(TitleTextHandle);

	//スタート文字画像の破棄
	DeleteGraph(StartTextHandle);

	//タイトルの後はプレイへ
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
