//============================================================================
// Name        : Linked_list.cpp
// Author      : Daniele
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Linked_list.h"
using namespace std;

int main() {

	  Linked_list<int> list1, list2, list3;
	 // Linked_list<int>::position iter;

		int x;

		/* inserting three elements into the list list1 */
		x = 1;
	  list1.insert(x, list1.begin());
		x = 2;
	  list1.insert(x, list1.begin());
		x = 3;
	  list1.insert(x, list1.begin());
		x = 4;
	  list1.insert(x, list1.begin());
	  	x = 5;
	 list1.insert(x, list1.begin());
	  	x = 6;
	 list1.insert(x, list1.begin());
	  	x = 7;
	 list1.insert(x, list1.begin());
	  	x = 8;
	 list1.insert(x, list1.begin());
	  	x = 9;
	 list1.insert(x, list1.begin());
	  	x = 10;
	 list1.insert(x, list1.begin());
	  	x = 11;
	 list1.insert(x, list1.begin());
	  	x = 12;
	 list1.insert(x, list1.begin());
	  	x = 13;
	 list1.insert(x, list1.begin());
		x = 14;
	 list1.insert(x, list1.begin());

		/* visualizing the list list1 */
		cout << "list1=" ; cout << list1;

		/* assigning the list list1 to the list list2.
		 * Here we are using the operator =
		 */


		list2 = list1;
		/* visualizing the list list2 */
		cout << "After list2=list1, list2="; cout << list2;

		/* comparing for equality the lists list1 and list2 */
		if (list1 == list2)
				cout << "list1 == list2" << endl;
		else
				cout << "list1 != list2" << endl;

		/* erasing the first element from the list list2 */
		list2.erase(list2.begin());
		/* visualizing the list list2 */
		cout << "After erasing the first element, list2="; cout << list2;
		/* comparing for equality the lists list1 and list2 */
		if (list1 == list2)
				cout << "list1 == list2" << endl;
		else
				cout << "list1 != list2" << endl;
		list1.inverti(list1);
		cout << list1 << endl;

		x = 4;
		list3.insert(x,list3.begin());
		x = 5;
		list3.insert(x,list3.begin());
		x = 9;
		list3.insert(x,list3.begin());
		x = 0;
		list3.insert(x,list3.begin());
		x = 18;
		list3.insert(x,list3.begin());
		x = 1;
		list3.insert(x,list3.begin());
		x = 3;
		list3.insert(x,list3.begin());
		x = 0;
		list3.insert(x,list3.begin());
		x = 9;
		list3.insert(x,list3.begin());
		x = 5;
		list3.insert(x,list3.begin());
		x = 4;
		list3.insert(x,list3.begin());
		cout << endl << list3;

		cout << list3.palindromo(list3) << endl;

		cout << list3.freq(list3,9) << endl;;

		list3.remp(list3);
		cout << list3;
		return 0;
}


