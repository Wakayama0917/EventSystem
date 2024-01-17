#pragma once

#include <map>
#include <set>
#include "M_EventListener.h"

class EventManager
{
public:
    /// <summary>
    /// �V���O���g���Ԃ�
    /// </summary>
    /// <returns></returns>
    static EventManager& Get() noexcept;

    /// <summary>
    /// �֐����s
    /// </summary>
    /// <param name="id">���s����֐��̔ԍ�</param>
    /// <param name="data">���s����֐��ɕK�v�Ȉ���</param>
    void Invoke(int id, std::any data);

    /// <summary>
    /// ID�ɑΉ�����֐��ǉ�
    /// </summary>
    /// <param name="InEventListener">�ǉ�����֐�</param>
    /// <param name="InEventId">�ǉ�����ԍ�</param>
    void AddEventListener(EventListener* InEventListener, int InEventId);
    
    /// <summary>
    /// ID�ɑΉ�����֐��폜
    /// </summary>
    /// <param name="InEventListener">�폜����֐�</param>
    /// <param name="InEventId">�폜����ԍ�</param>
    void RemoveEventListener(EventListener* InEventListener, int InEventId);

private:
    std::map<int, std::set<EventListener*>> EventListenerMap;
};