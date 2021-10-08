
/*
 * linearList.h
 *
 *  Created on: 1 ott 2020
 *      Author: Daniele
 */

#ifndef LINEARLIST_H_
#define LINEARLIST_H_

#include <iostream>

using namespace std;

//classe astratta listaLineare

template <class T, class P>
class Linear_list{
public :
	typedef T value_type; //tipo oggetto salvato nella lista
	typedef P position;		//posizione dell'oggetto

	//operatori
	virtual ~Linear_list(){}
	virtual void create() = 0;
	virtual bool empty() const = 0; //vero se la lista è di lunghezza 0
	virtual value_type read(position) const = 0;
	virtual void write(const value_type &x, position p) = 0; //scrive x nella posizione p indicata come parametro
	virtual position begin() const = 0; //ritorna la posizione che punta all'inizio della lista
	virtual bool end(position) const = 0;	//verifica se la posizione indicata punta alla fine
	virtual position next(position) const = 0; //ritorna la prossima posizione
	virtual position previous(position) const = 0;	//ritorna la posizione precedente
	virtual void insert(const value_type &, position) = 0; //inserisce un elemento nella lista nella posizione indicata
	virtual void erase(position pos)=0; //cancella l'elemento nella posizione indicata


	//funzioni di servizio
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
#endif /* LINEARLIST_H_ */


/* sovraccarica <<. Attenzione se il tipo restituito da read non è primitivo, allora
 * anche per questo tipo bisogna sovraccaricare l'operatore <<
 */
template< class T, class P >
ostream& operator<<(ostream& os, const Linear_list<T,P> &l){
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
	return os;
}

/*
template< class T, class P >
int Linear_list<T,P>::size() const{
   ....
}
*/
