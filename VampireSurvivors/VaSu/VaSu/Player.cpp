//
#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

Player::Player()
{
	_speed = 5.0f;
	_extinc = 0.3f;
	_scale = 10.0f;
	_jumpPow = 25.0f;
	_jumpY = 0.0f;
	_grav = 0.0f;
	_groundY = 0.0f;

	_hp = 0;
	_interval = 0;
}

Player::~Player()
{

}

void Player::Start()
{
	//初期設定
	_objectType = (int)GameObjectType::Player;
	_hp = 100;
	_groundY = Transform.Position.Y;
	_interval = 0;
	Transform.Size = Vector2(50, 80);

	//コリジョン生成
	SetupCollider<AABBCollider>(Collider2D::PLAYER);
}

#define FRAME_TIME 4.0f/60.0f

void Player::Do()
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		Transform.Position.X--;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		Transform.Position.X++;
	}

	if (_jumpY < 0.001f)
	{
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			_jumpY = _jumpPow;
			_grav = 0.0f;
		}
	}
	else
	{
		_grav += FRAME_TIME;
		_jumpY *= 1.0f - FRAME_TIME * _extinc;
		float y = Transform.Position.Y;
		y -= (_jumpY - 9.81f * _grav) * FRAME_TIME * _scale;
		if (y > _groundY)
		{
			y = _groundY;
			_grav = 0;
			_jumpY = 0;
		}
		Transform.Position.Y = y;
	}

	if(_interval > 0)
		_interval--;

	if (_interval == 0 && CheckHitKey(KEY_INPUT_Z))
	{
		int mx, my;
		GetMousePoint(&mx, &my);

		Vector2 force = Vector2(mx - this->Transform.Position.X, my - this->Transform.Position.Y);
		force.Normalize();
		auto bullet = Bullet::CreateBullet(force * 6, this->Transform, Collider2D::COLLIDER_TAG::PLAYER);
		_interval = 10;
	}

	if (_hp <= 0)
	{
		Destroy();
	}
}

void Player::Physics()
{

}

bool Player::HitCallback(std::shared_ptr<Collider2D> target)
{
	//タマ以外と当たっても無視
	auto go = target->GetGameObject().lock();
	if (go->GetObjectType<GameObjectType>() != GameObjectType::Bullet) return false;

	//プレイヤーの弾なら無視
	//NOTE: dynamic_castしている
	Bullet* ptr = dynamic_cast<Bullet*>(go.get());
	if (ptr->GetBulletForce() == GameObjectType::Player) return false;

	//HP減らす
	_hp--;
	return true;
}

void Player::Draw()
{
	DrawString(50, 30, _T("Player"), GetColor(64, 64, 255));
	DrawFormatString(50, 50, GetColor(64, 64, 255), _T("HP: %d"), _hp);

	DrawBox(
		(int)(Transform.Position.X - Transform.Size.W / 2), (int)(Transform.Position.Y - Transform.Size.H / 2),
		(int)(Transform.Position.X + Transform.Size.W / 2), (int)(Transform.Position.Y + Transform.Size.H / 2),
		GetColor(64, 64, 255), TRUE);

	int mx, my;
	GetMousePoint(&mx, &my);
	DrawBox(mx - 2, my - 2, mx + 2, my + 2, GetColor(64, 64, 64), TRUE);
}

void Player::Release()
{

}
