#ifndef FILM_H
#define FILM_H
#include <QString>

class Film
{

public:
    QString title;
    QString director;
    QString budget;
    Film();
    Film(QString title,QString director,QString budget);

    QString getTitle() const { return title; }
    QString getDir() const { return director; }
    QString getBud()const { return budget; }
};

#endif // FILM_H
