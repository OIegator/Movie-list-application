#include "film.h"

Film::Film()
{
    title = "";
    director = "";
    budget = "";
}

Film::Film(QString title,QString director,QString budget)
{
    this->title = title;
    this->director = director;
    this->budget = budget;
}
