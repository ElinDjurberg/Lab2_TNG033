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
//new är i heap och dynamiskt.
Polynomial::Polynomial(const int n, const double arr[])
	: degree{ n }, coefficient{ new double[n + 1] }
{

	for (int i = 0; i <= n; i++) {
		coefficient[i] = arr[i];
	}
	//delete[] coefficient;
	//coefficient = nullptr;
}


//Denna gör att vi ej behöver 3st additionsoperatorer utan den konverterar vår dubbel till ett polynom
//Vi måste konvertera double till ett polynom för att kunna addera ihop double med polynom. Då måste båda vara polynom
//Double är polynom av grad 0
//new double[1]{d} Ny array med 1 slot och initializerar den slotten med d
Polynomial::Polynomial(double d)
	: degree{ 0 }, coefficient{ new double[1]{d} }
{

}


//sätter graden till 0
//raderar arrayn som coefficient pekar på 
//sätter pekaren till null
Polynomial::~Polynomial() {

	// degree = 0; // behövs ej nollställa, tar inte bort något minne
	delete[] coefficient;
	coefficient = nullptr;
}


//copy constructor
// ska inte retuernera något
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

	//Vi måste ha << tecken istället för = och + när vi använder os.
	//vi är i polynomet och behöver därför ej skriva this för att komma åt degree och coefficient
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






//vi är i this
//Detta är assignment
//använd copy konstructor
//swapa adresser, Lecture 5, slide 27
// vi är referensen ör this (polynom) för att ändra dess egenskaper
// inte refrens i det vi får in i argumentet, det ska vi inte ändra
Polynomial Polynomial::operator=(Polynomial P) {

	std::swap(degree, P.degree);
	std::swap(coefficient, P.coefficient);

	return *this;
}



////
//3st additationsoperatorer för vi ska addera 2polynom med varandra, en double med polynom samt en polynom med en double.
//	Polynomial& Polynomial::operator+(const Polynomial P) const {
//	
//	//hur funcar dynamic alocated array. Behöver vi inte oroa oss för att hamna out of bounderies?? Växer den automatiskt?? Var 
//
//	//vi är i this och vi får in P
//	//vi vill jämföra degrees av polynom och ta den som är störrst och antingen skapa en ny eller ändra i den vi har.
//	  if (this->degree >= P.degree) {
//		  //det är vår temp som inte funkar
//		  Polynomial temp = this*;
//		  //std::cout << temp;
//
//		  //använd dens degree och array
//		  for (int i = 0; i <= P.degree; i++) {
//
//			temp.coefficient[i] = this->coefficient[i] + P.coefficient[i];
//		  }
//
//		  return temp;
//	 }
//	 // this->degree < P.degree
//	  else {
//		  //använ P.degrees array
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

		//hur funcar dynamic alocated array. Behöver vi inte oroa oss för att hamna out of bounderies?? Växer den automatiskt?? Var 

		//vi är i this och vi får in P
		//vi vill jämföra degrees av polynom och ta den som är störrst och antingen skapa en ny eller ändra i den vi har.
		if (lhs.degree > rhs.degree || lhs.degree == rhs.degree) {
			Polynomial temp = Polynomial (lhs);
			//använd dens degree och array
			for (int i = 0; i <= rhs.degree; i++) {

				temp.coefficient[i] = lhs.coefficient[i] + rhs.coefficient[i];
			}

			return temp;
		}
		// this->degree < P.degree
		else {
			//använ P.degrees array
			Polynomial temp = rhs;
			for (int i = 0; i <= lhs.degree; i++) {

				temp.coefficient[i] = lhs.coefficient[i] + rhs.coefficient[i];;
			}
			return temp;
		}

	}

//Denna är för vänster sida och den vill vi kunna ändra på .
double& Polynomial::operator[](int i) {

	return this->coefficient[i];
}


//Den är på höger sida av en tilldelningssats i huvudprogrammet. Datorn går in och hämtar värdet till den adressen vi har lagt ut.
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



