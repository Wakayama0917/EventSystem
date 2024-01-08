#pragma once

#include <functional>
#include <any>

class EventManager;  // Forward declaration

class EventListener
{
public:
    void Action(std::any data);
    void SetFunction(int InEventId, std::function<void(std::any)> InFunc);
    void RegisterToEventManager();

private:
    int eventId;
    std::function<void(std::any)> func;
};