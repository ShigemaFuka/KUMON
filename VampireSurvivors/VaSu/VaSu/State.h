#pragma once
#include <memory>

/// <summary>
/// ステートマシン
/// NOTE: 汎用的なデザインパターン
/// </summary>
class StateControl;

// 抽象クラス
class State
{
protected:
	std::weak_ptr<StateControl> _ctrl; //循環参照になるのでweakで持つ

	State() {}
public:
	// explicit：暗黙の型変換を防止
	explicit State(std::weak_ptr<StateControl> c) : _ctrl(c) { }
	// 仮想デストラクタ
	virtual ~State() {};
	// 純粋仮想関数
	virtual void Enter() = 0;
	virtual void Loop() = 0;
	virtual void Exit() = 0;
};

//std::shared_ptr：所有権の共有・自動メモリ管理
class StateControl : public std::enable_shared_from_this<StateControl>
{
protected:
	std::shared_ptr<State> _state;

	virtual void Next(std::shared_ptr<State> state);

public:
	StateControl();
	virtual ~StateControl() {};

	std::shared_ptr<StateControl> GetPtr() { return shared_from_this(); }
	virtual void NextState(int state) = 0;
	void Loop();
};
