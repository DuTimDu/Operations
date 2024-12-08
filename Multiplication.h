#pragma once
#include "Operation.h"
#include "OperationException.h"

class Multiplication :
    public Operation
{
public:
    Multiplication(float operande1, float operande2) :Operation(operande1, operande2) {}
    void faireOperation() {
        float resultat = abs(getOperande1()) * abs(getOperande2());
        if (resultat > 1000000) {
            throw OperationException("Le resultat de la multiplication est trop eleve");
        }
        setResultat(resultat);
    }
};