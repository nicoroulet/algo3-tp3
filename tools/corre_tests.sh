iters=20

mkdir -p ../tests/stats

#ejercicio 2
if [ $1 = 2m ]; then
	for n in {25..25} # valores de n para testear en funcion de m
	do 
		python testgen_ej2.py $n $iters m 	# genero los tests en funcion de m
		rm -f ../tests/stats/ej2_m_$n.stats
		echo $iters > ../tests/stats/ej2_m_$n.stats	# el graficador toma como primera linea iters
		for test in ../tests/ej2/m/*.in
		do
			echo "test $test"
			i=${test#*_}
			i=${i%.in} # me quedo con el segundo numero del nombre (el numero de test)
			
			for _ in {1..20}
			do
				# corro los tests, con awk me quedo con colmuna 2 y 3 (m y tiempo) y num. de test y lo appendeo a las stats 
				cat $test | ../src/ej2 2>&1  >/dev/null | awk '{print $2 " '$i' " $3}' >> ../tests/stats/ej2_m_$n.stats
				
			done
		done
	done
	python graficar.py 2m
fi

if [ $1 = 2n ]; then
	python testgen_ej2.py $n2n $iters n 	# genero los tests en funcion de n
	rm -f ../tests/stats/ej2_n.stats
	echo $n2n $iters > ../tests/stats/ej2_n.stats	# el graficador toma como primera linea iters
	for test in ../tests/ej2/n/*.in
	do
		echo "test $test"
		i=${test#*_}
		i=${i%.in} # me quedo con el segundo numero del nombre (el numero de test)
		
		for _ in {1..20}
		do
			# corro los tests, con awk me quedo con colmuna 1 y 3 (n y tiempo) y num. de test
			# tiro stdout y mando stderr a stdout y lo appendeo a las stats 
			cat $test | ../src/ej2  >/dev/null | awk '{print $1 " '$i' " $3}' 2>> ../tests/stats/ej2_n.stats
			
		done
	done
	python graficar.py 2n
fi

# ejercicio 3
if [ $1 = 3 ]; then
	python genera_tests.py 3 $n3 $iters
	echo $n3 $iters > ../tests/stats/ej3.stats
	for test in ../tests/ej3/*.in
	do
		echo "test $test"
		i=${test#*_}
		i=${i%.in}
		for _ in {1..20}
		do
			cat $test | ../src/ej3 ../tests/stats/ej3.stats $i > /dev/null
		done
	done
	python graficar.py 3
fi

if [ $1 = 31 ]; then
	python genera_tests.py 31 $n3 1
	echo $n3 $iters > ../tests/stats/ej3_garca.stats
	for test in ../tests/ej3/*.in
	do
		echo "test $test"
		i=${test#*_}
		i=${i%.in}
		for _ in {1..20}
		do
			cat $test | ../src/ej3 ../tests/stats/ej3.stats $i > /dev/null
		done
	done
	python graficar.py 3
fi