
#include <vector>
#include <list>
#include <iostream>
#include "grafo.h"

using namespace std;

grafoGoloso::grafoGoloso(): grafo(), esta(n, false) {}

void grafoGoloso::CIDMgoloso(){
	while(n>0) {
		marcarCIDM(nodoMayorGrado());
	}
	print_res();
}


int grafoGoloso::nodoMayorGrado(){
	int nodoMax = 0;
	for (auto it = ady.begin(); it != ady.end(); ++it)
	{
		if (it->size() >= ady[nodoMax].size() && !esta[it-ady.begin()]){
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
	esta[marcame] = true;
	while(!ady[marcame].empty()) { //for (auto it = ady[marcame].begin(); it != ady[marcame].end(); ++it) {
		esta[*ady[marcame].begin()] = true;
		borrarNodo(*ady[marcame].begin());
	}
	ady[marcame].clear();
	n--;
	res.push_back(marcame);	
}


int main() {
	grafoGoloso g;
	g.printGrafo();
	g.CIDMgoloso();
	return 0;
}















