#include "DxLib.h"
#include "SceneClear.h"
#include "Scene.h"

//�^�C�g���n���h��
int clear_buckGround_image_handle;

//�N���A������
void InitClear()
{
	//�摜�ǂݍ���
	//�w�i
	clear_buckGround_image_handle = LoadGraph(CLEAR_BUCKGROUND_PATH);

	//�N���A�ʏ폈���Ɉړ�
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//�N���A�ʏ폈��
void StepClear()
{


	//�G���^�[�L�[�ŃN���A�㏈���Ɉړ�
	if (IsKeyRelease(KEY_INPUT_RETURN))
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
}

//�N���A�㏈��
void FinClear()
{
	//�摜�j��
	//�w�i
	DeleteGraph(clear_buckGround_image_handle);
}