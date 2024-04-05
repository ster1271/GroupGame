#include "DxLib.h"
#include "../Common.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "ScenePlay.h"
#include "../Effect/Effect.h"

//プレイヤークラスの宣言
Player player;

//------------------------------------------------
// ちゃんとした処理ができるまでの仮置き処理

//エンターが押されたかどうか(クリアフラグ)
bool isPushEnter;

//スペースが押されたかどうか(ゲームオーバーフラグ)
bool isPushSpace;

//------------------------------------------------

//プレイシーン初期化
void InitPlay()
{
	//------------------------------------------------
	// ちゃんとした処理ができるまでの仮置き処理
	
	//クリアフラグを折る
	isPushEnter = false;

	//ゲームオーバーフラグを折る
	isPushSpace = false;

	//------------------------------------------------

	//プレイヤーの初期化
	player.InitPlayer();

	//道路の初期化および画像の読み込み
	player.InitRoad();

	//エフェクトの初期化
	InitEffect();

	//プレイシーンループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void StepPlay()
{
	//プレイヤー通常処理
	player.StepPlayer();

	//エフェクト通常処理
	StepEffect();

	//------------------------------------------------
	// ちゃんとした処理ができるまでの仮置き処理

	//エンターキーが押されたら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//クリアフラグを立てる
		isPushEnter = true;

		//プレイシーン後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

	//スペースキーが押されたら
	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		//ゲームオーバーフラグを立てる
		isPushSpace = true;

		//プレイシーン後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

	//------------------------------------------------
}

//プレイシーン描画処理
void DrawPlay()
{
	//道路描画処理
	player.DrawRoad();

	//プレイヤー描画処理
	player.DrawPlayer();

	//エフェクト描画処理
	DrawEffect();

	//デバッグ用文字
	DrawFormatString(0, 0, GetColor(255, 255, 255), "W または →:右移動");
	DrawFormatString(0, 30, GetColor(255, 255, 255), "A または ←:左移動");
	DrawFormatString(0, 60, GetColor(255, 255, 255), "エンターでクリアシーンに移行");
	DrawFormatString(0, 90, GetColor(255, 255, 255), "スペースでゲームオーバーシーンに移行");
}

//プレイシーン後処理
void FinPlay()
{
	//道路画像後処理
	player.FinRoad();

	//プレイヤーの後処理
	player.FinPlayer();
	
	//エフェクトの後処理
	FinEffect();

	//------------------------------------------------
	// ちゃんとした処理ができるまでの仮置き処理

	//クリアフラグがtrueなら
	if (isPushEnter)
	{
		//クリアシーンへ移行
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}

	//ゲームオーバーフラグがtrueなら
	else if (isPushSpace)
	{
		//ゲームオーバーシーンへ移行
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;
	}

	//------------------------------------------------

}