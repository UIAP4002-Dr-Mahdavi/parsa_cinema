#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H
#include "temp.h"
#include "user.h"
#include <QDialog>
extern temp tmp;
extern user person;
namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogLogin *ui;
};

#endif // DIALOGLOGIN_H
