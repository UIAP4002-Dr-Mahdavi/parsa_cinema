#ifndef ADDFILM_H
#define ADDFILM_H
#include "QString"
#include "tmpfilm.h"
#include "film.h"
#include "actor.h"
#include "tmpactor.h"
#include <QDialog>
namespace Ui {
class addFilm;
}

class addFilm : public QDialog
{
    Q_OBJECT

public:
    explicit addFilm(QWidget *parent = nullptr);
    ~addFilm();

private slots:
    void on_confirm_inf_clicked();

    void on_confirm_actor_clicked();

private:
    Ui::addFilm *ui;
    FILE *fptr;
    tmpFilm tmpf;
    film sample;
    film filmFile;
    tmpActor tmpAct;
    actor act;
    actor actFile;
    int filecounter;
};

#endif // ADDFILM_H
