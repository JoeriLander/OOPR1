#include "DualLed.h"
#include "SingleLed.h"
#include "Led.h"
#include "RaspberryPi.h"
#include "LedLamp.h"
#include <iostream>
#include <unistd.h>

int	main() 
{
    RaspberryPi aansluiting2(12,123456); //gpio poort 12, studienummer 123456
    RaspberryPi aansluiting3(13,123456);
    RaspberryPi aansluiting4(19,123456);
    RaspberryPi aansluiting5(24,123456);
    
    LedLamp ll("Joeri Lander ll");

    ll.voegLedToe(new SingleLed("Pietje Puk 1e",0.7,"Rood",&aansluiting4));
    ll.voegLedToe(new DualLed("Joeri Lander 2e", 1.2, "Rood", "Groen", &aansluiting2, &aansluiting3));
    ll.voegLedToe(new SingleLed("Joeri Lander 3e",0.65,"Groen",&aansluiting5));
    ll.zetAan("Rood");
    sleep(3);
    ll.zetAan("Groen");
    sleep(3);
    ll.zetUit();
    sleep(1);
    std::cout<<"connectie(s) van ll: "<< ll.connectie();
    
    aansluiting2.ontkoppel();
    aansluiting3.ontkoppel();
    aansluiting4.ontkoppel();
    aansluiting5.ontkoppel();

return 0;
}

