#include "Player.h"
#include "DXlib.h"
#include "CheckKeyh.h"
#include <math.h>

#define PLAYER_MOVE_SPEED 30.0f
#define PLAYER_ANGLE_SPEED 0.2f
#define PLAYER_MAX_HITCOLL 2048	// ��������R���W�����|���S���̍ő吔
#define PLAYER_ENUM_DEFAULT_SIZE 800.0f // ���͂̃|���S�����o�Ɏg�p���鋅�̏����T�C�Y
#define PLAYER_HIT_WIDTH 200.0f // �����蔻��J�v�Z���̔��a
#define PLAYER_HIT_HEIGHT 700.0f // �����蔻��J�v�Z���̍���
#define PLAYER_HIT_TRYNUM 16 // �ǉ����o�������̍ő厎�s��
#define PLAYER_HIT_SLIDE_LENGTH	5.0f // ��x�̕ǉ����o�������ŃX���C�h�����鋗��

void PlayerAngle(Player* player);

Player::Player(float x, float y, float z,float angle,int hp) :Character(x,y,z,angle,hp)
{
	//3D���f���ǂݍ���
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
	//���ɂȂ�
}

void Player::Draw()
{
	//3D���f���̈ړ�
	MV1SetPosition(GetModelHandle(), VGet(GetX(), GetY(), GetZ()));
	//3D���f���̕`��
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
	VECTOR UpMoveVec;  // �����{�^���u���v����͂������Ƃ��̃v���C���[�̈ړ������x�N�g��
	VECTOR LeftMoveVec; // �����{�^���u���v����͂������Ƃ��̃v���C���[�̈ړ������x�N�g��
	VECTOR MoveVec;	// ���̃t���[���̈ړ��x�N�g��
	int MoveFlag; // �ړ��������ǂ����̃t���O( 1:�ړ�����  0:�ړ����Ă��Ȃ� )

	// ���[�g�t���[���̂y�������̈ړ��p�����[�^�𖳌��ɂ���
	{
		MATRIX LocalMatrix;

		// ���[�U�[�s�����������
		MV1ResetFrameUserLocalMatrix(PlayerModelHandle, 2);

		// ���݂̃��[�g�t���[���̍s����擾����
		LocalMatrix = MV1GetFrameLocalMatrix(PlayerModelHandle, 2);

		// �y�������̕��s�ړ������𖳌��ɂ���
		LocalMatrix.m[3][2] = 0.0f;

		// ���[�U�[�s��Ƃ��ĕ��s�ړ������𖳌��ɂ����s������[�g�t���[���ɃZ�b�g����
		MV1SetFrameUserLocalMatrix(PlayerModelHandle, 2, LocalMatrix);
	}

	// �v���C���[�̈ړ������̃x�N�g�����Z�o
	{
		// �����{�^���u���v���������Ƃ��̃v���C���[�̈ړ��x�N�g���̓J�����̎�����������x�����𔲂�������
		UpMoveVec = VSub(player->GetVector(), eye);
		UpMoveVec.y = 0.0f;

		// �����{�^���u���v���������Ƃ��̃v���C���[�̈ړ��x�N�g���͏���������Ƃ��̕����x�N�g���Ƃx���̃v���X�����̃x�N�g���ɐ����ȕ���
		LeftMoveVec = VCross(UpMoveVec, VGet(0.0f, 1.0f, 0.0f));

		// ��̃x�N�g���𐳋K��( �x�N�g���̒������P�D�O�ɂ��邱�� )
		UpMoveVec = VNorm(UpMoveVec);
		LeftMoveVec = VNorm(LeftMoveVec);
	}

	// ���̃t���[���ł̈ړ��x�N�g����������
	MoveVec = VGet(0.0f, 0.0f, 0.0f);

	// �ړ��������ǂ����̃t���O��������Ԃł́u�ړ����Ă��Ȃ��v��\���O�ɂ���
	MoveFlag = 0;

	// �p�b�h�̂R�{�^���ƍ��V�t�g���ǂ����������Ă��Ȃ�������v���C���[�̈ړ�����
	if (CheckHitKey(KEY_INPUT_LSHIFT) == 0 && (*nowInput & PAD_INPUT_C) == 0)
	{
		// �����{�^���u���v�����͂��ꂽ��J�����̌��Ă���������猩�č������Ɉړ�����
		if (*nowInput & PAD_INPUT_LEFT)
		{
			// �ړ��x�N�g���Ɂu���v�����͂��ꂽ���̈ړ��x�N�g�������Z����
			MoveVec = VAdd(MoveVec, LeftMoveVec);

			// �ړ��������ǂ����̃t���O���u�ړ������v�ɂ���
			MoveFlag = 1;
		}
		else
			// �����{�^���u���v�����͂��ꂽ��J�����̌��Ă���������猩�ĉE�����Ɉړ�����
			if (*nowInput & PAD_INPUT_RIGHT)
			{
				// �ړ��x�N�g���Ɂu���v�����͂��ꂽ���̈ړ��x�N�g���𔽓]�������̂����Z����
				MoveVec = VAdd(MoveVec, VScale(LeftMoveVec, -1.0f));

				// �ړ��������ǂ����̃t���O���u�ړ������v�ɂ���
				MoveFlag = 1;
			}

		// �����{�^���u���v�����͂��ꂽ��J�����̌��Ă�������Ɉړ�����
		if (*nowInput & PAD_INPUT_UP)
		{
			// �ړ��x�N�g���Ɂu���v�����͂��ꂽ���̈ړ��x�N�g�������Z����
			MoveVec = VAdd(MoveVec, UpMoveVec);

			// �ړ��������ǂ����̃t���O���u�ړ������v�ɂ���
			MoveFlag = 1;
		}
		else
			// �����{�^���u���v�����͂��ꂽ��J�����̕����Ɉړ�����
			if (*nowInput & PAD_INPUT_DOWN)
			{
				// �ړ��x�N�g���Ɂu���v�����͂��ꂽ���̈ړ��x�N�g���𔽓]�������̂����Z����
				MoveVec = VAdd(MoveVec, VScale(UpMoveVec, -1.0f));

				// �ړ��������ǂ����̃t���O���u�ړ������v�ɂ���
				MoveFlag = 1;
			}
	}

	// �ړ��{�^���������ꂽ���ǂ����ŏ����𕪊�
	if (MoveFlag)
	{
		// �ړ��x�N�g���𐳋K���������̂��v���C���[�������ׂ������Ƃ��ĕۑ�
		targetMoveDirection = VNorm(MoveVec);

		// �v���C���[�������ׂ������x�N�g�����v���C���[�̃X�s�[�h�{�������̂��ړ��x�N�g���Ƃ���
		MoveVec = VScale(player->targetMoveDirection, PLAYER_MOVE_SPEED);

	}

	//�v���C���[�̈ړ������Ƀ��f���̕������߂Â���
	{
		float TargetAngle;			// �ڕW�p�x
		float SaAngle;				// �ڕW�p�x�ƌ��݂̊p�x�Ƃ̍�

		// �ڕW�̕����x�N�g������p�x�l���Z�o����
		TargetAngle = atan2(player->GetTargetMoveDirection().x, player->GetTargetMoveDirection().z);

		// �ڕW�̊p�x�ƌ��݂̊p�x�Ƃ̍�������o��
		{
			// �ŏ��͒P���Ɉ����Z
			SaAngle = TargetAngle - player->GetAngle();

			// ����������炠������̍����P�W�O�x�ȏ�ɂȂ邱�Ƃ͖����̂�
			// ���̒l���P�W�O�x�ȏ�ɂȂ��Ă�����C������
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

		// �p�x�̍����O�ɋ߂Â���
		if (SaAngle > 0.0f)
		{
			// �����v���X�̏ꍇ�͈���
			SaAngle -= PLAYER_ANGLE_SPEED;
			if (SaAngle < 0.0f)
			{
				SaAngle = 0.0f;
			}
		}
		else
		{
			// �����}�C�i�X�̏ꍇ�͑���
			SaAngle += PLAYER_ANGLE_SPEED;
			if (SaAngle > 0.0f)
			{
				SaAngle = 0.0f;
			}
		}

		// ���f���̊p�x���X�V
		player->SetAngle(TargetAngle - SaAngle);
		MV1SetRotationXYZ(player->GetModelHandle(), VGet(0.0f, player->GetAngle() + DX_PI_F, 0.0f));
	}

	//�ړ��x�N�g�������Ƀv���C���[���ړ�
	{
		int i, j, k;						// �ėp�J�E���^�ϐ�
		int MoveFlag;						// ���������Ɉړ��������ǂ����̃t���O( �O:�ړ����Ă��Ȃ�  �P:�ړ����� )
		int HitFlag;						// �|���S���ɓ����������ǂ������L�����Ă����̂Ɏg���ϐ�( �O:�������Ă��Ȃ�  �P:�������� )
		MV1_COLL_RESULT_POLY_DIM HitDim;			// �v���C���[�̎��͂ɂ���|���S�������o�������ʂ��������铖���蔻�茋�ʍ\����
		int KabeNum;						// �ǃ|���S���Ɣ��f���ꂽ�|���S���̐�
		int YukaNum;						// ���|���S���Ɣ��f���ꂽ�|���S���̐�
		MV1_COLL_RESULT_POLY *Kabe[PLAYER_MAX_HITCOLL];	// �ǃ|���S���Ɣ��f���ꂽ�|���S���̍\���̂̃A�h���X��ۑ����Ă������߂̃|�C���^�z��
		MV1_COLL_RESULT_POLY *Yuka[PLAYER_MAX_HITCOLL];	// ���|���S���Ɣ��f���ꂽ�|���S���̍\���̂̃A�h���X��ۑ����Ă������߂̃|�C���^�z��
		MV1_COLL_RESULT_POLY *Poly;				// �|���S���̍\���̂ɃA�N�Z�X���邽�߂Ɏg�p����|�C���^( �g��Ȃ��Ă��ς܂����܂����v���O�����������Ȃ�̂ŁE�E�E )
		HITRESULT_LINE LineRes;				// �����ƃ|���S���Ƃ̓����蔻��̌��ʂ�������\����
		VECTOR OldPos;						// �ړ��O�̍��W	
		VECTOR NowPos;						// �ړ���̍��W

		// �ړ��O�̍��W��ۑ�
		OldPos = player->GetVector();

		// �ړ���̍��W���Z�o
		NowPos = VAdd(player->GetVector(), MoveVec);

		// �v���C���[�̎��͂ɂ���X�e�[�W�|���S�����擾����
		// ( ���o����͈͈͂ړ��������l������ )
		HitDim = MV1CollCheck_Sphere(stage->GetModelHandle(), -1, player->GetVector(), PLAYER_ENUM_DEFAULT_SIZE + VSize(MoveVec));

		// x����y�������� 0.01f �ȏ�ړ������ꍇ�́u�ړ������v�t���O���P�ɂ���
		if (fabs(MoveVec.x) > 0.01f || fabs(MoveVec.z) > 0.01f)
		{
			MoveFlag = 1;
		}
		else
		{
			MoveFlag = 0;
		}

		// ���o���ꂽ�|���S�����ǃ|���S��( �w�y���ʂɐ����ȃ|���S�� )�����|���S��( �w�y���ʂɐ����ł͂Ȃ��|���S�� )���𔻒f����
	{
		// �ǃ|���S���Ə��|���S���̐�������������
		KabeNum = 0;
		YukaNum = 0;

		// ���o���ꂽ�|���S���̐������J��Ԃ�
		for (i = 0; i < HitDim.HitNum; i++)
		{
			// �w�y���ʂɐ������ǂ����̓|���S���̖@���̂x�������O�Ɍ���Ȃ��߂����ǂ����Ŕ��f����
			if (HitDim.Dim[i].Normal.y < 0.000001f && HitDim.Dim[i].Normal.y > -0.000001f)
			{
				// �ǃ|���S���Ɣ��f���ꂽ�ꍇ�ł��A�v���C���[�̂x���W�{�P�D�O����荂���|���S���̂ݓ����蔻����s��
				if (HitDim.Dim[i].Position[0].y > player->GetVector().y + 1.0f ||
					HitDim.Dim[i].Position[1].y > player->GetVector().y + 1.0f ||
					HitDim.Dim[i].Position[2].y > player->GetVector().y + 1.0f)
				{
					// �|���S���̐����񋓂ł�����E���ɒB���Ă��Ȃ�������|���S����z��ɒǉ�
					if (KabeNum < PLAYER_MAX_HITCOLL)
					{
						// �|���S���̍\���̂̃A�h���X��ǃ|���S���|�C���^�z��ɕۑ�����
						Kabe[KabeNum] = &HitDim.Dim[i];

						// �ǃ|���S���̐������Z����
						KabeNum++;
					}
				}
			}
			else
			{
				// �|���S���̐����񋓂ł�����E���ɒB���Ă��Ȃ�������|���S����z��ɒǉ�
				if (YukaNum < PLAYER_MAX_HITCOLL)
				{
					// �|���S���̍\���̂̃A�h���X�����|���S���|�C���^�z��ɕۑ�����
					Yuka[YukaNum] = &HitDim.Dim[i];

					// ���|���S���̐������Z����
					YukaNum++;
				}
			}
		}
	}

	// �ǃ|���S���Ƃ̓����蔻�菈��
	if (KabeNum != 0)
	{
		// �ǂɓ����������ǂ����̃t���O�͏�����Ԃł́u�������Ă��Ȃ��v�ɂ��Ă���
		HitFlag = 0;

		// �ړ��������ǂ����ŏ����𕪊�
		if (MoveFlag == 1)
		{
			// �ǃ|���S���̐������J��Ԃ�
			for (i = 0; i < KabeNum; i++)
			{
				// i�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
				Poly = Kabe[i];

				// �|���S���ƃv���C���[���������Ă��Ȃ������玟�̃J�E���g��
				if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == FALSE) continue;

				// �����ɂ�����|���S���ƃv���C���[���������Ă���Ƃ������ƂȂ̂ŁA�|���S���ɓ��������t���O�𗧂Ă�
				HitFlag = 1;

				// �ǂɓ���������ǂɎՂ��Ȃ��ړ������������ړ�����
				{
					VECTOR SlideVec;	// �v���C���[���X���C�h������x�N�g��

					// �i�s�����x�N�g���ƕǃ|���S���̖@���x�N�g���ɐ����ȃx�N�g�����Z�o
					SlideVec = VCross(MoveVec, Poly->Normal);

					// �Z�o�����x�N�g���ƕǃ|���S���̖@���x�N�g���ɐ����ȃx�N�g�����Z�o�A���ꂪ
					// ���̈ړ���������Ǖ����̈ړ������𔲂����x�N�g��
					SlideVec = VCross(Poly->Normal, SlideVec);

					// ������ړ��O�̍��W�ɑ��������̂�V���ȍ��W�Ƃ���
					NowPos = VAdd(OldPos, SlideVec);
				}

				// �V���Ȉړ����W�ŕǃ|���S���Ɠ������Ă��Ȃ����ǂ����𔻒肷��
				for (j = 0; j < KabeNum; j++)
				{
					// j�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
					Poly = Kabe[j];

					// �������Ă����烋�[�v���甲����
					if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == TRUE) break;
				}

				// j �� KabeNum �������ꍇ�͂ǂ̃|���S���Ƃ�������Ȃ������Ƃ������ƂȂ̂�
				// �ǂɓ��������t���O��|������Ń��[�v���甲����
				if (j == KabeNum)
				{
					HitFlag = 0;
					break;
				}
			}
		}
		else
		{
			// �ړ����Ă��Ȃ��ꍇ�̏���

			// �ǃ|���S���̐������J��Ԃ�
			for (i = 0; i < KabeNum; i++)
			{
				// i�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
				Poly = Kabe[i];

				// �|���S���ɓ������Ă����瓖�������t���O�𗧂Ă���Ń��[�v���甲����
				if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == TRUE)
				{
					HitFlag = 1;
					break;
				}
			}
		}

		// �ǂɓ������Ă�����ǂ��牟���o���������s��
		if (HitFlag == 1)
		{
			// �ǂ���̉����o�����������݂�ő吔�����J��Ԃ�
			for (k = 0; k < PLAYER_HIT_TRYNUM; k++)
			{
				// �ǃ|���S���̐������J��Ԃ�
				for (i = 0; i < KabeNum; i++)
				{
					// i�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
					Poly = Kabe[i];

					// �v���C���[�Ɠ������Ă��邩�𔻒�
					if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == FALSE) continue;

					// �������Ă�����K�苗�����v���C���[��ǂ̖@�������Ɉړ�������
					NowPos = VAdd(NowPos, VScale(Poly->Normal, PLAYER_HIT_SLIDE_LENGTH));

					// �ړ�������ŕǃ|���S���ƐڐG���Ă��邩�ǂ����𔻒�
					for (j = 0; j < KabeNum; j++)
					{
						// �������Ă����烋�[�v�𔲂���
						Poly = Kabe[j];
						if (HitCheck_Capsule_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), PLAYER_HIT_WIDTH, Poly->Position[0], Poly->Position[1], Poly->Position[2]) == TRUE) break;
					}

					// �S�Ẵ|���S���Ɠ������Ă��Ȃ������炱���Ń��[�v�I��
					if (j == KabeNum) break;
				}

				// i �� KabeNum �ł͂Ȃ��ꍇ�͑S���̃|���S���ŉ����o�������݂�O�ɑS�Ă̕ǃ|���S���ƐڐG���Ȃ��Ȃ����Ƃ������ƂȂ̂Ń��[�v���甲����
				if (i != KabeNum) break;
			}
		}
	}

	
	// ���|���S���Ƃ̓����蔻��
	if (YukaNum != 0)
	{
		/*
		// �W�����v�����㏸���̏ꍇ�͏����𕪊�
		if (pl.State == 2 && pl.JumpPower > 0.0f)
		{
			float MinY;

			// �V��ɓ����Ԃ��鏈�����s��

			// ��ԒႢ�V��ɂԂ���ׂ̔���p�ϐ���������
			MinY = 0.0f;

			// �����������ǂ����̃t���O�𓖂����Ă��Ȃ����Ӗ�����O�ɂ��Ă���
			HitFlag = 0;

			// ���|���S���̐������J��Ԃ�
			for (i = 0; i < YukaNum; i++)
			{
				// i�Ԗڂ̏��|���S���̃A�h���X�����|���S���|�C���^�z�񂩂�擾
				Poly = Yuka[i];

				// ���悩�瓪�̍����܂ł̊ԂŃ|���S���ƐڐG���Ă��邩�ǂ����𔻒�
				LineRes = HitCheck_Line_Triangle(NowPos, VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), Poly->Position[0], Poly->Position[1], Poly->Position[2]);

				// �ڐG���Ă��Ȃ������牽�����Ȃ�
				if (LineRes.HitFlag == FALSE) continue;

				// ���Ƀ|���S���ɓ������Ă��āA�����܂Ō��o�����V��|���S����荂���ꍇ�͉������Ȃ�
				if (HitFlag == 1 && MinY < LineRes.Position.y) continue;

				// �|���S���ɓ��������t���O�𗧂Ă�
				HitFlag = 1;

				// �ڐG�����x���W��ۑ�����
				MinY = LineRes.Position.y;
			}

			// �ڐG�����|���S�������������ǂ����ŏ����𕪊�
			if (HitFlag == 1)
			{
				// �ڐG�����ꍇ�̓v���C���[�̂x���W��ڐG���W�����ɍX�V
				NowPos.y = MinY - PLAYER_HIT_HEIGHT;

				// �x�������̑��x�͔��]
				pl.JumpPower = -pl.JumpPower;
			}
		}
		*/
		//else
		{
			float MaxY;

			// ���~�����W�����v���ł͂Ȃ��ꍇ�̏���

			// ���|���S���ɓ����������ǂ����̃t���O��|���Ă���
			HitFlag = 0;

			// ��ԍ������|���S���ɂԂ���ׂ̔���p�ϐ���������
			MaxY = 0.0f;

			// ���|���S���̐������J��Ԃ�
			for (i = 0; i < YukaNum; i++)
			{
				// i�Ԗڂ̏��|���S���̃A�h���X�����|���S���|�C���^�z�񂩂�擾
				Poly = Yuka[i];

				/*
				// �W�����v�����ǂ����ŏ����𕪊�
				if (pl.State == 2)
				{
					// �W�����v���̏ꍇ�͓��̐悩�瑫���菭���Ⴂ�ʒu�̊Ԃœ������Ă��邩�𔻒�
					LineRes = HitCheck_Line_Triangle(VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), VAdd(NowPos, VGet(0.0f, -1.0f, 0.0f)), Poly->Position[0], Poly->Position[1], Poly->Position[2]);
				}
				*/
				//else
				{
					// �����Ă���ꍇ�͓��̐悩�炻�������Ⴂ�ʒu�̊Ԃœ������Ă��邩�𔻒�( �X�΂ŗ�����ԂɈڍs���Ă��܂�Ȃ��� )
					LineRes = HitCheck_Line_Triangle(VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), VAdd(NowPos, VGet(0.0f, -40.0f, 0.0f)), Poly->Position[0], Poly->Position[1], Poly->Position[2]);
				}

				// �������Ă��Ȃ������牽�����Ȃ�
				if (LineRes.HitFlag == FALSE) continue;

				// ���ɓ��������|���S��������A�����܂Ō��o�������|���S�����Ⴂ�ꍇ�͉������Ȃ�
				if (HitFlag == 1 && MaxY > LineRes.Position.y) continue;

				// �|���S���ɓ��������t���O�𗧂Ă�
				HitFlag = 1;

				// �ڐG�����x���W��ۑ�����
				MaxY = LineRes.Position.y;
			}

			// ���|���S���ɓ����������ǂ����ŏ����𕪊�
			if (HitFlag == 1)
			{
				// ���������ꍇ

				// �ڐG�����|���S���ň�ԍ����x���W���v���C���[�̂x���W�ɂ���
				NowPos.y = MaxY;

				// �x�������̈ړ����x�͂O��
				//pl.JumpPower = 0.0f;

				/*
				// �����W�����v���������ꍇ�͒��n��Ԃɂ���
				if (pl.State == 2)
				{
					// �ړ����Ă������ǂ����Œ��n��̏�ԂƍĐ�����A�j���[�V�����𕪊򂷂�
					if (MoveFlag)
					{
						// �ړ����Ă���ꍇ�͑����Ԃ�
						Player_PlayAnim(1);
						pl.State = 1;
					}
					else
					{
						// �ړ����Ă��Ȃ��ꍇ�͗����~���Ԃ�
						Player_PlayAnim(4);
						pl.State = 0;
					}

					// ���n���̓A�j���[�V�����̃u�����h�͍s��Ȃ�
					pl.AnimBlendRate = 1.0f;
				}
				*/
			}
			else
			{
				/*
				// ���R���W�����ɓ������Ă��Ȃ��Ċ��W�����v��Ԃł͂Ȃ������ꍇ��
				if (pl.State != 2)
				{
					// �W�����v���ɂ���
					pl.State = 2;

					// ������Ƃ����W�����v����
					pl.JumpPower = PLAYER_FALL_UP_POWER;

					// �A�j���[�V�����͗������̂��̂ɂ���
					Player_PlayAnim(3);
				}
				*/
			}
		}
	}

	// �V�������W��ۑ�����
	player->SetVector(NowPos);

	// �v���C���[�̃��f���̍��W���X�V����
	MV1SetPosition(GetModelHandle(), player->GetVector());

	// ���o�����v���C���[�̎��͂̃|���S�������J������
	MV1CollResultPolyDimTerminate(HitDim);
	}


	/*
	PlayerAnimation(player);
	*/
}


void PlayerAngle()
{
	/*
	float TargetAngle;			// �ڕW�p�x
	float SaAngle;				// �ڕW�p�x�ƌ��݂̊p�x�Ƃ̍�

	// �ڕW�̕����x�N�g������p�x�l���Z�o����
	TargetAngle = atan2(player->GetTargetMoveDirection().x, player->GetTargetMoveDirection().z);

	// �ڕW�̊p�x�ƌ��݂̊p�x�Ƃ̍�������o��
	{
		// �ŏ��͒P���Ɉ����Z
		SaAngle = TargetAngle - player->GetAngle();

		// ����������炠������̍����P�W�O�x�ȏ�ɂȂ邱�Ƃ͖����̂�
		// ���̒l���P�W�O�x�ȏ�ɂȂ��Ă�����C������
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

	// �p�x�̍����O�ɋ߂Â���
	if (SaAngle > 0.0f)
	{
		// �����v���X�̏ꍇ�͈���
		SaAngle -= PLAYER_ANGLE_SPEED;
		if (SaAngle < 0.0f)
		{
			SaAngle = 0.0f;
		}
	}
	else
	{
		// �����}�C�i�X�̏ꍇ�͑���
		SaAngle += PLAYER_ANGLE_SPEED;
		if (SaAngle > 0.0f)
		{
			SaAngle = 0.0f;
		}
	}

	// ���f���̊p�x���X�V
	player->SetAngle(TargetAngle - SaAngle);
	MV1SetRotationXYZ(player->GetModelHandle(), VGet(0.0f, player->GetAngle() + DX_PI_F, 0.0f));
	*/
}

VECTOR Player::GetTargetMoveDirection()
{
	return targetMoveDirection;
}