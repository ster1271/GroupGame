#pragma once

#define GATE_NUM	(6)	//������Q�[�g�̐�
#define TEMP_NUM	(4)	//�e���v���̐�
#define GATE1_PATH		("Data/PlayImage/Gate/Gate1_1_1.png")	//�v���X�Q�[�g�̉摜�̃p�X
#define GATE2_PATH		("Data/PlayImage/Gate/Gate1_1_2.png")	//�}�C�i�X�Q�[�g�̉摜�̃p�X
#define PLUS_SOUND		("Data/Sounds/SE/Play/Plus.wav")		//�v���X���ʉ��̃p�X
#define MINUS_SOUND		("Data/Sounds/SE/Play/Minus.wav")		//�}�C�i�X���ʉ��̃p�X

//�Q�[�g���\����
struct GateInfo
{
	int GateHandle;				//�摜�n���h��
	float GatePosX, GatePosY;	//X���W,Y���W
	float Radius;				//���a
	bool isDraw;				//�`��t���O
	float Speed;				//�X�N���[�����x
	int Score;					//�Q�[�g�̓��_
	int CurrentGate;			//���݂̃Q�[�g
};

void InitGate();	//�Q�[�g�̏�����

void StepGate();	//�Q�[�g�ʏ폈��

void DrawGate();	//�Q�[�g�`�揈��

void FinGate();		//�Q�[�g�̌㏈��

void LoadGate(int Temp);		//�Q�[�g�̃e���v���ǂݍ���
