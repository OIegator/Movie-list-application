#include "film.h"

Film::Film()
{
    name="";
    director="";
    budget=0;
}

Film::Film(QString name,QString director,int budget){
    this->name=name;
    this->director=director;
    this->budget=budget;
}
