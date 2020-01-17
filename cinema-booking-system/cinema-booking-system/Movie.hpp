#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Sit.hpp"
#include "Client.hpp"


class Movie {
public:
	std::string nameOfMovie;
	Movie();
	void showCinemaHall();
	void pickYourSit(std::string, int&, int&);
	void addBooking();
	void cancelBooking();
	void checkBooking();
	void showListOfViewers();
	void removeFromVector(Client);
	void showMovie();

private:
	static const int rows{ 10 };
	static const int nums{ 20 };


	Sit cinema_hall[rows][nums];
	std::vector <Client> listOfViewers;
};

#endif