from sys import argv, exit
import os
import subprocess
from random import randrange
from math import sqrt

usage="python testgen_ej2.py max_size iters m/n"

if len(argv) < 4:
	print usage
	exit()
max_size = int(argv[1])
iters = int(argv[2])
mn = argv[3]

test_folder = os.path.join(os.path.dirname(__file__), '../tests/ej2')
subprocess.call(['sh', '-c', ('mkdir -p ' + test_folder)])



if (mn == "m"):
	#tests en funcion de m
	subprocess.call(['sh', '-c', ('mkdir -p ' + test_folder + '/m')])
	subprocess.call(['sh', '-c', ('rm -f ' + test_folder + '/m/*')])
	n = max_size
	for sqrtm in range(int(sqrt(n)), n-2):
		m = (sqrtm**2)/2 # m va entre n/2 y (n-2)**2/2
		for i in range(iters):
			f = open(test_folder + "/m/%d_%d.in" %(m,i))
			f.write("%d %d\n" %(n,m))
			s=set()
			while len(s) < m:
				t1, t2=(randrange(n), randrange(n))
				if not ((t1, t2) in s or (t2,t1) in s or t1==t2): 
					s.add((t1,t2))
					f.write("%d %d\n" %(t1,t2))
			f.close()


if (mn == "n"):
	#tests en funcion de n
	subprocess.call(['sh', '-c', ('mkdir -p ' + test_folder + '/n')])
	subprocess.call(['sh', '-c', ('rm -f ' + test_folder + '/n/*')])

	for n in range(max_size/5, max_size):
		
		m = ((n-2)*(n-1)/2)
		for i in range(iters):
			f = open(test_folder + "/n/%d_%d.in" %(n,i))
			f.write("%d %d\n" %(n,m))
			s=set()
			while len(s) < m:
				t1, t2=(randrange(n), randrange(n))
				if not ((t1, t2) in s or (t2,t1) in s): 
					s.add((t1,t2))
					f.write("%d %d\n" %(t1,t2))
			f.close()

		
