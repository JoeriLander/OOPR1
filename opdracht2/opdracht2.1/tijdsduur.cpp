#include "tijdsduur.h"
#include <iomanip>
#include <iostream>
using namespace std;
void Tijdsduur::normaliseer()
{
    if(this -> min < 0)
    {   
        this -> min = 0;
        this -> sec = 0; 
    }

    this -> min = ((this -> min + this -> sec / 60) % 60);
    this -> sec = this -> sec % 60; 

    if(this -> sec < 0 && this -> min > 0)
    {
        this -> min -= 1; 
        this -> sec = 60 + this -> sec;
    }
}
Tijdsduur::Tijdsduur(int minuut, int seconde) : min(minuut), sec(seconde) { 
    normaliseer(); 
}
Tijdsduur::Tijdsduur(int seconde) : sec(seconde) {
 this -> min = 0;
 normaliseer(); 
 }
void Tijdsduur::eraf(Tijdsduur t)
{
   this -> sec -= t.sec;
   this -> min -= t.min;
   normaliseer();   
}
void Tijdsduur::erbij(Tijdsduur t)
{
    this -> sec += t.sec;
    this -> min += t.min;
    normaliseer();
}
void Tijdsduur::maal(int x)
{
        this -> sec *= x;
        this -> min *= x;
        normaliseer();
}
void Tijdsduur::print()
{
    if(this -> min > 0)
    { 
    cout << this -> min << " minuten en "<<
    this -> sec << " seconden" << endl;
    }
    else{
    cout << this -> sec << " seconden" << endl;
    }
    
}




