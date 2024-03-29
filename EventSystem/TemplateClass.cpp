#include <iostream>
#include <functional>
#include <vector>

using namespace std; // std::を省略する

//引数あり
template<class T>
class Event
{
public:

	//関数追加
	void AddFunction(function<void(T)> func) {
		Events.push_back(func);
	}

	//登録されている関数実行
	void Invoke(T data) {
		for (auto Event : Events)
		{
			Event(data);
		}
	}

private:
	//登録する関数軍
	vector<function<void(T)>> Events;

};

//引数無し
template<>
class Event<void>
{
public:

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

int main() {
	//引数無し
	Event<void> event1;
	event1.AddFunction([]() {printf("event1\n"); });
	event1.Invoke();

	//引数あり
	Event<int> event2;
	event2.AddFunction([](int id) {printf("id = %d\n", id); });
	event2.Invoke(10);

	return 0;
}