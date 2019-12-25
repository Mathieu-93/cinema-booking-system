#include "stdafx.h"
#include "Film.h"
#include "Miejsce.h"
#include<iostream>
#include<string>

using namespace std;

Film::Film() {
	
	strcpy(tytul, ""); // uzupe³niamy konstruktor domyœlny o tytu³
	wybrane_miejsce = 0; // reszta bez zmian
	int i = 0;

	for (i = i; i < ilosc_miejsc; i++)
	{
		wszystkie_miejsca[i] = Miejsce("", "", i + 1, false);
	}
}

Film::Film(char t_tytul[])
{
	strcpy(tytul, t_tytul); // przypisujemy konkretny tytu³
	wybrane_miejsce = 0; // dalsza czêœæ bez zmian
	int i = 0;

	for (i = i; i < ilosc_miejsc; i++)
	{
		wszystkie_miejsca[i] = Miejsce("", "", i + 1, false);
	}
}

void Film::wybierz_miejsce() {
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

void Film::wyswietl_wszystkie_miejsca() {
	int i = 0;

	for (i = i; i < ilosc_miejsc; i++)
	{
		wszystkie_miejsca[i].wypisz();
	}

	cout << endl << "Wszystkich miejsc: " << ilosc_miejsc << endl;
}

void Film:: wyswietl_wolne_miejsca() // bez zmian
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

void Film:: wyswietl_zarezerwowane_miejsca() // bez zmian
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
void Film:: dodaj_rezerwacje() // bez zmian
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

void Film :: anuluj_rezerwacje() // bez zmian
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
void Film:: sprawdz_miejsce() // bez zmian
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

void Film :: wyczysc_miejsce()
{
	wybrane_miejsce = 0;
}


void Film::czekaj_na_klawisz()
{
	cout << endl << "(Wcisnij dowolny przycisk, aby wyjsc)" << endl;
	getchar();
}


