#ifndef BEATLE_H
#define BEATLE_H

#include "insect.h"

class Beetle : public Insect
{
public:
    Beetle(const char* name);
    virtual const char* type() {return "Beetle";}
    virtual void update();
    virtual void enterState();
};

#endif // BEATLE_H
