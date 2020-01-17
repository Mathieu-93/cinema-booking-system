#ifndef Movie_h
#define Movie_h

#include <iostream>
#include <string>
#include <vector>
#include "Sit.h"
#include "Client.h"


class Movie : public Sit, Client {
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