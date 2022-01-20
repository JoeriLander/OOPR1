#ifndef RASPBERRY_H
#define RASPBERRY_H
#define GPIO_PATH "/sys/class/gpio/"
#include <string>

#include "AansluitingsPlatform.h"
#include <string>
using namespace std;

class RaspberryPi : public AansluitingsPlatform {
public:
	RaspberryPi(int,int);
	~RaspberryPi();
	void zetSpanningOp(bool);
	void ontkoppel();
	int pinNumber();
	void veranderGPIOnummer(int);
private:
	void zetPin(string, string, string);
	int gpioNummer;	
	string gpioPath;	
	int studentnummer;
	int productienummer;
};

#endif 