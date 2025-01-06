#pragma once

/// <summary>
/// ベクトルクラス(2D)
/// NOTE: Unity/C#におけるVector2とほぼ同じです。X,YでもW,Hでも使えるようにしています。
/// </summary>
struct Vector2
{
	//無名共用体をつかって、X,YとW,Hのメモリ配置を同じにする
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
/// ベクトルクラス(3D)
/// NOTE: Unity/C#におけるVector3とほぼ同じです。使ってないので最小実装です。
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