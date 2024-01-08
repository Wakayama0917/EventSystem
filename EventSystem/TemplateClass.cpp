#include <iostream>
#include <functional>
#include <vector>

using namespace std; // std::‚ğÈ—ª‚·‚é

//ˆø”‚ ‚è
template<class T>
class Event
{
public:

	//ŠÖ”’Ç‰Á
	void AddFunction(function<void(T)> func) {
		Events.push_back(func);
	}

	//“o˜^‚³‚ê‚Ä‚¢‚éŠÖ”Às
	void Invoke(T data) {
		for (auto Event : Events)
		{
			Event(data);
		}
	}

private:
	//“o˜^‚·‚éŠÖ”ŒR
	vector<function<void(T)>> Events;

};

//ˆø”–³‚µ
template<>
class Event<void>
{
public:

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

int main() {
	//ˆø”–³‚µ
	Event<void> event1;
	event1.AddFunction([]() {printf("event1\n"); });
	event1.Invoke();

	//ˆø”‚ ‚è
	Event<int> event2;
	event2.AddFunction([](int id) {printf("id = %d\n", id); });
	event2.Invoke(10);

	return 0;
}