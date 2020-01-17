#ifndef SIT_HPP
#define SIT_HPP

#include <iostream>
#include <string>
#include "Client.hpp"

class Sit : public Client
{
public:
	Sit() : row(0), number(0), booked(false) {
		Client();
	}
	Sit(int row, int number, bool booked);

	void book();
	void cancel();
	virtual void show();
	bool isBooked();

private:
	int row;
	int number;
	bool booked;
	void setBooking(bool);
};

#endif	//SIT_H