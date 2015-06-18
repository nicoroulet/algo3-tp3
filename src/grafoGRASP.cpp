#include "grafo.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <list>
#include <iostream>
#include "grafo.h"

using namespace std;

// ------------------------------------- Greedy randomize:

grafoGRASP::grafoGRASP(): grafoLocalS() {}


void grafoGRASP::CIDMGRASP(int cantCandidatos){
	srand(time(NULL));
	sorted_ady = vector<list<int> >(ady);
	for (int i = 0; i < n; ++i){
		sorted_ady[i].sort(); // nlogn
	}
	
	while(1/*criterio*/){
		aux_ady = vector< list<int> >(ady);
		
		res.clear(); // la nueva solucion arranca de 0
		
		// ---- Goloso randomizado:
		while(n>0){
			cantCandidatos = max(cantCandidatos, n);
			marcarCIDM(nodosMayorGrado(cantCandidatos)[rand() % (cantCandidatos-1)]);
		}
		n = ady.size();
		
		// ---- Busquedas locales:
		marcas = vector<int>(n,0);
		for (auto i = res.begin(); i != res.end(); ++i) {
			marcarNodo(*i);
		}
		
		int gusGil;
		do {
			gusGil = res.size();
			sacar2poner1();
			sacar3poner2();
		} while(res.size() < gusGil);
			
	}
}

vector<int> grafoGRASP::nodosMayorGrado(int cantCandidatos){
	
	// creamos una estructura nodito, que guarda su numero de nodo (para identificarlo), y la cantidad de vecinos que tiene (para ordenarlo)
	struct nodito{
		int numerito;
		int cantVecinitos;
			bool operator<(const nodito& otro) const {return (cantVecinitos < otro.cantVecinitos);}
	};
	
	// hacemos la conversion de vector de ints a vector de 'listaNoditos'
	vector<nodito> listaNoditos(cantCandidatos);
	for (int i = 0; i < n; ++i){
		listaNoditos[i].numerito = i;
		listaNoditos[i].cantVecinitos = aux_ady[i].size();
	}

	//ordenamos, dejando a los mejores al principio
	sort(listaNoditos.begin(), listaNoditos.end()); // nlogn

	//rebanamos el vector, quedandonos con los <cantCandidatos> mejores
	listaNoditos.resize(cantCandidatos);
	
	//devuelvo solamente los numeros de los nodos
	vector<int> res(cantCandidatos);
	for (int i = 0; i<n; i++){
		res[i] = listaNoditos[i].numerito;
	}

	return res;
}

