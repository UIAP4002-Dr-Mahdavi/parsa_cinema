#include "tmpactor.h"

tmpActor::tmpActor()
{

}

void tmpActor::setName(actor *Act)
{
    memcpy(this->tmpName,this->Name.toStdString().c_str(),this->Name.size());
    this->tmpName[this->Name.size()]=NULL;
    strcpy(Act->name,(char*)this->tmpName);
}
