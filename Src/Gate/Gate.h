#pragma once

#define GATE_NUM	(6)	//くぐるゲートの数
#define TEMP_NUM	(4)	//テンプレの数
#define GATE1_PATH		("Data/PlayImage/Gate/Gate1_1_1.png")	//プラスゲートの画像のパス
#define GATE2_PATH		("Data/PlayImage/Gate/Gate1_1_2.png")	//マイナスゲートの画像のパス
#define PLUS_SOUND		("Data/Sounds/SE/Play/Plus.wav")		//プラス効果音のパス
#define MINUS_SOUND		("Data/Sounds/SE/Play/Minus.wav")		//マイナス効果音のパス

//ゲート情報構造体
struct GateInfo
{
	int GateHandle;				//画像ハンドル
	float GatePosX, GatePosY;	//X座標,Y座標
	float Radius;				//半径
	bool isDraw;				//描画フラグ
	float Speed;				//スクロール速度
	int Score;					//ゲートの得点
	int CurrentGate;			//現在のゲート
};

void InitGate();	//ゲートの初期化

void StepGate();	//ゲート通常処理

void DrawGate();	//ゲート描画処理

void FinGate();		//ゲートの後処理

void LoadGate(int Temp);		//ゲートのテンプレ読み込み
