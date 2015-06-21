from sys import argv,maxint
import subprocess
from numpy import mean , log2
import matplotlib.pyplot as plt       
# graficador: recibe un parametro que indica que ejercicio tiene que graficar (2m, 2n, etc..)


# funcion que lee el input del archivo pasado como paramentro
# input: primera linea, cant de tests distintos de cada tamano
# 	cada linea adicional tiene tamano de entrada, numero de test (de ese tamano) y tiempo de ejecucion
# 	todas las corridas del mismo test llevan el mismo numero de test
# output: una lista de tuplas (tamano de test, tiempo) donde el tiempo son los minimos de las mediciones de cada test distinto de ese tamano, promediados
def read_input(path):
	f=open(path, 'r')
	t = int(f.readline()) # cant de tests
	
	d = dict()
	for i in f: #por cada linea del archivo
		i=i.strip().split()
		i=[int(i[0]), int(i[1]), float(i[2])] # leo los 3 valores
		# if i[0] > 200:
		if not i[0] in d:
			d[i[0]] = [maxint]*t
		d[i[0]][i[1]] = min(d[i[0]][i[1]], i[2])
	l = [(i[0], mean([x for x in i[1] if x != maxint])) for i in d.items()]
	return l

def f(x):
	return x[1]
def fn(x):
	return x[1]/x[0]
def fnlogn(x):
	return x[1]/(x[0]*log2(x[0]))
def fn2(x):
	return x[1]/(x[0]**2)
def fn2logn(x):
	return x[1]/(x[0]**2*log2(x[0]))

usage="hay que pasar como parametro el ejercicio a graficar (2m, 2n, etc..)"
if (len(argv) < 2): print usage
ej=argv[1]

if (ej=="2m"):
	subprocess.call(['sh', '-c', 'mkdir -p ../graficos'])

	l=read_input("../tests/stats/ej2_m_20.stats")
	xs = [i[0] for i in l]
	ys = [f(i) for i in l]
	plt.plot(xs, ys, 'o', label="n=20")
	
	l=read_input("../tests/stats/ej2_m_30.stats")
	xs = [i[0] for i in l]
	ys = [f(i) for i in l]
	plt.plot(xs, ys, 'o', label="n=30")
	
	l=read_input("../tests/stats/ej2_m_25.stats")
	xs = [i[0] for i in l]
	ys = [f(i) for i in l]
	plt.plot(xs, ys, 'o', label="n=25")
	
	plt.xlabel("Cantidad de ejes (m)")
	plt.ylabel("Tiempo de ejecucion (seg)")
	
	plt.legend(loc=2)
	plt.savefig("../graficos/ej2_m.png")
	plt.show()
	
	
if (ej=="2n"):
	l = read_input("../tests/stats/ej2_n.stats")
	xs = [i[0] for i in l3]
	ys = [f(i) for i in l3]
	plt.plot(xs, ys, label="Sin podas")
	
	
	plt.savefig("../graficos/ej2_n.png")
	plt.show()
	
if (ej=="3"):
	
	subprocess.call(['sh', '-c', 'mkdir -p ../graficos'])
	'''l=[[float(i) for i in x.strip().split()] for x in open("../tests/stats/ej3.stats", 'r')]
	l2 = [(i[0], mean(sorted([j[2] for j in l if j[1]==i[1] and j[0]==i[0]])[2:-2])) for i in l] ## saco 2 outliers de cada lado
	l3 = [l2[i] for i in range(len(l2)) if not l2[i] in l2[:i-1]] # a esta altura, l3 son tuplas (n, promedio de tiempos de tests de tamanio n)
	'''
	l3 = read_input("../tests/stats/ej3.stats")
	xs = [i[0] for i in l3]
	ys = [f(i) for i in l3]
	plt.xlabel("Cantidad de conexiones posibles (m)")
	plt.ylabel("Tiempo de ejecucion (s)")
	plt.plot(xs, ys, 'o')
	plt.savefig("../graficos/ej3.png")
	plt.show()
	
	plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
	
	ys = [fn(i) for i in l3]
	plt.xlabel("Cantidad de conexiones posibles (m)")
	plt.ylabel("Tiempo de ejecucion / m (s)")
	plt.plot(xs, ys, 'o')
	plt.savefig("../graficos/ej3_sobre_n.png")
	plt.show()
		
	plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
	
	ys = [fnlogn(i) for i in l3]
	plt.xlabel("Cantidad de conexiones posibles (m)")
	plt.ylabel("Tiempo de ejecucion / (m*log(m)) (s)")
	plt.plot(xs, ys, 'o')
	plt.savefig("../graficos/ej3_sobre_nlogn.png")
	plt.show()
	
	ys = [fn2(i) for i in l3]
	plt.xlabel("Cantidad de conexiones posibles (m)")
	plt.ylabel("Tiempo de ejecucion / n^2 (s)")
	plt.plot(xs, ys, 'o')
	plt.savefig("../graficos/ej3_sobre_n2.png")
	plt.show()	
	
	ys = [fn2logn(i) for i in l3]
	plt.xlabel("Cantidad de pozos")
	plt.ylabel("Tiempo de ejecucion / n^2*log(n) (s)")
	plt.plot(xs, ys, 'o')
	plt.savefig("../graficos/ej3_sobre_n2logn.png")
	plt.show()	