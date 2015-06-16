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
		// Dios nos perdone y nos guarde en su gloria
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
	vector<int> cantVecinitosPorNodito(cantCandidatos);
	
	struct nodito{
		int numerito;
		int cantVecinitos;
		bool operator<(nodito otro){
			return (cantVecinitos < otro.cantVecinitos);
		}
	};
	
	for (int i = 0; i < n; ++i){
		cantVecinitosPorNodito[i] = aux_ady[i].size();
	}
	sort(cantVecinitosPorNodito.begin(), cantVecinitosPorNodito.end()); // nlogn
	cantVecinitosPorNodito.resize(cantCandidatos); // rebano
	
	return cantVecinitosPorNodito;
}

