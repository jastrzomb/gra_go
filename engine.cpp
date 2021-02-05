
#include"engine.h"
#include"menu.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define white 1
#define black -1
#define n 8 

	void ruch::set(char z, int m)
	{
		i = z;
		j = m;
	}
	int ruch::getk() {
		return i;
	}
	int ruch:: getw() {
		return j;
	}
	ruch& ruch::operator=(const ruch& rv) {
		i = rv.i;
		j = rv.j;
		return *this;
	}
	void pole:: set(int x)
	{
		if (x == 1)
		{
			if (typ == -x)
			{
				pole_czrne--;
			}
			
			pole_biale++;
		}
		else
		{
			if (typ == -x)
			{
				pole_biale--;
			}
			pole_czrne++;
		}
		typ = x;
	}
	int pole::typ_pola()
	{
		return typ;
	}
	void pole::set_czy() 
	{
		czy_mozna = 1;
	}
	void pole ::zaj()	
	{
		czy_mozna = 0;		
	}
	int pole::get_czy() 
	{
		return czy_mozna;
	}
	int pole:: get_biale() 
	{
		return pole_biale;
	}
	int pole::get_czrne() 
	{
		 return pole_czrne;
	}
	void pole::set_biale() 
	{
		 pole_biale = 0;
	}
	void pole::set_czrne() 
	{
		 pole_czrne = 0;
	}
	void pole::kopia(int x)
	{
		 if (x == 1)
		 {
			 pole_biale++;
		 }
		 else if(x==-1)
		 {
			 pole_czrne++;
		 }
		 typ = x;
	}
	pole::pole() :typ(0), czy_mozna(0) {}
	int pole::pole_biale = 0;
	int pole::pole_czrne = 0;
	void plansza::inicjalizacja_planszy()
	{
		tab[0][0].set_czrne();
		tab[0][0].set_biale();
		tab[4][4].set(white);
		tab[4][5].set(black);
		tab[5][5].set(white);
		tab[5][4].set(black);
	}
	void plansza::pokaz_plansze()
	{
		system("cls");
		printf("kafelki czarne:%d\tkafelki biale: %d\n", tab[0][0].get_czrne(), tab[0][0].get_biale());
		printf("W-white\t\t\tB-black\n");
		printf("   A   B   C   D   E   F   G   H\n");
		printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 191);
		for (int i = 1; i < n + 1; ++i)
		{
			printf("%d", i);
			printf("%c", 179);
			for (int j = 1; j < n + 1; ++j)
			{
				if (tab[i][j].typ_pola() == white)
				{
					printf(" W %c", 179);
				}
				else if (tab[i][j].typ_pola() == black)
				{
					printf(" B %c", 179);
				}
				else
				{
					printf("   %c", 179);
				}	
			}
		printf("%d", i);
		printf("\n");
		if (i != n)
		{
			printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 180);
		}
		else
		{
			printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 217);
		}
		}
	printf("   A   B   C   D   E   F   G   H\n");
	
	}
void plansza::spr_pola(int i, int j, int x) {
	int drugi_kolor = -x;
	if (tab[i][j].typ_pola() == 0)
	{
		//West
		int k = 1;
		while (tab[i][j - k].typ_pola() == drugi_kolor)
		{
			k++;
		}
		if (tab[i][j - k].typ_pola() == x && k != 1)
		{
			tab[i][j].set_czy();
		}
		//South-WESt
		k = 1;
		while (tab[i + k][j - k].typ_pola() == drugi_kolor)
		{
			k++;
		}
		if (tab[i + k][j - k].typ_pola() == x && k != 1)
		{
			tab[i][j].set_czy();
		}
		//South
		k = 1;
		while (tab[i + k][j].typ_pola() == drugi_kolor)
		{
			k++;
		}
		if (tab[i + k][j].typ_pola() == x && k != 1)
		{
			tab[i][j].set_czy();

		}

		//South-East
		k = 1;
		while (tab[i + k][j + k].typ_pola() == drugi_kolor)
		{
			k++;
		}
		if (tab[i + k][j + k].typ_pola() == x && k != 1)
		{
			tab[i][j].set_czy();
		}
		//East
		k = 1;
		while (tab[i][j + k].typ_pola() == drugi_kolor)
		{
			k++;
		}
		if (tab[i][j + k].typ_pola() == x && k != 1)
		{
			tab[i][j].set_czy();
		}
		//North-East
		k = 1;
		while (tab[i - k][j + k].typ_pola() == drugi_kolor)
		{
			k++;
		}
		if (tab[i - k][j + k].typ_pola() == x && k != 1)
		{
			tab[i][j].set_czy();
		}
		//North
		k = 1;
		while (tab[i - k][j].typ_pola() == drugi_kolor)
		{
			k++;
		}
		if (tab[i - k][j].typ_pola() == x && k != 1)
		{
			tab[i][j].set_czy();
		}
		//North-West
		k = 1;
		while (tab[i - k][j - k].typ_pola() == drugi_kolor)
		{
			k++;
		}
		if (tab[i - k][j - k].typ_pola() == x && k != 1)
		{
			tab[i][j].set_czy();
		}
	}
	else
	{
		tab[i][j].zaj();
	}

}
void plansza::spr_tablicy(int x) {
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{			
			tab[i][j].zaj();
		}
	}
	ilosc_ruchuw = 0;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			spr_pola(i, j, x);
			if (tab[i][j].get_czy() == 1)
			{				
				ilosc_ruchuw++;
			}
		}
		
	}
}
bool plansza::mozliwy_ruch(int x, int y) {
	if (tab[x][y].get_czy() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void plansza::odwracanie(int i, int j, int x) {
	int drugi_kolor = -x;
	//West
	int k = 1;
	while (tab[i][j - k].typ_pola() == drugi_kolor)
	{
		k++;
	}
	if (tab[i][j - k].typ_pola() == x && k != 1)
	{
		for (int p = 1; p < k; p++)
		{
			tab[i][j - p].set(x);
		}
	}
	//South-WESt
	k = 1;
	while (tab[i + k][j - k].typ_pola() == drugi_kolor)
	{
		k++;
	}
	if (tab[i + k][j - k].typ_pola() == x && k != 1)
	{
		for (int p = 1; p < k; p++)
		{
			tab[i + p][j - p].set(x);
		}
	}
	//South
	k = 1;
	while (tab[i + k][j].typ_pola() == drugi_kolor)
	{
		k++;
	}
	if (tab[i + k][j].typ_pola() == x && k != 1)
	{
		for (int p = 1; p < k; p++)
		{
			tab[i + p][j].set(x);
		}

	}

	//South-East
	k = 1;
	while (tab[i + k][j + k].typ_pola() == drugi_kolor)
	{
		k++;
	}
	if (tab[i + k][j + k].typ_pola() == x && k != 1)
	{
		for (int p = 1; p < k; p++)
		{
			tab[i + p][j + p].set(x);
		}
	}
	//East
	k = 1;
	while (tab[i][j + k].typ_pola() == drugi_kolor)
	{
		k++;
	}
	if (tab[i][j + k].typ_pola() == x && k != 1)
	{
		for (int p = 1; p < k; p++)
		{
			tab[i][j + p].set(x);
		}
	}
	//North-East
	k = 1;
	while (tab[i - k][j + k].typ_pola() == drugi_kolor)
	{
		k++;
	}
	if (tab[i - k][j + k].typ_pola() == x && k != 1)
	{
		for (int p = 1; p < k; p++)
		{
			tab[i - p][j + p].set(x);
		}
	}
	//North
	k = 1;
	while (tab[i - k][j].typ_pola() == drugi_kolor)
	{
		k++;
	}
	if (tab[i - k][j].typ_pola() == x && k != 1)
	{
		for (int p = 1; p < k; p++)
		{
			tab[i - p][j].set(x);
		}
	}
	//North-West
	k = 1;
	while (tab[i - k][j - k].typ_pola() == drugi_kolor)
	{
		k++;
	}
	if (tab[i - k][j - k].typ_pola() == x && k != 1)
	{
		for (int p = 1; p < k; p++)
		{
			tab[i - p][j - p].set(x);
		}
	}
	tab[i ][j].set(x);

}
ruch wczytaj_ruch()
{
	char klawiatura[10];
	ruch jak;
	
	printf("podaj ruch w formacie: B5 albo pauza\n");
	while (scanf_s("%s",klawiatura,10)!=1 ||klawiatura[0] < 'A' ||klawiatura[0] > 'H' ||klawiatura[1] < '1'||klawiatura[1] > '8'||klawiatura[2] != 0)
	{
		if (strcmp(klawiatura, "pauza") == 0)
		{
			jak.set(0, 0);
			return jak;
		}
		printf("blad.podaj ruch w formacie: B5 albo pauza\n");
	
		while (getchar() != '\n');
	}
	
		jak.set(klawiatura[0] - 'A' + 1, klawiatura[1]-'1'+1);		
	
	return jak;
}
gracz::gracz(int a):kolor(a){}
	int ai:: zrub_ruch(plansza& board,int oznacznie) {
		losowanie = 0;
		int liczba = rand() % board.ilosc_ruchuw + 1;
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (board.tab[i][j].get_czy() == 1)
				{
					losowanie++;
				}
				if (losowanie == liczba)
				{
					board.odwracanie(i, j, kolor);
					return ((i*8)+j);
				}
			}
		}
		return 0;
	}
	ai::ai(int a):gracz(a){}
	int human:: zrub_ruch(plansza& board,int oznaczenie) {
		int odp=1;
		ruch czlowieka=wczytaj_ruch();
		while (board.mozliwy_ruch(czlowieka.getw(), czlowieka.getk()) != true)
		{
			if (czlowieka.getk() == 0 && czlowieka.getw() == 0)
			{
				 odp=pauza(board,oznaczenie);
				if (odp == 1)
				{
					return 1;
				}
				if (odp == 2)
				{
					break;
				}
				czlowieka = wczytaj_ruch();
				continue;
			}
			printf("bledny ruch\n");
			czlowieka = wczytaj_ruch();
			
		} 
		if (odp == 1)
		{
			board.odwracanie(czlowieka.getw(), czlowieka.getk(), kolor);
		}
		return 0;
	}
	human::human(int a):gracz(a) {}
	

