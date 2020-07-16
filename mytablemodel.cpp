#include "mytablemodel.h"

myTableModel::myTableModel()
{

}

int myTableModel::rowCount(const QModelIndex &parent) const
{
    return films.size(); // сделаем фиксированно 5 строк в таблице
    //если вы станете использовать скажем QList, то пишите return list.size();
}
int myTableModel::columnCount(const QModelIndex &parent) const
{
    return 3; // количество колонок сделаем также фиксированным
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole) {
        if (index.column()==0)
            return films.at(index.row()).name;
        if (index.column()==1)
            return films.at(index.row()).budget;
        if (index.column()==2)
            return films.at(index.row()).director;
        QString unswer = QString("row = ") + QString::number(index.row()) + "  col = " + QString::number(index.column());
        // строкой выше мы формируем ответ. QString::number преобразует число в текст
        return QVariant(unswer);
    }
    return QVariant();
}

void myTableModel::insertRow(Film movie, QFile file)
{
    QDataStream stream(&file);
    stream << movie.getName() << movie.getBud() << movie.getDir();
    if(stream.status() != QDataStream::Ok) {
        qDebug("Ошибка записи");
    }
}

void myTableModel::populateData(QList<Film> list){
    films=list;
}
