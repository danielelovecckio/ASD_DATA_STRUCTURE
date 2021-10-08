/*
 * Hash.h
 *
 *  Created on: 6 ott 2020
 *      Author: peppi
 */

#ifndef HASH_H_
#define HASH_H_

#include"LinkedList.h"
#include "Dizionario.h"
#include <string>

using namespace std;


template<class T>
class Hash{
public:
	size_t operator()(const T the_key)const;
};

template<>
class Hash<int>{
public:
	size_t operator()(const int the_key)const{
		return the_key;
	}
};

template<>
class Hash<string>{
public:
	size_t operator()(const string the_key)const{
		unsigned long hash_valore=0;
		int lunghezza=(int) the_key.length();
		for(int i=0; i<lunghezza; i++){
			hash_valore=5*hash_valore+the_key.at(i);
		}
		return size_t (hash_valore);
	}
};

/* = TASTATURA LINEARE =
 *
 * Il modo più semplice per trovare un posto in cui inserire un valore nella tabella è cercare nella tabella
 * il prossimo bucket disponibile.
 *
 * Dall'altro lato, la ricerca inizia dal bucket home f (k) della chiave k che stiamo cercando
 * per e continua esaminando i bucket successivi nella tabella fino a uno dei seguenti
 * si verificano condizioni:
 * i) viene raggiunto un bucket contenente una coppia con chiave k
 * ii) viene raggiunto un secchio vuoto
 * iii) torniamo al secchio di casa
 */

template<class K,class E>
struct Coppia;

template<class K,class E>
class HashTable:public Dizionario<K,E>{

public:
	bool vuoto()const{
		return dsize==0;
	}

	int size()const{
		return dsize;
	}

	void elimina(const K &);
	void modifica(const K &, const E &);

	E& operator[](K &);
	E operator[](K &)const;

	HashTable(const HashTable<K,E> &);
	HashTable(int);
	~HashTable();

	void crea(){};
	bool contiene(const K &)const;
	LinkedList<K> keys()const;
	LinkedList<E> valore()const;
	int cerca(const K&)const;	//search
	Coppia<K,E>* trova(const K&)const;
	void inserisci(Coppia<K,E>&);
	void inserisci(const K&, const E&);
	void resize(const size_t);		////////////////////////////
	void print()const;

	HashTable<K,E> &operator=(const HashTable<K,E>&);
	template<class C, class G>
	friend ostream& operator<<(ostream& os, const HashTable<C,G> &th);

private:
	Coppia<K,E>** table;
	Hash<K> hashm;		//mappa tipo k non negativi
	int  dsize;
	int divisor;

};




template<class K,class E>
HashTable<K,E>::HashTable(int d){
	if(d==0){
		d=1;
	}
	divisor=d;
	dsize=0;
	table= new Coppia<K,E>*[divisor];
	for(int i=0; i<divisor; i++){
		table[i]=nullptr;
	}
}


template<class K,class E>
HashTable<K,E>::HashTable(const HashTable<K,E> & ht){
	dsize=0;
	divisor=ht.divisor;
	table=new Coppia<K,E>*[divisor];
	for(int i=0; i<ht.divisor;i++){
		if(ht.table[i]!=NULL){
			table[i]=new Coppia<K,E>(*ht.table[i]);
			dsize++;
		}else{
			table[i]=nullptr;
		}
	}
}


template<class K,class E>
HashTable<K,E>::~HashTable(){

	for(int i=0; i<divisor;i++){
		delete table[i];
	}
	delete [] table;
	table=nullptr;

}

template<class K,class E>
E& HashTable<K,E>::operator [](K& key){
	return trova(key)->secondo;
}

template<class K,class E>
E HashTable<K,E>::operator [](K& key)const{
	return trova(key)->secondo;
}

template<class K,class E>
bool HashTable<K,E>::contiene(const K& k)const{
	int i=(int)hashm(k)%divisor;
	int j=i;

	do{
		if(table[i]==NULL){
			return false;
		}else if(table[j]->primo==k){
			return true;
		}else{
			j=(j+1)%divisor;
		}
	}while(j!=i);
	return false;
}

template<class K,class E>
LinkedList<K> HashTable<K,E>::keys()const{
	LinkedList<K> kyz;
	for(int i=0; i<divisor;i++){
		if(table[i]!=NULL){
			kyz.inserisci1(table[i]->primo);
		}
	}
	return kyz;
}

template<class K,class E>
LinkedList<E> HashTable<K,E>::valore()const{

	LinkedList<E> vlz;

	for(int i=0; i<divisor; i++){
		if(table[i]!=NULL){
			vlz.inserisci1(table[i]->secondo);
		}
	}
	return vlz;
}


template<class K,class E>
int HashTable<K,E>::cerca(const K& k)const{

	int i=(int) hashm(k) % divisor;
	int j=i;
	do{
		if(table[j]==NULL || table[j]->primo ==k){
			return j;
		}
		j=(j+1)%divisor;
	}while(j!=i);
	return j;			//piena

}

template<class K,class E>
Coppia<K,E>* HashTable<K,E>::trova(const K& k)const{

	int b=cerca(k);
	if(table[b]==NULL || table[b]->primo!=k){
		return NULL;
	}
	return table[b];

}

/* = INSERIMENTO =
 *
 * Inizia invocando la ricerca del metodo. Se il bucket b restituito è vuoto, non è presente
 * coppia nella tabella con la chiave the_pair.first e la coppia the_pair può essere inserita in questa
 * secchio. Se il bucket restituito non è vuoto, allora contiene una coppia con la chiave the_pair.first
 * o il tavolo è pieno. Nel primo caso cambiamo la seconda componente della coppia memorizzata
 * nel secchio a the_pair.second; in quest'ultimo, lanciamo un'eccezione
 */

template<class K,class E>
void HashTable<K,E>::inserisci(Coppia<K,E>& p){

	int b=cerca(p.primo);
	if(table[b]==NULL){
		table[b]=new Coppia<K,E>(p);
		dsize++;
	}else{
		if(table[b]->primo==p.primo){
			table[b]->secondo=p.secondo;
		}else throw "tabbella piena";
	}


}

template<class K,class E>
void HashTable<K,E>::inserisci(const K& k,const E& v){

	int b=cerca(k);
	if(table[b]==NULL){
		table[b]=new Coppia<K,E> (k,v);
		dsize++;
	}else{
		if(table[b]->primo==k){
			table[b]->secondo=valore;
		}else throw "tabella piena";
	}

}

template<class K,class E>
void HashTable<K,E>::elimina(const K& k){

	int b=cerca(k);
	if(table[b]==NULL){
		return;
	}else{
		delete table[b];
		table[b]=NULL;
		dsize--;
	}

}

template<class K,class E>
void HashTable<K,E>::modifica(const K& k, const E& e){
	int b=cerca(k);
	if(table[b]==NULL){
		return;
	}else{
		table[b]->secondo=e;
	}
}


template<class K,class E>
void HashTable<K,E>::resize(const size_t dim){

	if(dim!=divisor && dim!=0 && dim>=dsize){
		static HashTable<K,E> newtable(dim);
		for(int i=0; i<divisor;i++){
			if(table[i]!=NULL){
				newtable.inserisci(*table[i]);
			}
		}
		*this=newtable;
	}else throw "impossibile dimensione";

}

template<class K,class E>
HashTable<K,E>& HashTable<K,E>::operator=(const HashTable<K,E> & ht){

	if(this==&ht){
		return*this;
	}else{
		for(int i=0; i<divisor;i++){
			delete table[i];
		}
		delete [] table;
		table=nullptr;
		dsize=0;
		divisor=ht.divisor;


		table=new Coppia<K,E>* [divisor];
		for(int i=0; i<divisor; i++){
			table[i]=nullptr;
		}
		for(int i=0; i<ht.divisor; i++){
			if(ht.table[i]!=NULL){
				table[i]=new Coppia<K,E>(*ht.table[i]);
				dsize++;
			}
		}

	}

	return *this;
}

template<class K,class E>
void HashTable<K,E>::print()const{

	for(int i=0; i<divisor;i++){
		cout<<i<<" : [";
		if(table[i]!=NULL){
			cout<<table[i]->primo<<","<<table[i]->secondo;
		}
		cout<<"]"<<endl;
	}

}

template<class K, class E>
ostream& operator<<(ostream& os, const HashTable<K,E> &ht){

  for(int i=0; i<ht.divisor; i++){

    os<<i<<": [";
    if(ht.table[i]!=NULL){
      os<<ht.table[i]->primo <<","<<ht.table[i]->secondo;
    }
    os<<"]"<<endl;

  }
	return os;
}




#endif /* HASH_H_ */
