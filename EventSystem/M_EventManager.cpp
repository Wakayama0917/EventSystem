#include "M_EventManager.h"

EventManager& EventManager::Get() noexcept {
    static EventManager instance;
    return instance;
}

void EventManager::Invoke(int id, std::any data) {
    auto hasEvent = EventListenerMap.contains(id);

    if (hasEvent == false) {
        return;
    }

    for (auto EventListener : EventListenerMap[id]) {
        EventListener->Action(data);
    }
}

void EventManager::AddEventListener(EventListener* InEventListener, int InEventId) {
    EventListenerMap[InEventId].insert(InEventListener);
}

void EventManager::RemoveEventListener(EventListener* InEventListener, int InEventId) {
    EventListenerMap[InEventId].erase(InEventListener);
}