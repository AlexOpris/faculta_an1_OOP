#pragma once
#include <iostream>
#include "Car.h"
#include <algorithm>

using namespace std;

//subclass of "Car" class
class Electric:public Car 
{
private:
	int kw;
	int autonomy;

public:

	Electric(string b, int y, float pr, string c, int kw, int autonomy);

	virtual ~Electric();

	void setKw(int kw);
	int getKw() const;
	void setAutonomy(int a);
	int getAutonomy() const;

	string toString();

	friend ostream& operator<< (ostream& os, Electric& c);

};

