#include <vector>
#include <list>
#include <iostream>
#include "grafo.h"

using namespace std;

void grafoGoloso::CIDMgoloso(){
	while(n>0) {
		marcarCIDM(nodoMayorGrado());
	}
	cout << "anduvo CIDMgoloso" << endl;
	print_res();
}


int grafoGoloso::nodoMayorGrado(){
	int nodoMax = 0;
	for (auto it = ady.begin(); it != ady.end(); ++it)
	{
		if (it->size() > ady[nodoMax].size()){
			nodoMax = it-ady.begin();
		}
	}
	return nodoMax;
}


void grafoGoloso::borrarNodo(int borrame) {
	for (auto it = ady[borrame].begin(); it != ady[borrame].end(); ++it) {
		ady[*it].remove(borrame);
	}
	ady[borrame].clear();
	n--;
}

void grafoGoloso::marcarCIDM(int marcame){
	cout << "nodo a marcar es " << marcame+1<< endl;
	while(!ady[marcame].empty()) { //for (auto it = ady[marcame].begin(); it != ady[marcame].end(); ++it) {
		cout << "nodo borrarNodo es " << *ady[marcame].begin()+1 << endl;
		borrarNodo(*ady[marcame].begin());
		printGrafo();	
	}
	cout << "sali" << endl;
	ady[marcame].clear();
	n--;
	res.push_back(marcame);	
	cout << "anduvo marcarCIDM" << endl;
}


int main() {
	grafoGoloso g;
	g.printGrafo();
	g.CIDMgoloso();
	return 0;
}






















