#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include "film.h"
#include "tmpfilm.h"
#include "actor.h"
#include "tmpactor.h"

namespace Ui {
class search;
}

class search : public QDialog
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private slots:
    void on_pushButton_genre_clicked();

    void on_pushButton_director_clicked();

    void on_pushButton_actor_clicked();

    void on_pushButton_confirm_clicked();

private:
    Ui::search *ui;
    film filmSearch;
    tmpFilm tmpFilmSearch;
    actor searchActor;
    tmpActor tmpSearchActor;
    actor fileActor;
    film fileFilm;
    bool checkFile;
    bool checkGenre;
    bool checkDirector;
    bool checkActor;
    FILE* fptr;
};

#endif // SEARCH_H
