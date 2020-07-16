#ifndef MYTABLEMODE_H
#define MYTABLEMODE_H
#include "film.h"

#include <QAbstractTableModel>
#include <QFile>
#include <QFileDialog>

class myTableModel : public QAbstractTableModel
{
public:
        myTableModel();
    void populateData(QList<Film> list);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void removeRow(int index);
    void insertRow(Film movie, QFile file);

    void appendRow(Film f);
    bool SetValue(int index,Film f);
    QList<Film> films;
};

#endif // MYTABLEMODE_H
