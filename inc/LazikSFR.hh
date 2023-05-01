#pragma once

#include "Lazik.hh"
#include <iostream>
#include <memory>
#include "ProbkaRegolitu.hh"

class LazikSFR : public Lazik
{
    std::list<std::shared_ptr<ProbkaRegolitu>> ListaProbek;
    public:

    LazikSFR(); 
    LazikSFR(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D Skala, Wektor3D Polozenie, double kat , Obrys obrys):
         Lazik(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, Skala, Polozenie, kat, obrys){};
    //LazikSFR(Lazik& lazik);
    
    void DodajDoListyProbek (std::shared_ptr<ProbkaRegolitu> ProbRego);
    void WyswietlListeProbek(std::ostream &StrmWy);

    std::string JakiObiekt() override 
    {return "LazikSFR";}
    
    //TypKolizji CzyKolizja(std::shared_ptr<ObiektGeom> l) override;
    //~LazikSFR ();
    TypKolizji Czy_kolizja(std::list<std::shared_ptr<ObiektGeom>> Obiekty);

};