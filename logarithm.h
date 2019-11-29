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
	//Logarithm(const Expression E, const double C1, const double C2, const int b);
	

protected:

private:
	double C1 = 0.0;
	double C2 = 1.00;
	int b = 2;

};

#endif
