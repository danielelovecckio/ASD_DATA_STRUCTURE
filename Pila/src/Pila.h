/*
 * Pila.h
 *
 *  Created on: 5 ott 2020
 *      Author: daniele
 */

#ifndef PILA_H_
#define PILA_H_


#include <iostream>

using namespace std;

template <class Elemento>
class Pila{
public :
	typedef Elemento value_type;
	Pila();
	~Pila();
	Pila(int);

	void crea();
	bool pilaVuota() const;
	value_type leggiPila() const;
	void fuoriPila();
	void inPila(value_type);
private :
	value_type *elementi;
	int MAXLUNGH;
	int testa;
};

template<class Elemento>
Pila<Elemento>::Pila(){
	elementi = new value_type[100];
	MAXLUNGH = 100;
	crea();
}


template <class Elemento>
Pila<Elemento>::Pila(int N)
{
  elementi = new value_type[N]; // dimensione N della pila passato come parametro
  MAXLUNGH = N;
  crea();
}

template <class Elemento>
Pila<Elemento>::~Pila(){
  delete[] elementi;
};

template <class Elemento>
void Pila<Elemento>::crea(){
	testa = 0;
}

template <class Elemento>
bool Pila<Elemento>::pilaVuota() const{
    return testa==0;
}

template <class Elemento>
Elemento Pila<Elemento>::leggiPila() const{
    return elementi[testa-1];
}

template <class Elemento>
void Pila<Elemento>::fuoriPila(){
	if(!pilaVuota())
		testa-=1;
	else
		cout << "No elements in" << endl;

}


template <class Elemento>
void Pila<Elemento>::inPila(value_type el){
  if (testa==MAXLUNGH)
      cout << "Raggiunta capacità massima della pila"<<endl;
  else
    {
      elementi[testa]=el;
      testa++;
    }
}
#endif /* PILA_H_ */
