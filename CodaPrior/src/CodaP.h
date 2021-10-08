/*
 * CodaP.h
 *
 *  Created on: 5 ott 2020
 *      Author: daniele
 */

#ifndef CODAP_H_
#define CODAP_H_

template <class Elemento>
class CodaP{
public:
	typedef Elemento T;
	CodaP();
	CodaP(int);
	~CodaP();

	void crea();
	void inserisci(T);
	T min();
	void cancellaMin();

private:
    int MAXLUNG;
    T *heap;
    int ultimo;

    void fixUp ();
    void fixDown (int, int);
};

template < class Elemento >
CodaP<Elemento>::CodaP():MAXLUNG(100) {
  heap = new T[MAXLUNG];
  crea();
};

template < class Elemento >
CodaP <Elemento>::CodaP (int n):MAXLUNG(n){
  heap = new T[MAXLUNG];
  crea();
};

template <class Elemento>
CodaP <Elemento>::~CodaP(){
	delete[] heap;
}

template<class Elemento>
void CodaP<Elemento>::crea(){
	ultimo=0;
}

template<class Elemento>
void CodaP<Elemento>::inserisci(T q){
	if(ultimo<MAXLUNG){
		heap[++ultimo-1]=q;
		fixUp();
	}
}

template<class Elemento>
typename CodaP<Elemento>::T CodaP<Elemento>::min(){
	if(ultimo!=0)
		return heap[0];
}

template<class Elemento>
void CodaP<Elemento>::cancellaMin(){
	if(ultimo!=0){
		heap[0]=heap[ultimo-1];//copia il valore dell'ultima foglia nella radice
		ultimo--;
		fixDown(1,ultimo); //fai scendere verso il basso
	}
}

template <class Elemento>
void CodaP <Elemento>::fixUp () {
  int k = ultimo;

  while (k > 1 && heap[k - 1] < heap[k / 2 - 1]) {
      T tmp;
      tmp = heap[k - 1];
      heap[k - 1] = heap[k / 2 - 1];
      heap[k / 2 - 1] = tmp;
      k = k / 2;
    }

}

template < class Elemento >
void CodaP < Elemento >::fixDown (int k, int N) {

  short int scambio = 1;

  while (k <= N / 2 && scambio) {
      int j = 2 * k;
      T tmp;
      if (j < N && heap[j - 1] > heap[j])
	     j++;

      if ((scambio = (heap[j - 1] < heap[k - 1]))) {
		 tmp = heap[k - 1];
		 heap[k - 1] = heap[j - 1];
	     heap[j - 1] = tmp;
		 k = j;
	  }
  }
};

#endif /* CODAP_H_ */
