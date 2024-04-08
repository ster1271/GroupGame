#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//�^�C�g���w�i�摜�̃n���h��
int BgTitleHandle;


//�^�C�g��������
void InitTitle()
{
	//�^�C�g���w�i�摜�̏�����
	BgTitleHandle = LoadGraph(BG_TITLE_PATH);

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

}

//�^�C�g���㏈��
void FinTitle()
{
	//�^�C�g���w�i�摜�̔j��
	DeleteGraph(BgTitleHandle);

	//�^�C�g���̌�̓v���C��
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
