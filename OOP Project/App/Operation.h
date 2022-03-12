#pragma once
#include "Car.h"

enum OperationType { add };

class Operation
{
	Car* element;
	OperationType opType;

public:
	Operation();
	Operation(Car* element, OperationType type);
	~Operation();
	OperationType getType();
	Car* getElement();
};



