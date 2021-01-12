#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif

#define CHECK_BOX_COLUMN 0
#define File_PATH_COLUMN 1
#include "ocrtablemodel.h"

OCRTableModel::OCRTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

// 行数
int OCRTableModel::rowCount(const QModelIndex &parent) const
{
    return 10;
}

// 列数
int OCRTableModel::columnCount(const QModelIndex &parent) const
{
    return 8;
}


// 表格项数据
QVariant OCRTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int nRow = index.row();
    int nColumn = index.column();

    switch (role)
    {

    case Qt::TextAlignmentRole:
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    case Qt::DisplayRole:
    {

    }
    case Qt::UserRole:
    {
        //if (nColumn == 0)
            //return record.bChecked;
    }
    default:
        return QVariant();
    }

    return QVariant();
}



// 表格可选中、可复选
Qt::ItemFlags OCRTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return QAbstractItemModel::flags(index);

    Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    if(index.column()==0)
    {
          flags|=Qt::ItemIsUserCheckable;
    }
    return flags;
}
