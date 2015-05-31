#include <vector>
#include <list>
#include "grafo.h"

using namespace std;

void grafo::CIDMgoloso(){
	int marcar;
	while(n>0) {
		marcar = nodoMayorGrado();
		marcarCIDM(marcar);
	}
	print_res();
}


int grafo::nodoMayorGrado(){
	int nodoMax = -1;
	for ( auto it = ady.begin(); it != ady.end(); ++it) {
		if (it->size() > ady[nodoMax].size()){
			nodoMax = it-ady.begin();
		}
	}
	return nodoMax;
}


void grafo::borrarNodo(int borrame) {
	for (auto it = ady[borrame].begin(); it != ady[borrame].end(); ++it) {
		ady[*it].remove(borrame);
	}
	ady[borrame].clear();
	n--;
}

void grafo::marcarCIDM(int marcame){
	list<unsigned int> l = ady[marcame]; 
	for (auto it = l.begin(); it != l.end(); ++it) {
		borrarNodo(*it);
	}
	l.clear();
	n--;
	res.push_back(marcame);	
}


int main() {
	grafo g;
	g.CIDMgoloso();
	return 0;
}






















