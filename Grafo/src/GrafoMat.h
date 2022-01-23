/*
 * GrafoMat.h
 *
 *  Created on: 13 ott 2020
 *      Author: daniele
 */

#ifndef GRAFOMAT_H_
#define GRAFOMAT_H_

#include "Grafo.h"

template<class P>
class InfoArcoMat
{
 public:
	P peso;			//peso dell'arco tra due nodi
	bool vuoto;		//indica se è presente l'elemento o meno

	InfoArcoMat()
	{
		vuoto = true;
	}
};
template<class E, class P>
class InfoNodoMat {
 public:
	E   etichetta;
	bool vuoto;
	void* info;
	bool marcato;
	InfoArcoMat<P>* archi;

	InfoNodoMat(){
		info = 0;
		marcato = false;
		vuoto = true;
		archi = nullptr;
	}

	~InfoNodoMat(){
		if (!vuoto)
			delete [] archi;
	}
};
class NodoGMat{
 public:
	NodoGMat(int i){
		nodoId = i;
	}
	NodoGMat(){
		nodoId = 0;
	}
	int getId(){
		return nodoId;
	}
	void setId(int id) {
		nodoId = id;
	}
 private:

	int nodoId;
};

template<class E, class P>
	class GrafoMat : public Grafo<E, P, NodoGMat > {
 public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoGMat Nodo;
    typedef _Arco<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
	typedef typename Grafo_::ListaNodiPos ListaNodiPos;

    GrafoMat(int);
    ~GrafoMat();

    bool vuoto() const;
    void insNodo(NodoGMat&);
    void insArco(Nodo, Nodo, Peso);
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);

    void setMarcato(Nodo&);
    bool getMarcato(Nodo&);

    void reset_marcatura();
    ListaNodi adiacenti(Nodo) const ;
    ListaNodi list_nodi() const ;
    Etichetta leggiEtichetta(Nodo) const ;
    void scriviEtichetta(Nodo, Etichetta) ;
    Peso leggiPeso(Nodo, Nodo) const ;
    void scriviPeso(Nodo, Nodo, Peso) ;
    bool sameColorPath(Nodo&,Nodo&); //Restituisce true se esiste un path che collega il nodo n1 al nodo n2 e tutti i nodi presenti
    							   //in tale path sono dello stesso colore, false altrimenti

    bool uniformColorPath(Nodo&,Nodo&); 	//restituisce true se esiste un path che collega il nodo n1
    										//al nodo n2 ed ogni nodo presente in tale path e etichettato con un colore diverso da quello con
    										//cui `e etichettato il nodo precedente, false altrimenti.

    bool esiste_cammino(Nodo,Nodo,Peso); //true se nel grafo esiste un cammino tra i due nodi e sugli archi c'è il peso indicato
    int numero_cammini(Nodo&,Nodo&); //calcola il numero di cammini tra un nodo ed un altro
    bool esiste_cammino(Nodo&,Nodo&); //true se nel grafo esiste un cammino tra i due nodi, false altrimenti

    int somma_nodi_adiacenti(Nodo); 		//somma tutti i nodi adiacenti al nodo indicato come parametro
    int somma_nodi_con_cammino(Nodo,int);	//Dato un nodo di partenza e la lunghezza del cammino, il metodo restituisce la somma delle etichette contenute dai nodi
    										//raggiungibili dal nodo indicato dal primo parametro con cammini di lunghezza indicata con il secondo parametro

    int conta_nodi_nei_cammini(Nodo,int);	//indicato un nodo di partenza e la lunghezza del cammino,
    										//il metodo restituisce il numero di nodi raggiungibili dal nodo con cammini di lunghezza indicata con il secondo parametro

    double media_nodi_cammino(Nodo,int);	//restituisce la media dei valori delle etichette dei nodi raggiungibili dal nodo indicato dal primo parametro con
    										//cammini di lunghezza indicata con il secondo parametro
    int countSame(Nodo);	//restituisce il numero di nodi raggiungibili da n1 e aventi la sua stessa etichetta

    int numNodi(){
		return nodi;
	};
	int numArchi(){
		return archi;
	};

private:
	InfoNodoMat<E,P>* matrice;
	int dimensione;
	int nodi;
	int archi;
};

template <class E,class P>
GrafoMat<E,P>::GrafoMat(int _dim){
	dimensione = _dim;
	nodi = 0;
	archi = 0;
	matrice = new InfoNodoMat<E,P>[dimensione];

	for(int i = 0; i<dimensione;i++){
		matrice[i].archi = new InfoArcoMat<P>[dimensione];
	}
}

template<class E, class P>
	GrafoMat<E, P>::~GrafoMat() {
	delete [] matrice;
}


template<class E, class P>
bool GrafoMat<E, P>::vuoto() const {
	return (nodi == 0);
}

template<class E,class P>
void GrafoMat<E,P>::insNodo(Nodo& n){
	int i = 0;
	if(nodi< dimensione){
		while(matrice[i].vuoto == false)
			i++;

		nodi++;
		matrice[i].vuoto = false;
	}
	n.setId(i);
}

template<class E, class P>
void GrafoMat<E, P>::insArco(Nodo n1, Nodo n2, P peso) {
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
	matrice[n1.getId()].archi[n2.getId()].vuoto = false;
	archi++;
}

template<class E, class P>
void GrafoMat<E,P>::setMarcato(Nodo& n){
	matrice[n.getId()].marcato = true;
}

template<class E, class P>
bool GrafoMat<E,P>::getMarcato(Nodo& n){
	return matrice[n.getId()].marcato;
}

template<class E,class P>
void GrafoMat<E,P>::reset_marcatura(){
	for(int i=0;i<dimensione;i++){
		matrice[i].marcato = false;
	}
}



template<class E, class P>
void GrafoMat<E, P>::cancNodo(Nodo n) {
	// ATTENZIONE: controllare prima che non ci siano archi uscenti o entranti in n
	bool canc = true;
	int i;
	for (i=0; i < dimensione && canc; i++)
		if (!matrice[n.getId()].archi[i].vuoto)
			canc = false;
	for (i=0; i < dimensione && canc; i++)
		if (!matrice[i].vuoto && !matrice[i].archi[n.getId()].vuoto)
			canc = false;

	if (canc){
		delete matrice[n.getId()].archi;
		cout<<"cancellato";
		matrice[n.getId()].vuoto = true;
	}
}


template<class E, class P>
void GrafoMat<E, P>::cancArco(Nodo n1, Nodo n2){
	matrice[n1.getId()].archi[n2.getId()].vuoto = true;
	archi--;
}

template<class E, class P>
typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::adiacenti(Nodo n) const{
	ListaNodi list;

	for (int i = 0; i < dimensione; i++) {
		if (!matrice[n.getId()].archi[i].vuoto) {
			list.insert(new NodoGMat(i), list.begin());
		}
	}
	return list;
}

template<class E, class P>
typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::list_nodi() const {
	ListaNodi list;
	for (int i = 0; i < dimensione; i++)
		if (!matrice[i].vuoto)
			list.insert(new NodoGMat(i), list.begin());
	return list;
}

template<class E, class P>
E GrafoMat<E, P>::leggiEtichetta(Nodo n) const {
	return matrice[n.getId()].etichetta;
}

template<class E, class P>
void GrafoMat<E, P>::scriviEtichetta(Nodo n, E etichetta) {
	matrice[n.getId()].etichetta = etichetta;
}

template<class E, class P>
P GrafoMat<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
	return matrice[n1.getId()].archi[n2.getId()].peso;
}

template<class E, class P>
void GrafoMat<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
}

template <class E,class P>
bool GrafoMat<E,P>::sameColorPath(Nodo& n1,Nodo& n2){

	bool risp = false;
    GrafoMat<E,P>::ListaNodi listN1 = adiacenti(n1);
    GrafoMat<E,P>::ListaNodiPos p1 = listN1.begin();

    GrafoMat<E,P>::ListaNodiPos pTemp = p1;

    while(!listN1.end(p1)){
    	if(listN1.read(p1)->getId() == n2.getId() && leggiEtichetta(n1) == leggiEtichetta(n2))
    		return risp = true;
    	p1 = listN1.next(p1);
    }

    setMarcato(n1);

    while(!listN1.end(pTemp)){
    	Nodo n3 = *listN1.read(pTemp);
    	if(getMarcato(n3)==false && leggiEtichetta(n3) == leggiEtichetta(n1)){
    		risp = sameColorPath(n3,n2);
    	}
    	if(risp){
    		return risp;
    	}
    	pTemp = listN1.next(pTemp);
    }

	return risp;
}

template<class E,class P>
bool GrafoMat<E,P>::uniformColorPath(Nodo& n1,Nodo& n2){
	bool risp = false;
	 GrafoMat<E,P>::ListaNodi listN1 = adiacenti(n1);
	    GrafoMat<E,P>::ListaNodiPos p1 = listN1.begin();

	    GrafoMat<E,P>::ListaNodiPos pTemp = p1;


	    while(!listN1.end(p1)){
	    	if(listN1.read(p1)->getId() == n2.getId() && leggiEtichetta(n1) != leggiEtichetta(n2))
	    		return risp = true;
	    	p1 = listN1.next(p1);
	    }

	    setMarcato(n1);

	    while(!listN1.end(pTemp)){
	    	Nodo n3 = *listN1.read(pTemp);
	    	if(getMarcato(n3)==false && leggiEtichetta(n3) != leggiEtichetta(n1)){
	    		risp = uniformColorPath(n3,n2);
	    	}
	    	if(risp){
	    		return risp;
	    	}
	    	pTemp = listN1.next(pTemp);
	    }

	return risp;
}

template <class E,class P>
bool GrafoMat<E,P>::esiste_cammino(Nodo n1, Nodo n2,Peso peso){

	GrafoMat<E,P>::ListaNodi list = adiacenti(n1);
	GrafoMat<E,P>::ListaNodiPos p = list.begin();
	GrafoMat<E,P>::ListaNodiPos pTemp = p;
	bool risp = false;

	while(!list.end(p)){
		if(list.read(p)->getId() == n2.getId() && leggiPeso(n1,*list.read(p))==peso){
			return risp = true;
		}
		p = list.next(p);
	}

	while(!list.end(pTemp)){
		Nodo n = *list.read(pTemp);

		if(leggiPeso(n1,n)==peso)
		 risp = esiste_cammino(n,n2,peso);

		pTemp = list.next(pTemp);
	}
	return risp;
}

template <class E,class P>
int GrafoMat<E,P>::numero_cammini(Nodo& n1,Nodo& n2){
	int num = 0;
	GrafoMat<E,P>::ListaNodi list = adiacenti(n1);
	GrafoMat<E,P>::ListaNodiPos p = list.begin();
	GrafoMat<E,P>::ListaNodiPos pTemp = p;

	while(!list.end(p)){
		if(list.read(p)->getId() == n2.getId())
		  num++;

		p = list.next(p);
	}

	while(!list.end(pTemp)){
		Nodo n = *list.read(pTemp);
		num += numero_cammini(n,n2);
		pTemp = list.next(pTemp);
	}

	return num;
}

template <class E,class P>
bool GrafoMat<E,P>::esiste_cammino(Nodo& n1, Nodo& n2){
	bool risp = false;
	GrafoMat<E,P>::ListaNodi list = adiacenti(n1);
	GrafoMat<E,P>::ListaNodiPos p = list.begin();
	GrafoMat<E,P>::ListaNodiPos pTemp = p;

	while(!list.end(p)){
		if(list.read(p)->getId() == n2.getId())
			return risp = true;
		p = list.next(p);
	}

	setMarcato(n1);

	while(!list.end(pTemp)){
		Nodo n = *list.read(pTemp);
		if(!getMarcato(n))
			risp = esiste_cammino(n,n2);
		if(risp) return risp;
		pTemp = list.next(pTemp);
	}
	return risp;
}

template<class E,class P>
int GrafoMat<E,P>::somma_nodi_adiacenti(Nodo n){
	int somma = 0;
	GrafoMat<E,P>::ListaNodi list = adiacenti(n);
	GrafoMat<E,P>::ListaNodiPos p = list.begin();

	while(!list.end(p)){
		somma += leggiEtichetta(*list.read(p));
		p = list.next(p);
	}

	return somma;
}

template <class E,class P>
int GrafoMat<E,P>::somma_nodi_con_cammino(Nodo n, int cammino){
	int somma = 0;
	GrafoMat<E,P>::ListaNodi list = adiacenti(n);
	GrafoMat<E,P>::ListaNodiPos p = list.begin();

	if(cammino == 1)
		return somma_nodi_adiacenti(n);

	p = list.begin();
	while(!list.end(p)){
		n = *list.read(p);
		somma += somma_nodi_con_cammino(n,cammino-1);
		p = list.next(p);
	}

	return somma;
}

template <class E,class P>
int GrafoMat<E,P>::conta_nodi_nei_cammini(Nodo n, int cammino){
	int num = 0;
	GrafoMat<E,P>::ListaNodi list = adiacenti(n);
	GrafoMat<E,P>::ListaNodiPos p = list.begin();

	if(cammino == 1)
		num++;

	p = list.begin();
	while(!list.end(p)){
		n = *list.read(p);
		num += conta_nodi_nei_cammini(n,cammino-1);
		p = list.next(p);
	}
	return num;
}

template <class E,class P>
double GrafoMat<E,P>::media_nodi_cammino(Nodo n, int cammino){
	return somma_nodi_con_cammino(n,cammino)/conta_nodi_nei_cammini(n,cammino);
}

template <class E,class P>
int GrafoMat<E,P>::countSame(Nodo n){
	int num = 0;
	GrafoMat<E,P>::ListaNodi list = adiacenti(n);
	GrafoMat<E,P>::ListaNodiPos p = list.begin();

	while(!list.end(p)){
		if(leggiEtichetta(*list.read(p)) == leggiEtichetta(n))
			num++;
	 p = list.next(p);
	}
	p = list.begin();
	while(!list.end(p)){
	//	Nodo n1 = *list.read(p);
    //	scriviEtichetta(n1,leggiEtichetta(n));
		num += countSame(n1);
		p = list.next(p);
	}

	return num;
}












#endif /* GRAFOMAT_H_ */
