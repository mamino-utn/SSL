clean_files = main.o manejadorDeErrores.o parser.o scanner.o verificadorSemantico.o generadorDeCodigo.o 

1: SVGLite clean

main.o: main.c parser.h manejadorDeErrores.h
	@gcc -c main.c -o main.o

manejadorDeErrores.o: manejadorDeErrores.c manejadorDeErrores.h
	@gcc -c manejadorDeErrores.c -o manejadorDeErrores.o

parser.o: parser.c parser.h scanner.h verificadorSemantico.h generadorDeCodigo.h figura.h manejadorDeErrores.h
	@gcc -c parser.c -o parser.o

scanner.o: scanner.c scanner.h manejadorDeErrores.h
	@gcc -c scanner.c -o scanner.o

verificadorSemantico.o: verificadorSemantico.c verificadorSemantico.h
	@gcc -c verificadorSemantico.c -o verificadorSemantico.o

generadorDeCodigo.o: generadorDeCodigo.c generadorDeCodigo.h
	@gcc -c generadorDeCodigo.c -o generadorDeCodigo.o

SVGLite: main.o manejadorDeErrores.o parser.o scanner.o verificadorSemantico.o generadorDeCodigo.o
	@gcc $^ -o SVGLite
	@#./SVGLite
	@#rm -f SVGLite


.PHONY: clean
clean:
	@rm -f $(clean_files)
