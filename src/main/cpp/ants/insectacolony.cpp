#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "colony.h"
#include "namegenerator.h"
#include "room.h"
#include "ant.h"
#include "beetle.h"
#include "roomnames.h"

int main(int argc,char* argv[])
{
    //check if user is passing in the seed
    int seed = 1;
    if(argc > 1)
        seed = atoi(argv[1]);

    randomize(seed);    // reseed the random generator

    cls();

    NameGenerator namegen;
    Colony *world = new Colony("Alpha Colony");
    world->addRoom(new Room(LAIR));
    world->addRoom(new Room(TREASURY));
    world->addRoom(new Room(HATCHERY));

    int numInsects = 1;
//    int numInsects = random(5,10);
    for(int i=0; i<numInsects; i++)
    {
        Insect* bug = new Ant(namegen.generateName());
        bug->setColony(world);
        world->addInsect(bug,world->room(LAIR));
    }
//    numInsects = random(5,10);
    for(int i=0; i<numInsects; i++)
    {
        Insect* bug = new Beetle(namegen.generateName());
        bug->setColony(world);
        world->addInsect(bug,world->room(HATCHERY));
    }

    for(int i=0; i<10; i++)
    {
        world->update();
//        world->showState();
        sleep(1);
    }

//    gotoxy(1,36);
    printf("Done\n");
}
