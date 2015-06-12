FLAGS= -g -std=c++11
all: ej2 ej3 ej4

ej2: ej2.cpp grafo.h grafo.cpp grafoExacto.cpp grafoGoloso.cpp 
	g++ $(FLAGS) ej2.cpp grafo.cpp grafoExacto.cpp grafoGoloso.cpp -o ej2

ej3: ej3.cpp grafo.h grafo.cpp grafoGoloso.cpp
	g++ $(FLAGS) ej3.cpp grafo.cpp grafoGoloso.cpp -o ej3
	
ej4: ej4.cpp grafo.h grafo.cpp grafoLocalS.cpp grafoGoloso.cpp 
	g++ $(FLAGS) ej4.cpp grafo.cpp grafoGoloso.cpp grafoLocalS.cpp -o ej4

clean:
	rm -f ej1
	rm -f ej2
	rm -f ej3
	rm -f ej4