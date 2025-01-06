#pragma once

/// <summary>
/// プレイヤーオブジェクト
/// NOTE: Unity/C#において次のコードと等価
/// https://github.com/vtn-team/2dActionSample/blob/master/Assets/Scripts/Enemy.cs
/// </summary>
class Enemy : public IGameObject {
	int _index;
	int _hp;
	int _counter;

	std::weak_ptr<Player> _player;

public:
	Enemy();
	virtual	~Enemy();

	bool HitCallback(std::shared_ptr<Collider2D> target);
	void SetIndex(int index) { _index = index; }
	void SetPlayer(std::weak_ptr<Player> p) { _player = p; }

	void Start();		//初期化
	void Do();			//メイン処理
	void Physics();		//演算処理
	void Draw();		//描画処理
	void Release();		//解放
};
