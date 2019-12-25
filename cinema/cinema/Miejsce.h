#pragma once
#include <iostream>

using namespace std;

class Miejsce {

public:
	char imie[20]; // sk³adniki klasy
	char nazwisko[20];
	int numer;
	bool zarezerwowane;

	Miejsce();

	Miejsce(char t_imie[], char t_nazwisko[], int t_numer, bool t_zarezerwowane);

	void rezerwuj();
	void anuluj_rezerwacje();
	void wypisz();
	bool jestZarezerwowane();

};