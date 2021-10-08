//============================================================================
// Name        : Pilapt.cpp
// Author      : Daniele
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Pilapt.h"
using namespace std;

int main() {
	Pilapt<int> p,p1;
	p.push_front(23);
	p.push_front(13);
	p.push_front(78);
	p.push_front(99);
	p.push_front(34);
	p.push_front(6);
	//p.push_front(6);
	p.push_front(122);

	p.stampa(p);
	cout<<"--------------------------"<<endl;
	p1=p.sort(p);
	p1.stampa(p1);
	cout<<endl<<"------------------------"<<endl;
	p1.filtra(p1,34);
	p1.stampa(p1);
	//system("pause");
	return 0;
}
