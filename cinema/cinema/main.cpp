// cinema.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include "Film.h"
#include "Miejsce.h"
#include "Kino.h"


using namespace std;

void wyswietl_menu()
{
	cout << "System rezerwacji miejsc - KINOKOSMOS" << endl << endl;
	cout << "1 - Zarezerwuj seans" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "2 - Anuluj rezerwacje" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "3 - Sprawdz seans" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "4 - Panel Admina" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "5 - Wyjdz z systemu" << endl;
}

void wyswietl_menu_admin() {
	cout << "Panel admina - KINOKOSMOS" << endl << endl;
	cout << "1 - Dodaj film" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "2 - Sprawdz rezerwacje" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "3 - Wyjdz z panelu admina" << endl;
}
void czekaj_na_klawisz()
{
	cout << endl << "(Wcisnij dowolny przycisk, aby wyjsc)" << endl;
	getchar();
}

bool haslo()
{
	string password = "";
	string correctPassword = "admin";
	bool zwrot;

	unsigned tries = 3;
	char character = ' ';

	do {
		cout << "Enter password: ";
		while ((character = _getch()) != '\r') {
			cout << "*";
			password += character;
		}

		if (password != correctPassword) {
			password = "";
			tries -= 1;
			cout << "\nTries remaining: " << tries << endl;
		}
	} while (tries > 0 && password != correctPassword);

	if (tries == 0) {
		cout << "\nUser blocked!\n";
		zwrot = false;
	}
	else {
		cout << "\nPassword correct!\n";
		zwrot = true;
	}

	return zwrot;
}


int main()
{

	Kino kino;
	Film film;
	char znak, znak2;
	string nazwa_filmu;

	wyswietl_menu();

	cin >> znak; // program pobiera znak

	while (znak != '5')
	{
		switch (znak)
		{
		case '1':
			kino.dodaj_rezerwacje();
			czekaj_na_klawisz();
			break;
		case '2':
			kino.anuluj_rezerwacje();
			czekaj_na_klawisz();
			break;
		case '3':
			kino.sprawdz_miejsce();
			czekaj_na_klawisz();
			break;
		case '4':
		{
			if (haslo())
			{
				wyswietl_menu_admin();
				cin >> znak2;
				while (znak2 != '3')
				{
					switch (znak2)
					{
					case '1':
						cout << "Podaj tytuł filmu: ";
						cin >> nazwa_filmu;
						kino.dodaj_film(nazwa_filmu);
						cout << endl;
						break;
					case '2':

						break;
					}
					wyswietl_menu_admin();
					cin >> znak2;
				}
			}
			else
			{
				break;
			}
		}
		case '5':

			break;
		}
		wyswietl_menu();
		cin >> znak;// jeszcze raz dokonujemy wyboru

	}

		return 0;
	}