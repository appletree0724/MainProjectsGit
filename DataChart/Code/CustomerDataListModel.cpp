#include "CustomerDataListModel.h"
#include "CustomerData.h"

CustomerDataListModel::CustomerDataListModel(vector<CustomerData> &customerDataList, QObject *parent)
                                       : QAbstractItemModel(parent), customerDataList(customerDataList)
{
}

int CustomerDataListModel::rowCount(const QModelIndex &/*parent*/) const
{
    return (int)this->customerDataList.size();
}

QVariant CustomerDataListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(index.row() > (int)this->customerDataList.size())
        return QVariant();

    if(index.column() > (int)CustomerData::ElementCount)
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        CustomerData data = this->customerDataList[index.row()];

        if(index.column() == 0)
            return data.Name;
        else if(index.column() == 1)
            return data.Age;
        else if(index.column() == 2)
            return data.Company;
        else if(index.column() == 3)
            return data.Title;
    }

    return QVariant();
}
