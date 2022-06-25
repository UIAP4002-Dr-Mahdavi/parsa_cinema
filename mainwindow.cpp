#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialoglogin.h"
#include "registration.h"
#include "edit_information.h"
#include "list.h"
#include "history_show.h"
#include "buy_ticket.h"
#include "remove_film.h"
#include "addfilm.h"
#include "QMessageBox"
#include "QDebug"
#include "QString"
#include "temp.h"
#include "user.h"
temp tmp;
user person;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_history->setVisible(false);
    ui->pushButton_list->setVisible(false);
    ui->removeFilm->setVisible(false);
    ui->buy_ticket->setVisible(false);
    ui->password->setVisible(false);
    ui->username->setVisible(false);
    ui->add_Film->setVisible(false);
    ui->edit->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_log_in_clicked()
{
    DialogLogin login;
    login.setModal(true);
    login.exec();
    if(tmp.USERNAME=="admin"&&tmp.PASSWORD=="admin")
    {
        ui->edit->setVisible(true);
        ui->registration->setVisible(false);
        ui->log_in->setVisible(false);
        ui->setPassword->setText("admin");
        ui->setUsername->setText("admin");
        ui->setPassword->setVisible(true);
        ui->setUsername->setVisible(true);
        ui->password->setVisible(true);
        ui->username->setVisible(true);
        ui->add_Film->setVisible(true);
        ui->removeFilm->setVisible(true);
        ui->pushButton_list->setVisible(false);

    }
   else if(tmp.USERNAME==""||tmp.PASSWORD=="")
    {
       QMessageBox::information(this,"warn","You didn't enter informations");
    }
   else if(tmp.USERNAME!="" && tmp.PASSWORD!="" && checkLogin(person)==true)
    {
        ui->registration->setVisible(false);
        ui->log_in->setVisible(false);
        ui->setPassword->setVisible(true);
        ui->setUsername->setVisible(true);
        ui->buy_ticket->setVisible(true);
        ui->password->setVisible(true);
        ui->username->setVisible(true);
        ui->pushButton_list->setVisible(true);
        ui->pushButton_history->setVisible(true);
        ui->setPassword->setText(tmp.PASSWORD);
        ui->setUsername->setText(tmp.USERNAME);
    }
    else {
        QMessageBox::information(this,"warn","the username or passwprd is wrong");
    }
}

void MainWindow::on_log_out_clicked()
{
    ui->setPassword->setVisible(false);
    ui->setUsername->setVisible(false);
    ui->buy_ticket->setVisible(false);
    ui->log_in->setVisible(true);
    ui->registration->setVisible(true);
    ui->add_Film->setVisible(false);
    ui->edit->setVisible(false);
    ui->removeFilm->setVisible(false);
    ui->pushButton_history->setVisible(false);
}

void MainWindow::on_registration_clicked()
{
    registration reg;
    reg.setModal(true);
    reg.exec();
    if(tmp.USERNAME==""||tmp.PASSWORD=="")
    {
       QMessageBox::information(this,"warn","You didn't enter informations");
    }
   else if(tmp.USERNAME=="admin"||tmp.PASSWORD=="admin")
    {
        QMessageBox::information(this,"warning","you cant registrate with this username and password");
    }
   else if(tmp.USERNAME!="" && tmp.PASSWORD!="" && checkName(person)==true)
    {
        ui->setPassword->setVisible(true);
        ui->setUsername->setVisible(true);
        ui->buy_ticket->setVisible(true);
        ui->password->setVisible(true);
        ui->username->setVisible(true);
        ui->setPassword->setText(tmp.PASSWORD);
        ui->setUsername->setText(tmp.USERNAME);
        QMessageBox::information(this,"message","your registration was successfully");
    }
    else {

        QMessageBox::information(this,"warn","this password has been used already");
    }
}

bool MainWindow::checkName(user pr)
{
    filecheck=true;
    fopen_s(&fptr,"users","a+");
    fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
        fread(&personf,sizeof(user),1,fptr);
        if(strcmp(personf.password,pr.password)==0)
        {
            filecheck=false;
            break;
        }
    }
    fclose(fptr);
    if(filecheck==true)
    {
        fopen_s(&fptr,"users","a+");
        fseek(fptr,0,SEEK_END);
        fwrite(&pr,sizeof(user),1,fptr);
        fclose(fptr);
    }
    return filecheck;
}

bool MainWindow::checkLogin(user pr)
{
    filecheck=false;
    fopen_s(&fptr,"users","a+");
    fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
        fread(&personf,sizeof(user),1,fptr);
        if(strcmp(personf.password,pr.password)==0&&strcmp(personf.username,pr.username)==0)
        {
            filecheck=true;
            break;
        }
    }
    fclose(fptr);
    return filecheck;
}

void MainWindow::on_add_Film_clicked()
{
    addFilm addf;
    addf.setModal(true);
    addf.exec();
}

void MainWindow::on_edit_clicked()
{
    Edit_information edit;
    edit.setModal(true);
    edit.exec();
}

void MainWindow::on_removeFilm_clicked()
{
    remove_film removeF;
    removeF.setModal(true);
    removeF.exec();
}

void MainWindow::on_buy_ticket_clicked()
{
    buy_ticket tick;
    tick.setModal(true);
    tick.exec();
}

void MainWindow::on_pushButton_list_clicked()
{
    list ll;
    ll.setModal(true);
    ll.exec();
}

void MainWindow::on_pushButton_history_clicked()
{
    history_show history_sh;
    history_sh.setModal(true);
    history_sh.exec();
}
