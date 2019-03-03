#ifndef TIMERTEST_H
#define TIMERTEST_H

#include <QObject>
#include <QTimerEvent>
#include <QDebug>

class TimerTest : public QObject
{
    Q_OBJECT

public:
    TimerTest(QObject * parent = 0);

    void SendData(int miliseconds);

protected:
    void timerEvent(QTimerEvent * event);
};

#endif // TIMERTEST_H
