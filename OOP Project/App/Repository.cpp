#include "Repository.h"
#include "Operation.h"

Repository::Repository()
{
	this->p = 1;
	this->pos = 0;
	this->nrElem = 0;
	this->data = new Car[100];
}

Repository::Repository(const Repository& other)
{
	this->pos = other.pos;
	this->nrElem = other.nrElem;
	this->data = new Car[100];
	for (int i = 0; i < 100; i++)
		this->data[i] = other.data[i];
}

Repository Repository::operator=(const Repository& other)
{
	if (this != &other)
	{
		this->pos = other.pos;
		this->nrElem = other.nrElem;
		this->data = new Car[100];
		for (int i = 0; i < 100; i++)
			this->data[i] = other.data[i];
	}
	return Repository();
}

//destructor
Repository::~Repository()
{
	delete[] data;
}

//adds an object to the repository
void Repository::add(Car car)
{
	this->data[this->p] = car;
	this->p++;
	this->nrElem++;
}

//displays all the objects from the repository
void Repository::getAll()
{
	for (int i = 1; i <= this->nrElem; i++)
	{
		cout << "Car number " << i << ": " << this->data[i].toString() << "\n";
	}
}

//returns the number of objects from the repository
int Repository::getSize()
{
	return this->nrElem;
}


void Repository::load()
{
	ifstream load;
	load.open(this->file_name, std::ios::in);
	if (!load.is_open())
		return;
	Car c;
	while (load >> c)
		Repository::add(c);
	load.close();
}

void Repository::save()
{
	unsigned int length = Repository::getSize();
	ofstream file;
	file.open(this->file_name, std::ios::out | std::ios::trunc);
	if (!file.is_open())
		return;
	for (int i = 1; i <= length; i++)
		file << data[i].getBrand() << ',' << data[i].getYear() << ',' << data[i].getPrice() << ',' << data[i].getColor() << '\n';
	file.close();
}


//undose the last delete operation
void Repository::undoDelete()
{
	this->nrElem++;
	for (int i = this->nrElem - 1; i > this->pos; i--)
		this->data[i] = this->data[i - 1];
	this->data[this->pos] = this->removed;
}

//redoes the last undoDelete operation
void Repository::redoDelete()
{
	this->deleteElem(this->pos);
}

//undose the last add operation
void Repository::undoAdd()
{
	this->nrElem--;
}

//redoes the last undoAdd operation
void Repository::redoAdd()
{
	this->nrElem++;
}

//displays all objects older than a given year
void Repository::displayOlder(int year)
{
	int k = 0;
	if (year > 2021 || year < 1800)
		throw "Invalid year, try again:\n";
	for (int i = 1; i <= this->nrElem; i++)
	{
		if (this->data[i].getYear() < year) {
			cout << this->data[i].toString();
			cout << "\n";
			k++;
		}
	}
	if (k == 0)
		cout << "Nothing to show\n";
}

//displays all objects of a given brand
void Repository::displayBrand(string brand)
{
	int k = 0;
	for (int i = 1; i <= this->nrElem; i++)
	{
		if (this->data[i].getBrand() == brand) {
			cout << this->data[i].toString();
			cout << "\n";
			k++;
		}
	}
	if (k == 0)
		cout << "Nothing to show\n";
}

//deletes an object at a given position
void Repository::deleteElem(int poz)
{
	
	if (poz < 0 || poz > this->nrElem)
		throw "Invalid position, try again:\n";
	else
	{
		this->pos = poz;
		this->removed = this->data[poz];
		for (int i = poz; i < this->nrElem; i++)
			this->data[i] = this->data[i + 1];
		this->nrElem--;
	}
	deleted.push(this->removed);
}