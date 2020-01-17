#ifndef Cinema_hpp
#define Cinema_hpp

#include <iostream>
#include <string>
#include <vector>
#include "Sit.h"
#include "Client.h"
#include "Movie.h"

class Cinema : public Movie {
public:
	Cinema();
	void pickYourFilm();
	void cancelYourFilm();
	void showListOfFilms();
	void addFilm();

private:
	std::vector <Movie> listOfFilms;
};

#endif