#include <iostream>
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
	}
}

void Sit::show() {
	if (isBooked()) {
		std::cout << "\nSit number " << this->number << " in a row " << this->row << " is booked for ";
		(((Client)(*this))).show();
	}
	else std::cout << "\nSit number " << this->number << " in a row " << this->row << " is available.\n";
}