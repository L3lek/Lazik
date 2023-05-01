#include <iostream>
#include "ObrysXY.hh"

Wektor2D Obrys::konwersja(Wektor3D pom){
    Wektor2D zwracany;
    zwracany.ustaw(pom.get_wektor(0),pom.get_wektor(1));
    return zwracany;
}

void Obrys::ustaw_pierwszy_raz(Wektor3D pom){
    Wektor2D tmp;
    tmp = konwersja(pom);
    (*this).set_max(0, tmp[0]);
    (*this).set_max(1, tmp[1]);
    (*this).set_min(0, tmp[0]);
    (*this).set_min(1, tmp[1]);
}


void Obrys::wyznacz_obrys(Wektor3D pom){
    Wektor2D porownywany;
    Obrys pomocniczy;
    porownywany = pomocniczy.konwersja(pom);

    if(porownywany[0]>(*this)._max[0])
        (*this).set_max(0, porownywany[0]);

    if(porownywany[1]>(*this)._max[1])
        (*this).set_max(1, porownywany[1]);

    if(porownywany[0]<(*this)._min[0])
        (*this).set_min(0, porownywany[0]);

    if(porownywany[1]<(*this)._min[1])
        (*this).set_min(1, porownywany[1]);
}

bool Obrys::kolizja(Obrys obiekt){
    if(((*this)._max[0]<obiekt._max[0]&&(*this)._max[0]>obiekt._min[0])&&((*this)._max[1]<obiekt._max[1]&&(*this)._max[1]>obiekt._min[1]))
        return true;
    else if(((*this)._min[0]<obiekt._max[0]&&(*this)._min[0]>obiekt._min[0])&&((*this)._min[1]<obiekt._max[1]&&(*this)._min[1]>obiekt._min[1]))
        return true;
    else if(((*this)._max[0]<obiekt._max[0]&&(*this)._max[0]>obiekt._min[0])&&((*this)._min[1]<obiekt._max[1]&&(*this)._min[1]>obiekt._min[1]))
        return true;
    else if(((*this)._min[0]<obiekt._max[0]&&(*this)._min[0]>obiekt._min[0])&&((*this)._max[1]<obiekt._max[1]&&(*this)._max[1]>obiekt._min[1]))
        return true;  
    else if(((*this)._min[0]<obiekt._min[0]&&(*this)._min[0]<obiekt._max[0]&&(*this)._max[0]>obiekt._min[0]&&(*this)._max[0]>obiekt._max[0])&&
            ((*this)._min[1]<obiekt._min[1]&&(*this)._min[1]<obiekt._max[1]&&(*this)._max[1]>obiekt._min[1]&&(*this)._max[1]>obiekt._max[1]))
        return true;   
    else return false;
}