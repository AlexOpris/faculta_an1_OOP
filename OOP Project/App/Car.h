#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//main class
class Car 
{
protected:

	string brand;
	int year;
	int price;
	string color;

public:

	Car();
	Car(string b, int y, int pr, string c);
	Car(const Car& other);
	Car& operator=(const Car& other);
	virtual ~Car();

	string getBrand() const;
	void setBrand(string b);
	int getYear() const;
	void setYear(int y);
	int getPrice() const;
	void setPrice(int pr);
	string getColor() const;
	void setColor(string c);
	virtual string toString();

	friend std::ifstream& operator>>(std::ifstream&, Car&);

};

