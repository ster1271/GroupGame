#include "DxLib.h"
#include "Gate.h"
#include "../Player/Player.h"

//�Q�[�g���\���̂̐錾
GateInfo gateInfo[GATE_NUM][2] = {0};

//���݂̃Q�[�g
int CurrentGate = 0;

//���ʉ��i�[�ϐ�
int SoundEffect[2] = { 0 };

void InitGate()		//�Q�[�g�̏�����
{
	//�Q�[�g����擪�����
	for (int i = 0; i < GATE_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//���_���v���X�Ȃ�
			if (gateInfo[i][j].Score >= 0)
			{
				//�΂̃Q�[�g
				gateInfo[i][j].GateHandle = LoadGraph(GATE1_PATH);
			}
			//�}�C�i�X�Ȃ�
			else
			{
				//�Ԃ̃Q�[�g
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

	//���ʉ��ǂݍ���
	SoundEffect[0] = LoadSoundMem(PLUS_SOUND);
	SoundEffect[1] = LoadSoundMem(MINUS_SOUND);

	CurrentGate = 0;
}

void StepGate()		//�Q�[�g�ʏ폈��
{
	for (int j = 0; j < 2; j++)
	{
		//���݂̃Q�[�g�̕`��t���O��true�Ȃ�
		if (gateInfo[CurrentGate][j].isDraw)
		{
			//���ɃX�N���[��
			gateInfo[CurrentGate][j].GatePosY += gateInfo[CurrentGate][j].Speed;

			//�v���C���[���擾
			PlayerInfo* playerInfo = GetPlayerInfo();
			for (int j = 0; j < 2; j++)
			{
				//�v���C���[�Ɠ���������
				if(gateInfo[CurrentGate][j].GatePosY >= playerInfo->PosY - 96.0f)
				{
					//������ʂ�����
					if (playerInfo->PosX < 642.0f)
					{
						playerInfo->Life += gateInfo[CurrentGate][0].Score;	//�����̃X�R�A�����C�t�ɉ�����

						//�Q�[�g�̓��_�����Ȃ�
						if (gateInfo[CurrentGate][0].Score >= 0)
						{
							//�v���X�̌��ʉ���炷
							PlaySoundMem(SoundEffect[0], DX_PLAYTYPE_BACK, true);
						}
						//���Ȃ�
						else
						{
							//�}�C�i�X�̌��ʉ���炷
							PlaySoundMem(SoundEffect[1], DX_PLAYTYPE_BACK, true);
						}

						//���C�t��0���傫���Ȃ�
						if (playerInfo->Life > 0)
						{
							playerInfo->Cleared++;	//�N���A����1���₷
						}
					}
					//�E����ʂ�����
					else
					{
						playerInfo->Life += gateInfo[CurrentGate][1].Score;	//�E���̃X�R�A�����C�t�ɉ�����
						
						//�Q�[�g�̓��_�����Ȃ�
						if (gateInfo[CurrentGate][1].Score >= 0)
						{
							//�v���X�̌��ʉ���炷
							PlaySoundMem(SoundEffect[0], DX_PLAYTYPE_BACK, true);
						}
						//���Ȃ�
						else
						{
							//�}�C�i�X�̌��ʉ���炷
							PlaySoundMem(SoundEffect[1], DX_PLAYTYPE_BACK, true);
						}

						//���C�t��0���傫���Ȃ�
						if (playerInfo->Life > 0)
						{
							playerInfo->Cleared++;	//�N���A����1���₷
						}
					}
					gateInfo[CurrentGate][j].GatePosY = -600.0f;		//��ʊO�Ɉړ�
					gateInfo[CurrentGate][j].isDraw = false;			//�`��t���O��܂�
					CurrentGate++;	//���̃Q�[�g�ɐi��
				}
			}
		}
	}
}

void DrawGate()		//�Q�[�g�`�揈��
{
	for (int j = 0; j < 2; j++)
	{
		//���݂̃Q�[�g�̕`��t���O��true�Ȃ�
		if (gateInfo[CurrentGate][j].isDraw)
		{
			DrawGraph((int)gateInfo[CurrentGate][j].GatePosX, (int)gateInfo[CurrentGate][j].GatePosY, gateInfo[CurrentGate][j].GateHandle, true);
			DrawFormatString((int)gateInfo[CurrentGate][j].GatePosX + 135, (int)gateInfo[CurrentGate][j].GatePosY + 64, GetColor(255, 255, 255), "%d", gateInfo[CurrentGate][j].Score);
		}
	}	
}

void FinGate()		//�Q�[�g�̌㏈��
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

void LoadGate(int Temp)		//�Q�[�g�̃e���v���ǂݍ���
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
