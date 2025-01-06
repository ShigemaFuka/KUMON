
#include "stdafx.h"
#include "MainGameSequence.h"
#include "TitleState.h"
#include "MainGameState.h"

MainGameSequence::MainGameSequence()
{
}

MainGameSequence::~MainGameSequence()
{
}

void MainGameSequence::NextState(int state)
{
	auto p = shared_from_this();
	std::weak_ptr<StateControl> _this(p);
	switch (state)
	{
	case MAIN_GAME_SEQUENCE::TITLE:
		Next(std::make_shared<TitleState>(_this));
		break;

	case MAIN_GAME_SEQUENCE::INGAME:
		Next(std::make_shared<MainGameState>(_this));
		break;

	case MAIN_GAME_SEQUENCE::RESULT:
		break;
	}
}