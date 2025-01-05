#pragma once
#include <memory>

/// <summary>
/// �X�e�[�g�}�V��
/// NOTE: �ėp�I�ȃf�U�C���p�^�[��
/// </summary>
class StateControl;

// ���ۃN���X
class State
{
protected:
	std::weak_ptr<StateControl> _ctrl; //�z�Q�ƂɂȂ�̂�weak�Ŏ���

	State() {}
public:
	// explicit�F�Öق̌^�ϊ���h�~
	explicit State(std::weak_ptr<StateControl> c) : _ctrl(c) { }
	// ���z�f�X�g���N�^
	virtual ~State() {};
	// �������z�֐�
	virtual void Enter() = 0;
	virtual void Loop() = 0;
	virtual void Exit() = 0;
};

//std::shared_ptr�F���L���̋��L�E�����������Ǘ�
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
