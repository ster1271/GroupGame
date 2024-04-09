#include "DxLib.h"
#include "../Common.h"
#include "../Effect/Effect.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "ScenePlay.h"
#include "../Player/Player.h"
#include "../Gate/Gate.h"
#include "../Enemy/Enemy.h"
#include "../Score/Score.h"

//背景クラスの宣言
BackGround background;

//道路クラスの宣言
Road road;

//フレームをカウントする変数
int FrameCount = 0;

//ゲームオーバーフラグ
bool isGameOver;

//BGM格納ハンドル
int BgmHandle = 0;

int Template = 0;

//プレイシーン初期化
void InitPlay()
{
	//ゲームオーバーフラグを折る
	isGameOver = false;

	//プレイヤーの初期化
	InitPlayer();

	//背景の初期化
	background.InitBackGround();

	//道路の初期化および画像の読み込み
	road.InitRoad();

	Template = GetRand(TEMP_NUM);

	//ゲートのテンプレ読み込み
	LoadGate(Template);

	//ゲートの初期化
	InitGate();

	//体力設定
	SetLife(Template);

	//敵の初期化
	InitEnemy();

	//ランクの初期化
	InitRank();

	//エフェクトの初期化
	InitEffect();

	FrameCount = 0;

	//BGM読み込み
	BgmHandle = LoadSoundMem(BGM_PATH);

	//BGM再生
	PlaySoundMem(BgmHandle, DX_PLAYTYPE_LOOP, true);

	//プレイシーンループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void StepPlay()
{
	//自動スクロール処理
	road.MoveRoad();

	//プレイヤー通常処理
	StepPlayer();

	//ゲート通常処理
	StepGate();

	//敵通常処理
	StepEnemy();

	//ランク通常処理
	StepRank();

	//エフェクト通常処理
	StepEffect();

	//プレイヤー情報取得
	PlayerInfo* playerInfo = GetPlayerInfo();

	//クリアフラグがtrueなら
	if (playerInfo->isClear)
	{
		//プレイシーン後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

	//ライフが0になったら
	if (playerInfo->Life <= 0)
	{
		playerInfo->Life = 0;

		//生存フラグを折る
		playerInfo->isAlive = false;

		//エフェクトを描画
		PlayEffect(EFFECT_TYPE_EXPLOSION, (int)playerInfo->PosX, (int)playerInfo->PosY);

		//フレームをカウント
		FrameCount++;

		if (FrameCount > FRAME_RATE / 2)
		{
			//ゲームオーバーフラグを立てる
			isGameOver = true;
		}

		//ゲームオーバーフラグがtrueなら
		if (isGameOver)
		{
			//プレイシーン後処理へ移動
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;
		}
	}
}

//プレイシーン描画処理
void DrawPlay()
{
	//背景描画処理
	background.DarwBakcGround();

	//道路描画処理
	road.DrawRoad();

	//ゲート描画処理
	DrawGate();

	//プレイヤー描画処理
	DrawPlayer();

	//敵描画処理
	DrawEnemy();

	//ランク描画処理
	DrawRank();

	//エフェクト描画処理
	DrawEffect();

	//デバッグ用文字
	DrawFormatString(50, 150, GetColor(255, 255, 255), "W または →:右移動");
	DrawFormatString(50, 180, GetColor(255, 255, 255), "A または ←:左移動");
}

//プレイシーン後処理
void FinPlay()
{
	//道路画像後処理
	road.FinRoad();

	//背景の後処理
	background.FinBackGround();

	//プレイヤーの後処理
	FinPlayer();

	//ゲートの後処理
	FinGate();

	//敵の後処理
	FinEnemy();

	//ランクの後処理
	FinRank();
	
	//エフェクトの後処理
	FinEffect();

	//BGM停止
	StopSoundMem(BgmHandle);

	//BGM破棄
	DeleteSoundMem(BgmHandle);

	//プレイヤー情報取得
	PlayerInfo* playerInfo = GetPlayerInfo();

	//クリアフラグがtrueなら
	if (playerInfo->isClear)
	{
		//クリアシーンへ移行
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}

	//生存フラグがfalseなら
	else if (!playerInfo->isAlive)
	{
		//ゲームオーバーシーンへ移行
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;
	}
}
