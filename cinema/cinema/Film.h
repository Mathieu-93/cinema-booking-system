#pragma once
#ifndef Film

#include <iostream>
#include <string>
#include "Miejsce.h"


using namespace std;

class Film {
private: 
	string m_tytul;
	static const int m_ilosc_miejsc = 30;
	int m_wybrane_miejsce;
	Miejsce wszystkie_miejsca[m_ilosc_miejsc];

public:
	
	Film(string tytul = "", int wybrane_miejsce = 0);
	void wypisz();
	void wybierz_miejsce();
	void wyczysc_miejsce();
	void wyswietl_wszystkie_miejsca();
	void wyswietl_wolne_miejsca();
	void wyswietl_zarezerwowane_miejsca();
	void dodaj_rezerwacje();
	void anuluj_rezerwacje();
	void sprawdz_miejsce();
	void czekaj_na_klawisz();

};

#endif // Film