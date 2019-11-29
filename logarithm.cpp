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
// �r detta r�tt 
Logarithm::Logarithm() :C1{ 0.0 }, C2{ 1.0 }, b{ 2 } {
	//kan vi kalla p� andra subclassen polynom??
	//C1 = 0.0;
	//C2 = 1.0;
	//b = 2;
	double V[2] = { 0.0, 1.0 };
	//Skapas i heap obs m�ste radera
	basclassptr = new Polynomial{ 1, V };
	
}

//copy constructor
//Vi m�ste ha en copy constructor 
//vi kopierar �ver allt i log till this(den vi �r i), Dock kan v inte ha att de pekar p� samma objekt f�r det blir konstigt n�r n�gon blir raderad
//D�rf�r m�ste vi kopiera det log pekar p� d�rf�r g�r vi log.basclassptr->clone() 
//punkten �r f�r att det �r referens och pilen �r f�r att basclassptr �r en pekare som ska peka p� clone()
Logarithm::Logarithm(const Logarithm& log) : C1{ log.C1 }, C2{ log.C2 }, b{ log.b }, basclassptr{ log.basclassptr->clone() }{
}

/*
Logarithm::~Logarithm() {

	C1 = 0.00;
	C2 = 0.00;
	b = 0;
	delete[] basclassptr;
	basclassptr = nullptr;

	
}*/

//hur funkar denna?? basclassptr = E.clone(); och vad s�ger Expression()
//vi kan inte ha const f�r d� kan vi inte assigna den 	Expression* e1 = new Polynomial(p4);
//*e1 = *e2; Vaf�r funkar inte denna
Logarithm::Logarithm(const Expression& E, double c1, double c2, int B) : Expression(), C1{ c1 }, C2{ c2 }, b{ B }
{
	//Denna kallar p� den clonfunktionen som expression �r allts� om E �r en logaritm s� kallar den p� clone() i logaritm.
	//Det m�ste vara en pointer f�r det �r enda s�ttet vi kan n� saker i C++ (kan g�ra med referens men blir konstigare att skriva)
	//const Expression& E �r referens f�r den kan vara stor
	basclassptr = E.clone();
	//pointer points to clone of E
	//use clone
}

Logarithm Logarithm::operator=(Logarithm log) {

	//ska den se ut s�h�r??
	//Polynomial temp = Polynomial(P);
	std::swap(C1, log.C1);
	std::swap(C2, log.C2);
	std::swap(b, log.b);
	std::swap(basclassptr, log.basclassptr);

	return *this;
}

Logarithm* Logarithm::clone() const {

	Logarithm* log1 = new Logarithm(*this);
	return log1;
}



void Logarithm::display(std::ostream& os) const {


	os << C1 << " + " << C2 << " * " << "Log_" << b
		<< " ( " << *basclassptr << " ) ";
	//m�ste l�gga till stj�rna f�r att f� det att funka
}

//ska vi verkligen ha denna? I expression s� ville den att vi skulle implementera detta
double Logarithm::operator()(const double d) const {
	//double sylvia = d;
	//double hej = this->b;
	//double nej = log(d);

	//hur ska vi komma �t operator() i polynomial och det ska ju kunna vara en expression ocks�
	//ska vi ha en kopy konstructor ocks�
	//Vi m�ste ha basclassptr m�ste kallas -> operator() och d� kallar den Expression som sedan kallar r�tt beroende p� om det �r ett polynom eller logaritm
	//Vi kan n� alla som expression har och expression n�r polynom
	return C1 + C2 * (double)(log(basclassptr->operator()(d)) / log(this->b));

	//return 0;

}



