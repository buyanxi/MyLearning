#include <iostream>
#include <thread>
#include <unistd.h>
#include "Timer.h"

using namespace std;


void TimingTimerHandle(std::string strPara)
{
    printf("*******TimingTimerHandle: %s*********\n", strPara.data());
}

void CycleTimerHandle(std::string strPara)
{
    printf("*******CycleTimerHandle: %s*********\n", strPara.data());
}

void* on_timer_handle(void*)
{
    pthread_detach(pthread_self());

    TimerManager cTM;
    Timer cTimer(cTM);

    cTimer.Start(&CycleTimerHandle, 1 * 1000, Timer::CIRCLE, "mytest");

    //cTimer.Start(&TimingTimerHandle, 10 * 1000, Timer::ONCE, "mytest");

    while (true) {
        cTM.DetectTimers();
        std::this_thread::sleep_for(std::chrono::milliseconds(10 * 1000));
    }
}


int main()
{
    pthread_t iThreadID;
    if (pthread_create(&iThreadID, nullptr, on_timer_handle, (void*)0) != 0) {
        return -1;
    }

    while(true) {
        sleep(30);
    }


    return 0;
}
