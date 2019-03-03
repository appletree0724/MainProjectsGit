#ifndef CUSTOMERDATALISTMODEL_H
#define CUSTOMERDATALISTMODEL_H

#include <QObject>
#include <QVariant>
#include <QAbstractItemModel>

#include <vector>

using namespace std;

struct CustomerData;

class CustomerDataListModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    CustomerDataListModel(vector<CustomerData>& customerDataList, QObject * parent = 0);

    int rowCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

//    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

//    Qt::ItemFlags flags(const QModelIndex &index) const;

//    bool setData(const QModelIndex &index, const QVariant &value, int role);

//    bool insertRows(int row, int count, const QModelIndex &parent);

//    bool removeRows(int row, int count, const QModelIndex &parent);

private:
    vector<CustomerData> customerDataList;
};

#endif // CUSTOMERDATALISTMODEL_H
