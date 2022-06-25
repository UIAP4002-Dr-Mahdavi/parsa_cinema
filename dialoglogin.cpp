#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include "temp.h"

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_pushButton_clicked()
{
    tmp.USERNAME=ui->lineEditUsername->text();
    tmp.PASSWORD=ui->lineEditPassword->text();
    tmp.setusername(&person);
    tmp.setPassword(&person);
}
