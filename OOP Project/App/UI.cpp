#include "UI.h"
#include <iostream>
#include <string>
#include <stack>
#include "Repository.h"


using namespace std;

UI::UI()
{
	this->ctrl = new Controller();
}

UI::~UI()
{
}

//Displays the menu of the application
void UI::showMenu()
{
	cout << "1. Add diesel car\n";
	cout << "2. Add electric car\n";
	cout << "3. Display cars of a specific brand\n";
	cout << "4. Display cars older than year\n";
	cout << "5. Remove car by id\n";
	cout << "6. Undo\n";
	cout << "7. Redo\n";
	cout << "8. Print All\n";
	cout << "0. Exit\n";
	cout << "->";
}

void UI::run()
{
	int op, prev_op = 0;

	this->ctrl->Load();
	//Adds some objects in the repository
	this->ctrl->addDiesel("Audi", 2012, 15500, "red", 165, 40);
	this->ctrl->addElectric("Tesla", 2018, 32700, "green", 255, 350);
	this->ctrl->addDiesel("Opel", 2009, 7500, "blue", 95, 35);
	this->ctrl->addDiesel("Mercedes", 1999, 3700, "black", 125, 42);
	this->ctrl->addElectric("Honda", 2020, 25900, "white", 150, 400);
	this->ctrl->addElectric("Hyundai", 2015, 10250, "blue", 200, 375);
	this->ctrl->addDiesel("Nissan", 2017, 17500, "red", 225, 35);

	this->showMenu();
	
	cin >> op;
	while (op != 0)
	{
		if (op == 1)
		{
			string b;
			int y;
			int pr;
			string c;
			int horsepower;
			int tank_size;				
			Repository copy;

			//introduce the atributes of the new diesel car which is to be added
			cout << "Introduce the brand of the car: ";
			cin >> b;
			cout << "Introduce the year of the car: ";
			cin >> y;
			while (y < 1800 || y>2021) {
				cout << "Invalid year, try again";
				cin >> y;
			}
			cout << "Introduce the price of the car: ";
			cin >> pr;
			while (pr < 0) {
				cout << "Invalid price, try again: ";
				cin >> pr;
			}
			cout << "Introduce the color of the car: ";
			cin >> c;
			cout << "Introduce the horsepower of the car: ";
			cin >> horsepower;
			while (horsepower < 0) {
				cout << "Invalid horsepower, try again: ";
				cin >> horsepower;
			}
			cout << "Introduce the tank size of the car: ";
			cin >> tank_size;
			while (tank_size < 0) {
				cout << "Invalid tank size, try again: ";
				cin >> tank_size;
			}
			
			this->ctrl->addDiesel(b, y, pr, c, horsepower, tank_size);
		}
		else if (op == 2)
		{
			string b;
			int y;
			int pr;
			string c;
			int kw;
			int a;
			//introduce the atributes of the new electric car which is to be added
			cout << "Introduce the brand of the car: ";
			cin >> b;
			cout << "Introduce the year of the car: ";
			cin >> y;
			while (y < 1800 || y>2021) {
				cout << "Invalid year, try again: ";
				cin >> y;
			}
			cout << "Introduce the price of the car: ";
			cin >> pr;
			while (pr < 0) {
				cout << "Invalid price, try again: ";
				cin >> pr;
			}
			cout << "Introduce the color of the car: ";
			cin >> c;
			cout << "Introduce the kilowatts of the car: ";
			cin >> kw;
			while (kw < 0) {
				cout << "Invalid kw, try again: ";
				cin >> kw;
			}
			cout << "Introduce the autonomy of the car: ";
			cin >> a;
			while (a < 0) {
				cout << "Invalid autonomy, try again: ";
				cin >> a;
			}

			this->ctrl->addElectric(b, y, pr, c, kw, a);
		}
		else if (op == 3)
		{
			//Introduce the brand you want to display
			string brand;
			cout << "Introduce brand:\n";
			cin >> brand;
			this->ctrl->displayBr(brand);
		}
		else if (op == 4)
		{
			//Intoduce year of which cars older than will be displayed
			int year;
			cout << "Introduce year:\n";
			cin >> year;
			try {
				this->ctrl->displayOld(year);
			}
			catch (const char* msg) {
				cerr << msg << endl;
			}
		}
		else if (op == 5)
		{
			//Introduce position of the object which will be deleted 
			int poz;
			cout << "Introduce the id of the car you want to delete:\n";
			cin >> poz;
			try {
				this->ctrl->deleteElement(poz);
			}
			catch (const char* msg) {
				cerr << msg << endl;
			}
		}
		else if (op == 6)
		{
			//Undoes the last add or delete operation
			if (prev_op == 5)
			{
				this->ctrl->undoDel();
				prev_op = 10;
			}
			else if (prev_op == 1 || prev_op == 2)
			{
				this->ctrl->undoAdd();
				prev_op = 11;
			}
			else
				cout << "Nothing to do\n";
		
		}
		else if (op == 7)
		{
			//Redoes the last undo of add or delete operation
			if (prev_op == 10)
			{
				this->ctrl->redoDel();
				prev_op = 0;
			}
			else if (prev_op == 11)
			{
				this->ctrl->redoAdd();
				prev_op = 0;
			}
			else
				cout << "Nothing to do\n";
		}
		else if (op == 8)
		{
			//Displays all objects from the repository
			this->ctrl->getAll();
		}
		else
			cout << "Invalid command, try again\n";
		cout << "->";
		if (op == 1 || op == 2 || op == 5)
			prev_op = op;
		cin >> op;
	}
	this->ctrl->Save();
	cout << "Good bye";
}