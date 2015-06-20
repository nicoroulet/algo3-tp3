
#include "grafo.h"

using namespace std;

grafoGoloso::grafoGoloso(): grafo(), esta(n, false) {}

// grafoGoloso::grafoGoloso(grafo &g): grafo(g), esta(n, false) {}

void grafoGoloso::CIDMgoloso(){
	aux_ady = vector< list<int> >(ady);
	while(n>0) {
		marcarCIDM(nodoMayorGrado());
	}
	n = ady.size();
}


int grafoGoloso::nodoMayorGrado(){
	int nodoMax = 0;
	for (auto it = aux_ady.begin(); it != aux_ady.end(); ++it)
	{
		if (it->size() >= aux_ady[nodoMax].size() && !esta[it-aux_ady.begin()]){
			nodoMax = it-aux_ady.begin();
		}
	}
	return nodoMax;
}


void grafoGoloso::borrarNodo(int borrame) {
	for (auto it = aux_ady[borrame].begin(); it != aux_ady[borrame].end(); ++it) {
		aux_ady[*it].remove(borrame);
	}
	aux_ady[borrame].clear();
	n--;
}

void grafoGoloso::marcarCIDM(int marcame){
	if (esta[marcame]) cout << "Sos un forrrrrrrro\n";
	esta[marcame] = true;
	while(!aux_ady[marcame].empty()) { //for (auto it = aux_ady[marcame].begin(); it != aux_ady[marcame].end(); ++it) {
		esta[*aux_ady[marcame].begin()] = true;
		borrarNodo(*aux_ady[marcame].begin());
	}
	aux_ady[marcame].clear();
	n--;
	res.push_back(marcame);	
}

