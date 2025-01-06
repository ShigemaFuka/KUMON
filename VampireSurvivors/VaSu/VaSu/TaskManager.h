#pragma once
#include <memory>
#include "TaskBase.h"
#include "Singleton.h"

namespace Task 
{

	enum TASK_LAYER
	{
		NORMAL,
		BULLET,
		MAX_LAYER
	};

	enum RUN_TYPE
	{
		DO,
		DRAW,
		PHYSICS,
		DESTROY,
	};

	/// <summary>
	/// タスクの管理クラス実装
	/// NOTE: Unity/C#におけるMonoBehaviourと近いです。タスクシステムを管理するクラスです。
	///		  シングルトン
	/// </summary>
	class TaskManager : public Singleton<TaskManager>
	{
		friend class Singleton<TaskManager>;

		std::shared_ptr<TaskBase> _rootTask[MAX_LAYER];
		std::vector<std::pair<std::shared_ptr<TaskBase>, TASK_LAYER>> _destroyList;

		TaskManager();

		void Runner(RUN_TYPE type, std::shared_ptr<TaskBase> current);
		void RunTypeAll(RUN_TYPE type);
		void RegisterTask(std::shared_ptr<TaskBase> task, TASK_LAYER layer);
		void DestroyTask(std::shared_ptr<TaskBase> task, TASK_LAYER layer);
	public:
		static void Run(RUN_TYPE type);
		static void Register(std::shared_ptr<TaskBase> task, TASK_LAYER layer = TASK_LAYER::NORMAL);
		static void Destroy(std::shared_ptr<TaskBase> task, TASK_LAYER layer = TASK_LAYER::NORMAL);

		static void Create();
		static void Release();
	};
}