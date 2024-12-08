#pragma once
#include <cstdlib>
#include "Operation.h"

class Addition :
    public Operation
{
public:
    Addition(float operande1, float operande2) :Operation(operande1, operande2) {}
    void faireOperation() { setResultat(abs(getOperande1()) + abs(getOperande2())); }
};