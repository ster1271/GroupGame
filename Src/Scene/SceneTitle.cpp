#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//タイトル背景画像のハンドル
int BgTitleHandle;

//矢印画像ハンドル
int S_Handle;

//タイトル文字画像のハンドル
int TitleTextHandle;

//サブタイトル文字画像のパス
int SubTitleTextHandle;

//スタート文字画像のハンドル
int StartTextHandle;

//BGMのハンドル
int Title_Bgm;

//タイトル初期化
void InitTitle()
{
	//タイトル背景画像の初期化
	BgTitleHandle = LoadGraph(BG_TITLE_PATH);


	//矢印画像の初期化
	S_Handle = LoadGraph(SELECT_PATH);

	//タイトル文字画像の初期化
	TitleTextHandle = LoadGraph(TITLE_TEXT_PATH);

	//サブタイトル文字画像の初期化
	SubTitleTextHandle = LoadGraph(SUB_TEXT_PATH);

	//スタート文字画像の初期化
	StartTextHandle = LoadGraph(START_TEXT_PATH);


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

	//矢印画像の描画
	DrawRotaGraph(430, 630, 2.0f, 0.0f, S_Handle, true, false, false);

	//タイトル文字画像の描画
	DrawRotaGraph(640, 300, 1.0f, 0.0f, TitleTextHandle, true);

	//サブタイトル文字画像の描画
	DrawRotaGraph(640, 150, 1.0f, 0.0f, SubTitleTextHandle, true);

	//スタート文字画像の描画
	DrawRotaGraph(640, 550, 1.0f, 0.0f, StartTextHandle, true);
}

//タイトル後処理
void FinTitle()
{
	//タイトル背景画像の破棄
	DeleteGraph(BgTitleHandle);

	//矢印画像の破棄
	DeleteGraph(S_Handle);

	//タイトル文字画像の破棄
	DeleteGraph(TitleTextHandle);

	//サブタイトル文字画像の破棄
	DeleteGraph(SubTitleTextHandle);

	//スタート文字画像の破棄
	DeleteGraph(StartTextHandle);

	//BGM停止
	StopSoundMem(Title_Bgm);

	//BGM破棄
	DeleteSoundMem(Title_Bgm);

	//タイトルの後はプレイへ
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
