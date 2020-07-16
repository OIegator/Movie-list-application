#include "mytablemodel.h"

myTableModel::myTableModel()
{

}

int myTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return films.size(); // сделаем фиксированно 5 строк в таблице
    //если вы станете использовать скажем QList, то пишите return list.size();
}
int myTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3; // количество колонок сделаем также фиксированным
}

QVariant myTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Horizontal) {
        switch (section) {
        case TITLE:
            return QString("Название");
        case BUDGET:
            return QString("Стоимость");
        case DIRECTOR:
            return QString("Режиссёр");
        }
    } else {
        return section;
    }

    return QVariant();
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole) {
        if (index.column()==0)
            return films.at(index.row()).title;
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
    stream << movie.getTitle() << movie.getBud() << movie.getDir();
    if(stream.status() != QDataStream::Ok) {
        qDebug("Ошибка записи");
    }
}

void myTableModel::populateData(QList<Film> list){
    films=list;
}

void myTableModel::appendRow(Film f){
    Film a(f.title,f.budget,f.director);
    films.append(f);
}

void myTableModel::removeRow(int index){
    films.removeAt(index);
}

bool myTableModel::setValue(int index,Film f){
   if (index<0 && index>films.size())
       return false;
   films.replace(index,f);
   return true;
}
