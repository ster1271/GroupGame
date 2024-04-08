#pragma once

#define PLAYER_PATH		("Data/PlayImage/runBoy/runBoy1.png")	//プレイヤー画像のパス
#define ROAD_PATH		("Data/PlayImage/Road/道路.png")		//道路の画像


//プレイヤー画像の種類
enum PLAYER_IMAGE
{
	PLAYER_1 = 0,	//runBoy1
	PLAYER_2,		//runBoy2
	PLAYER_3,		//runBoy3
	PLAYER_4,		//runBoy4
	PLAYER_5,		//runBoy5
	PLAYER_6,		//runBoy6
	PLAYER_7,		//runBoy7
	PLAYER_8,		//runBoy8
	PLAYER_9,		//runBoy9
	PLAYER_10,		//runBoy10

	PLAYER_NUM,
};

//プレイヤー画像のパス
const char PlayerImage_Path[PLAYER_NUM][100] =
{
	"Data/PlayImage/runBoy/runBoy1.png",	//runBoy1
	"Data/PlayImage/runBoy/runBoy2.png",	//runBoy2
	"Data/PlayImage/runBoy/runBoy3.png",	//runBoy3
	"Data/PlayImage/runBoy/runBoy4.png",	//runBoy4
	"Data/PlayImage/runBoy/runBoy5.png",	//runBoy5
	"Data/PlayImage/runBoy/runBoy6.png",	//runBoy6
	"Data/PlayImage/runBoy/runBoy7.png",	//runBoy7
	"Data/PlayImage/runBoy/runBoy8.png",	//runBoy8
	"Data/PlayImage/runBoy/runBoy9.png",	//runBoy9
	"Data/PlayImage/runBoy/runBoy10.png",	//runBoy10
};

//プレイヤークラス
class Player
{
	private:	//メンバ変数一覧
		int PlayerHandle[PLAYER_NUM];	//画像ハンドル
		int HandleIndex;				//画像ハンドルの添え字用変数
		int AnimeFrame;					//画像の再生時間
		bool isReverse;					//アニメーションの逆再生フラグ
		float PosX, PosY;				//X座標,Y座標
		float MoveSpeed;				//移動速度

		//道路画像用変数
		int Road_Handle[2];				//道路の画像ハンドル
		float Road_PosX, Road_PosY;		//X座標,Y座標
		float Road_Speed;				//自動スクロールの速度
		bool RoadIsMove;					//今道路の画像が自動スクロールしているかフラグ

	public:		//メソッド一覧
		Player()	//コンストラクタ(全ての情報をリセット)
		{
			for (int i = 0; i < PLAYER_NUM; i++)
			{
				PlayerHandle[i] = 0;
			}
			HandleIndex = 0;
			AnimeFrame = 0;
			isReverse = false;
			PosX = 0.0f;
			PosY = 0.0f;
			MoveSpeed = 0.0f;

		}

		void InitPlayer()	//プレイヤーの初期化
		{
			//画像の読み込み
			LoadPlayer(PLAYER_1);	//runBoy1
			LoadPlayer(PLAYER_2);	//runBoy2
			LoadPlayer(PLAYER_3);	//runBoy3
			LoadPlayer(PLAYER_4);	//runBoy4
			LoadPlayer(PLAYER_5);	//runBoy5
			LoadPlayer(PLAYER_6);	//runBoy6
			LoadPlayer(PLAYER_7);	//runBoy7
			LoadPlayer(PLAYER_8);	//runBoy8
			LoadPlayer(PLAYER_9);	//runBoy9
			LoadPlayer(PLAYER_10);	//runBoy10
			PosX = 640.0f;			//初期X座標を設定
			PosY = 550.0f;			//初期Y座標を設定
			MoveSpeed = 3.0f;		//初期移動速度を設定
		}

		void StepPlayer()	//プレイヤー通常処理
		{
			MovePlayer();	//プレイヤーの移動処理

			ChangePlayerImage();	//	プレイヤーの画像を変える

			MoveRoad();		//自動スクロール処理
		}

		void DrawPlayer()	//プレイヤー描画処理
		{
			DrawRotaGraph((int)PosX, (int)PosY, 1.0f, 0.0f, PlayerHandle[HandleIndex], true);
		}

		void FinPlayer()	//プレイヤーの後処理
		{
			//画像を破棄
			DeleteGraph(PlayerHandle[0]);
		}

		void LoadPlayer(PLAYER_IMAGE type)	//プレイヤー画像の読み込み
		{
			PlayerHandle[type] = LoadGraph(PlayerImage_Path[type]);
		}

		void MovePlayer()	//プレイヤーの移動処理
		{
			//Dキーまたは右矢印キーを押している間
			if (IsKeyKeep(KEY_INPUT_D) || IsKeyKeep(KEY_INPUT_RIGHT))
			{
				//右に移動する
				PosX += MoveSpeed;

				//画面端まで到達したら
				if (PosX >= 875.0f)
				{
					//それ以上右に行けないようにする
					PosX = 875.0f;
				}
			}

			//Aキーまたは左矢印キーを押している間
			else if (IsKeyKeep(KEY_INPUT_A) || IsKeyKeep(KEY_INPUT_LEFT))
			{
				//左に移動する
				PosX -= MoveSpeed;

				//画面端まで到達したら
				if (PosX <= 405.0f)
				{
					//それ以上左に行けないようにする
					PosX = 405.0f;
				}
			}
		}

		void ChangePlayerImage()	//プレイヤーの画像を変える
		{
			AnimeFrame++;	//再生時間をカウント
			if (AnimeFrame >= FRAME_TIME / 2)	//一定の時間に達したら
			{
				AnimeFrame = 0;		//再生時間をリセット

				if (!isReverse)		//逆再生フラグがfalseなら
				{
					if (HandleIndex == 9)	//最後の画像なら
					{
						isReverse = true;	//逆再生にする
						HandleIndex = 8;	//1つ前の画像にする
					}

					else	//最後の画像でないなら
					{
						HandleIndex++;	//次の画像に切り替える
					}
				}

				else
				{
					if (HandleIndex == 0)	//最初の画像なら
					{
						isReverse = false;	//通常再生にする
						HandleIndex = 1;	//1つ次の画像にする
					}

					else	//最初の画像でないなら
					{
						HandleIndex--;	//前の画像に切り替える
					}
				}
			}
		}

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
				DrawGraph(Road_PosX, Road_PosY - i * 720, Road_Handle[i], true);
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

		void FinRoad()		//道路画像破棄
		{
			for (int i = 0; i < 2; i++)
			{
				DeleteGraph(Road_Handle[i]);
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
