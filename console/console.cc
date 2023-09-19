#include <iostream>
#include "polynom/polynom.h"

using namespace pol;
using namespace std;


int main() {

	cout << "Check" << endl;
	cout << "------------------" << endl;
	Polynom <int> a(5);
	int array[] = {1,2, 3,4};
	Polynom <int> b (array, 4);
	cout << a << endl;
	cout << b << endl;




	return 0;
}