#include "DxLib.h"
#include "../Input/Input.h"
#include "../Player/Player.h"
#include "Score.h"

//�����N���\���̂̐錾
RankInfo rankInfo[STAR_NUM][2] = {0};

//�{�[�i�X�X�R�A
int Bonus = 0;

//�����X�R�A
int Result = 0;

//���ʉ�
int Result_SE = 0;

void InitRank()		//�����N�̏�����
{
	for (int i = 0; i < STAR_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			rankInfo[i][0].StarHandle = LoadGraph(STAR_PATH);	//��
			rankInfo[i][1].StarHandle = LoadGraph(STAR2_PATH);	//�D�F�́�
			rankInfo[i][j].PosX = 400.0f;
			rankInfo[i][j].PosY = 480.0f;
			rankInfo[i][j].isDraw = false;
			rankInfo[i][j].Result = 0;
		}
	}

	//���ʉ��ǂݍ���
	Result_SE = LoadSoundMem(RESULT_SE);

	Bonus = 0;

	Result = 0;
}

void StepRank()		//�����N�ʏ폈��
{
	//�v���C���[���擾
	PlayerInfo* playerInfo = GetPlayerInfo();

	Bonus = playerInfo->Life * 10;

	Result = playerInfo->CurrentScore + Bonus;

	playerInfo->Result = Result;

	for (int i = 0; i < STAR_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			rankInfo[i][j].Result = Result;
		}
	}
	//�����N�\���t���O��true�Ȃ�
	if (playerInfo->isRank)
	{
		//�X�R�A��1000�_�ȉ��Ȃ�
		if (Result <= 1000)
		{
			//��1��
			rankInfo[0][0].isDraw = true;
			rankInfo[1][1].isDraw = true;
			rankInfo[2][1].isDraw = true;
		}

		//�X�R�A��1001�_�ȏ�2000�_�ȉ��Ȃ�
		else if (Result >= 1001 && Result <= 2000)
		{
			//��2��
			rankInfo[0][0].isDraw = true;
			rankInfo[1][0].isDraw = true;
			rankInfo[2][1].isDraw = true;
		}

		//�X�R�A��2001�_�ȏ�Ȃ�
		else if (Result >= 2001)
		{
			//��3��
			rankInfo[0][0].isDraw = true;
			rankInfo[1][0].isDraw = true;
			rankInfo[2][0].isDraw = true;
		}

		//�G���^�[�L�[�������ꂽ��
		if (IsKeyPush(KEY_INPUT_RETURN))
		{
			//�N���A�t���O�𗧂Ă�
			playerInfo->isClear = true;
		}

		//���ʉ��Đ�
		PlaySoundMem(Result_SE, DX_PLAYTYPE_BACK, true);
	}
}

void DrawRank()		//�����N�`�揈��
{
	//�v���C���[���擾
	PlayerInfo* playerInfo = GetPlayerInfo();

	for (int i = 0; i < STAR_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//�`��t���O��true�Ȃ�
			if (rankInfo[i][j].isDraw)
			{
				DrawFormatString(550, 150, GetColor(0, 0, 0), "Score  :%d", playerInfo->CurrentScore);
				DrawFormatString(550, 180, GetColor(0, 0, 0), "Bonus  :%d * 10 = %d", playerInfo->Life, Bonus);
				DrawFormatString(550, 210, GetColor(0, 0, 0), "Result :%d + %d = %d", playerInfo->CurrentScore, Bonus, Result);
				DrawFormatString(575, 300, GetColor(0, 0, 0), "Press Enter Key");
			}
		}
	}
}

void FinRank()		//�����N�̌㏈��
{
	for (int i = 0; i < STAR_NUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			DeleteGraph(rankInfo[i][j].StarHandle);
		}
	}

	//���ʉ��j��
	DeleteSoundMem(Result_SE);
}