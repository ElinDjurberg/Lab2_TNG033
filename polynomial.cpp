/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"


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


//copy constructor
// ska inte retuernera n�got
Polynomial::Polynomial(const Polynomial& p) :
	degree{ p.degree }, coefficient{ new double[p.degree + 1]{0.0} }
{
	double slots = degree + 1;

	for (int i = 0; i < slots; i++) {
		this->coefficient[i] = p.coefficient[i];
	}
}



// klon funktion
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
//anv�nd copy konstructor
//swapa adresser, Lecture 5, slide 27
// vi �r referensen �r this (polynom) f�r att �ndra dess egenskaper
// inte refrens i det vi f�r in i argumentet, det ska vi inte �ndra
Polynomial& Polynomial::operator=(Polynomial P) {
	std::swap(degree, P.degree);
	std::swap(coefficient, P.coefficient);

	return *this;
}



//forts�tt jobba med kolla om den �r r�tt
double& Polynomial::operator[](int i) {

	return this->coefficient[i];
}


//forts�tt jobba med kolla om den �r r�tt
const double& Polynomial::operator[](int i) const {

	return this->coefficient[i];
}

double Polynomial::operator()(const double d) const {

	double sum = 0.0;

	for (int i = 0; i < this->degree + 1; i++) {

		if (i == 0) {
			sum = this->coefficient[i];
		}
		else {
			sum += this->coefficient[i] * (pow(d, i));
		}

	}
	return sum;
}

//root ska kolla om den �r en l�sning till functionen
//operator() om den = 0 s� �r det en root.
//operator() ska kolla vad uttrycket blir
bool Polynomial::isRoot(const double x) const{

	double b = operator()(x);

	if (std::abs(b) < EPSILON) {
		return true;
	}
	else {
		return false;
	}


}


