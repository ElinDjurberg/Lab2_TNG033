/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

#include "expression.h"


class Polynomial : public Expression
{
public:
	
	//vilken av dom???
	explicit Polynomial(const int i, const double arr[]);

	//explicit Polynomial(const int i, const double arr[])
	//	: degree{ i }, coefficient{ new double[i + 1] }
	//{  }


	Polynomial* clone() const override;

	//default constructors
	Polynomial(double d);

	Polynomial operator=(const Polynomial P);

	Polynomial::copy(const Polynomial R);

//kanske inte behöver protected
protected:
	//varför vill vi ha den här?
	//var är override??

	void display(std::ostream& os) const override;



private:
	int degree = 0;
	//pekare kan vi nå mellan klasserna, pekare kan väl bara peka nedåt . Pekare till en array
	double* coefficient = nullptr;


};


#endif
