/*
 * Linked_list.h
 *
 *  Created on: 2 ott 2020
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

template <class T>
class Linked_list : public Linear_list<T, Nodo<T>*>{
public :
	typedef typename Linear_list<T,Nodo<T>*>::value_type value_type;
	typedef typename Linear_list<T,Nodo<T>*>::position position;
	//costruttori
	Linked_list();
	Linked_list(int);
	//costruttore copia
	Linked_list(const Linked_list<T>&);
	//distruttore
	~Linked_list();

	//operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type&, position);
	position begin() const;
	position last() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(const value_type&, position);
	void erase(position);
	void inverti(Linked_list&);		//inverte le posizioni di tutti gli elementi della lista
	void invertiDueElementi(position,position);	//inverte la posizione di due elementi della lista
	bool palindromo(Linked_list&);		//true se la lista è palindroma, false altrimenti
	int freq(Linked_list<T>,int);		//restituisce le occorrenza dei multipli dell'intero (secondo parametro)
	void remp(Linked_list<T>&);		// rimuove dalla lista L tutti gli elementi seguiti da un numero dispari.
	int size() const {
		return length;
	};
	// sovraccarico di operatori
	Linked_list<T>& operator=(const Linked_list<T>&); // operatore d'assegnamento
	bool operator==(const Linked_list<T> &) const; //operatore per test d'ugualianza

private:
		Nodo<T> * head;
		int length; // lunghezza della lista
};

template <class T>
Linked_list<T>::Linked_list(){
	head = new Nodo<T>;
	head ->next = head;
	head ->prev = head;
	length = 0;
}

template <class T>
Linked_list<T>::Linked_list(int a){
	head = new Nodo<T>;
	if(a == 0){
		head ->next = head;
		head ->prev = head;
	}else {
		position p;
		p = head;
		for(int i = 0; i<a; i++){
			p-> next = new Nodo<T>;
			p-> next->prev=p;
			p= p->next;
		}
		head->prev=p;
		p->next=head;
	}
	length=a;
}

template <class T>
Linked_list<T>::Linked_list(const Linked_list<T>& l){
	length = l.size();
	head = new Nodo<T>;
	head->next=head;
	head->prev=head;

	if(!l.empty()){
		position p = l.last();
		for(int i = 0;i<l.size();i++){
			insert(l.read(p),begin());
			p=l.previous(p);
		}
	}
}

template <class T>
Linked_list<T>::~Linked_list(){
	while(!empty()){
		erase(begin());
	}
	delete head;
}

template< class T >
void Linked_list< T >::create(){
	if (empty())
		length = 0;
}

template<class T>
bool Linked_list<T>::empty() const{
	return head==head->next;
}

template< class T >
typename Linked_list<T>::position Linked_list<T>::begin() const {
	return head->next;
}


template <class T>
typename Linked_list<T>::position Linked_list<T>::last() const{
	return head->prev;
}

template<class T>
typename Linked_list<T>::position Linked_list<T>::next(position p) const {
	return(p->next);
}

template<class T>
typename Linked_list<T>::position Linked_list<T>::previous(position p) const {
	if (p != head)
		return(p->prev);
	else
		return nullptr;
}


template<class T>
bool Linked_list<T>::end(position p) const {
	return p == head;
}

template<class T>
typename Linked_list<T>::value_type Linked_list<T>::read(position p) const{
	if(!end(p))
		return p->value;
}

template <class T>
void Linked_list<T>::write(const value_type &a, position p){
	if(!end(p))
	p->value = a;
}

template <class T>
void Linked_list<T>::insert(const value_type &a, position p){
	position t = new Nodo<T>;
	t->value = a;

	t->next = p;
	t->prev = p->prev;
	p->prev->next = t;
	p->prev = t;

	length++;
}

template<class T>
void Linked_list<T>::erase(position p){
	if(!empty() && !end(p)){
		p->prev->next=p->next;
		p->next->prev=p->prev;
		delete p;
	}
}


template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L){
	if (this != &L){
		length = L.size();

		head = new Nodo<T>;
		head->next = head;
		head->prev = head;

		if (!L.empty()){
            position p = L.last();
			for (int i=0; i < L.size(); i++){
				cout << i, L.read(p);
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this;
}


template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const{
	if (L.size() != length)
		return false;
	position p, pL;
	p = begin();
	pL = L.begin();
	while (!end(p)){
		if (p->value != pL->value)
			return false;
		p = p->next;
		pL = pL->next;
	}
	return true;
}

template<class T>
void Linked_list<T>::inverti(Linked_list& lista){

	Linked_list<T>::position pBegin = lista.begin();
	Linked_list<T>::position pEnd = lista.last();

	invertiDueElementi(pBegin,pEnd);

	if(lista.length%2==0){
		while(pBegin->next!=pEnd){
			invertiDueElementi(pBegin->next,pEnd->prev);
			pBegin = pBegin->next;
			pEnd = pEnd->prev;
		}
	}else{
		for(int i = 0;i<=(lista.size()/2)-1;i++){
			invertiDueElementi(pBegin->next,pEnd->prev);
			pBegin = pBegin->next;
			pEnd = pEnd->prev;
			cout<<i;
		}
	}

}
template<class T>
void Linked_list<T>::invertiDueElementi(position p,position p1){
	value_type e;

	e = p->value;
	p->value = p1->value;
	p1->value = e;
}

template<class T>
bool Linked_list<T>::palindromo(Linked_list& lista){
	bool risp = true;
	Linked_list<T>::position pBegin = lista.begin();
	Linked_list<T>::position pEnd = lista.last();
/*	do{
		risp = true;
		if(pBegin->value!=pEnd->value)
			return false;
		pBegin = pBegin->next;
		pEnd = pEnd->prev;
	}while(pBegin->value==pEnd->value);
*/
	if(lista.size()%2!=0){
		while((lista.read(pBegin)==lista.read(pEnd)) && pBegin->next!=pEnd->prev){
			risp = true;
			pBegin = pBegin->next;
			pEnd = pEnd->prev;
		}
	}else{
		while((lista.read(pBegin)==lista.read(pEnd)) && pBegin->next!=pEnd){
			risp = true;
			pBegin = pBegin->next;
			pEnd = pEnd->prev;
		}
	}
	if(lista.read(pBegin)!=lista.read(pEnd))
		risp = false;
	return risp;
}
template<class T>
int Linked_list<T>::freq(Linked_list<T> list, int k){
	int occorrenze = 0;
	Linked_list<T>::position iter = list.begin();
	while(iter!=list.last()){
		if(list.read(iter)%k == 0 && list.read(iter)!=0)
			occorrenze++;
		iter = iter->next;
	}
	return occorrenze;
}

template<class T>
void Linked_list<T>::remp(Linked_list<T> &list){
	Linked_list<T>::position iter = list.begin();
	while(!list.end(iter)){
		if(list.read(iter)%2!=0)
			erase(list.next(iter));
		iter = list.next(iter);
	}
}

#endif /* LINKED_LIST_H_ */
