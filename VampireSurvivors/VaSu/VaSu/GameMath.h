#pragma once

/// <summary>
/// �x�N�g���N���X(2D)
/// NOTE: Unity/C#�ɂ�����Vector2�Ƃقړ����ł��BX,Y�ł�W,H�ł��g����悤�ɂ��Ă��܂��B
/// </summary>
struct Vector2
{
	//�������p�̂������āAX,Y��W,H�̃������z�u�𓯂��ɂ���
	union {
		float X;
		float W;
		float Radius;
	};
	union {
		float Y;
		float H;
	};
	Vector2()
	{
		X = 0; Y = 0;
	}

	Vector2(float x, float y)
	{
		X = x;
		Y = y;
	}

	Vector2 operator + (Vector2 pos)
	{
		X += pos.X;
		Y += pos.Y;
		return *this;
	}
	Vector2 operator += (Vector2 pos)
	{
		X += pos.X;
		Y += pos.Y;
		return *this;
	}
	Vector2 operator * (float f)
	{
		X *= f;
		Y *= f;
		return *this;
	}
	void Normalize()
	{
		float len = sqrtf(X * X + Y * Y);
		X = X / len;
		Y = Y / len;
	}
};

/// <summary>
/// �x�N�g���N���X(3D)
/// NOTE: Unity/C#�ɂ�����Vector3�Ƃقړ����ł��B�g���ĂȂ��̂ōŏ������ł��B
/// </summary>
struct Vector3
{
	float X;
	float Y;
	float Z;

	Vector3()
	{
		X = 0; Y = 0; Z = 0;
	}

	Vector3(float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}
};