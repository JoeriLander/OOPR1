#include "Led.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#define WACHTTIJD 100000
#define GPIO_SYSFS "/sys/class/gpio/"

Led::Led(int nummer) : portnummer(nummer), eigenaar("anoniem"), aangesloten(true)
{
    writeGPIO(GPIO_SYSFS "export", std::to_string(this -> portnummer).c_str());
    usleep(WACHTTIJD);
    writeGPIO((GPIO_SYSFS + ("gpio" + std::to_string(this->portnummer)) + "/direction").c_str(), "out");
}

Led::Led(int nummer, std::string naam) : portnummer(nummer), eigenaar(naam), aangesloten(true)
{
    writeGPIO(GPIO_SYSFS "export", std::to_string(this -> portnummer).c_str());
    usleep(WACHTTIJD);
    writeGPIO((GPIO_SYSFS + ("gpio" + std::to_string(this->portnummer)) + "/direction").c_str(), "out");
}

Led::~Led()
{
    this -> aangesloten = false;
    writeGPIO(GPIO_SYSFS "unexport", std::to_string(this -> portnummer).c_str());
}

int Led::writeGPIO(const char *filename, const char *value)
{

    std::ofstream file; 
    file.open(filename);
    file << value;
    file.close();
    return 0;

}

void Led::zetAan()
{

    writeGPIO((GPIO_SYSFS  + (("gpio" + std::to_string(this->portnummer)) + "/value")).c_str(), "1");

}

void Led::zetUit()
{
    writeGPIO((GPIO_SYSFS  + (("gpio" + std::to_string(this->portnummer)) + "/value")).c_str(), "0"); 
}

bool Led::isAangesloten()
{
    return this -> aangesloten;
} 

int Led::gpioPin()
{
    return this -> portnummer;
}