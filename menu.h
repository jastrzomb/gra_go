

#ifndef menu_h
#define menu_h
#include "engine.h"
//funkcja do wczytania zapisanej gry
int wczytaj_plik(plansza& board);
//funkcja zapisu gry
void zapisz_plik(plansza& board,int oznaczenie);
//interfejs z uzytkownikiem 
int menu(plansza& board);
//interfejs z uzytkownik kiedy zatrzymasz gre
int pauza(plansza& board,int oznaczenie);
#endif
