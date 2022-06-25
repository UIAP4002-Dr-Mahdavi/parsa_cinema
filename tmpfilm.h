#ifndef TMPFILM_H
#define TMPFILM_H
#include "QString"
#include "film.h"
class tmpFilm
{
public:
    tmpFilm();
    QString Name;
    QString Genre;
    QString Director;
    char tmpName[30];
    char tmpGenre[30];
    char tmpDirector[30];
    void setFilmInfo(film*);
};

#endif // TMPFILM_H
