#include "registration.h"
#include "ui_registration.h"
#include "QMessageBox"
registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    tmp.USERNAME=ui->lineEditUsername->text();
    tmp.PASSWORD=ui->lineEditPassword->text();
    if(tmp.USERNAME!="admin"&&tmp.PASSWORD!="admin")
    {
        tmp.setusername(&person);
        tmp.setPassword(&person);
    }
    else {
        ui->lineEditPassword->setText("");
        ui->lineEditUsername->setText("");
        QMessageBox::information(this,"wrning","you cannot use this informations");
    }

}
