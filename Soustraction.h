#include <stdexcept>
#include "Operation.h"
#include "OperationException.h"

class Soustraction :
    public Operation
{
public:
    Soustraction(float operande1, float operande2) :Operation(operande1, operande2) {}
    void faireOperation() {
        float resultat = abs(getOperande1()) - abs(getOperande2());
        if (resultat == 0) {
			throw OperationException("Le resultat de la soustraction est de 0");
        }
        setResultat(resultat);
    }
};