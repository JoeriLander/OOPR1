#ifndef LED_H
#define LED_H
#define GPIO_SYSFS "/sys/class/gpio/"
#include <string>
#include "Platform.h"
class Led
{
    private:
    bool status;
    std::string eigenaar;
    bool aangesloten;
    Platform* gpio;

    public: 
    Led(std::string naam, Platform *gpio);
    bool ledStatus();
    void zetAan();
    void zetUit();
    bool isAangesloten();
    int gpioPin();

};

#endif
