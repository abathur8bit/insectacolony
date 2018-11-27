#ifndef COLONY_H
#define COLONY_H

#include <map>

#include "namedentity.h"
#include "insect.h"

using namespace std;

class Insect;
class NamedEntity;
class Room;

/** A colony houses a group of insects. A world can have several colony's. */
class Colony : public NamedEntity
{
protected:
   std::map<const char*,Insect*> m_insects;
   std::map<const char*,Room*> m_rooms;
   std::map<Insect*,Room*> m_insectRoomMap;                 ///< So we can find the room an insect is in quickly.

public:
    Colony(const char* name);


    void addRoom(Room* r);
    void removeRoom(Room* r);
    Room* room(const char* name);                               ///< Find a room by name.

    map<const char*,Room*> rooms() {return m_rooms;}

    void addInsect(Insect* bug,Room* r);
    void removeInsect(Insect* bug);
    Insect* insect(const char* name);                           ///< Find a insect by name.
    map<const char*,Insect*> insects() {return m_insects;}      ///< The map of insects.
    bool changeRoom(Insect* bug,Room* r);                       ///< Change the insects current room.

    void update();
    void printbox(int x,int y,int w,int h);
    void showState();
    void showRoom(int x,int y,int w,int h,Room* r);
};

#endif // COLONY_H
