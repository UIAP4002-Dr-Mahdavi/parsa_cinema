#ifndef TEMP_H
#define TEMP_H
#include "QString"
#include "user.h"
class temp
{
public:
   QString USERNAME;
   QString PASSWORD;
   char tmpUserName[30];
   char tmpPassword[30];
   temp();
   void setPassword(user*);
   void setusername(user*);
};

#endif // TEMP_H
