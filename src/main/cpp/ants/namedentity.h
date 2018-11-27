#ifndef NAMEDENTITY_H
#define NAMEDENTITY_H

class NamedEntity
{
protected:
    char m_name[20];

public:
    NamedEntity(const char* name);
    char* name() {return m_name;}
};


#endif // NAMEDENTITY_H
