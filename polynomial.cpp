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
//new �r i heap och dynamiskt.
Polynomial::Polynomial(const int n, const double arr[])
	: degree{ n }, coefficient{ new double[n + 1] }
{

	for (int i = 0; i <= n; i++) {
		coefficient[i] = arr[i];
	}
	//delete[] coefficient;
	//coefficient = nullptr;
}


//Denna g�r att vi ej beh�ver 3st additionsoperatorer utan den konverterar v�r dubbel till ett polynom
//Vi m�ste konvertera double till ett polynom f�r att kunna addera ihop double med polynom. D� m�ste b�da vara polynom
//Double �r polynom av grad 0
//new double[1]{d} Ny array med 1 slot och initializerar den slotten med d
Polynomial::Polynomial(double d)
	: degree{ 0 }, coefficient{ new double[1]{d} }
{

}


//s�tter graden till 0
//raderar arrayn som coefficient pekar p� 
//s�tter pekaren till null
Polynomial::~Polynomial() {

	// degree = 0; // beh�vs ej nollst�lla, tar inte bort n�got minne
	delete[] coefficient;
	coefficient = nullptr;
}


//copy constructor
// ska inte retuernera n�got
Polynomial::Polynomial(const Polynomial& p) :
	degree{ p.degree }, coefficient{ new double[p.degree + 1]{0.0} }
{
	double slots = degree+1;

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

		if (i == 0){
			os << std::fixed << std::setprecision(2) << coefficient[i];
		}
		else {

			if (coefficient[i] != 0) 
				os << " + " << std::fixed << std::setprecision(2) << coefficient[i] << " * X^" << i;
			}
		}

	}






//vi �r i this
//Detta �r assignment
//anv�nd copy konstructor
//swapa adresser, Lecture 5, slide 27
// vi �r referensen �r this (polynom) f�r att �ndra dess egenskaper
// inte refrens i det vi f�r in i argumentet, det ska vi inte �ndra
Polynomial Polynomial::operator=(Polynomial P) {

	std::swap(degree, P.degree);
	std::swap(coefficient, P.coefficient);

	return *this;
}



////
//3st additationsoperatorer f�r vi ska addera 2polynom med varandra, en double med polynom samt en polynom med en double.
//	Polynomial& Polynomial::operator+(const Polynomial P) const {
//	
//	//hur funcar dynamic alocated array. Beh�ver vi inte oroa oss f�r att hamna out of bounderies?? V�xer den automatiskt?? Var 
//
//	//vi �r i this och vi f�r in P
//	//vi vill j�mf�ra degrees av polynom och ta den som �r st�rrst och antingen skapa en ny eller �ndra i den vi har.
//	  if (this->degree >= P.degree) {
//		  //det �r v�r temp som inte funkar
//		  Polynomial temp = this*;
//		  //std::cout << temp;
//
//		  //anv�nd dens degree och array
//		  for (int i = 0; i <= P.degree; i++) {
//
//			temp.coefficient[i] = this->coefficient[i] + P.coefficient[i];
//		  }
//
//		  return temp;
//	 }
//	 // this->degree < P.degree
//	  else {
//		  //anv�n P.degrees array
//		  Polynomial temp = Polynomial(P);
//		  for (int i = 0; i <= this->degree; i++) {
//
//			 temp.coefficient[i] = this->coefficient[i] + P.coefficient[i];;
//		  }
//		  return temp;
//	  }
//
//}


	Polynomial operator+(const Polynomial lhs, const Polynomial rhs) {

		//hur funcar dynamic alocated array. Beh�ver vi inte oroa oss f�r att hamna out of bounderies?? V�xer den automatiskt?? Var 

		//vi �r i this och vi f�r in P
		//vi vill j�mf�ra degrees av polynom och ta den som �r st�rrst och antingen skapa en ny eller �ndra i den vi har.
		if (lhs.degree > rhs.degree || lhs.degree == rhs.degree) {
			Polynomial temp = Polynomial (lhs);
			//anv�nd dens degree och array
			for (int i = 0; i <= rhs.degree; i++) {

				temp.coefficient[i] = lhs.coefficient[i] + rhs.coefficient[i];
			}

			return temp;
		}
		// this->degree < P.degree
		else {
			//anv�n P.degrees array
			Polynomial temp = rhs;
			for (int i = 0; i <= lhs.degree; i++) {

				temp.coefficient[i] = lhs.coefficient[i] + rhs.coefficient[i];;
			}
			return temp;
		}

	}

//Denna �r f�r v�nster sida och den vill vi kunna �ndra p� .
double& Polynomial::operator[](int i) {

	return this->coefficient[i];
}


//Den �r p� h�ger sida av en tilldelningssats i huvudprogrammet. Datorn g�r in och h�mtar v�rdet till den adressen vi har lagt ut.
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



