#include "state.h"

State::State(int stateId) : m_type(stateId)
{
}

void State::setType(int stateId)
{
    m_type = stateId;
}

const char* State::name()
{
    switch(m_type)
    {
        case SLEEPING: return "SLEEPING"; break;
        case WAKING: return "WAKING"; break;
        case HUNGRY: return "HUNGRY"; break;
        case EATING: return "EATING"; break;
        case WANDERING: return "WANDERING"; break;
        case MINING: return "MINING"; break;
    }
    return "UNKNOWN";
}
