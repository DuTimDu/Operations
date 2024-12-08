#include "OperationFactory.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "OperationException.h"

Operation* OperationFactory::createOperation(char id, float operande1, float operande2) const
{
    switch (id)
    {
        case '+': return new Addition(operande1, operande2);
        case '-': return new Soustraction(operande1, operande2);
        case '*': return new Multiplication(operande1, operande2);
        case '/': return new Division(operande1, operande2);
		default: throw ChargementOperationException(id);
    }
    return nullptr;
}
