#ifndef XMLDATA_INT_H
#define XMLDATA_INT_H

#include <QObject>

class DataAgent_Int : QObject
{
    Q_OBJECT
public:
    DataAgent_Int(int *value, QObject * parent = 0);

    int Value();

signals:
    void ValueChanged(int value);

public slots:
    void SetValue(int value);

private:
    int * value;
};

#endif // XMLDATA_INT_H
