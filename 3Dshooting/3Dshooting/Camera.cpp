#include "Camera.h"
#include <DxLib.h>
#define PI 3.1415926
#include "CheckKeyh.h"
#include <math.h>
#define CAMERA_ANGLE_SPEED 0.05f
#define CAMERA_PLAYER_TARGET_HEIGHT 50.0f //�v���C���[����ǂꂭ�炢�̍����𒍎��_�ɂ��邩
#define CAMERA_PLAYER_LENGTH 200.0f //�v���C���[�ƃJ�����Ƃ̋���
#define CAMERA_COLLISION_SIZE 50.0f //�J�����̓����蔻��T�C�Y

Camera::Camera(const Player& player,VECTOR eye)
{
	angleH = DX_PI_F;
	angleV = 0.0f;
	lookAt = player.GetVector();
	lookAt.y += 50.0f;
	SetCameraPositionAndTargetAndUpVec(eye, lookAt, VGet(0, 1, 0));

	//�J�����̃N���b�v�w��
	SetCameraNearFar(10, 100000);

	//����p��ݒ�
	SetupCamera_Perspective(PI/3);
}


Camera::~Camera()
{
}

//�J��������֐�
void Camera::CameraControl(const Player& player)const
{
}

//�J������]�֐�
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
	// �p�b�h�̂R�{�^�����A�V�t�g�L�[��������Ă���ꍇ�̂݊p�x�ύX������s��
	if (CheckHitKey(KEY_INPUT_LSHIFT) || (*nowInput & PAD_INPUT_C))
	{
		// �u���v�{�^����������Ă����琅���p�x���}�C�i�X����
		if (*nowInput & PAD_INPUT_LEFT)
		{
			angleH -= CAMERA_ANGLE_SPEED;

			// �|�P�W�O�x�ȉ��ɂȂ�����p�x�l���傫���Ȃ肷���Ȃ��悤�ɂR�U�O�x�𑫂�
			if (angleH < -DX_PI_F)
			{
				angleH += DX_TWO_PI_F;
			}
		}

		// �u���v�{�^����������Ă����琅���p�x���v���X����
		if (*nowInput & PAD_INPUT_RIGHT)
		{
			angleH += CAMERA_ANGLE_SPEED;

			// �P�W�O�x�ȏ�ɂȂ�����p�x�l���傫���Ȃ肷���Ȃ��悤�ɂR�U�O�x������
			if (angleH > DX_PI_F)
			{
				angleH -= DX_TWO_PI_F;
			}
		}

		// �u���v�{�^����������Ă����琂���p�x���}�C�i�X����
		if (*nowInput & PAD_INPUT_UP)
		{
			angleV -= CAMERA_ANGLE_SPEED;

			// ������p�x�ȉ��ɂ͂Ȃ�Ȃ��悤�ɂ���
			if (angleV < -DX_PI_F / 2.0f + 0.6f)
			{
				angleV = -DX_PI_F / 2.0f + 0.6f;
			}
		}

		// �u���v�{�^����������Ă����琂���p�x���v���X����
		if (*nowInput & PAD_INPUT_DOWN)
		{
			angleV += CAMERA_ANGLE_SPEED;

			// ������p�x�ȏ�ɂ͂Ȃ�Ȃ��悤�ɂ���
			if (angleV > DX_PI_F / 2.0f - 0.6f)
			{
				angleV = DX_PI_F / 2.0f - 0.6f;
			}
		}
	}

	// �J�����̒����_�̓v���C���[���W����K��l���������W
	lookAt = VAdd(player->GetVector(), VGet(0.0f, CAMERA_PLAYER_TARGET_HEIGHT, 0.0f));

	// �J�����̍��W�����肷��
	{
		MATRIX RotZ, RotY;
		float Camera_Player_Length;
		MV1_COLL_RESULT_POLY_DIM HRes;
		int HitNum;

		// ���������̉�]�͂x����]
		RotY = MGetRotY(angleH);

		// ���������̉�]�͂y����] )
		RotZ = MGetRotZ(angleV);

		// �J��������v���C���[�܂ł̏����������Z�b�g
		Camera_Player_Length = CAMERA_PLAYER_LENGTH;

		// �J�����̍��W���Z�o
		// �w���ɃJ�����ƃv���C���[�Ƃ̋����������L�т��x�N�g����
		// ����������]( �y����] )���������Ɛ���������]( �x����] )���čX��
		// �����_�̍��W�𑫂������̂��J�����̍��W
		*eye = VAdd(VTransform(VTransform(VGet(-Camera_Player_Length, 0.0f, 0.0f), RotZ), RotY), lookAt);

		// �����_����J�����̍��W�܂ł̊ԂɃX�e�[�W�̃|���S�������邩���ׂ�
		HRes = MV1CollCheck_Capsule(stage->GetModelHandle(), -1, lookAt, *eye, CAMERA_COLLISION_SIZE);
		HitNum = HRes.HitNum;
		MV1CollResultPolyDimTerminate(HRes);
		if (HitNum != 0)
		{
			float NotHitLength;
			float HitLength;
			float TestLength;
			VECTOR TestPosition;

			// �������疳���ʒu�܂Ńv���C���[�ɋ߂Â�

			// �|���S���ɓ�����Ȃ��������Z�b�g
			NotHitLength = 0.0f;

			// �|���S���ɓ����鋗�����Z�b�g
			HitLength = Camera_Player_Length;
			do
			{
				// �����邩�ǂ����e�X�g���鋗�����Z�b�g( ������Ȃ������Ɠ����鋗���̒��� )
				TestLength = NotHitLength + (HitLength - NotHitLength) / 2.0f;

				// �e�X�g�p�̃J�������W���Z�o
				TestPosition = VAdd(VTransform(VTransform(VGet(-TestLength, 0.0f, 0.0f), RotZ), RotY), lookAt);

				// �V�������W�ŕǂɓ����邩�e�X�g
				HRes = MV1CollCheck_Capsule(stage->GetModelHandle(), -1, lookAt, TestPosition, CAMERA_COLLISION_SIZE);
				HitNum = HRes.HitNum;
				MV1CollResultPolyDimTerminate(HRes);
				if (HitNum != 0)
				{
					// ���������瓖���鋗���� TestLength �ɕύX����
					HitLength = TestLength;
				}
				else
				{
					// ������Ȃ������瓖����Ȃ������� TestLength �ɕύX����
					NotHitLength = TestLength;
				}

				// HitLength �� NoHitLength ���\���ɋ߂Â��Ă��Ȃ������烋�[�v
			} while (HitLength - NotHitLength > 0.1f);

			// �J�����̍��W���Z�b�g
			*eye = TestPosition;
		}
	}

	// �J�����̏������C�u�����̃J�����ɔ��f������
	SetCameraPositionAndTarget_UpVecY(*eye, lookAt);
}