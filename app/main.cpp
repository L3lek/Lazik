#include <iostream>
#include <fstream>

#include "Scena.hh"

/*!                                                                                                      
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.                              
 *                                                                                                       
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,                                       
 *  które będą widoczne jako obszar objęty układem współrzędnych.                                        
 *  Następnie w tle uruchamiany jest program gnuplot.                                                    
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.                                                    
 */
void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze){
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);
  rLacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok                                            
  rLacze.Inicjalizuj();  // Tutaj startuje gnuplot.                                                      
}

int main(){
  PzG::LaczeDoGNUPlota  Lacze;
  Scena nowascena;

  std::cout << std::endl << "Start programu gnuplot" << std::endl << std::endl;


  bool forwhile = true;
  while (forwhile){
    nowascena.Wyswietl_menu();
    char wybor;
    std::cin >> wybor;

    switch(wybor){
    case 'j':
      nowascena.jedz();
      break;

    case 'o':
      nowascena.obroc();
      break;

    case 'p':
      nowascena.PodejmijProbke();
      break;

    case 'w':
      nowascena.zmien_lazik();
      break;

    case 'l':
      nowascena.WyswietlProbki(std::cout);
      break;

    case 'k':
      forwhile = false;
      break;

    default:
      std::cout << "Nieznana komenda, sproboj podnownie." << std::endl;
    }
  }
}

