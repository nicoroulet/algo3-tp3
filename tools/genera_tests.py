from sys import argv
import subprocess
from random import randrange

n=int(argv[1])
m=int(argv[2])#randrange(n*(n-1)/2)
f=open("../src/test.in", 'w')
f.write("%d %d\n" %(n,m))
s=set()
while len(s) < m:
	t1, t2=(randrange(n), randrange(n))
	if not ((t1+1, t2+1) in s or (t2+1,t1+1) in s or (t1==t2)): s.add((t1+1,t2+1))
for (t1,t2) in s:
	f.write("%d %d\n" %(t1,t2))
f.close()
# subprocess.call(['sh', '-c', ('rm -f ../tests/ej3/*')])
# for n in range(2*max_size/25, max_size+1, max_size/50):
# 	for i in range(cant):
# 		m=randrange(n*(n-1)/2)
# 		C=randrange(1,n**2)
# 		f=open("../tests/ej3/%d_%d.in" % (n,i), 'w')
# 		f.write("%d %d %d\n" %(n,m,C))
# 		s=set()
# 		while len(s) < m:
# 			t1, t2=(randrange(n), randrange(n))
# 			if not ((t1, t2) in s or (t2,t1) in s): s.add((t1,t2))
# 		for (t1,t2) in s:
# 			f.write("%d %d %d\n" %(t1,t2,randrange(2*C)))
# 		f.close()
