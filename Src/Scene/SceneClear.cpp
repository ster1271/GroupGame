#include "DxLib.h"
#include "SceneClear.h"
#include "Scene.h"

//�^�C�g���n���h��
int clear_buckGround_image_handle;
int Select_Hundle;

//���̔w�i
int Bg_SterHndl[3] = { 0 };

//���̖{��
int Score_SterHndl[3] = { 0 };

//BGM�̃n���h��
int Clear_Bgm;

//�N���A������
void InitClear()
{
	//�摜�ǂݍ���
	//�w�i
	clear_buckGround_image_handle = LoadGraph(CLEAR_BUCKGROUND_PATH);
	Select_Hundle = LoadGraph(SELECT_PATH);

	//���̔w�i
	for (int i = 0; i < 3; i++)
	{
		Bg_SterHndl[i] = LoadGraph(BG_STER_PATH);
	}

	//���̖{��
	for (int i = 0; i < 3; i++)
	{
		Score_SterHndl[i] = LoadGraph(STER_PATH);
	}

	//BGM�ǂݍ���
	Clear_Bgm = LoadSoundMem(CLEAR_BGM_PATH);

	//BGM�Đ�
	PlaySoundMem(Clear_Bgm, DX_PLAYTYPE_LOOP, true);

	//�N���A�ʏ폈���Ɉړ�
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//�N���A�ʏ폈��
void StepClear()
{
	//�G���^�[�L�[�ŃN���A�㏈���Ɉړ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}
}

//�N���A�`�揈��
void DrawClear()
{
	//�摜�\��
	//�w�i
	DrawGraph(0, 0, clear_buckGround_image_handle, true);

	DrawRotaGraph(330, 600, 2.0f, 0.0f, Select_Hundle, true, false, false);

	for (int i = 0; i < 3; i++)
	{
		//�D�F�̐�
		DrawGraph(220 * i + 360, 220, Bg_SterHndl[i], true);

		
	}

	//���'3'��ϐ��ɕύX����
	for (int a = 0; a < 3; a++)
	{
		//�F�t���̐�
		DrawGraph(220 * a + 360, 220, Score_SterHndl[a], true);
	}
}

//�N���A�㏈��
void FinClear()
{
	//�摜�j��
	//�w�i
	DeleteGraph(clear_buckGround_image_handle);

<<<<<<< Updated upstream
	DeleteGraph(Select_Hundle);

	//�^�C�g���V�[���Ɉړ�
=======
	//BGM��~
	StopSoundMem(Clear_Bgm);

	//BGM�j��
	DeleteSoundMem(Clear_Bgm);

	//�^�C�g���ɖ߂�悤�ɂ���
>>>>>>> Stashed changes
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}