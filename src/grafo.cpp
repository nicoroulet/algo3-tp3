#include "grafo.h"
#include <iostream>

using namespace std;

grafo::grafo() {
	cin >> n >> m;
	vector< list<int> > ady(n,list<int>());
	int a, b;
	for (int i = 0; i < m; ++i)
	{	cin >> a >> b;
		a--, b--;
		ady[a].push_back(b);
		ady[b].push_back(a);
	}
	for (auto it = ady.begin(); it != ady.end(); ++it)
	{
		if (it->empty()) {
			res.push_back(it - ady.begin());
			n--;
		}
	}
}
void grafo::print_res() {
	cout << res.size();
	for (auto it = res.begin(); it != res.end(); ++it)
	{
		cout << " " << *it;
	}
	cout << endl;
}

void grafo::printGrafo(){
	cout << n << " " << m << endl;
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << "->";
		for (auto it = ady[i].begin(); it != ady[i].end(); ++it) {
			cout << *it + 1 << " "; 			
		}
		cout << endl;
	}
}