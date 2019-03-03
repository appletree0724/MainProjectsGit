#ifndef EQUIPMENTINFO_H
#define EQUIPMENTINFO_H

#include <QString>
//#include <string>

#include "SpotAddress.h"
#include "EquipmentError.h"

//using namespace std;

struct SpotAddress;
struct EquipmentError;

// 设备信息
struct EquipmentInfo
{
    QString Name;

    SpotAddress Address;

    EquipmentError SystemError;

    EquipmentError RandomError;
};

#endif // EQUIPMENTINFO_H
