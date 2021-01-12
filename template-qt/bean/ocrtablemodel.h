#ifndef OCRTABLEMODEL_H
#define OCRTABLEMODEL_H
#include <QAbstractItemModel>
#include <QObject>


class OCRTableModel : public QAbstractTableModel
{
    Q_OBJECT
public: 
    explicit OCRTableModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // OCRTABLEMODEL_H

