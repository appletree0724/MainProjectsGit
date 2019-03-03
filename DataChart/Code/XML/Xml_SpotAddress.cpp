#include "Xml_SpotAddress.h"
#include "SpotAddress.h"

Xml_SpotAddress::Xml_SpotAddress()
{
}

const QString Xml_SpotAddress::elementName_B = "B";
const QString Xml_SpotAddress::elementName_L = "L";
const QString Xml_SpotAddress::elementName_H = "H";

void Xml_SpotAddress::WriteToFile(QXmlStreamWriter &writer, const QString &name,
                                                         const SpotAddress &address)
{
    writer.writeStartElement(name);

    writer.writeTextElement(Xml_SpotAddress::elementName_B, QString::number(address.B));
    writer.writeTextElement(Xml_SpotAddress::elementName_L, QString::number(address.L));
    writer.writeTextElement(Xml_SpotAddress::elementName_H, QString::number(address.H));

    writer.writeEndElement();
}
