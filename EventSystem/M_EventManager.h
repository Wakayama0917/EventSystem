#pragma once

#include <map>
#include <set>
#include "M_EventListener.h"

class EventManager
{
public:
    /// <summary>
    /// シングルトン返す
    /// </summary>
    /// <returns></returns>
    static EventManager& Get() noexcept;

    /// <summary>
    /// 関数実行
    /// </summary>
    /// <param name="id">実行する関数の番号</param>
    /// <param name="data">実行する関数に必要な引数</param>
    void Invoke(int id, std::any data);

    /// <summary>
    /// IDに対応する関数追加
    /// </summary>
    /// <param name="InEventListener">追加する関数</param>
    /// <param name="InEventId">追加する番号</param>
    void AddEventListener(EventListener* InEventListener, int InEventId);
    
    /// <summary>
    /// IDに対応する関数削除
    /// </summary>
    /// <param name="InEventListener">削除する関数</param>
    /// <param name="InEventId">削除する番号</param>
    void RemoveEventListener(EventListener* InEventListener, int InEventId);

private:
    std::map<int, std::set<EventListener*>> EventListenerMap;
};