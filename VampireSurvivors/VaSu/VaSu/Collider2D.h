#pragma once

class IGameObject;
class SysPhysics;

/// <summary>
/// 2Dコライダー基底
/// NOTE: Unity/C#におけるコライダーコンポーネントとほぼ同じです。当たった際にイベントが実行されます。
/// </summary>
class Collider2D : public std::enable_shared_from_this<Collider2D> {
public:
	enum COLLIDER_TYPE {
		INVALID_TYPE,
		AABB,
		CIRCLE,
		OBB
	};

	enum COLLIDER_TAG {
		INVALID_TAG,
		PLAYER,
		ENEMY,
		BULLET,
		MAX_COLLIDER_TAG
	};
private:
	friend SysPhysics;

	COLLIDER_TYPE _type;
	COLLIDER_TAG _tag;

protected:
	std::weak_ptr<IGameObject> _target;
	std::function<bool(std::shared_ptr<Collider2D>)> _hitCallback;
	std::shared_ptr<Collider2D> GetPtr() { return shared_from_this(); }

	Collider2D():_type(COLLIDER_TYPE::INVALID_TYPE), _tag(COLLIDER_TAG::INVALID_TAG) {}
public:
	Collider2D(COLLIDER_TYPE type, std::weak_ptr<IGameObject> link);
	virtual ~Collider2D();

	COLLIDER_TYPE GetType() { return _type; }
	COLLIDER_TAG GetTag() { return _tag; }
	std::weak_ptr<IGameObject> GetGameObject() { return _target; }

	void SetCallback(std::function<bool(std::shared_ptr<Collider2D>)> callback);
	void UpdateTag(COLLIDER_TAG tag);
	virtual bool IsHit(std::shared_ptr<Collider2D> target) = 0; //targetに対して当たっているか
};

/// <summary>
/// AABBコライダー
/// NOTE: Unity/C#におけるBoxCollider2Dとほぼ同じです。
/// </summary>
class AABBCollider : public Collider2D {

	AABBCollider() {}
	AABBCollider(AABBCollider&&) = delete;
public:
	AABBCollider(std::weak_ptr<IGameObject> link) :
		Collider2D(COLLIDER_TYPE::AABB, link) {}
	bool IsHit(std::shared_ptr<Collider2D> target); //targetに対して当たっているか
};

class OBBCollider : public Collider2D {
}; 

/// <summary>
/// 円コライダー
/// NOTE: Unity/C#におけるCircleColliderとほぼ同じです。
/// </summary>
class CircleCollider : public Collider2D {
	CircleCollider(){}
	CircleCollider(CircleCollider&&) = delete;
public:
	CircleCollider(std::weak_ptr<IGameObject> link) :
		Collider2D(COLLIDER_TYPE::CIRCLE, link) {}
	bool IsHit(std::shared_ptr<Collider2D> target); //targetに対して当たっているか
};