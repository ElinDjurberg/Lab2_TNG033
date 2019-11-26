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

	explicit Polynomial(const int i, const double arr[]);

	// copy constructor
	Polynomial(const Polynomial& p);

	Polynomial* clone() const override;


	//tillger värde
	double& operator[](int i);

	// skriver ut värdet
	const double& operator[](int i) const;

	//default constructors
	Polynomial(double d);

	Polynomial& operator=( Polynomial P);

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
