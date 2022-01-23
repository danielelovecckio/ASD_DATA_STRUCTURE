/*
 * Grafo.h
 *
 *  Created on: 12 ott 2020
 *      Author: daniele
 */

#ifndef GRAFO_H_
#define GRAFO_H_
#include "Linked_list.h"

template <class P,class N>
class _Arco{
public :
	N nodo1;
	N nodo2;
	P peso;
};

template <class E, class P, class N>
class Grafo{
public:
	typedef E Etichetta;
	typedef P Peso;
	typedef N Nodo;

	typedef _Arco<Peso, Nodo> Arco;
	typedef Linked_list<Nodo*> ListaNodi;
	typedef typename Linked_list<Nodo*>::position ListaNodiPos;
	typedef Linked_list<Arco> ListaArchi;

	virtual bool vuoto() const = 0;
	virtual void insNodo(Nodo&) = 0;
	virtual void insArco(Nodo, Nodo, Peso) = 0;
	virtual void cancNodo(Nodo) = 0;
	virtual void cancArco(Nodo, Nodo) = 0;
//	virtual bool esisteNodo(Nodo)const = 0;
//	virtual bool esisteArco(Nodo,Nodo)const = 0;
	virtual ListaNodi adiacenti(Nodo) const = 0;
	virtual ListaNodi list_nodi() const = 0;
	virtual Etichetta leggiEtichetta(Nodo) const = 0;
	virtual void scriviEtichetta(Nodo, Etichetta) = 0;
	virtual Peso leggiPeso(Nodo, Nodo) const = 0;
	virtual void scriviPeso(Nodo, Nodo, Peso) = 0;

	virtual int numNodi() = 0;
	virtual int numArchi() = 0;

	virtual ~Grafo(){};
};
#endif /* GRAFO_H_ */
