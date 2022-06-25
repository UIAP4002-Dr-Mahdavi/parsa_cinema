#include "history_show.h"
#include "ui_history_show.h"
#include "QString"
history_show::history_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::history_show)
{
    ui->setupUi(this);
    ui->list->clear();
    fopen_s(&fptr,"films","a+");
    fseek(fptr,0,SEEK_SET);
    fileFilmCount=0;
    while(feof(fptr)==false)
    {
        fread(&filmFile,sizeof(film),1,fptr);
        fileFilmCount++;
    }
    fileFilmCount--;
    film* arr=new film[fileFilmCount];
    fseek(fptr,0,SEEK_SET);
    for(int i=0;i<fileFilmCount;i++)
    {
        fread(&arr[i],sizeof(film),1,fptr);
    }
    fclose(fptr);
    fopen_s(&fptr,"tickets","a+");
    fseek(fptr,0,SEEK_SET);
    while(feof(fptr)==false)
    {
        fread(&userTicketFile,sizeof(userTickets),1,fptr);
        if(feof(fptr)==true)break;
        if(strcmp(person.password,userTicketFile.password)==0)
        {
            check=false;
            for(int i=0;i<fileFilmCount;i++)
            {
                if(strcmp(arr[i].name,userTicketFile.film_name)==0)
                {
                    check=true;
                    break;
                }
            }
            if(check==true)
            {
                ui->list->append("film: ");
                ui->list->moveCursor(QTextCursor::End);
                ui->list->insertPlainText(userTicketFile.film_name);
                ui->list->moveCursor(QTextCursor::End);
                ui->list->insertPlainText("  ");
                ui->list->append("numbers of tickets whitch you bought: ");
                ui->list->moveCursor(QTextCursor::End);
                ui->list->insertPlainText(QString::number(userTicketFile.numberOfTickets));
                ui->list->append("--------------------------------");
            }
        }
    }
    fclose(fptr);
}

history_show::~history_show()
{
    delete ui;
}
