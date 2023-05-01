#include "Scena.hh"
#include "LazikSFR.hh"

#include<memory>
#include <list>
#include <iterator>

using namespace std;

void Scena::Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze){
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);  
  rLacze.UstawRotacjeXZ(40,60);
  rLacze.Inicjalizuj();
}

void Scena::DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb){
  PzG::InfoPlikuDoRysowania *wInfoPliku;
  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());
}

Scena::Scena(){
  Wektor3D Skala, Skala_prob;
  Wektor3D Polozenie_lazik1, Polozenie_lazik2, Polozenie_lazik3, Polozenie_probki;
  Obrys  obrys;
  std::list<std::shared_ptr<ObiektGeom>> _ObiektySceny;
  CzyMoznaPodniesc=false;
  
  Polozenie_lazik1.ustaw(10,-70,0);
  Polozenie_lazik2.ustaw(20,70,0);
  Polozenie_lazik3.ustaw(20,0,0);

  Inicjalizuj_Lacze(Lacze);
  if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) std::cerr << "Blad 1";
  
  Skala.ustaw(20,20,10);
  Skala_prob.ustaw(2,6,2);
  
  LazikSFR FSR("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski, Skala, Polozenie_lazik1, 0, obrys);
  std::shared_ptr<Lazik> FSR_ptr = std::make_shared<LazikSFR>(FSR);
  (*this).dodaj_do_listy(FSR_ptr);
  
  Lazik  Perseverance("../bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony, Skala, Polozenie_lazik2, 90, obrys);
  std::shared_ptr<Lazik> Perseverance_ptr = std::make_shared<Lazik>(Perseverance);
  (*this).dodaj_do_listy(Perseverance_ptr);

  Lazik Curiosity("../bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony, Skala, Polozenie_lazik3, 0, obrys);   
  std::shared_ptr<Lazik> Curiosity_ptr = std::make_shared<Lazik>(Curiosity);
  (*this).dodaj_do_listy(Curiosity_ptr);
  
  _AktywnyLazik=FSR_ptr;

  Polozenie_probki.ustaw(-50,50,0);
  ProbkaRegolitu  Regolit1("../bryly_wzorcowe/szescian3.dat","Regolit1",Kolor_Czerwony, Skala_prob, Polozenie_probki, 0, obrys);
  std::shared_ptr<ProbkaRegolitu> ptr1 = std::make_shared<ProbkaRegolitu>(Regolit1);
  (*this).dodaj_do_listy(ptr1);
  
  Polozenie_probki.ustaw(-50,-50,0);
  ProbkaRegolitu  Regolit2("../bryly_wzorcowe/szescian3.dat","Regolit2",Kolor_Czerwony, Skala_prob, Polozenie_probki, 30, obrys);
  std::shared_ptr<ProbkaRegolitu> ptr2 = std::make_shared<ProbkaRegolitu>(Regolit2);
  (*this).dodaj_do_listy(ptr2);
  
  Polozenie_probki.ustaw(30,-70,0);
  ProbkaRegolitu  Regolit3("../bryly_wzorcowe/szescian3.dat","Regolit3",Kolor_Czerwony, Skala_prob, Polozenie_probki, 60, obrys);
  std::shared_ptr<ProbkaRegolitu> ptr3 = std::make_shared<ProbkaRegolitu>(Regolit3);
  (*this).dodaj_do_listy(ptr3);

  DodajDoListyRysowania(Lacze,FSR);
  DodajDoListyRysowania(Lacze,Perseverance);
  DodajDoListyRysowania(Lacze,Curiosity);
  DodajDoListyRysowania(Lacze,Regolit1);
  DodajDoListyRysowania(Lacze,Regolit2);
  DodajDoListyRysowania(Lacze,Regolit3);

  FSR_ptr->Przelicz_i_Zapisz_Wierzcholki();
  Perseverance_ptr->Przelicz_i_Zapisz_Wierzcholki();
  Curiosity_ptr->Przelicz_i_Zapisz_Wierzcholki();
  ptr1->Przelicz_i_Zapisz_Wierzcholki();
  ptr2->Przelicz_i_Zapisz_Wierzcholki();
  ptr3->Przelicz_i_Zapisz_Wierzcholki();

  
  Lacze.Rysuj();

}

void Scena::wybierz_lazik(int numer_lazika){
    std::list<std::shared_ptr<ObiektGeom>>::iterator iter = _ObiektySceny.begin();
    for(int i=0;i<numer_lazika;++i){
        _AktywnyLazik = std::static_pointer_cast<Lazik>(*iter);
        ++iter;
    }
}

void Scena::zmien_lazik(){
    std::cout << "Dostępne łaziki: " << std::endl;
    std::list<std::shared_ptr<ObiektGeom>>::iterator iter = _ObiektySceny.begin();
    int numer_lazika;
    std::cout << "1 ---------- Nazwa: " << std::static_pointer_cast<Lazik>(*iter)->WezNazweObiektu() << std::endl;
    std::cout << "         Położenie:" << std::static_pointer_cast<Lazik>(*iter)->get_polozenie() << std::endl;
    std::cout << "        Orientacja: " << std::static_pointer_cast<Lazik>(*iter)->get_kat() << std::endl << std::endl;
    ++iter;
    std::cout << "2 ---------- Nazwa: " << std::static_pointer_cast<Lazik>(*iter)->WezNazweObiektu() << std::endl;
    std::cout << "         Położenie:" << std::static_pointer_cast<Lazik>(*iter)->get_polozenie() << std::endl;
    std::cout << "        Orientacja: " << std::static_pointer_cast<Lazik>(*iter)->get_kat() << std::endl << std::endl;
    ++iter;
    std::cout << "3 ---------- Nazwa: " << std::static_pointer_cast<Lazik>(*iter)->WezNazweObiektu() << std::endl;
    std::cout << "         Położenie:" << std::static_pointer_cast<Lazik>(*iter)->get_polozenie() << std::endl;
    std::cout << "        Orientacja: " << std::static_pointer_cast<Lazik>(*iter)->get_kat() << std::endl << std::endl;
    std::cout << "Podaj numer łazika: " << std::endl;
    std::cin >> numer_lazika;
    wybierz_lazik(numer_lazika);
}

TypKolizji Scena::Czy_kolizja_aktywnego(){
    CzyMoznaPodniesc = false;
    TypKolizji wynik = TK_BrakKolizji;
    for(const std::shared_ptr<ObiektGeom> & Ob : _ObiektySceny)
    {
      if(_ObiektySceny.empty()) return wynik;
        if(Ob != _AktywnyLazik)
        {
            wynik = _AktywnyLazik->Czy_koliduje(Ob);
            
            if(wynik != TK_BrakKolizji)
            {
                if(Ob->JakiObiekt() == "ProbkaRegolitu" && _AktywnyLazik->JakiObiekt() == "LazikSFR") 
                {
                    std::cout << std::endl << "Wykryto próbkę!" << std::endl << std::endl;
                    _Aktualnaprobka = std::static_pointer_cast<ProbkaRegolitu>(Ob);
                    CzyMoznaPodniesc = true;
                }else{
                    std::cout << std::endl << "Kolizja!" << std::endl << std::endl;
                }
                return wynik;
            }
        }
    }
    return wynik;
}

void Scena::jedz(){
    double odleglosc;
    bool temp=false;
    CzyMoznaPodniesc = false;
    Wektor3D pom;
    std::cout << "Podaj odległość(w jednostkach sceny): " << std::endl;
    std::cin >> odleglosc;
    pom[0] = odleglosc;
    temp =_AktywnyLazik.get()->jedz(pom,Lacze,_ObiektySceny);
    if(temp==true) {Czy_kolizja_aktywnego();}

}

void Scena::obroc(){
    std::cout << std::endl << "Podaj rotacje (w stopniach):" <<  std::endl;
    int kat;
    bool temp=false;
    CzyMoznaPodniesc = false;
    std::cin >> kat;
    _AktywnyLazik.get()->Obroc(kat,Lacze,_ObiektySceny);
    if(temp==true) {Czy_kolizja_aktywnego();}
}

void Scena::dodaj_do_listy(std::shared_ptr<ObiektGeom> Obiekt){  
    (this->_ObiektySceny).push_back(Obiekt);

}

void Scena::usun_z_listy(std::shared_ptr<ObiektGeom> Obiekt){  

    (this->_ObiektySceny).remove(Obiekt);
}

void Scena::Wyswietl_wektory(){
    Wektor3D pom;
    std::cout<< "Aktualna ilość wektorów: " << pom.get_wektor_ilosc() << std::endl;
    std::cout<< "Ilość wszystkich wektorów: " << pom.get_wektor_ilosc_max() << std::endl<< std::endl;
}

void Scena::Wyswietl_nazwa(){
    std::cout << "Aktywny łazik:"<< std::endl << "  " << _AktywnyLazik.get()->WezNazweObiektu()<<std::endl;
}

void Scena::Wyswietl_polozenie(){
    std::cout << "Położenie łazika: x, y, z:" << std::endl << " " << _AktywnyLazik.get()->get_polozenie()<<std::endl;
}

void Scena::Wyswietl_orientacja(){
    int kat_pom;
    if(_AktywnyLazik.get()->get_kat()>360)

        kat_pom = _AktywnyLazik.get()->get_kat()-360;
    else if(_AktywnyLazik.get()->get_kat()<-360)
        kat_pom = _AktywnyLazik.get()->get_kat()+360;
    else kat_pom = _AktywnyLazik.get()->get_kat();
    std::cout << "Orientacja łazika w stopniach:" << std::endl << "  " << kat_pom <<std::endl<<std::endl;
}

void Scena::Wyswietl_menu(){
    std::cout << "===============================================================================" << std::endl;
    Wyswietl_nazwa();
    Wyswietl_polozenie();
    Wyswietl_orientacja();
    Wyswietl_wektory();
    WyswietlProbkiSFR(std::cout);
    std::cout << "j - jazda na wprost" << std::endl << "o - obroc lazik" << std::endl << "w - wybor lazika" << std::endl << 
    "p - podnies probke " << std::endl << "k - koniec dzialania programu" << std::endl << "l - wyswietlanie probek na mapie" << std::endl << std::endl;
    
}

void Scena::WyswietlProbki (std::ostream &StrmWy){
    int i=-2;
    for(const std::shared_ptr<ObiektGeom> & Ob : _ObiektySceny){
        if(Ob->JakiObiekt() == "ProbkaRegolitu"){
            StrmWy<<i<<". ";
            StrmWy << Ob->WezNazweObiektu() << std::endl;
        }
        ++i;
    }
    if(i==1){StrmWy << " Zebrałeś wszystkie próbki! Gratulacje!!!" << std::endl;}
    StrmWy << std::endl;
}

 void Scena::ZbierzProbke (std::shared_ptr<ObiektGeom>  Probka){
     if(_AktywnyLazik->JakiObiekt() != "LazikSFR"){
         std::cerr << "Lazik inny niz SFR. Nie mozna zebrac probki!" << std::endl;
     }
     else{  
         std::static_pointer_cast<LazikSFR>(_AktywnyLazik)->DodajDoListyProbek(std::static_pointer_cast<ProbkaRegolitu>(Probka));
         Lacze.UsunNazwePliku(Probka->WezNazwePliku_BrylaRysowana());
         _ObiektySceny.remove(Probka);
         CzyMoznaPodniesc = false;

         Lacze.Rysuj();
     }
 }

void Scena::PodejmijProbke(){
    if(CzyMoznaPodniesc == false) std::cout << "Nie można zebrać probki" << std::endl;
    else ZbierzProbke(_Aktualnaprobka);
}
 
 void Scena::WyswietlProbkiSFR (std::ostream &StrmWyj){
    if(_AktywnyLazik->JakiObiekt() == "LazikSFR") {
        std::static_pointer_cast<LazikSFR>(_AktywnyLazik)->WyswietlListeProbek(StrmWyj);
    }
}