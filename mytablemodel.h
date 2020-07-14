#ifndef MYTABLEMODE_H
#define MYTABLEMODE_H

#include <QAbstractTableModel>

class myTableModel : public QAbstractTableModel
{
public:
        myTableModel();
private:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // MYTABLEMODE_H
