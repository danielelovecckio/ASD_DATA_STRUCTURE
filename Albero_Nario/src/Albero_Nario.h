/*
 * Albero_Nario.h
 *
 *  Created on: 10 ott 2020
 *      Author: daniele
 */

#ifndef ALBERO_NARIO_H_
#define ALBERO_NARIO_H_

#include "Cella.h"
#include <cassert>
#include <iostream>

using namespace std;

template<class T>
class Albero_Nario{
public :
	//tipi
	typedef T tipoelem;
	typedef Cella<T>* Nodo;
	//costruttore
	Albero_Nario();
	//operatori
	void crea();
	bool empty();
	void insRadice(Nodo);
	void insPrimoFiglio(Nodo);
	void insFratello(Nodo);
	Nodo radiceAlbero();
	Nodo padre(Nodo);
	Nodo primoFiglio(Nodo);
	Nodo succFratello(Nodo);
	bool ultimoFratello(Nodo);
	void insPrimoSottoAlbero(Nodo,Albero_Nario<T>&);	//inserisce un sotto albero come primo figlio di un nodo
	void insSottoAlbero(Nodo,Albero_Nario<T>&);	// inserisce un sotto albero come succFratello di Nodo
	void cancSottoAlbero(Nodo);
	bool isLeaf(Nodo); //se il nodo è foglia allora true altrimenti false

	tipoelem leggiNodo(Nodo);
	void scriviNodo(Nodo,tipoelem);

	void stampaAlbero();
	void stampaSottoAlbero(Nodo);
    void stampaPreOrdine(Nodo);//stampa l'albero dal Nodo in preordine
    void stampaPostOrdine(Nodo);//stampa l'albero dal Nodo in post Ordine
    void stampaSimmetrica(Nodo);//stamoa l'albero in simmetria dal Nodo
    int profondita(Nodo); //calcola la profondità dell'albero
    void stampaBFS(Nodo);//stampa in ampiezza dell'albero
    int larghezza(Nodo);
    int contaNodi(Nodo);
    void foglieK(Nodo u,int somma,int k);
    int numFoglie(Nodo);
    void n_livello(Nodo,int k,int&);
    bool pariDispari(Nodo);//verifica se ogni nodo pari ha solo figli dispari


    tipoelem maxAlbero(Nodo);//restituisce il valore massimo contenuto in albero
    int altezza(Nodo);//restituisce l'altezza dell'albero
    int nodiKfigli(Nodo,int k);//calcola il numero di nodi con k figli
    bool tuttiPari(Nodo);//verifica se tutti i valori dei nodi sono pari partendo dal Nodo
    int livello(Nodo);//restituisce il livello di un nodo
    bool trovaElemento(Nodo,T valore);//verifica che valore appartiene all'albero
    int altezzaMinimale(Nodo n);
    void cancellaPrimoFiglio(Nodo n);
    void cancellaSuccFratello(Nodo n);
    bool appartiene(Nodo u,Nodo n);//controlla se Nodo u appartiene all'albero partendo la ricerca dal Nodo n
   void somma_valori_sottoalbero(Nodo);//modifica l’albero in modo tale che l’etichetta di ogni nodo n corrisponda alla somma dei valori delle etichette dei nodi del sottoalbero radicato in n.
    int max_level(Nodo); // restituisce output il livello k dell’albero per il quale la somma di tutti i nodi di livello k `e massima
private:
    void max_level2(Nodo,int[]);
    int calcolaMax(int[],int);	//calcola il massimo in un array e restituisce la posizione
    void altezzaMinimale(Nodo n,int &minAltezza);
    Nodo radice;
    void deleteMarcato(Nodo);//mette a false tutti i nodi
};

template <class T>
Albero_Nario<T>::Albero_Nario(){
	crea();
}
template<class T>
void Albero_Nario<T>::crea(){
	radice = NULL;
}

template <class T>
bool Albero_Nario<T>::empty(){
	return radice == NULL;
}
template <class T>
void Albero_Nario<T>::insRadice(Nodo rad){
	if(empty())
		this->radice=rad;
}
template <class T>
typename Albero_Nario<T>::Nodo Albero_Nario<T>::radiceAlbero(){
	return this->radice;
}
template <class T>
typename Albero_Nario<T>::Nodo Albero_Nario<T>::padre(Nodo n){
	if(!empty())
		return n->getPadre();
	else
		return nullptr;
}
template<class T>
bool Albero_Nario<T>::isLeaf(Nodo n){
if(n->getPrimoFiglio()==NULL)
	return true;
else
	return false;
}
template <class T>
typename Albero_Nario<T>::Nodo Albero_Nario<T>::primoFiglio(Nodo n){
	return n->getPrimoFiglio();
}

template<class T>
bool Albero_Nario<T>::ultimoFratello(Nodo n){
	return n->getProxFratello()==NULL;
}

template<class T>
typename Albero_Nario<T>::Nodo Albero_Nario<T>::succFratello(Nodo n){
    return (n->getProxFratello());
}

template <class T>
void Albero_Nario<T>::insPrimoSottoAlbero(Nodo n,Albero_Nario<T>& tree){
	tree.radiceAlbero()->setProxFratello(n->getPrimoFiglio());
	tree.radiceAlbero()->setPadre(n);
	n->setPrimoFiglio(tree.radiceAlbero());
}

template <class T>
void Albero_Nario<T>::insSottoAlbero(Nodo n, Albero_Nario<T>& tree){
	tree.radiceAlbero()->setProxFratello(n->getProxFratello());
	tree.radiceAlbero()->setPadre(n->getPadre());
	n->setProxFratello(tree.radiceAlbero());
}
template <class T>
typename Albero_Nario<T>::tipoelem Albero_Nario<T>::leggiNodo(Nodo n){
	return n->getElemento();
}

template <class T>
void Albero_Nario<T>::scriviNodo(Nodo n,tipoelem a){
    n->setElemento(a);
}

template<class T>
void Albero_Nario<T>::stampaSottoAlbero(Nodo u){
    cout<<"\n "<<leggiNodo(u)<<" :";

        Nodo c=primoFiglio(u);
        while(c!=NULL){
            cout<<" "<<leggiNodo(c);
            c=succFratello(c);
        }
        c=primoFiglio(u);
        while(c!=NULL){
            stampaSottoAlbero(c);
            c=succFratello(c);
        }

}

template<class T>
void Albero_Nario<T>::stampaAlbero(){
    cout<<"\n*****STAMPA DELL'ALBERO*****\n";
    if(!empty()){
        cout<<"{\n";
        stampaSottoAlbero(radiceAlbero());
        cout<<"\n\n}";
    }
}
template <class T>
void Albero_Nario<T>::insPrimoFiglio(Nodo n){
	n->setPrimoFiglio(new Cella<T>);
	primoFiglio(n)->setPadre(n);
}
template<class T>
void Albero_Nario<T>::insFratello(Nodo n){
    n->setProxFratello(new Cella<T>);
    succFratello(n)->setPadre(padre(n));
}

template<class T>
void Albero_Nario<T>::stampaPreOrdine(Nodo u){
    Nodo temp;
    if(u!=NULL){
        cout<<" "<<leggiNodo(u);
        temp=primoFiglio(u);
        while(temp!=NULL){
            stampaPreOrdine(temp);
            temp=succFratello(temp);
        }
    }
    return;
}

template<class T>
void Albero_Nario<T>::stampaPostOrdine(Nodo u){
    Nodo temp;
    if(u!=NULL){
        temp=primoFiglio(u);
        while(temp!=NULL){
            stampaPostOrdine(temp);
            temp=succFratello(temp);
        }
    }
    cout<<" "<<leggiNodo(u);
    return;
}

template<class T>
void Albero_Nario<T>::cancSottoAlbero(Nodo n){
    cout<<"\nEntro nella procedura per eliminare nodo:"<<n->getElemento();
    //spezzo i legami tra n, il padre ed i fratelli
    if(radiceAlbero()==n)
        delete radiceAlbero();
    else{
        if(n==primoFiglio(padre(n))){//se n è il primo figlio
            if(ultimoFratello(n))//e non ha fratelli
                padre(n)->setPrimoFiglio(NULL);
            else//altrimenti ha un fratello che diventa primo figlio
                padre(n)->setPrimoFiglio(succFratello(n));
        }else{
            Nodo prec=primoFiglio(padre(n));
            Nodo current=succFratello(prec);
            while(current!=n){
                prec=current;
                current=succFratello(current);
            }
            if(ultimoFratello(n))
                prec->setProxFratello(NULL);
            else
                prec->setProxFratello(succFratello(n));
        }
    }
    delete n;
    contaNodi(radiceAlbero());
}
template<class T>
void Albero_Nario<T>::stampaSimmetrica(Nodo u){
    Nodo temp;
    if(isLeaf(u)){
        cout<<" "<<leggiNodo(u);
    }else{
        temp=primoFiglio(u);
        stampaSimmetrica(temp);
        cout<<" "<<leggiNodo(u);
        temp=succFratello(temp);
        while(temp!=NULL){
            stampaSimmetrica(temp);
            temp=succFratello(temp);
        }
    }
}

template<class T>
int Albero_Nario<T>::profondita(Nodo u){
    Nodo v;
    int massimo,temp;
    if(isLeaf(u))
        return 0;
    else{
        v=primoFiglio(u);
        massimo=0;
        while(v!=NULL){
            temp=profondita(v);
            if(massimo<=temp)
                massimo=temp;
            v=succFratello(v);
        }
        return massimo+1;
    }
}
template<class T>
void Albero_Nario<T>::deleteMarcato(Nodo n){
    Nodo temp;
    if(n!=NULL){
        if(n->getMarcato())
            n->desetMarcato();
        temp=primoFiglio(n);
        while(temp!=NULL){
            deleteMarcato(temp);
            temp=succFratello(temp);
        }
    }
    return;
}
/*
template<class T>
void Albero_Nario<T>::stampaBFS(Nodo v){
    deleteMarcato(radiceAlbero());//pone a false tutti i marcati
    Coda<Nodo> C(contaNodi(radiceAlbero()));
    C.inCoda(v);
    v->setMarcato();
    Nodo t;
    while(!C.codaVuota()){
        t=C.leggiCoda();
        C.fuoriCoda();
        cout<<" "<<leggiNodo(t)<<"("<<t->getNumNodi()<<")";
        Nodo u=primoFiglio(t);
        while(u!=NULL){
            if(!u->getMarcato()){
                u->setMarcato();
                C.inCoda(u);
            }
            u=succFratello(u);
        }
    }
}
*/

/*template<class T>
int Albero<T>::larghezza(Nodo t){
    if(t==NULL)
        return 0;
    int conteggio=1;
    int larghezza=1;
    Coda<Nodo> Q(30);
    Q.inCoda(t);
    while(!Q.codaVuota()){
        Nodo u=Q.leggiCoda();
        Q.fuoriCoda();
        Nodo v=primoFiglio(u);
        while(v!=NULL){
            Q.inCoda(v);
            v=succFratello(v);
        }
        conteggio=conteggio-1;
        if(conteggio==0){
            conteggio=Q.Size();
            larghezza=max(larghezza,conteggio);
        }
    }
    return larghezza;
}*/
template<class T>
int Albero_Nario<T>::contaNodi(Nodo u){
    int conteggio=0;
    Nodo temp;
    if(u!=NULL){
        if(isLeaf(u)){
            u->setNumNodi(1);
            conteggio++;
        }else{
            conteggio++;
            temp=primoFiglio(u);
            while(temp!=NULL){
                conteggio=conteggio+contaNodi(temp);
                temp=succFratello(temp);
            }
            u->setNumNodi(conteggio);
        }
    }
    return conteggio;
}


/*Dato un albero ordinato i cui nodi contengono valori interi
si vogliono cancellare tutte le foglie per il quale il percorso radice-foglia
ha somma complessiva uguale a k*/
template<class T>
void Albero_Nario<T>::foglieK(Nodo u,int somma,int k){
    Nodo v;
    if(!isLeaf(u)){
        v=primoFiglio(u);
        while(v!=NULL){
            foglieK(v,somma+ leggiNodo(u),k);
            v=succFratello(v);
        }
    }else{
        if(somma+leggiNodo(u)==k)
            cancSottoAlbero(u);
    }
}
template<class T>
T Albero_Nario<T>::maxAlbero(Nodo n){
	tipoelem massimo = 0;
   if(!empty()){
    tipoelem currMax;
    tipoelem massimo=n->getElemento();
    Nodo temp=primoFiglio(n);
    while(temp!=NULL){
        currMax=maxAlbero(temp);
        if(currMax>massimo)
            massimo=currMax;
        temp=succFratello(temp);
    }
   }
    return massimo;
}

template<class T>
int Albero_Nario<T>::altezza(Nodo n){
    int maxAltezza=0;
    Nodo temp=primoFiglio(n);
    while(temp!=NULL){
        int t=altezza(temp)+1;
        if(t>maxAltezza)
            maxAltezza=t;
        temp=succFratello(temp);
    }
    return maxAltezza;
}
template<class T>
int Albero_Nario<T>::nodiKfigli(Nodo n,int k){
    int k1=0;
    Nodo temp;
    if(n==NULL)
        return 0;
    else{

        temp=primoFiglio(n);
        while(temp!=NULL){
            k1++;
            temp=succFratello(temp);
        }
        if(k==k1)
            return(1+nodiKfigli(succFratello(n),k)+nodiKfigli(primoFiglio(n),k));
        else
            return (nodiKfigli(succFratello(n),k)+nodiKfigli(primoFiglio(n),k));
    }
}
template<class T>
int Albero_Nario<T>::livello(Nodo n){
    int Level;
    //restituisce il livello di n
    //se n è radice il livello è 0
    if(n==radiceAlbero())
        return 0;
    else{
        Level=1;
        Nodo temp=padre(n);
        while(temp!=radiceAlbero()){
            Level++;
            temp=padre(temp);
        }
    }
    return Level;
}
/*restituisci il numero di nodi di livello k*/
template<class T>
void Albero_Nario<T>::n_livello(Nodo u,int k,int& numero){
    Nodo temp;
    if(u!=NULL){
        if(livello(u)==k){
            numero++;
        }
        temp=primoFiglio(u);
        while(temp!=NULL){
            n_livello(temp,k,numero);
            temp=succFratello(temp);
        }
    }
    return;
}

template<class T>
bool Albero_Nario<T>::appartiene(Nodo u,Nodo n){
    Nodo temp;
    bool trovato=false;
    if(n==NULL)
        return false;
    if(n==u)
        return true;
    temp=primoFiglio(n);
    while(temp!=NULL && !trovato){
        if(appartiene(u,temp))
                trovato=true;
        temp=succFratello(temp);
    }
    return trovato;
}
template<class T>
bool Albero_Nario<T>::trovaElemento(Nodo n,T valore){
    Nodo temp;
    bool trovato=false;
    if(n==NULL)
        return false;
    if(leggiNodo(n)==valore)
        return true;
    temp=primoFiglio(n);
    while(temp!=NULL && !trovato){
        if(trovaElemento(temp,valore))//una volta che lo ha trovato,tutti i trovato nella funzioni ricorsive vanno a true
            trovato=true;
        temp=succFratello(temp);
    }
    return trovato;
}

template<class T>
void Albero_Nario<T>::altezzaMinimale(Nodo n,int &minAltezza){
    Nodo temp;
    int current=0;
    if(n!=NULL){
        if(isLeaf(n)){
            current=livello(n);
            if(current<=minAltezza)
                minAltezza=current;
        }else{
           temp=primoFiglio(n);
            while(temp!=NULL){
                altezzaMinimale(temp,minAltezza);
                temp=succFratello(temp);
            }
        }
    }
    return;
}

template<class T>
int Albero_Nario<T>::altezzaMinimale(Nodo n){
    int minAltezza=altezza(n);
    altezzaMinimale(n,minAltezza);
    return minAltezza;
}


template<class T>
void Albero_Nario<T>::cancellaPrimoFiglio(Nodo n){
    if(isLeaf(n))
        return;
    else{
        Nodo temp=primoFiglio(n);
        delete primoFiglio(n);
        n->setPrimoFiglio(succFratello(temp));
    }
}

template<class T>
void Albero_Nario<T>::cancellaSuccFratello(Nodo n){
    if(succFratello(n)==NULL)
        return;
    else{
        Nodo temp=succFratello(n);
        delete succFratello(n);
        n->setProxFratello(succFratello(temp));
    }
}

/*Verifica se ogni nodo pari ha solo figli dispari*/
template<class T>
bool Albero_Nario<T>::pariDispari(Nodo n){
    Nodo temp;
    bool ris=true;
    if(n==NULL)
        return true;
    if(leggiNodo(n)%2){
        temp=primoFiglio(n);
        while(temp!=NULL){
            ris=ris &&pariDispari(temp);
            temp=succFratello(temp);
        }
        return ris;
    }else{
        temp=primoFiglio(n);
        while(temp!=NULL){
            ris=ris && (leggiNodo(temp)%2) && pariDispari(temp);
            temp=succFratello(temp);
        }
        return ris;
    }
}

template <class T>
int Albero_Nario<T>::max_level(Nodo nodo){

	int array[altezza(radiceAlbero())+1];
	array[0] = leggiNodo(radiceAlbero());
	for(int i=0;i<altezza(radiceAlbero())+1;i++){
		array[i] = 0;
	}
	max_level2(nodo,array);
	return calcolaMax(array,altezza(radiceAlbero())+1);
}

template<class T>
void Albero_Nario<T>::max_level2(Nodo nodo, int array[]){
	typename Albero_Nario<int>::Nodo n;
	array[livello(nodo)] += leggiNodo(nodo);

	n = primoFiglio(nodo);
	while(n!=NULL){
		max_level2(n,array);
		n = succFratello(n);
	}

}

/*
 * Calcolo della posizione del massimo all'interno di un array
 */
template<class T>
int Albero_Nario<T>::calcolaMax(int array[],int dim){
	int max = 0;
	for(int i = 0;i<dim;i++){
		cout << " " <<array[i];
		if(array[i]>=max){
			max = i;
		}
	}
	cout << endl;
	return max+1;
}

template<class T>
void Albero_Nario<T>::somma_valori_sottoalbero(Nodo n){
	int somma = 0;
	Albero_Nario<int>::Nodo nodo = primoFiglio(n);

	while(nodo!=NULL){
		somma_valori_sottoalbero(nodo);
		nodo = succFratello(nodo);
	}

	nodo = primoFiglio(n);
	while(nodo!=NULL){
		somma += leggiNodo(nodo);
		nodo = succFratello(nodo);
	}

	nodo = primoFiglio(n);
	if(!isLeaf(n) && nodo != radiceAlbero())
		scriviNodo(n,somma);

}


#endif /* ALBERO_NARIO_H_ */
