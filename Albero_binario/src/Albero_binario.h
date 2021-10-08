/*
 * Albero_binario.h
 *
 *  Created on: 8 ott 2020
 *      Author: daniele
 */

#ifndef ALBERO_BINARIO_H_
#define ALBERO_BINARIO_H_

#include <iostream>
#include "Cella.h"
#include <limits.h>
#include "Linked_list.h"
#include <vector>

using namespace std;

template <class T>
class Albero_binario{
public:
	typedef T tipoelem;
	typedef Cella<T>* Nodo;	//puntatore ad una cella
	Albero_binario();//costruttore
//	~Albero_binario();//distruttore

	//operatori
	void crea();
	bool empty();
	Nodo radiceAlbero();//restituisce la radice
	Nodo dad(Nodo);//restituisce il padre
	Nodo figlioSX(Nodo);//restituisce il figlio sinistro del nodo
	Nodo figlioDX(Nodo);//restituisce il figlio destro del nodo
	bool sinistroEmpty(Nodo);
	bool destroEmpty(Nodo);
	void cancSottoAlbero(Nodo);//cancella il sottoalbero che ha come radice il nodo
	tipoelem leggiNodo(Nodo);//restituisce l'elemento del nodo
    void scriviNodo(Nodo,tipoelem); //Scrive l'elemento nel nodo
    void insRadice(Nodo);
    void insFiglioSX(Nodo n);
    void insFiglioDX(Nodo n);
    void stampaSottoAlbero(Nodo n);
    void stampa();

    //servizio
    int count(Nodo n);//restituisce il numero di nodi del sottoalbero che ha come radice n
    int altezza(Nodo n);//restituisce l'altezza del nodo n
    int livello(Nodo n);//restituisce il livello del nodo n
    void modificaNumeroNodi(Nodo n);
    int livello_n(Nodo,int k);//restituisce il numero di nodi di livello k
    bool is_height_balanced(Nodo);//stabilisce se è bilanciato in altezza
    bool isLeaf(Nodo);//true se il nodo è foglia false altrimenti
    int altezza_minimale(Nodo);//altezza minimale dal nodo ad una delle sue foglie
    int larghezza(Nodo);
    int lunghezzaDiCammino(Nodo,int);//somma delle distanze dai nodi alla radice
    void creaSottoAlbero(Albero_binario<T> tree, Nodo n, Nodo current);//crea un sottoalbero a partire dal nodo n in tree
    void inserisciSottoAlberoASinistraDelNodo(Albero_binario<T> subTree, Nodo n, Nodo d);//inserisce il sottoalbero subTree in this a partire dal nodo sinistro di n, in cui il nodo d è la radice del sottoalbero subTree
    void inserisciSottoAlberoADestraDelNodo(Albero_binario<T> subTree,Nodo n,Nodo d);//inserisce il sottoalbero subtree in this a partire dal nodo destro di n,in cui il nodo d è la radice del sotto albero subtree
    void inserisciSottoAlbero(Albero_binario,Nodo,Nodo);
    void mutate(Albero_binario<T>& tree1, Albero_binario<T>& tree2, Nodo n1, Nodo n2);//scambia i sottoalberi che hanno radice in n1 per tree1 e n2 per tree2
    //int multipli(Albero_binario<int>&);
    int multipli(Albero_binario<T>&);	//modifica l’etichetta di ogni nodo n dell’albero memorizzandoci il numero dei nodi pari presenti nel sottoalbero radicato in n
    int oddDispari(Albero_binario<T>&,int k);	//restituisce il numero di nodi di livello k il cui valore è dispari
    int oddPari(Albero_binario<T>&,int k); //restituisce il numero di nodi di livello k il cui valore è pari
    bool esiste(Albero_binario<T>&,int);	//dato un nodo ricerca un valore nell'albero
    int even_leafs(Albero_binario<T>); //calcola e restituisce il numero di foglie il cui valore è pari
    int leafs_with_even_parent(Albero_binario<int>&);// calcola e restituisce il numero di foglie che hanno come genitore un nodo il cui valore è pari.
    bool is_zero_one(Albero_binario<T>&); //stabilisce se l'albero rispetta le proprietà di un'albero zero-one (ogni nodo che ha etichetta 1, ha figli con etichetta 0 e viceversa
    int zero_nodes(Albero_binario<T>&); //restituisce il numero di nodi nell'albero che hanno etichetta 0
    Linked_list<double> values_average(Albero_binario<T>&); //metodo che restituisce una lista. nella posizione i ci sarà la media dei valori del livello i
    //stampa
    void stampaPreOrdine(Nodo n);
    void stampaPostOrdine(Nodo n);
    void stampaSimmetrica(Nodo n);

private:
    void larghezza(Nodo,vector<T>&,int);
    void is_height_balanced(Nodo,bool&);
    int numeroElementi;
    Nodo radice;
};

template<class T>
Albero_binario<T>::Albero_binario(){
	crea();
}
template<class T>
void Albero_binario<T>::crea(){
	numeroElementi=0;
	this->radice=NULL;	//empty
}
template<class T>
bool Albero_binario<T>::empty(){
	return radice==NULL;
}
template<class T>
typename Albero_binario<T>::Nodo Albero_binario<T>::radiceAlbero(){
	return radice;
}
template<class T>
typename Albero_binario<T>::Nodo Albero_binario<T>::dad(Nodo n){
	if(n!=radice)
		return n->getDAD();
	else
		return NULL;
}
template<class T>
typename Albero_binario<T>::Nodo Albero_binario<T>::figlioDX(Nodo n){
	return n->getDX();
}
template<class T>
typename Albero_binario<T>::Nodo Albero_binario<T>::figlioSX(Nodo n){
	return n->getSX();
}
template<class T>
bool Albero_binario<T>::sinistroEmpty(Nodo n){
	return n->getSX()==NULL;
}
template<class T>
bool Albero_binario<T>::destroEmpty(Nodo n){
	return n->getDX()==NULL;
}
template<class T>
void Albero_binario<T>::insRadice(Nodo n){
	if(empty()){	//solo se vuoto posso inserire nella radice
		radice=n;
	}
}
template<class T>
void Albero_binario<T>::insFiglioSX(Nodo n){
	if(sinistroEmpty(n)){
		n->setSX(new Cella<T>);	//setto il figlio sinistro di n (nuova cella creata al momento)
		//adesso configuro chi è il padre del figlio sinistro e
		//imposto a NULL i figli che per l'appunto non ha
		n->getSX()->setDad(n);
		n->getSX()->setDX(NULL);
		n->getSX()->setSX(NULL);
	}
}
template<class T>
void Albero_binario<T>::insFiglioDX(Nodo n){
	if(destroEmpty(n)){
		n->setDX(new Cella<T>);
		n->getDX()->setDad(n);
		n->getDX()->setDX(NULL);
		n->getDX()->setSX(NULL);
	}
}
template<class T>
typename Albero_binario<T>::tipoelem Albero_binario<T>::leggiNodo(Nodo n) {
	if(n!=NULL)
	return n->getElemento();
}
template<class T>
void Albero_binario<T>::scriviNodo(Nodo n,tipoelem e){
	if(n!=NULL){
		n->setElemento(e);
		numeroElementi++;
	}
}
template<class T>
void Albero_binario<T>::cancSottoAlbero(Nodo n){
	if(n!=NULL){
		if(!sinistroEmpty(n)){
			cancSottoAlbero(figlioSX(n));
		}
		if(!destroEmpty(n)){
			cancSottoAlbero(figlioDX(n));
		}
		if(n!=radice){
			Nodo padre = dad(n);
			if(figlioSX(padre)==n){
				padre->setSX(NULL);
			}else if(figlioDX(padre)==n){
				padre->setDX(NULL);
			}
		}
	  numeroElementi--;
	}
	 if(!empty())
	        modificaNumeroNodi(radiceAlbero());
}

template <class T>
void Albero_binario<T>::stampaSottoAlbero(Nodo n){
	cout<<"["<<n->getElemento()<< "    "<<"("<<n->getNumeroNodi()<<")"<<",";
	if(!sinistroEmpty(n))
		stampaSottoAlbero(figlioSX(n));
	else
		cout<<"NULL";
	cout<<", ";
	if(!destroEmpty(n))
		stampaSottoAlbero(figlioDX(n));
	else
		cout<<"NULL";
	cout<<"]";
}
template<class T>
void Albero_binario<T>::stampa(){
	if(!empty())
		stampaSottoAlbero(radice);
	else
		cout<<"[]"<<endl;
	cout<<endl;
}
template<class T>
int Albero_binario<T>::count(Nodo n){
	int sx = 0,dx = 0;
	if(!sinistroEmpty(n))
		sx = count(figlioSX(n));
	if(!destroEmpty(n))
		dx = count(figlioDX(n));
	return sx+dx+1;
}
template <class T>
int Albero_binario<T>::altezza(Nodo n){
	if(sinistroEmpty(n)&&destroEmpty(n))
		return 0;
	int hsx=0,hdx=0;
	if(!sinistroEmpty(n))
		hsx=altezza(figlioSX(n));
	if(!destroEmpty(n))
		hdx=altezza(figlioDX(n));
	if(hsx<hdx)
		return hsx+1;
	else
		return hdx+1;
}
template<class T>
int Albero_binario<T>::livello(Nodo n){
	int l=0;
	if(n==radice)
		return l;
	else
		l = livello(dad(n));
	return l+1;
}
template<class T>
void Albero_binario<T>::modificaNumeroNodi(Nodo n){
	if(!empty()){
		if(n!=NULL){
			n->setNumeroNodi(count(n));
			modificaNumeroNodi(figlioSX(n));
			modificaNumeroNodi(figlioDX(n));
		}
	}
}
template<class T>
int Albero_binario<T>::livello_n(Nodo n, int k){
	if(n==NULL)
     return 0;
	if(k==0)
	 return 1;
	return livello_n(figlioSX(n),k-1)+livello_n(figlioDX(n),k-1);

}
template<class T>
bool Albero_binario<T>::is_height_balanced(Nodo n){
    bool ris=false;
    is_height_balanced(n,ris);
    return ris;
}

template<class T>
void Albero_binario<T>::is_height_balanced(Nodo n,bool& ris){
     if(!empty() || !ris){
        if(n!=NULL && figlioSX(n)!=NULL && figlioDX(n)!= NULL){
            if((altezza(figlioSX(n))-altezza(figlioDX(n)))>1 || (altezza(figlioDX(n))-altezza(figlioSX(n)))>1)
                ris=false;
            else
                ris=true;
            (is_height_balanced(figlioSX(n),ris));
            (is_height_balanced(figlioDX(n),ris));
        }
    }
}
template<class T>
bool Albero_binario<T>::isLeaf(Nodo n){
    if(figlioSX(n)==NULL && figlioDX(n)==NULL)
        return true;
    else
    	return false;
}

template<class T>
int Albero_binario<T>::altezza_minimale(Nodo n){
    int h1,hr;
    if(n==NULL)
        return UINT_MAX;
    if(isLeaf(n))
        return 0;
    h1=altezza_minimale(figlioSX(n));
    hr=altezza_minimale(figlioDX(n));
    return min(h1,hr)+1;
}

template<class T>
void Albero_binario<T>::larghezza(Nodo t,vector<T>& conteggio,int level){
    if(t!=NULL){
        conteggio[level]=conteggio[level]+1;
        larghezza(figlioSX(t),conteggio,level+1);
        larghezza(figlioDX(t),conteggio,level+1);
    }
}
template<class T>
int Albero_binario<T>::larghezza(Nodo t){
    vector<T> conteggio(30,0);
    larghezza(t,conteggio,0);
    int maxC=0;
    for(int i=0;i<=numeroElementi;i++){
        if(conteggio[i]>=maxC)
            maxC=conteggio[i];
    }
    return maxC;
}

template<class T>
int Albero_binario<T>::lunghezzaDiCammino(Nodo n,int l){
    if(n==NULL)
        return 0;
    return l+lunghezzaCammino(figlioSX(n),l+1)+lunghezzaCammino(figlioDX(n),l+1);
}
template<class T>
void Albero_binario<T>::stampaPreOrdine(Nodo n){
    if(!empty()){
        if(n!=NULL){
            cout<<n->getElemento()<<" ";
            stampaPreOrdine(figlioSX(n));
            stampaPreOrdine(figlioDX(n));
        }
    }
}

template<class T>
void Albero_binario<T>::stampaPostOrdine(Nodo n){
    if(n==NULL)
        return;
    stampaPostOrdine(figlioSX(n));
    stampaPostOrdine(figlioDX(n));
    cout<<n->getElemento()<<" ";
}

template<class T>
void Albero_binario<T>::stampaSimmetrica(Nodo n){
    if(n==NULL)
        return;
    stampaSimmetrica(figlioSX(n));
    cout<<n->getElemento()<<" ";
    stampaSimmetrica(figlioDX(n));
}

//Nodo corrente sarà la radice del sottoalbero
/*crea un sottoalbero di tree che ha come radice il nodo n*/
template<class T>
void Albero_binario<T>::creaSottoAlbero(Albero_binario<T> tree,Nodo n,Nodo corrente){
   this->scriviNodo(corrente,tree.leggiNodo(n));
   if(!tree.sinistroEmpty(n)){
        if(this->sinistroEmpty(corrente)){
            this->insFiglioSX(corrente);
        }
        creaSottoAlbero(tree,tree.figlioSX(n),this->figlioSX(corrente));
   }
   if(!tree.destroEmpty(n)){
        if(this->destroEmpty(corrente)){
            this->insFiglioDX(corrente);
        }
        creaSottoAlbero(tree,tree.figlioDX(n),this->figlioDX(corrente));
   }
   this->modificaNumeroNodi(this->radiceAlbero());
}

template<class T>
void Albero_binario<T>::inserisciSottoAlbero(Albero_binario<T> subtree,Nodo n,Nodo d){
    this->scriviNodo(n,subtree.leggiNodo(d));
    if(!subtree.sinistroEmpty(d)){
        if(this->sinistroEmpty(n)){
            this->insFiglioSX(n);
        }
        inserisciSottoAlbero(subtree,this->figlioSX(n),subtree.figlioSX(d));
    }
    if(!subtree.destroEmpty(d)){
        if(this->destroEmpty(n)){
            this->insFiglioDX(n);
        }
        inserisciSottoAlbero(subtree,this->figlioDX(n),subtree.figlioDX(d));
    }
}

template<class T>
void Albero_binario<T>::inserisciSottoAlberoASinistraDelNodo(Albero_binario<T> subtree,Nodo n,Nodo d){
    if(this->sinistroEmpty(n)){
        this->insFiglioSX(n);
        inserisciSottoAlbero(subtree,this->figlioSX(n),subtree.radiceAlbero());
        this->modificaNumeroNodi(this->radiceAlbero());
    }else{
        cout<<"L'operazione non puo' essere eseguita";
    }
}

template<class T>
void Albero_binario<T>::inserisciSottoAlberoADestraDelNodo(Albero_binario<T> subtree,Nodo n,Nodo d){
    if(this->destroEmpty(n)){
        this->insFiglioDX(n);
        inserisciSottoAlbero(subtree,this->figlioDX(n),subtree.radiceAlbero());
        this->modificaNumeroNodi(this->radiceAlbero());
    }else{
        cout<<"L'operazione non puo' essere eseguita";
    }
}

template<class T>
void Albero_binario<T>::mutate(Albero_binario<T>& tree1,Albero_binario<T>& tree2,Nodo n1,Nodo n2){
	Albero_binario<T> sub1,sub2;
    sub1.insRadice(new Cella<T>);
    sub2.insRadice(new Cella<T>);
    sub1.creaSottoAlbero(tree1,n1,sub1.radiceAlbero());
    sub2.creaSottoAlbero(tree2,n2,sub2.radiceAlbero());
    Albero_binario<T>::Nodo padre1,padre2;
    padre1=tree1.dad(n1);
    padre2=tree1.dad(n2);
    int SxOrDx1,SxOrDx2; //flag
    if(n1==tree1.dad(n1)->getSX())
        SxOrDx1=0;//è un nodo sinistro
    else
        SxOrDx1=1;//è un nodo destro
    if(n2==tree1.dad(n2)->getSX())
        SxOrDx2=0;
    else
        SxOrDx2=1;
    tree1.cancSottoAlbero(n1);
    tree2.cancSottoAlbero(n2);
    if(SxOrDx2==0)
        tree2.inserisciSottoAlberoASinistraDelNodo(sub1,padre2,sub1.radiceAlbero());
    else
        tree2.inserisciSottoAlberoADestraDelNodo(sub1,padre2,sub1.radiceAlbero());
    if(SxOrDx1==0)
        tree1.inserisciSottoAlberoASinistraDelNodo(sub2,padre1,sub2.radiceAlbero());
    else
        tree1.inserisciSottoAlberoASinistraDelNodo(sub2,padre1,sub2.radiceAlbero());
    tree1.modificaNumeroNodi(tree1.radiceAlbero());
    tree2.modificaNumeroNodi(tree2.radiceAlbero());

}
/*
template<class T>
int Albero_binario<T>::multipli(Albero_binario<int>& tree){
	int multi = 0;
	if(!tree.empty()){
		if(leggiNodo(figlioSX(tree.radiceAlbero()))%2==0 && leggiNodo(figlioDX(tree.radiceAlbero()))%2==0)
			multi+=2;
		else if ((leggiNodo(figlioSX(tree.radiceAlbero()))%2==0 && !(leggiNodo(figlioDX(tree.radiceAlbero()))%2==0)) || !(leggiNodo(figlioSX(tree.radiceAlbero()))%2==0 && leggiNodo(figlioDX(tree.radiceAlbero()))%2==0))
			multi+=1;
	}else
		return multi;
	if(!tree.sinistroEmpty(tree.radiceAlbero())){
		Albero_binario<int> Tr;
		Albero_binario<int>::Nodo figliosinistro = tree.figlioSX(tree.radiceAlbero());
		Tr.radice = figliosinistro;
		multipli(Tr);
	}
	if(!tree.destroEmpty(tree.radiceAlbero())){
		Albero_binario<int> Tr;
		Albero_binario<int>::Nodo figliodestro = tree.figlioDX(tree.radiceAlbero());
		Tr.radice = figliodestro;
		multipli(Tr);
	}
	tree.scriviNodo(tree.radiceAlbero(),multi);

	return multi;
}
*/

template<class T>
int Albero_binario<T>::multipli(Albero_binario<T>& tree){
	int multi = 0;
	if(!empty() && tree.radiceAlbero()!=NULL){
		Albero_binario<T> subtree;
		if(sinistroEmpty(tree.radiceAlbero()) && destroEmpty(tree.radiceAlbero()))
			return leggiNodo(tree.radiceAlbero());
		else{
			if(!sinistroEmpty(tree.radiceAlbero()) && destroEmpty(tree.radiceAlbero())){
				if(leggiNodo(figlioSX(tree.radiceAlbero()))%2==0)
					multi=1;
				subtree.radice = figlioSX(tree.radiceAlbero());
				multipli(subtree);
			}
			else if(sinistroEmpty(tree.radiceAlbero()) && !destroEmpty(tree.radiceAlbero())){
				if(leggiNodo(figlioDX(tree.radiceAlbero()))%2==0)
					multi=1;
				subtree.radice = figlioDX(tree.radiceAlbero());
				multipli(subtree);
			}else{
				if(leggiNodo(figlioSX(tree.radiceAlbero()))%2==0 && leggiNodo(figlioDX(tree.radiceAlbero()))%2==0)
					multi=2;
				else if(leggiNodo(figlioSX(tree.radiceAlbero()))%2==0 && !leggiNodo(figlioDX(tree.radiceAlbero()))%2==0)
					multi=1;
				else if(!leggiNodo(figlioSX(tree.radiceAlbero()))%2==0 && leggiNodo(figlioDX(tree.radiceAlbero()))%2==0)
					multi=1;
				else
					return leggiNodo(tree.radiceAlbero());
				subtree.radice = figlioSX(tree.radiceAlbero());
				multipli(subtree);
				subtree.radice = figlioDX(tree.radiceAlbero());
				multipli(subtree);
			}
		}
		scriviNodo(tree.radiceAlbero(),multi);
	}
	return multi;
}

template<class T>
bool Albero_binario<T>::esiste( Albero_binario<T>& tree, int num){
	bool boole;
	if(!empty()){
	    if(leggiNodo(tree.radiceAlbero())==num){
			return true;
		}else{
			Albero_binario<T> subtree;
			if(!sinistroEmpty(tree.radiceAlbero()))
				subtree.radice = figlioSX(tree.radiceAlbero());
				boole = esiste(subtree,num);
			if(!destroEmpty(tree.radiceAlbero()) && !esiste(subtree,num))
				subtree.radice = figlioDX(tree.radiceAlbero());
				boole = esiste(subtree,num);
		}

	}else boole=false;
	return boole;
}

template<class T>
int Albero_binario<T>::oddDispari(Albero_binario<T>& tree,int k){
	int num = 0;
	if(!empty()){
		Albero_binario<T> subtree;
		if(livello(tree.radiceAlbero())==k && leggiNodo(tree.radiceAlbero())%2!=0)
			return num+=1 ;
		else{
			if(!sinistroEmpty(tree.radiceAlbero())){
				subtree.radice = figlioSX(tree.radiceAlbero());
				num += oddDispari(subtree,k);
			}
			if(!destroEmpty(tree.radiceAlbero())){
				subtree.radice = figlioDX(tree.radiceAlbero());
				num += oddDispari(subtree,k);
			}
		}
	}
	return num;
}

template <class T>
int Albero_binario<T>::oddPari(Albero_binario<T>& tree, int k){
	int num = 0;
	if(!empty()){
		Albero_binario<T> subtree;
		if(livello(tree.radiceAlbero())==k && leggiNodo(tree.radiceAlbero())%2==0)
			return num+=1 ;
		else{
			if(!sinistroEmpty(tree.radiceAlbero())){
				subtree.radice = figlioSX(tree.radiceAlbero());
				num += oddPari(subtree,k);
			}
			if(!destroEmpty(tree.radiceAlbero())){
				subtree.radice = figlioDX(tree.radiceAlbero());
				num += oddPari(subtree,k);
			}
		}
	}
	return num;
}


template <class T>
int Albero_binario<T>::even_leafs(Albero_binario<T> tree){
	int num = 0;
	if(!empty()){
		Albero_binario<T> subtree;
		if(isLeaf(tree.radiceAlbero()) && leggiNodo(tree.radiceAlbero())%2==0)
			return num+=1;
		else{
			if(!sinistroEmpty(tree.radiceAlbero())){
				subtree.radice = figlioSX(tree.radiceAlbero());
				num += even_leafs(subtree);
			}
			if(!destroEmpty(tree.radiceAlbero())){
				subtree.radice = figlioDX(tree.radiceAlbero());
				num += even_leafs(subtree);
			}
		}
	}
	return num;
}

template<class T>
int Albero_binario<T>::leafs_with_even_parent(Albero_binario<int>& tree){
	int num = 0;
	if(!empty()){
		if(leggiNodo(tree.radiceAlbero())%2==0 && !isLeaf(tree.radiceAlbero())){
			if(!sinistroEmpty(tree.radiceAlbero()) && isLeaf(figlioSX(tree.radiceAlbero()))){
				num+=1;
			}
			if(!destroEmpty(tree.radiceAlbero()) && isLeaf(figlioDX(tree.radiceAlbero()))){
				num+=1;
			}
		}else{
			Albero_binario<T> subtree;
			if(!sinistroEmpty(tree.radiceAlbero())){
				subtree.radice = figlioSX(tree.radiceAlbero());
				num += leafs_with_even_parent(subtree);
			}
			if(!destroEmpty(tree.radiceAlbero())){
				subtree.radice = figlioDX(tree.radiceAlbero());
				num += leafs_with_even_parent(subtree);
			}
		}
	}
	return num;
}

template <class T>
bool Albero_binario<T>::is_zero_one(Albero_binario<T>& tree){
	bool risp = false;
	if(leggiNodo(tree.radiceAlbero()) == 0 && !isLeaf(tree.radiceAlbero())){
		if(leggiNodo(figlioSX(tree.radiceAlbero()))==1 && leggiNodo(figlioDX(tree.radiceAlbero()))==1)
			return risp = true;
	}else if(leggiNodo(tree.radiceAlbero()) == 1 && !isLeaf(tree.radiceAlbero())){
		if(leggiNodo(figlioSX(tree.radiceAlbero()))==0 && leggiNodo(figlioDX(tree.radiceAlbero()))==0)
			return risp = true;
	}


	Albero_binario<T> subtree;
	if(!sinistroEmpty(tree.radiceAlbero())){
		subtree.radice = figlioSX(tree.radiceAlbero());
		risp = is_zero_one(subtree);
	}
	if(!destroEmpty(tree.radiceAlbero())){
		subtree.radice = figlioDX(tree.radiceAlbero());
		risp = is_zero_one(subtree);
	}
	return risp;
}

template <class T>
int Albero_binario<T>::zero_nodes(Albero_binario<T>& tree){
	int num = 0;
	if(leggiNodo(tree.radiceAlbero()) == 0)
		return num++;

	Albero_binario<T> subtree;
	if(!sinistroEmpty(tree.radiceAlbero())){
		subtree.radice = figlioSX(tree.radiceAlbero());
		num += zero_nodes(subtree);
	}
	if(!destroEmpty(tree.radiceAlbero())){
		subtree.radice = figlioDX(tree.radiceAlbero());
		num += zero_nodes(subtree);
	}
	return num;
}

template<class T>
Linked_list<double> Albero_binario<T>::values_average(Albero_binario<T>& tree){
	Linked_list<double> list;
	Linked_list<double>::position p = list.begin();


	Albero_binario<T> subtree;
	if(!sinistroEmpty(tree.radiceAlbero())){
		subtree.radice = figlioSX(tree.radiceAlbero());
		list.insert(values_average(subtree),p);
	}
	if(!destroEmpty(tree.radiceAlbero())){
		subtree.radice = figlioDX(tree.radiceAlbero());
		list.insert(values_average(subtree),p);
	}
	return list;
}


#endif /* ALBERO_BINARIO_H_ */
