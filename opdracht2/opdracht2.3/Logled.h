#ifndef LOGLED_H
#define LOGLED_H

#include <string>
#include "../opdracht2.1/tijdsduur.h"
#include "../opdracht2.2/Platform.h"
#include "Stopwatch.h"

class Logled
{
private:
    bool status;
    std::string eigendomVan;
    Tijdsduur brandUren; 
    Stopwatch tijdmeting; 
    Platform *aangesloten;
    

public:
    Logled(std::string, Platform*, int);
    ~Logled();
    void zetAan();
    void zetUit();
    bool ledStatus();
    unsigned int hoeveelTijdTeGaan();
};

#endif