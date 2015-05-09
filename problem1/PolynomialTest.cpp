#include <iostream>
#include <string>
#include "Polynomial.h"

using namespace std;

void main(void)
{
	Polynomial f1("f1");
	f1.PlusElement(1, -3);
	f1.PlusElement(1, 5);
	f1.PlusElement(1, 5);
	f1.PlusElement(1, 3);
	f1.PlusElement(1, 4);
	f1.PlusElement(1, 0);
	f1.DisplayPolynomial();

	Polynomial f2("f2");

	f2.PlusElement(10, 0);
	f2.PlusElement(10, 1);
	f2.PlusElement(10, 5);
	f2.DisplayPolynomial();

	Polynomial f3("f3");
	f3 = f1 + f2;
	f3.DisplayPolynomial();

	Polynomial f4("f4");
	f4.PlusElement(1, -3);
	f4.PlusElement(1, 5);
	f4.PlusElement(1, 5);
	f4.PlusElement(1, 3);
	f4.PlusElement(1, 4);
	f4.PlusElement(1, 0);
	f4.DisplayPolynomial();

	Polynomial f5("f5");

	f5.PlusElement(10, 0);
	f5.PlusElement(10, 1);
	f5.PlusElement(10, 5);
	f5.DisplayPolynomial();

	Polynomial f6("f6");
	f6 = f4 - f5;
	f6.DisplayPolynomial();

	//Polynomial f7("f7");
	//f7.PlusElement(1, -3);
	//f7.PlusElement(1, 5);
	//f7.PlusElement(1, 5);
	//f7.PlusElement(1, 3);
	//f7.PlusElement(1, 4);
	//f7.PlusElement(1, 0);
	//f7.DisplayPolynomial();

	//Polynomial f8("f8");
	//f8.PlusElement(10, 0);
	//f8.PlusElement(10, 1);
	//f8.PlusElement(10, 5);
	//f8.PlusElement(10, -3);
	//f8.DisplayPolynomial();

	//Polynomial f9("f9");
	//f9 = f7 * f8;
	//f9.DisplayPolynomial();

	Polynomial f10("f10");
	f10.PlusElement(1, 1);
	f10.PlusElement(1, 0);
	f10.DisplayPolynomial();

	Polynomial f11("f11");
	f11.PlusElement(1, 1);
	f11.PlusElement(-1, 0);
	f11.DisplayPolynomial();

	Polynomial f12("f12");
	f12 = f10 * f11;
	f12.DisplayPolynomial();

	Polynomial f13("f13");
	f13.PlusElement(1, 5);
	f13.PlusElement(1, 4);
	f13.PlusElement(1, 3);
	f13.PlusElement(1, 2);
	f13.PlusElement(1, 1);
	f13.PlusElement(1, 0);
	f13.PlusElement(1, -1);
	f13.PlusElement(1, -2);
	f13.PlusElement(1, -3);
	f13.PlusElement(1, -4);
	//f13.PlusElement(1, -5);
	f13.Derivative();
	f13.DisplayPolynomial();

	cout << "Test" << endl;
	string done;
	cin >> done;

}