#ifndef INSECTTESTSUITE_H
#define INSECTTESTSUITE_H

//../../cxxtest-4.4/bin/cxxtestgen --error-printer -o runner.cpp insecttestsuite.h && g++ -o runner -I../../cxxtest-4.4 runner.cpp && ./runner

#include <string>

#include <cxxtest/TestSuite.h>

#include "room.h"
#include "insect.h"
#include "colony.h"
#include "ant.h"
#include "beetle.h"
#include "state.h"

using namespace std;

string insectName = "Blarg";
string roomName = "Lair";
string colonyName = "Alpha Colony";

class InsectTestSuite : public CxxTest::TestSuite
{
private:
    char buffer[1024];

public:
    void testString()
    {
        string s = "foobar";
        TS_ASSERT(strcmp(s.c_str(),"foobar") == 0);
    }

    void testJunk()
    {
        Beetle b("Bob");
        Ant a("Vicky");

        Insect* p = &a;
        TS_TRACE(p->name());
        TS_ASSERT((p = dynamic_cast<Insect *>(p)));
        TS_ASSERT((p = dynamic_cast<Ant *>(p)));
        TS_ASSERT(!(p = dynamic_cast<Beetle *>(p)));

        Beetle* pb = &b;
//        TS_ASSERT((pb = dynamic_cast<Insect *>(pb)));     error: assigning to 'Beetle *' from incompatible type 'Insect *'
//        TS_ASSERT(!(pb = dynamic_cast<Ant *>(pb)));       error: assigning to 'Beetle *' from incompatible type 'Ant *'
        TS_ASSERT((pb = dynamic_cast<Beetle *>(pb)));

        p = &a;
        State& s = p->state();
        TS_ASSERT(s.type() == State::SLEEPING);
        s.setType(State::HUNGRY);
        sprintf(buffer,"state type[%d] state name[%s]\n",s.type(),s.name());
        TS_TRACE(buffer);
    }

    void testAnt()
    {
        string insectName = "Blarg";
        Ant i(insectName.c_str());
        TS_ASSERT(strcmp(i.name(),insectName.c_str()) == 0);    //make sure name is copied in

        TS_ASSERT(i.state().type() == State::SLEEPING);                       //make sure initial state is what we expect
        TS_ASSERT(strcmp(i.type(),"Ant") == 0);                 //make sure insect type is set

        i.state().setType(State::WAKING);
        TS_ASSERT(i.state().type() == State::WAKING);                         //when we set the state, make sure it is set correctly
    }

    void testBeetleType()
    {
        string insectName = "Blarg";
        Beetle i(insectName.c_str());
        TS_ASSERT(strcmp(i.type(),"Beetle") == 0);              //make sure insect type is set
    }

    void testRoom()
    {
        Room r(roomName.c_str());
        Ant fireant(insectName.c_str());

        r.addInsect(&fireant);
        TS_ASSERT(r.insectCount() == 1);
        TS_ASSERT(strcmp(r.name(),roomName.c_str()) == 0);

        Insect* bug = r.insect(insectName.c_str());
        TS_ASSERT(bug != NULL);
        TS_ASSERT(bug == &fireant);

        Ant* pant = (Ant*)r.insect(insectName.c_str());
        TS_ASSERT(pant != NULL);
        TS_ASSERT(pant == &fireant);

        r.removeInsect(&fireant);
        TS_ASSERT(r.insectCount() == 0);
    }

    void testColony()
    {
        Colony* world = new Colony(colonyName.c_str());
        Insect* insect = new Ant(insectName.c_str());
        Room* room = new Room(roomName.c_str());

        world->addRoom(room);
        world->addInsect(insect,room);

        TS_ASSERT(strcmp(world->name(),colonyName.c_str()) == 0);
        TS_ASSERT(world->insect(insectName.c_str()) == insect);
        TS_ASSERT(world->room(roomName.c_str()) == room);
        TS_ASSERT(world->room(roomName.c_str())->insect(insectName.c_str()) == insect);   //make sure the insect we added got added to the room
    }

    void testColonyChangeRoom()
    {
        Colony* world = new Colony(colonyName.c_str());
        Insect* bug = new Ant("ant 1");
        Room* room1 = new Room("room 1");
        Room* room2 = new Room("room 2");
        world->addInsect(bug,room1);

        TS_ASSERT(room1->insect(bug->name()));      //make sure insect is in room 1
        TS_ASSERT(!room2->insect(bug->name()));     //make sure insect is NOT in room 2

        world->changeRoom(bug,room2);
        TS_ASSERT(!room1->insect(bug->name()));     //make sure insect is NOT in room 1
        TS_ASSERT(room2->insect(bug->name()));      //make sure insect is in room 2
    }

    void testColonyRemoveRoom()
    {
        //create insects and add to the colony
        Colony* world = new Colony(colonyName.c_str());
        Insect* insect1 = new Ant("ant 1");
        Insect* insect2 = new Ant("ant 2");
        Room* room = new Room(roomName.c_str());
        world->addInsect(insect1,room);
        world->addInsect(insect2,room);

        //make sure they are in the colony
        TS_ASSERT(world->insects().size() == 2);
        TS_ASSERT(world->insect(insect1->name()) == insect1);
        TS_ASSERT(world->insect(insect2->name()) == insect2);

        //remove one and make sure it's gone
        world->removeInsect(insect1);
        TS_ASSERT(world->insect(insect1->name()) == NULL);
        TS_ASSERT(world->insect(insect2->name()) == insect2);
        TS_ASSERT(world->insects().size() == 1);
    }

    void testColonyFindInsect()
    {
        //create insects and add to the colony
        Colony* world = new Colony(colonyName.c_str());
        Insect* insect1 = new Ant("ant 1");
        Insect* insect2 = new Ant("ant 2");
        Room* room = new Room(roomName.c_str());
        world->addInsect(insect1,room);
        world->addInsect(insect2,room);
        TS_TRACE(insect1);

        //make sure they are in the colony
        TS_ASSERT(world->insects().size() == 2);
        TS_ASSERT(world->insect(insect1->name()) == insect1);
        TS_ASSERT(world->insect(insect2->name()) == insect2);

        std::map<const char*,Insect*>::iterator it = world->insects().find(insect1->name());
        TS_ASSERT(it != world->insects().end());
        TS_ASSERT(it->second != NULL);
        Insect* bug = it->second;
        TS_TRACE(it->first);
        TS_TRACE(it->second);
        TS_ASSERT(bug == insect1);
        TS_ASSERT(it->second == insect1);

        bug = world->insect(insect1->name());
        TS_ASSERT(bug != NULL);
    }
};

#endif // INSECTTESTSUITE_H
