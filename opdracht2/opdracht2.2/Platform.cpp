#include "Platform.h"
#include <fstream>
#include <unistd.h>
#define GPIO_SYSFS "/sys/class/gpio/"           // define filepath to gpio

void writeFile(std::string fileName, std::string action)
{
    std::ofstream file;
    file.open(fileName);
    file << action;
    file.close();
}

void Platform::zetPin(std::string path, std::string action, std::string value)
{
    writeFile(path + action + "/", value); 
}

Platform::Platform(int pinnummer, int studienummer) : gpioNummer(pinnummer), studentnummer(studienummer)
{
    this -> gpioNummer = 0;
    veranderGPIOnummer(pinnummer); 

}

Platform::~Platform()
{
    ontkoppel();
}

void Platform::zetSpanningOp(bool aan)
{

    if(aan) writeFile(gpiopath + "/value", "1"); 
    else writeFile(gpiopath + "/value", "0"); 
    
}

void Platform::ontkoppel()
{

    writeFile(GPIO_SYSFS "unexport", std::to_string(this -> gpioNummer)); 
    this -> gpioNummer = 0;

}

int Platform::nummerGPIO()
{

    return this -> gpioNummer; 

}

void Platform::veranderGPIOnummer(int nummer)
{

    this -> gpioNummer = nummer; // sets gpio number
    this -> gpiopath = GPIO_SYSFS + ("gpio" + std::to_string(nummer)); // sets path to /sys/class/gpio/gpionummer
    writeFile(GPIO_SYSFS "export", std::to_string(nummer)); 
    usleep(100000);

}