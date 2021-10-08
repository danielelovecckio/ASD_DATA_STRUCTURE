/*
 * Codapt.h
 *
 *  Created on: 6 ott 2020
 *      Author: daniele
 */

#ifndef CODAPT_H_
#define CODAPT_H_

#include <iostream>

using namespace std;
template<class T>
class Codapt;

template<class T>
class Node{
public:
	friend class Codapt<T>;
	Node(){
		next=nullptr;
	}
	Node(Node<T>&n){
		value=n.value;
		next=nullptr;
	}
	 template<class K>
	 friend ostream& operator<<(ostream& os, const Codapt<K>& q);
private:
	Node *next;
	T value;
};

template <class T>
class Codapt{
public:

  Codapt();		//costruttori
  Codapt(const Codapt<T>& q);
  ~Codapt();

  bool empty();
  int size();
  void push(T v);
  void pop();
  T top();
  void print();
  Codapt<T>& operator=(const Codapt<T>&);

   template<class K>
   friend ostream& operator<<(ostream& os, const Codapt<K>& q);

private:
   Node <T>* head;	//testa
   Node <T>* tail;	//coda
   int s;	//dimensione
};

template<class T>
Codapt<T>::Codapt(){
	head=nullptr;
	tail=nullptr;
	s=0;
}

template<class T>
Codapt<T>::Codapt(const Codapt<T>&c){
	head=nullptr;
	tail=nullptr;
	s = 0;

	Node<T> *temp=c.head;
	while(temp!=nullptr){
		push(temp->value);
		temp=temp->next;
	}
}

template <class T>
Codapt<T>::~Codapt(){
  while(!empty())
    pop();
}

template <class T>
bool Codapt<T>::empty(){
  return (head == nullptr);
}

template <class T>
int Codapt<T>::size(){
	return s;
}

template<class T>
void Codapt<T>::push(T v){
	Node<T> *temp = new Node<T>;

	if(empty()){
		head = temp;
		tail = temp;
	}else
		tail->next=temp;

	temp->next=nullptr;
	temp->value=v;
	tail=temp;
	s++;
}


template <class T>
void Codapt<T>::pop(){
  Node<T> *tmp = head;
  head = head->next;
  delete tmp;
  s--;
}

template <class T>
T Codapt<T>::top(){
	return head->value;
}



template <class T>
Codapt<T>& Codapt<T>::operator=(const Codapt<T>&q){

  if (this==&q) return *this;

  while(!empty()){
    pop();
  }
  Node<T>* tmp = q.head;
  while(tmp!=nullptr){
    push(tmp->value);
    tmp=tmp->next;
  }
  return *this;
}

template<class K>
ostream& operator<<(ostream& os, const Codapt<K>& q){

  Node<K>* tmp = q.head;
  int i=0;
  while(tmp!=nullptr){
    os<<i<<" :["<<tmp->value<<"]"<<endl;
    tmp=tmp->next;
    i++;
  }
  return os;
}

#endif /* CODAPT_H_ */
