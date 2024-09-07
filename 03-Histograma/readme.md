## 1 - Arboles de expresion
 b.<br>
<img src="https://imgur.com/a/62RDNuF"/>

 c.<br>
 <img src="https://imgur.com/1asLuSI.png"/>

## 2 - Máquina de estado 

a.<br>
<img src="https://imgur.com/rfoa1Af.png"/>

b.

(Q,Σ,T,q0,F) 5-upla

Q = {In,Out,End}; (Conjunto posible de estados)

Σ = ASCII = cb U cnb U EOF 
  - cb={ ' ' , '\n' , '\t' } ;
  - cnb= ASCII -{cb, EOF};
  
T = Q x Σ -> Q; (Funcion de transiciones)
  - T : {
    OUT -> cb | ε -> OUT, 
    OUT -> cnb | lp++ -> IN, 
    OUT -> EOF | ε -> END, 
    IN -> cnb | lp++ -> IN, 
    IN -> cb | histograma(lp)++, lp=0 -> OUT, 
    IN -> EOF | histograma(lp)++ -> END 
    }

q0 = Out; (Estado inicial)

F ={End}; (Estado final)


## 3 - Implementaciones de Máquinas de Estado
### a. Implementación #1: Una variable para el estado actual
**ventajas y desventajas de la implementacion**
La version de [KR1988] ofrece una solución simple y eficiente para contar las palabras de un texto, mientras que la variante con enum y switch ofrece un análisis más detallado y una estructura de código más organizada, a costa de una mayor complejidad y poca prestacion a una lectura mas clara como la antes mencionada.

### b. Implementación #2: Sentencias goto
¿Tiene alguna aplicación go to hoy en día? ¿Algún lenguaje moderno lo utiliza?
En algunos lenguajes como C el goto se utiliza para simplificar el manejo de errores y la limpieza de recursos en funciones complejas. Esto es común en código de sistemas operativos y controladores donde se requiere un control fino sobre la memoria y los recursos.
Un lenguaje moderno que incluye goto es Go, aunque el uso del mismo es raro y no es necesario, por lo que no se lo utiliza

### c. Implementación #3: Funciones Recursivas
¿Es necesario que las funciones accedan a contadores? Si es así, ¿cómo hacerlo?
Es necesario que las funciones accedan a los contadores (nl, nw, nc) para poder contar el número de líneas, palabras y caracteres respectivamente. Para hacerlo utilizamos variables globales , para que sean accesibles desde todas las funciones recursivas.
