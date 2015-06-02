#include <iostream>
#include <vector>

#include "grafo.h"

using namespace std;


grafoExacto::grafoExacto(): grafo(), n_provisorio(0), n_final(n), res_parcial(), marcas(n, 0),
                            k(-1), no_visitados(n) {}

void grafoExacto::CIDMexacto() {
	k++;
	// si es solucion
	if (no_visitados == 0) {
		if (n_provisorio < n_final) {
			res.clear();
			res = list<int>(res_parcial);
		}
		k--;
		return;
	}
	// si no es solucion
	if (k == n) {
		k--;
		return;
	}
	
	// podas
	
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
	no_visitados--;
	for (auto it = ady[k].begin(); it != ady[k].end(); ++it) {
		if (marcas[*it]++ == 0) no_visitados--;
	}
	res_parcial.push_back(k);
}

void grafoExacto::desmarcarNodo(int k) {
	marcas[k]--;
	no_visitados++;
	for (auto it = ady[k].begin(); it != ady[k].end(); ++it) {
		if (--marcas[*it] == 0) no_visitados++;
	}
	res_parcial.pop_back();
}
int main()
{
	grafoExacto g;
	g.CIDMexacto();
	g.print_res();
	
	return 0;
}