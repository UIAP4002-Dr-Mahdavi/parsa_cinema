#include "search.h"
#include "ui_search.h"
#include "QString"
#include "QMessageBox"
search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    ui->textEdit->clear();
    ui->pushButton_actor->setVisible(true);
    ui->pushButton_genre->setVisible(true);
    ui->pushButton_director->setVisible(true);
}

search::~search()
{
    delete ui;
}

void search::on_pushButton_genre_clicked()
{
   ui->pushButton_actor->setVisible(false);
   ui->pushButton_director->setVisible(false);
   checkGenre=true;
   checkActor=false;
   checkDirector=false;
  // tmpFilmSearch.Genre=ui->lineEdit->text();
}

void search::on_pushButton_director_clicked()
{
    ui->pushButton_actor->setVisible(false);
    ui->pushButton_genre->setVisible(false);
    checkGenre=true;
    checkActor=false;
    checkDirector=true;
  //  tmpFilmSearch.Director=ui->lineEdit->text();
}

void search::on_pushButton_actor_clicked()
{
    ui->pushButton_genre->setVisible(false);
    ui->pushButton_director->setVisible(false);
    checkGenre=false;
    checkActor=true;
    checkDirector=false;
   // tmpSearchActor.Name=ui->lineEdit->text();
}

void search::on_pushButton_confirm_clicked()
{
    if(checkGenre==true)
    {
       tmpFilmSearch.Genre=ui->lineEdit->text();
       if(tmpFilmSearch.Genre!="")
       {
           checkFile=false;
           tmpFilmSearch.setFilmInfo(&filmSearch);
           fopen_s(&fptr,"films","a+");
           fseek(fptr,0,SEEK_SET);
           while(feof(fptr)==false)
           {
               fread(&fileFilm,sizeof(film),1,fptr);
               if(feof(fptr)==true)break;
               if(strcmp(fileFilm.genre,filmSearch.genre)==0)
               {
                   checkFile=true;
                   filmSearch=fileFilm;
                   break;
               }
           }
           fclose(fptr);
           if(checkFile==false)
           {
                    QMessageBox::information(this,"warning","this genre is wrong");
                    ui->lineEdit->setText("");
                    ui->pushButton_actor->setVisible(true);
                    ui->pushButton_genre->setVisible(true);
                    ui->pushButton_director->setVisible(true);
           }
           else
           {
               ui->textEdit->clear();
               ui->lineEdit->setText("");
               ui->pushButton_actor->setVisible(true);
               ui->pushButton_director->setVisible(true);
               fopen_s(&fptr,"films","a+");
               fseek(fptr,0,SEEK_SET);
               while(feof(fptr)==false)
               {
                   fread(&fileFilm,sizeof(film),1,fptr);
                   if(feof(fptr)==true)break;
                   if(strcmp(fileFilm.genre,filmSearch.genre)==0)
                   {
                       ui->textEdit->append(fileFilm.name);
                   }
               }
               fclose(fptr);
           }

       }
    }
    if(checkDirector==true)
    {
       tmpFilmSearch.Director=ui->lineEdit->text();
       if(tmpFilmSearch.Director!="")
       {
           checkFile=false;
           tmpFilmSearch.setFilmInfo(&filmSearch);
           fopen_s(&fptr,"films","a+");
           fseek(fptr,0,SEEK_SET);
           while(feof(fptr)==false)
           {
               fread(&fileFilm,sizeof(film),1,fptr);
               if(feof(fptr)==true)break;
               if(strcmp(fileFilm.director,filmSearch.director)==0)
               {
                   checkFile=true;
                   filmSearch=fileFilm;
                   break;
               }
           }
           fclose(fptr);
           if(checkFile==false)
           {
                    QMessageBox::information(this,"warning","wrong name");
                    ui->lineEdit->setText("");
                    ui->pushButton_actor->setVisible(true);
                    ui->pushButton_genre->setVisible(true);
                    ui->pushButton_director->setVisible(true);
           }
           else
           {
               ui->textEdit->clear();
               ui->lineEdit->setText("");
               ui->pushButton_actor->setVisible(true);
               ui->pushButton_genre->setVisible(true);
               fopen_s(&fptr,"films","a+");
               fseek(fptr,0,SEEK_SET);
               while(feof(fptr)==false)
               {
                   fread(&fileFilm,sizeof(film),1,fptr);
                   if(feof(fptr)==true)break;
                   if(strcmp(fileFilm.director,filmSearch.director)==0)
                   {
                       ui->textEdit->append(fileFilm.name);
                   }
               }
               fclose(fptr);
           }
       }
    }
    if(checkActor==true)
    {
        tmpSearchActor.Name=ui->lineEdit->text();
        if(tmpSearchActor.Name!="")
        {
           checkFile=false;
           tmpSearchActor.setName(&searchActor);
           fopen_s(&fptr,"actors","a+");
           fseek(fptr,0,SEEK_SET);
           while(feof(fptr)==false)
           {
               fread(&fileActor,sizeof(actor),1,fptr);
               if(feof(fptr)==true)break;
               if(strcmp(fileActor.name,searchActor.name)==0)
               {
                   checkFile=true;
                   searchActor=fileActor;
                   break;
               }
           }
           fclose(fptr);
           if(checkFile==false)
           {
               QMessageBox::information(this,"warning","wrong name");
               ui->lineEdit->setText("");
               ui->pushButton_actor->setVisible(true);
               ui->pushButton_genre->setVisible(true);
               ui->pushButton_director->setVisible(true);
           }
           else
           {
               ui->textEdit->clear();
               ui->lineEdit->setText("");
               ui->pushButton_genre->setVisible(true);
               ui->pushButton_director->setVisible(true);
               fopen_s(&fptr,"actors","a+");
               fseek(fptr,0,SEEK_SET);
               while(feof(fptr)==false)
               {
                   fread(&fileActor,sizeof(actor),1,fptr);
                   if(feof(fptr)==true)break;
                   if(strcmp(fileActor.name,searchActor.name)==0)
                   {
                       ui->textEdit->append(fileActor.FilmName);
                   }
               }
               fclose(fptr);
           }
        }
    }
}
