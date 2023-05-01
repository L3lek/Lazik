#pragma once 

#include <math.h>
#include <unistd.h>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"
#include "Kolory.hh"
#include "TypKolizji.hh"
#include <memory>

class Lazik : public ObiektGeom{
public:
    // ObiektGeom get_dane_lazika()const;
    TypKolizji Czy_kolizja(std::list<std::shared_ptr<ObiektGeom>> Obiekty);
    TypKolizji Czy_koliduje(std::shared_ptr<ObiektGeom> Obiekt);
    Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D Skala, Wektor3D Polozenie, double Kat, Obrys obrysXY):
    ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, Skala, Polozenie, Kat, obrysXY){};
    Lazik();
    bool jedz(Wektor3D wek_przemieszczenia, PzG::LaczeDoGNUPlota& Lacze, std::list<std::shared_ptr<ObiektGeom>> Obiekty);
    bool Obroc(double kat, PzG::LaczeDoGNUPlota& Lacze,std::list<std::shared_ptr<ObiektGeom>> Obiekty);
    int wzor_redukcyjny(double kat);
};