#include "Logled.h"
#include <unistd.h>
int main() {
 //platform 23 met studienummer 123456
 Platform gpio(18,123456);

 Logled led1("Joeri Lander",&gpio,4);
 led1.zetAan();
 sleep(3);
 led1.zetUit();
 
 return 0;
}