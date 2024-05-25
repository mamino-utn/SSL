### TablasDeConversion.c ->

 Su funcion es imprimir en formato de tabla la conversion de una temperatura de fahrenheit a celsius y viceversa. Los valores de la tabla estan dados por los siguientes parametros:
1. LOWER : Valor minimo de las tablas
2. UPPER : Valor maximo de las tablas
3. STEP : Incremento de valor entre filas
    
#### Posee las funciones 
1. printTablaCelsius(LOWER, UPPER, STEP); : invoca a la funcion print tablas pasando la funcion celsius como parametro
2. printTablaFahrenheit(LOWER, UPPER, STEP); : invoca a la funcion print tablas pasando la funcion fahrenheit como parametro
3. printTablas(LOWER, UPPER, STEP, conversion); : funcion generica de imprimir tablas a partir de la conversion de un valor segun una funcion
4. printFila(valorOriginal, conversion); : funcion que imprime cada fila de la tabla tomando un valor de la escala original y utilizando la funcion para obtener el valor convertido
5. printFilas(LOWER, UPPER, STEP, conversion); : funcion generica que invoca a la funcion printFila para imprimir cada una de las filas de la tabla de conversion
   
---

### Conversion.c
 Se encarga de definir el funcionamiento de la conversion de Celsius a Fahrenheit y la conversion de Fahrenheit 

#### Contiene las funciones
1. Celsius esta funcion recibira un valor real equivalente a una temperatura Fahrenheit y retornara el valor convertido a Celsius.
2. Fahrenheit recibe un valor equivalente a una temperatura celsius y retornara la conversion a Fahrenheit.

---
### Conversion.h 

Su funcion es de contrato, para que TablasDeConversion.c conozca la declaraciones de Conversion.c 

---
### ConversionTest.c 

Su funcion es verificar el funcionamiento de las funciones que estan en "Conversion.c"
Posee varios test que verifican esto.

---
### Makefile

Su funcion es compilar los archivos fuentes, obtener los archivos objetos y luego vincularlos para formar los ejecutables. Va a crear 2 archivos ejecutables, "TablasDeConversion" y "ConversionTest".
