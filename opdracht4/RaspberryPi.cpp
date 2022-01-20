#include "RaspberryPi.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

RaspberryPi::RaspberryPi(int poort, int nummer) : gpioNummer(poort), studentnummer(nummer)
{
	veranderGPIOnummer(poort);
	zetPin(gpioPath, "/direction", "out");
}

RaspberryPi::~RaspberryPi()
{
	ontkoppel();
}

void RaspberryPi::zetPin(string path, string action, string value)
{
	std::ofstream file;
	file.open(path + action);
	file << value;
	file.close();
}

void RaspberryPi::zetSpanningOp(bool aan)
{
	if(aan) zetPin(gpioPath, "/value", "1");
	else zetPin(gpioPath, "/value", "0");
}

void RaspberryPi::ontkoppel()
{
	zetPin(GPIO_PATH, "unexport", to_string(gpioNummer));
}

int RaspberryPi::pinNumber()
{
	return gpioNummer;
}

void RaspberryPi::veranderGPIOnummer(int nummer)
{
	gpioNummer = nummer;
	gpioPath = GPIO_PATH "gpio" + to_string(nummer);
	zetPin(GPIO_PATH, "export", to_string(nummer));
	usleep(50000);
}