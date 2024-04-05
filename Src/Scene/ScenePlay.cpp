#include "DxLib.h"
#include "../Common.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "ScenePlay.h"
#include "../Effect/Effect.h"

//�v���C���[�N���X�̐錾
Player player;

//------------------------------------------------
// �����Ƃ����������ł���܂ł̉��u������

//�G���^�[�������ꂽ���ǂ���(�N���A�t���O)
bool isPushEnter;

//�X�y�[�X�������ꂽ���ǂ���(�Q�[���I�[�o�[�t���O)
bool isPushSpace;

//------------------------------------------------

//�v���C�V�[��������
void InitPlay()
{
	//------------------------------------------------
	// �����Ƃ����������ł���܂ł̉��u������
	
	//�N���A�t���O��܂�
	isPushEnter = false;

	//�Q�[���I�[�o�[�t���O��܂�
	isPushSpace = false;

	//------------------------------------------------

	//�v���C���[�̏�����
	player.InitPlayer();

	//���H�̏���������щ摜�̓ǂݍ���
	player.InitRoad();

	//�G�t�F�N�g�̏�����
	InitEffect();

	//�v���C�V�[�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void StepPlay()
{
	//�v���C���[�ʏ폈��
	player.StepPlayer();

	//�G�t�F�N�g�ʏ폈��
	StepEffect();

	//------------------------------------------------
	// �����Ƃ����������ł���܂ł̉��u������

	//�G���^�[�L�[�������ꂽ��
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�N���A�t���O�𗧂Ă�
		isPushEnter = true;

		//�v���C�V�[���㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

	//�X�y�[�X�L�[�������ꂽ��
	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		//�Q�[���I�[�o�[�t���O�𗧂Ă�
		isPushSpace = true;

		//�v���C�V�[���㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

	//------------------------------------------------
}

//�v���C�V�[���`�揈��
void DrawPlay()
{
	//���H�`�揈��
	player.DrawRoad();

	//�v���C���[�`�揈��
	player.DrawPlayer();

	//�G�t�F�N�g�`�揈��
	DrawEffect();

	//�f�o�b�O�p����
	DrawFormatString(0, 0, GetColor(255, 255, 255), "W �܂��� ��:�E�ړ�");
	DrawFormatString(0, 30, GetColor(255, 255, 255), "A �܂��� ��:���ړ�");
	DrawFormatString(0, 60, GetColor(255, 255, 255), "�G���^�[�ŃN���A�V�[���Ɉڍs");
	DrawFormatString(0, 90, GetColor(255, 255, 255), "�X�y�[�X�ŃQ�[���I�[�o�[�V�[���Ɉڍs");
}

//�v���C�V�[���㏈��
void FinPlay()
{
	//���H�摜�㏈��
	player.FinRoad();

	//�v���C���[�̌㏈��
	player.FinPlayer();
	
	//�G�t�F�N�g�̌㏈��
	FinEffect();

	//------------------------------------------------
	// �����Ƃ����������ł���܂ł̉��u������

	//�N���A�t���O��true�Ȃ�
	if (isPushEnter)
	{
		//�N���A�V�[���ֈڍs
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}

	//�Q�[���I�[�o�[�t���O��true�Ȃ�
	else if (isPushSpace)
	{
		//�Q�[���I�[�o�[�V�[���ֈڍs
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;
	}

	//------------------------------------------------

}