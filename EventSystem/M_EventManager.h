#pragma once

#include <map>
#include <set>
#include "M_EventListener.h"

class EventManager
{
public:
    static EventManager& Get() noexcept;

    void Invoke(int id, std::any data);
    void AddEventListener(EventListener* InEventListener, int InEventId);
    void RemoveEventListener(EventListener* InEventListener, int InEventId);

private:
    std::map<int, std::set<EventListener*>> EventListenerMap;
};