/*
 * LinkedList.h
 *
 *  Created on: 2 ott 2020
 *      Author: peppi
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Linear_List.h"

template<class T>
class LinkedList;

template<class T>
class Nodo{
	//ho detto al compilatore che solo questa classe (di tipo friend) possono accedere alle componenti private
	friend class LinkedList<T>;

private:
	T valore;
	Nodo<T> * succ;
	Nodo<T> * precc;

};

///////////////////////////////////
//////////////////////////////////

template<class T>
//è una linear list dove la posizione è un puntatore ad un nodo
class LinkedList : public Linear_List<T, Nodo<T>*>{

public:
	typedef typename Linear_List<T,Nodo<T>*>::valore valore;
	typedef typename Linear_List<T,Nodo<T>*>::posizione posizione;

	//costruttori
	LinkedList();
	LinkedList(int);
	//costruttore copia
	LinkedList(const LinkedList<T>&);
	//distruttore
	~LinkedList();

	//operatori
	void crea();
	bool vuoto()const;
	valore leggi(posizione)const;
	void scrivi(const valore &,posizione );
	posizione inizio()const;
	posizione ultimo()const;
	bool fine(posizione) const;
	posizione succ(posizione)const;
	posizione precc(posizione)const;
	void inserisci(const valore &, posizione);
	void cancella(posizione);
	int size()const{
		return lunghezza;
	}
	// sovraccarico di operatori
		LinkedList<T>& operator=(const LinkedList<T>&); // the assignment operator
		bool operator==(const LinkedList<T> &) const; // tests two list for equality

		////
		void inserisci1(const valore&);

private:
		Nodo<T>* testa;
		int lunghezza;


};


template<class T>
LinkedList<T>::LinkedList(){
	testa=new Nodo<T>;
	testa->succ=testa;
	testa->precc=testa;
	lunghezza=0;
}

template<class T>
LinkedList<T>::LinkedList(int l){

	testa=new Nodo<T>;
	if(l==0){
		testa->succ=testa;
		testa->precc=testa;
	}else{
		posizione p;
		p=testa;
		for(int i=0; i<l; i++){
			p->succ=new Nodo<T>;
			p->succ->precc=p;
			p=p->succ;
		}
		testa->precc=p;
		p->succ=testa;
	}
	lunghezza=l;

}


template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>&l){

	lunghezza=l.size();
	testa=new Nodo<T>;
	testa->succ=testa;
	testa->precc=testa;

	if(!l.vuoto()){
		posizione p=l.ultimo();
		for(int i=0; i<=l.lunghezza;i++){
			inserisci(l.leggi(p),inizio());
			p=l.precc(p);
		}
	}

}

//distruttore deve deallocare partendo dal begin() fino a quando la lista non è vuota.
//Devo poi eliminare il puntatore testa e la sentinella (in next della sentinella punta a se stesso)
//primolista è il successore della sentinella- Se la lista è vuota mi restituisce il valore della sentinella.

template<class T>
LinkedList<T>::~LinkedList(){
	while(!vuoto()){
		cancella(inizio());
	}
	delete testa;
}

//operatori

template<class T>
void LinkedList<T>::crea(){
	if(vuoto()){
		lunghezza=0;
	}
}

template<class T>
bool LinkedList<T>::vuoto()const{
	return testa==testa->succ;
}

template<class T>
typename LinkedList<T>::posizione LinkedList<T>::inizio()const{
	return testa->succ;
}

template<class T>
typename LinkedList<T>::posizione LinkedList<T>::ultimo()const{
	return testa->precc;
}

template<class T>
typename LinkedList<T>::posizione LinkedList<T>::succ(posizione p)const{
	return p->succ;
}

template<class T>
typename LinkedList<T>::posizione LinkedList<T>::precc(posizione p)const{
	return p->precc;
}

template<class T>
bool LinkedList<T>::fine(posizione p)const{
	return p==testa;
}

template<class T>
typename LinkedList<T>::valore LinkedList<T>::leggi(posizione p)const{
	if(!fine(p)){
		return p->valore;
	}
}

template<class T>
void LinkedList<T>::scrivi(const valore &a,posizione p){
	if(!fine(p)){
		p->valore=a;
	}
}

template<class T>
void LinkedList<T>::inserisci(const valore&a,posizione p){

	posizione t=new Nodo<T>;

	t->valore=a;
	t->succ=p;
	t->precc=p->precc;
	p->precc->succ=t;
	p->precc=t;
	lunghezza++;
}


template<class T>
void LinkedList<T>::cancella(posizione p){
	if(!vuoto() && !fine(p)){
		p->precc->succ=p->succ;
		p->succ->precc=p->precc;
		delete p;
	}
}


template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L){
	if (this != &L){
		lunghezza = L.size();

		testa = new Nodo<T>;
		testa->succ = testa;
		testa->precc = testa;

        cout << L.vuoto()<<endl;
        cout << L.size()<<endl;
		if (!L.vuoto()){
            posizione p = L.ultimo();
			for (int i=0; i < L.size(); i++){
				cout << i, L.leggi(p);
				inserisci(L.leggi(p), inizio());
				p = L.precc(p);
			}
		}
	}
	return *this;
}


template<class T>
bool LinkedList<T>::operator==(const LinkedList<T>&L)const{
	if (L.size() == lunghezza)
		return false;
	posizione p, pL;
	p = inizio();
	pL = L.inizio();
	while (!fine(p)){
		if (p->valore != pL->valore)
			return false;
		p = p->succ;
		pL = pL->succ;
	}
	return true;
}

///
template<class T>
void LinkedList<T>::inserisci1(const valore &a){

	if(this->vuoto()){
		inserisci(a,inizio());
		return;
	}else{
		posizione t=new Nodo<T>;
			t->valore=a;
			t->succ=inizio();
			t->precc=ultimo();
			ultimo()->succ=t;
			inizio()->precc=t;
			lunghezza++;

	}

}


#endif /* LINKEDLIST_H_ */
