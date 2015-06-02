#include <vector>
#include <list>
#include <iostream>
#include "grafo.h"

using namespace std;

void grafo::CIDMgoloso(){
	while(n>0) {
		marcarCIDM(nodoMayorGrado());
	}
	cout << "anduvo CIDMgoloso" << endl;
	print_res();
}


int grafo::nodoMayorGrado(){
	int nodoMax = 0;
	for (auto it = ady.begin(); it != ady.end(); ++it)
	{
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
	cout << "nodo a marcar es " << marcame<< endl;
	for (auto it = ady[marcame].begin(); it != ady[marcame].end(); ++it) {
		cout << "nodo borrarNodo es " << *it << endl;
		borrarNodo(*it);
	}
	cout << "sali" << endl;
	ady[marcame].clear();
	n--;
	res.push_back(marcame);	
	cout << "anduvo marcarCIDM" << endl;
}


int main() {
	grafo g;
	g.printGrafo();
	g.CIDMgoloso();
	return 0;
}






















