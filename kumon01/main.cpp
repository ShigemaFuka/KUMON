#include <iostream>

int main(int argc, char* argv[])
{
	for (int i = 1; i <= 100; ++i)
	{
		//判定処理をここに書いてください
		if (i % 15 == 0)
		{
			std::cout << "hogepiyo" << std::endl;	//文字列を出力する
		}
		if (i % 5 == 0)
		{
			std::cout << "piyo" << std::endl;	//文字列を出力する
		}
		if (i % 3 == 0)
		{
			std::cout << "hoge" << std::endl;	//文字列を出力する
		}
		else
		{
			std::cout << i << std::endl;		//数字を出力する
		}
		//出力は以下の形式を使用してください
		//std::cout << i << std::endl;		//数字を出力する
		//std::cout << "hoge" << std::endl;	//文字列を出力する
	}

	return 0;
}