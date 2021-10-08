/*
 * Dizionario.h
 *
 *  Created on: 6 ott 2020
 *      Author: peppi
 */

#ifndef DIZIONARIO_H_
#define DIZIONARIO_H_


#include "LinkedList.h"

template<class K,class E>
struct Coppia{
	K primo;	//key
	E secondo; //valore

	Coppia(){}
	Coppia(Coppia<K,E>& v){
		primo=v.primo;
		secondo=v.secondo;
	}
	Coppia(const K &k, const E &e){
		primo=k;
		secondo=e;
	}
};


template<class K,class E>
class Dizionario{

public:

	virtual ~Dizionario(){}
	virtual void crea()=0;
	virtual bool vuoto()const=0;
	virtual int size()const=0;
	virtual Coppia<K,E>* trova(const K & k)const=0;	//find
	virtual void inserisci(Coppia<K,E> &)=0;
	virtual void elimina(const K &)=0;
	virtual void modifica(const K &, const E &)=0;
	virtual bool contiene(const K& )const=0;	//contains
	virtual LinkedList<K> keys()const=0;
	virtual LinkedList<E> valore()const=0;


};

#endif /* DIZIONARIO_H_ */
