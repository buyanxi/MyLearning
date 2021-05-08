#ifndef CXX_TIMER_H
#define CXX_TIMER_H

#include <vector>
#include <boost/function.hpp>

class TimerManager;

class Timer
{
public:
    enum TimerType { ONCE, CIRCLE };

    Timer(TimerManager& manager);
    ~Timer();

    template<typename Fun>
    void Start(Fun fun(std::string), int interval, TimerType timeType = CIRCLE, std::string funPara = "");
    void Stop();

private:
    void OnTimer(unsigned long long now);

private:
    friend class TimerManager;
    TimerManager& manager_;
    TimerType timerType_;
    boost::function<void(std::string)> timerFun_;
    std::string funPara_;
    int interval_;
    unsigned long long expires_;

    size_t heapIndex_;
};

class TimerManager
{
public:
    static unsigned long long GetCurrentMillisecs();
    void DetectTimers();
private:
    friend class Timer;
    void AddTimer(Timer* timer);
    void RemoveTimer(Timer* timer);

    void UpHeap(size_t index);
    void DownHeap(size_t index);
    void SwapHeap(size_t, size_t index2);

private:
    struct HeapEntry
    {
        unsigned long long time;
        Timer* timer;
    };
    std::vector<HeapEntry> heap_;
};

template<typename Fun>
inline void Timer::Start(Fun fun(std::string), int interval, TimerType timeType, std::string funPara)
{
    Stop();
    interval_ = interval;
    timerFun_ = fun;
    funPara_ = funPara;
    timerType_ = timeType;
    if (interval_ < 0) {
        interval_ = 24/*h*/ * 60/*m*/ * 60/*s*/ * 1000/*ms*/ + interval_;
    }
    expires_ = interval_ + TimerManager::GetCurrentMillisecs();
    manager_.AddTimer(this);
}

#endif // CXX_TIMER_H
