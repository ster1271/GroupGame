#pragma once

#define PLAYER_PATH		("Data/PlayImage/Player.png")	//�v���C���[�摜(��)�̃p�X

//�v���C���[�N���X
class Player
{
	private:	//�����o�ϐ��ꗗ
		int PlayerHandle;	//�摜�n���h��
		float PosX, PosY;	//X���W,Y���W
		float MoveSpeed;	//�ړ����x

	public:		//���\�b�h�ꗗ
		Player()	//�R���X�g���N�^(�S�Ă̏������Z�b�g)
		{
			PlayerHandle = 0;
			PosX = 0.0f;
			PosY = 0.0f;
			MoveSpeed = 0.0f;
		}

		void InitPlayer()	//�v���C���[�̏�����
		{
			PlayerHandle = LoadGraph(PLAYER_PATH);	//�摜�̓ǂݍ���
			PosX = 320.0f;		//����X���W��ݒ�
			PosY = 400.0f;		//����Y���W��ݒ�
			MoveSpeed = 3.0f;	//�����ړ����x��ݒ�
		}

		void StepPlayer()	//�v���C���[�ʏ폈��
		{
			//D�L�[�܂��͉E���L�[�������Ă����
			if (IsKeyKeep(KEY_INPUT_D) || IsKeyKeep(KEY_INPUT_RIGHT))
			{
				//�E�Ɉړ�����
				PosX += MoveSpeed;

				//��ʒ[�܂œ��B������
				if (PosX >= 624.0f)
				{
					//����ȏ�E�ɍs���Ȃ��悤�ɂ���
					PosX = 624.0f;
				}
			}

			//A�L�[�܂��͍����L�[�������Ă����
			else if (IsKeyKeep(KEY_INPUT_A) || IsKeyKeep(KEY_INPUT_LEFT))
			{
				//���Ɉړ�����
				PosX -= MoveSpeed;

				//��ʒ[�܂œ��B������
				if (PosX <= 16.0f)
				{
					//����ȏ㍶�ɍs���Ȃ��悤�ɂ���
					PosX = 16.0f;
				}
			}
		}

		void DrawPlayer()	//�v���C���[�`�揈��
		{
			DrawRotaGraph((int)PosX, (int)PosY, 1.0f, 0.0f, PlayerHandle, true);
		}

		void FinPlayer()	//�v���C���[�̌㏈��
		{
			//�摜��j��
			DeleteGraph(PlayerHandle);
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
