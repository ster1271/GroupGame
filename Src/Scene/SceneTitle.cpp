#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//�^�C�g���w�i�摜�̃n���h��
int BgTitleHandle;

//�^�C�g���摜�n���h��
int TitleHundle;

//BGM�̃n���h��
int Title_Bgm;

//�^�C�g��������
void InitTitle()
{
	//�^�C�g���w�i�摜�̏�����
	BgTitleHandle = LoadGraph(BG_TITLE_PATH);

	//�^�C�g���摜�ǂݍ���
	TitleHundle = LoadGraph(TITLE_PATH);

	//BGM�ǂݍ���
	Title_Bgm = LoadSoundMem(TITLE_BGM_PATH);

	//BGM�Đ�
	PlaySoundMem(Title_Bgm, DX_PLAYTYPE_LOOP, true);

	//�^�C�g�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//�^�C�g���ʏ폈��
void StepTitle()
{
	//Enter�L�[�������ꂽ��
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�^�C�g���㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

//�^�C�g���`�揈��
void DrawTitle()
{
	//�^�C�g���w�i�摜�̕`��
	DrawGraph(0, 0, BgTitleHandle, true);

	//�^�C�g���摜�̕`��
	DrawGraph(250, 0, TitleHundle, true);
}

//�^�C�g���㏈��
void FinTitle()
{
	//�^�C�g���w�i�摜�̔j��
	DeleteGraph(BgTitleHandle);

	//BGM��~
	StopSoundMem(Title_Bgm);

	//BGM�j��
	DeleteSoundMem(Title_Bgm);

	//�^�C�g���̌�̓v���C��
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
