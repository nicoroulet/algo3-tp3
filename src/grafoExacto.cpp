#include "grafo.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


grafoExacto::grafoExacto(): grafo(), res_parcial(), marcas(n, 0), grados_max(n)
{
	// marco nodos aislados
	//poda: hardcodear casos chicos
	// for (int i = 0; i < n; ++i)
	// {
		// if (ady[i].empty()) // marco los nodos aislados
		// 	marcarNodo(i);
		// if (marcas[i] == 0) { // marco los nodos que son el centro de una "estrella"
		// 	auto it = ady[i].begin();
		// 	while (it != ady[i].end() && ady[*it].size() == 1) ++it;
		// 	if (it == ady[i].end())
		// 		marcarNodo(i);
		// }
	// }
	

	int n_componentes = componentes.size();
	n_provisorio = vector<int>(n_componentes, 0);
	n_final = vector<int>(n_componentes, n+1);
	no_visitados = vector<int>(n_componentes);
	for(int i = 0; i < n_componentes; ++i) {
		no_visitados[i] = componentes[i].size();
	}
	
	// for (int i = 0; i < n; ++i) {
	// 	if (ady[i].empty()) {
	// 		res.push_back(i);
	// 		n--;
	// 	}
	// }
	
	// calculo los grados 
	for(int i = 0; i < n; ++i) {
		grados_max[i] = ady[i].size()+1;
	}
	sort(grados_max.begin(), grados_max.end(), greater<int>()); // ordeno de mayor a menor
	for(int i = 1; i < n; ++i) {
		grados_max[i] += grados_max[i-1];
	}
	
	
	// cota inicial
	// grafoGoloso aux(*this);
	// n_final = aux.CIDMgoloso()+1;
}

void grafoExacto::CIDMexacto() {
	for (act = 0; act < componentes.size(); act++)
	{
		k = -1;
		// cout << "resolviendo componente " << act << " de tamanio " << componentes[act].size() << endl;
		res_parcial.swap(res); //empiezo desde donde dejo la componente conexa anterior
		subCIDMexacto();
	}
	
	// tiempo.end();
	// ofstream f("../tests/stats/tmp_stats.dat", ofstream::app); f << n << " " << m << " " << tiempo.time() << endl;
}

void grafoExacto::subCIDMexacto() {
	k++;
	int nodo = componentes[act][k]; // el numero del nodo en el grafo original 
	// si es solucion
	if (no_visitados[act] == 0) {
		if (n_provisorio[act] < n_final[act]) {
			res.clear();
			res = list<int>(res_parcial);
			n_final[act]=n_provisorio[act];
		}
		k--;
		return;
	}
	// si no es solucion
	if (k == componentes[act].size()) {
		k--;
		return;
	}
	
	// poda: soluciones inutiles
	if (n_provisorio[act] >= n_final[act]-1) {
		k--;
		return;
	}
	
	// poda grados_max: si no hay chances de llegar 
	if (no_visitados[act] > grados_max[n_final[act]-n_provisorio[act]-1]) {
		k--; return;
	}
	

	subCIDMexacto();
	if (marcas[nodo] == 0) {
		marcarNodo(nodo);
		subCIDMexacto();
		desmarcarNodo(nodo);
	}
	k--;
	return;
}

void grafoExacto::marcarNodo(int marcame) {
	marcas[marcame]++;
	n_provisorio[act]++;
	no_visitados[act]--;
	for (auto it = ady[marcame].begin(); it != ady[marcame].end(); ++it) {
		if (marcas[*it]++ == 0) no_visitados[act]--;
	}
	res_parcial.push_back(marcame);
}

void grafoExacto::desmarcarNodo(int desmarcame) {
	marcas[desmarcame]--;
	n_provisorio[act]--;
	no_visitados[act]++;
	for (auto it = ady[desmarcame].begin(); it != ady[desmarcame].end(); ++it) {
		if (--marcas[*it] == 0) no_visitados[act]++;
	}
	res_parcial.pop_back();
}

