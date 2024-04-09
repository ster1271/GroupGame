#pragma once

#define ROAD_PATH	("Data/PlayImage/Road/���H.png")					//���H�̉摜�̃p�X
#define BACK_PATH	("Data/PlayImage/BackGround/PlayBackGround.png")	//�w�i�̉摜�̃p�X
#define BGM_PATH	("Data/Sounds/Music/Play/Stage.mp3")				//BGM�̃p�X

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
