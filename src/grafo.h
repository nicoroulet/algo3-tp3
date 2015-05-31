#include <vector>
#include <list>


using namespace std;

class grafo {
	
	private:
		int n, m;
		vector< list<unsigned int> > ady;
		list<unsigned int> res;
		
		
		int nodoMayorGrado();
		void borrarNodo(int borrame);
		void marcarCIDM(int marcame);
		void print_res();
		
	public:
		grafo();
		
		// void CIDMexacto();
		void CIDMgoloso();
		
};