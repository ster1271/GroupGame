//2309430 宮近一星

#pragma once

#define BG_GAMEOVER_PATH	("Data/GameOverImage/Game Over.png")	//ゲームオーバー背景画像
#define	SELECT_PATH			("Data/GameOverImage/Select.png")		//矢印画像

//ゲームオーバー初期化
void InitGameOver();

//ゲームオーバー通常処理
void StepGameOver();

//ゲームオーバー描画処理
void DrawGameOver();

//ゲームオーバー後処理
void FinGameOver();
