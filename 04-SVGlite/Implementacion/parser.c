#include "parser.h"

int atributos_usados[3];
int contador_atributos = 0;
//int control_flag;


Figura figura_actual;
atributos_figura atributos_a_llenar;



void parsear(FILE* in, FILE* out){

    reestablecer_atributos();
    emitirSVGParaInicio();
    unidadDeTraduccion();
    emitirSVGParaFin();
    
}


void unidadDeTraduccion(){

    while(!match(END_OF_FILE))
    {
        //printf("\nESTOY EN EL WHILE DE TRADUCCION\n");
        parsear_figura();
        puntoycoma();
    }

    //printf("\nESTOY FUERA DE LA UNIDAD DE TRADUCCION\n");

    
    
    return;
}

void parsear_figura() {
    
    if(match(KEYWORD_CUADRADO ) ){
        figura_actual.tipo = CUADRADO;
        cuadrado();
    }else if(match(KEYWORD_RECTANGULO )){
        figura_actual.tipo = RECTANGULO;
        rectangulo();
    }else if(match(KEYWORD_TRIANGULO )){
        figura_actual.tipo = TRIANGULO;
        triangulo();
    }else if(match(KEYWORD_CIRCULO )){
        figura_actual.tipo = CIRCULO;
        circulo();
    } 
    else{
        emitirErrorSintactico("No se reconoce la figura");
    }
        
   
    checkAttributes(atributos_usados , contador_atributos); //se ocupa el verificador semantico

    emitir_codigo_figura();

    return;
    
}

void cuadrado(){
    
    reestablecer_atributos();

    figura_actual.datos.cuadrado.x = coordenada();
    figura_actual.datos.cuadrado.y = coordenada();

    checkInsideCanvas(figura_actual.datos.cuadrado.x, figura_actual.datos.cuadrado.y); //se ocupa el verificador semantico

    figura_actual.datos.cuadrado.lado = dimension();

    //figura_actual.datos.cuadrado.atributos_figura = atributos();
    atributos();
    figura_actual.datos.cuadrado.atributos_figura = atributos_a_llenar;

    //printf()


    
    return;
}



void rectangulo(){
    
    reestablecer_atributos();

    figura_actual.datos.rectangulo.x = coordenada();
    figura_actual.datos.rectangulo.y = coordenada();

    checkInsideCanvas(figura_actual.datos.rectangulo.x, figura_actual.datos.rectangulo.y); //se ocupa el verificador semantico

    figura_actual.datos.rectangulo.base = dimension();
    figura_actual.datos.rectangulo.altura = dimension();

    atributos();

    figura_actual.datos.rectangulo.atributos_figura = atributos_a_llenar;

    
    return;
}

void triangulo(){
    
    reestablecer_atributos();

    figura_actual.datos.triangulo.x = coordenada();
    figura_actual.datos.triangulo.y = coordenada();

    checkInsideCanvas(figura_actual.datos.triangulo.x, figura_actual.datos.triangulo.y); //se ocupa el verificador semantico
    figura_actual.datos.triangulo.base = dimension();
    figura_actual.datos.triangulo.altura = dimension();
    atributos();
    figura_actual.datos.triangulo.atributos_figura = atributos_a_llenar ;

    return;
}

void circulo(){
    
    reestablecer_atributos();

    figura_actual.datos.circulo.x = coordenada();
    figura_actual.datos.circulo.y = coordenada();

    checkInsideCanvas(figura_actual.datos.circulo.x, figura_actual.datos.circulo.y); //se ocupa el verificador semantico
    figura_actual.datos.circulo.diametro = dimension();
    
    //figura_actual.datos.circulo.atributos_figura = atributos();
    atributos();

    figura_actual.datos.circulo.atributos_figura = atributos_a_llenar;

    return;
}

int coordenada(){
    
    if (match(NUMBER)){
        return obtenerNumero();
    }
    else
        emitirErrorSintactico("La coordenada deberia ser un numero");

}

int dimension(){
    
    if (match(NUMBER)){
        return obtenerNumero();
    }
    else
        emitirErrorSintactico("Las dimensiones deberian ser un numero");
}

void atributos(){

    cantidadDeAtributosValida(contador_atributos);

    if (match(KEYWORD_FILL)){
            
        asign();
        strcpy(atributos_a_llenar.fill , color());
        contador_atributos++;
        atributos_usados[contador_atributos] = KEYWORD_FILL;
        
        atributos();

        
    }
    else if (match(KEYWORD_BORDER)){

        asign();
        strcpy(atributos_a_llenar.border , color());
        contador_atributos++;
        atributos_usados[contador_atributos] = KEYWORD_BORDER;
        
        atributos();

        

            
    }
    else if (match(KEYWORD_TEXT)){

        asign();
        text();
        contador_atributos++;
        atributos_usados[contador_atributos] = KEYWORD_TEXT;
        
        atributos();

        
            
    }else {
        return;
    }
    
    
    
  
}
void asign(){
    if (match(ASSIGN))
        return;
    else
        emitirErrorSintactico("Se esperaba un =");
}
void puntoycoma(){
    
    if (match(SEMICOLON))
        return;
    else
        emitirErrorSintactico("Se esperaba un atributo o un ;");
}

char* color(){
    if(match(COLOR_BLUE))
    {
        return "blue";

    }else if(match(COLOR_RED))
    {
        return "red";

    }else if(match(COLOR_YELLOW))
    {
        return "yellow";

    }else if(match(COLOR_GREEN))
    {
        return "green";
    }else emitirErrorSintactico("Debería haber un color");
}

void text() {
    if (match(STRING))
    {
        strcpy(atributos_a_llenar.texto , obtenerCadena());
    }
}
void emitir_codigo_figura(){

    //printf("Color del cuadrado %s\n ",figura_actual.datos.cuadrado.atributos_figura.fill);
    //printf("Color del borde cuadrado %s\n ",figura_actual.datos.cuadrado.atributos_figura.border);
    
   switch (figura_actual.tipo)
   {
   case CUADRADO:
        emitirSvgParaCuad(figura_actual.datos.cuadrado.x, figura_actual.datos.cuadrado.y, figura_actual.datos.cuadrado.lado, figura_actual.datos.cuadrado.atributos_figura.border, figura_actual.datos.cuadrado.atributos_figura.fill,figura_actual.datos.cuadrado.atributos_figura.texto);
        
    break;
    case RECTANGULO:
        emitirSvgParaRec(figura_actual.datos.rectangulo.x, figura_actual.datos.rectangulo.y, figura_actual.datos.rectangulo.base,figura_actual.datos.rectangulo.altura, figura_actual.datos.rectangulo.atributos_figura.border, figura_actual.datos.rectangulo.atributos_figura.fill,figura_actual.datos.rectangulo.atributos_figura.texto);
    break;

    case TRIANGULO:
        emitirSvgParaTri(figura_actual.datos.triangulo.x, figura_actual.datos.triangulo.y, figura_actual.datos.rectangulo.base,figura_actual.datos.triangulo.altura, figura_actual.datos.triangulo.atributos_figura.border, figura_actual.datos.triangulo.atributos_figura.fill,figura_actual.datos.triangulo.atributos_figura.texto);
    break;

    case CIRCULO:
        emitirSvgParaCirc(figura_actual.datos.circulo.x, figura_actual.datos.circulo.y, figura_actual.datos.circulo.diametro, figura_actual.datos.circulo.atributos_figura.border, figura_actual.datos.circulo.atributos_figura.fill,figura_actual.datos.circulo.atributos_figura.texto);
    break;
   }

   return;
}

void reestablecer_atributos(){

    //printf("Color al restablecer el atributo %s",atributos_a_llenar.fill);

    strcpy(atributos_a_llenar.fill,"");
    strcpy(atributos_a_llenar.border, "");
    strcpy(atributos_a_llenar.texto,"");

    //printf("Color al restablecer el atributo %s",atributos_a_llenar.fill);

    contador_atributos = 0;

    for(int i = 0; i < 4 ; i++)
    {
        atributos_usados[i] = -1;
    }
    
}