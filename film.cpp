#include "film.h"

Film::Film()
{
    name="";
    director="";
    budget="";
}

Film::Film(QString name,QString director,QString budget){
    this->name=name;
    this->director=director;
    this->budget=budget;
}
