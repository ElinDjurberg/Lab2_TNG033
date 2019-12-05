/******************************************************
 * Test program for the expressions hierarchy         *
 * Author: Aida Nordman                               *
 * TNG033: Lab 2                                      *
 ******************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>  //abs

// using namespace std;

#include "polynomial.h"
#include "logarithm.h"

/**************************************************
 * main(): incremental tests of lab 3             *
 * Do NOT MODIFY                                  *
 **************************************************/

int main() {
    /*****************************************************
     * TEST PHASE 0                                      *
     * Polynomial: constructors and operator<<           *
     *****************************************************/
    std::cout << "TEST PHASE 0\n";

     //coefficients of polynomials
    double v1[4]{2.2, 4.4, 2.0, 5.0};
    double v2[3]{2.2, 4.4, 2.0};

    const Polynomial p1{3, v1};  // create a polynomial of degree 3
    const Polynomial p2{2, v2};  // create a polynomial of degree 2

    std::cout << "p1 = " << p1 << '\n';
    std::cout << "p2 = " << p2 << '\n';

    Polynomial p3{6.6};  // conversion constructor: convert a double to a Polynomial
    Polynomial p4{p1};   // copy constructor

    std::cout << "p3 = " << p3 << '\n';
	std::cout << "p4 = " << p4 << '\n';

    /*****************************************************
     * TEST PHASE 1                                      *
     * Polynomial: operator=                             *
     *****************************************************/
    std::cout << "\nTEST PHASE 1\n";

    p4 = p4;  // self-assignement
    std::cout << "p4 = " << p4 << '\n';

    // coefficients of polynomials
    double v3[3]{-1, 0, 1};
    Polynomial p5{2, v3};

    p3 = p4 = p5;

    std::cout << "p3 = " << p3 << '\n';
    std::cout << "p4 = " << p4 << '\n';
    std::cout << "p5 = " << p5 << '\n';

    /*****************************************************
     * TEST PHASE 2                                      *
     * Polynomial: operator()                            *
     *****************************************************/
    std::cout << "\nTEST PHASE 2\n";

    std::cout << "p5(1) = " << p5(1) << '\n';
    std::cout << "p1(3.3) = " << p1(3.3) << '\n';

    /*****************************************************
     * TEST PHASE 3                                      *
     * Polynomial: isRoot                                *
     *****************************************************/
    std::cout << "\nTEST PHASE 3\n";

    if (p5.isRoot(1)) {
        std::cout << "One is a root of " << p5 << '\n';
    } else {
        std::cout << "One is not root of " << p5 << '\n';
    }

    /*****************************************************
     * TEST PHASE 4                                      *
     * Polynomial: operator[]                            *
     *****************************************************/
    std::cout << "\nTEST PHASE 4\n";

    p4[2] = 8;
    std::cout << "p4 = " << p4 << '\n';

    if (abs(p4[1]) < EPSILON)  // compare a double with zero
    {
        std::cout << "Coefficient 1 of p4 is zero!\n";
    }

    std::cout << "Coefficient zero of p1: " << p1[0] << '\n';



    /*
	p1[2] = 4.4; //this should not compile <-- test
    */

    /*****************************************************
     * TEST PHASE 5                                      *
     * Polynomial: P1+P2                                 *
     *****************************************************/
    std::cout << "\nTEST PHASE 5\n";

    p4 = p1 + p2;
    std::cout << "p4 = " << p4 << '\n' << '\n';

    std::cout << "p1 = " << p1 << '\n';
    std::cout << "p2 = " << p2 << '\n';
    std::cout << "p3 = " << p3 << '\n';
    std::cout << "p1 + p3 + p2 = " << p1 + p3 + p2 << '\n';

    /*****************************************************
     * TEST PHASE 6                                       *
     * Polynomial: const+P and P+const                    *
     ******************************************************/
    std::cout << "\nTEST PHASE 6\n";

	p4 = 2.0 + p4;
	std::cout << "p4 = " << p4 << '\n';

    p4 = 0 + p4 + 3.3;
    std::cout << "p4 = " << p4 << '\n';

    /*****************************************************
     * TEST PHASE 7                                      *
     * Logarithm: constructors and operator<<            *
     *****************************************************/
    std::cout << "\nTEST PHASE 7\n";
	/*
	HÄR BÖRJAR MEMORY LEAKS
	2 LEAKS FINNS HÄR
	*/

    Logarithm l0;  // default constructor
    Logarithm l1{p3 + 2, 2, 3, 10};// andra punkten i instructionen
    Logarithm l2{l1};  // copy constructor

    std::cout << "l0 = " << l0 << '\n';
    std::cout << "l1 = " << l1 << '\n';
    std::cout << "l2 = " << l2 << '\n';

	Expression* e1 = new Polynomial(p4);
	// systemet själv gör minne för pekaren
	// new gör minne på polynomet som e1 ska peka på
	// destructorn körs inte för dessa två
	// destructorn tar inte bort e1, e2
	// destructorn kan inte anropas automatiskt

    Expression* e2 = new Logarithm(l1);
    //*e1 = *e2; //<-- should not compile!!

	// kan inte sätta i expression så destructorn är public, så man når dom, då kommer *e1=*e2 kompilera

	// noll memory leaks, måste göra HÄR, manuellt
	 delete e1;
	 delete e2;

	// man avreferar pekarna
	// ingen tilldelningsoperator som matchar när den ena pekar på polynom
	// och den andra på logarithm
	// expressions tilldelnings är i private
	// 'Expression::operator =': cannot access protected member declared in class 'Expression'

    /*****************************************************
     * TEST PHASE 8                                      *
     * Logarithm: assignment operator                    *
     *****************************************************/
    std::cout << "\nTEST PHASE 8\n";

    Logarithm l3{p4, 1, 1, 2};

    l2 = l0 = l3;

    // test that memory is not shared between expressions
    p4[0] = 2;

    std::cout << "p4 = " << p4 << '\n';
    std::cout << "l0 = " << l0 << '\n';
    std::cout << "l2 = " << l2 << '\n';
    std::cout << "l3 = " << l3 << '\n';

    /*****************************************************
     * TEST PHASE 9                                      *
     * Logarithm: operator()                             *
     *****************************************************/
    std::cout << "\nTEST PHASE 9\n";

    std::cout << "l1(1) = " << l1(1) << '\n';
    std::cout << "l3(1) = " << l3(1) << '\n';

    /*****************************************************
     * TEST PHASE 10                                     *
     * Logarithm: isRoot                                 *
     *****************************************************/
    std::cout << "\nTEST PHASE 10\n";

    const Logarithm l4;

    if (l4.isRoot(1)) {
        std::cout << "One is a root of " << l4 << '\n';
    } else {
        std::cout << "One is not a root of " << l4 << '\n';
    }

    /*****************************************************
     * TEST PHASE 11                                     *
     * Expressions: dynamic binding                      *
     *****************************************************/
    std::cout << "\nTEST PHASE 11\n";

	Polynomial p6{p4};
    Polynomial p7{p2};

    Expression *E[4]{&p6, &l1, &p7, &l0};

    std::cout << "** evaluate " << '\n';
    for (int i = 0; i < 4; i++) {
        std::cout << "(" << *E[i] << ")"
                  << "(1) = " << (*E[i])(1) << '\n';
    }

    std::cout << "\n** isRoot " << '\n';
    for (int i = 0; i < 4; i++) {
        if (E[i]->isRoot(1)) {
            std::cout << "1 is a root of " << *E[i] << '\n';
        } else {
            std::cout << "1 is not a root of " << *E[i] << '\n';
        }
    }

    return 0;
}
