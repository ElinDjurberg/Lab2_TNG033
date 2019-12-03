/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/


#ifndef LOGARITHM_H
#define LOGARITHM_H

#include <iostream>

#include "expression.h"

class Logarithm : public Expression
{
public:
	//Default constructor
	Logarithm();
	Logarithm(const Expression& E, const double c1, const double c2, int B);


	//Destructor
	//~Logarithm();

	Logarithm operator=(Logarithm log);

	//Logarithm(const Expression E, const double C1, const double C2, const int b);
	Logarithm* clone() const override;
	Logarithm(const Logarithm& log);
	
	//ska denna ta in en double?
	virtual double operator()(const double d) const override;
	//virtual double operator()(const Expression E, double d) const override;

protected:
	void display(std::ostream& os) const override;

private:
	double C1 = 0.00;
	double C2 = 0.00;
	int b = 0;
	//Pointer of typ expression that can points to Polynomial and logaritm
	Expression* basclassptr = nullptr;

};

#endif
