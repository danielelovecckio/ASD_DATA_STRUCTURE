//============================================================================
// Name        : Pila.cpp
// Author      : Daniele
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Pila.h"
using namespace std;

int main() {
	Pila<int> pilaInt;
	Pila<char> pilaChar;

	//inserting values
	pilaInt.inPila(12);
	pilaInt.inPila(14);
	pilaInt.inPila(1);
	pilaInt.inPila(17);
	pilaInt.inPila(4);

	//inserting characters
	pilaChar.inPila('c');
	pilaChar.inPila('p');
	pilaChar.inPila('i');
	pilaChar.inPila('l');
	pilaChar.inPila('a');
	pilaChar.inPila('q');

	cout << pilaInt.leggiPila();
	pilaInt.fuoriPila();
	cout << pilaInt.leggiPila();
	pilaInt.fuoriPila();
	cout << pilaInt.leggiPila();
	pilaInt.fuoriPila();
	cout << pilaInt.leggiPila();
	pilaInt.fuoriPila();


	cout << pilaChar.leggiPila();
	pilaChar.fuoriPila();
	cout << pilaChar.leggiPila();
	pilaChar.fuoriPila();
	cout << pilaChar.leggiPila();
	pilaChar.fuoriPila();
	cout << pilaChar.leggiPila();
	pilaChar.fuoriPila();
	cout << pilaChar.leggiPila();
	pilaChar.fuoriPila();

	return 0;
}
