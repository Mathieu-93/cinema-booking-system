#include <iostream>
#include <random>
#include <string>
#include "Sit.h"

Sit::Sit(int row1, int number1, bool booked1) {
	this->row = row1;
	this->number = number1;
	this->booked = booked1;
}

void Sit::setBooking(bool temp) {
	this->booked = temp;
}

bool Sit::isBooked() {
	return this->booked;
}

void Sit::book() {
	std::string name, surname;
	if (this->booked) {
		std::string taken = "This sit is taken. Please try again\n";
		throw taken;
	}
	std::cout << "Your name (or a first letter of your name): ";
	try {
		setName();
	}
	catch (std::string wrongName) {
		std::cout << "Name has to be alphabetic, please try to book again" << std::endl;
		throw wrongName;
	}
	std::cout << "Your surname (or a first letter of your surname): ";
	try {
		setSurname();
	}
	catch (std::string wrongSurname) {
		std::cout << "Surname has to be alphabetic, please try to book again" << std::endl;
		throw wrongSurname;
	}
	setBooking(true);
}

void Sit::cancel() {
	if (this->booked) {
		Client();
		setBooking(false);
		rndCode = "";
	}
}

void Sit::show() {
	if (isBooked()) {
		std::cout << "\nSit number " << this->number << " in a row " << this->row << " is booked for ";
		(((Client)(*this))).show();
	}
	else std::cout << "\nSit number " << this->number << " in a row " << this->row << " is available.\n";
}

std::string Sit::generateRandomCode()
{
	std::string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<> dist(0, possible_characters.size() - 1);
	std::string ret = "";
	int max_length = 5;
	for (int i = 0; i < max_length; i++) {
		int random_index = dist(engine); //get index between 0 and possible_characters.size()-1
		ret += possible_characters[random_index];
	}
	return ret;
}

std::string Sit::getRndCode(void) {
	return this -> rndCode;
}