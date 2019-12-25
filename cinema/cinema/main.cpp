// cinema.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Film.h"
#include "Miejsce.h"
#include "Kino.h"


using namespace std;

void wyswietl_menu_glowne() // funkcja bez argumentów
{
	cout << "System rezerwacji miejsc - Singlekino.pl" << endl << endl; // tworzymy menu
	cout << "Wybierz opcje:" << endl << endl;
	cout << "1 - Dodaj rezerwacje" << endl;
	cout << "2 - Usun rezerwacje" << endl;
	cout << "3 - Sprawdz miejsce" << endl;
	cout << "4 - Wyswietl wszystkie rezerwacje" << endl;
	cout << "5 - Wyswietl wolne miejsca" << endl;
	cout << "6 - Wyswietl zarezerwowane miejsca" << endl;
	cout << "7 - Zamknij system" << endl;
}

void czekaj_na_klawisz()
{
	cout << endl << "(Wcisnij dowolny przycisk, aby wyjsc)" << endl;
	getchar();
}


int main()
{

	Kino kino;
	char znak; // tu zapiszemy wciśnięty klawisz

			   // dodajmy kilka filmów do bazy
	kino.dodaj_film("film1");
	kino.dodaj_film("film2");
	kino.dodaj_film("film3");
	kino.dodaj_film("film4");
	kino.dodaj_film("film5");

	//kino.wyswietl_wszystkie_miejsca();

	wyswietl_menu_glowne();

	znak = getchar(); // program pobiera znak

	while (znak != '7')
	{

		system("cls");

		switch (znak)
		{
		case '1':
			kino.dodaj_rezerwacje();
			break;
		case '2':
			kino.anuluj_rezerwacje();
			break;
		case '3':
			kino.sprawdz_miejsce();
			break;
		case '4':
			kino.wyswietl_wszystkie_miejsca();
			czekaj_na_klawisz();
			break;
		case '5':
			kino.wyswietl_wolne_miejsca();
			czekaj_na_klawisz();
			break;
		case '6':
			kino.wyswietl_zarezerwowane_miejsca();
			czekaj_na_klawisz();
			break;
		}

		system("cls");
		wyswietl_menu_glowne();
		znak = getchar();// jeszcze raz dokonujemy wyboru

	} // tutaj pętla zawraca i jeszcze raz sprawdza warunek

	return 0;
}