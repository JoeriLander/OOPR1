#include <fstream>
#include <unistd.h>

#include "Led.h"

#define GPIO_SYSFS "/sys/class/gpio/"           // define filepath to gpio
#define WACHTTIJD  100000

Led::Led(std::string naam, Platform *gpio)
{
    this -> eigenaar = naam;
    this -> status = false; 
    this -> aangesloten = true; 
    this -> gpio = gpio;
    std::ofstream file; 
    file.open(GPIO_SYSFS + ("gpio" + std::to_string(this -> gpio -> nummerGPIO()) + "/direction"));
    file << "out";
    file.close();

}

bool Led::ledStatus()
{

    return this -> status;

}

void Led::zetAan()
{

    gpio->zetSpanningOp(true); 
    this -> status = true;

}

void Led::zetUit()
{

    gpio->zetSpanningOp(false);
    this -> status = false;

}

bool Led::isAangesloten()
{

    return this -> aangesloten; 

}

int Led::gpioPin()
{

    return this -> gpio -> nummerGPIO(); 

}