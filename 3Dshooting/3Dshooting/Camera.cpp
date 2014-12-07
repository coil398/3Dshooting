#include "Camera.h"
#include <DxLib.h>
#define PI 3.1415926
#include "CheckKeyh.h"
#include <math.h>
#define CAMERA_ANGLE_SPEED 0.05f
#define CAMERA_PLAYER_TARGET_HEIGHT 50.0f //プレイヤーからどれくらいの高さを注視点にするか
#define CAMERA_PLAYER_LENGTH 200.0f //プレイヤーとカメラとの距離
#define CAMERA_COLLISION_SIZE 50.0f //カメラの当たり判定サイズ

Camera::Camera(const Player& player,VECTOR eye)
{
	angleH = DX_PI_F;
	angleV = 0.0f;
	lookAt = player.GetVector();
	lookAt.y += 50.0f;
	SetCameraPositionAndTargetAndUpVec(eye, lookAt, VGet(0, 1, 0));

	//カメラのクリップ指定
	SetCameraNearFar(10, 1000);

	//視野角を設定
	SetupCamera_Perspective(PI/3);
}


Camera::~Camera()
{
}

//カメラ操作関数
void Camera::CameraControl(const Player& player)const
{
}

//カメラ回転関数
void Camera::RotCamera(const VECTOR& vPlayer, VECTOR *vCamera, float arg)
{

}

void Camera::AddX(float x)
{
	vCamera.x += x;
}

void Camera::AddY(float y)
{
	vCamera.y += y;
}

void Camera::AddZ(float z)
{
	vCamera.z += z;
}

void Camera::Process(int *nowInput,Player* player,VECTOR* eye,BackGround* stage)
{
	// パッドの３ボタンか、シフトキーが押されている場合のみ角度変更操作を行う
	if (CheckHitKey(KEY_INPUT_LSHIFT) || (*nowInput & PAD_INPUT_C))
	{
		// 「←」ボタンが押されていたら水平角度をマイナスする
		if (*nowInput & PAD_INPUT_LEFT)
		{
			angleH -= CAMERA_ANGLE_SPEED;

			// －１８０度以下になったら角度値が大きくなりすぎないように３６０度を足す
			if (angleH < -DX_PI_F)
			{
				angleH += DX_TWO_PI_F;
			}
		}

		// 「→」ボタンが押されていたら水平角度をプラスする
		if (*nowInput & PAD_INPUT_RIGHT)
		{
			angleH += CAMERA_ANGLE_SPEED;

			// １８０度以上になったら角度値が大きくなりすぎないように３６０度を引く
			if (angleH > DX_PI_F)
			{
				angleH -= DX_TWO_PI_F;
			}
		}

		// 「↑」ボタンが押されていたら垂直角度をマイナスする
		if (*nowInput & PAD_INPUT_UP)
		{
			angleV -= CAMERA_ANGLE_SPEED;

			// ある一定角度以下にはならないようにする
			if (angleV < -DX_PI_F / 2.0f + 0.6f)
			{
				angleV = -DX_PI_F / 2.0f + 0.6f;
			}
		}

		// 「↓」ボタンが押されていたら垂直角度をプラスする
		if (*nowInput & PAD_INPUT_DOWN)
		{
			angleV += CAMERA_ANGLE_SPEED;

			// ある一定角度以上にはならないようにする
			if (angleV > DX_PI_F / 2.0f - 0.6f)
			{
				angleV = DX_PI_F / 2.0f - 0.6f;
			}
		}
	}

	// カメラの注視点はプレイヤー座標から規定値分高い座標
	lookAt = VAdd(player->GetVector(), VGet(0.0f, CAMERA_PLAYER_TARGET_HEIGHT, 0.0f));

	// カメラの座標を決定する
	{
		MATRIX RotZ, RotY;
		float Camera_Player_Length;
		MV1_COLL_RESULT_POLY_DIM HRes;
		int HitNum;

		// 水平方向の回転はＹ軸回転
		RotY = MGetRotY(angleH);

		// 垂直方向の回転はＺ軸回転 )
		RotZ = MGetRotZ(angleV);

		// カメラからプレイヤーまでの初期距離をセット
		Camera_Player_Length = CAMERA_PLAYER_LENGTH;

		// カメラの座標を算出
		// Ｘ軸にカメラとプレイヤーとの距離分だけ伸びたベクトルを
		// 垂直方向回転( Ｚ軸回転 )させたあと水平方向回転( Ｙ軸回転 )して更に
		// 注視点の座標を足したものがカメラの座標
		*eye = VAdd(VTransform(VTransform(VGet(-Camera_Player_Length, 0.0f, 0.0f), RotZ), RotY), lookAt);

		// 注視点からカメラの座標までの間にステージのポリゴンがあるか調べる
		HRes = MV1CollCheck_Capsule(stage->GetModelHandle(), -1, lookAt, *eye, CAMERA_COLLISION_SIZE);
		HitNum = HRes.HitNum;
		MV1CollResultPolyDimTerminate(HRes);
		if (HitNum != 0)
		{
			float NotHitLength;
			float HitLength;
			float TestLength;
			VECTOR TestPosition;

			// あったら無い位置までプレイヤーに近づく

			// ポリゴンに当たらない距離をセット
			NotHitLength = 0.0f;

			// ポリゴンに当たる距離をセット
			HitLength = Camera_Player_Length;
			do
			{
				// 当たるかどうかテストする距離をセット( 当たらない距離と当たる距離の中間 )
				TestLength = NotHitLength + (HitLength - NotHitLength) / 2.0f;

				// テスト用のカメラ座標を算出
				TestPosition = VAdd(VTransform(VTransform(VGet(-TestLength, 0.0f, 0.0f), RotZ), RotY), lookAt);

				// 新しい座標で壁に当たるかテスト
				HRes = MV1CollCheck_Capsule(stage->GetModelHandle(), -1, lookAt, TestPosition, CAMERA_COLLISION_SIZE);
				HitNum = HRes.HitNum;
				MV1CollResultPolyDimTerminate(HRes);
				if (HitNum != 0)
				{
					// 当たったら当たる距離を TestLength に変更する
					HitLength = TestLength;
				}
				else
				{
					// 当たらなかったら当たらない距離を TestLength に変更する
					NotHitLength = TestLength;
				}

				// HitLength と NoHitLength が十分に近づいていなかったらループ
			} while (HitLength - NotHitLength > 0.1f);

			// カメラの座標をセット
			*eye = TestPosition;
		}
	}

	// カメラの情報をライブラリのカメラに反映させる
	SetCameraPositionAndTarget_UpVecY(*eye, lookAt);
}