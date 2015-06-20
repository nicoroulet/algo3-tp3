#include "grafo.h"
#include <vector>
#include <iostream>

using namespace std;


grafo::grafo(): res() {}

// grafo::grafo(grafo &g) : ady(g.ady), n(g.n), m(g.m) {}

void grafo::leer_grafo() {
	cin >> n >> m;
	int a, b;
	ady = vector<list<int> >(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		ady[a].push_back(b);
		ady[b].push_back(a);
	}
}

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

int grafo::n_nodos() {return n;}

int grafo::n_ejes() {return m;}