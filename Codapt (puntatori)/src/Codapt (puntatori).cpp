//============================================================================
// Name        : Coda.cpp
// Author      : Daniele
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Codapt.h"

#include <iostream>
using namespace std;

int main() {
	Codapt<int> queue;

	//inserting values
	queue.push(1);
	queue.push(2);
	queue.push(6);
	queue.push(6);

	for(int i=0;i<4;i++){
		cout << queue.top() << endl;
		queue.pop();
	}

	Codapt<int> queue1;

	queue1.push(7);
	queue1.push(2);
	queue1.push(9);
	queue1.push(6);

	Codapt<int> queue2(queue1);

	for(int i=0;i<4;i++){
		cout << queue2.top() << endl;
		queue2.pop();
	}
	return 0;
}
