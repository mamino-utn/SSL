# Makefile
# Programa utilizado para compilar todos los archivos que hacen los ejecutables TablasDeConversion y ConversionTest
# Hecho por Franco Andino y Santiago Gimenez
# Ultima modificacion: 11/05/2024

all: TablasDeConversion ConversionTest

TablasDeConversion: TablasDeConversion.o Conversion.o
	gcc TablasDeConversion.o Conversion.o -o TablasDeConversion

TablasDeConversion.o: TablasDeConversion.c Conversion.h
	gcc -c TablasDeConversion.c -o TablasDeConversion.o

ConversionTest: ConversionTest.o Conversion.o
	gcc ConversionTest.o Conversion.o -o ConversionTest

ConversionTest.o: ConversionTest.c Conversion.h 
	gcc -c ConversionTest.c -o ConversionTest.o

Conversion.o: Conversion.c Conversion.h
	gcc -c Conversion.c -o Conversion.o

.PHONY: clean
clean:
	rm -f TablasDeConversion.o Conversion.o TablasDeConversion ConversionTest.o ConversionTest