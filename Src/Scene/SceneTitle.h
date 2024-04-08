#pragma once

#define BG_TITLE_PATH	("Data/TitleImage/BgTitle.png")		//タイトル背景画像のパス
#define SELECT_PATH		("Data/ClearImage/Select.png")		//矢印画像パス

//タイトル初期化
void InitTitle();

//タイトル通常処理
void StepTitle();

//タイトル描画処理
void DrawTitle();

//タイトル後処理
void FinTitle();
