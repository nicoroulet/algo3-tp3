#include "grafo.h"
#include "Tiempo.h"
#include <iostream>

int main() {
	grafoExacto g;
	g.leer_grafo();
	// g.printGrafo();
	Tiempo t; t.begin();
	
	g.CIDMexacto();
	
	t.end();
	std::cerr << g.n_nodos() << " " << g.n_ejes() << " " << t.time() << endl;
	
	g.print_res();
	return 0;
}