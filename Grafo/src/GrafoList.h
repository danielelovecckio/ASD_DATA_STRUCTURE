/*
 * GrafoList.h
 *
 *  Created on: 12 ott 2020
 *      Author: daniele
 */

#ifndef GRAFOLIST_H_
#define GRAFOLIST_H_

#include "Grafo.h"
#include "Linked_list.h"
/**
	Questa realizzazione usa un vettore per tenere traccia di tutti quanti i nodi del grafo, ogni cella del vettore fa riferimento ad un'altra lista di nodi
	facenti parte alla lista degli adiacenti di ogni nodo.

	Inoltre è possibile creare dei grafi pesati, andando a specificare in fase di costruzione del grafo di che tipo si vuole il peso.

**/
class NodoG{
public :
	NodoG(int i){
		id = i;
		marcato = false;
		G = nullptr;
	}
	NodoG(){
		id = 0;
		G = nullptr;
		marcato = false;
	}
	int getId(){return id;}
	void setId(int id1){
		id = id1;
	}
	void setPuntatore(void* Gr){
		G = Gr;
	}
	void* getPuntatore(){
		return G;
	}
private :
	bool marcato; //marcatura di un nodo
	void*G;
	int id = 0; //id del nodo, indice del nodo nel vettore
};

template<class P>
class InfoArco{
public:
	P peso;//peso dell'arco tra due nodi
	NodoG _to;//indice a cui punta l'arco nel vettore
};

template<class E, class P>
class InfoNodo{
public :
	E etichetta;
	bool vuoto; //status se vuoto o meno nel vettore dei nodi
	void *info;
	Linked_list<InfoArco<P>> archi;
	int archi_entranti;	//contiene il numero di archi entranti di un nodo

	InfoNodo(){
		info = 0;
		vuoto = true;
		archi_entranti = 0;
	}
};


template <class E,class P>
class GrafoList : public Grafo<E,P,NodoG>{
public :
	typedef E Etichetta;
	typedef P Peso;
	typedef NodoG Nodo;
	typedef _Arco<Peso,Nodo> Arco;
	typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
	typedef typename Grafo_::ListaNodi ListaNodi;
	typedef typename Grafo_::ListaNodiPos ListaNodiPos;


    GrafoList(int);		//COSTRUTTORE
    ~GrafoList();		//DISTRUTTORE

    bool vuoto() const;	//grafo vuoto
    void insNodo(NodoG&);	//inserimento di un nodo
    void insArco(Nodo, Nodo, Peso);	//inserimento di un arco
    void cancNodo(Nodo);	//cancella un nodo
    void cancArco(Nodo,Nodo); 	//cancella l'arco
    bool esisteArco(Nodo n1,Nodo n2)const;	//controllo esistenza di un arco
    bool esisteNodo(Nodo)const;	//controllo esistenza nodo
    ListaNodi adiacennti(Nodo)const;	 //metodo che dato un nodo mi restituisce una lista di nodi adiacenti a quello indicato
    ListaNodi list_nodi() const;	//lista di nodi presenti nel grafo
    Etichetta leggiEtichetta(Nodo) const;	//Valore dell'etichetta associata al Nodo dato come parametro
    void scriviEtichetta(Nodo,Etichetta);	//Settaggio dell'etichetta associata ad un nodo
    Peso leggiPeso(Nodo,Nodo) const; //dati due nodi, il metodo mi restituisce il peso dell'arco che collega i due nodi
    void scriviPeso(Nodo, Nodo, Peso) ;			//funzione che, dati due nodi ed un peso, mi determina il peso dell'arco
    void* getIndirizzo() {return this;}
    ListaNodi adiacenti(Nodo) const;
    int numNodi()
	{
      return nodi;		//restituisce il numero di nodi del grafo
    };
    int numArchi()
	{
      return archi;		//restituisce il numero di archi del grafo
    };

private:
   InfoNodo<E,P>* matrice;			//array di tipo Infonodo - che contiene nodi
   int dimensione;					//dimensione massima dei nodi possibili in un grafo
   int nodi;						//nodi effettivamente presenti nel grafo
   int archi;						//numero di archi presenti presenti nel grafo

};

template<class E,class P>
GrafoList<E,P>::GrafoList(int _dim){
	dimensione = _dim;
	nodi = 0;		//setto il numero dei nodi presenti a 0
	archi = 0;		//setto il numero dei archi presenti a 0
	matrice = new InfoNodo<E,P>[dimensione];		//alloco un array di tipo InfoNodo di dimensione (DIMENSIONE)

	for(int i = 0;i<dimensione;i++){
		matrice[i].vuoto= true;
		matrice[i].archi.create();
	}
}

template<class E, class P>
GrafoList<E, P>::~GrafoList(){ 		//distruttore del vettore

  delete [] matrice;		//deallocazione del vettore dei nodi
}


template<class E,class P>
bool GrafoList<E,P>::vuoto()const{
	return nodi==0;
}

template<class E, class P>
bool GrafoList<E,P>::esisteNodo(Nodo n)const{
	bool trovato = false;
	if(n.getPuntatore()==this && !matrice[n.getId()].vuoto){

		for(int i = 0;i<dimensione && trovato==false;i++){
			if(matrice[i].etichetta == matrice[n.getId()].etichetta)
				trovato = true;
		}
	}
	return trovato;
}


template<class E,class P>
bool GrafoList<E,P>::esisteArco(NodoG n1, NodoG n2)const{
	typename Linked_list<InfoArco<P> >::position p;
	    bool trovato=false;
	    p=matrice[n1.getId()].archi.begin();
	    while(!matrice[n1.getId()].archi.end(p) && !trovato)
	    {
	        if(matrice[n1.getId()].archi.read(p)._to.getId()==n2.getId())
	        {
	            trovato=true;
	        }
	        else
	        {
	            p = matrice[n1.getId()].archi.next(p);
	        }
	    }
	    return trovato;
}

template<class E, class P>
void GrafoList<E,P>::insNodo(NodoG& n){
	int i = 0; 	//indice
	if(nodi<dimensione){		//numero di nodi minore della dimensione effettiva
		while(matrice[i].vuoto == false)		//fin quando non trovo una cella vuota nella matrice
			i++;
		nodi++;
		matrice[i].vuoto  = false;
	}
	matrice[i].archi_entranti = 0;
	n.setId(i);			//il nuovo nodo avrà l'id equivalente alla posizione nel vettore
	n.setPuntatore(this);	// this -> indirizzo di memoria del grafo
}

template<class E,class P>
void GrafoList<E,P>::insArco(Nodo n1, Nodo n2, P peso){
	if(esisteNodo(n1)&&esisteNodo(n2)){
		InfoArco<P> I;
		I.peso = peso;
		I._to = n2;		//n2 è il nodo entrante, _to è la destinazione dell'arco
		matrice[n1.getId()].archi.insert(I, matrice[n1.getId()].archi.begin());		//vado ad inserire l'arco nella lista degli archi uscenti del nodo n1

		matrice[n2.getId()].archi_entranti++;	//vado ad aumentare il numero di archi entranti
		archi++;
	}else{
		cout << "I due nodi non appartengono allo stesso grafo "<<endl;
	}
}


template<class E, class P>
  void GrafoList<E, P>::cancNodo(Nodo n){
  bool canc = true;
  int i = 0;
  for (i=0; i < dimensione && canc; i++){ 		//ciclo fino a quando l'indice è minore della dimensione e canc=TRUE
    if (!matrice[n.getId()].archi.empty()) 		//se la lista degli archi in riferimento al nodo uscente è vuota
      canc = false;			//setto canc a falso

  	if(matrice[n.getId()].archi_entranti!=0)
  		canc=false;
  }

	//se il numero di archi entranti e' 0
  if(canc)		//se CANC è TRUE
  {
    // la lista  matrice[n.getId()].archi è vuota;
    matrice[n.getId()].vuoto = true;		//setto a TRUE la cella del vettore in riferimento al nodo cancellato
    cout<<"cancellato"<<endl;
  }
}


template<class E, class P>
  void GrafoList<E, P>::cancArco(Nodo n1, Nodo n2){
	if(n1.getPuntatore()==n2.getPuntatore()){		//puntano alla cella di memoria del grafo

		typename Linked_list<InfoArco<P> >::position p; 		//dichiaro un indice di posizione P
		p = matrice[n1.getId()].archi.begin();					//lo faccio puntare alla prima posizione della lista degli archi uscenti del nodo N1
		bool trovato = false;									//inizializzo il boolean TROVATO a false
		while (!matrice[n1.getId()].archi.end(p) && !trovato){		//fino a quando non arrivo alla fine della lista dei nodi uscenti e non è stato trovato

			if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())		//se l'ID della posizione in cui si trova P è uguale a quello di n2
				trovato = true;														//imposto trovato=true
			else
					p = matrice[n1.getId()].archi.next(p);		//altrimenti passo al successivo
		}
		if (trovato)		//se il nodo di destinazione è stato trovato
		{
			matrice[n1.getId()].archi.erase(p);		//cancello l'arco presente in posizione P
			matrice[n2.getId()].archi_entranti--;			//<--FATTO
	  		archi--;			//decremento il numero di archi presenti nel grafo
		}
	}
	else
	{
		cout<<"ATTENZIONE! Si sta tentando di cancellare un arco tra due nodi che non appartengono allo stesso grafo"<<endl;
	}
}

template<class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::adiacenti(Nodo n) const{
ListaNodi list;
typename Linked_list<InfoArco<P> >::position p; 			//dichiaro l'indice posizionale P

    if(!matrice[n.getId()].archi.empty())
	{
		p = matrice[n.getId()].archi.begin();
		while (!matrice[n.getId()].archi.end(p))
		{
			//matrice[n.getId()].archi.read(p)._to.getId();
			list.insert(new NodoG(matrice[n.getId()].archi.read(p)._to),list.begin());
			p = matrice[n.getId()].archi.next(p);
		}
	}
  return list;
}

template<class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::list_nodi() const {
  ListaNodi list;			//creo una lista di riferimenti a Nodi
  for (int i = 0; i < dimensione; i++)		//ciclo fino alla dimensione massima
    if (!matrice[i].vuoto) 		//se il nodo corrente ha archi uscenti
      list.insert(new NodoG(i), list.begin());		//inserisco nella lista creata il riferimento alla posizione del vettore del nodo, posizionandola all'inizio
  return list;		//ritorno l'indice della lista
}

template<class E, class P>
  E GrafoList<E, P>::leggiEtichetta(Nodo n) const{
  return matrice[n.getId()].etichetta;				//restituisce l'etichetta di un nodo, passato per parametro
}

template<class E, class P>
void GrafoList<E, P>::scriviEtichetta(Nodo n, E etichetta){
  matrice[n.getId()].etichetta = etichetta;			//imposta l'etichetta del nodo indicato, con la sua etichetta
}

template<class E, class P>
P GrafoList<E, P>::leggiPeso(Nodo n1, Nodo n2) const{
	typename Linked_list<InfoArco<P> >::position p; 			//dichiaro l'indice posizionale P
	p = matrice[n1.getId()].archi.begin();						//P lo metto all'inizio della lista degli archi del nodo uscente
	bool trovato = false;										//imposto trovato=false
	while (!matrice[n1.getId()].archi.end(p) && !trovato)			//fino a quando non arrivo alla fine della lista degli archi e non l'ho trovato
	{
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())		//se il riferimento al nodo entrante è uguale all'ID di N2
			trovato = true;														//imposto trovato=true
		else
				p = matrice[n1.getId()].archi.next(p);							//altrimenti incremento P al successivo
	}
	if (trovato)																//se l'ho trovato
		return matrice[n1.getId()].archi.read(p).peso;							//leggo il peso relativo all'arco
}

template<class E, class P>
void GrafoList<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	typename Linked_list<InfoArco<P> >::position p; 			//dichiaro l'indice posizionale P
	p = matrice[n1.getId()].archi.begin();						//P lo metto all'inizio della lista degli archi del nodo uscente
	bool trovato = false;										//imposto trovato=false
	while (!matrice[n1.getId()].archi.end(p) && !trovato)		//fino a quando non arrivo alla fine della lista degli archi e non l'ho trovato
	{
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())	//se il riferimento al nodo entrante è uguale all'ID di N2
			trovato = true;													//imposto trovato=true
		else
				p = matrice[n1.getId()].archi.next(p);						//altrimenti incremento P al successivo
	}
	if (trovato)												//se l'ho trovato
	{
		InfoArco<P> I;											//creo un arco i
		I.peso = peso;											//ne imposto il peso
		I._to = n2;												//imposto il riferimento al nodo destinatario
		matrice[n1.getId()].archi.write(I,p);					//scrivo nella posizione p L'ARCO che è stato creato
	}
}

#endif /* GRAFOLIST_H_ */
