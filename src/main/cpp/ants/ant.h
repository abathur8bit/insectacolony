#ifndef ANT_H
#define ANT_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "colony.h"
#include "namegenerator.h"
#include "room.h"

class Ant : public Insect
{

public:
    Ant(const char* name);
    virtual void update();
    virtual const char* type() {return "Ant";}
    virtual void enterState();

protected:    
    void updateState();
    void wander();
    void mine();
};

#endif //ANT_H
