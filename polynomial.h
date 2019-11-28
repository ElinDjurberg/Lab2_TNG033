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

	//destructor. Ska denna bara vara default??
	~Polynomial() = default;

	// copy constructor
	Polynomial(const Polynomial& p);

	Polynomial* clone() const override;

	virtual double operator()(const double d) const override;


	//tillger v�rde
	double& operator[](int i);

	// skriver ut v�rdet
	const double& operator[](int i) const;

	//default constructors
	Polynomial(double d);

	virtual bool isRoot(const double x) const override;

	Polynomial& operator=( Polynomial P);

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
