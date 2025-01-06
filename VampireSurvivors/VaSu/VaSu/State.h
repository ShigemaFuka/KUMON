#pragma once
#include <memory>

/// <summary>
/// ステートマシン
/// NOTE: 汎用的なデザインパターン
/// </summary>
class StateControl;
class State
{
protected:
	std::weak_ptr<StateControl> _ctrl; //循環参照になるのでweakで持つ

	State() {}
public:
	explicit State(std::weak_ptr<StateControl> c): _ctrl(c){ }
	virtual ~State() {};

	virtual void Enter() = 0;
	virtual void Loop() = 0;
	virtual void Exit() = 0;
};

class StateControl : public std::enable_shared_from_this<StateControl>
{
protected:
	std::shared_ptr<State> _state;

	virtual void Next(std::shared_ptr<State> state);

public:
	StateControl();
	virtual ~StateControl() {};

	std::shared_ptr<StateControl> GetPtr() { return shared_from_this(); }
	virtual void NextState(int state)=0;
	void Loop();
};
