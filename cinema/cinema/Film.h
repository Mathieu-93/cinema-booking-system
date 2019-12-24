#pragma once

#include<iostream>

using namespace std;

class Film {

	char tytul[100]; // dodajemy prywatn¹ w³asnoœæ tytu³
	static const int ilosc_miejsc = 30; // resza prywatnych w³asnoœci bez zmin
	int wybrane_miejsce;
	Miejsce wszystkie_miejsca[ilosc_miejsc];


public:
	Film();
	void wybierz_miejsce();
	void wyswietl_wszystkie_miejsca();
	void wyswietl_wolne_miejsca();
	void wyswietl_zarezerwowane_miejsca();
	void dodaj_rezerwacje();
	void anuluj_rezerwacje();
	void sprawdz_miejsce();

};