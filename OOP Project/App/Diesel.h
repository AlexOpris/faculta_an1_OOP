#pragma once
#include <iostream>
#include "Car.h"

using namespace std;

//subclass of "Car" class
class Diesel :public Car
{
protected:
	int horsepower;
	int tank_size;

public:

	Diesel(string b, int y, float pr, string c, int hp, int tank_s);
	
	virtual ~Diesel();

	void setHorsepower(int hp);
	int getHorsepower() const;
	void setTankSize(int ts);
	int getTankSize() const;

	string toString();

	friend ostream& operator<< (ostream& os, Diesel& c);

};

