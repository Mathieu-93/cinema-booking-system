#include <iostream>
#include <regex>
#include "Client.hpp"

std::ostream& operator<< (std::ostream& os, const Client& cli) {
	os << cli.name << " " << cli.surname;
	return  os;
}

Client::Client(std::string N, std::string S) {
	std::string notAlphabetic = "This is not alphabetic string";
	if (!std::regex_match(N, std::regex("^[A-Za-z]+$"))) // Not Alphabetic Name
	{
		throw notAlphabetic;
	}
	if (!std::regex_match(N, std::regex("^[A-Za-z]+$"))) // Not Alphabetic Surname
	{
		throw notAlphabetic;
	}
	name = N;
	surname = S;
}



Client::Client() {
	this->name = "";
	this->surname = "";
}
std::string Client::getName() {
	return this->name;
}

std::string Client::getSurname() {
	return this->surname;
}

void Client::setName() {
	std::string name;
	std::cin >> name;
	std::string notAlphabetic = "This is not alphabetic string";
	if (!std::regex_match(name, std::regex("^[A-Za-z]+$"))) // Not Alphabetic Name
	{
		throw notAlphabetic;
	}

	this->name = name;
}

void Client::setSurname() {
	std::string surname;
	std::cin >> surname;
	std::string notAlphabetic = "This is not alphabetic string";
	if (!std::regex_match(surname, std::regex("^[A-Za-z]+$"))) // Not Alphabetic Name
	{
		throw notAlphabetic;
	}
	this->surname = surname;
}

void Client::show() {
	std::cout << this->name << " " << this->surname;
}

void Client::show(std::string* t1, std::string* t2) { // old function overload, it does not actualy show anything
	*t1 = this->name;
	*t2 = this->surname;
}