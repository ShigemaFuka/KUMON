#pragma once

/// <summary>
/// プレイヤーオブジェクト
/// NOTE: Unity/C#において次のコードと等価
/// https://github.com/vtn-team/2dActionSample/blob/master/Assets/Scripts/Player.cs
/// </summary>
class Player : public IGameObject {
	int _hp;
	int _interval;

	float _groundY;
	float _speed;
	float _extinc;
	float _scale;
	float _jumpPow;
	float _jumpY;
	float _grav;

public:
	Player();
	virtual	~Player();

	bool HitCallback(std::shared_ptr<Collider2D> target);

	void Start();		//初期化
	void Do();			//メイン処理
	void Physics();		//演算処理
	void Draw();		//描画処理
	void Release();		//解放
	// ↑を書いておけば、呼んでもらえる（？）
};