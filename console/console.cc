#include <iostream>
#include "polynom/polynom.h"

using namespace pol;
using namespace std;


int main() {

	cout << "Check" << endl;
	cout << "------------------" << endl;
	Polynom <float> a(5);
	a.set(5.2, 1);
	a.set(1.5, 2);
	float array[] = {1.4,2.7, 3.4,4.2};
	Polynom <float> b (array, 4);
	cout << a << endl;
	cout << b << endl;
	cout << "Sum +" << endl;
	cout << "------------------" << endl;
	Polynom <float> c = a + b;
	cout << c << endl;
	cout << "------------------" << endl;
	cout << "Sum +=" << endl;
	cout << "------------------" << endl;
	a += b;
	cout << a << endl;
	cout << "------------------" << endl;
	cout << "Minus -" << endl;
	cout << "------------------" << endl;
	c = a - b;
	cout << c << endl;
	cout << "------------------" << endl;
	cout << "Minus -=" << endl;
	cout << "------------------" << endl;
	a -= c;
	cout << a << endl;
	cout << "------------------" << endl;
	cout << "Operator []" << endl;
	cout << "------------------" << endl;
	cout << a[9] << endl;
	cout << "------------------" << endl;
	cout << "set []" << endl;
	cout << "------------------" << endl;
	a.set(7, 7);
	cout << a << endl;
	cout << "------------------" << endl;
	cout << "expand" << endl;
	cout << "------------------" << endl;
	b.expand(12);
	cout << b << endl;
	cout << "------------------" << endl;
	cout << "shrink_to_fit" << endl;
	cout << "------------------" << endl;
	b.shrink_to_fit();
	cout << b << endl;
	cout << "------------------" << endl;
	cout << "multiply x" << endl;
	cout << "------------------" << endl;
	b = b * 5;
	cout << b << endl;
	cout << "------------------" << endl;
	cout << "multiply x" << endl;
	cout << "------------------" << endl;
	b = 2 * b;
	cout << b << endl;
	cout << "------------------" << endl;

	return 0;
}