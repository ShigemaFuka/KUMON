#pragma once
#include "State.h"

/// <summary>
/// タイトルシーン
/// NOTE: Unity/C#においてのSceneと似た役割。タイトルシーンに何を作るかを記述するものと考えるとよい
/// </summary>
class TitleState : public State
{
protected:

	TitleState() {}
public:
	explicit TitleState(std::weak_ptr<StateControl> ctrl)
		: State(ctrl)
	{
	}
	virtual ~TitleState() {};

	void Enter();
	void Loop();
	void Exit();
};
