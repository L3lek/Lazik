#include "Lazik.hh"

#include<math.h>
#include <thread>
#include <chrono>
#include <memory>

TypKolizji Lazik::Czy_kolizja(std::list<std::shared_ptr<ObiektGeom>> Obiekty){
    std::list<std::shared_ptr<ObiektGeom>>::iterator iter = Obiekty.begin();
    int rozmiar;
    rozmiar = Obiekty.size();
    if(Obiekty.empty()) return TK_BrakKolizji;
    for(int i=0;i<rozmiar;++i){
        if((*this).get_obrys().kolizja(std::static_pointer_cast<ObiektGeom> (*iter).get()->get_obrys())==true)
            
            return TK_Kolizja;
        ++iter;
    }
    return TK_BrakKolizji;
}
TypKolizji Lazik::Czy_koliduje (std::shared_ptr<ObiektGeom> (Obiekt)){
        if((*this).get_obrys().kolizja(Obiekt.get()->get_obrys())==true)
            {return TK_Kolizja;}
            else
            {return TK_BrakKolizji;}
}

bool Lazik::jedz(Wektor3D wek_przemieszczenia, PzG::LaczeDoGNUPlota& Lacze, std::list<std::shared_ptr<ObiektGeom>> Obiekty){
    double dlug_wek = wek_przemieszczenia.dlugosc();
    int i=0;
    MacierzObrotu rot;
    Wektor3D aktualne_polozenie;
    bool warunek=false;
    wek_przemieszczenia = rot.ObrotZ((*this).get_kat(), wek_przemieszczenia);
    wek_przemieszczenia = wek_przemieszczenia/ dlug_wek;

    while((i<dlug_wek)&&(warunek==false)){
        usleep(4000);
        aktualne_polozenie=(*this).get_polozenie()+wek_przemieszczenia;
        (*this).set_polozenie(aktualne_polozenie);
        (*this).Przelicz_i_Zapisz_Wierzcholki();
        Lacze.Rysuj();
        warunek = Czy_kolizja(Obiekty);
        i++;
    }
    return warunek;
}

int Lazik::wzor_redukcyjny(double kat){
    int pomoc;
    if(kat>360){
        pomoc = kat/360;
        kat = kat-360*pomoc;
    }

    if(kat<-360){
        pomoc = kat/360;
        kat = kat+360*pomoc;
    }

    return kat;
}


bool Lazik::Obroc(double kat, PzG::LaczeDoGNUPlota& Lacze_do_Gnu, std::list<std::shared_ptr<ObiektGeom>> Obiekty){
    Wektor3D pozycja,pozycja_0;
    MacierzObrotu obrot;
    pozycja = (*this).get_polozenie();
    pozycja_0 = pozycja.odwrotnosc();
    int stopien=1;
    int iter=0;
    bool warunek=false;
    kat=wzor_redukcyjny(kat);

    if(kat>=0){
        while((iter<kat)&&(warunek==false)){
            std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
            (*this).set_polozenie(pozycja+pozycja_0);
            (*this).Przelicz_i_Zapisz_Wierzcholki();
            (*this).Obroc_suma(stopien);
            (*this).set_polozenie(pozycja);
            (*this).Przelicz_i_Zapisz_Wierzcholki();
            warunek = Czy_kolizja(Obiekty);
            if(warunek == false)
                Lacze_do_Gnu.Rysuj();
            ++iter;
        }
    }
    else{
        while((iter>kat)&&(warunek==false)){
            std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
            (*this).set_polozenie(pozycja+pozycja_0);
            (*this).Przelicz_i_Zapisz_Wierzcholki();
            (*this).Obroc_suma(-stopien);
            (*this).set_polozenie(pozycja);
            (*this).Przelicz_i_Zapisz_Wierzcholki();
            warunek = Czy_kolizja(Obiekty);
            if(warunek == false)
                Lacze_do_Gnu.Rysuj();
            --iter;
        }
    }

    return warunek;
}
