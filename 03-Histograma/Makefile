clean_files = graficador.o Switch.o mainSwitch.o Goto.o mainGoto.o Recursivo.o mainRecursivo.o Tabla.o mainTabla.o

1:Switch clean
2:Goto clean
3:Recursivo clean
4:Tabla clean



graficador.o: Graficador.c Graficador.h
	@gcc -c Graficador.c -o graficador.o

Switch.o: histograma-1-enum-switch.c histograma.h
	@gcc -c histograma-1-enum-switch.c -o Switch.o 

Goto.o: histograma-2-goto.c histograma.h
	@gcc -c histograma-2-goto.c -o Goto.o 

Recursivo.o: histograma-3-rec.c histograma.h
	@gcc -c histograma-3-rec.c -o Recursivo.o 

Tabla.o: histograma-x.c histograma.h
	@gcc -c histograma-x.c -o Tabla.o 


mainSwitch.o : main.c Switch.o graficador.o 
	@gcc -c main.c -o mainSwitch.o

Switch: mainSwitch.o Switch.o graficador.o 
	@gcc $^ -o Switch
	@./Switch
	@rm -f Switch
	@rm -f Switch.o
	@rm -f graficador.o


mainGoto.o : main.c Goto.o graficador.o 
	@gcc -c main.c -o mainGoto.o

Goto: mainGoto.o Goto.o graficador.o 
	@gcc $^ -o Goto
	@./Goto
	@rm -f Goto
	@rm -f Goto.o
	@rm -f graficador.o

mainRecursivo.o : main.c Recursivo.o graficador.o 
	@gcc -c main.c -o mainRecursivo.o

Recursivo: mainRecursivo.o Recursivo.o graficador.o 
	@gcc $^ -o Recursivo
	@./Recursivo
	@rm -f Recursivo
	@rm -f Recursivo.o
	@rm -f graficador.o

mainTabla.o : main.c Tabla.o graficador.o 
	@gcc -c main.c -o mainTabla.o
Tabla: mainTabla.o Tabla.o graficador.o 
	@gcc $^ -o Tabla
	@./Tabla
	@rm -f Tabla
	@rm -f Tabla.o
	@rm -f graficador.o


# Regla para ejecutar todos los tests

testSwitch.o: Test.c histograma.h
	@gcc -c Test.c -o testSwitch.o

# Regla para compilar testGoto.o
testGoto.o: Test.c histograma.h
	@gcc -c Test.c -o testGoto.o

# Regla para compilar testRecursivo.o
testRecursivo.o: Test.c histograma.h
	@gcc -c Test.c -o testRecursivo.o

# Regla para compilar testTabla.o
testTabla.o: Test.c histograma.h
	@gcc -c Test.c -o testTabla.o

# Regla para ejecutar todos los tests
tests: testSwitch testGoto testRecursivo testTabla

testSwitch: testSwitch.o Switch.o graficador.o
	@gcc $^ -o testSwitch
	@./testSwitch Switch
	@rm -f testSwitch
	@rm -f testSwitch.o
	@rm -f Switch.o

testGoto: testGoto.o Goto.o graficador.o
	@gcc $^ -o testGoto
	@./testGoto Goto
	@rm -f testGoto
	@rm -f testGoto.o
	@rm -f Goto.o

testRecursivo: testRecursivo.o Recursivo.o graficador.o
	@gcc $^ -o testRecursivo
	@./testRecursivo Recursivo
	@rm -f testRecursivo
	@rm -f testRecursivo.o
	@rm -f Recursivo.o

testTabla: testTabla.o Tabla.o graficador.o
	@gcc $^ -o testTabla
	@./testTabla X
	@rm -f testTabla
	@rm -f testTabla.o
	@rm -f Tabla.o
	@rm -f graficador.o

.PHONY: clean tests
clean:
	rm -f $(clean_files)