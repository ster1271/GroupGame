#include "DxLib.h"
#include "../Common.h"
#include "../Effect/Effect.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "ScenePlay.h"
#include "../Player/Player.h"
#include "../Gate/Gate.h"
#include "../Enemy/Enemy.h"
#include "../Score/Score.h"

//�w�i�N���X�̐錾
BackGround background;

//���H�N���X�̐錾
Road road;

//�t���[�����J�E���g����ϐ�
int FrameCount = 0;

//�Q�[���I�[�o�[�t���O
bool isGameOver;

//BGM�i�[�n���h��
int BgmHandle = 0;

int Template = 0;

//�v���C�V�[��������
void InitPlay()
{
	//�Q�[���I�[�o�[�t���O��܂�
	isGameOver = false;

	//�v���C���[�̏�����
	InitPlayer();

	//�w�i�̏�����
	background.InitBackGround();

	//���H�̏���������щ摜�̓ǂݍ���
	road.InitRoad();

	Template = GetRand(TEMP_NUM);

	//�Q�[�g�̃e���v���ǂݍ���
	LoadGate(Template);

	//�Q�[�g�̏�����
	InitGate();

	//�̗͐ݒ�
	SetLife(Template);

	//�G�̏�����
	InitEnemy();

	//�����N�̏�����
	InitRank();

	//�G�t�F�N�g�̏�����
	InitEffect();

	FrameCount = 0;

	//BGM�ǂݍ���
	BgmHandle = LoadSoundMem(BGM_PATH);

	//BGM�Đ�
	PlaySoundMem(BgmHandle, DX_PLAYTYPE_LOOP, true);

	//�v���C�V�[�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void StepPlay()
{
	//�����X�N���[������
	road.MoveRoad();

	//�v���C���[�ʏ폈��
	StepPlayer();

	//�Q�[�g�ʏ폈��
	StepGate();

	//�G�ʏ폈��
	StepEnemy();

	//�����N�ʏ폈��
	StepRank();

	//�G�t�F�N�g�ʏ폈��
	StepEffect();

	//�v���C���[���擾
	PlayerInfo* playerInfo = GetPlayerInfo();

	//�N���A�t���O��true�Ȃ�
	if (playerInfo->isClear)
	{
		//�v���C�V�[���㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

	//���C�t��0�ɂȂ�����
	if (playerInfo->Life <= 0)
	{
		playerInfo->Life = 0;

		//�����t���O��܂�
		playerInfo->isAlive = false;

		//�G�t�F�N�g��`��
		PlayEffect(EFFECT_TYPE_EXPLOSION, (int)playerInfo->PosX, (int)playerInfo->PosY);

		//�t���[�����J�E���g
		FrameCount++;

		if (FrameCount > FRAME_RATE / 2)
		{
			//�Q�[���I�[�o�[�t���O�𗧂Ă�
			isGameOver = true;
		}

		//�Q�[���I�[�o�[�t���O��true�Ȃ�
		if (isGameOver)
		{
			//�v���C�V�[���㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;
		}
	}
}

//�v���C�V�[���`�揈��
void DrawPlay()
{
	//�w�i�`�揈��
	background.DarwBakcGround();

	//���H�`�揈��
	road.DrawRoad();

	//�Q�[�g�`�揈��
	DrawGate();

	//�v���C���[�`�揈��
	DrawPlayer();

	//�G�`�揈��
	DrawEnemy();

	//�����N�`�揈��
	DrawRank();

	//�G�t�F�N�g�`�揈��
	DrawEffect();

	//�f�o�b�O�p����
	DrawFormatString(50, 150, GetColor(255, 255, 255), "W �܂��� ��:�E�ړ�");
	DrawFormatString(50, 180, GetColor(255, 255, 255), "A �܂��� ��:���ړ�");
}

//�v���C�V�[���㏈��
void FinPlay()
{
	//���H�摜�㏈��
	road.FinRoad();

	//�w�i�̌㏈��
	background.FinBackGround();

	//�v���C���[�̌㏈��
	FinPlayer();

	//�Q�[�g�̌㏈��
	FinGate();

	//�G�̌㏈��
	FinEnemy();

	//�����N�̌㏈��
	FinRank();
	
	//�G�t�F�N�g�̌㏈��
	FinEffect();

	//BGM��~
	StopSoundMem(BgmHandle);

	//BGM�j��
	DeleteSoundMem(BgmHandle);

	//�v���C���[���擾
	PlayerInfo* playerInfo = GetPlayerInfo();

	//�N���A�t���O��true�Ȃ�
	if (playerInfo->isClear)
	{
		//�N���A�V�[���ֈڍs
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}

	//�����t���O��false�Ȃ�
	else if (!playerInfo->isAlive)
	{
		//�Q�[���I�[�o�[�V�[���ֈڍs
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;
	}
}
