#include "DualLed.h"

DualLed::DualLed(string naam, double sterkte, string color1, string color2, AansluitingsPlatform* pi1, AansluitingsPlatform* pi2):
Led(naam, sterkte), kleur(color1), kleur1(color2), gpio(pi1), gpio1(pi2)
{
    
}

bool DualLed::zetAan(string color)
{
    if(kleur.compare(color) == 0 || kleur1.compare(color) == 0)
    {
        if(color == "groen" || color == "Groen")
        {
            gpio->zetSpanningOp(true);
            gpio1->zetSpanningOp(false);
            status = 1;
        }

        if(color == "rood" || color == "Rood")
        {
            gpio->zetSpanningOp(false);
            gpio1->zetSpanningOp(true);
            status = 1;
        }
        return true;
    }

    else return true;
}

void DualLed::zetUit()
{
    gpio ->zetSpanningOp(false);
    gpio1->zetSpanningOp(false);
    status = 0; 
}

string DualLed::connectie()
{
    return to_string(gpio->pinNumber()) + " " + to_string(gpio1->pinNumber());
}

int DualLed::ledStatus()
{
    return status;
}