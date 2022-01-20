#ifndef LED_H
#define LED_H
#include <string>

class Led
{
private:
    std::string eigenaar;
    bool aangesloten;
    int portnummer;
    int writeGPIO(char const*, char const*);

public:
    Led(int);
    Led(int, std::string);
    ~Led();
    void zetAan();
    void zetUit();
    bool isAangesloten();
    int gpioPin();
};


#endif