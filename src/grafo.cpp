#include "grafo.h"
#include <iostream>

using namespace std;

grafo::grafo() {
	cin >> n >> m;
	int a, b;
	ady.resize(n);
	esta.assign(n,false);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--, b--;
		ady[a].push_back(b);
		ady[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		if (ady[i].empty()) {
			res.push_back(i);
			n--;
		}
	}
}
void grafo::print_res() {
	cout << res.size();
	for (auto it = res.begin(); it != res.end(); ++it)
	{
		cout << " " << *it + 1;
	}
	cout << endl;
}

void grafo::printGrafo(){
	cout << n << " " << m << endl;
	for (int i = 0; i < ady.size(); ++i) {
		cout << i + 1 << " -> ";
		for (list<int>::iterator it = ady[i].begin(); it != ady[i].end(); ++it) {
			cout << *it + 1 << " "; 			
		}
		cout << endl;
	}
}