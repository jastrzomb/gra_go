
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "engine.h"
#define plik "zapis.txt"
bool czy_jest_plik()
{
	FILE *f;
	errno_t err;
	err = fopen_s(&f, plik, "r");
	if (errno != 0)
	{
		fclose(f);
		return false;
	}
	else
	{
		fclose(f);
		return true;
	}	
}
int wczytaj_plik(plansza& board)
{
	FILE *f;
	errno_t err;
	err = fopen_s(&f, plik, "r");
	if (errno != 0)
	{
		printf("nieudalo sie wczytac.koniec programu\n");
		exit(0);
	}
	int typ;
	int znak;
	int przeskok;
	fscanf_s(f,"%d",&przeskok);
	fscanf_s(f,"%d",&typ);
	board.tab[0][0].set_czrne();
	board.tab[0][0].set_biale();
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			fscanf_s(f, "%d",&znak);
			board.tab[i][j].kopia(znak);
		}
	}
	fclose(f);
	
	if (typ == 'A')
	{
		if (przeskok == 0)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else if (typ == 'H')
	{
		if (przeskok == 0)
		{
			return 2;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return 0;
	}
}
void zapisz_plik(plansza& board,int oznaczenie)
{
	FILE *f;
	errno_t err;
	err = fopen_s(&f, plik, "w");
	if (errno != 0)
	{
		printf("nieudalo sie zapisac.koniec programu%d\n",errno);
		exit(0);
	}
	if (oznaczenie < 0)
	{
		fprintf_s(f, "%d ", 1);
		oznaczenie *=-1 ;
	}
	else
	{
		fprintf_s(f, "%d ", 0);
	}
	int typ;
	if (oznaczenie == 1)
	{
		typ = 'A';
	}
	else
	{
		typ = 'H';
	}
	
	int znak;
	fprintf_s(f, "%d ", typ);
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			znak=board.tab[i][j].typ_pola();
			fprintf_s(f,"%d ", znak);
		}
	}
	fclose(f);
}
int menu(plansza& board)
{
	char wybur[30];
	
	while (1)
	{
		system("cls");
		printf("napisz aby wybrac\n\n");
		printf("Nowa gra vs ai\n");
		printf("Nowa gra vs human\n");
		if (czy_jest_plik() == true)
		{
			printf("Wczytaj gre\n");
		}
		printf("Zamknij program\n");
		fgets(wybur, 30, stdin);
		if (strcmp("Nowa gra vs ai\n", wybur) ==0 )
		{
			return 1;
		}
		if (strcmp("Nowa gra vs human\n", wybur) ==0 )
		{
			return 2;
		}
		if (strcmp("Wczytaj gre\n", wybur) == 0)
		{
			int kontrol=wczytaj_plik(board);
			
			return kontrol;
		}
		
		if (strcmp("Zamknij program\n", wybur) == 0)
		{
			exit(0);
		}
		if (!strchr(wybur, '\n'))
		{
			while (getchar() != '\n');
		}
		system("cls");
		printf("bledne dane. podaj jeszcze raz\n");
	}
}
int pauza(plansza& board,int oznaczenie)
{
	while (getchar() != '\n');
	char wybur[30];
	while (1)
	{
		system("cls");
		printf("napisz aby wybrac\n\n");
		printf("Wznow\n");
		printf("Zapisz gre\n");
		printf("Powrot do menu\n");
		fgets(wybur, 30, stdin);
		if (strcmp("Wznow\n", wybur) == 0)
		{
			return 2;
		}
		if (strcmp("Zapisz gre\n", wybur) == 0)
		{
			zapisz_plik(board, oznaczenie);
			continue;
		}
		if (strcmp("Powrot do menu\n", wybur) == 0)
		{
			return 1;
		}
		while (getchar() != '\n');
		printf("bledne dane. podaj jeszcze raz\n");
	}


}