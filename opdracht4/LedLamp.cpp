#include "LedLamp.h"
#include <iostream>

LedLamp::LedLamp(string naam) : Led(naam)
{

}

bool LedLamp::zetAan(string kleur)
{
    bool waarde = false;
    for(unsigned int i = 0; i < ledje.size(); i++)
    {
        ledje.at(i) -> zetAan(kleur);
    }
    return waarde;
}

void LedLamp::zetUit()
{
    for(unsigned int i = 0; i < ledje.size(); i++)
    {
        ledje.at(i) -> zetUit();
    }
}

string LedLamp::connectie()
{
    string connections;
    for(unsigned int i = 0; i < ledje.size(); i++)
    {
        if(i == ledje.size() - 1)
        {
            connections += ledje.at(i) -> connectie();
            connections += "\n";
        }

        else
        {
            connections += ledje.at(i) -> connectie();
            connections += ", ";
        }
        
    }

    return connections;
}

void LedLamp::voegLedToe(Led* lampje)
{
    ledje.push_back(lampje);
}

int LedLamp::ledStatus()
{
    return 69;
}