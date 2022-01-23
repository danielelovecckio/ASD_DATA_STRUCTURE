
/*
 * linearList.h
 *
 *  Created on: 1 ott 2020
 *      Author: Daniele
 */


#ifndef _LISTALIN_H
#define _LISTALIN_H

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

// classe astratta listaLinare
template< class T, class P > //definiamo due segnaposto, perch� la variabile di tipo posizione pu� essere un intero o un puntatore (t per tipoelem) (p per iteratore)
class Linear_list{
 public:
	typedef T value_type;   // the type of object, T, stored in the list
	typedef P position;

	// elenco dei metodi virtual ...operators
	virtual void create() = 0; //=0 non sto dando l'implementazione
	virtual bool empty() const = 0; // true if the list's size is 0
	virtual value_type read(position) const = 0;
	virtual void write(const value_type & x, position p) = 0; // write x at position p
	virtual position begin() const = 0;  // returns a position pointing to the beginning of the list
	virtual bool end(position) const = 0; // verify whether a position points to the end of the list
	virtual position next(position) const = 0; // returns the next position
	virtual position previous(position) const = 0; // return the previous position
	virtual void insert(const value_type &, position) = 0; // insert an element
	virtual void erase(position pos) = 0; // ersaes the element at position pos

	// funzioni di servizio
	//friend ostream& operator<< <T,P>(ostream&, const Linear_list<T,P>&);

	/* Altre funzioni di servizio implementabili */
	/*
		virtual int size() const;  // returns the size of the list
		virtual void push_front(const value_type &); // insert a new element at the beginning
		virtual void push_back(const value_type &); // insert a new element at the end
		virtual void pop_front(); // removes the first element
		virtual void pop_back(); // removes the last element
		virtual void clear(); // erases all the elements
	*/

};

/* sovraccarica <<. Attenzione se il tipo restituito da read non è primitivo, allora
 * anche per questo tipo bisogna sovraccaricare l'operatore <<
  posso usare i metodi della classe astratta (grazie alla parola operator<<)
  Si ritorna un reference ad outputstream
 */
template< class T, class P >
ostream& operator<<(ostream& os, const Linear_list<T,P> &l){
	//serve per dire che position � un nome di tipo
	typename Linear_list<T,P>::position p;
	p = l.begin();
	cout << "[";
	while (!l.end(p)){
		if (p != l.begin())
			cout << ", " << l.read(p);
		else
			cout << l.read(p);
		p = l.next(p);
	}
	cout << "]" << endl;
	return os; //restituisce l'outputstream
}

/*
template< class T, class P >
int Linear_list<T,P>::size() const{
   ....
}
*/

#endif // _LISTALIN_H

