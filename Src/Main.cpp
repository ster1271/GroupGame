//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "Common.h"
#include "Scene/Scene.h"
#include "Scene/SceneTitle.h"
#include "Scene/SceneClear.h"
#include "Scene/SceneGameOver.h"

// define
#define	SCREEN_SIZE_X	1280	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	720	// Y�����̉�ʃT�C�Y���w��

//�t���[�����[�g���
struct FrameRateInfo
{
	int currentTime;	//���݂̎���
	int lastFrameTime;	//�O��̃t���[�����s���̎���
	int count;			//�t���[���J�E���g�p
	int calcFpsTime;	//FPS���v�Z��������
	float fps;			//�v������FPS�i�\���p�j
};

//�t���[�����[�g���ϐ�
FrameRateInfo frameRateInfo;

//FPS�v�Z
void CalcFPS();

//FPS�\���i�f�o�b�O�p�j
void DrawFPS();

//���݂̃V�[��ID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(false);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//���͏�����
	InitInput();
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		Sleep(1);	//�V�X�e���ɏ�����Ԃ�

		//���݂̎��Ԃ��擾
		frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�A
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		//���݂̎��Ԃ��A�O��̃t���[�������
		//1000/60�~���b�i1/60�b�j�ȏ�o�߂��Ă����珈�������s����
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//�t���[�������J�E���g
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

			//���̓X�e�b�v
			StepInput();

			//-----------------------------------------
			//��������Q�[���̖{�̂��������ƂɂȂ�
			//-----------------------------------------

			//�V�[��ID�ɂ���ď����̐U�蕪��
			switch (g_CurrentSceneID)
			{
				case SCENE_ID_INIT_TITLE:
				{
					//�^�C�g��������
					InitTitle();

				}//SCENE_ID_INIT_TITLE�̏I���̊���
				break;

				case SCENE_ID_LOOP_TITLE:
				{
					//�^�C�g���ʏ폈��
					StepTitle();

					//�^�C�g���`�揈��
					DrawTitle();

				}//SCENE_ID_LOOP_TITLE�̏I���̊���
				break;

				case SCENE_ID_FIN_TITLE:
				{
					//�^�C�g���㏈��
					FinTitle();

				}//SCENE_ID_FIN_TITLE�̏I���̊���
				break;

				//------------------------------------------
				//�������̒S���̃V�[�������Ƃ���
				//�Y���ӏ��̃R�����g���̉��������Y��Ȃ�
				//								by ��c
				//------------------------------------------

				//case SCENE_ID_INIT_PLAY:
				//{
				//	//�v���C�V�[��������
				//	InitPlay();

				//}//SCENE_ID_INIT_PLAY�̏I���̊���
				//break;

				//case SCENE_ID_LOOP_PLAY:
				//{
				//	//�v���C�V�[���ʏ폈��
				//	StepPlay();

				//	//�v���C�V�[���`�揈��
				//	DrawPlay();

				//}//SCENE_ID_LOOP_PLAY�̏I���̊���
				//break;

				//case SCENE_ID_FIN_PLAY:
				//{
				//	//�v���C�V�[���㏈��
				//	FinPlay();

				//}//SCENE_ID_FIN_PLAY�̏I���̊���
				//break;

				//�N���A�V�[��(����)
				case SCENE_ID_INIT_CLEAR:
				{
					//�N���A��ʏ�����
					InitClear();

				}//SCENE_ID_INIT_CLEAR�̏I���̊���
				break;

				case SCENE_ID_LOOP_CLEAR:
				{
					//�N���A��ʒʏ폈��
					StepClear();

					//�N���A��ʕ`�揈��
					DrawClear();

				}//SCENE_ID_LOOP_CLEAR�̏I���̊���
				break;

				case SCENE_ID_FIN_CLEAR:
				{
					//�N���A��ʌ㏈��
					FinClear();

				}//SCENE_ID_FIN_CLEAR�̏I���̊���
				break;

				//�Q�[���I�[�o�[�V�[���S���{��
				case SCENE_ID_INIT_GAMEOVER:
				{
					//�Q�[���I�[�o�[��ʏ�����
					InitGameOver();

				}//SCENE_ID_INIT_GAMEOVER�̏I���̊���
				break;

				case SCENE_ID_LOOP_GAMEOVER:
				{
					//�Q�[���I�[�o�[��ʒʏ폈��
					StepGameOver();

					//�Q�[���I�[�o�[��ʕ`�揈��
					DrawGameOver();

				}//SCENE_ID_LOOP_GAMEOVER�̏I���̊���
				break;

				case SCENE_ID_FIN_GAMEOVER:
				{
					//�Q�[���I�[�o�[��ʌ㏈��
					FinGameOver();

				}//SCENE_ID_FIN_GAMEOVER�̏I���̊���
				break;

			}//�V�[���U�蕪����switch���̏I���̊���

			//FPS�v�Z
			CalcFPS();

			//FPS�\��
			DrawFPS();

			//-----------------------------------------
			//���[�v�̏I����
			//�t���b�v�֐�
			ScreenFlip();

		}//�t���[�����[�g��if���̏I���̊���

	}//���C�����[�v�̏I���̊���

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

//FPS�v�Z
void CalcFPS()
{
	//�O���FPS���v�Z�������Ԃ���̌o�ߎ��Ԃ����߂�
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//�O���FPS���v�Z�������Ԃ���
	//�P�b�ȏ�o�߂��Ă�����FPS���v�Z����
	if (difTime > 1000)
	{
		//�t���[���񐔂��~���b�ɍ��킹��
		//�����܂ŏo�������̂�float�ɃL���X�g
		float frameCount = (float)(frameRateInfo.count * 1000.0f);

		//FPS�����߂�
		//���z�̐��l�� 60000 / 1000 �� 60 �ƂȂ�
		frameRateInfo.fps = frameCount / difTime;

		//�t���[�����[�g�J�E���g���N���A
		frameRateInfo.count = 0;

		//FPS���v�Z�������Ԃ��X�V
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

//FPS�\���i�f�o�b�O�p�j
void DrawFPS()
{
	unsigned int color = GetColor(255, 30, 30);
	DrawFormatString(1175, 700, color, "FPS[%.2f]", frameRateInfo.fps);
}
