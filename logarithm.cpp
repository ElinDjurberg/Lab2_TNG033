/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"

Logarithm::Logarithm() :C1{ 0.0 }, C2{ 1.0 }, b{ 2 } {
	//kan vi kalla på andra subclassen polynom??
	
	
	// det här är samma som att nämna dom där uppe: C1{ 0.0 }, C2{ 1.0 }, b{ 2 }
	//C1 = 0.0;
	//C2 = 1.0;
	//b = 2;
	double V[2] = { 0.0, 1.0 };

	basclassptr = new Polynomial{ 1, V };
	
}

//copy constructor
//vi kopierar över allt i log till this(den vi är i), Dock kan v inte ha att de pekar på samma objekt för det blir konstigt när någon blir raderad
//Därför måste vi kopiera det log pekar på därför gör vi log.basclassptr->clone() 
//punkten är för att det är referens och pilen är för att basclassptr är en pekare som ska peka på clone()
Logarithm::Logarithm(const Logarithm& log) : C1{ log.C1 }, C2{ log.C2 }, b{ log.b }, basclassptr{ log.basclassptr->clone() }{
}


Logarithm::~Logarithm() {
	
	/* C1 = 0.00;
	C2 = 0.00;
	b = 0; */
	// detta behövs ej, tar inte bort minne, bara nollställer
	
	//delete[] basclassptr;
	//basclassptr = nullptr;

	delete basclassptr;
	basclassptr = nullptr;
}

// basclassptr = E.clone(); och vad säger Expression()
//vi kan inte ha const för då kan vi inte assigna den 	Expression* e1 = new Polynomial(p4);
//*e1 = *e2; Vaför funkar inte denna
Logarithm::Logarithm(const Expression& E, double c1, double c2, int B) : Expression(), C1{ c1 }, C2{ c2 }, b{ B }
{
	//Denna kallar på den clonfunktionen som expression är alltså om E är en logaritm så kallar den på clone() i logaritm.
	//Det måste vara en pointer för det är enda sättet vi kan nå saker i C++ (kan göra med referens men blir konstigare att skriva)
	//const Expression& E är referens för den kan vara stor
	basclassptr = E.clone();
	//pointer points to clone of E
	//use clone
}

// assignment
Logarithm Logarithm::operator=(Logarithm log) {

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

	if (std::abs(C1) > EPSILON) {
		os << C1 << " + ";
	}

	os << C2 << " * " << "Log_" << b
		<< " ( " << *basclassptr << " ) ";
	//måste lägga till stjärna för att få det att funka
}

// I expression så ville den att vi skulle implementera detta
double Logarithm::operator()(const double d) const {

	//hur ska vi komma åt operator() i polynomial och det ska ju kunna vara en expression också
	//ska vi ha en kopy konstructor också
	//Vi måste ha basclassptr måste kallas -> operator() och då kallar den Expression som sedan kallar rätt beroende på om det är ett polynom eller logaritm
	//Vi kan nå alla som expression har och expression når polynom
	return C1 + C2 * (double)(log(basclassptr->operator()(d)) / log(this->b));

	//return 0;

}



