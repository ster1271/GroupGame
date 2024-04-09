#include "DxLib.h"
#include "../Common.h"
#include "../Collision/Collision.h"
#include "Enemy.h"
#include "../Player/Player.h"
#include "../Gate/Gate.h"

//敵情報構造体の宣言
EnemyInfo enemyInfo[4] = { 0 };

//現在の敵
int CurrentEnemy = 0;

//フレームをカウントする変数
int Waiting = 0;

//ループをカウントする変数
int LoopCount = 0;

//効果音変数
int EnemySound = 0;

void InitEnemy()	//敵の初期化
{
	for (int i = 0; i < 3; i++)
	{
		enemyInfo[i].Enemyhandle = LoadGraph(ENEMY_PATH);
	}
	enemyInfo[3].Enemyhandle = LoadGraph(BOSS_PATH);

	for (int j = 0; j < ENEMY_NUM; j++)
	{
		enemyInfo[j].PosX = 640.0f;
		enemyInfo[j].PosY = -200.0f;
		enemyInfo[j].Speed = 3.0f;
		enemyInfo[j].isAlive = false;
		enemyInfo[j].isbreak = false;
	}

	//効果音読み込み
	EnemySound = LoadSoundMem(ENEMY_DIE);

	CurrentEnemy = 0;
	Waiting = 0;
	LoopCount = 0;
}

void StepEnemy()	//敵通常処理
{
	//プレイヤー情報取得
	PlayerInfo* playerInfo = GetPlayerInfo();

	//通過したゲートの数が1つなら
	if (playerInfo->Cleared == 1)
	{
		//最初の敵なら
		if (CurrentEnemy == 0)
		{
			enemyInfo[CurrentEnemy].isAlive = true;

			//生存フラグがtrueなら
			if (enemyInfo[CurrentEnemy].isAlive)
			{
				//下にスクロール
				enemyInfo[CurrentEnemy].PosY += enemyInfo[CurrentEnemy].Speed;
			}

			//一定のラインまでスクロールしたら
			if (enemyInfo[CurrentEnemy].PosY >= playerInfo->PosY - 96.0f)
			{
				//プレイヤーのライフが敵の体力より多かったら
				if (enemyInfo[CurrentEnemy].Life < playerInfo->Life)
				{
					playerInfo->Life -= enemyInfo[CurrentEnemy].Life;
					playerInfo->CurrentScore += enemyInfo[CurrentEnemy].Life;
					PlaySoundMem(EnemySound, DX_PLAYTYPE_BACK, true);	//効果音再生
					enemyInfo[CurrentEnemy].isAlive = false;	//生存フラグを折る
					enemyInfo[CurrentEnemy].isbreak = true;		//撃破フラグを立てる
					playerInfo->BreakEnemy++;	//敵を倒した数を増やす
					CurrentEnemy++;		//次の敵に
				}
				else
				{
					playerInfo->Life = 0;
				}
			}
		}
	}

	//通過したゲートの数が3つなら
	else if (playerInfo->Cleared == 3)
	{
		//2番目の敵なら
		if (CurrentEnemy == 1)
		{
			enemyInfo[CurrentEnemy].isAlive = true;

			//生存フラグがtrueなら
			if (enemyInfo[CurrentEnemy].isAlive)
			{
				//下にスクロール
				enemyInfo[CurrentEnemy].PosY += enemyInfo[CurrentEnemy].Speed;
			}

			//一定のラインまでスクロールしたら
			if (enemyInfo[CurrentEnemy].PosY >= playerInfo->PosY - 96.0f)
			{
				//プレイヤーのライフが敵の体力より多かったら
				if (enemyInfo[CurrentEnemy].Life < playerInfo->Life)
				{
					playerInfo->Life -= enemyInfo[CurrentEnemy].Life;
					playerInfo->CurrentScore += enemyInfo[CurrentEnemy].Life;
					PlaySoundMem(EnemySound, DX_PLAYTYPE_BACK, true);	//効果音再生
					enemyInfo[CurrentEnemy].isAlive = false;	//生存フラグを折る
					enemyInfo[CurrentEnemy].isbreak = true;		//撃破フラグを立てる
					playerInfo->BreakEnemy++;	//敵を倒した数を増やす
					CurrentEnemy++;		//次の敵に
				}
				else
				{
					playerInfo->Life = 0;
				}
			}
		}
	}

	//通過したゲートの数が5つなら
	else if (playerInfo->Cleared == 5)
	{
		//3番目の敵なら
		if (CurrentEnemy == 2)
		{
			enemyInfo[CurrentEnemy].isAlive = true;

			//生存フラグがtrueなら
			if (enemyInfo[CurrentEnemy].isAlive)
			{
				//下にスクロール
				enemyInfo[CurrentEnemy].PosY += enemyInfo[CurrentEnemy].Speed;
			}

			//一定のラインまでスクロールしたら
			if (enemyInfo[CurrentEnemy].PosY >= playerInfo->PosY - 96.0f)
			{
				//プレイヤーのライフが敵の体力より多かったら
				if (enemyInfo[CurrentEnemy].Life < playerInfo->Life)
				{
					playerInfo->Life -= enemyInfo[CurrentEnemy].Life;
					playerInfo->CurrentScore += enemyInfo[CurrentEnemy].Life;
					PlaySoundMem(EnemySound, DX_PLAYTYPE_BACK, true);	//効果音再生
					enemyInfo[CurrentEnemy].isAlive = false;	//生存フラグを折る
					enemyInfo[CurrentEnemy].isbreak = true;		//撃破フラグを立てる
					playerInfo->BreakEnemy++;	//敵を倒した数を増やす
					CurrentEnemy++;		//次の敵に
				}
				else
				{
					playerInfo->Life = 0;
				}
			}
		}
	}

	//通過したゲートの数が6つなら
	else if (playerInfo->Cleared == 6)
	{
		//ボスなら
		if (CurrentEnemy == 3)
		{
			enemyInfo[CurrentEnemy].isAlive = true;

			//生存フラグがtrueなら
			if (enemyInfo[CurrentEnemy].isAlive)
			{
				//下にスクロール
				enemyInfo[CurrentEnemy].PosY += enemyInfo[CurrentEnemy].Speed;
			}

			//一定のラインまでスクロールしたら
			if (enemyInfo[CurrentEnemy].PosY >= playerInfo->PosY - 96.0f)
			{
				//プレイヤーのライフが敵の体力より多かったら
				if (enemyInfo[CurrentEnemy].Life < playerInfo->Life)
				{
					playerInfo->Life -= enemyInfo[CurrentEnemy].Life;
					playerInfo->CurrentScore += enemyInfo[CurrentEnemy].Life;
					PlaySoundMem(EnemySound, DX_PLAYTYPE_BACK, true);	//効果音再生
					enemyInfo[CurrentEnemy].isAlive = false;	//生存フラグを折る
					enemyInfo[CurrentEnemy].isbreak = true;		//撃破フラグを立てる
					playerInfo->BreakEnemy++;	//敵を倒した数を増やす
					CurrentEnemy++;		//次の敵に
				}
				else
				{
					playerInfo->Life = 0;
				}
			}
		}
	}

	//ボスを倒したら
	if (enemyInfo[3].isbreak)
	{
		if (LoopCount < 5)
		{
			Waiting++;
			if (Waiting > FRAME_RATE / 2)
			{
				LoopCount++;
				Waiting = 0;
			}
		}
		else
		{
			//ランク表示に進む
			playerInfo->isRank = true;
		}
	}
}

void DrawEnemy()	//敵描画処理
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//生存フラグがtrueなら
		if (enemyInfo[i].isAlive)
		{
			DrawRotaGraph((int)enemyInfo[i].PosX, (int)enemyInfo[i].PosY, 1.0f, 0.0f, enemyInfo[i].Enemyhandle, true);
			DrawFormatString((int)enemyInfo[i].PosX - 15, (int)enemyInfo[i].PosY, GetColor(255, 255, 255), "%d", enemyInfo[i].Life);
		}
	}
}

void FinEnemy()		//敵の後処理
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		DeleteGraph(enemyInfo[i].Enemyhandle);
		DeleteSoundMem(EnemySound);
	}
}

void SetLife(int temp)		//体力設定
{
	switch (temp)
	{
		case 0:
		{
			enemyInfo[0].Life = 40;
			enemyInfo[1].Life = 123;
			enemyInfo[2].Life = 508;
			enemyInfo[3].Life = 893;
		}
		break;

		case 1:
		{
			enemyInfo[0].Life = 37;
			enemyInfo[1].Life = 134;
			enemyInfo[2].Life = 479;
			enemyInfo[3].Life = 912;
		}
		break;

		case 2:
		{
			enemyInfo[0].Life = 71;
			enemyInfo[1].Life = 269;
			enemyInfo[2].Life = 514;
			enemyInfo[3].Life = 834;
		}
		break;

		case 3:
		{
			enemyInfo[0].Life = 83;
			enemyInfo[1].Life = 176;
			enemyInfo[2].Life = 281;
			enemyInfo[3].Life = 927;
		}
		break;

		case 4:
		{
			enemyInfo[0].Life = 64;
			enemyInfo[1].Life = 182;
			enemyInfo[2].Life = 269;
			enemyInfo[3].Life = 935;
		}
		break;
	}
}
