#include "Diesel.h"

//constructor
Diesel::Diesel(string b, int y, float pr, string c, int hp, int tank_s) :Car(b, y, pr, c)
{
	this->horsepower = hp;
	this->tank_size = tank_s;
}


//destructor
Diesel::~Diesel()
{
}

//getters and setters

void Diesel::setHorsepower(int hp)
{
	this->horsepower = hp;
}

int Diesel::getHorsepower() const
{
	return horsepower;
}

void Diesel::setTankSize(int ts)
{
	this->tank_size = ts;
}

int Diesel::getTankSize() const
{
	return tank_size;
}

//returns the atributes of a diesel car as a string
string Diesel::toString()
{
	return Car::toString() + ", horsepower: " + to_string(this->horsepower) + ", tank_size: " + to_string(this->tank_size);
}


ostream& operator<<(ostream& os, Diesel& c)
{
	os << "Brand: " << c.brand << "year: " << c.year << "price: " << c.price << "color: " << c.color << "horsepower: " << c.horsepower << "tank_size: " << c.tank_size << "\n";
	return os;
}