
#include "stdafx.h"
#include "State.h"

StateControl::StateControl()
{
	_state = NULL;
}

void StateControl::Next(std::shared_ptr<State> state)
{
	if(_state) _state->Exit();
	_state = state;
	_state->Enter();
}

void StateControl::Loop()
{
	if (_state == NULL) return;

	_state->Loop();
}
