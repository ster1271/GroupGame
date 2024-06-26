//2309430 {ßê¯

#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

//Q[I[o[wiænh
int BgGameOverHundle;

//îóænh
int SelectHundle;

//ZNgYÀW
int SelectPosY;

//BGMÌnh
int GameOver_Bgm;

//øÊ¹ÌpX
int Select_SE = 0;

//Q[I[o[ú»
void InitGameOver()
{
	//wiæÇÝÝ
	BgGameOverHundle = LoadGraph(BG_GAMEOVER_PATH);

	//îóæÇÝÝ
	SelectHundle = LoadGraph(SELECT_PATH);

	//ÀWÝè
	SelectPosY = 360;

	//BGMÇÝÝ
	GameOver_Bgm = LoadSoundMem(GAMEOVER_BGM_PATH);

	//BGMÄ¶
	PlaySoundMem(GameOver_Bgm, DX_PLAYTYPE_LOOP, true);

	//øÊ¹ÇÝÝ
	Select_SE = LoadSoundMem(SELECT_SE);

	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//Q[I[o[Êí
void StepGameOver()
{
	if (IsKeyPush(KEY_INPUT_UP))
	{
		SelectPosY = 360;
	}
	else if (IsKeyPush(KEY_INPUT_DOWN))
	{
		SelectPosY = 525;
	}

	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

//Q[I[o[`æ
void DrawGameOver()
{
	///wiæ`æ
	DrawGraph(0, 0, BgGameOverHundle, true);

	//îóæ`æ
	DrawRotaGraph(370, SelectPosY, 2.0f, 0.0f, SelectHundle, true, false, false);
}

//Q[I[o[ã
void FinGameOver()
{
	//wiæjü
	DeleteGraph(BgGameOverHundle);

	//îóæjü
	DeleteGraph(SelectHundle);

	if (SelectPosY == 360)
	{
		//vCV[Éßé
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
	else
	{
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}

	//BGMâ~
	StopSoundMem(GameOver_Bgm);

	//BGMjü
	DeleteSoundMem(GameOver_Bgm);

	//øÊ¹jü
	DeleteSoundMem(Select_SE);
}