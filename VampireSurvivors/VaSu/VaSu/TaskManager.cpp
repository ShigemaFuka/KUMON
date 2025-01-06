#include "stdafx.h"
#include "TaskBase.h"
#include "TaskManager.h"

using namespace Task;

//シングルトンインスタンス
static std::unique_ptr<Task::TaskManager> _instance;
Task::TaskManager* GetTaskManagerInstance()
{
	return _instance.get();
}


TaskManager::TaskManager()
{
	for (int i = 0; i < TASK_LAYER::MAX_LAYER; ++i)
	{
		_rootTask[i] = std::make_shared<TaskBase>();
	}
}

void TaskManager::Run(RUN_TYPE type)
{
	GetTaskManagerInstance()->RunTypeAll(type);
}

void TaskManager::Register(std::shared_ptr<TaskBase> task, TASK_LAYER layer)
{
	GetTaskManagerInstance()->RegisterTask(task, layer);
}

void TaskManager::Destroy(std::shared_ptr<TaskBase> task, TASK_LAYER layer)
{
	GetTaskManagerInstance()->DestroyTask(task, layer);
}

void TaskManager::Create()
{
	if (_instance == nullptr)
	{
		_instance = std::unique_ptr<Task::TaskManager>(new Task::TaskManager());
	}
}

void TaskManager::Release()
{
	_instance.release();
}

void TaskManager::Runner(RUN_TYPE type, std::shared_ptr<TaskBase> current)
{
	switch (type)
	{
	case RUN_TYPE::DO:
		//初期化系
		if (!current->_init)
		{
			current->Start();
			current->_init = true;
		}
		current->Do();
		break;

	case RUN_TYPE::DRAW:
		if (current->_init)
		{
			current->Draw();
		}
		break;

	case RUN_TYPE::PHYSICS:
		if (current->_init)
		{
			current->Physics();
		}
		break;

	case RUN_TYPE::DESTROY:
	{
		for (auto itr = _destroyList.begin(); itr != _destroyList.end(); ++itr) {
			itr->first->Erase();
			_rootTask[itr->second]->RemoveChild(itr->first);
			itr->first.reset();
		}
		_destroyList.clear();
	}
	break;
	}

	auto childs = current->GetChilds();
	for (std::shared_ptr<TaskBase> c : childs)
	{
		Runner(type, c);
	}
	// 親から子の順にリスト構造のようにタスクを実行する
};

void TaskManager::RunTypeAll(RUN_TYPE type)
{
	for (int i = 0; i < TASK_LAYER::MAX_LAYER; ++i)
	{
		Runner(type, _rootTask[i]);
	}
}

void TaskManager::RegisterTask(std::shared_ptr<TaskBase> task, TASK_LAYER layer)
{
	//レイヤの設定する
	task->_layer = layer;
	_rootTask[layer]->AddChild(task);
}

void TaskManager::DestroyTask(std::shared_ptr<TaskBase> task, TASK_LAYER layer)
{
	_destroyList.push_back(std::pair<std::shared_ptr<TaskBase>, TASK_LAYER>(task, layer));
}