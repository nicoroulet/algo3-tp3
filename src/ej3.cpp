#include "grafo.h"
#include "Tiempo.h"
#include <iostream>

int main() {
	grafoGoloso g;
	g.leer_grafo();
	// g.printGrafo();
	Tiempo t; t.begin();
	
	g.CIDMgoloso();
	
	t.end();
	std::cerr << g.n_nodos() << " " << t.time() << endl;
	
	g.print_res();
	return 0;
}















