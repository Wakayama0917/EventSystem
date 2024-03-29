#include <iostream>
#include <functional>
#include <vector>

using namespace std; // std::を省略する

class GameClearEvent
{
public:

	//GameClearEvent();
	//~GameClearEvent();

	//関数追加
	void AddFunction(function<void()> func) {
		Events.push_back(func);
	}

	//登録されている関数実行
	void Invoke() {
		for (auto Event : Events)
		{
			Event();
		}
	}

private:
	//登録する関数軍
	vector<function<void()>> Events;

};

//登録する仮関数
void GameClearMessage() {
	printf("GameClear\n");
}

//メインループ
int main() {
	GameClearEvent gameClearEvent;
	int count = 0;

	//
	gameClearEvent.AddFunction(GameClearMessage);

	//
	while (true)
	{
		gameClearEvent.Invoke();
		count++;

		if (count == 5)
		{
			break;
		}
	}
}