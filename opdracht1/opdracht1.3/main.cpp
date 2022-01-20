 #include <iostream>
 #include <unistd.h>
 #include "Led.h"

 int main() {
 std::cout<<"hoi embedded OO programmeurs"<<std::endl;

 Led l1(23);
 Led l2(18,"Joeri Lander"); //Zet hier je eigen naam

 l1.zetAan();
 std::cout<<"l1 is aan"<<std::endl;
 usleep(1000000);
 l2.zetAan();
 std::cout<<"l2 is aan"<<std::endl;
 usleep(1000000);
 l1.zetUit();
 usleep(1000000);
 l2.zetUit();

 return 0;
}
