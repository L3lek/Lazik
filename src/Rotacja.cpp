#include "Rotacja.hh"
#include <math.h>

double MacierzObrotu::operator() (unsigned int wiersz, unsigned int kolumna){
    return RMacierz(wiersz,kolumna);
}

Wektor3D MacierzObrotu::ObrotX(double kat, Wektor3D pom){
    Wektor3D zwracana;
    double radian = (kat*M_PI)/180;

    RMacierz(0,0)=1;
    RMacierz(0,1)=0;
    RMacierz(0,2)=0;
    RMacierz(1,0)=0;
    RMacierz(1,1)=round(cos(radian)*100)/100;
    RMacierz(1,2)=round(-sin(radian)*100)/100;
    RMacierz(2,0)=0;
    RMacierz(2,1)=round(sin(radian)*100)/100;
    RMacierz(2,2)=round(cos(radian)*100)/100;

    zwracana = (*this).RMacierz*pom;
    return zwracana;
}

Wektor3D MacierzObrotu::ObrotY(double kat, Wektor3D pom){
    Wektor3D zwracana;
    double radian = (kat*M_PI)/180;

    RMacierz(0,0)=round(cos(radian)*100)/100;
    RMacierz(0,1)=0;
    RMacierz(0,2)=round(sin(radian)*100)/100;
    RMacierz(1,0)=0;
    RMacierz(1,1)=1;
    RMacierz(1,2)=0;
    RMacierz(2,0)=round(-sin(radian)*100)/100;
    RMacierz(2,1)=0;
    RMacierz(2,2)=round(cos(radian)*100)/100;

    zwracana = (*this).RMacierz*pom;
    return zwracana;
}

Wektor3D MacierzObrotu::ObrotZ(double kat, Wektor3D pom){
    Wektor3D zwracana;
    double radian = (kat*M_PI)/180;

    RMacierz(0,0)=round(cos(radian)*100)/100;
    RMacierz(0,1)=round(-sin(radian)*100)/100;
    RMacierz(0,2)=0;
    RMacierz(1,0)=round(sin(radian)*100)/100;
    RMacierz(1,1)=round(cos(radian)*100)/100;
    RMacierz(1,2)=0;
    RMacierz(2,0)=0;
    RMacierz(2,1)=0;
    RMacierz(2,2)=1;

    zwracana = (*this).RMacierz*pom;
    return zwracana;
}