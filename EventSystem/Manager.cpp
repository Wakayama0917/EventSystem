#include <iostream>
#include <functional>
#include <any>
#include <set>
#include <map>

#include "M_EventListener.h";
#include "M_EventManager.h"

using namespace std;

// 簡単なテスト処理
void TestFunction(any data) {
    int value = any_cast<int>(data);
    cout << "TestFunction called with data: " << value << endl;
}

int main() {
    EventListener listener;
    listener.SetFunction(1, TestFunction);
    
    listener.SetFunction(2, TestFunction);

    EventManager::Get().Invoke(2, 200);

    return 0;
}