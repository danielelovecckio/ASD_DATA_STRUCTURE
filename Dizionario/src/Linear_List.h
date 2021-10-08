/*
 * Linear_List.h
 *
 *  Created on: 1 ott 2020
 *      Author: peppi
 */

#ifndef LINEAR_LIST_H_
#define LINEAR_LIST_H_

#include <iostream>
using namespace std;


//Classe astratta lista lineare

template<class T, class P>	//definiamo due segnaposto, perchè la variabile di tipo posizione può essere un intero o un puntatore (t per tipoelem) (p iteratore)

class Linear_List{

public:
	typedef T valore;
	typedef P posizione;

	//elenco metodi virtuali...operators
	virtual void crea()=0; //=0 non sto dando l'implementazione
	virtual bool vuoto()const=0;	//vuoto true se e vuoto
	virtual valore leggi(posizione) const=0;	//read
	virtual void scrivi(const valore & x, posizione p)=0;
	virtual posizione inizio()const=0;	//ritorna la posiione iniziale
	virtual bool fine(posizione) const =0; //verifica se è lultima posizione
	virtual posizione succ(posizione)const=0;
	virtual posizione precc(posizione)const=0;
	virtual void inserisci(const valore &, posizione)=0;
	virtual void cancella(posizione)=0;	//erase

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


/* sovraccarica <<. Attenzione se il tipo restituito da read non Ã¨ primitivo, allora
 * anche per questo tipo bisogna sovraccaricare l'operatore <<
  posso usare i metodi della classe astratta (grazie alla parola operator<<)
  Si ritorna un reference ad outputstream
 */
template< class T, class P >
ostream& operator<<(ostream& os, const Linear_List<T,P> &l){
	//serve per dire che position è un nome di tipo
	typename Linear_List<T,P>::posizione p;
	p = l.inizio();
	cout << "[";
	while (!l.fine(p)){
		if (p != l.inizio())
			cout << ", " << l.leggi(p);
		else
			cout << l.leggi(p);
		p = l.succ(p);
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



#endif /* LINEAR_LIST_H_ */
