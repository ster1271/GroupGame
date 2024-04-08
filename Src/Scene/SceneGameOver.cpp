//2309430 宮近一星

#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

//ゲームオーバー背景画像ハンドル
int BgGameOverHundle;

//矢印画像ハンドル
int SelectHundle;

//セレクトY座標
int SelectPosY;

//ゲームオーバー初期化
void InitGameOver()
{
	//背景画像読み込み
	BgGameOverHundle = LoadGraph(BG_GAMEOVER_PATH);

	//矢印画像読み込み
	SelectHundle = LoadGraph(SELECT_PATH);

	//座標設定
	SelectPosY = 360;

	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//ゲームオーバー通常処理
void StepGameOver()
{
	if (IsKeyPush(KEY_INPUT_UP))
	{
		SelectPosY = 360;
	}
	else if(IsKeyPush(KEY_INPUT_DOWN))
	{
		SelectPosY = 525;
	}

	//Enterキーが押されたら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//ゲームオーバー後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

//ゲームオーバー描画処理
void DrawGameOver()
{
	///背景画像描画
	DrawGraph(0, 0, BgGameOverHundle, true);

	//矢印画像描画
	DrawRotaGraph(370, SelectPosY, 2.0f, 0.0f, SelectHundle, true, false, false);
}

//ゲームオーバー後処理
void FinGameOver()
{
	//背景画像破棄
	DeleteGraph(BgGameOverHundle);

	//矢印画像破棄
	DeleteGraph(SelectHundle);


	if (SelectPosY == 360)
	{
		//プレイシーンに戻る
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
	else
	{
		//タイトルに戻るようにする
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
}
