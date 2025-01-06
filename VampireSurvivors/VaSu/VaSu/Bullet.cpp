
#include "stdafx.h"
#include "Bullet.h"

//ビルダーで作って返す
std::shared_ptr<Bullet> Bullet::CreateBullet(Vector2 force, Transform2D parent, Collider2D::COLLIDER_TAG tag)
{
	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>();
	bullet->_objectType = (int)GameObjectType::Bullet;
	bullet->_force = force;
	bullet->Transform = parent;
	bullet->_tag = tag;
	bullet->_self = bullet;
	TaskManager::Register(bullet);
	return bullet;
}

Bullet::Bullet()
{
	_force = Vector2(0, 0);
	_tag = Collider2D::INVALID_TAG;
}

Bullet::~Bullet()
{

}

void Bullet::Start()
{
	Transform.Size.Radius = 30;
	SetupCollider<CircleCollider>(Collider2D::BULLET);
}

void Bullet::Do()
{
	Transform.Position += _force;
	SysPhysics::CalcStack(_collider);
}

void Bullet::Physics()
{

}

GameObjectType  Bullet::GetBulletForce()
{
	if (_force.X < 0) return GameObjectType::Enemy;
	if (_force.X > 0) return GameObjectType::Player;
	return  GameObjectType::Invalid;
}

bool Bullet::HitCallback(std::shared_ptr<Collider2D> target)
{
	auto go = target->GetGameObject().lock();
	if (_force.X < 0) {
		if (go->GetObjectType<GameObjectType>() == GameObjectType::Enemy) return false;
	}
	if (_force.X > 0) {
		if (go->GetObjectType<GameObjectType>() == GameObjectType::Player) return false;
	}// 敵自身に敵の弾、プレイヤー自身にプレイヤーの弾が当たっても消さないようにする

	SysPhysics::Remove(_collider, Collider2D::BULLET);
	TaskManager::Destroy(_self);
	return true;
}

void Bullet::Draw()
{
	DrawCircle((int)(Transform.Position.X), (int)(Transform.Position.Y), (int)Transform.Size.Radius, GetColor(64, 64, 64), TRUE);
}

void Bullet::Release()
{

}