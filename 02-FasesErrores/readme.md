### 1: Preprocesador
1.b : 
Comando utilizado gcc -E hello2.c -o hello2.i. Este comando preprocesa hello2.c y genera hello2.i
hello2.i contiene nuestro codigo fuente sin comentarios y todas las definicion traidas desde la biblioteca stdio.h. En conclusion es nuestro codigo puro (sin comentarios) con los headers de stdio.h 

1.d La primera linea es la definicion de la funcion printf en donde devuelve un int y recibe un puntero a una constante de caracteres con la agregacion de la palabra restrict lo que le indica al compilador que ningun otro puntero puede acceder a la misma memomoria, ademas los puntos suspensivos que indican que puede recibir un numero arbitrario de parametros.

1.e La diferencia se encuentra en las primeras lineas que son agregadas al preprocesar el archivo hello3.c. Estas lineas indican directivas del preprocesador y rutas de inclusion. Muestran como el preprocesador maneja los encabezados incluidos y las directivas

### 2: Compilación
2.a
 Se utiliza el comando gcc -S hello3.c -o hello3.s. Al ejecutarlo tiera un error y un warning.
 
 2.b Los errores se deben a las llaves de finalizacion de la funcion main y a su return 0. Agrego esto en el archivo hello4.c
 Volvemos a ejecutar el comando gcc -S hello4.c -o hello4.s 
 Genera el archivo hello4.s conteniendo lenguaje ensamblador

 2.c El objetivo de este codigo es el ser el intermediario entre nuestro codigo de alto nivel y el codigo maquina del hardware.
 Haciendo más sensilla la interpretacion de nuestro codigo para el hardware.

 ### 3: Vinculación 
 3.a
  Comando ejecutado gcc -c hello4.c -o hello4.o 

3.b
  Se corrige prontf por printf para que ejecute.

3.c
  El codigo muestra por consola un numero aleatorio alojado en la memoria. Esto se debe a que no le pasamos nada a %d y tomara un valor aleatorio.
 ### 4: Corrección de Bug
4.a
 Agrego i en el printf para que %d tenga un valor asosiado para mostrar.

 ### 5: Remoción de Prototipo
 b.
 
i. El codigo no arroja ningun error, pero si da warnings respecto a printf y la inclusion de la libreria stdio.h

ii. Un prototipo es la declaración de una función en C que especifica el nombre de la función, su tipo de retorno y los tipos de sus   parámetros, sin necesidad de realizar el cuerpo de la funcion. Se pueden generar en el mismo archivo c al comienzo y luego realizar el cuerpo de la funcion. O realizar un archivo .h que contenga los propotipos de las funciones que vayamos a utilizar y un archivo .c que contenga el cuerpo de nuestras funciones luego realizar el contrato entre ambas partes. 

iii. Un declaracion implicita es cuando se hace llamada a una funcion sin tener declarado previamente un prototipo de dicha funcion en el codigo. En C provoca que el compilador asuma ciertos tipos por defecto para la funcion.

iv. La especificacion de main indica que devuelve un entero y no recibe parametros.

v.En general las implementaciones tratan de seguir el estándar de C establecido por el ISO, siempre y cuando no tenga extensiones del compilador y configuraciones especificas.

vi. Una función "built-in" es una función que está directamente integrada en el compilador o en el entorno de ejecución del lenguaje de programación. Estas funciones son parte del propio lenguaje y no necesitan ser definidas o importadas desde bibliotecas externas.

vii. Podemos concluir que gcc compila el codigo ya que posee un configuracion o extension que le permite tener definida implicitamente la funcion printf. No va en contra de las especificaciones porque el mismo compilador asume los parametros de printf . Pero es más recomendable para hacer a nuestro codigo más portable,legible y menos propenso a errores.

### 6: Compilación Separada: Contratos y Módulos
b . Utilizando el comando gcc hello8.c studio1.c -o nombreArchivo logre generar un ejecutable conectado ambos archivos.

c. Si eliminamos el primer parametro la funcion tirara error pero si eliminamos cualquier otro parametro la funcion funciona de igual forma que el printf. Y podemos agregar cualquier cantidad de parametros por el parametro ... .

d.
 iv. Incluir un contrato tanto en el cliente como en el proveedor facilita la integracion y la prueba, ya que ambas partes pueden confiar en la consistencia y la estabilidad de la interfaz, reduccion de errores y ambiguedades, permitir cambios y evolución en el sistema tanto de parte del  cliente como del proveedor sin interrumpir la integración o el funcionamiento de las partes.


 ### Credito Extra 

 Investigación sobre bibliotecas

 ¿Que son ? : Una biblioteca es un conjunto de funciones, rutinas y datos predefinidos agrupadas en un solo archivo o varios. Para su reutilización y facilitar el desarrollo de software.

 ¿Se pueden distribuir? : Si y existen varias formas de distribuirlos
  Bibliotecas Estándar como la biblioteca estandar de c que es distribuida junto con el compilador o el entorno de ejecución

  Bibliotecas Propias: Se puede crear nuestras propias bibliotecas y distribuirlos como archivos independientes o como paquetes de software 

  Bibliotecas de Terceros: Bibliotecas creadas por otros programadores para utilizarlos en nuestros proyectos.
