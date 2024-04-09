#include "DxLib.h"
#include "../Input/Input.h"
#include "../Player/Player.h"
#include "Score.h"

//ランク情報構造体の宣言
RankInfo rankInfo[STAR_NUM][2] = {0};

//ボーナススコア
int Bonus = 0;

//総合スコア
int Result = 0;

//効果音
int Result_SE = 0;

void InitRank()		//ランクの初期化
{
	for (int i = 0; i < STAR_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			rankInfo[i][0].StarHandle = LoadGraph(STAR_PATH);	//★
			rankInfo[i][1].StarHandle = LoadGraph(STAR2_PATH);	//灰色の★
			rankInfo[i][j].PosX = 400.0f;
			rankInfo[i][j].PosY = 480.0f;
			rankInfo[i][j].isDraw = false;
			rankInfo[i][j].Result = 0;
		}
	}

	//効果音読み込み
	Result_SE = LoadSoundMem(RESULT_SE);

	Bonus = 0;

	Result = 0;
}

void StepRank()		//ランク通常処理
{
	//プレイヤー情報取得
	PlayerInfo* playerInfo = GetPlayerInfo();

	Bonus = playerInfo->Life * 10;

	Result = playerInfo->CurrentScore + Bonus;

	playerInfo->Result = Result;

	for (int i = 0; i < STAR_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			rankInfo[i][j].Result = Result;
		}
	}
	//ランク表示フラグがtrueなら
	if (playerInfo->isRank)
	{
		//スコアが1000点以下なら
		if (Result <= 1000)
		{
			//★1つ
			rankInfo[0][0].isDraw = true;
			rankInfo[1][1].isDraw = true;
			rankInfo[2][1].isDraw = true;
		}

		//スコアが1001点以上2000点以下なら
		else if (Result >= 1001 && Result <= 2000)
		{
			//★2つ
			rankInfo[0][0].isDraw = true;
			rankInfo[1][0].isDraw = true;
			rankInfo[2][1].isDraw = true;
		}

		//スコアが2001点以上なら
		else if (Result >= 2001)
		{
			//★3つ
			rankInfo[0][0].isDraw = true;
			rankInfo[1][0].isDraw = true;
			rankInfo[2][0].isDraw = true;
		}

		//エンターキーが押されたら
		if (IsKeyPush(KEY_INPUT_RETURN))
		{
			//クリアフラグを立てる
			playerInfo->isClear = true;
		}

		//効果音再生
		PlaySoundMem(Result_SE, DX_PLAYTYPE_BACK, true);
	}
}

void DrawRank()		//ランク描画処理
{
	//プレイヤー情報取得
	PlayerInfo* playerInfo = GetPlayerInfo();

	for (int i = 0; i < STAR_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//描画フラグがtrueなら
			if (rankInfo[i][j].isDraw)
			{
				DrawFormatString(550, 150, GetColor(0, 0, 0), "Score  :%d", playerInfo->CurrentScore);
				DrawFormatString(550, 180, GetColor(0, 0, 0), "Bonus  :%d * 10 = %d", playerInfo->Life, Bonus);
				DrawFormatString(550, 210, GetColor(0, 0, 0), "Result :%d + %d = %d", playerInfo->CurrentScore, Bonus, Result);
				DrawFormatString(575, 300, GetColor(0, 0, 0), "Press Enter Key");
			}
		}
	}
}

void FinRank()		//ランクの後処理
{
	for (int i = 0; i < STAR_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			DeleteGraph(rankInfo[i][j].StarHandle);
		}
	}

	//効果音破棄
	DeleteSoundMem(Result_SE);
}