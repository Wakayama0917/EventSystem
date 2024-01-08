#include <iostream>
#include <functional>
#include <vector>

using namespace std; // std::‚ğÈ—ª‚·‚é

class GameClearEvent
{
public:

	//GameClearEvent();
	//~GameClearEvent();

	//ŠÖ”’Ç‰Á
	void AddFunction(function<void()> func) {
		Events.push_back(func);
	}

	//“o˜^‚³‚ê‚Ä‚¢‚éŠÖ”Às
	void Invoke() {
		for (auto Event : Events)
		{
			Event();
		}
	}

private:
	//“o˜^‚·‚éŠÖ”ŒR
	vector<function<void()>> Events;

};

//“o˜^‚·‚é‰¼ŠÖ”
void GameClearMessage() {
	printf("GameClear\n");
}

//ƒƒCƒ“ƒ‹[ƒv
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