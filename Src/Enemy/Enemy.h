#pragma once

#define ENEMY_PATH	("Data/PlayImage/Enemy/Enemy.png")	//�G�̉摜�̃p�X
#define BOSS_PATH	("Data/Playimage/Enemy/Boss.png")	//�{�X�̉摜�̃p�X
#define ENEMY_NUM	(4)		//�G�̐�
#define ENEMY_DIE	("Data/Sounds/SE/Play/EnemyDie.wav")	//�G��|�������̉��̃p�X

struct EnemyInfo
{
	int Enemyhandle;	//�摜�n���h��
	float PosX, PosY;	//X���W	
	float Speed;		//�X�N���[�����x
	bool isAlive;		//�����t���O
	int Life;			//�̗�
	bool isbreak;		//���j�t���O
};

void InitEnemy();			//�G�̏�����

void StepEnemy();			//�G�ʏ폈��

void DrawEnemy();			//�G�`�揈��

void FinEnemy();			//�G�̌㏈��

void SetLife(int temp);		//�̗͐ݒ�
