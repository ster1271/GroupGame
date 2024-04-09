#include "DxLib.h"
#include "../Common.h"
#include "../Input/Input.h"
#include "Player.h"

//�v���C���[���\���̂̐錾
PlayerInfo playerInfo = { 0 };

void InitPlayer()	//�v���C���[�̏�����
{
	//�摜�̓ǂݍ���
	LoadPlayer(PLAYER_1);	//runBoy1
	LoadPlayer(PLAYER_2);	//runBoy2
	LoadPlayer(PLAYER_3);	//runBoy3
	LoadPlayer(PLAYER_4);	//runBoy4
	LoadPlayer(PLAYER_5);	//runBoy5
	LoadPlayer(PLAYER_6);	//runBoy6
	LoadPlayer(PLAYER_7);	//runBoy7
	LoadPlayer(PLAYER_8);	//runBoy8
	LoadPlayer(PLAYER_9);	//runBoy9
	LoadPlayer(PLAYER_10);	//runBoy10
	playerInfo.PosX = 640.0f;			//����X���W��ݒ�
	playerInfo.PosY = 550.0f;			//����Y���W��ݒ�
	playerInfo.Radius = 32.0f;			//���a��ݒ�
	playerInfo.MoveSpeed = 4.0f;		//�����ړ����x��ݒ�
	playerInfo.CurrentScore = 0;		//�X�R�A�����Z�b�g
	playerInfo.Life = 1;				//�������C�t��ݒ�
	playerInfo.isAlive = true;			//�����t���O�𗧂Ă�
	playerInfo.Cleared = 0;				//�N���A�������Z�b�g
	playerInfo.BreakEnemy = 0;			//�|�����G�̐������Z�b�g
	playerInfo.isRank = false;			//�����N�\���͂��Ȃ�
	playerInfo.isClear = false;			//�N���A�t���O��܂�
	playerInfo.Result = 0;
}

void StepPlayer()	//�v���C���[�ʏ폈��
{
	MovePlayer();	//�v���C���[�̈ړ�����

	ChangePlayerImage();	//	�v���C���[�̉摜��ς���
}

void DrawPlayer()	//�v���C���[�`�揈��
{
	if (playerInfo.isAlive)
	{
		DrawRotaGraph((int)playerInfo.PosX, (int)playerInfo.PosY, 1.0f, 0.0f, playerInfo.PlayerHandle[playerInfo.HandleIndex], true);
		DrawFormatString((int)playerInfo.PosX - 10, (int)playerInfo.PosY, GetColor(0, 0, 0), "%d", playerInfo.Life);		//���C�t�̕`��
	}
	DrawFormatString(50, 240, GetColor(255, 255, 255), "Score:%d", playerInfo.CurrentScore);	//�X�R�A�̕`��
}

void FinPlayer()	//�v���C���[�̌㏈��
{
	//�摜��j��
	DeleteGraph(playerInfo.PlayerHandle[0]);
}

void LoadPlayer(PLAYER_IMAGE type)	//�v���C���[�摜�̓ǂݍ���
{
	playerInfo.PlayerHandle[type] = LoadGraph(PlayerImage_Path[type]);
}

void MovePlayer()	//�v���C���[�̈ړ�����
{
	//D�L�[�܂��͉E���L�[�������Ă����
	if (IsKeyKeep(KEY_INPUT_D) || IsKeyKeep(KEY_INPUT_RIGHT))
	{
		//�E�Ɉړ�����
		playerInfo.PosX += playerInfo.MoveSpeed;

		//���H�̒[�܂œ��B������
		if (playerInfo.PosX >= 880.0f)
		{
			//����ȏ�E�ɍs���Ȃ��悤�ɂ���
			playerInfo.PosX = 880.0f;
		}
	}

	//A�L�[�܂��͍����L�[�������Ă����
	else if (IsKeyKeep(KEY_INPUT_A) || IsKeyKeep(KEY_INPUT_LEFT))
	{
		//���Ɉړ�����
		playerInfo.PosX -= playerInfo.MoveSpeed;

		//���H�̒[�܂œ��B������
		if (playerInfo.PosX <= 404.0f)
		{
			//����ȏ㍶�ɍs���Ȃ��悤�ɂ���
			playerInfo.PosX = 404.0f;
		}
	}
}

void ChangePlayerImage()	//�v���C���[�̉摜��ς���
{
	playerInfo.AnimeFrame++;	//�Đ����Ԃ��J�E���g
	if (playerInfo.AnimeFrame >= FRAME_TIME / 2)	//���̎��ԂɒB������
	{
		playerInfo.AnimeFrame = 0;		//�Đ����Ԃ����Z�b�g

		if (!playerInfo.isReverse)		//�t�Đ��t���O��false�Ȃ�
		{
			if (playerInfo.HandleIndex == 9)	//�Ō�̉摜�Ȃ�
			{
				playerInfo.isReverse = true;	//�t�Đ��ɂ���
				playerInfo.HandleIndex = 8;	//1�O�̉摜�ɂ���
			}

			else	//�Ō�̉摜�łȂ��Ȃ�
			{
				playerInfo.HandleIndex++;	//���̉摜�ɐ؂�ւ���
			}
		}

		else
		{
			if (playerInfo.HandleIndex == 0)	//�ŏ��̉摜�Ȃ�
			{
				playerInfo.isReverse = false;	//�ʏ�Đ��ɂ���
				playerInfo.HandleIndex = 1;	//1���̉摜�ɂ���
			}

			else	//�ŏ��̉摜�łȂ��Ȃ�
			{
				playerInfo.HandleIndex--;	//�O�̉摜�ɐ؂�ւ���
			}
		}
	}
}

PlayerInfo* GetPlayerInfo()	//�v���C���[���擾
{
	return &playerInfo;
}
