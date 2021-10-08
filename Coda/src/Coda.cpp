//============================================================================
// Name        : Coda.cpp
// Author      : Daniele
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Coda.h"

#include <iostream>
using namespace std;

int main() {
	Coda<int> queue;

	//inserting values
	queue.push(1);
	queue.push(2);
	queue.push(6);
	queue.push(6);

	for(int i=0;i<3;i++){
		cout << queue.top() << endl;
		queue.pop();
	}
	return 0;
}
