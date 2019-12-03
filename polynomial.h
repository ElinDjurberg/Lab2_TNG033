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

	//default constructors
	Polynomial(double d);

	//constructor
	explicit Polynomial(const int i, const double arr[]);

	// copy constructor
	Polynomial(const Polynomial& p);

	//destructor. Ska denna kan inte vara default då vi på ett ställe har new vilket betyder att vi måste frigöra heapen.
	~Polynomial();

	// clone funktion
	Polynomial* clone() const override;

	//tillger värde
	double& operator[](int i);

	// skriver ut värdet
	const double& operator[](int i) const;


	virtual double operator()(const double d) const override;

	//Polynomial& operator+(const Polynomial P) const;

	friend Polynomial operator+(const Polynomial lhs, const Polynomial rhs);

	// assignment
	Polynomial operator=(Polynomial P);

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
