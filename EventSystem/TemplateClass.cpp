#include <iostream>
#include <functional>
#include <vector>

using namespace std; // std::���ȗ�����

//��������
template<class T>
class Event
{
public:

	//�֐��ǉ�
	void AddFunction(function<void(T)> func) {
		Events.push_back(func);
	}

	//�o�^����Ă���֐����s
	void Invoke(T data) {
		for (auto Event : Events)
		{
			Event(data);
		}
	}

private:
	//�o�^����֐��R
	vector<function<void(T)>> Events;

};

//��������
template<>
class Event<void>
{
public:

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

int main() {
	//��������
	Event<void> event1;
	event1.AddFunction([]() {printf("event1\n"); });
	event1.Invoke();

	//��������
	Event<int> event2;
	event2.AddFunction([](int id) {printf("id = %d\n", id); });
	event2.Invoke(10);

	return 0;
}