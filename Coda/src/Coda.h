/*
 * coda.h
 *
 *  Created on: 5 ott 2020
 *      Author: daniele
 */

#ifndef CODA_H_
#define CODA_H_
#include <iostream>
#define STANDARDSIZE 10;

using namespace std;

template <class Elemento>
class Coda{
public :
	Coda(int);
	Coda();
	Coda(const Coda<Elemento>&);
	~Coda();

	void create();
	bool empty();
	Elemento top();	//visualizza l'elemento pop
	void pop();		//elimina l'elemento inserito per ultimo
	void push(Elemento a);
	Coda<Elemento>& operator = (const Coda<Elemento>&);

	 template<class tp>
	 friend ostream& operator<<(ostream&, const Coda<tp>&);

private :

	  Elemento *elems;
	  int head, length, maxlength;

};

template <class Elemento>
Coda<Elemento>::Coda(int n){
	maxlength=n;
	create();
}

template <class Elemento>
Coda<Elemento>::~Coda(){
	delete[] elems;
}
template <class Elemento>
Coda<Elemento>::Coda(){
	maxlength=STANDARDSIZE;
	create();
}

template <class Elemento>
Coda<Elemento>::Coda(const Coda<Elemento>&q){
	head = q.head;
	length = q.length;
	maxlength = q.maxlength;
	elems = new Elemento[q.maxlength];

	for(int i = 0; i<q.length;i++)
		elems[i]=q.elems[i];
}

template < class Elemento>
void Coda<Elemento>::create(){
  elems = new Elemento[maxlength];
  head = 0;
  length = 0;
}

template < class Elemento >
bool Coda<Elemento>::empty(){
  return (length == 0);
}

template <class Elemento>
Elemento Coda<Elemento>::top(){
	if(!empty())
		return elems[head];
}

template <class Elemento>
void Coda<Elemento>::pop(){
	if(!empty()){
		head=(head + 1) % maxlength;
		length--;
	}
}

template < class Elemento >
void Coda<Elemento>::push(Elemento a){
  if (length != maxlength){
    elems[(head+length) % maxlength] = a;
    length++;
  }
}

template < class Elemento >
Coda<Elemento>& Coda<Elemento>::operator=(const Coda<Elemento>& q){

  if(this==&q) return *this;

  head=q.head;
  length=q.length;

  if(maxlength!=q.maxlength){
    delete[]elems;
    elems=new Elemento[q.maxlength];
    maxlength=q.maxlength;
  }

  for (int i=head; i<length; i++)
    elems[i]=q.elems[i];

  return *this;

}

template<class tp>
ostream& operator<<(ostream& os, const Coda<tp>& q){

  os<<"[";

  if(!q.empty()){
    int i=q.head;
    while(i<q.length-1){

      os<<q.elems[i]<<", ";

      i++;
    }

    os<<q.elems[i];
  }
  os<<"]"<<endl;

  return os;
}
#endif /* CODA_H_ */
