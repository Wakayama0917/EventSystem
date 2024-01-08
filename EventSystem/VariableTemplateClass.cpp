#include <iostream>
#include <functional>
#include <vector>

using namespace std; // std::���ȗ�����

//��������
template<class... Args>
class Action
{
	using Func = function<void(Args...)>;
public:

	//�֐��ǉ�
	void AddFunction(Func&& func) {
		functions.push_back(func);
	}

	//�o�^����Ă���֐����s
	void Invoke(Args... args) {
		for (auto func : functions)
		{
			func(args...);
		}
	}

private:
	//�o�^����֐��R
	vector<Func> functions;

};

//��������
template<>
class Action<void>
{
	using Func = function<void()>;
public:

	//�֐��ǉ�
	void AddFunction(Func&& func) {
		functions.push_back(func);
	}

	//�o�^����Ă���֐����s
	void Invoke() {
		for (auto func : functions)
		{
			func();
		}
	}

private:
	//�o�^����֐��R
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