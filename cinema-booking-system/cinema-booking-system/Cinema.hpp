/*
	Name: Maciej Czy¿kowski
	Index number: 300198
	Coordinator: mgr Wiktor Kuœmirek
	Project 4: Cinema
*/

#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Sit.hpp"
#include "Client.hpp"

class Cinema {
public:
	Cinema();
	void showCinemaHall();
	void pickYourSit(std::string, int&, int&);
	void addBooking();
	void cancelBooking();
	void checkBooking();
	void showListOfViewers();
	void removeFromVector(Client);

private:
	static const int rows{ 10 };
	static const int nums{ 20 };

	Sit cinema_hall[rows][nums];
	std::vector <Client> listOfViewers;
};

#endif