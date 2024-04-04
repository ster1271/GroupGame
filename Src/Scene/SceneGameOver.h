//2309430 宮近一星

#pragma once

#define BG_GAMEOVER_PATH	("Data/GameOverImage/GameOverBG.png")	//ゲームオーバー背景画像
#define GAMEOVER_PATH		("Data/GameOverImage/GameOver.png")		//ゲームオーバー文字画像
#define CONTINUE_PATH		("Data/GameOverImage/Continue.png")		//コンティニュー文字画像
#define	BACKTITLE_PATH		("Data/GameOverImage/BackTitle.png")	//タイトルに戻る文字画像
#define	SELECT_PATH			("Data/GameOverImage/Select.png")		//矢印画像

//ゲームオーバー初期化
void InitGameOver();

//ゲームオーバー通常処理
void StepGameOver();

//ゲームオーバー描画処理
void DrawGameOver();

//ゲームオーバー後処理
void FinGameOver();
