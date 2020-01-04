
#include "stdafx.h"
#include "Kino.h"
#include "Film.h"
#include "Miejsce.h"

#include <string>
#include <iostream>

using namespace std;


Kino::Kino(int wybrany_film, int ilosc_dodanych_filmow) :m_wybrany_film{ wybrany_film }, m_ilosc_dodanych_filmow{ ilosc_dodanych_filmow }{}

void Kino::dodaj_film(string t_tytul)
{
	if (m_ilosc_dodanych_filmow < m_ilosc_filmow)
	{
		wszystkie_filmy[m_ilosc_dodanych_filmow] = Film(t_tytul);
		m_ilosc_dodanych_filmow++;

		cout << "Dodano film " << t_tytul << endl;
	}
	else
	{
		cout << "Maksymalna liczba filmow dodana" << endl;
	}
}

void Kino::wybierz_film()
{
	cout << "Wybierz numer filmu (lub 0 aby wyjsc):" << endl << endl;

	cin >> m_wybrany_film;

	if (m_wybrany_film < 0 || m_wybrany_film > m_ilosc_filmow)
	{
		if (m_wybrany_film != 0) {
			m_wybrany_film = 0;
			cout << "Nie ma takiego filmu" << endl << endl;
		}
	}
}

void Kino::wyswietl_wszystkie_filmy()
{
	int i = 0;

	for (i = i; i < m_ilosc_filmow; i++)
	{
		cout << "Film nr. " << i + 1 << ": ";
		wszystkie_filmy[i].wypisz();
		cout << endl;
	}

	cout << endl << "Wszystkich filmow: " << m_ilosc_filmow << endl;
}

void Kino::wyswietl_wszystkie_miejsca()
{
	int i = 0;

	for (i = i; i < m_ilosc_filmow; i++)
	{
		wszystkie_filmy[i].wypisz();
		wszystkie_filmy[i].wyswietl_wszystkie_miejsca();
	}
}

void Kino::wyswietl_wolne_miejsca()
{
	int i = 0;

	for (i = i; i < m_ilosc_filmow; i++)
	{
		wszystkie_filmy[i].wypisz();
		wszystkie_filmy[i].wyswietl_wolne_miejsca();
	}
}

void Kino::wyswietl_zarezerwowane_miejsca()
{
	int i = 0;

	for (i = i; i < m_ilosc_filmow; i++)
	{
		wszystkie_filmy[i].wypisz();
		wszystkie_filmy[i].wyswietl_zarezerwowane_miejsca();
	}
}

void Kino::dodaj_rezerwacje()
{
	cout << "Dodaj rezerwacje:" << endl << endl << endl;

	wyswietl_wszystkie_filmy();
	wybierz_film();

	if (m_wybrany_film != 0) {
		wszystkie_filmy[m_wybrany_film - 1].dodaj_rezerwacje();
	}
}

void Kino::anuluj_rezerwacje()
{
	cout << "Anuluj rezerwacje:" << endl << endl << endl;

	wyswietl_wszystkie_filmy();
	wybierz_film();

	if (m_wybrany_film != 0)
	{
		wszystkie_filmy[m_wybrany_film - 1].anuluj_rezerwacje();
	}
}

void Kino::sprawdz_miejsce()
{
	cout << "Sprawdz rezerwacje:" << endl << endl << endl;

	wyswietl_wszystkie_filmy();
	wybierz_film();

	if (m_wybrany_film != 0)
	{
		wszystkie_filmy[m_wybrany_film - 1].sprawdz_miejsce();
	}
}