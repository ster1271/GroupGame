#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//�^�C�g���w�i�摜�̃n���h��
int BgTitleHandle;

//���摜�n���h��
int S_Handle;

//�^�C�g�������摜�̃n���h��
int TitleTextHandle;

//�T�u�^�C�g�������摜�̃p�X
int SubTitleTextHandle;

//�X�^�[�g�����摜�̃n���h��
int StartTextHandle;

//BGM�̃n���h��
int Title_Bgm;

//�^�C�g��������
void InitTitle()
{
	//�^�C�g���w�i�摜�̏�����
	BgTitleHandle = LoadGraph(BG_TITLE_PATH);


	//���摜�̏�����
	S_Handle = LoadGraph(SELECT_PATH);

	//�^�C�g�������摜�̏�����
	TitleTextHandle = LoadGraph(TITLE_TEXT_PATH);

	//�T�u�^�C�g�������摜�̏�����
	SubTitleTextHandle = LoadGraph(SUB_TEXT_PATH);

	//�X�^�[�g�����摜�̏�����
	StartTextHandle = LoadGraph(START_TEXT_PATH);


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

	//���摜�̕`��
	DrawRotaGraph(430, 630, 2.0f, 0.0f, S_Handle, true, false, false);

	//�^�C�g�������摜�̕`��
	DrawRotaGraph(640, 300, 1.0f, 0.0f, TitleTextHandle, true);

	//�T�u�^�C�g�������摜�̕`��
	DrawRotaGraph(640, 150, 1.0f, 0.0f, SubTitleTextHandle, true);

	//�X�^�[�g�����摜�̕`��
	DrawRotaGraph(640, 550, 1.0f, 0.0f, StartTextHandle, true);
}

//�^�C�g���㏈��
void FinTitle()
{
	//�^�C�g���w�i�摜�̔j��
	DeleteGraph(BgTitleHandle);

	//���摜�̔j��
	DeleteGraph(S_Handle);

	//�^�C�g�������摜�̔j��
	DeleteGraph(TitleTextHandle);

	//�T�u�^�C�g�������摜�̔j��
	DeleteGraph(SubTitleTextHandle);

	//�X�^�[�g�����摜�̔j��
	DeleteGraph(StartTextHandle);

	//BGM��~
	StopSoundMem(Title_Bgm);

	//BGM�j��
	DeleteSoundMem(Title_Bgm);

	//�^�C�g���̌�̓v���C��
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
