#include "Electric.h"

//constructor
Electric::Electric(string b, int y, float pr, string c, int kw, int a) :Car(b, y, pr, c)
{
	this->kw = kw;
	this->autonomy = a;
}

Electric::~Electric()
{
}


//getters and setters
void Electric::setKw(int kw)
{
	this->kw = kw;
}

int Electric::getKw() const
{
	return kw;
}

void Electric::setAutonomy(int a)
{
	this->autonomy = a;
}

int Electric::getAutonomy() const
{
	return autonomy;
}

//returns the atributes of an electric car as a string
string Electric::toString()
{
	return ", kw: " + to_string(this->kw) + ", autonomy: " + to_string(this->autonomy) + " km";
}

ostream& operator<<(ostream& os, Electric& c)
{
	os << "Brand: " << c.brand << "year: " << c.year << "price: " << c.price << "color: " << c.color << "kilowatts: " << c.kw << "autonomy: " << c.autonomy << "\n";
	return os;
}
