#pragma once


class Kino {

private:
	static const int ilosc_filmow = 5;
	int wybrany_film;
	Film wszystkie_filmy[ilosc_filmow];
	int ilosc_dodanych_filmow;

public:

	Kino();

	void dodaj_film(char t_tytul[]);
	void wybierz_film();
	void wyswietl_wszystkie_filmy();
	void wyswietl_wszystkie_miejsca();
	void wyswietl_wolne_miejsca();
	void wyswietl_zarezerwowane_miejsca();
	void dodaj_rezerwacje();
	void anuluj_rezerwacje();
	void sprawdz_miejsce();
};