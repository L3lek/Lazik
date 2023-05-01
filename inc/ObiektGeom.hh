#pragma once

#include <string>
#include "ObrysXY.hh"


#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "../pliki_do_rysowania"

class ObiektGeom{
    Wektor3D _Skala;
    Wektor3D _Polozenie;
    double _Kat;
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int           _KolorID;
    Obrys   _ObrysXY;


  public:
    // void set_Skala(ObiektGeom wzorzec){(*this)._Skala=wzorzec._Skala;}
    // void set_Polozenie(ObiektGeom wzorzec){(*this)._Polozenie=wzorzec._Polozenie;}
    // void set_NazwaRysowana(ObiektGeom wzorzec){(*this)._NazwaPliku_BrylaRysowana=wzorzec._NazwaPliku_BrylaRysowana;}
    // void set_NazwaWejsciowa(ObiektGeom wzorzec){(*this)._NazwaPliku_BrylaWzorcowa=wzorzec._NazwaPliku_BrylaWzorcowa;}
    // void set_NazwaObiektu(ObiektGeom wzorzec){(*this)._NazwaObiektu=wzorzec._NazwaObiektu;}
    // void set_Kolor(ObiektGeom wzorzec){(*this)._KolorID=wzorzec._KolorID;}
    int WezKolorID() const {return _KolorID;}
    const std::string & WezNazweObiektu() const {return _NazwaObiektu;}
    const std::string & WezNazwePliku_BrylaRysowana() const {return _NazwaPliku_BrylaRysowana;}  

    ObiektGeom();
    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D Skala, Wektor3D Polozenie, double Kat, Obrys obrysXY);

    std::string get_nazwa();
    double get_kat()const;
    Obrys get_obrys() const {return(*this)._ObrysXY;}
    Wektor3D get_polozenie()const;
    void set_polozenie(Wektor3D pom);
    bool Przelicz_i_Zapisz_Wierzcholki();
    void Obroc_suma(int kat);    
    virtual std::string JakiObiekt() {return "Obiekt";}
};