#include <iostream>
#include <fstream>
#include "Operation.h"
#include "Division.h"
#include "Sequence.h"
#include "OperationFactory.h"
#include "OperationException.h"

/// <summary>
/// Réalisé par :
/// - Timothé DURAND DURT07070400
/// - Gaëtan DARRORT DARG21020300
/// </summary>

using namespace std;

int main()
{
	cout << "Realise par : " << endl;
	cout << "- Timothe DURAND DURT07070400" << endl;
	cout << "- Gaetan DARRORT DARG21020300" << endl;
	// Redirection du flux d'erreur par défaut
	ofstream errorFile("error.log", ios::app);
	if (!errorFile) {
		cerr << "Impossible d'ouvrir le fichier error.log" << endl;
		return 1;
	}
	cerr.rdbuf(errorFile.rdbuf());

	Sequence sequence;
	OperationFactory opFactory;
	char choix = '+';
	float op1, op2;

	// SECTION D'INITIALISATION DES OPERATIONS
	try {
		cout << "Lecture des choix..." << endl;
		cin >> choix >> op1 >> op2;
		while (choix != 'q')
		{
			cout << "(" << choix << "," << op1 << "," << op2 << ")" << endl;
			sequence.ajouterOperation(opFactory.createOperation(choix, op1, op2));
			cout << "Lecture des choix..." << endl;
			cin >> choix >> op1 >> op2;
		}
	}
	catch(OperationException & ceo)
	{
		cerr << ceo.getMessage() << endl;
		cout << ceo.getMessage() << endl;
		abort();
	}

	cout << "FIN DES LECTURES" << endl;


	cout << "DEBUT DES OPERATIONS" << endl;
	Operation* operationCourante = sequence.recupererOperation();
	while (operationCourante != nullptr)
	{
		try
		{
			operationCourante->faireOperation();
			cout << "(" << operationCourante->getOperande1() << ","
			<< operationCourante->getOperande2() << ","
			<< operationCourante->getResultat() << ")" << endl;
			operationCourante = sequence.recupererOperation();
		}
		catch (OperationException& ceo)
		{
			cerr << ceo.getMessage() << endl;
			cout << ceo.getMessage() << endl;
			abort();
		}
	}

	if (operationCourante == nullptr) {
		cout << "Erreur : aucune opération valide disponible (nullptr détecté)." << endl;
	}
	else {
		try {
			operationCourante->faireOperation();
			cout << "(" << operationCourante->getOperande1() << ","
				<< operationCourante->getOperande2() << ","
				<< operationCourante->getResultat() << ")" << endl;
		}
		catch (OperationException& ceo) {
			cerr << ceo.getMessage() << endl;
			cout << ceo.getMessage() << endl;
			abort();


		}
	}

	/*
	* https://stackoverflow.com/questions/1823721/how-to-catch-the-null-pointer-exception
	* There's no such thing as "null pointer exception" in C++. 
	* The only exceptions you can catch, is the exceptions explicitly thrown by throw expressions plus 
	* some standard C++ exceptions thrown intrinsically by standard operator new, dynamic_cast etc). 
	* There are no other exceptions in C++. Dereferencing null pointers, division by zero etc. does not generate exceptions 
	* in C++, it produces undefined behavior. If you want exceptions thrown in cases like that it is your 
	* own responsibility to manually detect these conditions and do throw explicitly. That's how it works in C++.
	*/

	return 0;
}