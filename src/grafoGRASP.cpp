#include "grafo.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <list>
#include <iostream>
#include "grafo.h"

using namespace std;

// ------------------------------------- Greedy randomize:

grafoGRASP::grafoGRASP(): grafoLocalS(), res_final() {}


void grafoGRASP::CIDMGRASP(int cantCandidatos, int iteraciones){
	srand(time(NULL));
	sorted_ady = vector<list<int> >(ady);
	for (int i = 0; i < n; ++i){
		sorted_ady[i].sort(); // nlogn
	}
	int k = iteraciones;
	int cantCandidatosOriginal = cantCandidatos;
	while(k-- > 0){
		cantCandidatos = cantCandidatosOriginal;
		
		aux_ady = vector< list<int> >(ady);
		esta = vector<bool>(n, false);

		
		res.clear(); // la nueva solucion arranca de 0

		// ---- Goloso randomizado:
		while(n>0){
			cantCandidatos = min(cantCandidatos, n);
			marcarCIDM(nodosMayorGrado(cantCandidatos));
		}
		// print_res();
		n = ady.size();
		// ---- Busquedas locales:
		marcas = vector<int>(n,0);
		for (auto i = res.begin(); i != res.end(); ++i) {
			marcarNodo(*i);
		}
		
		int prevResSize;
		do {
			prevResSize = res.size();
			sacar2poner1();
			sacar3poner2();
		} while(res.size() < prevResSize);
		if (res.size() < res_final.size() || res_final.empty()) {
			res_final.swap(res);
			k = iteraciones;
		}
	}
	res=res_final;
}

int grafoGRASP::nodosMayorGrado(int cantCandidatos){
	
	// creamos una estructura nodito, que guarda su numero de nodo (para identificarlo), y la cantidad de vecinos que tiene (para ordenarlo)
	struct nodito{
		int numerito;
		int cantVecinitos;
		bool operator<(const nodito& otro) const {return (cantVecinitos > otro.cantVecinitos);}
	};
	
	// hacemos la conversion de vector de ints a vector de 'listaNoditos'
	vector<nodito> listaNoditos(n);
	int indiceNoditos = 0;
	for (int i = 0; i < aux_ady.size(); ++i){
		if (!esta[i]){
			listaNoditos[indiceNoditos].numerito = i;
			listaNoditos[indiceNoditos].cantVecinitos = aux_ady[i].size();
			indiceNoditos++;
		}
	}

	//ordenamos, dejando a los mejores al principio
	sort(listaNoditos.begin(), listaNoditos.end()); // nlogn

	//devuelvo solamente los numeros de los nodos
	vector<int> result(cantCandidatos);

	for (int i = 0; i<cantCandidatos; i++){
		
		result[i] = listaNoditos[i].numerito;
	}
	int r = rand() % cantCandidatos;

	return result[r];
}

