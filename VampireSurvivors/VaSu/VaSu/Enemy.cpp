#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#include <fstream>
#include <iostream>

Enemy::Enemy()
{
	_counter = 0;
	_hp = 0;
	_index = 0;
}

Enemy::~Enemy()
{
}

bool Enemy::HitCallback(std::shared_ptr<Collider2D> target)
{
	//タマ以外と当たっても無視
	auto go = target->GetGameObject().lock();
	if (go->GetObjectType<GameObjectType>() != GameObjectType::Bullet) return false;

	//敵の弾なら無視
	//NOTE: dynamic_castしている
	Bullet* ptr = dynamic_cast<Bullet*>(go.get());
	if (ptr->GetBulletForce() == GameObjectType::Enemy) return false;

	//HPへらす
	_hp--;
	return true;
}

void Enemy::Start()
{
	//初期設定
	_objectType = (int)GameObjectType::Enemy;
	_hp = 5;

	Transform.Size = Vector2(40, 70);
	//コリジョン生成
	SetupCollider<AABBCollider>(Collider2D::ENEMY);
}

void Enemy::Do()
{
	_counter++;
	auto player = _player.lock();

	if (_counter > 20 && (this->Transform.Position.X - player->Transform.Position.X < 320))
	{
		auto bullet = Bullet::CreateBullet(Vector2(-5, 0), this->Transform, Collider2D::COLLIDER_TAG::ENEMY);
		_counter = 0;
	}

	if (_hp <= 0)
	{
		Destroy();
	}
}

void Enemy::Physics()
{

}

void Enemy::Draw()
{
	DrawFormatString(520, 50 + _index * 20, GetColor(255, 64, 64), _T("HP: %d"), _hp);

	DrawBox(
		(int)(Transform.Position.X - Transform.Size.W / 2), (int)(Transform.Position.Y - Transform.Size.H / 2),
		(int)(Transform.Position.X + Transform.Size.W / 2), (int)(Transform.Position.Y + Transform.Size.H / 2),
		GetColor(255, 64, 64), TRUE);
}

void Enemy::Release()
{

}
