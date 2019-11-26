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


//ADD implementation of the member functions for class Expression

