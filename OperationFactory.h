#pragma once
#include "Operation.h"

class OperationFactory
{
public:
	Operation* createOperation(char id, float operande1, float operande2) const;

};

