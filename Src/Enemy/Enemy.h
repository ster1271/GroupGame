#pragma once

#define ENEMY_PATH	("Data/PlayImage/Enemy/Enemy.png")	//敵の画像のパス
#define BOSS_PATH	("Data/Playimage/Enemy/Boss.png")	//ボスの画像のパス
#define ENEMY_NUM	(4)		//敵の数
#define ENEMY_DIE	("Data/Sounds/SE/Play/EnemyDie.wav")	//敵を倒した時の音のパス

struct EnemyInfo
{
	int Enemyhandle;	//画像ハンドル
	float PosX, PosY;	//X座標	
	float Speed;		//スクロール速度
	bool isAlive;		//生存フラグ
	int Life;			//体力
	bool isbreak;		//撃破フラグ
};

void InitEnemy();			//敵の初期化

void StepEnemy();			//敵通常処理

void DrawEnemy();			//敵描画処理

void FinEnemy();			//敵の後処理

void SetLife(int temp);		//体力設定
