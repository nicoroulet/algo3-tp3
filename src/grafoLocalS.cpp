#include <vector>
#include <list>
#include <iostream>
#include "grafo.h"


using namespace std;
void print(list<int> &l) {
	
	for (auto it = l.begin(); it != l.end(); ++it) {
		cout << *it << " ";
	}cout <<endl;
} 

void print(vector<int> &l) {
	
	for (auto it = l.begin(); it != l.end(); ++it) {
		cout << *it << " ";
	}cout <<endl;
} 

list<int> interseccion(list<int> &a, list<int> &b) {
	// pre: a y b estan ordenadas
	list<int> intersection;
	auto ita = a.begin();
	auto itb = b.begin();
	while (ita != a.end() && itb != b.end()) {
		if (*ita == *itb) {
			intersection.push_back(*ita);
			ita++; itb++;
		} else (*ita < *itb)? ita++ : itb++;
	}
	return intersection;
}

grafoLocalS::grafoLocalS(): grafoGoloso(), marcas(n,0), no_visitados(n)  {}

void grafoLocalS::CIDMLocalS() {
	
	sorted_ady = vector<list<int> >(ady);
	for (int i = 0; i < n; ++i){
		sorted_ady[i].sort(); // nlogn
	}
	
	CIDMgoloso();
	
	for (auto i = res.begin(); i != res.end(); ++i) {
		marcarNodo(*i);
	}
	
	int gusGil;
	do {
		gusGil = res.size();
		encontrarSolucionLocal();
	} while(res.size() < gusGil);
}

void grafoLocalS::encontrarSolucionLocal() {
	for (auto i = res.begin(); i != res.end(); ++i) {
		for (auto j = next(i); j != res.end(); ++j) {
			list<int> candidatos = interseccion(sorted_ady[*i], sorted_ady[*j]);
			// print(sorted_ady[*i]);
			// print(sorted_ady[*j]);
			// print(candidatos);
			// cout << "---------\n";
			for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
				if (marcas[*it] == 2) {
					desmarcarNodo(*i);
					desmarcarNodo(*j);
					marcarNodo(*it);
					if (no_visitados == 0) {
						// cout << "CACA, vieja, CACA\n";
						res.push_front(*it);
						j = res.erase(j);
						i = res.erase(i);
						if (i==j && j != res.end()) j++;
					} else {
						desmarcarNodo(*it);
						marcarNodo(*i);
						marcarNodo(*j);
					}
				}
			}
		}
	}
}


void grafoLocalS::marcarNodo(int marcame) {
	// if (marcas[marcame] != 0) cout << "esta haciendo cualquieraa\n";
	marcas[marcame]++;
	no_visitados--;
	for (auto it = sorted_ady[marcame].begin(); it != sorted_ady[marcame].end(); ++it) {
		if (marcas[*it] == 0) {
			no_visitados--;
		}
		marcas[*it]++;
	}
}

void grafoLocalS::desmarcarNodo(int desmarcame) {
	marcas[desmarcame]--;
	// if (marcas[desmarcame] != 0) cout << "esta haciendo cualquiera\n";
	no_visitados++;
	for (auto it = sorted_ady[desmarcame].begin(); it != sorted_ady[desmarcame].end(); ++it) {
		if (marcas[*it] == 1) {
			no_visitados++;
		}
		marcas[*it]--;
	}
}