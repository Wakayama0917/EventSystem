#include <iostream>
#include <functional>
#include <vector>

using namespace std; // std::を省略する

//引数あり
template<class... Args>
class Action
{
	using Func = function<void(Args...)>;
public:

	//関数追加
	void AddFunction(Func&& func) {
		functions.push_back(func);
	}

	//登録されている関数実行
	void Invoke(Args... args) {
		for (auto func : functions)
		{
			func(args...);
		}
	}

private:
	//登録する関数軍
	vector<Func> functions;

};

//引数無し
template<>
class Action<void>
{
	using Func = function<void()>;
public:

	//関数追加
	void AddFunction(Func&& func) {
		functions.push_back(func);
	}

	//登録されている関数実行
	void Invoke() {
		for (auto func : functions)
		{
			func();
		}
	}

private:
	//登録する関数軍
	vector<Func> functions;

};

int main() {
	//test1
	{
		Action<void> action;
		action.AddFunction([]() { printf("test1\n"); });
		action.Invoke();
	}

	//test2
	{
		Action<int> action;
		action.AddFunction([](int id) { printf("HP = %d\n", id); });
		action.Invoke(10);
	}

	//test3
	{
		Action<int, int> action;
		action.AddFunction([](int id, int hp) {printf("ID = %d HP = %d", id, hp); });
		action.Invoke(1, 50);
	}

	return 0;
}