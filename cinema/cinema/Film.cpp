#include "stdafx.h"
#include "Film.h"
#include "Miejsce.h"
#include<iostream>
#include<string>

using namespace std;

Film::Film(string tytul, int wybrane_miejsce) :m_tytul{ tytul }, m_wybrane_miejsce{ wybrane_miejsce }
{
	for (int i = 0; i < m_ilosc_miejsc; i++)
	{
		wszystkie_miejsca[i] = Miejsce("", "", i + 1, false);
	}
}

void Film::wypisz()
{
	cout << endl << "tytul: " << m_tytul << endl;
}

void Film::wybierz_miejsce()
{
	cout << "Wybierz numer miejsca (lub 0 aby wyjsc):" << endl << endl;

	cin >> m_wybrane_miejsce;

	if (m_wybrane_miejsce < 0 || m_wybrane_miejsce > m_ilosc_miejsc)
	{
		if (m_wybrane_miejsce != 0) {

			m_wybrane_miejsce = 0;
			cout << "Nie ma takiego miejsca" << endl << endl;
		}
	}
}

void Film::wyczysc_miejsce()
{
	m_wybrane_miejsce = 0;
}

void Film::wyswietl_wszystkie_miejsca()
{
	int i = 0;
	for (i = i; i < m_ilosc_miejsc; i++)
	{
		wszystkie_miejsca[i].wypisz();
	}

	cout << endl << "Wszystkich miejsc: " << m_ilosc_miejsc << endl;
}

void Film::wyswietl_wszystkie_miejsca2()
{
	int a;
	a = 50;

	cout << "____________________________________________________________________" << endl;
	cout << "|                              EKRAN                               |" << endl;
	cout << "____________________________________________________________________" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


		for (int j = 1; j < a+1; j++)

		{
			cout << " [ ";
			if (wszystkie_miejsca[j].jestZarezerwowane())
			{
				cout << "Z";
			}
			else
			{
				cout << "W";
			}
			cout << " ] ";
			if (j % 10 == 0 && j > 0 && j < 50)
			{
				cout << endl;
				cout << "____________________________________________________________________";
				cout << endl;
			}
		}
		cout << endl;
	}

void Film::wyswietl_wolne_miejsca()
{
	int i = 0;
	int wolne = 0;

	for (i = i; i < m_ilosc_miejsc; i++)
	{
		if (!wszystkie_miejsca[i].jestZarezerwowane())
		{
			wszystkie_miejsca[i].wypisz();
			wolne++;
		}
	}

	cout << endl << "Wolnych miejsc: " << wolne << endl;
}

void Film::wyswietl_zarezerwowane_miejsca()
{
	int i = 0;
	int zarezerwowane = 0;

	for (i = i; i < m_ilosc_miejsc; i++)
	{
		if (wszystkie_miejsca[i].jestZarezerwowane())
		{
			wszystkie_miejsca[i].wypisz();
			zarezerwowane++;
		}
	}

	cout << endl << "Zarezerwowanych miejsc: " << zarezerwowane << endl;
}

void Film::dodaj_rezerwacje()
{
	cout << "Dodaj rezerwacje:" << endl << endl << endl;

	wybierz_miejsce();

	if (m_wybrane_miejsce != 0)
	{
		wszystkie_miejsca[m_wybrane_miejsce - 1].rezerwuj();
	}

	czekaj_na_klawisz();
}

void Film::anuluj_rezerwacje()
{
	cout << "Anuluj rezerwacje:" << endl << endl << endl;
	wyswietl_zarezerwowane_miejsca();
	wybierz_miejsce();

	if (m_wybrane_miejsce != 0)
	{
		wszystkie_miejsca[m_wybrane_miejsce - 1].anuluj_rezerwacje();
	}

	czekaj_na_klawisz();
}

void Film::sprawdz_miejsce()
{
	cout << "Sprawdz rezerwacje:" << endl << endl << endl;
	wybierz_miejsce();

	if (m_wybrane_miejsce != 0)
	{
		wszystkie_miejsca[m_wybrane_miejsce - 1].wypisz();
		wyczysc_miejsce();
	}

	czekaj_na_klawisz();
}

void Film::czekaj_na_klawisz()
{
	cout << endl << "(Wcisnij dowolny przycisk, aby wyjsc)" << endl;
	getchar();
}


