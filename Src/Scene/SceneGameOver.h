//2309430 �{�߈ꐯ

#pragma once

<<<<<<< Updated upstream
#define BG_GAMEOVER_PATH	("Data/GameOverImage/Game Over.png")	//�Q�[���I�[�o�[�w�i�摜
#define	SELECT_PATH			("Data/GameOverImage/Select.png")		//���摜
=======
#define BG_GAMEOVER_PATH	("Data/GameOverImage/GameOverBG.png")		//�Q�[���I�[�o�[�w�i�摜
#define GAMEOVER_PATH		("Data/GameOverImage/GameOver.png")			//�Q�[���I�[�o�[�����摜
#define CONTINUE_PATH		("Data/GameOverImage/Continue.png")			//�R���e�B�j���[�����摜
#define	BACKTITLE_PATH		("Data/GameOverImage/BackTitle.png")		//�^�C�g���ɖ߂镶���摜
#define	SELECT_PATH			("Data/GameOverImage/Select.png")			//���摜
#define GAMEOVER_BGM_PATH	("Data/Sounds/Music/GameOver/GameOver.mp3")	//�Q�[���I�[�o�[���BGM�̃p�X
#define SELECT_SE			("Data/Sounds/SE/GameOver/Select.wav")		//�Z���N�g���ʉ��̃p�X
>>>>>>> Stashed changes

//�Q�[���I�[�o�[������
void InitGameOver();

//�Q�[���I�[�o�[�ʏ폈��
void StepGameOver();

//�Q�[���I�[�o�[�`�揈��
void DrawGameOver();

//�Q�[���I�[�o�[�㏈��
void FinGameOver();
