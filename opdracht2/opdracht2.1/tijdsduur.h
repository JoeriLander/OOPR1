#ifndef TIJDSDUUR_H
#define TIJDSDUUR_H

class Tijdsduur
{
    private:
        int sec;
        int min; 
        void normaliseer();

    public:
        Tijdsduur(int seconde);
        Tijdsduur(int minuut, int seconde);
        void eraf(Tijdsduur t); 
        void erbij(Tijdsduur t);
        void maal(int x);
        void print();
        int deTimerTijd();
};

#endif