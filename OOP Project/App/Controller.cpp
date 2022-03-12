#include "Controller.h"

Controller::Controller()
{
	this->repo = new Repository();
}

Controller::~Controller()
{
}

void Controller::addDiesel(string b, int y, float pr, string c, int hp, int tank_size)
{
	//adds a diesel car in the repository
	Car diesel = Diesel(b, y, pr, c, hp, tank_size);

	this->repo->add(diesel);
}

void Controller::addElectric(string b, int y, float pr, string c, int kw, int a)
{
	//adds an electric car in the repository
	Car electric = Electric(b, y, pr, c, kw, a);

	this->repo->add(electric);
}

void Controller::getAll()
{
	//returns all objects from the repository
	return this->repo->getAll();
}

//undoes the last delete operation
void Controller::undoDel()
{
	this->repo->undoDelete();
}

//redoes the last undoDelete operation
void Controller::redoDel()
{
	this->repo->redoDelete();
}

//undoes the last add operation
void Controller::undoAdd()
{
	this->repo->undoAdd();
}

//redoes the last undoAdd operation
void Controller::redoAdd()
{
	this->repo->redoAdd();
}

/*
void Controller::load()
{
	string line, brand, year, price, color, a, b;
	ifstream f;
	f.open("load.csv");
	while (getline(f, line, ' '))
	{
		getline(f, year, ',');
		getline(f, year, ',');
		getline(f, price, ',');
		getline(f, color, ',');
		getline(f, a, ',');
		getline(f, b, '\n');
		if (brand == "Tesla" || brand == "Hyundai" || brand == "Honda" || brand == "Polestar")
		{
			Car* electric = new Electric (brand, stoi(year), stof(price), color, stoi(a), stoi(b));
			this->repo->add(electric);
		}
		else
		{
			Car* diesel = new Diesel (brand, stoi(year), stof(price), color, stoi(a), stoi(b));
			this->repo->add(diesel);
		}
	}
}
*/

void Controller::displayBr(string brand)
{
	//displays all objects of a given brand
	this->repo->displayBrand(brand);
}

void Controller::displayOld(int year)
{
	//displays all objects older than a given year
	this->repo->displayOlder(year);
}

void Controller::deleteElement(int p)
{
	//deletes an element from a given position
	this->repo->deleteElem(p);
}

void Controller::Load()
{
	this->repo->load();
}

void Controller::Save()
{
	this->repo->save();
}
