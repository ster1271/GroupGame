#pragma once

//画像パス
//背景
#define CLEAR_BUCKGROUND_PATH	"Data/ClearImage/Game Clear.png"
#define SELECT_PATH				"Data/ClearImage/Select.png"
#define BG_STER_PATH			"Data/ClearImage/Score_Ster.png"
#define STER_PATH				"Data/ClearImage/Score_ColorSter.png"

//クリア初期化
void InitClear();

//クリア通常処理
void StepClear();

//クリア描画処理
void DrawClear();

//クリア後処理
void FinClear();