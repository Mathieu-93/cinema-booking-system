#include "stdafx.h"
#include <iostream>
#include"Miejsce.h"


using namespace std;

Miejsce::Miejsce()
{
	strcpy(imie, "");
	strcpy(nazwisko, "");

	numer = 0;
	zarezerwowane = false;
}

Miejsce::Miejsce(char t_imie[], char t_nazwisko[], int t_numer, bool t_zarezerwowane)
{
	strcpy(imie, t_imie);
	strcpy(nazwisko, t_nazwisko);

	numer = t_numer;
	zarezerwowane = t_zarezerwowane;
}

void Miejsce::rezerwuj()
{
	if (zarezerwowane)
	{
		cout << "Miejsce jest juz zarezerwowane.";
	}
	else
	{
		cout << "Podaj imie: ";
		cin >> imie;

		cout << "Podaj nazwisko: ";
		cin >> nazwisko;

		zarezerwowane = true;

		cout << endl << "Miejsce " << numer << " zostalo zarezerwowane dla: " << imie << " " << nazwisko << ".";
	}
}

void Miejsce::anuluj_rezerwacje()
{
	if (zarezerwowane)
	{
		strcpy(imie, "");
		strcpy(nazwisko, "");

		zarezerwowane = false;
		cout << "Rezerwacja anulowana." << endl;
	}
	else
	{
		cout << "Nie ma takiej rezerwacji." << endl;
	}
}

void Miejsce::wypisz() // funkcja wypisuj¹ca
{
	if (zarezerwowane)
	{
		cout << "Numer: " << numer << ", " << imie << " " << nazwisko << endl;
	}
	else
	{
		cout << "Numer: " << numer << " - miejsce wolne" << endl;
	}
}

bool Miejsce::jestZarezerwowane()
{
	return zarezerwowane;
}