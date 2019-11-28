/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <cmath>

constexpr double EPSILON = 1.0e-5;


class Expression
{
public:
	// Destructor Man m�ste ha en destructor
	virtual ~Expression() = default;  // Expression is a polymorphic class

	friend std::ostream& operator<<(std::ostream& os, const Expression& a);

	//vi s�tter den till 0 och tvingar subclasserna att implementera denna funktion
	virtual Expression* clone() const = 0;  // polymorphic copying

	//const double f�r att vi ska ta in en double x men inte �ndra p� den
	//Const = 0 tvingar subclasserna att implementera den.
	virtual double operator()(const double d) const = 0;

	//virtual har vi f�r att datorn ska g� till den funktionen vi pekar p� och ej den vi �r i. �veranv�nd ej virtual dock. 
	virtual bool isRoot(const double x) const = 0;

  //protected �r att subclasserna kan komma �t dem men ingen annan.
protected:
	//default constructor, anv�nder datorns egna. Vad h�nder d�? N�r vi har den som default???
	//beh�ver ingen constructor f�r man kan inte g�ra en egen instance
	//Expression() = default;

	//den ska vara protected f�r vi vill ej ha den public
	//vi s�tter den till 0 f�r att tvinga de andra subclasserna att initializera denna functionen
	virtual void display(std::ostream& os) const = 0; 

	//Vi har delete h�r f�r att man vill inte kunna j�mf�ra olika expressions
	//delet h�r betyder INTE att vi deletar i alla subclasser ocks�
	//d�remot har vi operator= i subclasserna f�r vi kan ex j�mf�ra polynomial med polynomial.
	//const �r f�r vi vill ej �ndra bara j�mf�ra
	//referenser kan peka ner�t i subclasserna
	//man har virtual f�r att datorn ska f�rst�r att man ska ha det som man pekar p� och inte anv�nda de funktioner som den �r ifr�n. 
	virtual Expression& operator=(const Expression&) = delete;

};


//std::ostream& operator<<(std::ostream& os, const Expression& a){
//	os << a;
//	return os;
//}




#endif
