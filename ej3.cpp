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
	print_result();
}


int grafo::nodoMayorGrado(){
	int nodoMax = -1;
	for ( auto it = ady.begin(); it != ady.end(); ++it) {
		if (it.size() > ady[nodoMax].size()){
			nodoMax = it-ady.begin();
		}
	}
	return nodoMax;
}


void grafo::borrarNodo(int borrame) {
	int cantVecinos = ady[borrame].size();
	int j;
	for (int i = 0; i < cantVecinos; ++i) {
		j = ady[borrame][i];
		ady[j].remove(borrame);
	}
	ady[borrame].clear();
	n--;
}

void grafo::marcarCIDM(int marcame){
	list l = ady[marcame]; 
	for (std::list::iterator it = l.begin(); it != l.end(); ++it) {
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






















