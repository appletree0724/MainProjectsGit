#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <string>

using namespace std;

struct CustomerData
{
    QString Name;
    int Age;
    QString Company;
    QString Title;

    static const size_t ElementCount = 4;
};

#endif // CUSTOMERDATA_H
