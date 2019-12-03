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

	//destructor. Ska denna kan inte vara default d� vi p� ett st�lle har new vilket betyder att vi m�ste frig�ra heapen.
	~Polynomial();

	// clone funktion
	Polynomial* clone() const override;

	//tillger v�rde
	double& operator[](int i);

	// skriver ut v�rdet
	const double& operator[](int i) const;


	virtual double operator()(const double d) const override;

	//Polynomial& operator+(const Polynomial P) const;

	friend Polynomial operator+(const Polynomial lhs, const Polynomial rhs);

	// assignment
	Polynomial operator=(Polynomial P);

//kanske inte beh�ver protected
protected:
	//varf�r vill vi ha den h�r?
	//var �r override??

	void display(std::ostream& os) const override;



private:
	int degree = 0;
	//pekare kan vi n� mellan klasserna, pekare kan v�l bara peka ned�t . Pekare till en array
	double* coefficient = nullptr;
};


#endif
