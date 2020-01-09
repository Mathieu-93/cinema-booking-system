#include "stdafx.h"
#include <iostream>
#include <string>
#include"Miejsce.h"


using namespace std;

Miejsce::Miejsce(string imie, string nazwisko, int numer, bool zarezerwowane) :m_imie{ imie }, m_nazwisko{ nazwisko }, m_numer{ numer }, m_zarezerwowane{ zarezerwowane }{}


void Miejsce::rezerwuj()
{
	if (m_zarezerwowane)
	{
		cout << "Miejsce jest juz zarezerwowane.";
	}
	else
	{
		cout << "Podaj imie: ";
		cin >> m_imie;

		cout << "Podaj nazwisko: ";
		cin >> m_nazwisko;

		m_zarezerwowane = true;

		cout << endl << "Miejsce " << m_numer-1 << " zostalo zarezerwowane dla: " << m_imie << " " << m_nazwisko << ".";
	}
}

void Miejsce::anuluj_rezerwacje()
{
	if (m_zarezerwowane)
	{
		m_imie = "";
		m_nazwisko = "";

		m_zarezerwowane = false;
		cout << "Rezerwacja anulowana." << endl;
	}
	else
	{
		cout << "Nie ma takiej rezerwacji." << endl;
	}
}

void Miejsce::wypisz() // funkcja wypisuj¹ca
{
	if (m_zarezerwowane)
	{
		cout << "Numer: " << m_numer << ", " << m_imie << " " << m_nazwisko << endl;
	}
	else
	{
		cout << "Numer: " << m_numer << " - miejsce wolne" << endl;
	}
}

bool Miejsce::jestZarezerwowane()
{
	return m_zarezerwowane;
}