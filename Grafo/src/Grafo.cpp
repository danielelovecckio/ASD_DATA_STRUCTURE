#include "GrafoList.h"

#include <string>
#include "GrafoMat.h"
using namespace std;


int main()
{
	//vado a creare un grafo di elementi di tipo stringa e come pesi numeri interi
/*	GrafoList<string,int> G(10);		//il grafo avrà 10 elementi

	//vado a creare i nodi del grafo
	NodoG n1,n2,n3,n4,n5,n6,n7;

	//vado ad inserire i nodi nel grafo e successivamente vado ad avvalorare le loro etichette
	G.insNodo(n1);
	G.scriviEtichetta(n1,"a");
	G.insNodo(n2);
	G.scriviEtichetta(n2,"b");
	G.insNodo(n3);
	G.scriviEtichetta(n3,"c");
	G.insNodo(n4);
	G.scriviEtichetta(n4,"d");
	G.insNodo(n5);
	G.scriviEtichetta(n5,"e");
	G.insNodo(n6);
	G.scriviEtichetta(n6,"f");
	G.insNodo(n7);
	G.scriviEtichetta(n7,"g");


	//vado a creare gli archi tra i vari nodi
	G.insArco(n1,n3,1);		//a con c
	G.insArco(n1,n4,2);		//a con d
	G.insArco(n1,n6,1);		//a con f

	G.insArco(n3,n6,1);		//c con f
	G.insArco(n3,n1,1);		//c con a

	G.insArco(n6,n3,1);		//f con c
	G.insArco(n6,n4,1);		//f con d
	G.insArco(n6,n1,1);		//f con a

	G.insArco(n4,n1,1);		//d con a
	G.insArco(n4,n6,1);		//d con f
	G.insArco(n4,n2,1);		//d con b
	G.insArco(n4,n5,1);		//d con e

	G.insArco(n2,n4,1);		//b con d
	G.insArco(n2,n5,1);		//b con e

	G.insArco(n5,n4,1);		//e con d
	G.insArco(n5,n2,1);		//e con b

	cout<<"Il numero di nodi del grafo e': "<<G.numNodi()<<endl;
	cout<<"Il numero di archi del grafo e': "<<G.numArchi()<<endl;


	GrafoList<string,double>::ListaNodi L = G.adiacenti(n1);		//creazione di una lista di nodi adiacenti, partendo da N1
	GrafoList<string,double>::ListaNodiPos p;					//dichiarazione di un puntatore posizionale P alla lista dei nodi
	cout << "Adiacenti di " << G.leggiEtichetta(n1) << "--> ";		//stampa adiacenti del nodo N1
	p = L.begin();													//Posiziono p all'inizio della lista
	while (!L.end(p))												//fino a quando non arrivo alla fine della lista
	{
		cout <<  G.leggiEtichetta(*(L.read(p))) << " ";			//stampo l'etichetta di ogni nodo adiacente
		p = L.next(p);											//incremento il puntatore
    }
    cout<<endl;


	L=G.adiacenti(n2);
    cout << "Adiacenti di " << G.leggiEtichetta(n2) << "--> ";
    p=L.begin();
    while (!L.end(p))												//fino a quando non arrivo alla fine della lista
	{
		cout <<  G.leggiEtichetta(*(L.read(p))) << " ";			//stampo l'etichetta di ogni nodo adiacente
		p = L.next(p);											//incremento il puntatore
    }

    cout<<endl;

    cout<<"Il peso dell'arco che va da "<<G.leggiEtichetta(n1)<<" A "<<G.leggiEtichetta(n2)<<" è: "<<G.leggiPeso(n1,n3)<<endl;

   bool risp = G.esisteArco(n1,n3);
   if (risp)
	   cout<<"si, esiste un arco tra "<<G.leggiEtichetta(n1)<<" e "<<G.leggiEtichetta(n3)<<endl;
   else
	   cout<< "no, non esiste un arco tra " <<G.leggiEtichetta(n1)<<" e "<<G.leggiEtichetta(n3)<<endl;

  // G.cancNodo(n2);

 //  G.cancArco(n1,n3);
//   cout<<"Il numero di archi del grafo e': "<<G.numArchi()<<endl;
  // cout<<"Il numero di nodi del grafo e': "<<G.numNodi()<<endl;
   *
   *
   *
   *
   *
  ---------------------------------------------TEST NUMERO 2------------------------------------------------
   GrafoList<string,double> G(10);		//DICHIARO UN GRAFO DI TIPO STRINGA

   	GrafoList<string,double> G2(20);
   	NodoG ng2;

   	G2.insNodo(ng2);
   	cout<<"STAMPO INDIRIZZO DEL GRAFO 2: "<<&G2<<endl;
   	cout<<"STAMPO INDIRIZZO DI NG2: "<<ng2.getPuntatore()<<endl;

   	NodoG n1,n2,n3,n4,n5,n6;			//DICHIARAZIONE DI DIFFERENTI NODI n1, n2, n3, n4, n5, n6

   	if(G.vuoto()==true) cout<<"Il grafo risulta essere vuoto"<<endl;
   	else cout<<"Il grafo non e' vuoto"<<endl;

   	G.insNodo(n1);						//Al grafo inserisco il Nodo n1
   	G.scriviEtichetta(n1,"a");			//Avvaloro l'etichetta n1 con la stringa "a"
   	G.insNodo(n2);						//Al grafo inserisco il Nodo n2
   	G.scriviEtichetta(n2,"b");			//Avvaloro l'etichetta n2 con la stringa "b"
   	G.insNodo(n3);						//Al grafo inserisco il Nodo n3
   	G.scriviEtichetta(n3,"c");			//Avvaloro l'etichetta n3
   	G.insNodo(n4);						//Al grafo inserisco il Nodo n4
   	G.scriviEtichetta(n4,"d");			//Avvaloro l'etichetta n4
   	G.insNodo(n5);						//Al grafo inserisco il Nodo n5
   	G.scriviEtichetta(n5,"e");			//Avvaloro l'etichetta n5
   	G.insNodo(n6);						//Al grafo inserisco il Nodo n6
   	G.scriviEtichetta(n6,"f");			//Avvaloro l'etichetta n6

   	if(G.vuoto()==true) cout<<"Il grafo risulta essere vuoto"<<endl;
   	else cout<<"Il grafo non e' vuoto"<<endl;


   	//DEFINIZIONE DEGLI ARCHI TRA I NODI E I RELATIVI PESI
   	G.insArco(n1,n2, 1.0);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n1,n3, 0.9);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n1,n5, 0.3);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n2,n4, 0.1);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n2,n6, 0.2);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n3,n4, 1.0);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n3,n6, 0.7);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n4,n1, 0.5);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n5,n2, 0.4);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n5,n3, 0.2);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	G.insArco(n6,n4, 0.1);				//Inserisco un arco tra due nodi e ne inserisco il peso
   	cout << G.esisteArco(n1,n6);
   	cout << "\nNumNodi " << G.numNodi();		//stampa il numero di nodi presenti nel grafo
   	cout << "\nNumArchi " << G.numArchi();		//stampa il numero di archi presenti nel grafo

   	//CANCELLAZIONE DI UN NODO
   	G.cancNodo(n6);

   	cout << "\nNumNodi " << G.numNodi() << endl;

   	GrafoList<string,double>::ListaNodi L = G.adiacenti(n1);		//creazione di una lista di nodi adiacenti, partendo da N1

   	GrafoList<string,double>::ListaNodiPos p;					//dichiarazione di un puntatore posizionale P alla lista dei nodi


   	cout << "Adiacenti di " << G.leggiEtichetta(n1) << "--> ";		//stampa adiacenti del nodo N1
   	p = L.begin();													//Posiziono p all'inizio della lista
   	while (!L.end(p))												//fino a quando non arrivo alla fine della lista
   	{
   		cout <<  G.leggiEtichetta(*(L.read(p))) << " ";			//stampo l'etichetta di ogni nodo adiacente
   		p = L.next(p);											//incremento il puntatore
       }
       cout<<endl;

       //TEST ESISTE ETICHETTA
       bool e_n=G.esisteNodo(n1);
       if(e_n)
       {
       	cout<<"Il nodo esiste"<<endl;
   	}
   	else
   	{
   		cout<<"Il nodo non esiste"<<endl;
   	}

       //STAMPO INDIRIZZO DEL GRAFO
       cout<<"INDIRIZZO DEL GRAFO: "<<&G<<endl;
       cout<<n1.getPuntatore()<<endl;

       G.insArco(n2,ng2,5);

       //TEST ESISTE ARCO
       bool esiste=G.esisteArco(n1,n4);
       if(esiste)
       {
       	cout<<"ESISTE UN ARCO!"<<endl;
   	}
   	else
   	{
   		cout<<"NON ESISTE UN ARCO TRA I DUE NODI INSERITI"<<endl;
   	}

   	//TEST VERIFICA ESISTENODO - CANCELLAZIONE DEL NODO - NUOVA VERIFICA ESISTENODO (solo se un nodo ha nodi uscenti)
   	e_n=G2.esisteNodo(ng2);
       if(e_n)
       {
       	cout<<"Il nodo esiste"<<endl;
   	}
   	else
   	{
   		cout<<"Il nodo non esiste"<<endl;
   	}
   	G2.cancNodo(ng2);
   	e_n=G2.esisteNodo(ng2);
       if(e_n)
       {
       	cout<<"Il nodo esiste"<<endl;
   	}
   	else
   	{
   		cout<<"Il nodo non esiste"<<endl;
   	}
 */




 /*-------------------------------------------------------TEST GRAFOMAT--------------------------------------------*/
/*
	GrafoMat<string,double> G(10);

	    NodoGMat n1,n2,n3,n4,n5,n6,n8;

	    G.insNodo(n1);
	    G.scriviEtichetta(n1,"n1");
	    G.insNodo(n2);
	    G.scriviEtichetta(n2,"n2");
	    G.insNodo(n3);
	    G.scriviEtichetta(n3,"n3");
	    G.insNodo(n4);
	    G.scriviEtichetta(n4,"n4");
	    G.insNodo(n5);
	    G.scriviEtichetta(n5,"n5");
	    G.insNodo(n6);
	    G.scriviEtichetta(n6,"n6");
	    G.insNodo(n8);
	    G.scriviEtichetta(n8,"n7");


	    G.insArco(n1,n2, 1.0);
	    G.insArco(n1,n3, 0.9);
	    G.insArco(n1,n5, 0.3);
	    G.insArco(n2,n4, 0.1);
	    G.insArco(n2,n6, 0.2);
	    G.insArco(n3,n4, 1.0);
	    G.insArco(n3,n6, 0.7);
	    G.insArco(n4,n1, 0.5);
	    G.insArco(n5,n2, 0.4);
	    G.insArco(n5,n3, 0.2);
	    G.insArco(n6,n4, 0.1);
	    G.insArco(n6,n5, 0.3);
	    G.insArco(n5,n8, 0.3);

	    cout << "\nNumNodi " << G.numNodi();
	    cout << "\nNumArchi " << G.numArchi();

	    G.cancNodo(n8);

	    cout << "\nNumNodi " << G.numNodi();

	    GrafoMat<string,double>::ListaNodi L = G.adiacenti(n1);

	    GrafoMat<string,double>::ListaNodiPos p;


	    cout << "\nAdiacenti di " << G.leggiEtichetta(n1) << "--> ";
	    p = L.begin();
	    while (!L.end(p)){
	        cout <<  G.leggiEtichetta(*(L.read(p))) << " ";
	        p = L.next(p);
	    }

	    cout << endl;
*/


	GrafoMat<string,int> g(15);
	    NodoGMat n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
	    g.insNodo(n1);
	    g.scriviEtichetta(n1,"n1");
	    g.insNodo(n2);
	    g.scriviEtichetta(n2,"n2");
	    g.insNodo(n3);
	    g.scriviEtichetta(n3,"n3");
	    g.insNodo(n4);
	    g.scriviEtichetta(n4,"n4");
	    g.insNodo(n5);
	    g.scriviEtichetta(n5,"n5");
	    g.insNodo(n6);
	    g.scriviEtichetta(n6,"n6");
	    g.insNodo(n7);
	    g.scriviEtichetta(n7,"n7");
	    g.insNodo(n8);
	    g.scriviEtichetta(n8,"n8");
	    g.insNodo(n9);
	    g.scriviEtichetta(n9,"n9");
	    g.insNodo(n10);
	    g.scriviEtichetta(n10,"n10");

	    g.insArco(n1,n2,0);
	    g.insArco(n1,n8,0);
	    g.insArco(n1,n7,0);
	    g.insArco(n1,n6,0);

	    g.insArco(n8,n3,0);
	    g.insArco(n8,n9,0);
	    g.insArco(n8,n7,0);

	    g.insArco(n9,n5,0);
	    g.insArco(n9,n10,0);

	    g.insArco(n5,n4,0);
	    g.insArco(n5,n3,0);
	    g.insArco(n7,n9,0);

	    cout << "Esiste un percorso tra i nodi n8 e n1 e tutti i nodi hanno lo stesso colore : "<< g.sameColorPath(n1,n4) << endl;
	    g.reset_marcatura();
	    cout << "Esiste un percorso tra i nodi e il nodo precedente ha un'etichetta diversa dal successivo : "<< g.uniformColorPath(n1,n4)<<endl;
	    g.reset_marcatura();

	   cout << "Esiste un cammino tra n1 e n9 :"<< g.esiste_cammino(n1,n9) << endl;
	   cout << "Esistono questo numero di cammini per arrivare da n1 e n9 : " << g.numero_cammini(n1,n3) << endl;
	  // cout << "Esiste un cammino tra i due nodi con peso sugli archi p : " << g.esiste_cammino(n1,n3,0);

	   GrafoMat<int,int> g1(10);
	   g1.insNodo(n1);
	  	    g1.scriviEtichetta(n1,12);
	  	    g1.insNodo(n2);
	  	    g1.scriviEtichetta(n2,54);
	  	    g1.insNodo(n3);
	  	    g1.scriviEtichetta(n3,5);
	  	    g1.insNodo(n4);
	  	    g1.scriviEtichetta(n4,34);
	  	    g1.insNodo(n5);
	  	    g1.scriviEtichetta(n5,31);
	  	    g1.insNodo(n6);
	  	    g1.scriviEtichetta(n6,22);
	  	    g1.insNodo(n7);
	  	    g1.scriviEtichetta(n7,45);
	  	    g1.insNodo(n8);
	  	    g1.scriviEtichetta(n8,5);
	  	    g1.insNodo(n9);
	  	    g1.scriviEtichetta(n9,2);
	  	    g1.insNodo(n10);
	  	    g1.scriviEtichetta(n10,5);

		    g1.insArco(n1,n2,0);
		    g1.insArco(n1,n8,0);
		    g1.insArco(n1,n7,0);
		    g1.insArco(n1,n6,0);

		    g1.insArco(n8,n3,0);
		    g1.insArco(n8,n9,0);
		    g1.insArco(n8,n7,0);

		    g1.insArco(n9,n5,0);
		    g1.insArco(n9,n10,0);

		    g1.insArco(n5,n4,0);
		    g1.insArco(n5,n3,0);
		    g1.insArco(n7,n9,0);
	   cout << "La somma delle etichette  dei nodi con cammino=2 è :" << g1.somma_nodi_con_cammino(n1,56) << endl;
	   cout << "Il numero di nodi raggiungibili da n con cammino=2 è :" << g1.conta_nodi_nei_cammini(n1,56);
	   cout << "Il numero di nodi raggiungibili da n e che hanno la sua stessa etichetta è :" << g1.countSame(n1);
	   return 0;
}
