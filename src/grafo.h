#pragma once

#include <vector>
#include <list>

class grafo {
	protected:
		int n, m;
		std::vector< std::list<int> > ady;
		std::vector< std::vector<int> > componentes;
		std::list<int> res;
		
	public:
		grafo();
		grafo(grafo &g);
		void print_res();
		void printGrafo();
};

class grafoExacto : public grafo {
	protected:
		std::vector<int> n_provisorio;
		std::vector<int> n_final;
		std::vector<int> no_visitados;
		int k;
		int act; // numero de componente siendo resuelta
		
		
		std::list<int> res_parcial;
		std::vector<int> marcas;
		
		
		void marcarNodo(int k);
		void desmarcarNodo(int k);
		void subCIDMexacto();
		
	public:
		grafoExacto();
		void CIDMexacto();
};

class grafoGoloso : public grafo {
	protected:
		std::vector<bool> esta;
		int nodoMayorGrado();
		void borrarNodo(int borrame);
		void marcarCIDM(int marcame);
		
	public:
		grafoGoloso();
		grafoGoloso(grafo &g);
		void CIDMgoloso();
};

class grafoLocalS : public grafo {
	protected:
		int knActual;
		int knPosible;
		std::list<int> res_parcial;
		void encontrarSolucionLocal();

	public:
		grafoLocalS();
		void CIDMlocalS();
};