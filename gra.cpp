#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include "menu.h"
#include "engine.h"
#define white 1
#define black -1
#define n 8 
//okreslenie czyja tura
void tura(int x)
{
	if (x == 0)
	{
		printf("\ntura bialych\n");
	}
	else
	{
		printf("\ntura czarnych\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		//zmienne pomocne przy okresleniu czyj ruch 
		int pomoc;
		int poprzedni = 0;
		int skok=0;
		//inicjalizacja planszy
		plansza board;
		board.inicjalizacja_planszy();
		//zmienna przekazujaca czyj ruch
		int kolor;
		//wybór opcji z menu
		int oznaczenie = menu(board);
		//oznaczenie przyjmuje wartosci ujemne gdy zamieniona wartosc ruchów 
		if (oznaczenie < 0)
		{
			skok = 1;
			oznaczenie *= -1;
		}
		pomoc = board.tab[0][0].get_biale() + board.tab[0][0].get_czrne()+skok;
		pomoc = pomoc % 2;
		//okreslenie koloru pocztkowego sytuacja gdy wczytujemy gre
		if (pomoc == 0)
		{
			kolor = white;
		}
		else
		{
			kolor = black;
		}
		//wersja gry z human vs ai
		if (oznaczenie == 1)
		{
			//incjalizacja wersji gry z human vs ai
			gra<human, ai> zawodnik;
			board.pokaz_plansze();
			board.spr_tablicy(kolor);
			poprzedni = 0;
			while (1)
			{
				//zmienne pomocnicze aby odpowiednie komórki zmieniac
				int x, y;
				//ustalenie koloru gracza grajacego
				pomoc = board.tab[0][0].get_biale() + board.tab[0][0].get_czrne()+skok;
				pomoc = pomoc % 2;
				if (pomoc == 0)
				{
					kolor = white;
				}
				else
				{
					kolor = black;
				}
				//sprawdzenie mozliwych ruchow gracza i jesli nie ma zadnych to pasuje a jesli poprzedni gracz tez nie mial to koniec gry
				board.spr_tablicy(kolor);
				if (board.ilosc_ruchuw == 0)
				{
					if (poprzedni == 1)
					{
						break;
					}
					else
					{
						if (pomoc == 0)
						{
							printf("biale pasuja\n");
						}
						else
						{
							printf("czarne pasuja\n");
						}

						poprzedni = 1;
						skok++;
						continue;
					}

				}
				else
				{
					poprzedni = 0;
				}
				//kosmetyka wypisanie czyj ruch
				tura(pomoc);
				if (kolor == white)
				{
					//ruch gracza bialego czlowiek jesli ==1 to wraca do menu glownego
					if (zawodnik.ruch_G1(board, oznaczenie) ==1)
					{
						poprzedni = -1;
						break;
					}
				}
				else
				{
					//ruch gracza czrnego ai
					int tmp = zawodnik.ruch_G2(board, oznaczenie);
					x = tmp / 8;
					y = tmp % 8;

				}
				board.pokaz_plansze();
				if (pomoc == 1)
				{
					printf("koputer zrobil ruch: %c%d\n", y+'A'-1, x);
				}
				
			}
		}
		if (oznaczenie == 2)
		{
			//incjalizacja gry guman vs human
			gra<human, human> zawodnik;
			board.pokaz_plansze();
			board.spr_tablicy(kolor);
			poprzedni=0;
			while (1)
			{
				//okreslenie koloru
				pomoc = board.tab[0][0].get_biale() + board.tab[0][0].get_czrne()+skok;
				pomoc = pomoc % 2;
				if (pomoc == 0)
				{
					kolor = white;
				}
				else
				{
					kolor = black;
				}
				//sprawdzenie ruchow gracza i sprawdzenie czy pasuje czy konczy gre
				board.spr_tablicy(kolor);
				if (board.ilosc_ruchuw == 0)
				{
					if (poprzedni == 1)
					{
						break;
					}
					else
					{
						poprzedni = 1;
						skok++;
						continue;
					}
					
				}
				else
				{
					poprzedni = 0;
				}
				//pokazuje czyj ruch
				tura(pomoc);
				if (kolor == white)
				{
					//ruch bialego gracza
					if (zawodnik.ruch_G1(board, oznaczenie) == 1)
					{
						poprzedni = -1;
						break;
					}
				}
				else
				{
					//ruch czrnego gracza
					if (zawodnik.ruch_G2(board, oznaczenie) == 1)
					{
						poprzedni = -1;
						break;
					}
				}
				board.pokaz_plansze();

			}
		
		}
		//sprawdzenie kto wygral
		if (poprzedni == 1)
		{
			if (board.tab[0][0].get_biale() > board.tab[0][0].get_czrne())
			{
				printf("biale wygraly\n");
			}
			else if (board.tab[0][0].get_biale() < board.tab[0][0].get_czrne())
			{
				printf("czrne wygralu\n");
			}
			else
			{
				printf("remis\n");
			}
			printf("napisz cokolwiek aby przejsc do menu\n");
			//czyszczenie bufora a zarazem zatrzymanie aby zobaczy sytuacje dla gracza
			while (getchar() != '\n');
			getchar();
		}
		
	}
	return 0;
}