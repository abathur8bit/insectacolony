#ifndef ROOM_H
#define ROOM_H

#include <vector>

#include "insect.h"

using namespace std;

class Insect;
class NamedEntity;

class Room : public NamedEntity
{
protected:
    map<const char*,Insect*> m_insects;

public:
    Room(const char *name);
    void addInsect(Insect* bug);
    void removeInsect(Insect* bug);
    int insectCount() {return m_insects.size();}
    Insect* insect(const char *name);
    map<const char*,Insect*>* insects() {return &m_insects;}
    map<const char*,Insect*>::iterator iterator() {return m_insects.begin();}
    map<const char*,Insect*>::iterator end() {return m_insects.end();}
};

#endif // ROOM_H
