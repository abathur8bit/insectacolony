#include <string.h>

#include "room.h"


Room::Room(const char* name)
    : NamedEntity(name),m_insects()
{

}

void Room::addInsect(Insect* bug)
{
    m_insects.insert(std::pair<const char*,Insect*>(bug->name(),bug));
}

void Room::removeInsect(Insect *bug)
{
    m_insects.erase(bug->name());
}

Insect* Room::insect(const char *name)
{
    std::map<const char*,Insect*>::iterator it;
    for(it = m_insects.begin(); it != m_insects.end(); ++it)
    {
        Insect* pbug = it->second;
        if(strcmp(pbug->name(),name) == 0)
            return pbug;
    }
    return NULL;
}
