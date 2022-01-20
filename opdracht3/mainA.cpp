#include "Led.h"
#include "SingleLed.h"
#include "DualLed.h"
#include "Platform.h"
#include <unistd.h>
#include <iostream>

void printConnecties(Led& l) 
{
   std::cout<<"Led verbonden op de volgende poort(en): "<< l.connectie() <<  std::endl;
}

int main()
{   
Platform gpioA(18,123456); //platform 18 met studienummer 123456
SingleLed sl1("Pietje Puk",0.9,"groen",&gpioA); //eigenaar "pietje Puk" lichtsterkte= 0.9 lumen

SingleLed ledje2(sl1);
sl1.veranderLichtsterkte(1.2);

sl1.zetAan("groen");
sleep(1);
ledje2.zetUit();

return 0;

}



