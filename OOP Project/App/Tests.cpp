#include <iostream>
#include <assert.h>
#include "Tests.h"
#include "Car.h"
#include "Electric.h"
#include "Diesel.h"
#include "Repository.h"
#include "Controller.h"
#include <cassert>

void TestAll()
{
	Repository r;
	
	Diesel c1("Audi", 2001, 7.800, "Blue", 210, 30);
	Electric c2("Tesla", 2017, 21.900, "White", 200, 150);

	assert(r.getSize() == 0);
	r.add(c1);
	assert(r.getSize() == 1);
	r.add(c2);
	assert(r.getSize() == 2);
	r.deleteElem(0);
	assert(r.getSize() == 1);
	r.undoDelete();
	assert(r.getSize() == 2);
	r.add(c1);
	r.undoAdd();
	assert(r.getSize() == 2);
	r.redoAdd();
	assert(r.getSize() == 3);
	r.deleteElem(0);
	r.undoDelete();
	r.redoDelete();
	assert(r.getSize() == 2);
}
