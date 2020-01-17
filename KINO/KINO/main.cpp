#include <iostream>
#include <random>
#include <chrono>
#include "Sit.h"
#include "Movie.h"
#include "Cinema.h"

using namespace std;

void choose() {
	cout << "Pick option number: ";
}

void menu() {
	cout << "\n      * * * * * Welcome to cinema electronic ticket system * * * * *      \n\n";
	cout << "What do you want to do? Choose your option. \n";
	cout << " 1. Book a sit.\n";
	cout << " 2. Cancel your booking.\n";
	cout << " 3. Check your booking.\n";
	cout << " 4. **W REMONCIE JESZCZE**\n";
	cout << " 5. Admin panel.\n";
	cout << " 6. Close the app.\n";
	choose();
}

void admin_menu() {
	cout << "\n      * * * * * Welcome to cinema electronic ticket system * * * * *      \n\n";
	cout << "What do you want to do master? Choose your option. \n";
	cout << " 1. Add a new film.\n";
	cout << " 2. Delete a film.\n";
	cout << " 3. **W REMONCIE JESZCZE**\n";
	cout << " 4. Close admin panel.\n";
	choose();
}



int main() {
	Sit booking;
	Movie* movie = new Movie;
	Cinema* cinema = new Cinema;
	cinema->addFilm();
	cinema->addFilm();
	cinema->addFilm();
	int answer = 0;
	int answer2 = 0;

	do {
		menu();
		cin >> answer;
		if (answer == 1)
		{
			cinema->showListOfFilms();
			cinema->pickYourFilm();
			system("pause");
		}
		else if (answer == 2)
		{
			cinema->showListOfFilms();
			cinema->cancelYourFilm();
			system("pause");
		}
		else if (answer == 3) movie->checkBooking();
		else if (answer == 4) movie->showCinemaHall();
		else if (answer == 5)
		{
			do {
				admin_menu();
				cin >> answer2;
				if (answer2 == 1)
				{
					cinema->addFilm();
					system("pause");
				}
				else if (answer2 == 2)
				{
					cinema->deleteFilm();
					system("pause");
				}
				else if (answer2 == 3)
				{
					system("pause");
				}
			} while (answer2 != 4); cout << "Try again, I do not know such an option.\n";
		}
		else if (answer != 6) cout << "Try again, I do not know such an option.\n";
	} while (answer != 6);

	delete movie;
	delete cinema;

	return 0;
}
