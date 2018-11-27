#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "util.h"
#include "colony.h"
#include "namegenerator.h"
#include "room.h"
#include "ant.h"
#include "roomnames.h"

Ant::Ant(const char* name) : Insect(name,"Ant")
{
    m_counterMax = random(1,5);
}

void Ant::update()
{
    updateState();
}

void Ant::updateState()
{
    assert(m_pcolony);

    switch(stateType())
    {
        case State::SLEEPING:
            if(++m_counter > m_counterMax)
            {
                setState(State::WAKING);
            }
            break;

        case State::WAKING:
            setState(State::MINING);
            m_pcolony->changeRoom(this,m_pcolony->room(TREASURY));
            break;

        case State::HUNGRY:
            log("Going for food");
            m_pcolony->changeRoom(this,m_pcolony->room(LAIR));
            setState(State::EATING);
            break;

        case State::WANDERING: wander(); break;
    }
}

void Ant::enterState()
{
    Insect::enterState();
    setCounter(0);
    setCounterMax(random(1,5));
}

void Ant::mine()
{
    if(m_counter < m_counterMax)
    {
    log("Making money");
    incMoney();
    incHunder();
    }
    else
    {

    }

}

void Ant::wander()
{
    if(++m_counter >= m_counterMax)
    {
        log("done wandering");
    }
    else
    {

    }
}
