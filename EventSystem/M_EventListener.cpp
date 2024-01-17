#include "M_EventListener.h"
#include "M_EventManager.h"

void EventListener::Action(std::any data) {
    func(data);
}

void EventListener::RegisterToEventManager() {
    EventManager::Get().AddEventListener(this, eventId);
}

void EventListener::SetFunction(int InEventId, std::function<void(std::any)> InFunc) {
    eventId = InEventId;
    func = InFunc;

    RegisterToEventManager();
}

