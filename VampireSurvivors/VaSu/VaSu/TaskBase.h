#pragma once
#include <vector>

namespace Task
{
	/// <summary>
	/// タスクの基底実装
	/// NOTE: Unity/C#におけるMonoBehaviourと近いです。システムから一定のタイミングで処理の呼び出しが行われます。
	/// </summary>
	class TaskManager;
	class TaskBase
	{
	friend TaskManager;

	private:
		int     _layer;		//!<レイヤ
		int		_priority;	//!<処理優先度
		bool	_init;		//!<初期化

	protected:
		std::vector<std::shared_ptr<TaskBase>> _childs;	//!<子供

	public:
		TaskBase()
			:_init(false)
			,_priority(0)
			,_layer(0)
			{}
		virtual	~TaskBase() {};

		//子供の追加
		int		AddChild(std::shared_ptr<TaskBase> task);
		void	RemoveChild(std::shared_ptr<TaskBase> task);
		const std::vector<std::shared_ptr<TaskBase>>& GetChilds() { return _childs; }

		void Erase();	//タスクの削除

		virtual	void Start() {};		//最初の一回目
		virtual	void Do() {};			//メイン処理
		virtual	void Physics() {};		//演算処理
		virtual	void Draw() {};			//描画処理
		virtual	void Release() {};		//解放
	};
}
