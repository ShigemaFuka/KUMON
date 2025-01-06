#pragma once

/// <summary>
///弾オブジェクト
/// NOTE: Unity/C#において次のコードと等価。当たり判定の処理が違うが、これは当たり判定の仕組みが違うためである。
/// https://github.com/vtn-team/2dActionSample/blob/master/Assets/Scripts/Bullet.cs
/// </summary>
class Bullet : public IGameObject {

	Collider2D::COLLIDER_TAG _tag;
	Vector2 _force;
	std::shared_ptr<Bullet> _self;

public:
	Bullet();
	virtual	~Bullet();

	static std::shared_ptr<Bullet> CreateBullet(Vector2 force, Transform2D parent, Collider2D::COLLIDER_TAG tag);

	bool HitCallback(std::shared_ptr<Collider2D> target);

	GameObjectType  GetBulletForce();

	void Start();		//初期化
	void Do();			//メイン処理
	void Physics();		//演算処理
	void Draw();		//描画処理
	void Release();		//解放
};