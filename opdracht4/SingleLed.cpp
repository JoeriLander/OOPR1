#include "SingleLed.h"

bool SingleLed::zetAan(string color) 
{
    // Check if color matches, otherwise return false.
    if (kleur.compare(color) != 0) 
    {
        return false;
    }

    this->gpio->zetSpanningOp(true);
    this->status = 1;
    return true;
}

void SingleLed::zetUit() 
{
    gpio->zetSpanningOp(false);
    status = 0;
}

string SingleLed::connectie() 
{
    return to_string(gpio->pinNumber());
}

int SingleLed::ledStatus() 
{
    return status;
}

SingleLed::SingleLed(string eigenaar, double lumen, string color, AansluitingsPlatform *pi1) :
Led(eigenaar, lumen), kleur(color), gpio(pi1)
{

}
