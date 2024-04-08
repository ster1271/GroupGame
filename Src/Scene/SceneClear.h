#pragma once

//画像パス
//背景
<<<<<<< Updated upstream
#define CLEAR_BUCKGROUND_PATH	"Data/ClearImage/Game Clear.png"
#define SELECT_PATH				"Data/ClearImage/Select.png"
#define BG_STER_PATH			"Data/ClearImage/Score_Ster.png"
#define STER_PATH				"Data/ClearImage/Score_ColorSter.png"
=======
#define CLEAR_BUCKGROUND_PATH	"Data/ClearImage/GameClear_BackGround.png"
#define CLEAR_BGM_PATH		("Data/Sounds/Music/Clear/GameClear.mp3")	//クリア画面BGMのパス
>>>>>>> Stashed changes

//クリア初期化
void InitClear();

//クリア通常処理
void StepClear();

//クリア描画処理
void DrawClear();

//クリア後処理
void FinClear();