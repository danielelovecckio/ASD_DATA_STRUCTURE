/*
 * Pilapt.h
 *
 *  Created on: 6 ott 2020
 *      Author: daniele
 */

#ifndef PILAPT_H_
#define PILAPT_H_

#include <iostream>

using namespace std;

template <class T>
class Pilapt;

template<class T>
class Node{

public:
	friend class Pilapt<T>;
	template <class tp>
	friend ostream& operator<<(ostream&, const Pilapt<tp>&);
	Node(){
	    next=nullptr;
	    prev=nullptr;
	}

private:
  Node *next;
  Node *prev;
  T value;
};

template <class T>
class Pilapt{
public :

	//costruttori
	Pilapt();
	Pilapt(const Pilapt<T>&);
	~Pilapt();
	//servizio
	bool empty()const;
	int size()const;
    void push_front(T v);
	void push_back(T v);
	void pop_front();
	void pop_back();
	T top()const;
	T bot()const;
	Pilapt<int> sort(Pilapt<int>);
	void swap(int*,int*);
	void stampa(Pilapt);
	void filtra(Pilapt&,int k);
	Pilapt<T> operator=(const Pilapt<T>&);


	template<class tp>
	friend ostream& operator<<(ostream&, const Pilapt<tp>&);

private:
	  Node <T>* head;	//testa
	  Node <T>* tail;	//coda
	  int s;		//dimensione
};

template<class T>
Pilapt<T>::Pilapt(){
	head=nullptr;
	tail=nullptr;
	s=0;
}


template<class T>
Pilapt<T>::Pilapt(const Pilapt<T>& p){
	head=nullptr;
	tail=nullptr;
	s=0;

	Node<T> *temp= p.head;

	while(temp!=nullptr){
		push_back(temp->value);
		temp=temp->next;
	}

}

template <class T>
Pilapt<T>::~Pilapt(){
  while(!empty()){
    pop_front();
  }
}

template <class T>
bool Pilapt<T>::empty()const{
  return (head == nullptr);
}

template <class T>
int Pilapt<T>::size()const{
  return s;
}

template<class T>
void Pilapt<T>::push_front(T v){
	Node<T> *temp=new Node<T>;
	temp->value=v;

	if(empty()){
		head = temp;
		tail = temp;
	}else{
		head->prev=temp;
		temp->next=head;
		head=temp;
	}
	s++;
}

template<class T>
void Pilapt<T>::push_back(T v){
	Node<T> *temp=new Node<T>;

	temp->value=v;

	if(empty()){
		head=temp;
		tail=temp;
	}else{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
	s++;
}

template <class T>
void Pilapt<T>::pop_front(){
	if(size()==1){
		s--;
		delete head;
		head=nullptr;
		tail=nullptr;
	}else if(!empty()){
		Node<T> *temp=head;
		head->next->prev=nullptr;
		head=head->next;
		delete temp;
		s--;
	}else{
		cout<<"Pila vuota";
	}
}

template <class T>
void Pilapt<T>::pop_back(){
	if(size()==1){
		s--;
		delete head;
		head = nullptr;
		tail = nullptr;
	}else if(!empty()){
		Node<T> *temp = new Node<T>;
		tail->prev->next=temp;
		temp->next->prev=tail;
		tail=temp;
	  s--;
	}else{
		cout<<"Pila vuota";
	}

}


template <class T>
T Pilapt<T>::top()const{
	return head->value;
}

template <class T>
T Pilapt<T>::bot()const{
	return tail->value;
}

template <class T>
Pilapt<T> Pilapt<T>::operator=(const Pilapt<T>& dp){

    if (this==&dp) return *this;
    while(!empty()) pop_back();

    Node<T>*tmp=dp.head;

    while(tmp!=nullptr){
      push_back(tmp->value);
      tmp=tmp->next;
    }

    return *this;
}

template<class tp>
ostream& operator<<(ostream&os, const Pilapt<tp>&q){

  os<<"[ ";
  if (!q.empty()){
    Node<tp>* tmp = q.head;

    while(tmp->next!=nullptr){
      os<<tmp->value<<", ";
      tmp=tmp->next;
    }
    os<<tmp->value;
  }
  os<<"]"<<endl;
  return os;
}

template<class T>
Pilapt<int> Pilapt<T>::sort(Pilapt<int> pila){
	int size = pila.size();
	int array[size];
	int i = 0;

	while(!pila.empty()){
		array[i] = pila.top();
		pila.pop_front();
		i++;
	}

	int posMinimo=0;
	for(int i = 0;i<size;i++){
		posMinimo = i;
		for(int pos=posMinimo;pos<=size;pos++){
			if(array[pos]<array[posMinimo]){
				posMinimo = pos;
			}
		}

		if(posMinimo!=i){
			int temp = 0;
			temp = array[i];
			array[i] = array[posMinimo];
			array[posMinimo] = temp;
		}


	}

	i = 0;
	while(i<size){
		pila.push_front(array[i]);
		i++;
	}

	return pila;

}



template<class T>
void Pilapt<T>::stampa(Pilapt pila){
	int i=0;
	while(!pila.empty()){
		cout<<"il valore "<<i <<" :  "<<pila.top()<<endl;
		pila.pop_front();
		i++;
	}
}



template<class T>
void Pilapt<T>::filtra(Pilapt& pila,int k){
	int size = pila.size();
	int i = 0;
	int array[size];

	while(i<size){
		array[i] = pila.top();
		pila.pop_front();
		i++;
	}

	for(int i =0;i<size;i++){
		if(array[i]<=k)
			pila.push_front(array[i]);
	}
}




#endif /* PILAPT_H_ */
