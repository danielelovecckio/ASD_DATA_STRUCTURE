//============================================================================
// Name        : CodaPrior.cpp
// Author      : Daniele
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "CodaP.h"
#include <iostream>
using namespace std;

int main() {
	CodaP<int> cp;
	cp.inserisci(1);
	cp.inserisci(5);
	cp.inserisci(8);
	cp.inserisci(9);
	cp.inserisci(4);
	cp.inserisci(3);
	cout << cp.min() << endl;
	cp.cancellaMin();
	cout << cp.min() << endl;
	cp.cancellaMin();
	cout << cp.min() << endl;
	return 0;
}
