
#include "stdafx.h"
#include "MainGameSequence.h"
#include "TitleState.h"

void TitleState::Enter()
{

}

void TitleState::Loop()
{
	DrawString(50, 50, _T("タイトル"), GetColor(255, 255, 255));

	DrawString(250, 250, _T("ENTERで次のシーン"), GetColor(255, 255, 255));

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		if (std::shared_ptr<StateControl> ptr = _ctrl.lock())
		{
			ptr->NextState(MAIN_GAME_SEQUENCE::INGAME);
		}
	}
}

void TitleState::Exit()
{

}
