// Copyright Lee Patterson <http://eightbits.me>
// Core idea from https://gamedevelopment.tutsplus.com/tutorials/quick-tip-how-to-code-a-simple-character-name-generator--gamedev-14308

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "namegenerator.h"

NameGenerator::NameGenerator()
    : m_names()
{
    setup();
}

NameGenerator::~NameGenerator()
{
    m_names.clear();
}

void NameGenerator::setup()
{
    m_names.push_back("mon");
    m_names.push_back("fay");
    m_names.push_back("shi");
    m_names.push_back("zag");
    m_names.push_back("blarg");
    m_names.push_back("rash");
    m_names.push_back("izen");
    m_names.push_back("ray");
    m_names.push_back("gnok");
    m_names.push_back("wonk");
}

const char* NameGenerator::generateName()
{
    string name;
    int numSyllables = 2;
    if(rand()%100 > 50)
        numSyllables++;     //50% chance to have 3 syllables

    for(int i=0; i<numSyllables; i++)
    {
        int syllableIndex = rand() % m_names.size();
        string syllable = m_names[syllableIndex];
        name.append(syllable);
    }

    //capitalize the first letter of the name
    char& ch = name[0];
    name[0] = ch-0x20;

    return name.c_str();
}
