#include "grafo.h"
#include <iostream>
using namespace std;


grafoExacto::grafoExacto(): grafo(), n_provisorio(0), n_final(n), res_parcial(), marcas(n, 0),
                            k(-1), no_visitados(n) 
{
	//poda: hardcodear nodos aislados
	for (int i = 0; i < ady.size(); ++i)
	{
		if (ady[i].empty()) {
			marcarNodo(i);
		}
	}
	// // cota inicial
	// grafoGoloso aux(*this);
	// n_final = aux.CIDMgoloso()+1;
}

void grafoExacto::CIDMexacto() {
	k++;
	// si es solucion
	if (no_visitados == 0) {
		if (n_provisorio < n_final) {
			res.clear();
			res = list<int>(res_parcial);
			n_final=n_provisorio;
		}
		k--;
		return;
	}
	// si no es solucion
	if (k == n) {
		k--;
		return;
	}
	
	// // poda: soluciones inutiles
	// if (n_provisorio >= n_final-1) {
	// 	k--;
	// 	return;
	// }

	CIDMexacto();
	if (marcas[k] == 0) {
		marcarNodo(k);
		CIDMexacto();
		desmarcarNodo(k);
	}
	k--;
	return;
}

void grafoExacto::marcarNodo(int k) {
	marcas[k]++;
	n_provisorio++;
	no_visitados--;
	for (auto it = ady[k].begin(); it != ady[k].end(); ++it) {
		if (marcas[*it]++ == 0) no_visitados--;
	}
	res_parcial.push_back(k);
}

void grafoExacto::desmarcarNodo(int k) {
	marcas[k]--;
	n_provisorio--;
	no_visitados++;
	for (auto it = ady[k].begin(); it != ady[k].end(); ++it) {
		if (--marcas[*it] == 0) no_visitados++;
	}
	res_parcial.pop_back();
}

