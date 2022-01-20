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
Platform gpioB(23,123456); //platform 23 met studienummer 123456
Platform gpioC(24,123456); //platform 24 met studienummer 123456
SingleLed* sl1=new SingleLed("Pietje Puk",0.9,"groen",&gpioA); //eigenaar "pietje Puk" lichtsterkte= 0.9 lumen
DualLed* dl1= new DualLed("Pietje Puk 2",1.5,"rood","groen",&gpioB,&gpioC); //eigenaar="Pietje Puk 2" lichtsterkte= 1.5 lumen
Led* l1=sl1;
Led* l2=dl1;

l1->zetAan("groen");
sleep(1);
l2->zetAan("groen");
sleep(1);
l2->zetAan("rood");
sleep(1);

Led* uit=sl1;
uit->zetUit();
sleep(1);
uit=dl1;
uit -> zetUit();

delete sl1;
delete dl1;
return 0;

}



