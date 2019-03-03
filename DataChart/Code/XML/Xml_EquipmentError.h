#ifndef XML_EQUIPMENTERROR_H
#define XML_EQUIPMENTERROR_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QString>

struct EquipmentError;

class Xml_EquipmentError
{
public:
    Xml_EquipmentError();

    static void WriteToFile(QXmlStreamWriter &writer, const QString &name,
                                         const EquipmentError &error);

private:
    static const QString elementName_Error_R;
    static const QString elementName_Error_A;
    static const QString elementName_Error_E;
};

#endif // XML_EQUIPMENTERROR_H
