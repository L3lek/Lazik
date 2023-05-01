#pragma once

#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"

class ProbkaRegolitu: public ObiektGeom {
    
    public:
      ProbkaRegolitu();
      ProbkaRegolitu(const char *sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, unsigned int KolorID, Wektor3D Skala, Wektor3D Polozenie, double kat, Obrys obrys):
      ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, Skala, Polozenie, kat, obrys) {}
       
    

      std::string JakiObiekt () override{
          return "ProbkaRegolitu";
        }
};