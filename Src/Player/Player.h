#pragma once

//プレイヤー画像の種類
enum PLAYER_IMAGE
{
	PLAYER_1 = 0,	//runBoy1
	PLAYER_2,		//runBoy2
	PLAYER_3,		//runBoy3
	PLAYER_4,		//runBoy4
	PLAYER_5,		//runBoy5
	PLAYER_6,		//runBoy6
	PLAYER_7,		//runBoy7
	PLAYER_8,		//runBoy8
	PLAYER_9,		//runBoy9
	PLAYER_10,		//runBoy10

	PLAYER_NUM,
};

//プレイヤー画像のパス
const char PlayerImage_Path[PLAYER_NUM][100] =
{
	"Data/PlayImage/runBoy/runBoy1.png",	//runBoy1
	"Data/PlayImage/runBoy/runBoy2.png",	//runBoy2
	"Data/PlayImage/runBoy/runBoy3.png",	//runBoy3
	"Data/PlayImage/runBoy/runBoy4.png",	//runBoy4
	"Data/PlayImage/runBoy/runBoy5.png",	//runBoy5
	"Data/PlayImage/runBoy/runBoy6.png",	//runBoy6
	"Data/PlayImage/runBoy/runBoy7.png",	//runBoy7
	"Data/PlayImage/runBoy/runBoy8.png",	//runBoy8
	"Data/PlayImage/runBoy/runBoy9.png",	//runBoy9
	"Data/PlayImage/runBoy/runBoy10.png",	//runBoy10
};

//プレイヤー情報構造体
struct PlayerInfo
{
	int PlayerHandle[PLAYER_NUM];	//画像ハンドル
	int HandleIndex;				//画像ハンドルの添え字用変数
	int AnimeFrame;					//画像の再生時間
	bool isReverse;					//アニメーションの逆再生フラグ
	float PosX, PosY;				//X座標,Y座標
	float Radius;					//半径
	float MoveSpeed;				//移動速度
	int CurrentScore;				//獲得スコア
	int Life;						//ライフ
	bool isAlive;					//生存フラグ
	int Cleared;					//通過したゲートの数
	int BreakEnemy;					//倒した敵の数
	bool isRank;					//ランク表示に進むフラグ
	bool isClear;					//クリアフラグ
};

void InitPlayer();	//プレイヤーの初期化

void StepPlayer();	//プレイヤー通常処理

void DrawPlayer();	//プレイヤー描画処理

void FinPlayer();	//プレイヤーの後処理

void LoadPlayer(PLAYER_IMAGE type);		//プレイヤー画像の読み込み

void MovePlayer();	//プレイヤーの移動処理

void ChangePlayerImage();	//プレイヤーの画像を変える

PlayerInfo* GetPlayerInfo();	//プレイヤー情報取得
