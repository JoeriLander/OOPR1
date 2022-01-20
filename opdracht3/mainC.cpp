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
std::cout << "!!!Hello World van de tijd!!!" << std::endl;
Platform gpio1(18,123456);
Platform gpio2(23,123456);
Platform gpio3(24,123456);
SingleLed sl1("Pietje Puk",0.9,"Groen",&gpio1); //eigenaar="Pietje Puk" lichtsterkte= 0.9 lumen
DualLed dl1("Pietje Puk",1.2,"Rood","Groen",&gpio2,&gpio3); //eigenaar="Pietje Puk" lichtsterkte= 1.2 lumen
printConnecties(sl1);
printConnecties(dl1);
for(int i=0;i<5;++i) {
sl1.zetAan("Groen");
sleep(1);
sl1.zetUit();
sleep(2);
}
dl1.zetAan("Groen");
sleep(2);
dl1.zetAan("Rood");
sleep(2);
dl1.zetUit();

gpio1.ontkoppel();
gpio2.ontkoppel();
gpio3.ontkoppel();
return 0;

}



