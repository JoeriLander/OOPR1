#ifndef DUALLED_H
#define DUALLED_H
#include "Led.h"
#include "../opdracht2/opdracht2.2/Platform.h"
#include <string>

class DualLed : public Led
{
    private:
        std::string kleur1;
        std::string kleur2;
        int status;
        Platform* aangesloten1; 
        Platform* aangesloten2;
    public:
        DualLed(std::string, double, std::string, std::string, Platform*, Platform*);
        ~DualLed();
        bool zetAan(std::string);
        void zetUit();
        std::string connectie();
        int ledStatus();
};

#endif