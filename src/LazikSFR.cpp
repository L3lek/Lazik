#include "LazikSFR.hh"


void LazikSFR::DodajDoListyProbek (std::shared_ptr<ProbkaRegolitu> ProbRego){
    ListaProbek.push_back(ProbRego);
}

void LazikSFR::WyswietlListeProbek(std::ostream &StrmWy){
    int i=1;
    if(ListaProbek.empty()) {StrmWy << "                         (brak probek na liscie)" << std::endl; }
    else{
    for(const std::shared_ptr<ProbkaRegolitu> & Pr : ListaProbek){
            StrmWy<<"                         "<<i<<". ";
            StrmWy << Pr->WezNazweObiektu() << std::endl;
        ++i;
    }
    }
}
