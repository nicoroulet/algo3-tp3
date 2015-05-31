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
	cout << "anduvo nodo mayor grado: " << nodoMax << endl;
	return nodoMax;
}


void grafo::borrarNodo(int borrame) {
	for (auto it = ady[borrame].begin(); it != ady[borrame].end(); ++it) {
		ady[*it].remove(borrame);
	}
	ady[borrame].clear();
	n--;
	cout << "anduvo borrarNodo" << endl;
}

void grafo::marcarCIDM(int marcame){
	cout << "entre funcion" << endl;
	//list<int> l = ; 
	cout << "entre funcion" << endl;
	for (auto it = ady[marcame].begin(); it != ady[marcame].end(); ++it) {
		cout << "me parece que no borra nodo" << endl;
		borrarNodo(*it);
	}
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






















