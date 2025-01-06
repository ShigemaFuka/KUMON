#pragma once
#include "State.h"

enum MAIN_GAME_SEQUENCE
{
	TITLE,
	INGAME,
	RESULT,
	MAX
};

/// <summary>
/// ゲームシーンの管理
/// NOTE: Unity/C#においてのSceneManagerと似た役割。シーン共通で持つオブジェクトなどをここに持たせることもできる。
/// </summary>
class MainGameSequence : public StateControl
{

public :
	MainGameSequence();
	~MainGameSequence();

	void NextState(int state);
};