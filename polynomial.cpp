/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"

//ADD implementation of the member functions for class Polynomial

//const för vi vill ej ändra arrayn eller graden
//Vi skapar/kopierar över till en ny array för att skapa polynomet. 
//vi har n+1 för att polynom av grad 3 har 4 konstanter,
//vi har <= n för att nå upp till slotten
//p(degree, coefficient)
//coefficient är en pekare som pekar till en array
Polynomial::Polynomial(const int n, const double arr[]) 
	: degree{ n }, coefficient{ new double[n + 1] }
{
 
	for (int i = 0; i <= n; i++) {
		coefficient[i] = arr[i];
	}

}

//Hur funkar denna?????
//Vi måste konvertera double till ett polynom för att kunna addera ihop double med polynom. Då måste båda vara polynom
//Double är polynom av grad 0
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

	//Vi måste ha << tecken istället för = och + när vi använder os.
	//vi är i polynomet och behöver därför ej skriva this för att komma åt degree och coefficient
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

//vi är i this
//måste skriva Polynomial Polynomial
//använd kopy konstructor
//swapa adresser
Polynomial Polynomial::operator=(const Polynomial P) {

	//vi vill lägga ny här??
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



//root ska kolla om den är en lösning till functionen
//operator() om den = 0 så är det en root.
//operator() ska kolla vad uttrycket blir