#pragma once

//画像パス
//背景
#define CLEAR_BUCKGROUND_PATH	"Data/ClearImage/GameClear_BuckGround.png"

//クリア初期化
void InitClear();

//クリア通常処理
void StepClear();

//クリア描画処理
void DrawClear();

//クリア後処理
void FinClear();