#pragma once

#include <functional>
#include <any>

class EventManager;  // Forward declaration

class EventListener
{
public:

    /// <summary>
    /// �C�x���g�������������ɌĂяo�����֐������s�B
    /// </summary>
    /// <param name="data"></param>
    void Action(std::any data);

    /// <summary>
    /// �֐����Z�b�g
    /// </summary>
    /// <param name="InEventId">�֐��̓o�^�ԍ�</param>
    /// <param name="InFunc">�o�^����֐��֐�</param>
    void SetFunction(int InEventId, std::function<void(std::any)> InFunc);

    /// <summary>
    /// �C�x���g�}�l�[�W���[�Ɏ��g��o�^����
    /// </summary>
    void RegisterToEventManager();

private:
    int eventId;
    std::function<void(std::any)> func;
};