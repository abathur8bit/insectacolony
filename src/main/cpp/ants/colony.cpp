#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "util.h"
#include "room.h"

#include "colony.h"

Colony::Colony(const char* name) : NamedEntity(name)
{
}

void Colony::addInsect(Insect* bug, Room *r)
{
    m_insects.insert(std::pair<const char*,Insect*>(bug->name(),bug));
    m_insectRoomMap.insert(pair<Insect*,Room*>(bug,r));
    r->addInsect(bug);
    printf("%s welcomes an %s named %s\n",name(),bug->type(),bug->name());
}

void Colony::removeInsect(Insect *bug)
{
    m_insects.erase(bug->name());
    m_insectRoomMap.erase(bug);
}

/** Searchs the list by name (not by key). */
Insect* Colony::insect(const char *name)
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

void Colony::addRoom(Room *r)
{
    m_rooms.insert(std::pair<char*,Room*>(r->name(),r));
}

void Colony::removeRoom(Room *r)
{
    m_rooms.erase(r->name());
}

/** Searchs the list by name (not by key). */
Room* Colony::room(const char *name)
{
    std::map<const char*,Room*>::iterator it;
    for(it = m_rooms.begin(); it != m_rooms.end(); ++it)
    {
        Room* p = it->second;
        if(strcmp(p->name(),name) == 0)
            return p;
    }
    return NULL;
}

void Colony::update()
{
    std::map<const char*,Insect*>::iterator it;
    for(it=m_insects.begin(); it != m_insects.end(); ++it)
    {
        it->second->update();
    }
}

void Colony::printbox(int x,int y,int w,int h)
{
    gotoxy(x,y);
    printf("+");
    for(int i=0; i<w-2; i++)
        printf("-");
    printf("+");
    for(int i=0; i<h-2; i++)
    {
        gotoxy(x,y+i+1);
        printf("|");
        for(int i=0; i<w-2; i++)
            printf(" ");
        printf("|");
    }
    gotoxy(x,y+h-1);
    printf("+");
    for(int i=0; i<w-2; i++)
        printf("-");
    printf("+");
}

void Colony::showRoom(int x,int y,int w,int h,Room* r)
{
    printbox(x,y,w,h);          //box

    //title
    gotoxy(x+1,y+1);
    printf("%s",r->name());

    //bar under title
    gotoxy(x,y+2);
    printf("+");
    for(int i=0; i<w-2; i++)
        printf("-");
    printf("+");

    //contents
    x++;
    y+=3;
    std::map<const char*,Insect*>::iterator it;
    for(it=r->insects()->begin(); it != r->insects()->end(); ++it)
    {
        gotoxy(x,y++);
        it->second->showState();
    }
}

void Colony::showState()
{
    cls();
    printf("Colony Name: %s\n\n",name());

    int x=1,y=5;
    int w=45,h=30;

    std::map<const char*,Room*>::iterator it;
    for(it=m_rooms.begin(); it != m_rooms.end(); ++it)
    {
        Room* proom = it->second;
        showRoom(x,y,w,h,proom);
        x+=w+1;
    }


//    printf("Inhabitance:\n");
//    std::map<const char*,Insect*>::iterator it;
//    for(it=m_insects.begin(); it != m_insects.end(); ++it)
//    {
//        it->second->showState();
//    }

//    printbox(60,2,30,10);
//    gotoxy(61,3);
//    printf("%-26s%2d",name(),3);
    fflush(stdout);
}


/**
 * Change the room the insect is in. If the insect isn't able to change rooms, false is returned.
 * @param bug The bug you are changing the room for.
 * @param r   The room you are moving the bug to.
 * @return true if the room changed, false otherwise.
 */
bool Colony::changeRoom(Insect* bug,Room* r)
{
    assert(r);
    assert(bug);

    Room* pcurrentRoom = m_insectRoomMap[bug];
    if(pcurrentRoom)
    {
        pcurrentRoom->removeInsect(bug);
        m_insectRoomMap.erase(bug);
    }
    r->addInsect(bug);
    m_insectRoomMap.insert(pair<Insect*,Room*>(bug,r));
    printf("%s is now in room %s\n",bug->name(),r->name());

    return true;
}
