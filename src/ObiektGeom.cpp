#include <iostream>
#include <fstream>
#include <math.h>
#include "ObiektGeom.hh"

ObiektGeom::ObiektGeom(){
}

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa, const char*  sNazwaObiektu, int KolorID, Wektor3D Skala, Wektor3D Polozenie, double Kat, Obrys obrysXY):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID){
  _Skala=Skala;
  _Polozenie=Polozenie;
  _Kat=Kat;
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
  _ObrysXY = obrysXY;
}


std::string ObiektGeom::get_nazwa(){
  return (*this)._NazwaObiektu;
}

void ObiektGeom::set_polozenie(Wektor3D pom){
  this->_Polozenie=pom;
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(){
  std::ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  std::ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if(!(StrmWe.is_open() && StrmWy.is_open())){
    std::cerr << std::endl << "Nie mozna otworzyc jednego z plikow:" << std::endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << std::endl
	 << "    " << _NazwaPliku_BrylaRysowana << std::endl
	 << std::endl;
    return false;
  }

  Wektor3D Wspolrzedne;
  MacierzObrotu RMacierz;
  int Indeks_Wiersza = 0;
  int Indeks_Pomocniczy =0;
  
  StrmWe >> Wspolrzedne;
  if (StrmWe.fail())return false;

  do{
    Wspolrzedne = RMacierz.ObrotZ(_Kat,(Wspolrzedne*_Skala))+_Polozenie;
    if(Indeks_Pomocniczy<1)
      _ObrysXY.ustaw_pierwszy_raz(Wspolrzedne);
    else
      (*this)._ObrysXY.wyznacz_obrys(Wspolrzedne);

    StrmWy << Wspolrzedne << std::endl;
    ++Indeks_Wiersza;
    ++Indeks_Pomocniczy;

    if (Indeks_Wiersza>=4){
      StrmWy << std::endl;
      Indeks_Wiersza=0;
    }

    StrmWe >> Wspolrzedne;

  } while(!StrmWe.fail());

  if(!StrmWe.eof()) return false;

  return Indeks_Wiersza == 0 && !StrmWy.fail();
}

void ObiektGeom::Obroc_suma(int kat){
  _Kat+=kat;
  Przelicz_i_Zapisz_Wierzcholki();
}


double ObiektGeom::get_kat()const{
  return (*this)._Kat;
}

Wektor3D ObiektGeom::get_polozenie()const{
  return (*this)._Polozenie;
}