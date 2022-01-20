#include "Stopwatch.h"


Stopwatch::Stopwatch()
{
    this -> begintijd.tv_sec = 0;
    this -> eindtijd.tv_sec = 0;
//	 gettimeofday(&begintijd,0);
//	 gettimeofday(&eindtijd, 0);


}

//Stopwatch::~Stopwatch() {
//
//}

void Stopwatch::reset() {
      begintijd.tv_sec=0;
      eindtijd.tv_sec=0;
}

void Stopwatch::begin() {

	struct timeval tijd;
	 gettimeofday(&tijd,0);
	 begintijd.tv_sec = tijd.tv_sec;

}

void Stopwatch::stop() {
	struct timeval tijd;
	 gettimeofday(&tijd,0);
	 eindtijd.tv_sec = tijd.tv_sec;
}

unsigned int Stopwatch::deTijd(){

    int verstreken = eindtijd.tv_sec-begintijd.tv_sec;
	return verstreken;

}

