#ifndef SINGLELED_H
#define SINGLELED_H
#include "../opdracht2/opdracht2.2/Platform.h"
#include "Led.h"
#include <string>

class SingleLed : public Led
{
    private:
        std::string kleur;
        int status; 
        Platform* aangesloten;
    public:
        SingleLed(std::string, double, std::string, Platform*);
        ~SingleLed();
        bool zetAan(std::string);
        void zetUit();
        std::string connectie();
        int ledStatus();
};

#endif