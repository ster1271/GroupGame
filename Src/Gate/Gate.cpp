#include "DxLib.h"
#include "Gate.h"
#include "../Player/Player.h"

//ゲート情報構造体の宣言
GateInfo gateInfo[GATE_NUM][2] = {0};

//現在のゲート
int CurrentGate = 0;

//効果音格納変数
int SoundEffect[2] = { 0 };

void InitGate()		//ゲートの初期化
{
	//ゲート情報を先頭から回す
	for (int i = 0; i < GATE_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//得点がプラスなら
			if (gateInfo[i][j].Score >= 0)
			{
				//緑のゲート
				gateInfo[i][j].GateHandle = LoadGraph(GATE1_PATH);
			}
			//マイナスなら
			else
			{
				//赤のゲート
				gateInfo[i][j].GateHandle = LoadGraph(GATE2_PATH);
			}
			gateInfo[i][0].GatePosX = 357.0f;
			gateInfo[i][1].GatePosX = 627.0f;
			gateInfo[i][j].GatePosY = -600.0f;
			gateInfo[i][j].Radius = 64.0f;
			gateInfo[i][j].isDraw = true;
			gateInfo[i][j].Speed = 3.0f;
			gateInfo[i][j].CurrentGate = 0;
		}
	}

	//効果音読み込み
	SoundEffect[0] = LoadSoundMem(PLUS_SOUND);
	SoundEffect[1] = LoadSoundMem(MINUS_SOUND);

	CurrentGate = 0;
}

void StepGate()		//ゲート通常処理
{
	for (int j = 0; j < 2; j++)
	{
		//現在のゲートの描画フラグがtrueなら
		if (gateInfo[CurrentGate][j].isDraw)
		{
			//下にスクロール
			gateInfo[CurrentGate][j].GatePosY += gateInfo[CurrentGate][j].Speed;

			//プレイヤー情報取得
			PlayerInfo* playerInfo = GetPlayerInfo();
			for (int j = 0; j < 2; j++)
			{
				//プレイヤーと当たったら
				if(gateInfo[CurrentGate][j].GatePosY >= playerInfo->PosY - 96.0f)
				{
					//左側を通ったら
					if (playerInfo->PosX < 642.0f)
					{
						playerInfo->Life += gateInfo[CurrentGate][0].Score;	//左側のスコアをライフに加える

						//ゲートの得点が正なら
						if (gateInfo[CurrentGate][0].Score >= 0)
						{
							//プラスの効果音を鳴らす
							PlaySoundMem(SoundEffect[0], DX_PLAYTYPE_BACK, true);
						}
						//負なら
						else
						{
							//マイナスの効果音を鳴らす
							PlaySoundMem(SoundEffect[1], DX_PLAYTYPE_BACK, true);
						}

						//ライフが0より大きいなら
						if (playerInfo->Life > 0)
						{
							playerInfo->Cleared++;	//クリア数を1増やす
						}
					}
					//右側を通ったら
					else
					{
						playerInfo->Life += gateInfo[CurrentGate][1].Score;	//右側のスコアをライフに加える
						
						//ゲートの得点が正なら
						if (gateInfo[CurrentGate][1].Score >= 0)
						{
							//プラスの効果音を鳴らす
							PlaySoundMem(SoundEffect[0], DX_PLAYTYPE_BACK, true);
						}
						//負なら
						else
						{
							//マイナスの効果音を鳴らす
							PlaySoundMem(SoundEffect[1], DX_PLAYTYPE_BACK, true);
						}

						//ライフが0より大きいなら
						if (playerInfo->Life > 0)
						{
							playerInfo->Cleared++;	//クリア数を1増やす
						}
					}
					gateInfo[CurrentGate][j].GatePosY = -600.0f;		//画面外に移動
					gateInfo[CurrentGate][j].isDraw = false;			//描画フラグを折る
					CurrentGate++;	//次のゲートに進む
				}
			}
		}
	}
}

void DrawGate()		//ゲート描画処理
{
	for (int j = 0; j < 2; j++)
	{
		//現在のゲートの描画フラグがtrueなら
		if (gateInfo[CurrentGate][j].isDraw)
		{
			DrawGraph((int)gateInfo[CurrentGate][j].GatePosX, (int)gateInfo[CurrentGate][j].GatePosY, gateInfo[CurrentGate][j].GateHandle, true);
			DrawFormatString((int)gateInfo[CurrentGate][j].GatePosX + 135, (int)gateInfo[CurrentGate][j].GatePosY + 64, GetColor(255, 255, 255), "%d", gateInfo[CurrentGate][j].Score);
		}
	}	
}

void FinGate()		//ゲートの後処理
{
	for (int i = 0; i < GATE_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			DeleteGraph(gateInfo[i][j].GateHandle);
			DeleteSoundMem(SoundEffect[j]);
		}
	}
}

void LoadGate(int Temp)		//ゲートのテンプレ読み込み
{
	switch (Temp)
	{
		case 0:
		{
			gateInfo[0][0].Score = 50;
			gateInfo[0][1].Score = 40;

			gateInfo[1][0].Score = 100;
			gateInfo[1][1].Score = -50;

			gateInfo[2][0].Score = -124;
			gateInfo[2][1].Score = 203;

			gateInfo[3][0].Score = 387;
			gateInfo[3][1].Score = 426;

			gateInfo[4][0].Score = -200;
			gateInfo[4][1].Score = 368;

			gateInfo[5][0].Score = 479;
			gateInfo[5][1].Score = 441;
		}
		break;

		case 1:
		{
			gateInfo[0][0].Score = 48;
			gateInfo[0][1].Score = 69;

			gateInfo[1][0].Score = 141;
			gateInfo[1][1].Score = -74;

			gateInfo[2][0].Score = 228;
			gateInfo[2][1].Score = -105;

			gateInfo[3][0].Score = -265;
			gateInfo[3][1].Score = 304;

			gateInfo[4][0].Score = 385;
			gateInfo[4][1].Score = 402;

			gateInfo[5][0].Score = -482;
			gateInfo[5][1].Score = 492;
		}
		break;

		case 2:
		{
			gateInfo[0][0].Score = 81;
			gateInfo[0][1].Score = 82;

			gateInfo[1][0].Score = 312;
			gateInfo[1][1].Score = 213;

			gateInfo[2][0].Score = 362;
			gateInfo[2][1].Score = -138;

			gateInfo[3][0].Score = -30;
			gateInfo[3][1].Score = -25;

			gateInfo[4][0].Score = 454;
			gateInfo[4][1].Score = 545;

			gateInfo[5][0].Score = -434;
			gateInfo[5][1].Score = 496;
		}
		break;

		case 3:
		{
			gateInfo[0][0].Score = 101;
			gateInfo[0][1].Score = 110;

			gateInfo[1][0].Score = 197;
			gateInfo[1][1].Score = 198;

			gateInfo[2][0].Score = 225;
			gateInfo[2][1].Score = 252;

			gateInfo[3][0].Score = -69;
			gateInfo[3][1].Score = -96;

			gateInfo[4][0].Score = 496;
			gateInfo[4][1].Score = 469;

			gateInfo[5][0].Score = 535;
			gateInfo[5][1].Score = 353;
		}
		break;

		case 4:
		{
			gateInfo[0][0].Score = 11;
			gateInfo[0][1].Score = 111;

			gateInfo[1][0].Score = -47;
			gateInfo[1][1].Score = -47;

			gateInfo[2][0].Score = 381;
			gateInfo[2][1].Score = 138;

			gateInfo[3][0].Score = 291;
			gateInfo[3][1].Score = 192;

			gateInfo[4][0].Score = 346;
			gateInfo[4][1].Score = 364;

			gateInfo[5][0].Score = 445;
			gateInfo[5][1].Score = 354;
		}
		break;
	}
}
