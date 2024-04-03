#include "DxLib.h"
#include "Effect.h"
#include "../Common.h"

//��x�ɕ\���ł���G�t�F�N�g�ő吔(���u��)
#define EFFECT_MAX_NUM		(100)

//�G�t�F�N�g�̃A�j���ő吔(���u��)
#define EFFECT_ANIME_MAX_NUM	(4)	

//�G�t�F�N�g���
struct EffectInfo
{
	EFFECT_TYPE Kind;							//�G�t�F�N�g�̎��
	int animeHandle[EFFECT_ANIME_MAX_NUM];		//�摜�n���h��
	int x, y;									//���W
	bool isUse;									//�g�p�t���O
	int animeUsedNum;							//�A�j����
	int currentAnimeIndex;						//���݂̃A�j���ԍ�
	float changeTime;							//�P��������̕\������
	float currentAnimeTime;						//���݂̃A�j������
};

//�G�t�F�N�g���
EffectInfo effectInfo[EFFECT_MAX_NUM];

//�G�t�F�N�g�̃t�@�C���p�X
const char effectFilePath[EFFECT_TYPE_NUM][256] =
{
	"Data/Effect/Explosion.png",	//����
	"Data/Effect/Recovery.png",		//��
};

//�e�G�t�F�N�g�̃A�j����
const int effectAnimeImgNum[EFFECT_TYPE_NUM] =
{
	4,	//EFFECT_TYPE_EXPLOSION
	4,	//EFFECT_TYPE_RECOVERY
};

//�e�G�t�F�N�g�̉摜������ [0] = x, [1] = y
const int effectImageSplitNum[EFFECT_TYPE_NUM][2] =
{
	{ 2, 2,},	//EFFECT_TYPE_EXPLOSION
	{ 2, 2,},	//EFFECT_TYPE_RECOVERY
};

//�G�t�F�N�g�̉摜�T�C�Y
const int effectImageSize[EFFECT_TYPE_NUM] =
{
	64,		//EFFECT_TYPE_EXPLOSION
	32,		//EFFECT_TYPE_RECOVERY
};

//�e�G�t�F�N�g�̃A�j���摜�؂�ւ�����
const float effectChageTime[EFFECT_TYPE_NUM] =
{
	0.05f,	//EFFECT_TYPE_EXPLOSION
	0.05f,	//EFFECT_TYPE_RECOVERY
};

//�G�t�F�N�g�̓ǂݍ���
//����	�F�G�t�F�N�g�̎�ށA�쐬��
void LoadEffect(EFFECT_TYPE type, int create_num)
{
	for (int createIndex = 0; createIndex < create_num; createIndex++)
	{
		for (int effectIndex = 0; effectIndex < EFFECT_MAX_NUM; effectIndex++)
		{
			//�ǂݍ��݂��Ă��Ȃ��G�t�F�N�g����������
			//�i�ЂƂڂ̉摜�n���h�����[���Ȃ�ǂݍ��݂���ĂȂ��j
			if (effectInfo[effectIndex].animeHandle[0] == 0)
			{
				//�摜�𕪊��ǂݍ���
				int success_flg = LoadDivGraph(effectFilePath[type],
					effectAnimeImgNum[type],
					effectImageSplitNum[type][0],
					effectImageSplitNum[type][1],
					effectImageSize[type],
					effectImageSize[type],
					effectInfo[effectIndex].animeHandle);

				//��������
				if (success_flg == 0)
				{
					for (int i = 0; i < EFFECT_MAX_NUM; i++)
					{
						//�A�j�������i�[
						effectInfo[effectIndex].animeUsedNum = effectAnimeImgNum[type];

						//�P��������̕\�����Ԃ�ݒ�
						effectInfo[effectIndex].changeTime = effectChageTime[type];

						//�G�t�F�N�g�̎�ނ�ݒ�
						effectInfo[effectIndex].Kind = type;

					}
				}

				//���ۂɂ�����炸������
				break;
			}
		}
	}
}

//�G�t�F�N�g�̏�����
void InitEffect()
{
	//���ׂẴG�t�F�N�g���̕ϐ����N���A����i�[���ɂ���j
	for (int effectIndex = 0; effectIndex < EFFECT_MAX_NUM; effectIndex++)
	{
		effectInfo[effectIndex].x = 0;
		effectInfo[effectIndex].y = 0;
		effectInfo[effectIndex].animeUsedNum = 0;
		effectInfo[effectIndex].currentAnimeIndex = 0;
		effectInfo[effectIndex].currentAnimeTime = 0.0f;
		effectInfo[effectIndex].changeTime = 0.0f;
		effectInfo[effectIndex].isUse = false;
		for (int i = 0; i < EFFECT_ANIME_MAX_NUM; i++)
		{
			effectInfo[effectIndex].animeHandle[i] = 0;
		}
	}
}

//�G�t�F�N�g�ʏ폈��
void StepEffect()
{
	for (int effectIndex = 0; effectIndex < EFFECT_MAX_NUM; effectIndex++)
	{
		//�g�p���Ȃ�A�j�����Ԃ��o�߂����āA�A�j���ԍ����X�V����
		if (effectInfo[effectIndex].isUse)
		{
			//�摜�؂�ւ��ɕK�v�Ȏ��Ԍo�߂�����
			if (effectInfo[effectIndex].currentAnimeTime >= effectInfo[effectIndex].changeTime)
			{
				//���̉摜��
				effectInfo[effectIndex].currentAnimeIndex++;

				//�v�����ԃ��Z�b�g
				effectInfo[effectIndex].currentAnimeTime = 0.0f;

				//���̉摜�����������Ȃ�
				if (effectInfo[effectIndex].currentAnimeIndex >= effectInfo[effectIndex].animeUsedNum)
				{
					//�g�p���t���O��OFF��
					effectInfo[effectIndex].isUse = false;

					//�ȉ��̏����͕s�v
					continue;
				}
			}

			//���ԍX�V
			effectInfo[effectIndex].currentAnimeTime += 1.0f / FRAME_RATE;
		}
	}
}

//�G�t�F�N�g�`�揈��
void DrawEffect()
{
	for (int effectIndex = 0; effectIndex < EFFECT_MAX_NUM; effectIndex++)
	{
		//�g�p���Ȃ猻�݂̃A�j���ԍ��ŕ`�悷��
		if (effectInfo[effectIndex].isUse)
		{
			DrawRotaGraph(effectInfo[effectIndex].x,
						  effectInfo[effectIndex].y,
						  1.0, 0.0, effectInfo[effectIndex].animeHandle[effectInfo[effectIndex].currentAnimeIndex], true);
		}
	}
}

//�G�t�F�N�g�̌㏈��
void FinEffect()
{
	//���ׂẴG�t�F�N�g���폜����
	for (int effectIndex = 0; effectIndex < EFFECT_MAX_NUM; effectIndex++)
	{
		//���ׂč폜����
		for (int animeIndex = 0; animeIndex < EFFECT_ANIME_MAX_NUM; animeIndex++)
		{

			//�[���ȊO�Ȃ�폜����
			if (effectInfo[effectIndex].animeHandle[animeIndex] != 0)
			{
				//�摜�폜
				DeleteGraph(effectInfo[effectIndex].animeHandle[animeIndex]);

				//�폜������[�������Ă���
				effectInfo[effectIndex].animeHandle[animeIndex] = 0;
			}
		}
	}
}

//�G�t�F�N�g�̍Đ�
//����	�F�G�t�F�N�g�̎��, �w���W, �x���W, �P��������̕\������
void PlayEffect(EFFECT_TYPE type, int x, int y)
{
	//���g�p�G�t�F�N�g��T���čĐ�
	for (int effectIndex = 0; effectIndex < EFFECT_MAX_NUM; effectIndex++)
	{
		//�g�p���Ȃ�ȉ��s��Ȃ�
		if (effectInfo[effectIndex].isUse)
		{
			continue;
		}

		//�^�C�v����v����
		if (effectInfo[effectIndex].Kind == type)
		{
			//���W�ݒ�
			effectInfo[effectIndex].x = x;
			effectInfo[effectIndex].y = y;

			//�v���p�̕ϐ����N���A
			effectInfo[effectIndex].currentAnimeIndex = 0;
			effectInfo[effectIndex].currentAnimeTime = 0.0f;

			//�g�p���ɂ���
			effectInfo[effectIndex].isUse = true;

			//������
			break;
		}
	}

}
