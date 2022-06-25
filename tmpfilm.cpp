#include "tmpfilm.h"
#include "QDebug"
tmpFilm::tmpFilm()
{

}

void tmpFilm::setFilmInfo(film *flm)
{
    memcpy(this->tmpName,this->Name.toStdString().c_str(),this->Name.size());
    this->tmpName[this->Name.size()]=NULL;
    strcpy(flm->name,(char*)this->tmpName);

    memcpy(this->tmpGenre,this->Genre.toStdString().c_str(),this->Genre.size());
    this->tmpGenre[this->Genre.size()]=NULL;
    strcpy(flm->genre,(char*)this->tmpGenre);

    memcpy(this->tmpDirector,this->Director.toStdString().c_str(),this->Director.size());
    this->tmpDirector[this->Director.size()]=NULL;
    strcpy(flm->director,(char*)this->tmpDirector);
}
