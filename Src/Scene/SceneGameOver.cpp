//2309430 �{�߈ꐯ

#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

//�Q�[���I�[�o�[�w�i�摜�n���h��
int BgGameOverHundle;

//���摜�n���h��
int SelectHundle;

<<<<<<< Updated upstream
//�Z���N�gY���W
int SelectPosY;

=======
//���Y���W
int SelectPosY;

//�R���e�j���[�t���O
bool isContinue;

//�o�b�N�^�C�g���t���O
bool isBackTitle;

//BGM�̃n���h��
int GameOver_Bgm;

//���ʉ��̃p�X
int Select_SE = 0;

>>>>>>> Stashed changes
//�Q�[���I�[�o�[������
void InitGameOver()
{
	//�w�i�摜�ǂݍ���
	BgGameOverHundle = LoadGraph(BG_GAMEOVER_PATH);

	//���摜�ǂݍ���
	SelectHundle = LoadGraph(SELECT_PATH);

<<<<<<< Updated upstream
	//���W�ݒ�
	SelectPosY = 360;
=======
	//���̏���Y���W�ݒ�
	SelectPosY = 370;

	//�R���e�j���[�t���O
	isContinue = false;

	//�o�b�N�^�C�g���t���O
	isBackTitle = false;

	//BGM�ǂݍ���
	GameOver_Bgm = LoadSoundMem(GAMEOVER_BGM_PATH);

	//BGM�Đ�
	PlaySoundMem(GameOver_Bgm, DX_PLAYTYPE_LOOP, true);

	//���ʉ��ǂݍ���
	Select_SE = LoadSoundMem(SELECT_SE);
>>>>>>> Stashed changes

	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//�Q�[���I�[�o�[�ʏ폈��
void StepGameOver()
{
<<<<<<< Updated upstream
	if (IsKeyPush(KEY_INPUT_UP))
	{
		SelectPosY = 360;
	}
	else if(IsKeyPush(KEY_INPUT_DOWN))
	{
		SelectPosY = 525;
=======
	//W�܂��͏���L�[��
	if (IsKeyPush(KEY_INPUT_W) || IsKeyPush(KEY_INPUT_UP))
	{
		//Back Title�ׂ̗Ȃ�
		if (SelectPosY == 570)
		{
			//���ʉ��Đ�
			PlaySoundMem(Select_SE, DX_PLAYTYPE_BACK, true);
		}
		//Continue�ׂ̗�
		SelectPosY = 370;
	}

	//S�܂��͉����L�[��
	else if (IsKeyPush(KEY_INPUT_S) || IsKeyPush(KEY_INPUT_DOWN))
	{
		//Continue�ׂ̗Ȃ�
		if (SelectPosY == 370)
		{
			//���ʉ��Đ�
			PlaySoundMem(Select_SE, DX_PLAYTYPE_BACK, true);
		}
		//Back Title�ׂ̗�
		SelectPosY = 570;
>>>>>>> Stashed changes
	}

	//Enter�L�[�������ꂽ��
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//Continue�ׂ̗Ȃ�
		if (SelectPosY == 370)
		{
			//�R���e�j���[�t���O�𗧂Ă�
			isContinue = true;
		}

		//Back Title�ׂ̗Ȃ�
		else if (SelectPosY == 570)
		{
			//�o�b�N�^�C�g���t���O�𗧂Ă�
			isBackTitle = true;
		}
		//�Q�[���I�[�o�[�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

//�Q�[���I�[�o�[�`�揈��
void DrawGameOver()
{
	///�w�i�摜�`��
	DrawGraph(0, 0, BgGameOverHundle, true);

<<<<<<< Updated upstream
	//���摜�`��
	DrawRotaGraph(370, SelectPosY, 2.0f, 0.0f, SelectHundle, true, false, false);
=======
	//�Q�[���I�[�o�[�����摜�`��
	DrawRotaGraph(640, 200, 1.0f, 0.0f, GameOverHundle, true);

	//�R���e�B�j���[�����摜�`��
	DrawRotaGraph(640, 400, 1.0f, 0.0f, ContinueHundle, true);

	//�^�C�g���ɖ߂镶���摜�`��
	DrawRotaGraph(640, 600, 1.0f, 0.0f, BackTitleHundle, true);

	//���摜�`��
	DrawGraph(300, SelectPosY, SelectHundle, true);
>>>>>>> Stashed changes
}

//�Q�[���I�[�o�[�㏈��
void FinGameOver()
{
	//�w�i�摜�j��
	DeleteGraph(BgGameOverHundle);

	//���摜�j��
	DeleteGraph(SelectHundle);

<<<<<<< Updated upstream

	if (SelectPosY == 360)
	{
		//�v���C�V�[���ɖ߂�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
	else
=======
	//BGM��~
	StopSoundMem(GameOver_Bgm);

	//BGM�j��
	DeleteSoundMem(GameOver_Bgm);

	//���ʉ��j��
	DeleteSoundMem(Select_SE);

	//�R���e�j���[�t���O��true�Ȃ�
	if (isContinue)
	{
		//�v���C�V�[���ɖ߂�悤�ɂ���
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}

	//�o�b�N�^�C�g���t���O��true�Ȃ�
	if (isBackTitle)
>>>>>>> Stashed changes
	{
		//�^�C�g���ɖ߂�悤�ɂ���
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
<<<<<<< Updated upstream
}
=======
}
>>>>>>> Stashed changes
