#include "Led.h"
#include <iostream>
#include <fstream>

Led::Led(std::string naam, double lumen) : eigenaar(naam), lichtsterkte(lumen)
{
    
}

Led::Led(std::string naam) : eigenaar(naam)
{
    
}

bool
void Led::veranderLichtsterkte(double lumen) 
{
    this -> lichtsterkte = lumen; 
}

double Led::hoeveelheidLicht()
{
    return this -> lichtsterkte;
}