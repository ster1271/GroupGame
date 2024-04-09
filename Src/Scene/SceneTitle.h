#pragma once

#define BG_TITLE_PATH	("Data/TitleImage/BgTitle.png")		//タイトル背景画像のパス
#define TITLE_PATH		("Data/TitleImage/title.png")		//タイトル画像パス
#define TITLE_BGM_PATH	("Data/Sounds/Music/Title/Title.mp3")	//タイトルBGMのパス

//タイトル初期化
void InitTitle();

//タイトル通常処理
void StepTitle();

//タイトル描画処理
void DrawTitle();

//タイトル後処理
void FinTitle();
