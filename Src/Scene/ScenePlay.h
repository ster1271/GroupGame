#pragma once

#define ROAD_PATH	("Data/PlayImage/Road/道路.png")					//道路の画像のパス
#define BACK_PATH	("Data/PlayImage/BackGround/PlayBackGround.png")	//背景の画像のパス
#define BGM_PATH	("Data/Sounds/Music/Play/Stage.mp3")				//BGMのパス

//背景クラス
class BackGround
{
	private:
		int BgHandle;			//背景の画像ハンドル
		float BgPosX, BgPosY;	//X座標,y座標

	public:
		BackGround()	//コンストラクタ
		{
			BgHandle = 0;
			BgPosX = 0.0f;
			BgPosY = 0.0f;
		}

		void InitBackGround()	//背景の初期化
		{
			BgHandle = LoadGraph(BACK_PATH);
			BgPosX = 0.0f;
			BgPosY = 0.0f;
		}

		void DarwBakcGround()	//背景の描画処理
		{
			DrawGraph((int)BgPosX, (int)BgPosY, BgHandle, true);
		}

		void FinBackGround()	//背景の後処理
		{
			DeleteGraph(BgHandle);
		}
};

//道路クラス
class Road
{
	private:
		int Road_Handle[2];				//道路の画像ハンドル
		float Road_PosX, Road_PosY;		//X座標,Y座標
		float Road_Speed;				//自動スクロールの速度
		bool RoadIsMove;				//今道路の画像が自動スクロールしているかフラグ

	public:
		void InitRoad()			//道路用初期化
		{
			//初期化
			for (int i = 0; i < 2; i++)
			{
				Road_Handle[i] = 0;
			}

			//道路の画像読み込み
			for (int i = 0; i < 2; i++)
			{
				Road_Handle[i] = LoadGraph(ROAD_PATH);
			}

			//道路用変数の初期設定
			Road_PosX = 240.0f;
			Road_PosY = 0.0f;
			Road_Speed = 3.0f;
			RoadIsMove = true;
		}

		void DrawRoad()		//道路用描画関数
		{
			for (int i = 0; i < 2; i++)
			{
				DrawGraph((int)Road_PosX, (int)Road_PosY - i * 720, Road_Handle[i], true);
			}
		}

		void FinRoad()		//道路画像破棄
		{
			for (int i = 0; i < 2; i++)
			{
				DeleteGraph(Road_Handle[i]);
			}
		}

		void MoveRoad()		//自動スクロール処理
		{
			if (RoadIsMove == true)	//フラグがtrueの時に処理に入る
			{
				Road_PosY += Road_Speed;

				if (Road_PosY == 720)
				{
					Road_PosY = 0;
				}
			}
		}

		
};

//プレイシーン初期化
void InitPlay();

//プレイシーン通常処理
void StepPlay();

//プレイシーン描画処理
void DrawPlay();

//プレイシーン後処理
void FinPlay();
