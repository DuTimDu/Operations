#include "Operation.h"
#include "OperationException.h"

Operation::Operation(float operande1, float operande2)
{
	validerOperande(operande1);
	validerOperande(operande2);

	this->operande1 = operande1;
	this->operande2 = operande2;
	resultat = 0;
}

void Operation::validerOperande(float operande) const
{
	if (operande == 0)
	{
		throw OperationException("Operande invalide!");
	}
}