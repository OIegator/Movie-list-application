#ifndef MYTABLEMODE_H
#define MYTABLEMODE_H
#include "film.h"

#include <QAbstractTableModel>

class myTableModel : public QAbstractTableModel
{
public:
        myTableModel();
    void populateData(QList<Film> list);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
private:
    QList<Film> films;
};

#endif // MYTABLEMODE_H
