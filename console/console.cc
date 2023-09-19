#include <iostream>
#include "polynom/polynom.h"

using namespace pol;
using namespace std;


int main() {

	Polynom<int> a(7);
	Polynom<int> b(7);
	a.set(2, 0);
	a.set(6, 1);
	a.set(6, 4);
	b.set(2, 1);
	b.set(6, 6);
	cout << a << endl;
	cout << "------------" << endl;
	a.shrink_to_fit();
	cout << a << endl;
	cout << "------------" << endl;
	a.expand(10);
	cout << a;

}