#pragma once
class Operation
{
private:
	float operande1;
	float operande2;
	float resultat;
	void validerOperande(float operande) const;

public:
	Operation(float operande1, float operande2);
	virtual void faireOperation() = 0;

	float getOperande1() const { return operande1; }
	float getOperande2() const { return operande2; }
	float getResultat() const { return resultat; }


protected:
	void setResultat(float resultat) { this->resultat = resultat; }
};