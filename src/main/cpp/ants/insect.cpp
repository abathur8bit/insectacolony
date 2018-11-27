#include <stdio.h>
#include <string.h>

#include "insect.h"

Insect::Insect(const char* name,const char* type)
    : NamedEntity(name),
      m_type(type),
      m_state(State::SLEEPING),
      m_counter(0),
      m_counterMax(0),
      m_destinationRoom(0),
      m_currentRoom(0),
      m_money(0),
      m_health(0),
      m_hunger(0)
{
}

void Insect::setState(int state)
{
    exitState();
    m_state.setType(state);
    enterState();
}

void Insect::enterState()
{
    printf("%s entering state %s\n",name(),state().name());
}

void Insect::exitState()
{
    printf("%s exiting state %s\n",name(),state().name());
}

void Insect::showState()
{
    printf("(%-3s) %-15s: %s \n",type(),name(),state().name());
}

void Insect::log(const char* msg)
{
    printf("%s (%-6s / %-10s): %s \n",name(),type(),state().name(),msg);
}
