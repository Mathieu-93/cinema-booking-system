
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Movie.h"
#include "Sit.h"

Movie::Movie() {
	for (size_t i = 0; i < this->rows; i++)
		for (size_t j = 0; j < this->nums; j++) {
			this->cinema_hall[i][j] = Sit(i + 1, j + 1, false);
		}
}


void Movie::showCinemaHall() {
	std::cout << "   ";
	for (size_t i = 0; i < this->nums; i++) std::cout << std::setw(3) << i + 1;
	std::cout << "\n";
	for (size_t i = 0; i < this->rows; i++) {
		std::cout << std::setw(3) << i + 1;
		for (size_t j = 0; j < this->nums; j++) {
			if (this->cinema_hall[i][j].isBooked()) std::cout << std::setw(3) << "x";
			else std::cout << std::setw(3) << "o";
		}
		std::cout << "\n";
	}
}

void Movie::pickYourSit(std::string comment, int& row, int& num) {
	std::cout << comment << "\n";
	std::cout << "Row: ";
	do {
		std::cin >> row;
		if (row < 0 || row > rows) std::cout << "Try again.\n";
	} while (row < 0 or row > rows);

	std::cout << "Number: ";
	do {
		std::cin >> num;
		if (num < 0 or num > nums) std::cout << "Try again.\n";
	} while (num < 0 or num > nums);
}

void Movie::removeFromVector(Client c) {
	std::vector<Client>::iterator it;
	it = std::find(this->listOfViewers.begin(), this->listOfViewers.end(), c);
	if (it != this->listOfViewers.end())
		this->listOfViewers.erase(it);
	else std::cout << "This sit is available. You cannot cancel this reservation.\n";
}

void Movie::addBooking() {
	int row{ 0 }, num{ 0 };
	showCinemaHall();
	pickYourSit("Where do you want to sit?", row, num);
	try {
		this->cinema_hall[row - 1][num - 1].book();
	}
	catch (std::string takenOrWrongInput) {
		std::cout << takenOrWrongInput << std::endl;
		return;
	}
	this->listOfViewers.push_back(cinema_hall[row - 1][num - 1]);

	std::string randomCode = generateRandomCode();
	cinema_hall[row - 1][num - 1].getRndCode() = randomCode;

	std::cout << "\n Your generated code is: " << randomCode << "\n \n Keep it till you make a check in! \n \n \n";
}

void Movie::cancelBooking() {
	std::string verName, verSur, verCode;
	int row{ 0 }, num{ 0 };
	showCinemaHall();
	pickYourSit("What sit do you want to cancel?", row, num);

	for (int i = 3; i>0 ;i--)
	{
		std::cout << "For verification, please enter your...\n\nName: ";
		std::cin >> verName;
		std::cout << "\nSurname: ";
		std::cin >> verSur;
		std::cout << "\nAnd Your ticket password: ";
		std::cin >> verCode;

		if (verName == cinema_hall[row - 1][num - 1].getName() && verSur == cinema_hall[row - 1][num - 1].getSurname() && verCode == cinema_hall[row - 1][num - 1].getRndCode())
		{
			removeFromVector(this->cinema_hall[row - 1][num - 1]);
			this->cinema_hall[row - 1][num - 1].cancel();

			std::cout << "Your seat has been canceled. \n \n";
			break;
		}
		else
			std::cout << "You have typed the wrong data! There is only " << i-1 << " tries left!\n\n";
	}
}

void Movie::checkBooking() {
	int row{ 0 }, num{ 0 };
	pickYourSit("What sit do you want to check?", row, num);
	this->cinema_hall[row - 1][num - 1].show();
}

void Movie::showListOfViewers() {

	for (std::vector<Client>::iterator it = this->listOfViewers.begin(); it != this->listOfViewers.end(); it++) {
		it->show();
		std::cout << "\n";
	}
}

void Movie::showMovie() {
	std::cout << this->nameOfMovie << "\n";
}

