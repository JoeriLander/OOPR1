#include "Led.h"

Led::Led(string naam) : eigenaar(naam)
{

}

Led::Led(string naam, double sterkte) : eigenaar(naam), lichtsterkte(sterkte)
{

}

void Led::veranderLichsterkte(double value) {
    this->lichtsterkte = value;
}

double Led::hoeveelheidLicht() const {
    return this->lichtsterkte;
}