#include "grafo.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

grafo::grafo() {
	cin >> n >> m;
	int a, b;
	ady.resize(n);
	// esta.assign(n,false);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		ady[a].push_back(b);
		ady[b].push_back(a);
	}
	
	// tiempo.begin();
	
	// separamos las componentes
	// BFS, numero las componentes conexas
	vector<int> num_componente(n, -1);	// aca guardo el numero de componente de cada nodo
	queue<int> q;					// cola de BFS
	int componente_actual = 0; 		// aumenta en cada nueva componente creada
	int i=0; 						// buscador de comienzo de nueva componente
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
	componentes = vector< vector<int> >(componente_actual);
	for(int i = 0; i < n; ++i) {
		componentes[num_componente[i]].push_back(i);
	}

}

grafo::grafo(grafo &g) : ady(g.ady), n(g.n), m(g.m) {}

void grafo::print_res() {
	res.sort();
	cout << res.size() << " ";
	for (auto it = res.begin(); it != res.end(); ++it)
	{
		cout << " " << *it + 1;
	}
	cout << endl;
}

void grafo::printGrafo(){
	cout << n << " " << m << endl;
	for (int i = 0; i < ady.size(); ++i) {
		cout << i + 1 << " -> ";
		for (list<int>::iterator it = ady[i].begin(); it != ady[i].end(); ++it) {
			cout << *it + 1 << " "; 			
		}
		cout << endl;
	}
}