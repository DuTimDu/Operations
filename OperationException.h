#pragma once

using namespace std;

#include <iostream>
#include <string>

#include <exception>

class OperationException : public exception
{
private:
	string message;
public:
	OperationException(string message);
	inline const string getMessage() const;
	
};


inline OperationException::OperationException(string message)
{
	this->message = message;
}

inline const string OperationException::getMessage() const
{
	return message;
}

class ChargementOperationException : public OperationException {
public:
	// Constructeur prenant un caractère représentant l'opération
	inline explicit ChargementOperationException(char id); 
};

inline ChargementOperationException::ChargementOperationException(char id) : OperationException("Erreur de chargement de l'opération " + id) 
{
}
