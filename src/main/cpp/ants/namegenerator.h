#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <vector>
#include <string>

using namespace std;

class NameGenerator
{
protected:
    vector<string> m_names;
    void setup();

public:
    NameGenerator();
    ~NameGenerator();
    const char* generateName();
};

#endif // NAMEGENERATOR_H
