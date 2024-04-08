#pragma once

//�v���C���[�摜�̎��
enum PLAYER_IMAGE
{
	PLAYER_1 = 0,	//runBoy1
	PLAYER_2,		//runBoy2
	PLAYER_3,		//runBoy3
	PLAYER_4,		//runBoy4
	PLAYER_5,		//runBoy5
	PLAYER_6,		//runBoy6
	PLAYER_7,		//runBoy7
	PLAYER_8,		//runBoy8
	PLAYER_9,		//runBoy9
	PLAYER_10,		//runBoy10

	PLAYER_NUM,
};

//�v���C���[�摜�̃p�X
const char PlayerImage_Path[PLAYER_NUM][100] =
{
	"Data/PlayImage/runBoy/runBoy1.png",	//runBoy1
	"Data/PlayImage/runBoy/runBoy2.png",	//runBoy2
	"Data/PlayImage/runBoy/runBoy3.png",	//runBoy3
	"Data/PlayImage/runBoy/runBoy4.png",	//runBoy4
	"Data/PlayImage/runBoy/runBoy5.png",	//runBoy5
	"Data/PlayImage/runBoy/runBoy6.png",	//runBoy6
	"Data/PlayImage/runBoy/runBoy7.png",	//runBoy7
	"Data/PlayImage/runBoy/runBoy8.png",	//runBoy8
	"Data/PlayImage/runBoy/runBoy9.png",	//runBoy9
	"Data/PlayImage/runBoy/runBoy10.png",	//runBoy10
};

//�v���C���[���\����
struct PlayerInfo
{
	int PlayerHandle[PLAYER_NUM];	//�摜�n���h��
	int HandleIndex;				//�摜�n���h���̓Y�����p�ϐ�
	int AnimeFrame;					//�摜�̍Đ�����
	bool isReverse;					//�A�j���[�V�����̋t�Đ��t���O
	float PosX, PosY;				//X���W,Y���W
	float Radius;					//���a
	float MoveSpeed;				//�ړ����x
	int CurrentScore;				//�l���X�R�A
	int Life;						//���C�t
	bool isAlive;					//�����t���O
	int Cleared;					//�ʉ߂����Q�[�g�̐�
	int BreakEnemy;					//�|�����G�̐�
	bool isRank;					//�����N�\���ɐi�ރt���O
	bool isClear;					//�N���A�t���O
};

void InitPlayer();	//�v���C���[�̏�����

void StepPlayer();	//�v���C���[�ʏ폈��

void DrawPlayer();	//�v���C���[�`�揈��

void FinPlayer();	//�v���C���[�̌㏈��

void LoadPlayer(PLAYER_IMAGE type);		//�v���C���[�摜�̓ǂݍ���

void MovePlayer();	//�v���C���[�̈ړ�����

void ChangePlayerImage();	//�v���C���[�̉摜��ς���

PlayerInfo* GetPlayerInfo();	//�v���C���[���擾
