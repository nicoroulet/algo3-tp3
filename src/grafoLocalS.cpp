#include <vector>
#include <list>
#include <iostream>
#include "grafo.h"


using namespace std;
void print(list<int> &l) {
	
	for (auto it = l.begin(); it != l.end(); ++it) {
		cout << *it << " ";
	}cout <<endl;
} 

void print(vector<int> &l) {
	
	for (auto it = l.begin(); it != l.end(); ++it) {
		cout << *it << " ";
	}cout <<endl;
} 

list<int> interseccion(list<int> &a, list<int> &b) {
	// pre: a y b estan ordenadas
	list<int> intersection;
	auto ita = a.begin();
	auto itb = b.begin();
	while (ita != a.end() && itb != b.end()) {
		if (*ita == *itb) {
			intersection.push_back(*ita);
			ita++; itb++;
		} else (*ita < *itb)? ita++ : itb++;
	}
	return intersection;
}

grafoLocalS::grafoLocalS(): grafoGoloso()  {}

void grafoLocalS::CIDMLocalS() {
	no_visitados=n;
	marcas=vector<int>(n,0);
	sorted_ady = vector<list<int> >(ady);
	for (int i = 0; i < n; ++i){
		sorted_ady[i].sort(); // nlogn
	}
	
	CIDMgoloso();
	
	for (auto i = res.begin(); i != res.end(); ++i) {
		marcarNodo(*i);
	}
	
	int prevResSize;
	do {
		prevResSize = res.size();
		sacar2poner1();
		sacar3poner1();
		sacar3poner2();
	} while(res.size() < prevResSize);
}


void grafoLocalS::sacar3poner1() {
	for (auto i = res.begin(); i != res.end(); ++i) {
		for (auto j = next(i); j != res.end(); ++j) {
			for (auto k = next(j); k != res.end(); ++k) {
				list<int> candidatos = interseccion(sorted_ady[*i], sorted_ady[*j]);
				candidatos = interseccion(candidatos, sorted_ady[*k]);
				for (auto it = candidatos.begin(); it != candidatos.end() && k != res.end(); ++it) {
					if (marcas[*it] == 3) {
						desmarcarNodo(*i);
						desmarcarNodo(*j);
						desmarcarNodo(*k);
						marcarNodo(*it);
						if (no_visitados == 0) {
							// cerr << "s3p1\n";
							res.push_front(*it);
							k = res.erase(k);
							j = res.erase(j);
							i = res.erase(i);
							if (k==j && k != res.end()) k++;
							if (i==j && j != res.end()) j++;
							if (k==j && k != res.end()) k++;
						} else {
							desmarcarNodo(*it);
							marcarNodo(*i);
							marcarNodo(*j);
							marcarNodo(*k);
						}
					}
				}
				if (k == res.end()) k--;
			}
			if (j == res.end()) j--;
		}
		if (i == res.end()) i--;
	}
}

void grafoLocalS::sacar2poner1() {
	for (auto i = res.begin(); i != res.end(); ++i) {
		for (auto j = next(i); j != res.end(); ++j) {
			list<int> candidatos = interseccion(sorted_ady[*i], sorted_ady[*j]);
			// print(sorted_ady[*i]);
			// print(sorted_ady[*j]);
			// print(candidatos);
			// cout << "---------\n";
			for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
				if (marcas[*it] == 2) {
					desmarcarNodo(*i);
					desmarcarNodo(*j);
					marcarNodo(*it);
					if (no_visitados == 0) {
						// cout << "CACA, vieja, CACA\n";
						res.push_front(*it);
						j = res.erase(j);
						i = res.erase(i);
						if (i==j && j != res.end()) j++;
					} else {
						desmarcarNodo(*it);
						marcarNodo(*i);
						marcarNodo(*j);
					}
				}
			}
		}
	}
}



void grafoLocalS::sacar3poner2() {
	for (auto i = res.begin(); i != res.end(); ++i) {
		for (auto j = next(i); j != res.end(); ++j) {
			list<int> candidatos = interseccion(sorted_ady[*i], sorted_ady[*j]);
			for (auto k = res.begin(); k != res.end(); ++k) {
				while(k == j || k == i) k++;
				if (k == res.end()) break;
				// print(sorted_ady[*i]);
				// print(sorted_ady[*j]);
				// print(candidatos);
				// cout << "---------\n";
				for (auto poneme1 = candidatos.begin(); poneme1 != candidatos.end(); ++poneme1) {
					if (marcas[*poneme1] == 2) {
						desmarcarNodo(*j);
						desmarcarNodo(*i);
						marcarNodo(*poneme1);
						for (auto poneme2 = sorted_ady[*k].begin(); poneme2 != sorted_ady[*k].end(); ++poneme2) {
							if (marcas[*poneme2] == 1) {
								desmarcarNodo(*k);
								marcarNodo(*poneme2);
							}
							if (no_visitados == 0) {
								res.push_front(*poneme1);
								res.push_front(*poneme2);
								res.erase(j);
								res.erase(i);
								res.erase(k);
								return;
								// if (i==j && j != res.end()) j++;
								
								// if (k == i) {
								// 	i++;
								// 	k = res.erase(k); // habia que borrar i
								// 	k++; // i no puede ser end() aca
								// 	if (i==j && j != res.end()) j++;
								// 	if (k == j && )
								// } else if (k == j) {
								// 	j++;
								// 	k = res.erase(k);
									
								// }
								// i = res.erase(i);
								// if (i==j && j != res.end()) j++;
							} else {
								desmarcarNodo(*poneme1);
								desmarcarNodo(*poneme2);
								marcarNodo(*i);
								marcarNodo(*j);
								marcarNodo(*k);
							}
						}
					}
				}
			}
		}
	}
}


void grafoLocalS::marcarNodo(int marcame) {
	// if (marcas[marcame] != 0) cout << "esta haciendo cualquieraa\n";
	marcas[marcame]++;
	no_visitados--;
	for (auto it = sorted_ady[marcame].begin(); it != sorted_ady[marcame].end(); ++it) {
		if (marcas[*it] == 0) {
			no_visitados--;
		}
		marcas[*it]++;
	}
}

void grafoLocalS::desmarcarNodo(int desmarcame) {
	marcas[desmarcame]--;
	// if (marcas[desmarcame] != 0) cout << "esta haciendo cualquiera\n";
	no_visitados++;
	for (auto it = sorted_ady[desmarcame].begin(); it != sorted_ady[desmarcame].end(); ++it) {
		if (marcas[*it] == 1) {
			no_visitados++;
		}
		marcas[*it]--;
	}
}