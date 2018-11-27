#ifndef __INSECT_H__
#define __INSECT_H__

#include <string.h>
#include <iostream>
#include <map>
#include <string>

#include "colony.h"
#include "state.h"

using namespace std;

class NamedEntity;
class Colony;
class Insect;
class State;

class Insect : public NamedEntity
{
public:
    string m_type;
    State m_state;
    int m_counter;
    int m_counterMax;
    int m_destinationRoom;
    int m_currentRoom;
    Colony* m_pcolony;

    int m_money;
    int m_health;
    int m_hunger;

public:    
    Insect(const char* name,const char* type);
    void setColony(Colony* c) {m_pcolony = c;}
    virtual void update()=0;
    virtual void enterState();
    virtual void exitState();

public:
    const char* type() {return m_type.c_str();}

    void setCounter(int c) {m_counter = c;}
    int counter() {return m_counter;}
    void setCounterMax(int c) {m_counterMax = c;}
    int counterMax() {return m_counterMax;}

    void setMoney(const int m) {m_money = m;}
    int money() {return m_money;}
    void incMoney() {++m_money;}

    void setHealth(const int h) {m_health = h;}
    int health() {return m_health;}

    void setHunger(const int h) {m_hunger = h;}
    int hunger() {return m_hunger;}
    void incHunder() {++m_hunger;}

    void setState(int state);
    State& state() {return m_state;}
    int stateType() {return m_state.type();}
    void showState();

    void log(const char* msg);                      ///< Outputs a message with the type ane name of the insect logging the info
};

#endif

