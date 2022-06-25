#include "edit_information.h"
#include "ui_edit_information.h"
#include "QString"
#include "QDebug"
#include "QMessageBox"
Edit_information::Edit_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_information)
{
    ui->setupUi(this);
    ui->lineEdit_confirm_actor->setVisible(false);
    ui->confirm_edite_actor->setVisible(false);
    ui->lineEdit_actor->setVisible(false);
    ui->confirm_actor->setVisible(false);
    ui->update_actors->setVisible(false);
    ui->update_information->setVisible(true);
    ui->update_actors->setVisible(false);
    ui->lineEdit->setReadOnly(false);
    ui->lineEditGenre->setReadOnly(true);
    ui->lineEditName->setReadOnly(true);
    ui->lineEditCapacity->setReadOnly(true);
    ui->lineEditDirector->setReadOnly(true);
    counter=1;
    fopen_s(&fptr,"films","a+");
    fseek(fptr,0,SEEK_SET);
    filecounter=0;
    while(feof(fptr)==false)
    {
        fread(&filmFile,sizeof(film),1,fptr);
        filecounter++;
    }
    filecounter--;
    qDebug()<<filecounter;
     fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
         fread(&filmFile,sizeof(film),1,fptr);
        if(feof(fptr)==true) break;
        ui->list->append(QString::number(counter));
        ui->list->moveCursor(QTextCursor::End);
        ui->list->insertPlainText("_");
        counter++;
        ui->list->append("name: ");
        ui->list->moveCursor(QTextCursor::End);
        ui->list->insertPlainText(filmFile.name);
        ui->list->append("genre: ");
        ui->list->moveCursor(QTextCursor::End);
        ui->list->insertPlainText(filmFile.genre);
        ui->list->append("director: ");
        ui->list->moveCursor(QTextCursor::End);
        ui->list->insertPlainText(filmFile.director);
        ui->list->append("capacity: ");
        ui->list->moveCursor(QTextCursor::End);
        ui->list->insertPlainText(QString::number(filmFile.capacity));
        ui->list->append("---------------------------------------");
    }
    fclose(fptr);
    ui->list->setReadOnly(true);
    filecounter=0;
    fopen_s(&fptr,"actors","a+");
    fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
        fread(&filmFile,sizeof(actor),1,fptr);
        filecounter++;
    }
    filecounter--;
    actor* arr=new actor[filecounter];
    fseek(fptr,0,SEEK_SET);
    for(int i=0;i<filecounter;i++)
    {
        fread(&arr[i],sizeof(actor),1,fptr);
    }
    fclose(fptr);
    for(int i=0;i<filecounter;i++)
    {
        if(i==0)
        {
            ui->actors_list->append(arr[i].FilmName);
            ui->actors_list->moveCursor(QTextCursor::End);
            ui->actors_list->insertPlainText(":");
        }
        if(i!=0 && strcmp(arr[i].FilmName,arr[i-1].FilmName)!=0)
        {
            ui->actors_list->append("--------------------------");
            ui->actors_list->append(arr[i].FilmName);
            ui->actors_list->moveCursor(QTextCursor::End);
            ui->actors_list->insertPlainText(":");
        }
        ui->actors_list->append(arr[i].name);

    }
}
Edit_information::~Edit_information()
{
    delete ui;
}

void Edit_information::on_cinfirm_name_of_film_clicked()
{
    tmpeditFilm.Name=ui->lineEdit->text();
    if(tmpeditFilm.Name!="")
   {
    tmpeditFilm.setFilmInfo(&editFilm);
    checkfile=false;
    fopen_s(&fptr,"films","a+");
    fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
        fread(&filmFile,sizeof(film),1,fptr);
        if(feof(fptr)==true)
            break;
        if(strcmp(filmFile.name,editFilm.name)==0)
        {
            ui->lineEdit_confirm_actor->setVisible(true);
            ui->confirm_edite_actor->setVisible(true);
            ui->lineEdit_actor->setVisible(true);
            ui->confirm_actor->setVisible(true);
            ui->lineEdit_actor->setReadOnly(true);
            checkfile=true;
           editFilm=filmFile;
            break;
        }

    }
    fclose(fptr);
    if(checkfile==true)
    {
    ui->lineEditGenre->setReadOnly(false);
    ui->lineEditName->setReadOnly(false);
    ui->lineEditCapacity->setReadOnly(false);
    ui->lineEditDirector->setReadOnly(false);
   // ui->lineEdit->setReadOnly(true);

   ui->lineEditName->setText(editFilm.name);
    ui->lineEditDirector->setText(editFilm.director);
    ui->lineEditGenre->setText(editFilm.genre);
    ui->lineEditCapacity->setText(QString::number(editFilm.capacity));
    ui->update_information->setVisible(true);
    }
    else
    {
       ui->lineEdit->setText("");
       QMessageBox::information(this,"warning","this name is false");
    }

  }

}

void Edit_information::on_update_information_clicked()
{
    editFilm.capacity=ui->lineEditCapacity->text().toInt();
    tmpeditFilm.Genre=ui->lineEditGenre->text();
    tmpeditFilm.Name=ui->lineEditName->text();
    tmpeditFilm.Director=ui->lineEditDirector->text();
    if( editFilm.capacity>0 && tmpeditFilm.Genre!="" && tmpeditFilm.Name!="" && tmpeditFilm.Director!="" )
    {
        tmpeditFilm.setFilmInfo(&editFilm);
        fopen_s(&fptr,"films","r+");
        fseek(fptr,0,SEEK_SET);
        fread(&filmFile,sizeof(film),1,fptr);
        while(feof(fptr)==false)
        {
            if(feof(fptr)==true)
                break;
            if(strcmp(filmFile.name,editFilm.name)==0)
            {
                fseek(fptr,(-1)*sizeof(film),SEEK_CUR);
                fwrite(&editFilm,sizeof(film),1,fptr);
              //  ui->update_actors->setVisible(true);
                break;
            }
             fread(&filmFile,sizeof(film),1,fptr);
        }
        fclose(fptr);
        ui->list->clear();
        fopen_s(&fptr,"films","a+");
        fseek(fptr,0,SEEK_SET);
        counter=1;
        fread(&filmFile,sizeof(film),1,fptr);
        while(feof(fptr)==false)
        {
            if(feof(fptr)==true) break;
            ui->list->append(QString::number(counter));
            ui->list->moveCursor(QTextCursor::End);
            ui->list->insertPlainText("_");
            counter++;
            ui->list->append("name: ");
            ui->list->moveCursor(QTextCursor::End);
            ui->list->insertPlainText(filmFile.name);
            ui->list->append("genre: ");
            ui->list->moveCursor(QTextCursor::End);
            ui->list->insertPlainText(filmFile.genre);
            ui->list->append("director: ");
            ui->list->moveCursor(QTextCursor::End);
            ui->list->insertPlainText(filmFile.director);
            ui->list->append("capacity: ");
            ui->list->moveCursor(QTextCursor::End);
            ui->list->insertPlainText(QString::number(filmFile.capacity));
            ui->list->append("---------------------------------------");
            fread(&filmFile,sizeof(film),1,fptr);
        }
        fclose(fptr);
        ui->list->setReadOnly(true);

    }



}

void Edit_information::on_confirm_actor_clicked()
{
    tmpEditactorConfirm.Name=ui->lineEdit_confirm_actor->text();
    checkfile=false;
    if(tmpEditactorConfirm.Name!="")
    {
        tmpEditactorConfirm.setName(&EditactorConfirm);
        strcpy(EditactorConfirm.FilmName,editFilm.name);
        fopen_s(&fptr,"actors","a+");
        fseek(fptr,0,SEEK_SET);
        while(feof(fptr)==false)
        {
            fread(&actorFile,sizeof(actor),1,fptr);
            if(feof(fptr)==true)break;
            if(strcmp(actorFile.name,EditactorConfirm.name)==0 && strcmp(actorFile.FilmName,EditactorConfirm.FilmName)==0)
            {
                checkfile=true;
                ui->lineEdit_confirm_actor->setReadOnly(true);
                ui->lineEdit_actor->setReadOnly(false);
                break;
            }
        }
        fclose(fptr);
        if(checkfile==false)
        {
           QMessageBox::information(this,"warning","wrong name for actor");
        }

    }
}

void Edit_information::on_confirm_edite_actor_clicked()
{
    tmpEditactor.Name=ui->lineEdit_actor->text();
    if(tmpEditactor.Name!="")
    {
        tmpEditactor.setName(&Editactor);
        strcpy(Editactor.FilmName,editFilm.name);
        fopen_s(&fptr,"actors","r+");
        fseek(fptr,0,SEEK_SET);
        while(feof(fptr)==false)
        {
            fread(&actorFile,sizeof(actor),1,fptr);
            if(feof(fptr)==true)break;
            if(strcmp(actorFile.name,EditactorConfirm.name)==0 && strcmp(actorFile.FilmName,EditactorConfirm.FilmName)==0)
            {
                fseek(fptr,(-1)*sizeof(actor),SEEK_CUR);
                fwrite(&Editactor,sizeof(actor),1,fptr);
                ui->update_actors->setVisible(true);
                break;
            }
        }
        fclose(fptr);

    }

}
void Edit_information::on_update_actors_clicked()
{
    ui->actors_list->clear();
    filecounter=0;
    fopen_s(&fptr,"actors","a+");
    fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
        fread(&filmFile,sizeof(actor),1,fptr);
        filecounter++;
    }
    filecounter--;
    actor* arr=new actor[filecounter];
    fseek(fptr,0,SEEK_SET);
    for(int i=0;i<filecounter;i++)
    {
        fread(&arr[i],sizeof(actor),1,fptr);
    }
    fclose(fptr);
    for(int i=0;i<filecounter;i++)
    {
        if(i==0)
        {
            ui->actors_list->append(arr[i].FilmName);
            ui->actors_list->moveCursor(QTextCursor::End);
            ui->actors_list->insertPlainText(":");
        }
        if(i!=0 && strcmp(arr[i].FilmName,arr[i-1].FilmName)!=0)
        {
            ui->actors_list->append("--------------------------");
            ui->actors_list->append(arr[i].FilmName);
            ui->actors_list->moveCursor(QTextCursor::End);
            ui->actors_list->insertPlainText(":");
        }
        ui->actors_list->append(arr[i].name);

    }
    ui->actors_list->setReadOnly(true);
    ui->lineEdit_confirm_actor->setText("");
    ui->lineEdit_actor->setText("");
    ui->lineEdit_actor->setReadOnly(true);
    ui->lineEdit_confirm_actor->setReadOnly(false);
}
