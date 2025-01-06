
#include "stdafx.h"
#include "TaskBase.h"

using namespace Task;

int		TaskBase::AddChild(std::shared_ptr<TaskBase> task)
{
	_childs.push_back(task);
	return (int)_childs.size() - 1;
}

void	TaskBase::RemoveChild(std::shared_ptr<TaskBase> task)
{
	for (auto itr = _childs.begin(); itr != _childs.end(); ++itr) {
		//ポインタをみて同一判定する
		if ((*itr).get() == task.get())
		{
			_childs.erase(itr);
			break;
		}
	}
}

void	TaskBase::Erase()
{
	//子供を削除
	for (auto itr = _childs.begin(); itr != _childs.end(); ++itr) {
		(*itr)->Erase();
	}
	Release();
}