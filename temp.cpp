#include "temp.h"

temp::temp()
{

}

void temp::setPassword(user * per)
{
    memcpy(this->tmpPassword,this->PASSWORD.toStdString().c_str(),this->PASSWORD.size());
    this->tmpPassword[this->PASSWORD.size()]=NULL;
    strcpy(per->password,(char*)this->tmpPassword);
}

void temp::setusername(user *per)
{
    memcpy(this->tmpUserName,this->USERNAME.toStdString().c_str(),this->USERNAME.size());
    this->tmpUserName[this->USERNAME.size()]=NULL;
    strcpy(per->username,(char*)this->tmpUserName);
}
