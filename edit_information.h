#ifndef EDIT_INFORMATION_H
#define EDIT_INFORMATION_H

#include <QDialog>
#include "film.h"
#include "actor.h"
#include "tmpactor.h"
#include "tmpfilm.h"
namespace Ui {
class Edit_information;
}

class Edit_information : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_information(QWidget *parent = nullptr);
    ~Edit_information();

private slots:
    void on_cinfirm_name_of_film_clicked();

    void on_update_information_clicked();

    void on_confirm_actor_clicked();

    void on_confirm_edite_actor_clicked();

    void on_update_actors_clicked();

private:
    Ui::Edit_information *ui;
    FILE* fptr;
    FILE* fp;
    film filmFile;
    actor actorFile;
    int counter;
    int filecounter;
    tmpFilm tmpeditFilm;
    film editFilm;
    tmpActor tmpEditactorConfirm;
    tmpActor tmpEditactor;
    actor EditactorConfirm;
    actor Editactor;
    bool checkfile;
};

#endif // EDIT_INFORMATION_H
