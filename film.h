#ifndef FILM_H
#define FILM_H
#include <QString>

class Film
{


public:
    QString name,director;
    QString budget;
    Film();
    Film(QString name,QString director,QString budget);

    void setName(QString name);
    void setDir(QString director);
    void setBud(int budget);

    QString getName() const {return name;}
    QString getDir() const {return director;}
    QString getBud()const {return budget;}
};

#endif // FILM_H
