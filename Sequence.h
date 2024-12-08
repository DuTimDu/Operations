#pragma once

#include <list>
#include "Operation.h"

using namespace std;

class Sequence
{
private:
	list<Operation*> operations;

public:
	void ajouterOperation(Operation* operation);
	Operation* recupererOperation();
};

