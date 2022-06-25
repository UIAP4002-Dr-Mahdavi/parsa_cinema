#include "list.h"
#include "ui_list.h"


list::list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::list)
{
    ui->setupUi(this);
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
     fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
         fread(&filmFile,sizeof(film),1,fptr);
        if(feof(fptr)==true) break;
        ui->list_2->append(QString::number(counter));
        ui->list_2->moveCursor(QTextCursor::End);
        ui->list_2->insertPlainText("_");
        counter++;
        ui->list_2->append("name: ");
        ui->list_2->moveCursor(QTextCursor::End);
        ui->list_2->insertPlainText(filmFile.name);
        ui->list_2->append("genre: ");
        ui->list_2->moveCursor(QTextCursor::End);
        ui->list_2->insertPlainText(filmFile.genre);
        ui->list_2->append("director: ");
        ui->list_2->moveCursor(QTextCursor::End);
        ui->list_2->insertPlainText(filmFile.director);
        ui->list_2->append("capacity: ");
        ui->list_2->moveCursor(QTextCursor::End);
        ui->list_2->insertPlainText(QString::number(filmFile.capacity));
        ui->list_2->append("---------------------------------------");
    }
    fclose(fptr);
    ui->list_2->setReadOnly(true);
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

list::~list()
{
    delete ui;
}
