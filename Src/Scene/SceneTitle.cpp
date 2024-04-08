#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//�^�C�g���w�i�摜�̃n���h��
int BgTitleHandle;

//���摜�n���h��
int S_Handle;

//�^�C�g��������
void InitTitle()
{
	//�^�C�g���w�i�摜�̏�����
	BgTitleHandle = LoadGraph(BG_TITLE_PATH);

	//���摜�̏�����
	S_Handle = LoadGraph(SELECT_PATH);

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


}

//�^�C�g���㏈��
void FinTitle()
{
	//�^�C�g���w�i�摜�̔j��
	DeleteGraph(BgTitleHandle);

	//���摜�̔j��
	DeleteGraph(S_Handle);

	//�^�C�g���̌�̓v���C��
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
