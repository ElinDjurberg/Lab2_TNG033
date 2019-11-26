/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <cmath>

const double EPSILON = 1.0e-5;


class Expression
{
public:
	// Destructor Man måste ha en destructor
	virtual ~Expression() = default;  // Expression is a polymorphic class

	friend std::ostream& operator<<(std::ostream& os, const Expression& a);

	//vi sätter den till 0 och tvingar subclasserna att implementera denna funktion
	virtual Expression* clone() const = 0;  // polymorphic copying

  //protected är att subclasserna kan komma åt dem men ingen annan.
protected:
	//default constructor, använder datorns egna. Vad händer då? När vi har den som default???
	//behöver ingen constructor för man kan inte göra en egen instance
	//Expression() = default;

	//den ska vara protected för vi vill ej ha den public
	//vi sätter den till 0 för att tvinga de andra subclasserna att initializera denna functionen
	virtual void display(std::ostream& os) const = 0; 

	//Vi har delete här fär att man vill inte kunna jämföra olika expressions
	//delet här betyder INTE att vi deletar i alla subclasser också
	//däremot har vi operator= i subclasserna för vi kan ex jämföra polynomial med polynomial.
	//const är för vi vill ej ändra bara jämföra
	//referenser kan peka neråt i subclasserna
	//man har virtual för att datorn ska förstår att man ska ha det som man pekar på och inte använda de funktioner som den är ifrån. 
	virtual Expression& operator=(const Expression&) = delete;

};


//std::ostream& operator<<(std::ostream& os, const Expression& a){
//	os << a;
//	return os;
//}




#endif
