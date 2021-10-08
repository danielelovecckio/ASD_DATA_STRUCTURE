/*
 * Linked_list.h
 *
 *  Created on: 21 gen 2021
 *      Author: daniele
 */


#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "Linear_list.h"

template <class T>
class Linked_list;



template <class T>
class Nodo{
	friend class Linked_list<T>;
private :
	T value;
	Nodo<T> * prev;
	Nodo<T> * next;
};



#endif /* LINKED_LIST_H_ */
