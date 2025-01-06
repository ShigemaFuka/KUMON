#pragma once
#include "State.h"

#include "Player.h"
#include "Enemy.h"


/// <summary>
/// メインゲームシーン
/// NOTE: Unity/C#においてのSceneと似た役割。インゲームのシーンに何を作るかを記述するものと考えるとよい
/// </summary>
class MainGameState : public State
{
#define MAX_ENEMY 5

	std::shared_ptr<Player> _player;
	std::shared_ptr<Enemy> _enemy[MAX_ENEMY];

public:
	explicit MainGameState(std::weak_ptr<StateControl> ctrl)
		: State(ctrl)
	{}
	virtual ~MainGameState() {};

	void Enter();
	void Loop();
	void Exit();
};
