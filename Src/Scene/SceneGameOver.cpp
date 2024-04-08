//2309430 �{�߈ꐯ

#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

//�Q�[���I�[�o�[�w�i�摜�n���h��
int BgGameOverHundle;

//���摜�n���h��
int SelectHundle;

//�Z���N�gY���W
int SelectPosY;

//�Q�[���I�[�o�[������
void InitGameOver()
{
	//�w�i�摜�ǂݍ���
	BgGameOverHundle = LoadGraph(BG_GAMEOVER_PATH);

	//���摜�ǂݍ���
	SelectHundle = LoadGraph(SELECT_PATH);

	//���W�ݒ�
	SelectPosY = 360;

	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//�Q�[���I�[�o�[�ʏ폈��
void StepGameOver()
{
	if (IsKeyPush(KEY_INPUT_UP))
	{
		SelectPosY = 360;
	}
	else if(IsKeyPush(KEY_INPUT_DOWN))
	{
		SelectPosY = 525;
	}

	//Enter�L�[�������ꂽ��
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�Q�[���I�[�o�[�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

//�Q�[���I�[�o�[�`�揈��
void DrawGameOver()
{
	///�w�i�摜�`��
	DrawGraph(0, 0, BgGameOverHundle, true);

	//���摜�`��
	DrawRotaGraph(370, SelectPosY, 2.0f, 0.0f, SelectHundle, true, false, false);
}

//�Q�[���I�[�o�[�㏈��
void FinGameOver()
{
	//�w�i�摜�j��
	DeleteGraph(BgGameOverHundle);

	//���摜�j��
	DeleteGraph(SelectHundle);


	if (SelectPosY == 360)
	{
		//�v���C�V�[���ɖ߂�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
	else
	{
		//�^�C�g���ɖ߂�悤�ɂ���
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
}
