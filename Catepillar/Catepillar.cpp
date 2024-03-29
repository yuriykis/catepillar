#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#define GORA '1'
#define DOL '2'
#define LEWO '3'
#define PRAWO '4'
#define PUSTE '#'

struct modul {
	char znak;
	modul* nastepny;
	modul();
};
modul::modul() {
	nastepny = NULL;
}

struct lista {
	modul* pierwszy;
	modul* ostatni;
	void dodaj_koniec(char);
	void dodaj_poczatek(char);
	void usun_koniec();
	void usun_poczatek();
	void wyswietl_liste();
	lista();
};

lista::lista() {
	pierwszy = NULL;
	ostatni = NULL;
}

void lista::dodaj_koniec(char znak) {
	modul* nowy = new modul;
	nowy->znak = znak;

	if (pierwszy == NULL) {
		pierwszy = nowy;
	}
	else {
		modul* temp = pierwszy;
		while (temp->nastepny) {
			temp = temp->nastepny;
		}
		temp->nastepny = nowy;
		nowy->nastepny = NULL;
		ostatni = nowy;
	}
}

void lista::dodaj_poczatek(char znak) {
	modul* nowy = new modul;
	nowy->znak = znak;

	if (pierwszy == NULL) {
		pierwszy = nowy;
		nowy->nastepny = NULL;
	}
	else {
		nowy->nastepny = pierwszy;
		pierwszy = nowy;
	}
}

void lista::usun_koniec() {
	if (pierwszy == ostatni) {
		pierwszy = NULL;
		ostatni = NULL;
	}
	else {
		int i = 0;
		modul* temp = pierwszy;
		while (temp->nastepny->nastepny != NULL) {
			temp = temp->nastepny;
		}
		temp->nastepny = NULL;
		ostatni = temp;
	}
}

void lista::usun_poczatek() {
	if (pierwszy == ostatni) {
		pierwszy = NULL;
		ostatni = NULL;
	}
	else {
		modul* temp = pierwszy;
		pierwszy = pierwszy->nastepny;
		delete temp;
	}
}

void lista::wyswietl_liste() {
	modul* temp = pierwszy;

	if (pierwszy == NULL) {
		printf("%c", PUSTE);
	}
	while (temp){ 
		printf("%c", temp->znak);
		temp = temp->nastepny;
	}
}

void zmiana_miejsca(int* x, int* y, char strona, int wysokosc, int szerokosc) {
	
	if (strona == GORA) {
		if ((*y) == 0) {
			(*y) = wysokosc - 1;
		}
		else {
			(*y)--;
		}
	}
	else if (strona == DOL) {
		if ((*y) == wysokosc - 1) {
			(*y) = 0;
		}
		else {
			(*y)++;
		}
	}
	else if (strona == PRAWO) {
		if ((*x) == szerokosc - 1) {
			(*x) = 0;
		}
		else {
			(*x)++;
		}
	}
	else if (strona == LEWO) {
		if ((*x) == 0) {
			(*x) = szerokosc - 1;
		}
		else {
			(*x)--;
		}
	}
	
}

void cofnij_miejsce(int* x, int* y, char strona, int wysokosc, int szerokosc) {
	
	if (strona == GORA) {
		if ((*y) == wysokosc - 1) {
			(*y) = 0;
		}
		else {
			(*y)++;
		}
	}
	else if (strona == DOL) {
		if ((*y) == 0) {
			(*y) = wysokosc - 1;
		}
		else {
			(*y)--;
		}
	}
	else if (strona == PRAWO) {
		if ((*x) == 0) {
			(*x) = szerokosc - 1;
		}
		else {
			(*x)--;
		}
	}
	else if (strona == LEWO) {
		if ((*x) == szerokosc - 1) {
			(*x) = 0;
		}
		else {
			(*x)++;
		}
	}
	
}

void akcja(int* x, int* y, char** pole, char* strona, int wysokosc, int szerokosc, lista* catepillar, bool* czy_zyje) {
	if (*czy_zyje) {
		if (pole[*y][*x] == GORA || pole[*y][*x] == DOL || pole[*y][*x] == PRAWO || pole[*y][*x] == LEWO) {
			*strona = pole[*y][*x];
			zmiana_miejsca(x, y, *strona, wysokosc, szerokosc);
		}
		else
		{
			if (pole[*y][*x] >= 65 && pole[*y][*x] <= 90) {
				catepillar->dodaj_koniec(pole[*y][*x] + 32);
				if (pole[*y][*x] == 65) {
					pole[*y][*x] = '$';
					zmiana_miejsca(x, y, *strona, wysokosc, szerokosc);
				}
				else {
					(pole[*y][*x])--;
					zmiana_miejsca(x, y, *strona, wysokosc, szerokosc);
				}
			}
			else if (pole[*y][*x] >= 97 && pole[*y][*x] <= 122) {
				catepillar->dodaj_poczatek(pole[*y][*x]);
				if (pole[*y][*x] == 97) {
					pole[*y][*x] = '@';
					zmiana_miejsca(x, y, *strona, wysokosc, szerokosc);
				}
				else {
					(pole[*y][*x])--;
					zmiana_miejsca(x, y, *strona, wysokosc, szerokosc);
				}
			}
			else if (pole[*y][*x] == '$') {
				catepillar->usun_koniec();
				if (catepillar->pierwszy == NULL) {
					*czy_zyje = false;
				}
				zmiana_miejsca(x, y, *strona, wysokosc, szerokosc);
			}
			else if (pole[*y][*x] == '@') {
				catepillar->usun_poczatek(); 
				if (catepillar->pierwszy == NULL) {
					*czy_zyje = false;
				}
				zmiana_miejsca(x, y, *strona, wysokosc, szerokosc);
			}
			else if (pole[*y][*x] == PUSTE) {
				zmiana_miejsca(x, y, *strona, wysokosc, szerokosc);
			}
		}
	}
}


int main()
{
	lista* list = new lista;
	int m, n, c, x, y, d;

	scanf("%d%d%d%d%d%d", &n, &m, &c, &x, &y, &d);


	for (int i = 0; i < d; i++) {
		char znak;
		scanf(" %c", &znak);
		list->dodaj_koniec(znak);
	}

	char** pole = new char*[m];
	for (int i = 0; i < m; i++) {
		pole[i] = new char[n];
		for (int j = 0; j < n; j++) {
			scanf(" %c", &(pole[i][j]));
		}
	}

	y--; x--;

	char strona = PRAWO;
	bool czy_zyje = true;
	for (int i = 0; i < c; i++) {
		akcja(&x, &y, pole, &strona, m, n, list, &czy_zyje);
	}
	
	cofnij_miejsce(&x, &y, strona, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (pole[i][j] == '$') {
				pole[i][j] = '@';
			}
		}
	}
	x++;
	y++;

	printf("%d", x);
	printf(" ");
	printf("%d", y);
	printf(" ");

	list->wyswietl_liste();

	printf("\n");

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", pole[i][j]);
		}
	
			printf("\n");
	}

	
    return 0;
}

