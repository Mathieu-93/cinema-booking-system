#ifndef Sit_h
#define Sit_h

#include <iostream>
#include <string>
#include "Client.h"

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

#endif