#pragma once

#include <array>
#include <vector>
#include <thread>
#include "GameMath.h"
#include "Singleton.h"

/// <summary>
/// �����V�X�e��
/// NOTE: Unity/C#�ɂ�����Physics System�Ƃقړ����ł��B����������Ă��邱�Ƃ͌���Ȃ����Ȃ��ł��B
///       �V�X�e�����ŏ��������邱�Ƃł��Ƃ���œK�������邱�Ƃ��ł��܂��B
///       �V���O���g��
/// </summary>
class SysPhysics : public Singleton<SysPhysics>
{
	/*friend class Singleton<SysPhysics>;

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
	static void Release();*/
};
