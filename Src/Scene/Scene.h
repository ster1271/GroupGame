#pragma once
#include "../Input/Input.h"
#include "../Collision/Collision.h"

//�^�C�g���֘A
#define SCENE_ID_INIT_TITLE		(100)	//������
#define SCENE_ID_LOOP_TITLE		(101)	//�J��Ԃ�
#define SCENE_ID_FIN_TITLE		(102)	//�㏈��

//�v���C�֘A
#define SCENE_ID_INIT_PLAY		(200)	//������
#define SCENE_ID_LOOP_PLAY		(201)	//�J��Ԃ�
#define SCENE_ID_FIN_PLAY		(202)	//�㏈��

//�N���A�֘A
#define SCENE_ID_INIT_CLEAR		(300)	//������
#define SCENE_ID_LOOP_CLEAR		(301)	//�J��Ԃ�
#define SCENE_ID_FIN_CLEAR		(302)	//�㏈��

//�Q�[���I�[�o�[�֘A
#define SCENE_ID_INIT_GAMEOVER	(400)	//������
#define SCENE_ID_LOOP_GAMEOVER	(401)	//�J��Ԃ�
#define SCENE_ID_FIN_GAMEOVER	(402)	//�㏈��

//���݂̃V�[��ID
extern int g_CurrentSceneID;
