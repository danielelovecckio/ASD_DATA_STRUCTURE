//============================================================================
// Name        : Dizionario.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Hash.h"
#include "Dizionario.h"
#include "LinkedList.h"
#include<string>
using namespace std;

int main() {

cout<<"dizionario 22 "<<endl;

//creiamo il dizionario
    HashTable<string,int> dizionario(3);
    Coppia<string,int> a;
    a.primo="ciao";
    a.secondo=56;
    dizionario.inserisci(a);
    a.primo="ragno";
    a.secondo=1234;
    dizionario.inserisci(a);
    a.primo="alto";
    a.secondo=234;
    dizionario.inserisci(a);

    cout<<"The position of elements with key 'ciao' is: "<<dizionario.cerca("ciao");
    cout<<"\nThe position of elements with key 'ragno' is: "<<dizionario.cerca("ragno");
    cout<<"\nThe position of elements with key 'alto' is: "<<dizionario.cerca("alto");
    cout<<"\n\n\n";
    dizionario.print();
    cout<<"\n\n\n";


/*    if(dizionario.containsvalore(1234))
       cout<<"\nTrovata\n";
    else
       cout<<"\nNon trovata";
  */
    cout<<"\nvalori:";
 /*   int *valori=dizionario.valore();
    for(int i=0;i<dizionario.returnDsize();i++){
       cout<<"\n "<<valori[i];
    }
    */
    cout<<"\nchiavi:";
//    string* chiavi=dizionario.keys();
/*    for(int i=0;i<dizionario.returnDsize();i++)
       cout<<"\n "<<chiavi[i];

    dizionario.resize();
*/
    cout<<"\nThe position of elements with key 'ciao' is: "<<dizionario.cerca("ciao");
    cout<<"\nThe position of elements with key 'ragno' is: "<<dizionario.cerca("ragno");
    cout<<"\nThe position of elements with key 'alto' is: "<<dizionario.cerca("alto");
 //   cout<<"\nThe new divisor is: "<<dizionario.returnDivisor();

    HashTable<int,int> dizionario1(4);
    Coppia<int,int> b;

    b.primo=23;
    b.secondo=11;
    dizionario1.inserisci(b);


    //hash table
cout<<"\n\n\n  hash table";
HashTable<string,string> t(10);
  cout << " size " << t.size() << endl;
  struct Coppia<string,string> e1;
  e1.primo="rossi";
  e1.secondo="giovanni";
  t.inserisci(e1);
  cout << t.trova("rossi")->secondo << endl;

  struct Coppia<string,string> e2;
  e2.primo="rossi";
  e2.secondo="marco";
  t.inserisci(e2);
  cout << t.trova("rossi")->secondo << endl;


	     return 0;

}
