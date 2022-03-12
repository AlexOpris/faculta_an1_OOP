#include "Car.h"
#include <algorithm>

//default constructor
Car::Car()
{
	this->brand = "";
	this->year = 0;
	this->price = 0;
	this->color = "";
}

//constructor
Car::Car(string b, int y, int pr, string c)
{
	this->brand = b;
	this->year = y;
	this->price = pr;
	this->color = c;
}

//replaces a object with another object
Car::Car(const Car& other)
{
	this->brand = other.brand;
	this->color = other.color;
	this->price = other.price;
	this->year = other.year;
}

//assign operator
Car& Car::operator=(const Car& other)
{
	if (this != &other) {
		this->brand = other.brand;
		this->color = other.color;
		this->price = other.price;
		this->year = other.year;
	}
	return *this;
}

//destructor
Car::~Car()
{
}

//getters and setters

string Car::getBrand() const
{
	return brand;
}

void Car::setBrand(string b)
{
	this->brand = b;
}

int Car::getYear() const
{
	return year;
}

void Car::setYear(int y)
{
	this->year = y;
}

int Car::getPrice() const
{
	return price;
}

void Car::setPrice(int pr)
{
	this->price = pr;
}

string Car::getColor() const
{
	return color;
}

void Car::setColor(string c)
{
	this->color = c;
}


//returns the atributes of a car as a string
string Car::toString()
{
	return "\n  Brand: " + this->brand + "\n  Year: " + to_string(this->year) + "\n  Price: " + to_string(this->price) + "\n  Color: " + color;
}

std::ifstream& operator>>(std::ifstream &ifs, Car &c)
{
	char brand[100], color[100];
	int price, year;
	ifs.getline(brand, 100);
	ifs >> year;
	ifs >> price;
	ifs.getline(color, 100);

	c.setBrand(brand);
	c.setColor(color);
	c.setPrice(price);
	c.setYear(year);

	return ifs;
}
