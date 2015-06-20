#include "grafo.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


grafoExacto::grafoExacto(): grafo(), res_parcial() {}

	


void grafoExacto::CIDMexacto() {

	// separamos las componentes
	// BFS, numero las componentes conexas
	vector<int> num_componente(n, -1);	// aca guardo el numero de componente de cada nodo
	queue<int> q;					// cola de BFS
	int componente_actual = 0; 		// aumenta en cada nueva componente creada
	int i=0; 						// buscador de comienzo de nueva componente
	res_parcial.push_back(10);
	while (i < n) {
		q.push(i);
		while(!q.empty()) {
			int nodo = q.front(); q.pop();
			if (num_componente[nodo] == -1) {
				num_componente[nodo] = componente_actual;
				for (auto it = ady[nodo].begin(); it != ady[nodo].end(); ++it) {
					q.push(*it);
				}
			}
		}
		componente_actual++;
		while (num_componente[i] != -1 && i<n) ++i;
	}
	
	// cout << "componentes:" << componente_actual << endl;
	// cout << "ejes:" << m << endl;
	// al terminar, compontente_actual vale la cantidad total de componentes conexas
	componentes = vector< vector<int> >(componente_actual, vector<int>());
	for(int i = 0; i < n; ++i) {
		componentes[num_componente[i]].push_back(i);
	}
	// inicializo variables
	marcas = vector<int>(n, 0);
	grados_max = vector<int>(n);
	n_provisorio = vector<int>(componente_actual, 0);
	n_final = vector<int>(componente_actual, n+1);
	no_visitados = vector<int>(componente_actual);
	for(int i = 0; i < componente_actual; ++i) {
		no_visitados[i] = componentes[i].size();
	}
	
	// calculo los grados 
	for(int i = 0; i < n; ++i) {
		grados_max[i] = ady[i].size()+1;
	}
	sort(grados_max.begin(), grados_max.end(), greater<int>()); // ordeno de mayor a menor
	for(int i = 1; i < n; ++i) {
		grados_max[i] += grados_max[i-1];
	}
	
	// resuelvo
	for (act = 0; act < componente_actual; act++) {
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
	// for (auto it = marcas.begin(); it != marcas.end(); ++it) {cout << *it << " ";} cout << endl;
	// cout << no_visitados[act] << endl;
	if (no_visitados[act] == 0) {
		if (n_provisorio[act] < n_final[act]) {
			res.clear();
			res = list<int>(res_parcial);
			n_final[act]=n_provisorio[act];
		}
		// cout << "actualice\n";
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
	if (n_provisorio[act] >= 1 && no_visitados[act] > grados_max[n_final[act]-n_provisorio[act]-1]) {
		// cout << "poda grados_max, no_visitados=" << no_visitados[act] << " grado_max= " << n_final[act]-n_provisorio[act]-1 << endl;
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

