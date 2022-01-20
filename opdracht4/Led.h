#ifndef LED_H
#define LED_H

#include <string>

using namespace std;

class Led {        
    private:
        string eigenaar;
        double lichtsterkte;
    public:
        Led(string);
        Led(string, double);
        virtual bool zetAan(string) = 0;
        virtual void zetUit() = 0;
        virtual string connectie() = 0;
        int ledStatus();
        void veranderLichsterkte(double);
        double hoeveelheidLicht() const;
};

#endif