#include "grafo.h"
#include "Tiempo.h"
#include <iostream>

int main() {
	grafoGRASP g;	
	g.leer_grafo();
	// g.printGrafo();
	Tiempo t; t.begin();
	
	g.CIDMGRASP(10, 100);
	
	t.end();
	std::cerr << g.n_nodos() << " " << t.time() << endl;
	
	g.print_res();
	return 0;
}