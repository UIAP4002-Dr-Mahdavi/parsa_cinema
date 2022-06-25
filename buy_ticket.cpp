#include "buy_ticket.h"
#include "ui_buy_ticket.h"
#include "QMessageBox"
buy_ticket::buy_ticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buy_ticket)
{
    ui->setupUi(this);
    ui->confirm->setVisible(true);
}

buy_ticket::~buy_ticket()
{
    delete ui;
}

void buy_ticket::on_confirm_clicked()
{
    tmpFilmTicket.Name=ui->lineEdit->text();
    if(tmpFilmTicket.Name!="")
    {
        tmpFilmTicket.setFilmInfo(&filmTicket);
        strcpy(userTick.password,person.password);
        strcpy(userTick.film_name,filmTicket.name);
        checkFile=false;
        fopen_s(&fptr,"films","a+");
        fseek(fptr,0,SEEK_SET);
        while(feof(fptr)==false)
        {
            fread(&filmFile,sizeof(film),1,fptr);
            if(feof(fptr)==true)break;
            if(strcmp(filmFile.name,userTick.film_name)==0)
            {
                checkFile=true;
                        break;
            }
        }
        fclose(fptr);
        if(checkFile==false)
        {
            QMessageBox::information(this,"warning","wrong name");
        }
        else {
                checkRemainTickets=false;
                   fopen_s(&fptr,"films","r+");
                   fseek(fptr,0,SEEK_SET);
                   while(feof(fptr)==false)
                   {
                       fread(&filmFile,sizeof(film),1,fptr);
                       if(feof(fptr)==true)break;

                       if(filmFile.capacity>0 && strcmp(filmFile.name,userTick.film_name)==0)
                       {
                           checkRemainTickets=true;
                           filmFile.capacity--;
                           fseek(fptr,-1*(sizeof(film)),SEEK_CUR);
                           fwrite(&filmFile,sizeof(film),1,fptr);
                           break;
                       }
                   }
                   fclose(fptr);

                   if(checkRemainTickets==true)
                   {
                       checkTicketFile=false;
                       fopen_s(&fptr,"tickets","a+");
                       fseek(fptr,0,SEEK_SET);
                       while(feof(fptr)==false)
                       {
                           fread(&userTickFile,sizeof(userTickets),1,fptr);
                           if(feof(fptr)==true)break;
                           if(strcmp(userTickFile.password,userTick.password)==0 && strcmp(userTick.film_name,userTickFile.film_name)==0)
                           {
                               checkTicketFile=true;
                               break;
                           }
                       }
                       fclose(fptr);
                       if( checkTicketFile==false)
                       {
                           userTick.numberOfTickets=1;
                            fopen_s(&fptr,"tickets","a+");
                            fseek(fptr,0,SEEK_END);
                            fwrite(&userTick,sizeof(userTickets),1,fptr);
                            fclose(fptr);
                       }
                       else {
                           fopen_s(&fptr,"tickets","r+");
                           fseek(fptr,0,SEEK_SET);
                           while(feof(fptr)==false)
                           {
                               fread(&userTickFile,sizeof(userTickets),1,fptr);
                               if(feof(fptr)==true)break;
                               if(strcmp(userTickFile.password,userTick.password)==0 && strcmp(userTick.film_name,userTickFile.film_name)==0)
                               {
                                   userTickFile.numberOfTickets++;
                                   fseek(fptr,-1*(sizeof(userTickets)),SEEK_CUR);
                                   fwrite(&userTickFile,sizeof(userTickets),1,fptr);
                                   break;
                               }
                           }
                           fclose(fptr);
                          // ui->confirm->setVisible(false);
                           QMessageBox::information(this,"message","your buy was successfully");
                           ui->confirm->setVisible(false);
                       }

                   }

                   else {
                       QMessageBox::information(this,"warning","tickets of this film is over");
                       ui->confirm->setVisible(true);
                   }


        }
    }
}
