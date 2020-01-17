#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Cinema.hpp"
#include "Movie.hpp"
#include "Sit.hpp"
#include "Client.hpp"


Cinema:Cinema(){}


void Cinema::pickYourFilm() 
{
	std::cout << "List of films: "
	
		for (int i = 0; i < listOfFilms.size(); i++)
		{
			std::cout << "Film: " << i << listOfFilms.begin() + i << "\n";
		}
}

void Cinema::addFilm() 
{
	std::string name;
	std::cout << "Type name of movie: ";
	std::cin >> name;
	std::cout << "\n";
	Movie newMovie(name);
	listOfFilms.push_back(newMovie);
}

void Cinema::showListOfFilms() 
{
	for (std::vector<Movie>::iterator it = this->listOfFilms.begin(); it != this->listOfFilms.end(); it++) {
		it->show();
		std::cout << "\n";
	}
}