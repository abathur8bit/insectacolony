#ifndef STATE_H
#define STATE_H

#include "namedentity.h"



class State
{
protected:
    int m_type;  ///< What type of state this is.

public:
    enum
    {
      //12345678901234567890
        SLEEPING=0,
        WAKING,
        HUNGRY,
        EATING,
        WANDERING,
        MINING,
    };

    State(int stateId);
    const char* name();
    int type() {return m_type;}
    void setType(int stateId);
};

#endif // STATE_H
