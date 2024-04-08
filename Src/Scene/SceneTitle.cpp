#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//タイトル背景画像のハンドル
int BgTitleHandle;

//矢印画像ハンドル
int S_Handle;

//タイトル初期化
void InitTitle()
{
	//タイトル背景画像の初期化
	BgTitleHandle = LoadGraph(BG_TITLE_PATH);

	//矢印画像の初期化
	S_Handle = LoadGraph(SELECT_PATH);

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

	//矢印画像の描画
	DrawRotaGraph(430, 630, 2.0f, 0.0f, S_Handle, true, false, false);


}

//タイトル後処理
void FinTitle()
{
	//タイトル背景画像の破棄
	DeleteGraph(BgTitleHandle);

	//矢印画像の破棄
	DeleteGraph(S_Handle);

	//タイトルの後はプレイへ
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
