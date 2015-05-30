#pragma once

class grafo {
	
	private:
		int n, m;
		std::vector<std::list<unsigned int> > ady;
		std::list<unsigned int> res;
		
		
		int nodoMayorGrado();
		void borrarNodo(int borrame);
		void marcarCIDM(int marcame);
		void print_res();
		
	public:
		grafo();
		
		// void CIDMexacto();
		void CIDMgoloso();
		
};