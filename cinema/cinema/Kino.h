#pragma once
#ifndef Kino

#include <iostream>
#include <string>
#include "Film.h"



class Kino {

private:

	static const int m_ilosc_filmow = 5;
	int m_wybrany_film;

	Film wszystkie_filmy[m_ilosc_filmow];
	int m_ilosc_dodanych_filmow;

public:

	Kino(int wybrany_film = 0, int ilosc_dodanych_filmow = 0);
	void dodaj_film(string t_tytul);
	void wybierz_film();
	void wyswietl_wszystkie_filmy();
	void wyswietl_wszystkie_miejsca();
	void wyswietl_wolne_miejsca();
	void wyswietl_zarezerwowane_miejsca();
	void dodaj_rezerwacje();
	void anuluj_rezerwacje();
	void sprawdz_miejsce();
};

#endif // !Kino