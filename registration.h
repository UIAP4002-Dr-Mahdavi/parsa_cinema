#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include "temp.h"
#include "user.h"
extern temp tmp;
extern user person;
namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registration *ui;
};

#endif // REGISTRATION_H
