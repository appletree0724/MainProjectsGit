#ifndef XML_SPOTADDRESS_H
#define XML_SPOTADDRESS_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QString>

struct SpotAddress;

class Xml_SpotAddress
{
public:
    Xml_SpotAddress();

    static void WriteToFile(QXmlStreamWriter &writer, const QString& name,
                                         const SpotAddress& address);

private:
    static const QString elementName_B;
    static const QString elementName_L;
    static const QString elementName_H;
};

#endif // XML_SPOTADDRESS_H
