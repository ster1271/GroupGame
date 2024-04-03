#pragma once

#define PLAYER_PATH		("Data/PlayImage/Player.png")	//プレイヤー画像(仮)のパス

//プレイヤークラス
class Player
{
	private:	//メンバ変数一覧
		int PlayerHandle;	//画像ハンドル
		float PosX, PosY;	//X座標,Y座標
		float MoveSpeed;	//移動速度

	public:		//メソッド一覧
		Player()	//コンストラクタ(全ての情報をリセット)
		{
			PlayerHandle = 0;
			PosX = 0.0f;
			PosY = 0.0f;
			MoveSpeed = 0.0f;
		}

		void InitPlayer()	//プレイヤーの初期化
		{
			PlayerHandle = LoadGraph(PLAYER_PATH);	//画像の読み込み
			PosX = 320.0f;		//初期X座標を設定
			PosY = 400.0f;		//初期Y座標を設定
			MoveSpeed = 3.0f;	//初期移動速度を設定
		}

		void StepPlayer()	//プレイヤー通常処理
		{
			//Dキーまたは右矢印キーを押している間
			if (IsKeyKeep(KEY_INPUT_D) || IsKeyKeep(KEY_INPUT_RIGHT))
			{
				//右に移動する
				PosX += MoveSpeed;

				//画面端まで到達したら
				if (PosX >= 624.0f)
				{
					//それ以上右に行けないようにする
					PosX = 624.0f;
				}
			}

			//Aキーまたは左矢印キーを押している間
			else if (IsKeyKeep(KEY_INPUT_A) || IsKeyKeep(KEY_INPUT_LEFT))
			{
				//左に移動する
				PosX -= MoveSpeed;

				//画面端まで到達したら
				if (PosX <= 16.0f)
				{
					//それ以上左に行けないようにする
					PosX = 16.0f;
				}
			}
		}

		void DrawPlayer()	//プレイヤー描画処理
		{
			DrawRotaGraph((int)PosX, (int)PosY, 1.0f, 0.0f, PlayerHandle, true);
		}

		void FinPlayer()	//プレイヤーの後処理
		{
			//画像を破棄
			DeleteGraph(PlayerHandle);
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
