#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Cinema.h"
#include "Movie.h"
#include "Sit.h"
#include "Client.h"


Cinema::Cinema() {}


void Cinema::pickYourFilm()
{
	std::cout << "\n";
	std::cout << "Please, enter the number of the film: \n";
	int it = 0;
	std::cin >> it;
	while (1)
	{
		if (it < listOfFilms.size())
		{
			listOfFilms[it - 1].addBooking();
			break;
		}
		else
			std::cout << "Wrong number! \n";
	}
}

void Cinema::cancelYourFilm() {
	std::cout << "\n";
	std::cout << "Please, enter the number of the film that u want to cancel the rezervation: \n";
	int it = 0;
	std::cin >> it;
	while (1)
	{
		if (it < listOfFilms.size())
		{
			listOfFilms[it - 1].cancelBooking();
			break;
		}
		else
			std::cout << "Wrong number! \n";
	}

}

void Cinema::addFilm()
{
	std::string name;
	std::cout << "Type name of movie: ";
	std::getline(std::cin, name);
	std::cout << "\n";
	Movie newMovie;
	newMovie.nameOfMovie = name;
	listOfFilms.push_back(newMovie);
}

void Cinema::showListOfFilms()
{
	if (listOfFilms.size() == 0)
	{
		std::cout << "Im sorry, we have not booked any films yet. \n";
	}
	else
	{
		int it2 = 1;
		for (std::vector<Movie>::iterator it = this->listOfFilms.begin(); it != this->listOfFilms.end(); it++) {
			std::cout << "Film " << it2 << " :";
			it->showMovie();
			std::cout << "\n";
			it2++;
		}
	}
}