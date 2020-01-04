#pragma once
#ifndef Miejsce
#include <iostream>
#include <string>




using namespace std;

class Miejsce {

public:
	string m_imie;
	string m_nazwisko;
	int m_numer;
	bool m_zarezerwowane;


	Miejsce(string imie = "", string nazwisko = "", int numer = 0, bool zarezerwowane = false);
	void rezerwuj();
	void anuluj_rezerwacje();
	void wypisz();
	bool jestZarezerwowane();

};

#endif // !Miejsce