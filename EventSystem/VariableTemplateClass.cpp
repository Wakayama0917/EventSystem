#include <iostream>
#include <functional>
#include <vector>

using namespace std; // std::‚ğÈ—ª‚·‚é

//ˆø”‚ ‚è
template<class... Args>
class Action
{
	using Func = function<void(Args...)>;
public:

	//ŠÖ”’Ç‰Á
	void AddFunction(Func&& func) {
		functions.push_back(func);
	}

	//“o˜^‚³‚ê‚Ä‚¢‚éŠÖ”Às
	void Invoke(Args... args) {
		for (auto func : functions)
		{
			func(args...);
		}
	}

private:
	//“o˜^‚·‚éŠÖ”ŒR
	vector<Func> functions;

};

//ˆø”–³‚µ
template<>
class Action<void>
{
	using Func = function<void()>;
public:

	//ŠÖ”’Ç‰Á
	void AddFunction(Func&& func) {
		functions.push_back(func);
	}

	//“o˜^‚³‚ê‚Ä‚¢‚éŠÖ”Às
	void Invoke() {
		for (auto func : functions)
		{
			func();
		}
	}

private:
	//“o˜^‚·‚éŠÖ”ŒR
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