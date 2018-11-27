#include <stdio.h>

#include "beetle.h"
#include "util.h"

Beetle::Beetle(const char *name) : Insect(name,"Beetle")
{
}

void Beetle::update()
{
//    switch(state())
//    {
//        case waking:
//            if(++m_counter > m_counterMax)
//            {
//                setState(observing);
//            }
//            break;

//        case observing:
//            if(++m_counter > m_counterMax)
//            {
//                chooseNextState();
//            }
//            break;

//        case sleeping:
//            if(++m_counter > m_counterMax)
//            {
//                setState(waking);
//            }
//            break;

//        case stunned:   break;
//        case traveling: break;
//        case eating:    break;
//        case payday:    break;
//    }
}

void Beetle::enterState()
{
    Insect::enterState();
    setCounter(0);
    setCounterMax(random(3,10));
}
