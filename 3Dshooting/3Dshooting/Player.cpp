#include "Player.h"
#include "DXlib.h"
#include "CheckKeyh.h"
#include <math.h>

#define PLAYER_MOVE_SPEED 50.0f
#define PLAYER_ANGLE_SPEED 0.2f
#define PLAYER_MAX_HITCOLL 2048	// 処理するコリジョンポリゴンの最大数
#define PLAYER_ENUM_DEFAULT_SIZE 800.0f // 周囲のポリゴン検出に使用する球の初期サイズ
#define PLAYER_HIT_WIDTH 200.0f // 当たり判定カプセルの半径
#define PLAYER_HIT_HEIGHT 700.0f // 当たり判定カプセルの高さ
#define PLAYER_HIT_TRYNUM 16 // 壁押し出し処理の最大試行回数
#define PLAYER_HIT_SLIDE_LENGTH	5.0f // 一度の壁押し出し処理でスライドさせる距離

void PlayerAngle(Player* player);

Player::Player(float x, float y, float z,float angle,int hp) :Character(x,y,z,angle,hp)
{
	//3Dモデル読み込み
	PlayerModelHandle = MV1LoadModel("../materials/model/marisa/marisa.pmx");
	if (PlayerModelHandle == -1)return;

	PlayerMaterialNum = MV1GetMaterialNum(PlayerModelHandle);
	for (int i = 0; i < PlayerMaterialNum; i++)
	{
		dotWidth = MV1GetMaterialOutLineDotWidth(PlayerModelHandle, i);
		MV1SetMaterialOutLineDotWidth(PlayerModelHandle, i, dotWidth / 5.0f);
	}
	return;
}


Player::~Player()
{
	MV1DeleteModel(PlayerModelHandle);
}

void Player::Move()
{

}

void Player::Rot()
{
	//特になし
}

void Player::Draw()
{
	//3Dモデルの移動
	MV1SetPosition(GetModelHandle(), VGet(GetX(), GetY(), GetZ()));
	//3Dモデルの描画
	MV1DrawModel(GetModelHandle());
}

int Player::GetModelHandle()
{
	return PlayerModelHandle;
}

void Player::SetModelHandle(int ModelHandle)
{
	this->PlayerModelHandle = ModelHandle;
}

void Player::Process(int* nowInput,int* edgeInput,Player* player,VECTOR eye,BackGround* stage)
{
	VECTOR UpMoveVec;  // 方向ボタン「↑」を入力をしたときのプレイヤーの移動方向ベクトル
	VECTOR LeftMoveVec; // 方向ボタン「←」を入力をしたときのプレイヤーの移動方向ベクトル
	VECTOR MoveVec;	// このフレームの移動ベクトル
	int MoveFlag; // 移動したかどうかのフラグ( 1:移動した  0:移動していない )

	/*
	// ルートフレームのＺ軸方向の移動パラメータを無効にする
	{
		MATRIX LocalMatrix;

		// ユーザー行列を解除する
		MV1ResetFrameUserLocalMatrix(PlayerModelHandle, 2);

		// 現在のルートフレームの行列を取得する
		LocalMatrix = MV1GetFrameLocalMatrix(PlayerModelHandle, 2);

		// Ｚ軸方向の平行移動成分を無効にする
		LocalMatrix.m[3][2] = 0.0f;

		// ユーザー行列として平行移動成分を無効にした行列をルートフレームにセットする
		MV1SetFrameUserLocalMatrix(PlayerModelHandle, 2, LocalMatrix);
	}
	*/

	// プレイヤーの移動方向のベクトルを算出
	{
		// 方向ボタン「↑」を押したときのプレイヤーの移動ベクトルはカメラの視線方向ベクトル
		UpMoveVec = VSub(player->GetVector(), eye);
		UpMoveVec.y = 0.0f;
		

		// 方向ボタン「←」を押したときのプレイヤーの移動ベクトルは上を押したときの方向ベクトルとＹ軸のプラス方向のベクトルに垂直な方向
		LeftMoveVec = VCross(UpMoveVec, VGet(0.0f, 1.0f, 0.0f));

		// 二つのベクトルを正規化
		//UpMoveVec = VNorm(UpMoveVec);
		//LeftMoveVec = VNorm(LeftMoveVec);
	}

	// このフレームでの移動ベクトルを初期化
	MoveVec = VGet(0.0f, 0.0f, 0.0f);

	// 移動したかどうかのフラグを初期状態では「移動していない」を表す０にする
	MoveFlag = 0;

	// パッドの３ボタンと左シフトがどちらも押されていなかったらプレイヤーの移動処理
	if (CheckHitKey(KEY_INPUT_LSHIFT) == 0 && (*nowInput & PAD_INPUT_C) == 0)
	{
		// 方向ボタン「←」が入力されたらカメラの見ている方向から見て左方向に移動する
		if (*nowInput & PAD_INPUT_LEFT)
		{
			// 移動ベクトルに「←」が入力された時の移動ベクトルを加算する
			MoveVec = VAdd(MoveVec, LeftMoveVec);

			// 移動したかどうかのフラグを「移動した」にする
			MoveFlag = 1;
		}
		else
			// 方向ボタン「→」が入力されたらカメラの見ている方向から見て右方向に移動する
			if (*nowInput & PAD_INPUT_RIGHT)
			{
				// 移動ベクトルに「←」が入力された時の移動ベクトルを反転したものを加算する
				MoveVec = VAdd(MoveVec, VScale(LeftMoveVec, -1.0f));

				// 移動したかどうかのフラグを「移動した」にする
				MoveFlag = 1;
			}

		// 方向ボタン「↑」が入力されたらカメラの見ている方向に移動する
		if (*nowInput & PAD_INPUT_UP)
		{
			// 移動ベクトルに「↑」が入力された時の移動ベクトルを加算する
			MoveVec = VAdd(MoveVec, UpMoveVec);

			// 移動したかどうかのフラグを「移動した」にする
			MoveFlag = 1;
		}
		else
			// 方向ボタン「↓」が入力されたらカメラの方向に移動する
			if (*nowInput & PAD_INPUT_DOWN)
			{
				// 移動ベクトルに「↑」が入力された時の移動ベクトルを反転したものを加算する
				MoveVec = VAdd(MoveVec, VScale(UpMoveVec, -1.0f));

				// 移動したかどうかのフラグを「移動した」にする
				MoveFlag = 1;
			}
	}

	// 移動ボタンが押されたかどうかで処理を分岐
	if (MoveFlag)
	{
		// 移動ベクトルを正規化したものをプレイヤーが向くべき方向として保存
		targetMoveDirection = VNorm(MoveVec);

		// プレイヤーが向くべき方向ベクトルをプレイヤーのスピード倍したものを移動ベクトルとする
		MoveVec = VScale(player->targetMoveDirection, PLAYER_MOVE_SPEED);

	}

	//プレイヤーの移動方向にモデルの方向を近づける
	{
		float TargetAngle;			// 目標角度
		float SaAngle;				// 目標角度と現在の角度との差

		// 目標の方向ベクトルから角度値を算出する
		TargetAngle = atan2(player->GetTargetMoveDirection().x, player->GetTargetMoveDirection().z);

		// 目標の角度と現在の角度との差を割り出す
		{
			// 最初は単純に引き算
			SaAngle = TargetAngle - player->GetAngle();

			// ある方向からある方向の差が１８０度以上になることは無いので
			// 差の値が１８０度以上になっていたら修正する
			if (SaAngle < -DX_PI_F)
			{
				SaAngle += DX_TWO_PI_F;
			}
			else
				if (SaAngle > DX_PI_F)
				{
					SaAngle -= DX_TWO_PI_F;
				}
		}

		// 角度の差が０に近づける
		if (SaAngle > 0.0f)
		{
			// 差がプラスの場合は引く
			SaAngle -= PLAYER_ANGLE_SPEED;
			if (SaAngle < 0.0f)
			{
				SaAngle = 0.0f;
			}
		}
		else
		{
			// 差がマイナスの場合は足す
			SaAngle += PLAYER_ANGLE_SPEED;
			if (SaAngle > 0.0f)
			{
				SaAngle = 0.0f;
			}
		}

		// モデルの角度を更新
		player->SetAngle(TargetAngle - SaAngle);
		MV1SetRotationXYZ(player->GetModelHandle(), VGet(0.0f, player->GetAngle() + DX_PI_F, 0.0f));
	}

	//移動ベクトルを元にプレイヤーを移動
	{
		int i, j, k;						// 汎用カウンタ変数
		int MoveFlag;						// 水平方向に移動したかどうかのフラグ( ０:移動していない  １:移動した )
		int HitFlag;						// ポリゴンに当たったかどうかを記憶しておくのに使う変数( ０:当たっていない  １:当たった )
		MV1_COLL_RESULT_POLY_DIM HitDim;			// プレイヤーの周囲にあるポリゴンを検出した結果が代入される当たり判定結果構造体
		int KabeNum;						// 壁ポリゴンと判断されたポリゴンの数
		int YukaNum;						// 床ポリゴンと判断されたポリゴンの数
		MV1_COLL_RESULT_POLY *Kabe[PLAYER_MAX_HITCOLL];	// 壁ポリゴンと判断されたポリゴンの構造体のアドレスを保存しておくためのポインタ配列
		MV1_COLL_RESULT_POLY *Yuka[PLAYER_MAX_HITCOLL];	// 床ポリゴンと判断されたポリゴンの構造体のアドレスを保存しておくためのポインタ配列
		MV1_COLL_RESULT_POLY *Poly;				// ポリゴンの構造体にアクセスするために使用するポインタ( 使わなくても済ませられますがプログラムが長くなるので・・・ )
		HITRESULT_LINE LineRes;				// 線分とポリゴンとの当たり判定の結果を代入する構造体
		VECTOR OldPos;						// 移動前の座標	
		VECTOR NowPos;						// 移動後の座標

		// 移動前の座標を保存
		OldPos = player->GetVector();

		// 移動後の座標を算出
		NowPos = VAdd(player->GetVector(), MoveVec);

		// プレイヤーの周囲にあるステージポリゴンを取得する
		// ( 検出する範囲は移動距離も考慮する )
		HitDim = MV1CollCheck_Sphere(stage->GetModelHandle(), -1, player->GetVector(), PLAYER_ENUM_DEFAULT_SIZE + VSize(MoveVec));

		// x軸かy軸方向に 0.01f 以上移動した場合は「移動した」フラグを１にする
		if (fabs(MoveVec.x) > 0.01f || fabs(MoveVec.z) > 0.01f)
		{
			MoveFlag = 1;
		}
		else
		{
			MoveFlag = 0;
		}

		// 検出されたポリゴンが壁ポリゴン( ＸＺ平面に垂直なポリゴン )か床ポリゴン( ＸＺ平面に垂直ではないポリゴン )かを判断する
	{
		// 壁ポリゴンと床ポリゴンの数を初期化する
		KabeNum = 0;
		YukaNum = 0;

		// 検出されたポリゴンの数だけ繰り返し
		for (i = 0; i < HitDim.HitNum; i++)
		{
			// ＸＺ平面に垂直かどうかはポリゴンの法線のＹ成分が０に限りなく近いかどうかで判断する
			if (HitDim.Dim[i].Normal.y < 0.000001f && HitDim.Dim[i].Normal.y > -0.000001f)
			{
				// 壁ポリゴンと判断された場合でも、プレイヤーのＹ座標＋１．０ｆより高いポリゴンのみ当たり判定を行う
				if (HitDim.Dim[i].Position[0].y > player->GetVector().y + 1.0f ||
					HitDim.Dim[i].Position[1].y > player->GetVector().y + 1.0f ||
					HitDim.Dim[i].Position[2].y > player->GetVector().y + 1.0f)
				{
					// ポリゴンの数が列挙できる限界数に達していなかったらポリゴンを配列に追加
					if (KabeNum < PLAYER_MAX_HITCOLL)
					{
						// ポリゴンの構造体のアドレスを壁ポリゴンポインタ配列に保存する
						Kabe[KabeNum] = &HitDim.Dim[i];

						// 壁ポリゴンの数を加算する
						KabeNum++;
					}
				}
			}
			else
			{
				// ポリゴンの数が列挙できる限界数に達していなかったらポリゴンを配列に追加
				if (YukaNum < PLAYER_MAX_HITCOLL)
				{
					// ポリゴンの構造体のアドレスを床ポリゴンポインタ配列に保存する
					Yuka[YukaNum] = &HitDim.Dim[i];

					// 床ポリゴンの数を加算する
					YukaNum++;
				}
			}
		}
	}

	// 壁ポリゴンとの当たり判定処理
	if (KabeNum != 0)
	{
		// 壁に当たったかどうかのフラグは初期状態では「当たっていない」にしておく
		HitFlag = 0;

		// 移動したかどうかで処理を分岐
		if (MoveFlag == 1)
		{
			// 壁ポリゴンの数だけ繰り返し
			for (i = 0; i < KabeNum; i++)
			{
				// i番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
				Poly = Kabe[i];

				// ポリゴンとプレイヤーが当たっていなかったら次のカウントへ
				if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == FALSE) continue;

				// ここにきたらポリゴンとプレイヤーが当たっているということなので、ポリゴンに当たったフラグを立てる
				HitFlag = 1;

				// 壁に当たったら壁に遮られない移動成分分だけ移動する
				{
					VECTOR SlideVec;	// プレイヤーをスライドさせるベクトル

					// 進行方向ベクトルと壁ポリゴンの法線ベクトルに垂直なベクトルを算出
					SlideVec = VCross(MoveVec, Poly->Normal);

					// 算出したベクトルと壁ポリゴンの法線ベクトルに垂直なベクトルを算出、これが
					// 元の移動成分から壁方向の移動成分を抜いたベクトル
					SlideVec = VCross(Poly->Normal, SlideVec);

					// それを移動前の座標に足したものを新たな座標とする
					NowPos = VAdd(OldPos, SlideVec);
				}

				// 新たな移動座標で壁ポリゴンと当たっていないかどうかを判定する
				for (j = 0; j < KabeNum; j++)
				{
					// j番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
					Poly = Kabe[j];

					// 当たっていたらループから抜ける
					if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == TRUE) break;
				}

				// j が KabeNum だった場合はどのポリゴンとも当たらなかったということなので
				// 壁に当たったフラグを倒した上でループから抜ける
				if (j == KabeNum)
				{
					HitFlag = 0;
					break;
				}
			}
		}
		else
		{
			// 移動していない場合の処理

			// 壁ポリゴンの数だけ繰り返し
			for (i = 0; i < KabeNum; i++)
			{
				// i番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
				Poly = Kabe[i];

				// ポリゴンに当たっていたら当たったフラグを立てた上でループから抜ける
				if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == TRUE)
				{
					HitFlag = 1;
					break;
				}
			}
		}

		// 壁に当たっていたら壁から押し出す処理を行う
		if (HitFlag == 1)
		{
			// 壁からの押し出し処理を試みる最大数だけ繰り返し
			for (k = 0; k < PLAYER_HIT_TRYNUM; k++)
			{
				// 壁ポリゴンの数だけ繰り返し
				for (i = 0; i < KabeNum; i++)
				{
					// i番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
					Poly = Kabe[i];

					// プレイヤーと当たっているかを判定
					if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == FALSE) continue;

					// 当たっていたら規定距離分プレイヤーを壁の法線方向に移動させる
					NowPos = VAdd(NowPos, VScale(Poly->Normal, PLAYER_HIT_SLIDE_LENGTH));

					// 移動した上で壁ポリゴンと接触しているかどうかを判定
					for (j = 0; j < KabeNum; j++)
					{
						// 当たっていたらループを抜ける
						Poly = Kabe[j];
						if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == TRUE) break;
					}

					// 全てのポリゴンと当たっていなかったらここでループ終了
					if (j == KabeNum) break;
				}

				// i が KabeNum ではない場合は全部のポリゴンで押し出しを試みる前に全ての壁ポリゴンと接触しなくなったということなのでループから抜ける
				if (i != KabeNum) break;
			}
		}
	}

	
	// 床ポリゴンとの当たり判定
	if (YukaNum != 0)
	{
		/*
		// ジャンプ中且つ上昇中の場合は処理を分岐
		if (pl.State == 2 && pl.JumpPower > 0.0f)
		{
			float MinY;

			// 天井に頭をぶつける処理を行う

			// 一番低い天井にぶつける為の判定用変数を初期化
			MinY = 0.0f;

			// 当たったかどうかのフラグを当たっていないを意味する０にしておく
			HitFlag = 0;

			// 床ポリゴンの数だけ繰り返し
			for (i = 0; i < YukaNum; i++)
			{
				// i番目の床ポリゴンのアドレスを床ポリゴンポインタ配列から取得
				Poly = Yuka[i];

				// 足先から頭の高さまでの間でポリゴンと接触しているかどうかを判定
				LineRes = HitCheck_Line_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), Poly->Position[0], Poly->Position[1], Poly->Position[2]);

				// 接触していなかったら何もしない
				if (LineRes.HitFlag == FALSE) continue;

				// 既にポリゴンに当たっていて、且つ今まで検出した天井ポリゴンより高い場合は何もしない
				if (HitFlag == 1 && MinY < LineRes.Position.y) continue;

				// ポリゴンに当たったフラグを立てる
				HitFlag = 1;

				// 接触したＹ座標を保存する
				MinY = LineRes.Position.y;
			}

			// 接触したポリゴンがあったかどうかで処理を分岐
			if (HitFlag == 1)
			{
				// 接触した場合はプレイヤーのＹ座標を接触座標を元に更新
				NowPos.y = MinY - PLAYER_HIT_HEIGHT;

				// Ｙ軸方向の速度は反転
				pl.JumpPower = -pl.JumpPower;
			}
		}
		*/
		//else
		{
			float MaxY;

			// 下降中かジャンプ中ではない場合の処理

			// 床ポリゴンに当たったかどうかのフラグを倒しておく
			HitFlag = 0;

			// 一番高い床ポリゴンにぶつける為の判定用変数を初期化
			MaxY = 0.0f;

			// 床ポリゴンの数だけ繰り返し
			for (i = 0; i < YukaNum; i++)
			{
				// i番目の床ポリゴンのアドレスを床ポリゴンポインタ配列から取得
				Poly = Yuka[i];

				/*
				// ジャンプ中かどうかで処理を分岐
				if (pl.State == 2)
				{
					// ジャンプ中の場合は頭の先から足先より少し低い位置の間で当たっているかを判定
					LineRes = HitCheck_Line_Triangle(VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), VAdd(NowPos, VGet(0.0f, -1.0f, 0.0f)), Poly->Position[0], Poly->Position[1], Poly->Position[2]);
				}
				*/
				//else
				{
					// 走っている場合は頭の先からそこそこ低い位置の間で当たっているかを判定( 傾斜で落下状態に移行してしまわない為 )
					LineRes = HitCheck_Line_Triangle(VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), VAdd(NowPos, VGet(0.0f, -40.0f, 0.0f)), Poly->Position[0], Poly->Position[1], Poly->Position[2]);
				}

				// 当たっていなかったら何もしない
				if (LineRes.HitFlag == FALSE) continue;

				// 既に当たったポリゴンがあり、且つ今まで検出した床ポリゴンより低い場合は何もしない
				if (HitFlag == 1 && MaxY > LineRes.Position.y) continue;

				// ポリゴンに当たったフラグを立てる
				HitFlag = 1;

				// 接触したＹ座標を保存する
				MaxY = LineRes.Position.y;
			}

			// 床ポリゴンに当たったかどうかで処理を分岐
			if (HitFlag == 1)
			{
				// 当たった場合

				// 接触したポリゴンで一番高いＹ座標をプレイヤーのＹ座標にする
				NowPos.y = MaxY;

				// Ｙ軸方向の移動速度は０に
				//pl.JumpPower = 0.0f;

				/*
				// もしジャンプ中だった場合は着地状態にする
				if (pl.State == 2)
				{
					// 移動していたかどうかで着地後の状態と再生するアニメーションを分岐する
					if (MoveFlag)
					{
						// 移動している場合は走り状態に
						Player_PlayAnim(1);
						pl.State = 1;
					}
					else
					{
						// 移動していない場合は立ち止り状態に
						Player_PlayAnim(4);
						pl.State = 0;
					}

					// 着地時はアニメーションのブレンドは行わない
					pl.AnimBlendRate = 1.0f;
				}
				*/
			}
			else
			{
				/*
				// 床コリジョンに当たっていなくて且つジャンプ状態ではなかった場合は
				if (pl.State != 2)
				{
					// ジャンプ中にする
					pl.State = 2;

					// ちょっとだけジャンプする
					pl.JumpPower = PLAYER_FALL_UP_POWER;

					// アニメーションは落下中のものにする
					Player_PlayAnim(3);
				}
				*/
			}
		}
	}

	// 新しい座標を保存する
	player->SetVector(NowPos);

	// プレイヤーのモデルの座標を更新する
	MV1SetPosition(GetModelHandle(), player->GetVector());

	// 検出したプレイヤーの周囲のポリゴン情報を開放する
	MV1CollResultPolyDimTerminate(HitDim);
	}


	/*
	PlayerAnimation(player);
	*/

	aaa(player);

}

void Player::aaa(Player* player)
{
	VECTOR a;
	a = player->GetVector();
}


void PlayerAngle()
{
	/*
	float TargetAngle;			// 目標角度
	float SaAngle;				// 目標角度と現在の角度との差

	// 目標の方向ベクトルから角度値を算出する
	TargetAngle = atan2(player->GetTargetMoveDirection().x, player->GetTargetMoveDirection().z);

	// 目標の角度と現在の角度との差を割り出す
	{
		// 最初は単純に引き算
		SaAngle = TargetAngle - player->GetAngle();

		// ある方向からある方向の差が１８０度以上になることは無いので
		// 差の値が１８０度以上になっていたら修正する
		if (SaAngle < -DX_PI_F)
		{
			SaAngle += DX_TWO_PI_F;
		}
		else
			if (SaAngle > DX_PI_F)
			{
				SaAngle -= DX_TWO_PI_F;
			}
	}

	// 角度の差が０に近づける
	if (SaAngle > 0.0f)
	{
		// 差がプラスの場合は引く
		SaAngle -= PLAYER_ANGLE_SPEED;
		if (SaAngle < 0.0f)
		{
			SaAngle = 0.0f;
		}
	}
	else
	{
		// 差がマイナスの場合は足す
		SaAngle += PLAYER_ANGLE_SPEED;
		if (SaAngle > 0.0f)
		{
			SaAngle = 0.0f;
		}
	}

	// モデルの角度を更新
	player->SetAngle(TargetAngle - SaAngle);
	MV1SetRotationXYZ(player->GetModelHandle(), VGet(0.0f, player->GetAngle() + DX_PI_F, 0.0f));
	*/
}

VECTOR Player::GetTargetMoveDirection()
{
	return targetMoveDirection;
}