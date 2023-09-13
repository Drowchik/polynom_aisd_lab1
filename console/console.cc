#include <iostream>
#include "polynom/polynom.h"

using namespace pol;
using namespace std;


int main() {

	Polynom <int> a(5);
	int* c = new int [5] {5, 1, 2, 3, 4};
	Polynom <int> b(c, 5);
	for (int i = 0; i < b.size(); i++) {
		cout << i<< '-'<<b[i] << endl;
	}
	cout << '-' << b[9] << endl;
	cout << "hello world";
	return 0;
}