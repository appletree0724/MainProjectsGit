#include "DataAgent_Int.h"

DataAgent_Int::DataAgent_Int(int *value, QObject *parent) : QObject(parent)
{
    this->value = value;
}

int DataAgent_Int::Value()
{
    return *this->value;
}

void DataAgent_Int::SetValue(int data)
{
    *this->value = data;

    emit this->ValueChanged(data);
}
