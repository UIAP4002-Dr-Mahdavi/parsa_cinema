#ifndef TMPACTOR_H
#define TMPACTOR_H
#include "actor.h"
#include "QString"
class tmpActor
{
public:
    tmpActor();
    QString Name;
    char tmpName[30];
    void setName(actor*);
};

#endif // TMPACTOR_H
