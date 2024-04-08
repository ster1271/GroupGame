#pragma once

#define PLAYER_PATH		("Data/PlayImage/runBoy/runBoy1.png")	//�v���C���[�摜�̃p�X
#define ROAD_PATH		("Data/PlayImage/Road/���H.png")		//���H�̉摜


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

//�v���C���[�N���X
class Player
{
	private:	//�����o�ϐ��ꗗ
		int PlayerHandle[PLAYER_NUM];	//�摜�n���h��
		int HandleIndex;				//�摜�n���h���̓Y�����p�ϐ�
		int AnimeFrame;					//�摜�̍Đ�����
		bool isReverse;					//�A�j���[�V�����̋t�Đ��t���O
		float PosX, PosY;				//X���W,Y���W
		float MoveSpeed;				//�ړ����x

		//���H�摜�p�ϐ�
		int Road_Handle[2];				//���H�̉摜�n���h��
		float Road_PosX, Road_PosY;		//X���W,Y���W
		float Road_Speed;				//�����X�N���[���̑��x
		bool RoadIsMove;					//�����H�̉摜�������X�N���[�����Ă��邩�t���O

	public:		//���\�b�h�ꗗ
		Player()	//�R���X�g���N�^(�S�Ă̏������Z�b�g)
		{
			for (int i = 0; i < PLAYER_NUM; i++)
			{
				PlayerHandle[i] = 0;
			}
			HandleIndex = 0;
			AnimeFrame = 0;
			isReverse = false;
			PosX = 0.0f;
			PosY = 0.0f;
			MoveSpeed = 0.0f;

		}

		void InitPlayer()	//�v���C���[�̏�����
		{
			//�摜�̓ǂݍ���
			LoadPlayer(PLAYER_1);	//runBoy1
			LoadPlayer(PLAYER_2);	//runBoy2
			LoadPlayer(PLAYER_3);	//runBoy3
			LoadPlayer(PLAYER_4);	//runBoy4
			LoadPlayer(PLAYER_5);	//runBoy5
			LoadPlayer(PLAYER_6);	//runBoy6
			LoadPlayer(PLAYER_7);	//runBoy7
			LoadPlayer(PLAYER_8);	//runBoy8
			LoadPlayer(PLAYER_9);	//runBoy9
			LoadPlayer(PLAYER_10);	//runBoy10
			PosX = 640.0f;			//����X���W��ݒ�
			PosY = 550.0f;			//����Y���W��ݒ�
			MoveSpeed = 3.0f;		//�����ړ����x��ݒ�
		}

		void StepPlayer()	//�v���C���[�ʏ폈��
		{
			MovePlayer();	//�v���C���[�̈ړ�����

			ChangePlayerImage();	//	�v���C���[�̉摜��ς���

			MoveRoad();		//�����X�N���[������
		}

		void DrawPlayer()	//�v���C���[�`�揈��
		{
			DrawRotaGraph((int)PosX, (int)PosY, 1.0f, 0.0f, PlayerHandle[HandleIndex], true);
		}

		void FinPlayer()	//�v���C���[�̌㏈��
		{
			//�摜��j��
			DeleteGraph(PlayerHandle[0]);
		}

		void LoadPlayer(PLAYER_IMAGE type)	//�v���C���[�摜�̓ǂݍ���
		{
			PlayerHandle[type] = LoadGraph(PlayerImage_Path[type]);
		}

		void MovePlayer()	//�v���C���[�̈ړ�����
		{
			//D�L�[�܂��͉E���L�[�������Ă����
			if (IsKeyKeep(KEY_INPUT_D) || IsKeyKeep(KEY_INPUT_RIGHT))
			{
				//�E�Ɉړ�����
				PosX += MoveSpeed;

				//��ʒ[�܂œ��B������
				if (PosX >= 875.0f)
				{
					//����ȏ�E�ɍs���Ȃ��悤�ɂ���
					PosX = 875.0f;
				}
			}

			//A�L�[�܂��͍����L�[�������Ă����
			else if (IsKeyKeep(KEY_INPUT_A) || IsKeyKeep(KEY_INPUT_LEFT))
			{
				//���Ɉړ�����
				PosX -= MoveSpeed;

				//��ʒ[�܂œ��B������
				if (PosX <= 405.0f)
				{
					//����ȏ㍶�ɍs���Ȃ��悤�ɂ���
					PosX = 405.0f;
				}
			}
		}

		void ChangePlayerImage()	//�v���C���[�̉摜��ς���
		{
			AnimeFrame++;	//�Đ����Ԃ��J�E���g
			if (AnimeFrame >= FRAME_TIME / 2)	//���̎��ԂɒB������
			{
				AnimeFrame = 0;		//�Đ����Ԃ����Z�b�g

				if (!isReverse)		//�t�Đ��t���O��false�Ȃ�
				{
					if (HandleIndex == 9)	//�Ō�̉摜�Ȃ�
					{
						isReverse = true;	//�t�Đ��ɂ���
						HandleIndex = 8;	//1�O�̉摜�ɂ���
					}

					else	//�Ō�̉摜�łȂ��Ȃ�
					{
						HandleIndex++;	//���̉摜�ɐ؂�ւ���
					}
				}

				else
				{
					if (HandleIndex == 0)	//�ŏ��̉摜�Ȃ�
					{
						isReverse = false;	//�ʏ�Đ��ɂ���
						HandleIndex = 1;	//1���̉摜�ɂ���
					}

					else	//�ŏ��̉摜�łȂ��Ȃ�
					{
						HandleIndex--;	//�O�̉摜�ɐ؂�ւ���
					}
				}
			}
		}

		void InitRoad()			//���H�p������
		{
			//������
			for (int i = 0; i < 2; i++)
			{
				Road_Handle[i] = 0;
			}

			//���H�̉摜�ǂݍ���
			for (int i = 0; i < 2; i++)
			{
				Road_Handle[i] = LoadGraph(ROAD_PATH);
			}

			//���H�p�ϐ��̏����ݒ�
			Road_PosX = 240.0f;
			Road_PosY = 0.0f;
			Road_Speed = 3.0f;
			RoadIsMove = true;
		}

		void DrawRoad()		//���H�p�`��֐�
		{
			for (int i = 0; i < 2; i++)
			{
				DrawGraph(Road_PosX, Road_PosY - i * 720, Road_Handle[i], true);
			}
		}

		void MoveRoad()		//�����X�N���[������
		{
			if (RoadIsMove == true)	//�t���O��true�̎��ɏ����ɓ���
			{
				Road_PosY += Road_Speed;

				if (Road_PosY == 720)
				{
					Road_PosY = 0;
				}
			}

		}

		void FinRoad()		//���H�摜�j��
		{
			for (int i = 0; i < 2; i++)
			{
				DeleteGraph(Road_Handle[i]);
			}
		}
};

//�v���C�V�[��������
void InitPlay();

//�v���C�V�[���ʏ폈��
void StepPlay();

//�v���C�V�[���`�揈��
void DrawPlay();

//�v���C�V�[���㏈��
void FinPlay();
