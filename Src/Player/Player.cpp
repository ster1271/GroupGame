#include "DxLib.h"
#include "../Common.h"
#include "../Input/Input.h"
#include "Player.h"

//プレイヤー情報構造体の宣言
PlayerInfo playerInfo = { 0 };

void InitPlayer()	//プレイヤーの初期化
{
	//画像の読み込み
	LoadPlayer(PLAYER_1);	//runBoy1
	LoadPlayer(PLAYER_2);	//runBoy2
	LoadPlayer(PLAYER_3);	//runBoy3
	LoadPlayer(PLAYER_4);	//runBoy4
	LoadPlayer(PLAYER_5);	//runBoy5
	LoadPlayer(PLAYER_6);	//runBoy6
	LoadPlayer(PLAYER_7);	//runBoy7
	LoadPlayer(PLAYER_8);	//runBoy8
	LoadPlayer(PLAYER_9);	//runBoy9
	LoadPlayer(PLAYER_10);	//runBoy10
	playerInfo.PosX = 640.0f;			//初期X座標を設定
	playerInfo.PosY = 550.0f;			//初期Y座標を設定
	playerInfo.Radius = 32.0f;			//半径を設定
	playerInfo.MoveSpeed = 4.0f;		//初期移動速度を設定
	playerInfo.CurrentScore = 0;		//スコアをリセット
	playerInfo.Life = 1;				//初期ライフを設定
	playerInfo.isAlive = true;			//生存フラグを立てる
	playerInfo.Cleared = 0;				//クリア数をリセット
	playerInfo.BreakEnemy = 0;			//倒した敵の数をリセット
	playerInfo.isRank = false;			//ランク表示はしない
	playerInfo.isClear = false;			//クリアフラグを折る
	playerInfo.Result = 0;
}

void StepPlayer()	//プレイヤー通常処理
{
	MovePlayer();	//プレイヤーの移動処理

	ChangePlayerImage();	//	プレイヤーの画像を変える
}

void DrawPlayer()	//プレイヤー描画処理
{
	if (playerInfo.isAlive)
	{
		DrawRotaGraph((int)playerInfo.PosX, (int)playerInfo.PosY, 1.0f, 0.0f, playerInfo.PlayerHandle[playerInfo.HandleIndex], true);
		DrawFormatString((int)playerInfo.PosX - 10, (int)playerInfo.PosY, GetColor(0, 0, 0), "%d", playerInfo.Life);		//ライフの描画
	}
	DrawFormatString(50, 240, GetColor(255, 255, 255), "Score:%d", playerInfo.CurrentScore);	//スコアの描画
}

void FinPlayer()	//プレイヤーの後処理
{
	//画像を破棄
	DeleteGraph(playerInfo.PlayerHandle[0]);
}

void LoadPlayer(PLAYER_IMAGE type)	//プレイヤー画像の読み込み
{
	playerInfo.PlayerHandle[type] = LoadGraph(PlayerImage_Path[type]);
}

void MovePlayer()	//プレイヤーの移動処理
{
	//Dキーまたは右矢印キーを押している間
	if (IsKeyKeep(KEY_INPUT_D) || IsKeyKeep(KEY_INPUT_RIGHT))
	{
		//右に移動する
		playerInfo.PosX += playerInfo.MoveSpeed;

		//道路の端まで到達したら
		if (playerInfo.PosX >= 880.0f)
		{
			//それ以上右に行けないようにする
			playerInfo.PosX = 880.0f;
		}
	}

	//Aキーまたは左矢印キーを押している間
	else if (IsKeyKeep(KEY_INPUT_A) || IsKeyKeep(KEY_INPUT_LEFT))
	{
		//左に移動する
		playerInfo.PosX -= playerInfo.MoveSpeed;

		//道路の端まで到達したら
		if (playerInfo.PosX <= 404.0f)
		{
			//それ以上左に行けないようにする
			playerInfo.PosX = 404.0f;
		}
	}
}

void ChangePlayerImage()	//プレイヤーの画像を変える
{
	playerInfo.AnimeFrame++;	//再生時間をカウント
	if (playerInfo.AnimeFrame >= FRAME_TIME / 2)	//一定の時間に達したら
	{
		playerInfo.AnimeFrame = 0;		//再生時間をリセット

		if (!playerInfo.isReverse)		//逆再生フラグがfalseなら
		{
			if (playerInfo.HandleIndex == 9)	//最後の画像なら
			{
				playerInfo.isReverse = true;	//逆再生にする
				playerInfo.HandleIndex = 8;	//1つ前の画像にする
			}

			else	//最後の画像でないなら
			{
				playerInfo.HandleIndex++;	//次の画像に切り替える
			}
		}

		else
		{
			if (playerInfo.HandleIndex == 0)	//最初の画像なら
			{
				playerInfo.isReverse = false;	//通常再生にする
				playerInfo.HandleIndex = 1;	//1つ次の画像にする
			}

			else	//最初の画像でないなら
			{
				playerInfo.HandleIndex--;	//前の画像に切り替える
			}
		}
	}
}

PlayerInfo* GetPlayerInfo()	//プレイヤー情報取得
{
	return &playerInfo;
}
