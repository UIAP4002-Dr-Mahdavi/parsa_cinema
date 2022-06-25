#include "remove_film.h"
#include "ui_remove_film.h"
#include "QMessageBox"

remove_film::remove_film(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remove_film)
{
    ui->setupUi(this);
    ui->confirmButton->setVisible(true);
}

remove_film::~remove_film()
{
    delete ui;
}

void remove_film::on_confirmButton_clicked()
{
  tmpFilmRemove.Name=ui->lineEdit->text();
  if(tmpFilmRemove.Name!="")
  {
      checkFile=false;
      tmpFilmRemove.setFilmInfo(&FilmRmove);
      fopen_s(&fptr,"films","a+");
      fseek(fptr,0,SEEK_SET);
      while(feof(fptr)==false)
      {
          fread(&filmFile,sizeof(film),1,fptr);
          if(feof(fptr)==true)break;
          if(strcmp(filmFile.name,FilmRmove.name)==0)
          {
              checkFile=true;
              break;
          }
      }
      fclose(fptr);
      if(checkFile==false)
      {
          QMessageBox::information(this,"warning","this name is false");
          ui->lineEdit->setText("");
      }
      else {
          remove_func();
      }

  }
}

void remove_film::remove_func()
{
    fopen_s(&fptr,"films","a+");
    fseek(fptr,0,SEEK_SET);
    fileFilmeCount=0;
    while(feof(fptr)==false)
    {
        fread(&filmFile,sizeof(film),1,fptr);
        fileFilmeCount++;
    }
    fclose(fptr);
    fileFilmeCount=fileFilmeCount-2;
    film * arrFilm=new film[fileFilmeCount];
    fopen_s(&fptr,"films","a+");
    fseek(fptr,0,SEEK_SET);
    cnt=-1;
      while(feof(fptr)==false)
      {
          fread(&filmFile,sizeof(film),1,fptr);
          if(feof(fptr)==true)break;
          if(strcmp(filmFile.name,FilmRmove.name)!=0)
          {
              cnt++;
              arrFilm[cnt]=filmFile;
          }
      }
      fclose(fptr);
      fopen_s(&fptr,"films","w");
      for(int i=0;i<=cnt;i++)
      {
          fwrite(&arrFilm[i],sizeof(film),1,fptr);
      }
      fclose(fptr);
      remove_actors();
}

void remove_film::remove_actors()
{
    actorFileCount=0;
    fopen_s(&fptr,"actors","a+");
    fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
        fread(&fileActor,sizeof(actor),1,fptr);
        actorFileCount++;
    }
    fclose(fptr);
    actorFileCount--;
    fileActoreRemoveCount=0;
    fopen_s(&fptr,"actors","a+");
    fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
        fread(&fileActor,sizeof(actor),1,fptr);
        if(feof(fptr)==true)break;
        if(strcmp(fileActor.FilmName,FilmRmove.name)==0)
        {
            fileActoreRemoveCount++;
        }
    }
    fclose(fptr);
    actorFileCount=actorFileCount-fileActoreRemoveCount;
    actor* arrActor=new actor[actorFileCount];
    cnt=-1;
    fopen_s(&fptr,"actors","a+");
    fseek(fptr,0,SEEK_SET);
     while(feof(fptr)==false)
     {
         fread(&fileActor,sizeof(actor),1,fptr);
         if(feof(fptr)==true)break;
         if(strcmp(fileActor.FilmName,FilmRmove.name)!=0)
         {
             cnt++;
             arrActor[cnt]=fileActor;
         }
     }
     fclose(fptr);
     fopen_s(&fptr,"actors","w");
     for(int i=0;i<=cnt;i++)
     {
         fwrite(&arrActor[i],sizeof(actor),1,fptr);
     }
     fclose(fptr);
     ui->confirmButton->setVisible(false);
}

