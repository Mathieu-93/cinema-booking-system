#ifndef Client_h
#define Client_h

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
		bool res = ((this->getName() == c.getName()) && (this->getSurname() == c.getSurname()));
		return res;
	}
	friend std::ostream& operator<< (std::ostream& os, const Client& cli);

private:
	std::string name;
	std::string surname;
};


#endif