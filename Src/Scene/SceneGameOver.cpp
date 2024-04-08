//2309430 宮近一星

#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

//ゲームオーバー背景画像ハンドル
int BgGameOverHundle;

//矢印画像ハンドル
int SelectHundle;

<<<<<<< Updated upstream
//セレクトY座標
int SelectPosY;

=======
//矢印Y座標
int SelectPosY;

//コンテニューフラグ
bool isContinue;

//バックタイトルフラグ
bool isBackTitle;

//BGMのハンドル
int GameOver_Bgm;

//効果音のパス
int Select_SE = 0;

>>>>>>> Stashed changes
//ゲームオーバー初期化
void InitGameOver()
{
	//背景画像読み込み
	BgGameOverHundle = LoadGraph(BG_GAMEOVER_PATH);

	//矢印画像読み込み
	SelectHundle = LoadGraph(SELECT_PATH);

<<<<<<< Updated upstream
	//座標設定
	SelectPosY = 360;
=======
	//矢印の初期Y座標設定
	SelectPosY = 370;

	//コンテニューフラグ
	isContinue = false;

	//バックタイトルフラグ
	isBackTitle = false;

	//BGM読み込み
	GameOver_Bgm = LoadSoundMem(GAMEOVER_BGM_PATH);

	//BGM再生
	PlaySoundMem(GameOver_Bgm, DX_PLAYTYPE_LOOP, true);

	//効果音読み込み
	Select_SE = LoadSoundMem(SELECT_SE);
>>>>>>> Stashed changes

	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//ゲームオーバー通常処理
void StepGameOver()
{
<<<<<<< Updated upstream
	if (IsKeyPush(KEY_INPUT_UP))
	{
		SelectPosY = 360;
	}
	else if(IsKeyPush(KEY_INPUT_DOWN))
	{
		SelectPosY = 525;
=======
	//Wまたは上矢印キーで
	if (IsKeyPush(KEY_INPUT_W) || IsKeyPush(KEY_INPUT_UP))
	{
		//Back Titleの隣なら
		if (SelectPosY == 570)
		{
			//効果音再生
			PlaySoundMem(Select_SE, DX_PLAYTYPE_BACK, true);
		}
		//Continueの隣へ
		SelectPosY = 370;
	}

	//Sまたは下矢印キーで
	else if (IsKeyPush(KEY_INPUT_S) || IsKeyPush(KEY_INPUT_DOWN))
	{
		//Continueの隣なら
		if (SelectPosY == 370)
		{
			//効果音再生
			PlaySoundMem(Select_SE, DX_PLAYTYPE_BACK, true);
		}
		//Back Titleの隣へ
		SelectPosY = 570;
>>>>>>> Stashed changes
	}

	//Enterキーが押されたら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//Continueの隣なら
		if (SelectPosY == 370)
		{
			//コンテニューフラグを立てる
			isContinue = true;
		}

		//Back Titleの隣なら
		else if (SelectPosY == 570)
		{
			//バックタイトルフラグを立てる
			isBackTitle = true;
		}
		//ゲームオーバー後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

//ゲームオーバー描画処理
void DrawGameOver()
{
	///背景画像描画
	DrawGraph(0, 0, BgGameOverHundle, true);

<<<<<<< Updated upstream
	//矢印画像描画
	DrawRotaGraph(370, SelectPosY, 2.0f, 0.0f, SelectHundle, true, false, false);
=======
	//ゲームオーバー文字画像描画
	DrawRotaGraph(640, 200, 1.0f, 0.0f, GameOverHundle, true);

	//コンティニュー文字画像描画
	DrawRotaGraph(640, 400, 1.0f, 0.0f, ContinueHundle, true);

	//タイトルに戻る文字画像描画
	DrawRotaGraph(640, 600, 1.0f, 0.0f, BackTitleHundle, true);

	//矢印画像描画
	DrawGraph(300, SelectPosY, SelectHundle, true);
>>>>>>> Stashed changes
}

//ゲームオーバー後処理
void FinGameOver()
{
	//背景画像破棄
	DeleteGraph(BgGameOverHundle);

	//矢印画像破棄
	DeleteGraph(SelectHundle);

<<<<<<< Updated upstream

	if (SelectPosY == 360)
	{
		//プレイシーンに戻る
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
	else
=======
	//BGM停止
	StopSoundMem(GameOver_Bgm);

	//BGM破棄
	DeleteSoundMem(GameOver_Bgm);

	//効果音破棄
	DeleteSoundMem(Select_SE);

	//コンテニューフラグがtrueなら
	if (isContinue)
	{
		//プレイシーンに戻るようにする
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}

	//バックタイトルフラグがtrueなら
	if (isBackTitle)
>>>>>>> Stashed changes
	{
		//タイトルに戻るようにする
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
<<<<<<< Updated upstream
}
=======
}
>>>>>>> Stashed changes
