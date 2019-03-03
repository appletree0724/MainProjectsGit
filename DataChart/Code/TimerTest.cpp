#include "TimerTest.h"

TimerTest::TimerTest(QObject *parent) : QObject(parent)
{
//      startTimer(50);     // 50-millisecond timer
//      startTimer(1000);   // 1-second timer
//      startTimer(60000);  // 1-minute timer

//      using namespace std::chrono;
//      startTimer(milliseconds(50));
//      startTimer(seconds(1));
//      startTimer(minutes(1));

      // since C++14 we can use std::chrono::duration literals, e.g.:
//      startTimer(1s);
//      startTimer(5s);
//      startTimer(2min);
    //      startTimer(1h);
}

void TimerTest::SendData(int miliseconds)
{
    this->startTimer(miliseconds, Qt::TimerType::PreciseTimer);
}

void TimerTest::timerEvent(QTimerEvent *event)
{
     //qDebug() << "Timer ID:" << event->timerId();

     qDebug() << "Data have been sended." << event->timerId();

     this->killTimer(event->timerId());
}
