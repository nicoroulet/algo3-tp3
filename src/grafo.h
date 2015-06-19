#pragma once

#include <vector>
#include <iostream>
#include <list>
// #include "Tiempo.h"

class grafo {
	protected:
		int n, m;
		std::vector< std::list<int> > ady;
		std::vector< std::vector<int> > componentes;
		std::list<int> res;
		// Tiempo tiempo;
		
	public:
		grafo();
		grafo(grafo &g);
		void print_res();
		void printGrafo();
};

class grafoExacto : public grafo {
	protected:
		std::vector<int> n_provisorio; // cantidad de nodos en la combinacion actual
		std::vector<int> n_final; // cantidad de nodos en la mejor solucion encontrada hasta ahora
		std::vector<int> no_visitados; // nodos que falta cubrir
		int k; // numero de nodo actual en la iteracion
		int act; // numero de componente siendo resuelta
		
		
		std::list<int> res_parcial; // mejor solucion encontrada
		std::vector<int> marcas;
		
		//para poda grados_max
		std::vector<int> grados_max; // [i]: suma de los grados de los i nodos con mayor grado + i

		
		void marcarNodo(int marcame);
		void desmarcarNodo(int desmarcame);
		void subCIDMexacto();
		
	public:
		grafoExacto();
		void CIDMexacto();
};

class grafoGoloso : public grafo {
	protected:
		std::vector< std::list<int> > aux_ady;
		std::vector<bool> esta;
		int nodoMayorGrado();
		void borrarNodo(int borrame);
		void marcarCIDM(int marcame);
		
		
	public:
		grafoGoloso();
		grafoGoloso(grafo &g);
		void CIDMgoloso();
};

class grafoLocalS : public grafoGoloso {
	protected:
		void sacar2poner1();
		void sacar3poner2();
		
		std::vector< std::list<int> > sorted_ady;
		
		int no_visitados;
		std::vector<int> marcas;
		void marcarNodo(int marcame);
		void desmarcarNodo(int desmarcame);
		
	public:
		grafoLocalS();
		void CIDMLocalS();
};

class grafoGRASP : public grafoLocalS {
	protected:
		int nodosMayorGrado(int cantCandidatos);
		std::list<int> res_final;
	public:
		grafoGRASP();
		grafoGRASP(grafo &g);
		void CIDMGRASP(int cant, int iteraciones);
};