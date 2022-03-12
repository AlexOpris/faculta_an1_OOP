#include "Operation.h"


Operation::Operation()
{
}


Operation::Operation(Car* element, OperationType type)
{
	this->element = element;
	this->opType = type;
}

Operation::~Operation()
{
}

OperationType Operation::getType()
{
	return this->opType;
}

Car* Operation::getElement()
{
	return element;
}
