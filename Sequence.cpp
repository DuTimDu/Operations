#include "Sequence.h"

void Sequence::ajouterOperation(Operation* operation)
{
	if (operation == nullptr)
	{
		throw nullptr;
	}
	operations.push_back(operation);

}

Operation* Sequence::recupererOperation()
{
	if (operations.empty())
	{
		return nullptr;
	}
	Operation* courante = operations.back();
	operations.pop_back();
	return courante;
}