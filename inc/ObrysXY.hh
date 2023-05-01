#pragma once 

#include <iostream>

#include "Rotacja.hh"

class Obrys{
    Wektor2D _max;
    Wektor2D _min;

    public:
    Wektor2D konwersja(Wektor3D pom);
    void ustaw_pierwszy_raz(Wektor3D pom);
    void wyznacz_obrys(Wektor3D pom);

    Wektor2D get_min() {return _min;}
    Wektor2D get_max() {return _max;}

    void set_min(int poz, double liczba){(*this)._min[poz]=liczba;}
    void set_max(int poz, double liczba){(*this)._max[poz]=liczba;}

    bool kolizja(Obrys obiekt);
};




