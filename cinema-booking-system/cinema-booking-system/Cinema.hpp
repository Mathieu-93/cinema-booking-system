#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Sit.hpp"
#include "Client.hpp"
#include "Movie.hpp"

class Cinema : public Movie {
public:
	Cinema();
	void pickYourFilm();
	void showListOfFilms();
	void addFilm();

private:
	int numberOfFilms;
	std::vector <Movie> listOfFilms;
};

#endif