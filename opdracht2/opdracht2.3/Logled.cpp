#include "Logled.h"
#include "../opdracht2.2/Platform.h"
#include <iostream>
#include <fstream>
#define GPIO_SYSFS "/sys/class/gpio/" 


Logled::Logled(std::string naam, Platform* gpio, int x) : eigendomVan(naam), aangesloten(gpio), brandUren(x)
{

    std::ofstream file; 
    file.open(GPIO_SYSFS + ("gpio" + std::to_string(this -> aangesloten -> nummerGPIO()) + "/direction"));
    file << "out";
    file.close();

}

Logled::~Logled()
{

    aangesloten->ontkoppel();

}

void Logled::zetAan()
{

    this -> status = true;     
    this -> tijdmeting.reset();
    this -> tijdmeting.begin();
    this -> aangesloten->zetSpanningOp(true);

}

void Logled::zetUit()
{
    
    this -> status = false;
    this -> tijdmeting.stop();     
    int verstreken = this -> tijdmeting.deTijd();
    std::cout << verstreken;
    Tijdsduur x(verstreken);
    this -> brandUren.eraf(x); 
    this -> aangesloten->zetSpanningOp(false);
    
}

bool Logled::ledStatus()
{

    return this -> status; 

}

