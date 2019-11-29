/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"




//Default constructor
//l0 = 1.00*Log_2( 0.00 + 1.00 * X^1 )

//double param, result;
//param = 5.5;
//result = log(param);

Logarithm::Logarithm() {
	//kan vi kalla på andra subclassen polynom??
	Expression();
}




////Uppgift nr 2.
//Logarithm::Logarithm(Expression E, const double C1, const double C2, const int b)
//	: degree{ n }, coefficient{ new double[n + 1] }
//{
//
//	for (int i = 0; i <= n; i++) {
//		coefficient[i] = arr[i];
////	}
//
//}