#include "listmodel.h"
#include <QList>
#include "roster.h"
ListModel::ListModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}

bool ListModel::IsEmpty()
{
    return list.empty();
}

QModelIndex ListModel::index(int row, int column, const QModelIndex &parent) const
{
    return this->createIndex(row,column);
}
QModelIndex ListModel::parent (const QModelIndex &child) const
{
    return QModelIndex();
}
int ListModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        return 2;
    }
    return 0;
}
int ListModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}
QVariant ListModel::data (const QModelIndex &index, int role) const
{
    Roster data;
    data = list.at(index.row());
    if(index.isValid()) {
        if(Qt::DisplayRole == role){
            switch (index.column()) {
            case 0:{
                return QString(data.setU());
            }
            case 1:
                return QString(data.setN());
            case 2:
               return QString(data.setA());
            case 3:{
                return QString(data.setT());
                }
            }
        }
    }
    return QVariant();
}

void ListModel::Send(Roster Data)
{
    this->list.append(Data);
}
