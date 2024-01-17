#pragma once

#include <functional>
#include <any>

class EventManager;  // Forward declaration

class EventListener
{
public:

    /// <summary>
    /// イベントが発生した時に呼び出される関数を実行。
    /// </summary>
    /// <param name="data"></param>
    void Action(std::any data);

    /// <summary>
    /// 関数をセット
    /// </summary>
    /// <param name="InEventId">関数の登録番号</param>
    /// <param name="InFunc">登録する関数関数</param>
    void SetFunction(int InEventId, std::function<void(std::any)> InFunc);

    /// <summary>
    /// イベントマネージャーに自身を登録する
    /// </summary>
    void RegisterToEventManager();

private:
    int eventId;
    std::function<void(std::any)> func;
};