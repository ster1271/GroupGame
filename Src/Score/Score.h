#pragma once

#define STAR_PATH	("Data/PlayImage/Rank/RankStar.png")	//���̉摜�̃p�X
#define STAR2_PATH	("Data/PlayImage/Rank/RankStar2.png")	//�D�F�́��̉摜�̃p�X

#define STAR_NUM	(3)		//���̐�
#define RESULT_SE	("Data/Sounds/SE/Play/ResultScore.wav")	//���U���g�̌��ʉ��̃p�X

//�����N���\����
struct RankInfo
{
	int StarHandle;		//�摜�n���h��
	float PosX, PosY;	//X���W,Y���W
	bool isDraw;		//�`��t���O
};

void InitRank();	//�����N�̏�����

void StepRank();	//�����N�ʏ폈��

void DrawRank();	//�����N�`�揈��

void FinRank();		//�����N�̌㏈��