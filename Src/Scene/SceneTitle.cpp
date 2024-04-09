#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//タイトル背景画像のハンドル
int BgTitleHandle;

//タイトル画像ハンドル
int TitleHundle;

//BGMのハンドル
int Title_Bgm;

//タイトル初期化
void InitTitle()
{
	//タイトル背景画像の初期化
	BgTitleHandle = LoadGraph(BG_TITLE_PATH);

	//タイトル画像読み込み
	TitleHundle = LoadGraph(TITLE_PATH);

	//BGM読み込み
	Title_Bgm = LoadSoundMem(TITLE_BGM_PATH);

	//BGM再生
	PlaySoundMem(Title_Bgm, DX_PLAYTYPE_LOOP, true);

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

	//タイトル画像の描画
	DrawGraph(250, 0, TitleHundle, true);
}

//タイトル後処理
void FinTitle()
{
	//タイトル背景画像の破棄
	DeleteGraph(BgTitleHandle);

	//BGM停止
	StopSoundMem(Title_Bgm);

	//BGM破棄
	DeleteSoundMem(Title_Bgm);

	//タイトルの後はプレイへ
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
