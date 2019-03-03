#ifndef XMLMANAGER_EQUIPMENTINFO_H
#define XMLMANAGER_EQUIPMENTINFO_H

#include <QString>

struct EquipmentInfo;
struct SpotAddress;
struct EquipmentError;

class XmlManager_EquipmentInfo
{
public:
    XmlManager_EquipmentInfo(QString &filePath);

    bool ReadFromFile(EquipmentInfo& equipmentInfo);

    bool WriteToFile(const EquipmentInfo& equipmentInfo);

private:
    QString xmlFilePath;

    const QString elementName_EquipmentInfoCollection = "EquipmentInfoCollection";
    const QString elementName_EquipmentInfo = "EquipmentInfo";

    const QString elementName_EquipmentInfoName = "Name";
    const QString elementName_Address = "SpotAddress";

    const QString elementName_SystemError = "SystemError";
    const QString elementName_RandomError = "RandomError";
};

#endif // XMLMANAGER_EQUIPMENTINFO_H
