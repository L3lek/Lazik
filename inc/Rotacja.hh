#pragma once

#include "SMacierz.hh"

#include <math.h>

class MacierzObrotu{
    Macierz3D RMacierz;

    public:
        double operator () (unsigned int wiersz, unsigned int kolumna);
        Wektor3D ObrotX(double kat, Wektor3D pom); 
        Wektor3D ObrotY(double kat, Wektor3D pom);
        Wektor3D ObrotZ(double kat, Wektor3D pom);
};