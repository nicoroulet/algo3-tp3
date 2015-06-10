#include <vector>
#include <list>
#include <iostream>
#include "grafo.h"

using namespace std;

grafolocalS::grafolocalS(): grafo(), res_parcial(), knActual(0), knPosible(-1) {}

void grafolocalS::CIDMlocalS() {
	while(knPosible < knActual) {
		encontrarSolucionLocal();
	}
}

void grafolocalS::encontrarSolucionLocal() {
// now what?
	
}

int main() {
	grafolocalS g;
	g.printGrafo();
	g.CIDMlocalS();
	g.print_res();
	return 0;
}