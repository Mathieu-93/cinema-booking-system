
#include "stdafx.h"
#include "Kino.h"
#include "Film.h"
#include "Miejsce.h"


Kino::Kino()
{
	wybrany_film = 0;
	ilosc_dodanych_filmow = 0;
}

void Kino:: dodaj_film(char t_tytul[])
{
	if (ilosc_dodanych_filmow<ilosc_filmow)
	{
		wszystkie_filmy[ilosc_dodanych_filmow] = Film(t_tytul);
		ilosc_dodanych_filmow++;

		cout << "Dodano film " << t_tytul << endl;
	}
	else
	{
		cout << "Maksymalna liczba filmow dodana" << endl;
	}
}

void Kino:: wybierz_film()
{
	cout << "Wybierz numer filmu (lub 0 aby wyjsc):" << endl << endl;

	cin >> wybrany_film;

	if (wybrany_film < 0 || wybrany_film > ilosc_filmow)
	{
		if (wybrany_film != 0) {
			wybrany_film = 0;
			cout << "Nie ma takiego filmu" << endl << endl;
		}
	}
}

void Kino:: wyswietl_wszystkie_filmy()
{
	int i = 0;

	for (i = i; i < ilosc_filmow; i++)
	{
		cout << "Film nr. " << i + 1 << ": ";
		wszystkie_filmy[i].wypisz();
		cout << endl;
	}

	cout << endl << "Wszystkich filmow: " << ilosc_filmow << endl;
}

void Kino:: wyswietl_wszystkie_miejsca()
{
	int i = 0;

	for (i = i; i < ilosc_filmow; i++)
	{
		wszystkie_filmy[i].wypisz();
		wszystkie_filmy[i].wyswietl_wszystkie_miejsca();
	}
}

void Kino:: wyswietl_wolne_miejsca()
{
	int i = 0;

	for (i = i; i < ilosc_filmow; i++)
	{
		wszystkie_filmy[i].wypisz();
		wszystkie_filmy[i].wyswietl_wolne_miejsca();
	}
}

void Kino:: wyswietl_zarezerwowane_miejsca()
{
	int i = 0;

	for (i = i; i < ilosc_filmow; i++)
	{
		wszystkie_filmy[i].wypisz();
		wszystkie_filmy[i].wyswietl_zarezerwowane_miejsca();
	}
}

void Kino :: dodaj_rezerwacje()
{
	cout << "Dodaj rezerwacje:" << endl << endl << endl;

	wyswietl_wszystkie_filmy();
	wybierz_film();

	if (wybrany_film != 0) {
		wszystkie_filmy[wybrany_film - 1].dodaj_rezerwacje();
	}
}

void Kino:: anuluj_rezerwacje()
{
	cout << "Anuluj rezerwacje:" << endl << endl << endl;

	wyswietl_wszystkie_filmy();
	wybierz_film();

	if (wybrany_film != 0)
	{
		wszystkie_filmy[wybrany_film - 1].anuluj_rezerwacje();
	}
}

void Kino:: sprawdz_miejsce()
{
	cout << "Sprawdz rezerwacje:" << endl << endl << endl;

	wyswietl_wszystkie_filmy();
	wybierz_film();

	if (wybrany_film != 0)
	{
		wszystkie_filmy[wybrany_film - 1].sprawdz_miejsce();
	}
}