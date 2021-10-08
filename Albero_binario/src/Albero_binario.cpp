#include <iostream>
#include<stdlib.h>
#include "Albero_binario.h"
#include "cella.h"


using namespace std;

int main()
{
/*
    Albero_binario<int> Tree;
    /*Poichè il puntatore NULL non può puntare a niente, utilizzo
    l'operatore "new" che mi crea un puntatore non NULL da assegnare
    alla radice di Tree



    typename Albero_binario<int>::Nodo radice;
    radice=new Cella<int>;



    Tree.insRadice(radice);
    Tree.scriviNodo(Tree.radiceAlbero(),2345);
    cout<<"         L'elemento radice dell'albero binario e': "<<Tree.radiceAlbero()->getElemento();
    Tree.insFiglioSX(Tree.radiceAlbero());
    Tree.insFiglioDX(Tree.radiceAlbero());
    Tree.scriviNodo(Tree.figlioSX(Tree.radiceAlbero()),234);
    Tree.scriviNodo(Tree.figlioDX(Tree.radiceAlbero()),235);
    cout<<"\n\n         Il figlio sinistro della radice dell'albero binario e': "<<Tree.figlioSX(Tree.radiceAlbero())->getElemento();
    cout<<"\n\n         Il figlio destro della radice dell'albero binario e': "<<Tree.figlioDX(Tree.radiceAlbero())->getElemento();
    radice=Tree.figlioDX(Tree.radiceAlbero());
    Tree.insFiglioSX(radice);
    Tree.scriviNodo(Tree.figlioSX(radice),345);
    cout<<"\n\n         Il figlio sinistro del nodo 235 e': "<<Tree.figlioSX(radice)->getElemento();
    Tree.modificaNumeroNodi(Tree.radiceAlbero());
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE **********************";
    cout<<"\n\n         ";
    Tree.stampa();
    cout<<"\n\n         L'altezza minimale dell'albero e':"<<Tree.altezza_minimale(Tree.radiceAlbero());
    int k=1;
    cout<<"\n\n         Il numero di nodi di livello "<<k<<" e':"<<Tree.livello_n(Tree.radiceAlbero(),k);
    cout<<"\n\n         Stampa in preordine: ";
    Tree.stampaPreOrdine(Tree.radiceAlbero());
    cout<<"\n\n         Stampa in postordine: ";
    Tree.stampaPostOrdine(Tree.radiceAlbero());
    cout<<"\n\n         Stampa simmetrica: ";
    Tree.stampaSimmetrica(Tree.radiceAlbero());
    cout<<"\n\n         Il numero di nodi del sottoalbero con radice in figlioSX di radice e':"<<Tree.count(Tree.figlioSX(Tree.radiceAlbero()));
    cout<<"\n\n         Il numero di nodi del sottoalbero con radice in figlioDX di radice e':"<<Tree.count(Tree.figlioDX(Tree.radiceAlbero()));
    Tree.cancSottoAlbero(Tree.figlioSX(Tree.radiceAlbero()));
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE(dopo canc figlio sx di radice) **********************";
    cout<<"\n\n         ";
    Tree.stampa();
    cout<<"\n\n         L'altezza del figlio destro della radice e': "<<Tree.altezza(Tree.figlioDX(Tree.radiceAlbero()));
    radice=Tree.figlioDX(Tree.radiceAlbero());
    cout<<"\n\n         L'altezza del figlio sinistro del figlio destro della radice e': "<<Tree.altezza(Tree.figlioSX(radice));
    cout<<"\n\n         L'altezza della radice e': "<<Tree.altezza(Tree.radiceAlbero());
    cout<<"\n\n         Il livello del figlio destro della radice e': "<<Tree.livello(Tree.figlioDX(Tree.radiceAlbero()));
    cout<<"\n\n         Il livello del figlio sinistro del figlio destro della radice e': "<<Tree.livello(Tree.figlioSX(radice));
    cout<<"\n\n         Il livello della radice e': "<<Tree.livello(Tree.radiceAlbero());
    Albero_binario<int> sub1;
    typename Albero_binario<int>::Nodo radiceSub;
    radiceSub=new Cella<int>;
    sub1.insRadice(radiceSub);
    sub1.creaSottoAlbero(Tree,Tree.figlioDX(Tree.radiceAlbero()),sub1.radiceAlbero());
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO SUB1 **********************";
    cout<<"\n\n         ";
    sub1.stampa();
    Tree.inserisciSottoAlberoASinistraDelNodo(sub1,Tree.radiceAlbero(),sub1.radiceAlbero());//inserisce il sottoalbero sub1 a sinistra del nodo radice
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE(dopo inserimento sottoalbero sub1 a sinistra della radice) **********************";
    cout<<"\n\n         ";
    Tree.stampa();
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE **********************";
    typename Albero_binario<int>::Nodo nodo;
    nodo=Tree.figlioSX(Tree.figlioDX(Tree.radiceAlbero()));
    Tree.inserisciSottoAlberoADestraDelNodo(sub1,nodo,sub1.radiceAlbero());//inserisce il sottoalbero sub1 a destra del nodo nodo in tree
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE(dopo inserimento sottoalbero sub1 a destra del nodo nodo) **********************";
    cout<<"\n\n         ";
    Tree.stampa();
    Albero_binario<int> albero1,albero2;
    typename Albero_binario<int>::Nodo radice1,radice2;
    radice1=new Cella<int>;
    radice2=new Cella<int>;
    albero1.insRadice(radice1);
    albero2.insRadice(radice2);
    albero1.scriviNodo(albero1.radiceAlbero(),5);
    albero1.insFiglioSX(albero1.radiceAlbero());
    albero1.scriviNodo(albero1.figlioSX(albero1.radiceAlbero()),4);
    albero1.insFiglioDX(albero1.radiceAlbero());
    albero1.scriviNodo(albero1.figlioDX(albero1.radiceAlbero()),3);
    radice1=albero1.figlioSX(albero1.radiceAlbero());
    albero1.insFiglioSX(radice1);
    albero1.scriviNodo(albero1.figlioSX(radice1),2);
    albero1.modificaNumeroNodi(albero1.radiceAlbero());
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO ALBERO1 **********************";
    cout<<"\n\n         ";
    albero1.stampa();
    albero2.scriviNodo(albero2.radiceAlbero(),34);
    albero2.insFiglioSX(albero2.radiceAlbero());
    albero2.scriviNodo(albero2.figlioSX(albero2.radiceAlbero()),23);
    albero2.insFiglioDX(albero2.radiceAlbero());
    albero2.scriviNodo(albero2.figlioDX(albero2.radiceAlbero()),56);
    radice2=albero2.figlioSX(albero2.radiceAlbero());
    albero2.insFiglioSX(radice2);
    albero2.scriviNodo(albero2.figlioSX(radice2),48);
    albero2.modificaNumeroNodi(albero2.radiceAlbero());
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO ALBERO2 **********************";
    cout<<"\n\n         ";
    albero2.stampa();
    albero1.mutate(albero1,albero2,albero1.figlioSX(albero1.radiceAlbero()),albero2.figlioSX(albero2.radiceAlbero()));
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO ALBERO1(dopo la mutate) **********************";
    cout<<"\n\n         ";
    albero1.stampa();
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO ALBERO2(dopo la mutate) **********************";
    cout<<"\n\n         ";
    albero2.stampa();

    Albero_binario<int> Tree2;
    typename Albero_binario<int>::Nodo radix;
    radix=new Cella<int>;
    Tree2.insRadice(radix);
    Tree2.scriviNodo(Tree2.radiceAlbero(),2345);
    Tree2.insFiglioSX(Tree2.radiceAlbero());
    Tree2.insFiglioDX(Tree2.radiceAlbero());
    Tree2.scriviNodo(Tree2.figlioSX(Tree2.radiceAlbero()),234);
    Tree2.scriviNodo(Tree2.figlioDX(Tree2.radiceAlbero()),235);

    Tree2.stampa();
    if(Tree2.is_height_balanced(Tree2.radiceAlbero())){
        cout<<"E' bilanciato in altezza";
    }

    cout<<"\n\nLa larghezza dell'albero binario e': "<<Tree2.larghezza(Tree2.radiceAlbero());
*/

	Albero_binario<int> Tree;
	typename Albero_binario<int>::Nodo radice;
	radice = new Cella<int>;
/*
	Tree.insRadice(radice);
	Tree.scriviNodo(Tree.radiceAlbero(),10);

	Tree.insFiglioSX(Tree.radiceAlbero());
	Tree.scriviNodo(Tree.figlioSX(Tree.radiceAlbero()),2);
	Tree.modificaNumeroNodi(radice);

	Tree.insFiglioDX(Tree.radiceAlbero());
	Tree.scriviNodo(Tree.figlioDX(Tree.radiceAlbero()),8);
	Tree.modificaNumeroNodi(radice);

	radice = Tree.figlioSX(Tree.radiceAlbero());
	Tree.insFiglioSX(radice);
	Tree.scriviNodo(Tree.figlioSX(radice),19);
	Tree.modificaNumeroNodi(radice);

	radice = Tree.figlioDX(Tree.radiceAlbero());
	Tree.insFiglioDX(radice);
	Tree.scriviNodo(Tree.figlioDX(radice),70);
	Tree.modificaNumeroNodi(radice);

	radice = Tree.figlioSX(radice);
	Tree.insFiglioSX(radice);
	Tree.scriviNodo(Tree.figlioSX(radice),3);
	Tree.modificaNumeroNodi(radice);

	radice = Tree.figlioDX(radice);
	Tree.insFiglioDX(radice);
	Tree.scriviNodo(Tree.figlioDX(radice),99);
	Tree.modificaNumeroNodi(radice);
*/
	 Tree.insRadice(radice);
	 Tree.scriviNodo(Tree.radiceAlbero(),1);

	 Tree.insFiglioSX(Tree.radiceAlbero());
	 Tree.scriviNodo(Tree.figlioSX(Tree.radiceAlbero()),19);

	 Tree.insFiglioDX(Tree.radiceAlbero());
	 Tree.scriviNodo(Tree.figlioDX(Tree.radiceAlbero()),8);

	 radice=Tree.figlioDX(Tree.radiceAlbero());
	 Tree.insFiglioSX(radice);
	 Tree.scriviNodo(Tree.figlioSX(radice),5);

	 Tree.modificaNumeroNodi(Tree.radiceAlbero());

	 Tree.insFiglioDX(radice);
	 Tree.scriviNodo(Tree.figlioDX(radice),3);

	 radice = Tree.figlioSX(Tree.radiceAlbero());
	 Tree.insFiglioSX(radice);
	 Tree.scriviNodo(Tree.figlioSX(radice),6);

	 Tree.insFiglioDX(radice);
	 Tree.scriviNodo(Tree.figlioDX(radice),4);

	 radice = Tree.figlioSX(radice);
	 Tree.insFiglioSX(radice);
	 Tree.scriviNodo(Tree.figlioSX(radice),10);

	 Tree.stampa();
	 Tree.multipli(Tree);
	 Tree.stampa();
	 cout << endl;
	 cout << "Il numero di nodi dispari al livello k  è :::: " << Tree.oddDispari(Tree,1) << endl;
	 cout << "Il numero di nodi pari al livello k  è :::: " << Tree.oddPari(Tree,2) << endl;
	 cout << "Il numero di nodi foglia pari è :::: " << Tree.even_leafs(Tree) << endl;
	 cout << "Il numero di nodi che hanno come padre un nodo padre è :::: " << Tree.leafs_with_even_parent(Tree) << endl;
	 //cout << "La lista :::: " << Tree.values_average(Tree) << endl;
	 cout << Tree.is_zero_one(Tree);
    return 0;
}
