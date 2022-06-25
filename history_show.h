#ifndef HISTORY_SHOW_H
#define HISTORY_SHOW_H

#include <QDialog>
#include "film.h"
#include "user.h"
#include "usertickets.h"
extern user person;

namespace Ui {
class history_show;
}

class history_show : public QDialog
{
    Q_OBJECT

public:
    explicit history_show(QWidget *parent = nullptr);
    ~history_show();

private:
    Ui::history_show *ui;
    FILE* fptr;
    film filmFile;
    userTickets userTicketFile;
    bool check;
    int fileFilmCount;
};

#endif // HISTORY_SHOW_H
