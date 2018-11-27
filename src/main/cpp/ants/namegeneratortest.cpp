// Copyright Lee Patterson <http://eightbits.me>
// Core idea from https://gamedevelopment.tutsplus.com/tutorials/quick-tip-how-to-code-a-simple-character-name-generator--gamedev-14308

// g++ -o namegeneratortest namegeneratortest.cpp && ./namegeneratortest

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

vector<std::string> listNames;

void start()
{
    listNames.push_back("mon");
    listNames.push_back("fay");
    listNames.push_back("shi");
    listNames.push_back("zag");
    listNames.push_back("blarg");
    listNames.push_back("rash");
    listNames.push_back("izen");
    listNames.push_back("ray");
    listNames.push_back("gnok");
    listNames.push_back("wonk");
}

void generateName()
{
    string name;
    int numSyllables = 2;
    if(rand()%100 > 50)
        numSyllables++;     //50% chance to have 3 syllables

    for(int i=0; i<numSyllables; i++)
    {
        int syllableIndex = rand() % listNames.size();
        string syllable = listNames[syllableIndex];
        name.append(syllable);
    }
    //capitalize the first letter of the name
    char& ch = name[0];
    name[0] = ch-0x20;
    printf("syllables %d name = %s\n",numSyllables,name.c_str());
}

int main(int argc,char* argv[])
{
    printf("Name Generator 1.0\n");
    srand(time(NULL));
    start();
    generateName();
}
