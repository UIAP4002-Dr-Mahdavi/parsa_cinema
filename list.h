#ifndef LIST_H
#define LIST_H

#include <QDialog>
#include "film.h"
#include "actor.h"
#include "tmpactor.h"
#include "tmpfilm.h"

namespace Ui {
class list;
}

class list : public QDialog
{
    Q_OBJECT

public:
    explicit list(QWidget *parent = nullptr);
    ~list();

private:
    Ui::list *ui;
    FILE* fptr;
    FILE* fp;
    film filmFile;
    actor actorFile;
    int counter;
    int filecounter;
    tmpFilm tmpeditFilm;
    bool checkfile;
};

#endif // LIST_H
