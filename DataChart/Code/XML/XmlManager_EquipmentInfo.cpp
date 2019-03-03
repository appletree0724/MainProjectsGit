#include "XmlManager_EquipmentInfo.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>

#include "EquipmentInfo.h"
#include "Xml_SpotAddress.h"
#include "Xml_EquipmentError.h"


XmlManager_EquipmentInfo::XmlManager_EquipmentInfo(QString& filePath)
{
    this->xmlFilePath = filePath;
}

bool XmlManager_EquipmentInfo::ReadFromFile(EquipmentInfo &/*equipmentInfo*/)
{
    QFile file(this->xmlFilePath);

    if(!file.open(QFile::ReadOnly | QFile::Text))
        return false;

    QXmlStreamReader reader;
    reader.setDevice(&file);



    return true;
}

bool XmlManager_EquipmentInfo::WriteToFile(const EquipmentInfo &equipmentInfo)
{
    QFile file(this->xmlFilePath);

    if(!file.open(QFile::WriteOnly | QFile::Text))
        return false;

    QXmlStreamWriter writer;
    writer.setDevice(&file);

    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement(this->elementName_EquipmentInfoCollection);

    writer.writeStartElement(this->elementName_EquipmentInfo);
    writer.writeTextElement(this->elementName_EquipmentInfoName, equipmentInfo.Name);

    Xml_SpotAddress::WriteToFile(writer, this->elementName_Address, equipmentInfo.Address);

    Xml_EquipmentError::WriteToFile(writer, this->elementName_RandomError, equipmentInfo.RandomError);

    Xml_EquipmentError::WriteToFile(writer, this->elementName_SystemError, equipmentInfo.SystemError);

    writer.writeEndElement();
    writer.writeEndElement();

    return true;
}
