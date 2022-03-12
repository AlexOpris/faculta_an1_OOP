#pragma once
#include "Operation.h"
#include <iostream>
#include "Car.h"
#include "Diesel.h"
#include "Electric.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

class Repository
{
private:
	Car* data; 
	int pos, nrElem, p;
	Car removed;
	stack<Car> deleted;
	string file_name;

public:
	Repository();
	Repository(const Repository& other);
	Repository operator=(const Repository& other);
	~Repository();
	void add(Car car);
	void getAll();
	int getSize();

	void undoDelete();
	void redoDelete();
	void undoAdd();
	void redoAdd();
	void displayOlder(int year);
	void displayBrand(string brand);
	void deleteElem(int poz);
	void load();
	void save();
};