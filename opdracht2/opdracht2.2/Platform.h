#ifndef PLATFORM_H
#define PLATFORM_H
#define GPIO_SYSFS "/sys/class/gpio/"
#include <string>

class Platform
{
    private:
        int gpioNummer;
        std::string gpiopath;
        int studentnummer;
        int productienummer;
        void zetPin(std::string path, std::string action, std::string nummer); 
    
    public:
        Platform(int, int); 
        ~Platform();
        void zetSpanningOp(bool);
        void ontkoppel();
        int nummerGPIO();
        void veranderGPIOnummer(int);
};

#endif