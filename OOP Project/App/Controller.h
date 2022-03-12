#pragma once
#include <iostream>
#include "Repository.h"
#include <string>

class Controller
{
private:
	Repository* repo;

public:
	Controller();
	~Controller();

	void addDiesel(string b, int y, float pr, string c, int hp, int tank_size);
	void addElectric(string b, int y, float pr, string c, int kw, int a);
	void getAll();

	void undoDel();
	void redoDel();
	void undoAdd();
	void redoAdd();
	void displayBr(string brand);
	void displayOld(int year);
	void deleteElement(int p);
	void Load();
	void Save();
};

