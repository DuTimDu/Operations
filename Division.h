#pragma once
#include "Operation.h"
#include "OperationException.h"
class Division :
    public Operation
{
public:
    Division(float operande1, float operande2) :Operation(operande1, operande2) {}
    void faireOperation() { 
		setResultat(abs(getOperande1()) / abs(getOperande2()));	
    }
};