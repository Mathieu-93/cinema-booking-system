#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Sit.hpp"
#include "Client.hpp"
#include "Cinema.hpp"

class Movie {
public:
	Movie();
	void showFilms();
	void pickYourfilm(std::string, int&, int&);

private:

};

#endif