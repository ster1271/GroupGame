#pragma once

//�摜�p�X
//�w�i
<<<<<<< Updated upstream
#define CLEAR_BUCKGROUND_PATH	"Data/ClearImage/Game Clear.png"
#define SELECT_PATH				"Data/ClearImage/Select.png"
#define BG_STER_PATH			"Data/ClearImage/Score_Ster.png"
#define STER_PATH				"Data/ClearImage/Score_ColorSter.png"
=======
#define CLEAR_BUCKGROUND_PATH	"Data/ClearImage/GameClear_BackGround.png"
#define CLEAR_BGM_PATH		("Data/Sounds/Music/Clear/GameClear.mp3")	//�N���A���BGM�̃p�X
>>>>>>> Stashed changes

//�N���A������
void InitClear();

//�N���A�ʏ폈��
void StepClear();

//�N���A�`�揈��
void DrawClear();

//�N���A�㏈��
void FinClear();