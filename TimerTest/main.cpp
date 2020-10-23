#include <iostream>
#include <thread>
#include <unistd.h>
#include "Timer.h"

using namespace std;


void TimingTimerHandle()
{
    printf("*******TimingTimerHandle*********\n");
}

void CycleTimerHandle()
{
    printf("*******CycleTimerHandle*********\n");
}

void* on_timer_handle(void*)
{
    pthread_detach(pthread_self());

    TimerManager cTM;
    Timer cTimer(cTM);

    //cTimer.Start(&CycleTimerHandle, 10 * 1000, Timer::CIRCLE);

    cTimer.Start(&TimingTimerHandle, 10 * 1000, Timer::ONCE);

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
