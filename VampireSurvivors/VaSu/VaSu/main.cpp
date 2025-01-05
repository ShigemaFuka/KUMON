// メイン
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウインドウモードに変更
	ChangeWindowMode(TRUE);

	// DxLibの初期化
	if (DxLib_Init() == -1) 
	{
		// 初期化失敗
		return -1;
	}

	// 描画ウィンドウの設定
	SetDrawScreen(DX_SCREEN_BACK);
	//初期化
	Task::TaskManager::Create();
	SysPhysics::Create();

	// キー入力があるまで待機
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 描画ウィンドウの更新
		ClearDrawScreen();
		DrawString(50, 50, _T("タイトル"), GetColor(255, 255, 255));
		ScreenFlip(); // 画面更新
		//プロセスメッセージ待ち
		if (ProcessMessage() == -1)
		{
			// エラーが起きたらループを抜ける
			break;
		}
	}

	// DxLib終了処理
	DxLib_End();
	return 0;
}