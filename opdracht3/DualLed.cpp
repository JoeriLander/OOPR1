#include "DualLed.h"
#include <iostream>
#include <fstream>
#define GPIO_SYSFS "/sys/class/gpio/"

void writefile(std::string filename, std::string action, std::string writeVal)
{
    std::ofstream file;
    file.open(filename + action); 
    file << writeVal;
    file.close();
}

DualLed::DualLed(std::string naam, double sterkte, std::string color1, std::string color2, Platform* gpio1, Platform* gpio2):
Led(naam, sterkte), kleur1(color1), kleur2(color2), aangesloten1(gpio1), aangesloten2(gpio2)
{
    writefile(GPIO_SYSFS "gpio" + std::to_string(this -> aangesloten1 ->nummerGPIO()), "/direction", "out");
    writefile(GPIO_SYSFS "gpio" + std::to_string(this -> aangesloten2 ->nummerGPIO()), "/direction", "out");
}



DualLed::~DualLed()
{
    
}



bool DualLed::zetAan(std::string color)
{
    if(color == "Rood" || color == "rood")
    {
        this -> aangesloten1 -> zetSpanningOp(true);
        this -> aangesloten2 -> zetSpanningOp(false);
        this -> status = 1;
        return true;
    }

    else if(color == "Groen" || color == "groen")
    {
        this -> aangesloten1 -> zetSpanningOp(false);
        this -> aangesloten2 -> zetSpanningOp(true);
        this -> status = 1;
        return true;
    }

    else
    {
        this -> status = 0;
        return false;
    }
}


void DualLed::zetUit()
{
    this -> aangesloten1 -> zetSpanningOp(false);
    this -> aangesloten2 -> zetSpanningOp(false);
    this -> status = 0;
}


std::string DualLed::connectie()
{
    int port1 = aangesloten1 -> nummerGPIO();
    int port2 = aangesloten2 -> nummerGPIO();
    return std::to_string(port1) + " " + std::to_string(port2);
}



int DualLed::ledStatus()
{
    return this -> status;
}

