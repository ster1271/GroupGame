#pragma once

#define STAR_PATH	("Data/PlayImage/Rank/RankStar.png")	//★の画像のパス
#define STAR2_PATH	("Data/PlayImage/Rank/RankStar2.png")	//灰色の★の画像のパス

#define STAR_NUM	(3)		//星の数
#define RESULT_SE	("Data/Sounds/SE/Play/ResultScore.wav")	//リザルトの効果音のパス

//ランク情報構造体
struct RankInfo
{
	int StarHandle;		//画像ハンドル
	float PosX, PosY;	//X座標,Y座標
	bool isDraw;		//描画フラグ
};

void InitRank();	//ランクの初期化

void StepRank();	//ランク通常処理

void DrawRank();	//ランク描画処理

void FinRank();		//ランクの後処理