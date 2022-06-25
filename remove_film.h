#ifndef REMOVE_FILM_H
#define REMOVE_FILM_H

#include <QDialog>
#include "tmpfilm.h"
#include "film.h"
#include "actor.h"
#include "tmpactor.h"

namespace Ui {
class remove_film;
}

class remove_film : public QDialog
{
    Q_OBJECT

public:
    explicit remove_film(QWidget *parent = nullptr);
    ~remove_film();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::remove_film *ui;
    tmpFilm tmpFilmRemove;
    film FilmRmove;
    film filmFile;
    actor fileActor;
    int fileFilmeCount;
    int actorFileCount;
    int fileActoreRemoveCount;
    int cnt;
    bool checkFile;
    FILE* fptr;
    void remove_func();
    void remove_actors();
};

#endif // REMOVE_FILM_H
