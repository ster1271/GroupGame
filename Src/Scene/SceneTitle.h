#pragma once

#define BG_TITLE_PATH	("Data/TitleImage/BgTitle.png")		//タイトル背景画像のパス
#define TITLE_TEXT_PATH	("Data/TitleImage/TitleText.png")	//タイトル文字画像のパス
#define START_TEXT_PATH	("Data/TitleImage/PressEnter.png")	//スタート文字画像のパス

//タイトル初期化
void InitTitle();

//タイトル通常処理
void StepTitle();

//タイトル描画処理
void DrawTitle();

//タイトル後処理
void FinTitle();
