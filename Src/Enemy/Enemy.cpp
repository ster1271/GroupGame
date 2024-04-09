#include "DxLib.h"
#include "../Common.h"
#include "../Collision/Collision.h"
#include "Enemy.h"
#include "../Player/Player.h"
#include "../Gate/Gate.h"

//�G���\���̂̐錾
EnemyInfo enemyInfo[4] = { 0 };

//���݂̓G
int CurrentEnemy = 0;

//�t���[�����J�E���g����ϐ�
int Waiting = 0;

//���[�v���J�E���g����ϐ�
int LoopCount = 0;

//���ʉ��ϐ�
int EnemySound = 0;

void InitEnemy()	//�G�̏�����
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

	//���ʉ��ǂݍ���
	EnemySound = LoadSoundMem(ENEMY_DIE);

	CurrentEnemy = 0;
	Waiting = 0;
	LoopCount = 0;
}

void StepEnemy()	//�G�ʏ폈��
{
	//�v���C���[���擾
	PlayerInfo* playerInfo = GetPlayerInfo();

	//�ʉ߂����Q�[�g�̐���1�Ȃ�
	if (playerInfo->Cleared == 1)
	{
		//�ŏ��̓G�Ȃ�
		if (CurrentEnemy == 0)
		{
			enemyInfo[CurrentEnemy].isAlive = true;

			//�����t���O��true�Ȃ�
			if (enemyInfo[CurrentEnemy].isAlive)
			{
				//���ɃX�N���[��
				enemyInfo[CurrentEnemy].PosY += enemyInfo[CurrentEnemy].Speed;
			}

			//���̃��C���܂ŃX�N���[��������
			if (enemyInfo[CurrentEnemy].PosY >= playerInfo->PosY - 96.0f)
			{
				//�v���C���[�̃��C�t���G�̗̑͂�葽��������
				if (enemyInfo[CurrentEnemy].Life < playerInfo->Life)
				{
					playerInfo->Life -= enemyInfo[CurrentEnemy].Life;
					playerInfo->CurrentScore += enemyInfo[CurrentEnemy].Life;
					PlaySoundMem(EnemySound, DX_PLAYTYPE_BACK, true);	//���ʉ��Đ�
					enemyInfo[CurrentEnemy].isAlive = false;	//�����t���O��܂�
					enemyInfo[CurrentEnemy].isbreak = true;		//���j�t���O�𗧂Ă�
					playerInfo->BreakEnemy++;	//�G��|�������𑝂₷
					CurrentEnemy++;		//���̓G��
				}
				else
				{
					playerInfo->Life = 0;
				}
			}
		}
	}

	//�ʉ߂����Q�[�g�̐���3�Ȃ�
	else if (playerInfo->Cleared == 3)
	{
		//2�Ԗڂ̓G�Ȃ�
		if (CurrentEnemy == 1)
		{
			enemyInfo[CurrentEnemy].isAlive = true;

			//�����t���O��true�Ȃ�
			if (enemyInfo[CurrentEnemy].isAlive)
			{
				//���ɃX�N���[��
				enemyInfo[CurrentEnemy].PosY += enemyInfo[CurrentEnemy].Speed;
			}

			//���̃��C���܂ŃX�N���[��������
			if (enemyInfo[CurrentEnemy].PosY >= playerInfo->PosY - 96.0f)
			{
				//�v���C���[�̃��C�t���G�̗̑͂�葽��������
				if (enemyInfo[CurrentEnemy].Life < playerInfo->Life)
				{
					playerInfo->Life -= enemyInfo[CurrentEnemy].Life;
					playerInfo->CurrentScore += enemyInfo[CurrentEnemy].Life;
					PlaySoundMem(EnemySound, DX_PLAYTYPE_BACK, true);	//���ʉ��Đ�
					enemyInfo[CurrentEnemy].isAlive = false;	//�����t���O��܂�
					enemyInfo[CurrentEnemy].isbreak = true;		//���j�t���O�𗧂Ă�
					playerInfo->BreakEnemy++;	//�G��|�������𑝂₷
					CurrentEnemy++;		//���̓G��
				}
				else
				{
					playerInfo->Life = 0;
				}
			}
		}
	}

	//�ʉ߂����Q�[�g�̐���5�Ȃ�
	else if (playerInfo->Cleared == 5)
	{
		//3�Ԗڂ̓G�Ȃ�
		if (CurrentEnemy == 2)
		{
			enemyInfo[CurrentEnemy].isAlive = true;

			//�����t���O��true�Ȃ�
			if (enemyInfo[CurrentEnemy].isAlive)
			{
				//���ɃX�N���[��
				enemyInfo[CurrentEnemy].PosY += enemyInfo[CurrentEnemy].Speed;
			}

			//���̃��C���܂ŃX�N���[��������
			if (enemyInfo[CurrentEnemy].PosY >= playerInfo->PosY - 96.0f)
			{
				//�v���C���[�̃��C�t���G�̗̑͂�葽��������
				if (enemyInfo[CurrentEnemy].Life < playerInfo->Life)
				{
					playerInfo->Life -= enemyInfo[CurrentEnemy].Life;
					playerInfo->CurrentScore += enemyInfo[CurrentEnemy].Life;
					PlaySoundMem(EnemySound, DX_PLAYTYPE_BACK, true);	//���ʉ��Đ�
					enemyInfo[CurrentEnemy].isAlive = false;	//�����t���O��܂�
					enemyInfo[CurrentEnemy].isbreak = true;		//���j�t���O�𗧂Ă�
					playerInfo->BreakEnemy++;	//�G��|�������𑝂₷
					CurrentEnemy++;		//���̓G��
				}
				else
				{
					playerInfo->Life = 0;
				}
			}
		}
	}

	//�ʉ߂����Q�[�g�̐���6�Ȃ�
	else if (playerInfo->Cleared == 6)
	{
		//�{�X�Ȃ�
		if (CurrentEnemy == 3)
		{
			enemyInfo[CurrentEnemy].isAlive = true;

			//�����t���O��true�Ȃ�
			if (enemyInfo[CurrentEnemy].isAlive)
			{
				//���ɃX�N���[��
				enemyInfo[CurrentEnemy].PosY += enemyInfo[CurrentEnemy].Speed;
			}

			//���̃��C���܂ŃX�N���[��������
			if (enemyInfo[CurrentEnemy].PosY >= playerInfo->PosY - 96.0f)
			{
				//�v���C���[�̃��C�t���G�̗̑͂�葽��������
				if (enemyInfo[CurrentEnemy].Life < playerInfo->Life)
				{
					playerInfo->Life -= enemyInfo[CurrentEnemy].Life;
					playerInfo->CurrentScore += enemyInfo[CurrentEnemy].Life;
					PlaySoundMem(EnemySound, DX_PLAYTYPE_BACK, true);	//���ʉ��Đ�
					enemyInfo[CurrentEnemy].isAlive = false;	//�����t���O��܂�
					enemyInfo[CurrentEnemy].isbreak = true;		//���j�t���O�𗧂Ă�
					playerInfo->BreakEnemy++;	//�G��|�������𑝂₷
					CurrentEnemy++;		//���̓G��
				}
				else
				{
					playerInfo->Life = 0;
				}
			}
		}
	}

	//�{�X��|������
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
			//�����N�\���ɐi��
			playerInfo->isRank = true;
		}
	}
}

void DrawEnemy()	//�G�`�揈��
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//�����t���O��true�Ȃ�
		if (enemyInfo[i].isAlive)
		{
			DrawRotaGraph((int)enemyInfo[i].PosX, (int)enemyInfo[i].PosY, 1.0f, 0.0f, enemyInfo[i].Enemyhandle, true);
			DrawFormatString((int)enemyInfo[i].PosX - 15, (int)enemyInfo[i].PosY, GetColor(255, 255, 255), "%d", enemyInfo[i].Life);
		}
	}
}

void FinEnemy()		//�G�̌㏈��
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		DeleteGraph(enemyInfo[i].Enemyhandle);
		DeleteSoundMem(EnemySound);
	}
}

void SetLife(int temp)		//�̗͐ݒ�
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
