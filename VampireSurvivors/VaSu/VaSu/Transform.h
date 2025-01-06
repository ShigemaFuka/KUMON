#pragma once
#include "GameMath.h"
#include "TaskBase.h"

/// <summary>
/// オブジェクトの状態変数クラスの2D版
/// NOTE: Unity/C#における(Rect)Transformと同じです。ゲームエンジンでは行列で表現されることが多いです。
/// </summary>
struct Transform2D
{
	Vector2 Position;
	Vector2 Rotation;
	Vector2 Size;

	Transform2D()
		:Position(0, 0)
		,Rotation(0, 0)
		,Size(0,0)
	{}
	virtual	~Transform2D() {};

	void SetPosition(Vector2 pos) { Position = pos; }
	void SetRotation(Vector2 rot) { Rotation = rot; }
};