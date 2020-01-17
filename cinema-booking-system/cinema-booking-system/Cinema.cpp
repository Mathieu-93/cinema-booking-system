#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Cinema.hpp"
#include "Movie.hpp"
#include "Sit.hpp"
#include "Client.hpp"


Cinema::Cinema(){}


void Cinema::pickYourFilm() 
{
	std::cout << "\n";
	std::cout << "Please, enter the number of the film: \n";
	int it = 0;
	std::cin >> it;
	while (1)
	{
		if (it < listOfFilms.size())
			listOfFilms[it - 1].addBooking();
		break;
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
	for (std::vector<Movie>::iterator it = this->listOfFilms.begin(); it != this->listOfFilms.end(); it++) {
		it->showMovie();
		std::cout << "\n";
	}
}