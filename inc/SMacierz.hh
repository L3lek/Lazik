#pragma once

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

#include "SWektor.hh"


template <typename STyp, int Wymiar>
    class SMacierz{
        SWektor<STyp,Wymiar> macierz[Wymiar];

    public:
    SWektor<STyp,Wymiar> get_macierz(unsigned int i)const{
        return macierz[i];
    }

    void set_macierz(unsigned int i, SWektor<STyp,Wymiar> pom){
        macierz[i] = pom;
    }

    STyp  operator () (unsigned int i, unsigned int j) const {return macierz[i][j];} 
    STyp &operator () (unsigned int i, unsigned int j)       {return macierz[i][j];}
    
    SWektor<STyp,Wymiar> operator *(SWektor<STyp,Wymiar> pom);
    };

typedef SMacierz<double,3> Macierz3D;


template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar> SMacierz<STyp,Wymiar>::operator *(SWektor<STyp,Wymiar> pom){
    SWektor<STyp,Wymiar> wynik;
    for(int i=0;i<Wymiar;++i){
        for(int j=0;j<Wymiar;++j){
            wynik[i] += macierz[i][j] * pom[j];
        }
    }
    return wynik;
}


template <typename STyp, int Wymiar>
std::istream& operator >> (std::istream &in, SMacierz<STyp, Wymiar> &macierz){
    SWektor<STyp,Wymiar> pom;
    for(int i=0;i<Wymiar;++i){
        in >> pom;
        macierz.set_macierz(i,pom);
    }
    return in;
}
