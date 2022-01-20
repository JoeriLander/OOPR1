#include "SingleLed.h"
#include <iostream>
#include <fstream>
#define GPIO_SYSFS "/sys/class/gpio/"

void writeFile(std::string filename, std::string action, std::string writeVal)
{
    std::ofstream file;
    file.open(filename + action); 
    file << writeVal;
    file.close();
}

SingleLed::SingleLed(std::string naam, double sterkte, std::string color, Platform *gpio):
Led(naam, sterkte), kleur(color), aangesloten(gpio)
{
    writeFile(GPIO_SYSFS "gpio" + std::to_string(this -> aangesloten ->nummerGPIO()), "/direction", "out");
}

SingleLed::~SingleLed()
{

}

bool SingleLed::zetAan(std::string color)
{
    if(color == "rood" || color == "Rood")
    {
        this -> aangesloten->zetSpanningOp(true); 
        this -> status = 1;
        return true; 
    }

    else if(color == "groen" || color == "Groen")
    {
        this -> aangesloten->zetSpanningOp(true); 
        this -> status = 1;
        return true; 
    }

    else
    {
        this -> aangesloten->zetSpanningOp(false);
        this -> status = 0;
        return false; 
    }

}

void SingleLed::zetUit()
{
    this -> aangesloten -> zetSpanningOp(false);
    this -> status = 0; 
}

std::string SingleLed::connectie() 
{
    int nummer = aangesloten -> nummerGPIO();
    return std::to_string(nummer);
}

int SingleLed::ledStatus()
{
    return this -> status;
}

