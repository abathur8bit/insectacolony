#include <string.h>

#include "namedentity.h"

NamedEntity::NamedEntity(const char* name)
{
    strncpy(m_name,name,sizeof m_name);
    m_name[sizeof(m_name)-1] = '\0';
}
