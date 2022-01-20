#include "Led.h"
#include "Platform.h"
#include <iostream>
#include <unistd.h>

int main()
{
    
    Platform gpio(23, 19140002);
    Platform gpio2(18, 19140002);
    
    Led lampje1("Joeri Lander", &gpio);
    Led lampje2("Joeri Lander", &gpio2);
    

    lampje1.zetAan();
    sleep(1);
    lampje2.zetAan();
    sleep(2);
    lampje1.zetUit();
    sleep(1);
    lampje2.zetUit();
    
    return 0;

}