#ifndef BUY_TICKET_H
#define BUY_TICKET_H

#include <QDialog>
#include "tmpfilm.h"
#include "film.h"
#include "usertickets.h"
#include "user.h"
#include "temp.h"
extern user person;

namespace Ui {
class buy_ticket;
}

class buy_ticket : public QDialog
{
    Q_OBJECT

public:
    explicit buy_ticket(QWidget *parent = nullptr);
    ~buy_ticket();

private slots:
    void on_confirm_clicked();

private:
    Ui::buy_ticket *ui;
    tmpFilm tmpFilmTicket;
    film filmTicket;
    userTickets userTick;
    film filmFile;
    userTickets userTickFile;
    bool checkTicketFile;
    bool checkFile;
    bool checkRemainTickets;
    FILE* fptr;
};

#endif // BUY_TICKET_H
