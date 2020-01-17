/*
	Name: Maciej Czy¿kowski
	Index number: 300198
	Coordinator: mgr Wiktor Kuœmirek
	Project 4: Cinema
*/
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>


class Client {
public:
	Client();
	Client(std::string, std::string);
	void setName();
	void setSurname();
	std::string getName();
	std::string getSurname();
	virtual void show();
	void show(std::string*, std::string*);
	bool operator==(Client c) {
		bool res = ((this->getName() == c.getName()) and (this->getSurname() == c.getSurname()));
		return res;
	}
	friend std::ostream& operator<< (std::ostream& os, const Client& cli);

private:
	std::string name;
	std::string surname;
};


#endif	//CLIENT_H