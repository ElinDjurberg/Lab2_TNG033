/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"

std::ostream& operator<<(std::ostream& os, const Expression& a)
{
	a.display(os); //dynamic binding occurs	

	return os;
}


//root ska kolla om den �r en l�sning till functionen
//operator() om den = 0 s� �r det en root.
//operator() ska kolla vad uttrycket blir
bool Expression::isRoot(const double x) const {

	//double b = operator()(x);
	//kallar vi p� den operatorn?

	if (std::abs(x) < EPSILON) {
		return true;
	}
	else {
		return false;
	}

}


