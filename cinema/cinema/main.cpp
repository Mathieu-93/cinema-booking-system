// cinema.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;


class Film
{
private:

	char tytul[100]; // dodajemy prywatną własność tytuł
	static const int ilosc_miejsc = 30; // resza prywatnych własności bez zmin
	int wybrane_miejsce;
	Miejsce wszystkie_miejsca[ilosc_miejsc];

public:
	Film() // konstruktor domyślny
	{
		strcpy(tytul, ""); // uzupełniamy konstruktor domyślny o tytuł
		wybrane_miejsce = 0; // reszta bez zmian
		int i = 0;

		for (i = i; i < ilosc_miejsc; i++)
		{
			wszystkie_miejsca[i] = Miejsce("", "", i + 1, false);
		}
	}

	Film(char t_tytul[]) // przeładowanie konstruktora
	{
		strcpy(tytul, t_tytul); // przypisujemy konkretny tytuł
		wybrane_miejsce = 0; // dalsza część bez zmian
		int i = 0;

		for (i = i; i < ilosc_miejsc; i++)
		{
			wszystkie_miejsca[i] = Miejsce("", "", i + 1, false);
		}
	}

	void wybierz_miejsce() // bez zmian
	{
		cout << "Wybierz numer miejsca (lub 0 aby wyjsc):" << endl << endl;

		cin >> wybrane_miejsce;

		if (wybrane_miejsce < 0 || wybrane_miejsce > ilosc_miejsc)
		{
			if (wybrane_miejsce != 0)
			{
				wybrane_miejsce = 0;
				cout << "Nie ma takiego miejsca" << endl << endl;
			}
		}
	}

	void wyswietl_wszystkie_miejsca() // bez zmian
	{
		int i = 0;

		for (i = i; i < ilosc_miejsc; i++)
		{
			wszystkie_miejsca[i].wypisz();
		}

		cout << endl << "Wszystkich miejsc: " << ilosc_miejsc << endl;
	}

	void wyswietl_wolne_miejsca() // bez zmian
	{
		int i = 0;
		int wolne = 0;

		for (i = i; i < ilosc_miejsc; i++)
		{
			if (!wszystkie_miejsca[i].jestZarezerwowane())
			{
				wszystkie_miejsca[i].wypisz();
				wolne++;
			}
		}

		cout << endl << "Wolnych miejsc: " << wolne << endl;
	}

	void wyswietl_zarezerwowane_miejsca() // bez zmian
	{
		int i = 0;
		int zarezerwowane = 0;

		for (i = i; i < ilosc_miejsc; i++)
		{
			if (wszystkie_miejsca[i].jestZarezerwowane())
			{
				wszystkie_miejsca[i].wypisz();
				zarezerwowane++;
			}
		}

		cout << endl << "Zarezerwowanych miejsc: " << zarezerwowane << endl;
	}

	void dodaj_rezerwacje() // bez zmian
	{
		cout << "Dodaj rezerwacje:" << endl << endl << endl;

		wyswietl_wolne_miejsca();
		wybierz_miejsce();

		if (wybrane_miejsce != 0)
		{
			wszystkie_miejsca[wybrane_miejsce - 1].rezerwuj();
		}

		czekaj_na_klawisz();
	}

	void anuluj_rezerwacje() // bez zmian
	{

		cout << "Anuluj rezerwacje:" << endl << endl << endl;

		wyswietl_zarezerwowane_miejsca();
		wybierz_miejsce();

		if (wybrane_miejsce != 0)
		{
			wszystkie_miejsca[wybrane_miejsce - 1].anuluj_rezerwacje();
		}

		czekaj_na_klawisz();
	}

	void sprawdz_miejsce() // bez zmian
	{
		cout << "Sprawdz rezerwacje:" << endl << endl << endl;
		wybierz_miejsce();

		if (wybrane_miejsce != 0)
		{
			wszystkie_miejsca[wybrane_miejsce - 1].wypisz();
			wyczysc_miejsce();
		}

		czekaj_na_klawisz();
	}
};

