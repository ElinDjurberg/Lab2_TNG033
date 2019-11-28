/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"


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


//copy constructor
// ska inte retuernera något
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
//använd copy konstructor
//swapa adresser, Lecture 5, slide 27
// vi är referensen ör this (polynom) för att ändra dess egenskaper
// inte refrens i det vi får in i argumentet, det ska vi inte ändra
Polynomial& Polynomial::operator=(Polynomial P) {
	std::swap(degree, P.degree);
	std::swap(coefficient, P.coefficient);

	return *this;
}



//fortsätt jobba med kolla om den är rätt
double& Polynomial::operator[](int i) {

	return this->coefficient[i];
}


//fortsätt jobba med kolla om den är rätt
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

//root ska kolla om den är en lösning till functionen
//operator() om den = 0 så är det en root.
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


