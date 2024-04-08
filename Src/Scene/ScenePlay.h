#pragma once

<<<<<<< Updated upstream
#define PLAYER_PATH		("Data/PlayImage/runBoy/runBoy1.png")	//�v���C���[�摜�̃p�X
#define ROAD_PATH		("Data/PlayImage/Road/���H.png")		//���H�̉摜�p�X
#define GATE_PATH		("Data/PlayImage/Gate/Gate.png")		//�Q�[�g�̉摜�p�X

#define GATE_NUM	(12)		//�Q�[�g�ő吔
=======
#define ROAD_PATH	("Data/PlayImage/Road/���H.png")					//���H�̉摜�̃p�X
#define BACK_PATH	("Data/PlayImage/BackGround/PlayBackGround.png")	//�w�i�̉摜�̃p�X
#define BGM_PATH	("Data/Sounds/Music/Play/Stage.mp3")				//BGM�̃p�X
>>>>>>> Stashed changes


//�w�i�N���X
class BackGround
{
	private:
		int BgHandle;			//�w�i�̉摜�n���h��
		float BgPosX, BgPosY;	//X���W,y���W

	public:
		BackGround()	//�R���X�g���N�^
		{
			BgHandle = 0;
			BgPosX = 0.0f;
			BgPosY = 0.0f;
		}

		void InitBackGround()	//�w�i�̏�����
		{
			BgHandle = LoadGraph(BACK_PATH);
			BgPosX = 0.0f;
			BgPosY = 0.0f;
		}

		void DarwBakcGround()	//�w�i�̕`�揈��
		{
			DrawGraph((int)BgPosX, (int)BgPosY, BgHandle, true);
		}

		void FinBackGround()	//�w�i�̌㏈��
		{
			DeleteGraph(BgHandle);
		}
};

//���H�N���X
class Road
{
	private:
		int Road_Handle[2];				//���H�̉摜�n���h��
		float Road_PosX, Road_PosY;		//X���W,Y���W
		float Road_Speed;				//�����X�N���[���̑��x
		bool RoadIsMove;				//�����H�̉摜�������X�N���[�����Ă��邩�t���O
<<<<<<< Updated upstream


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
=======
>>>>>>> Stashed changes

	public:
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
				DrawGraph((int)Road_PosX, (int)Road_PosY - i * 720, Road_Handle[i], true);
			}
		}

		void FinRoad()		//���H�摜�j��
		{
			for (int i = 0; i < 2; i++)
			{
				DeleteGraph(Road_Handle[i]);
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

		
};

//�v���C�V�[��������
void InitPlay();

//�v���C�V�[���ʏ폈��
void StepPlay();

//�v���C�V�[���`�揈��
void DrawPlay();

//�v���C�V�[���㏈��
void FinPlay();
