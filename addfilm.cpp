#include "addfilm.h"
#include "ui_addfilm.h"
#include "QDebug"
addFilm::addFilm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addFilm)
{
    ui->setupUi(this);
    ui->confirm_inf->setVisible(true);
    ui->name->setReadOnly(false);
    ui->genre->setReadOnly(false);
    ui->director->setReadOnly(false);
    ui->capacity->setReadOnly(false);
    ui->name->setText("");
    ui->genre->setText("");
    ui->director->setText("");
    ui->actor_name->setReadOnly(true);
}

addFilm::~addFilm()
{
    delete ui;
}

void addFilm::on_confirm_inf_clicked()
{
    tmpf.Name=ui->name->text();
    tmpf.Genre=ui->genre->text();
    tmpf.Director=ui->director->text();
    sample.capacity=ui->capacity->text().toInt();
    if(tmpf.Name!="" && tmpf.Genre!="" && tmpf.Director!=""&& sample.capacity>0)
    {
           tmpf.setFilmInfo(&sample);
           fopen_s(&fptr,"films","a+");
           fseek(fptr,0,SEEK_END);
           fwrite(&sample,sizeof(film),1,fptr);
           fclose(fptr);
              ui->confirm_inf->setVisible(false);
            ui->genre->setReadOnly(true);
            ui->name->setReadOnly(true);
            ui->director->setReadOnly(true);
            ui->capacity->setReadOnly(true);
            ui->actor_name->setReadOnly(false);
    }
    fopen_s(&fptr,"films","a+");
    fseek(fptr,0,SEEK_SET);
    filecounter=0;
    while(feof(fptr)==false)
    {
        fread(&filmFile,sizeof(film),1,fptr);
        filecounter++;
    }
    filecounter--;
    fclose(fptr);
    qDebug()<<filecounter;
}

void addFilm::on_confirm_actor_clicked()
{
    tmpAct.Name=ui->actor_name->text();
    if(tmpAct.Name !="")
    {
        tmpAct.setName(&act);
        strcpy(act.FilmName,sample.name);
         fopen_s(&fptr,"actors","a+");
         fseek(fptr,0,SEEK_END);

         fwrite(&act,sizeof(actor),1,fptr);
         fclose(fptr);
         ui->actor_name->setText("");
    }
}
