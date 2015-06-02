#include <vector>
#include <list>


using namespace std;

class grafo {
	protected:
		int n, m;
		vector< list<int> > ady;
		list<int> res;
		void print_res();
		
	public:
		grafo();
		void printGrafo();
};

class grafoExacto : public grafo {
	protected:
		int n_provisorio;
		int n_final;
		
		vector<int> marcas;
		
	public:
		void CIDMexacto();
		
};

class grafoGoloso : public grafo {
	protected:
		int nodoMayorGrado();
		void borrarNodo(int borrame);
		void marcarCIDM(int marcame);
		
	public:
		void CIDMgoloso();
};