#pragma once

#include <array>
#include <vector>
#include <thread>
#include "GameMath.h"
#include "Singleton.h"

/// <summary>
/// 物理システム
/// NOTE: Unity/C#におけるPhysics Systemとほぼ同じです。ただしやっていることは限りなく少ないです。
///       システム側で処理をすることであとから最適化をすることができます。
///       シングルトン
/// </summary>
class SysPhysics : public Singleton<SysPhysics>
{
	friend class Singleton<SysPhysics>;

	std::thread _worker;
	std::array<std::vector<std::shared_ptr<Collider2D>>, Collider2D::MAX_COLLIDER_TAG> _colliders;
	std::vector<std::shared_ptr<Collider2D>> _calcStack;
	std::vector<std::pair<std::shared_ptr<Collider2D>, Collider2D::COLLIDER_TAG>> _removeList;

	SysPhysics();

	void HitToAll(std::shared_ptr<Collider2D> collision, Collider2D::COLLIDER_TAG tag);

public:
	static void Run();
	static void Sync();
	static void CalcStack(std::shared_ptr<Collider2D> collision);
	static void Register(std::shared_ptr<Collider2D> collision, Collider2D::COLLIDER_TAG tag);
	static void Remove(std::shared_ptr<Collider2D> collision, Collider2D::COLLIDER_TAG tag);

	static void Create();
	static void Release();
};
