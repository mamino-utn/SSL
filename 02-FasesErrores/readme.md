### 1. Preprocesador
1.b  
Comando utilizado gcc -E hello2.c -o hello2.i. Este comando preprocesa hello2.c y genera hello2.i

hello2.i contiene nuestro codigo fuente sin comentarios y todas las definicion traidas desde la biblioteca stdio.h. En conclusion es nuestro codigo puro (sin comentarios) con los headers de stdio.h 

1.d 
La primera linea es la definicion de la funcion printf en donde devuelve un int y recibe un puntero a una constante de caracteres con la agregacion de la palabra restrict lo que le indica al compilador que ningun otro puntero puede acceder a la misma memoria, ademas los puntos suspensivos que indican que puede recibir un numero arbitrario de parametros.

1.e 
La diferencia se encuentra en las primeras lineas que son agregadas al preprocesar el archivo hello3.c. Estas lineas indican directivas del preprocesador y rutas de inclusion. Muestran como el preprocesador maneja los encabezados incluidos y las directivas

### 2. Compilación
2.a 
- Compilo el resultado y genero hello3.s, sin ensamblar, con el siguiente comando: `gcc -S hello3.c -o hello3.s`. 

 Resultado:
        .\hello3.c: In function 'main':
        .\hello3.c:4:2: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
        4 |  prontf("La respuesta es %d\n");
        |  ^~~~~~
        |  printf
        .\hello3.c:4:2: error: expected declaration or statement at end of input

2.b 
- Para corregir los errores se agrega "}" al final del programa.

2.c 
- El objetivo de este código imprimir "La respuesta es 42\n". El valor 42 es almacenado en una variable local "i" y se utiliza junto con una cadena de formato para imprimir el mensaje a través de la función printf que se la llama por medop del comando "CALL".

2.d 
- Para ensamblar hello4.s en hello4.o, sin vincular, se uso el siguiente comando: `as hello4.s -o hello4.o`

### 3. Vinculacion
3.a
- gcc hello4.o -o hello4
Al ejecutar este comando me tira un error (undefined reference to 'prontf').
3.b
- Corrijo el archivo hello4.c en hello5.c cambiando la invocacion de la funcion de 'prontf' a 'printf, luego ejecuto el comando gcc hello5.c -o hello5 y me genera el ejecutable
3.c
- Al ejecutar el codigo me muestra lo siguiente en consola: 'La respuesta es 4200880'. Yo creo que es un bug que surge ya que si bien declaramos la variable i y le asignamos el valor entero 42, cuando usamos el formato %d para imprimir i, nunca la llamamos luego de las comillas para que se asocie el %d con i. Por lo que estuve investigando el resultado que me tira por consola es un resultado impredescible ya que al no pasarle el argumento (i), toma un valor no definido de la pila de argumentos.


### 4: Correccion del bug
4.a
- Corrijo hello5.c en hello6.c y compilo usando el comando gcc hello6.c -o hello6
El codigo funciona como deberia hacerlo, compila correctamente e imprime por pantalla: 'La respuesta es 42'

### 5. Remocion de prototipo
#### hello7.c
- ¿Arroja error o warning?: 
  - arroja un warning pero el programa compila y ejecuta correctamente 
- ¿Qué es un prototipo y de qué maneras se puede generar?: 
  - Un prototipo es una declaración de una función. Un prototipo se puede generar incluyendo la declaración de la función al principio del código (prototipo explícito) o mediante la inclusión de la cabecera de la biblioteca que contiene la definición de la función (prototipo implícito).
- ¿Qué es una declaración implícita de una función?: 
  - Una declaración implícita de una función es cuando la función se utiliza antes de que se declare explícitamente o se incluya su prototipo.
- ¿Qué indica la especificación?
  - La especificación de C indica que es obligatorio declarar explícitamente todas las funciones antes de su uso.
- ¿Cómo se comportan las principales implementaciones?
  - El gcc sigue las especificaciones del estándar del lenguaje C, compilando pero emitiendo warnings cuando se utilizan funciones sin antes haberlas declarado, como en este caso. En algunos casos, se tratan estos warnings como erroes.
- ¿Qué es una función built-in?
  - Es una función que está directamente soportada por el compilador. Sin embargo, printf no es una función built-in ya que pertenece a la biblioteca estándar de C.
- ¿Conjeture la razón por la cual gcc se comporta como se comporta? ¿Va realmente contra la especificación?
  - El gcc nos emite un warning ya que es peligroso el uso de una función sin declaracion previa, el compilador no puede verificar los argumentos ni el tipo de retorno de la función. Además, gcc no va en contra de la especificación por cumplir con las normativas emitiendo el warning, esto indica que se está realizando algo incorrecto.

En resumen, como observamos, el código compilará emitiendo un warning sobre la declaracion implicita de printf, cumpliendo así con las normativas de las especifiaciones de C. Lo correcto sería incluir el archivo de cabecera "<stdio.h>" para proporcionar el prototipo de printf evitando los warnings.

### 6. Compilación separada: contratos y módulos
6.b
- Para generar un ejecutable en base a dos unidades de traduccion debemos ejecutar los siguientes comandos para la compilacion:
  - Generar el archivo objeto a partir de cada archivo fuente 
      - gcc -c hello8.c -o hello8.o
      - gcc -c studio1.c -o studio1.o
  - Enlazar los archivos para generar el ejecutable
     - gcc hello8.o studio1.o -o hello8
6. c
- ¿qué ocurre si eliminamos o agregamos argumentos a la invocación de prontf? Justifique.
  - Compilara igual y hara el linkeo, aunque arrojara warnings, esto se debe a que el compilador gcc permite las declaraciones implicitas de funciones, por lo cual no arrojara error en la llamada a prontf, luego al hacer el linkeo el linker solo hace un "copy paste" para generar el ejecutable, por lo cual no hace ningun control. Aunque el ejecutable se genere, la funcion prontf tendra un comportamiento indefinido. 

6.d iv
- Ventajas de incluir el contrato en los clientes
  - **Claridad y Mantenibilidad**: mejora la comprensión del código y facilita el mantenimiento en caso de cambios.
  - **Reducción de Errores**
  - **Independencia de la Implementación**: El cliente no necesita conocer los detalles de cómo se implementa la función prontf, solo necesita saber cómo utilizarla según el contrato definido en el header.

- Ventajas de incluir el contrato en el proveedor
  - **Consistencia con el Contrato**: ayuda a evitar errores en la implementación y garantiza que la función se utilice de acuerdo con las especificaciones.
  - **Facilidad de Mantenimiento**
  - **Facilita la Reutilización**: Al proporcionar un contrato claro, otras partes del código pueden reutilizar fácilmente la función prontf sin necesidad de conocer los detalles de su implementación. 

### 7. Crédito extra
- Una biblioteca es un grupo de funciones que pueden ser reutilizadas cuando sean necesarias.
- Las bibliotecas pueden ser distribuidas junto con el software que las utiliza o de manera independiente y pueden ser diseñadas para ser portables.
- Las ventajas son la reutilización de codigo, la abstracción que facilita el desarrollo y la mantenibilidad ya que los cambios en una biblioteca se aplican a todos los programas que la utilizan sin necesidad de cambiarlos individualmente.
- Las desventajas son la dependencia, que pueden aumentar el tamaño del ejecutable y que pueden generar conflictos si dos bibliotecas tienen nombres de función o variables similares.

**Desarrollar y utlizar la biblioteca studio**

    - Genero el archivo objeto de studio.c
      - gcc -c -o studio.o .\studio2.c 

    - Genero la biblioteca studio.lib
      - ar rcs studio.lib studio.o 

    - Compilo y enlazo el programa con la biblioteca
      - gcc -o hello hello9.c -L. -lstudio

    - Corro el ejecutable creado 
      - .\hello
    
    - Se imprime por pantalla "La respuesta es 42"
