/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"

//ADD implementation of the member functions for class Polynomial

//const f�r vi vill ej �ndra arrayn eller graden
//Vi skapar/kopierar �ver till en ny array f�r att skapa polynomet. 
//vi har n+1 f�r att polynom av grad 3 har 4 konstanter,
//vi har <= n f�r att n� upp till slotten
//p(degree, coefficient)
//coefficient �r en pekare som pekar till en array
Polynomial::Polynomial(const int n, const double arr[]) 
	: degree{ n }, coefficient{ new double[n + 1] }
{
 
	for (int i = 0; i <= n; i++) {
		coefficient[i] = arr[i];
	}

}

//Hur funkar denna?????
//Vi m�ste konvertera double till ett polynom f�r att kunna addera ihop double med polynom. D� m�ste b�da vara polynom
//Double �r polynom av grad 0
//new double[1]{d} Ny array med 1 slot och initializerar den slotten med d
Polynomial::Polynomial(double d)
	: degree{ 0 }, coefficient{ new double[1]{d} }
{

}

Polynomial* Polynomial::clone() const {

	Polynomial* p1 = new Polynomial(*this);
	return p1;
}


//obs ej exakt samma vissuella output
void Polynomial::display(std::ostream& os) const {
	//display(os);

	//Vi m�ste ha << tecken ist�llet f�r = och + n�r vi anv�nder os.
	//vi �r i polynomet och beh�ver d�rf�r ej skriva this f�r att komma �t degree och coefficient
	for (int i = 0; i <= degree; i++) {
		
		if (i == 0) {
			os << coefficient[i];
		}
		else if (i == 1) {
			os << " + " << coefficient[i] << "x";
		}
		else {
			os << " + " << coefficient[i] << "x^" << i;
		}
		
	 }

}

//vi �r i this
//m�ste skriva Polynomial Polynomial
//anv�nd kopy konstructor
//swapa adresser
Polynomial Polynomial::operator=(const Polynomial P) {

	//vi vill l�gga ny h�r??
	Polynomial newPolly  = Polynomial(P.degree, P.coefficient);
	return newPolly;
}

//Polynomial copy(const Polynomial R) {
//
//	Polynomial p1{ R., v1 };
//
//	Polynomial newPolynomial = new Polynomial(R.degree, R.c)
//}

Polynomial::copy(const Polynomial R)
	: degree{ R.degree }, coefficient{ new double[degree + 1] }
{
	double arr[]{ 0.0 };
	for (int i = 0; i <= degree; i++) {
		arr[i] = coefficient[i];
	}

}



//root ska kolla om den �r en l�sning till functionen
//operator() om den = 0 s� �r det en root.
//operator() ska kolla vad uttrycket blir