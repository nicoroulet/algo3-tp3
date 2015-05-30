#include "grafo.h"
#include <iostream>

using namespace std;

grafo::grafo() {
	cin >> n >> m;
	ady=vector(n,list<int>());
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		ady[a].push_back(b);
		ady[b].push_back(a);
	}
	for (auto i = ady.begin(); i != ady.end(); ++i)
	{
		if (i->empty()) {
			res.push_back(i - ady.begin());
			n--;
		}
	}
}
void grafo::print_res() {
	cout << res.size();
	for (list<int>::iterator it = res.begin(); it != res.end(); ++it)
	{
		cout << " " << *it;
	}
	cout << endl;
}