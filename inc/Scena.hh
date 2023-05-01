#pragma once

#include <iostream>
#include <memory>

#include "Lazik.hh"
#include "ProbkaRegolitu.hh"
#include "PowierzchniaMarsa.hh"
#include "TypKolizji.hh"

class Scena{
        std::shared_ptr<ProbkaRegolitu> _Aktualnaprobka;
        std::shared_ptr<Lazik> _AktywnyLazik;
        std::list<std::shared_ptr<ObiektGeom>> _ObiektySceny;
        PzG::LaczeDoGNUPlota  Lacze;
        void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze);
        bool CzyMoznaPodniesc;
    public:        
        void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb);
        Scena(std::shared_ptr<Lazik> ref);
        Scena();
        Lazik& getpointer();
        void zmien_szybkosc();
        void jedz();
        void obroc();
        void Wyswietl_wektory();
        void Wyswietl_nazwa();
        void Wyswietl_polozenie();
        void Wyswietl_orientacja();
        void Wyswietl_menu();
        void wybierz_lazik(int lazik);
        
        void zmien_lazik();
        void dodaj_do_listy(std::shared_ptr<ObiektGeom> Obiekt);
        void usun_z_listy(std::shared_ptr<ObiektGeom> Obiekt);
        void WyswietlProbki (std::ostream &StrmWy);
        void ZbierzProbke (std::shared_ptr<ObiektGeom>  Probka);
        void WyswietlProbkiSFR (std::ostream &StrmWyj);
        void PodejmijProbke();
        TypKolizji Czy_kolizja_aktywnego();
};


