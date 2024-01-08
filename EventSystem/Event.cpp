#include <iostream>
#include <functional>
#include <vector>

using namespace std; // std::���ȗ�����

class GameClearEvent
{
public:

	//GameClearEvent();
	//~GameClearEvent();

	//�֐��ǉ�
	void AddFunction(function<void()> func) {
		Events.push_back(func);
	}

	//�o�^����Ă���֐����s
	void Invoke() {
		for (auto Event : Events)
		{
			Event();
		}
	}

private:
	//�o�^����֐��R
	vector<function<void()>> Events;

};

//�o�^���鉼�֐�
void GameClearMessage() {
	printf("GameClear\n");
}

//���C�����[�v
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