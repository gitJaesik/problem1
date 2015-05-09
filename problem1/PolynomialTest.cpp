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
	f2.DisplayPolynomial();

	cout << "Test" << endl;
	string done;
	cin >> done;

}