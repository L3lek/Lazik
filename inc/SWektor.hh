#pragma once

#include <iostream>
#include <math.h>

template <typename STyp, int Wymiar>
    class SWektor{
        
    STyp wektor[Wymiar];
    static int wektor_ilosc;
    static int wektor_ilosc_max;

    public:
    SWektor();
    ~SWektor();
    SWektor(STyp[Wymiar]);

    STyp get_wektor(unsigned int i)const{
        return wektor[i];
    }

    /*Funkcja zapisująca wartości do wektora*/
    void set_wektor(unsigned int i, STyp wartosc){
        wektor[i] = wartosc;
    }

    int get_wektor_ilosc()const{
        return this->wektor_ilosc;
    }

    int get_wektor_ilosc_max()const{
        return this->wektor_ilosc_max;
    }

    STyp  operator [] (unsigned int i) const {return wektor[i];}
    STyp &operator [] (unsigned int i)       {return wektor[i];}


    SWektor<STyp,Wymiar> operator + (const SWektor<STyp,Wymiar> &skladnik)const;
    SWektor<STyp,Wymiar> operator - (const SWektor<STyp,Wymiar> &odjemnik)const;
    SWektor<STyp,Wymiar> operator * (const STyp &mnoznik);
    SWektor<STyp,Wymiar> operator * (const SWektor<STyp,Wymiar> &mnoznik) const;
    SWektor<STyp,Wymiar> operator / (const STyp &dzielnik)const;
    bool operator == (const SWektor<STyp,Wymiar> porownawczy)const;
    SWektor<STyp,Wymiar> odwrotnosc ()const;
    double dlugosc ();
    void WstawPolozenie (double a,double b,double c);
    void ustaw (double a,double b,double c);
    void ustaw (double a,double b);

};

typedef SWektor<double,3> Wektor3D;
typedef SWektor<double,2> Wektor2D;

template <typename STyp, int Wymiar>
int SWektor<STyp,Wymiar>::wektor_ilosc = 0;

template <typename STyp, int Wymiar>
int SWektor<STyp,Wymiar>::wektor_ilosc_max = 0;

template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar>::SWektor(){
    for(int i=0;i<Wymiar;++i){
        wektor[i]=0;
    }
    (*this).wektor_ilosc++;
    (*this).wektor_ilosc_max++;
}


template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar>::~SWektor(){
    (*this).wektor_ilosc--;
}


template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar>::SWektor(STyp pom[Wymiar]){
    for(int i=0;i<Wymiar;++i){
        wektor[i]=pom[i];
    }
    (*this).wektor_ilosc ++;
    (*this).wektor_ilosc_max ++;
}


template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar> SWektor<STyp,Wymiar>::operator + (const SWektor<STyp,Wymiar> &skladnik) const{
    SWektor<STyp,Wymiar> wynik;
    for(unsigned int i=0;i<Wymiar;++i)
        wynik[i] = (*this)[i] + skladnik[i];
    return wynik;
}

template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar> SWektor<STyp,Wymiar>::operator - (const SWektor<STyp,Wymiar> &odjemnik) const{
    SWektor<STyp,Wymiar> wynik;
    for(unsigned int i=0;i<Wymiar;++i)
        wynik[i] = (*this)[i] - odjemnik[i];
    return wynik;
}

template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar> SWektor<STyp,Wymiar>::operator * (const STyp &mnoznik){
    SWektor<STyp,Wymiar> wynik;
    for(unsigned int i=0;i<Wymiar;++i)
        wynik[i] = (*this)[i] * mnoznik;
    return wynik;
}

template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar> SWektor<STyp,Wymiar>::operator * (const SWektor<STyp,Wymiar> &mnoznik) const{
    SWektor<STyp,Wymiar> wynik;
    for(unsigned int i=0;i<Wymiar;++i){
        wynik[i]=(*this)[i]*mnoznik[i];
    }
    return wynik;        
}

template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar> SWektor<STyp,Wymiar>::operator / (const STyp &dzielnik) const{
    SWektor<STyp,Wymiar> wynik;
    for(unsigned int i=0;i<Wymiar;++i)
        wynik[i] = (*this)[i] / dzielnik;
    return wynik;
}

template <typename STyp, int Wymiar>
bool SWektor<STyp,Wymiar>::operator== (const SWektor<STyp,Wymiar> porownawczy)const{
    int licznik=0;
    for(int i=0;i<Wymiar;++i){
        if((*this)[i]==porownawczy[i])
            licznik++;
    }
    if(licznik==Wymiar)
        return true;
    else
        return false;
}

template <typename STyp, int Wymiar>
SWektor<STyp,Wymiar> SWektor<STyp,Wymiar>::odwrotnosc ()const{
    SWektor<STyp,Wymiar> wynik;
    for(unsigned int i=0;i<Wymiar;++i)
        wynik[i] = (*this)[i]*(-1);
    return wynik;
}

template <typename STyp, int Wymiar>
double SWektor<STyp,Wymiar>::dlugosc (){
    double pom, dlugosc=0;
    for(int i=0;i<Wymiar;++i){
        pom=(*this)[i]*(*this)[i];
        dlugosc=pom+dlugosc;
    }
    dlugosc=sqrt(dlugosc);
    return dlugosc;
}

template <typename STyp, int Wymiar>
void SWektor<STyp,Wymiar>::WstawPolozenie (double a,double b,double c){
    (*this)[0]=a;
    (*this)[1]=b;
    (*this)[2]=c;
}

template <typename STyp, int Wymiar>
std::ostream& operator << (std::ostream &out, const SWektor<STyp, Wymiar> &tmp){
    for(unsigned int i=0;i<Wymiar;++i){
        out << " " << tmp.get_wektor(i) << " ";
    }
    return out;
}

template <typename STyp, int Wymiar>
std::istream& operator >> (std::istream &in, SWektor<STyp, Wymiar> &tmp){
    STyp pom;
    for(unsigned int i=0;i<Wymiar;++i){
        in >> pom;
        tmp.set_wektor(i,pom);
    }
    return in;
}

template <typename STyp, int Wymiar>
void SWektor<STyp,Wymiar>::ustaw (double a,double b,double c){
    (*this)[0]=a;
    (*this)[1]=b;
    (*this)[2]=c;
}

template <typename STyp, int Wymiar>
void SWektor<STyp,Wymiar>::ustaw (double a,double b){
    (*this)[0]=a;
    (*this)[1]=b;
}
