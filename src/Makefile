FLAGS= -g -std=c++11
all: ej2 ej3 ej4 ej5

ej2: ej2.cpp grafo.h grafo.cpp grafoExacto.cpp Tiempo.h
	g++ $(FLAGS) ej2.cpp grafo.cpp grafoExacto.cpp -o ej2

ej3: ej3.cpp grafo.h grafo.cpp grafoGoloso.cpp Tiempo.h
	g++ $(FLAGS) ej3.cpp grafo.cpp grafoGoloso.cpp -o ej3
	
ej4: ej4.cpp grafo.h grafo.cpp grafoLocalS.cpp grafoGoloso.cpp Tiempo.h
	g++ $(FLAGS) ej4.cpp grafo.cpp grafoGoloso.cpp grafoLocalS.cpp -o ej4

ej5: ej5.cpp grafo.h grafo.cpp grafoLocalS.cpp grafoGRASP.cpp Tiempo.h
	g++ $(FLAGS) ej5.cpp grafo.cpp grafoGRASP.cpp grafoLocalS.cpp grafoGoloso.cpp -o ej5

clean:
	rm -f ej1
	rm -f ej2
	rm -f ej3
	rm -f ej4
	rm -f ej5