//2309430 �{�߈ꐯ

#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

//�Q�[���I�[�o�[�w�i�摜�n���h��
int BgGameOverHundle;

//�Q�[���I�[�o�[�����摜�n���h��
int GameOverHundle;

//�R���e�B�j���[�����摜�n���h��
int ContinueHundle;

//�^�C�g���ɖ߂镶���摜�n���h��
int BackTitleHundle;

//���摜�n���h��
int SelectHundle;

//�Z���N�gY���W
int SelectPosY;

//�Q�[���I�[�o�[������
void InitGameOver()
{
	//�w�i�摜�ǂݍ���
	BgGameOverHundle = LoadGraph(BG_GAMEOVER_PATH);

	//�Q�[���I�[�o�[�����摜�ǂݍ���
	GameOverHundle = LoadGraph(GAMEOVER_PATH);

	//�R���e�B�j���[�����摜�ǂݍ���
	ContinueHundle = LoadGraph(CONTINUE_PATH);

	//�^�C�g���ɖ߂镶���摜�ǂݍ���
	BackTitleHundle = LoadGraph(BACKTITLE_PATH);

	//���摜�ǂݍ���
	SelectHundle = LoadGraph(SELECT_PATH);

	//���W�ݒ�
	SelectPosY = 430;

	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//�Q�[���I�[�o�[�ʏ폈��
void StepGameOver()
{
	if (IsKeyPush(KEY_INPUT_UP))
	{
		SelectPosY = 430;
	}
	else if(IsKeyPush(KEY_INPUT_DOWN))
	{
		SelectPosY = 580;
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

	//�Q�[���I�[�o�[�����摜�`��
	DrawGraph(80, 50, GameOverHundle, true);

	//�R���e�B�j���[�����摜�`��
	DrawGraph(400, 400, ContinueHundle, true);

	//�^�C�g���ɖ߂镶���摜�`��
	DrawGraph(400, 550, BackTitleHundle, true);

	//���摜�`��
	DrawRotaGraph(330, SelectPosY, 2.0f, 0.0f, SelectHundle, true, false, false);
}

//�Q�[���I�[�o�[�㏈��
void FinGameOver()
{
	//�w�i�摜�j��
	DeleteGraph(BgGameOverHundle);

	//�Q�[���I�[�o�[�����摜�j��
	DeleteGraph(GameOverHundle);

	//�R���e�B�j���[�����摜�j��
	DeleteGraph(ContinueHundle);

	//�^�C�g���ɖ߂镶���摜�j��
	DeleteGraph(BackTitleHundle);

	//���摜�j��
	DeleteGraph(SelectHundle);


	if (SelectPosY == 430)
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
