#ifndef LED_H
#define LED_H
#include "../opdracht2/opdracht2.2/Platform.h"
#include <string>
class Led
{
    private:
        std::string eigenaar;
        double lichtsterkte;

    public:
        Led(std::string, double); 
        Led(std::string);
        virtual bool zetAan(std::string) = 0;
        virtual void zetUit() = 0;
        virtual std::string connectie() = 0;
        virtual int ledStatus() = 0;
        void veranderLichtsterkte(double);
        double hoeveelheidLicht();      

};

#endif