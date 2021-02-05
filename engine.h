
#ifndef engine_h
#define engine_h
//klasa przechowujaca ruch gracza
class ruch {
	int i;
	int j;
public:
	void set(char z, int m);
	int getk();
	int getw();
	ruch& operator=(const ruch& rv);
}; 
//klasa która buduje plansze
class pole {
	int typ;
	int czy_mozna;

public:
	int static pole_czrne;
	int static pole_biale;
	void set(int x);
	int typ_pola();
	void set_czy();
	void zaj();
	int get_czy();
	int get_biale();
	int get_czrne();
	void set_biale();
	void set_czrne();
	void kopia(int x);
	pole();
};
//klasa na której gra siê rozgrywa
class plansza {
public:
	pole tab[10][10];
	int ilosc_ruchuw;
	plansza() :ilosc_ruchuw(4) {}
	void inicjalizacja_planszy();
	void pokaz_plansze();
	void spr_pola(int i, int j, int x);
	void spr_tablicy(int x);
	bool mozliwy_ruch(int i, int j);
	void odwracanie(int i, int j, int x);
};
//funckja do wczytania ruchu gracza + mozliwosc pauzy
ruch wczytaj_ruch();
//klasa rodzicielska human i ai
class gracz {
protected:
	int kolor;
public:
	virtual void zrub_ruch() {}
	gracz(int a);
};
//klasa odpowiada za gracza ktory jest ai
class ai :public gracz {
	int losowanie = 0;
public:
	int zrub_ruch(plansza& board,int oznaczenie);
	ai(int a);
};
//klasa odpowiada za gracza który jest cz³owiekiem
class human :public gracz {
public:
	int zrub_ruch(plansza& board,int oznaczenie);
	
	human(int a);
};
//klasa która pozwala po³aczyæ typy graczy do jednej gry
template<typename G1,typename G2>
class gra {
	G1 player;
	G2 player2;
public:
	int ruch_G1(plansza& board,int oznaczenie) {
		return player.zrub_ruch(board,oznaczenie);
	}
	int ruch_G2(plansza& board,int oznaczenie) {
		return player2.zrub_ruch( board,oznaczenie);
	}
	gra():player(1),player2(-1){}
};

#endif