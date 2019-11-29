/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"

//bool Expression::isRoot(const double x) const {
//	return = 0;
//}



std::ostream& operator<<(std::ostream& os, const Expression& a)
{
	//var ska display ligga??
	a.display(os); //dynamic binding occurs	

	return os;
}


//root ska kolla om den är en lösning till functionen
//operator() om den = 0 så är det en root.
//operator() ska kolla vad uttrycket blir
bool Expression::isRoot(const double x) const {

	//double b = operator()(x);
	//kallar vi på den operatorn?

	if (std::abs(x) < EPSILON) {
		return true;
	}
	else {
		return false;
	}

}


//ADD implementation of the member functions for class Expression

