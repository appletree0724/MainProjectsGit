#include "Xml_EquipmentError.h"

#include "EquipmentError.h"


Xml_EquipmentError::Xml_EquipmentError()
{
}

const QString Xml_EquipmentError::elementName_Error_R = "Error_R";
const QString Xml_EquipmentError::elementName_Error_A = "Error_A";
const QString Xml_EquipmentError::elementName_Error_E = "Error_E";

void Xml_EquipmentError::WriteToFile(QXmlStreamWriter &writer, const QString &name,
                                                             const EquipmentError &error)
{
    writer.writeStartElement(name);

    writer.writeTextElement(Xml_EquipmentError::elementName_Error_R, QString::number(error.Error_R));
    writer.writeTextElement(Xml_EquipmentError::elementName_Error_A, QString::number(error.Error_A));
    writer.writeTextElement(Xml_EquipmentError::elementName_Error_E, QString::number(error.Error_E));

    writer.writeEndElement();
}
