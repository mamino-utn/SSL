#include "scanner.h"

Token tokenActual;
Token tokenAuxiliar;
Token proximoToken;

int tokenPeeked = 0;  // Flag para saber si se ha peekeado un token
const int maxString = 1024;
const int maxToken = 100;

void getNextToken(){
    char c; //Para leer caracter por caracter
    char token[maxToken]; //Para almacenar los tokens
    char cadena[maxString]; //Para guardar string de atributo TEXT
    int i = 0;
    State estado = INICIAL; //Comienza en estadio inicial

//Lee cada caracter y determina que estado le corresponda segun su tipo
    while((c = getchar()) != EOF){   
          
        switch(estado){
            case INICIAL:
            // printf("Estado = INICIAL:\n");
                if(isspace(c)){
                    // printf("Espacio detectado\n");
                    estado = ESPACIO;
                }
                else if(isalpha(c))
                {
                    strcpy(token, "");
                    i = 0;
                    token[i] = c;
                    // printf("1er caracter leido: %c\n",c);
                    estado = KEYWORD;
                }
                else if(isdigit(c)){
                    strcpy(token, "");
                    i = 0;
                    token[i] = c;
                    // printf("1er numero leido: %c\n",c);
                    estado = NUMERO;
                }
                else if(c == '\''){
                    strcpy(cadena , "");
                    estado = CADENA;
                }
                else if(c == ';' || c == '='){
            
                    // printf("Estado = SIMBOLO\n");
                    if(c == '='){
                        // printf("Simbolo leido: =\n");
                        tokenAuxiliar.type = ASSIGN;
                    }else if(c == ';'){
                        // printf("Simbolo leido: ;\n");
                        tokenAuxiliar.type = SEMICOLON;               
                    }
                    tokenActual = tokenAuxiliar;
                    // printf("Token generado: %d\n", tokenActual.type);
                    return; 
                }
                else 
                    estado = ERROR;
            break;
            case KEYWORD:
            // printf("Estado = KEYWORD:\n");
                while(isalpha(c)){ //Mientras siga leyendo letras
                    // printf("Otro caracter leido %c\n", c);
                    token[++i] = c; //Las va almacenando en el vector token
                    c = getchar(); //Lee
                }
                ungetc(c, stdin); //Devuelvo el ultimo caracter leido al buffer para que no se pierda y poder clasificar a que estado va
                token[++i] = '\0'; //Aca se termina la lectura y se agrega el caracter de fin a la posible palabra leida
                // printf("Palabra leida: %s \n", token);
                
            //Se evalua a que keyword corresponde lo que se leyo y en caso de no ser ninguna de las definidas en la espacificacion, 
            //cambia de estado al estado ERROR
                if(strcmp(token, "cuad") == 0){
                    tokenAuxiliar.type = KEYWORD_CUADRADO;
                    // printf("Keyword cuad reconocida\n");
                }
                else if(strcmp(token, "rec") == 0){
                    tokenAuxiliar.type = KEYWORD_RECTANGULO;
                }
                else if(strcmp(token, "tri") == 0){
                    tokenAuxiliar.type = KEYWORD_TRIANGULO;
                }
                else if(strcmp(token, "circ") == 0){
                    tokenAuxiliar.type = KEYWORD_CIRCULO;
                }
                else if(strcmp(token, "blue") == 0){
                    tokenAuxiliar.type = COLOR_BLUE;
                }
                else if(strcmp(token, "yellow") == 0){
                    tokenAuxiliar.type = COLOR_YELLOW;
                }
                else if(strcmp(token, "red") == 0){
                    tokenAuxiliar.type = COLOR_RED;
                }
                else if(strcmp(token, "green") == 0){
                    tokenAuxiliar.type = COLOR_GREEN;
                }
                else if(strcmp(token, "fill") == 0){
                    tokenAuxiliar.type = KEYWORD_FILL;
                }
                else if(strcmp(token, "border") == 0){
                    tokenAuxiliar.type = KEYWORD_BORDER;
                }
                else if(strcmp(token, "text") == 0){
                    tokenAuxiliar.type = KEYWORD_TEXT;
                }
                else
                    estado = ERROR;

                if(estado != ERROR){
                    tokenActual = tokenAuxiliar;
                    // printf("Token generado: %d\n", tokenActual.type);
                    estado = INICIAL;
                    return;
                }
            break;
            case ESPACIO:
                // printf("Estado = ESPACIO\n");
            //Ignora todos los espacios en blanco que encuentre
                while (isspace(c)){
                    // printf("Otro espacio detectado\n");
                    c = getchar();
                }
                ungetc(c, stdin);
                estado = INICIAL;
            break;
            case NUMERO:
            // printf("Estado = NUMERO\n");
            //Mientras siga leyendo numeros voy almacenandolos en el vector token como caracteres
                while(isdigit(c)){
                    // printf("Otro numero leido %c\n", c);
                    token[++i] = c; //Las va almacenando en el vector token
                    c = getchar(); //Lee
                }
                ungetc(c, stdin); //Devuelvo el ultimo caracter leido al buffer para que no se pierda y poder clasificar a que estado va
                token[++i] = '\0'; //Termino de leer numeros y finalizo la cadena con \0
                //printf("Numero total leido %s\n", token);
            //Creacion del token 
                tokenAuxiliar.value.number = atoi(token); //Convierto el numero leido a entero
                tokenAuxiliar.type = NUMBER;
                tokenActual = tokenAuxiliar;
                //printf("Token generado: %d\n", tokenActual.type);
                //printf("Valor del token: %d\n", tokenAuxiliar.value.number);
                estado = INICIAL;
                return;
            break;
            /*
            case SIMBOLO:
                printf("Estado = SIMBOLO\n");
                if(c == '='){
                    printf("Simbolo leido: =\n");
                    tokenAuxiliar.type = ASSIGN;
                }else if(c == ';'){
                    printf("Simbolo leido: ;\n");
                    tokenAuxiliar.type = SEMICOLON;                   
                }
                tokenActual = tokenAuxiliar;
                printf("Token generado: %d\n", tokenActual.type);
            
            break;
            */
            case CADENA:
            //printf("Estado = CADENA\n", c);
            i = 0;
            cadena[i] = c;
            //printf("1er caracter leido: %c\n", c);
            //Funciona mientras c no sea la comilla de cierre o EOF, y mientras el largo de la cadena sea menor  a maxString - 1
                while((c = getchar()) != '\'' && c != EOF && i < (maxString - 1)){
                    cadena[++i] = c;
                    //printf("Otro caracter: %c\n", c);
                }
                if(c == '\''){
                    cadena[++i] = '\0'; //Se indica el final de la cadena
                //Se genera el token de STRING
                    tokenAuxiliar.value.string = cadena;
                    tokenAuxiliar.type = STRING;
                    tokenActual = tokenAuxiliar;
                    //printf("Token generado: %d\n", tokenActual.type);
                    //printf("Valor del token: %s\n", tokenActual.value.string);
                    estado = INICIAL;
                    return;
                }else //Si la cadena no termina con \' se origina un error
                    estado = ERROR;
            break;
            case ERROR:
            //printf("Esta en el estado error %c\n", c);
                emitirErrorLexico("El lexema no pertenece al lenguaje SVGLite");
            break;
            default:
            //printf("Esta en el estado default %c\n", c);
            emitirErrorLexico("Error lexico indefinido");
        }
    }
//Se encuentra caracter de fin
    //printf("FIN\n");
    tokenAuxiliar.type = END_OF_FILE;
    tokenActual = tokenAuxiliar;
    //printf("Token generado: %d\n", tokenActual.type);
    

}


void peekNextToken() {
    Token token_aux;
    if (!tokenPeeked) {  // Solo obtiene un token si no se ha peekeado ya
        token_aux = tokenActual;  // Guarda el token actual
        getNextToken();  // Obtén el siguiente token
        proximoToken = tokenActual;  // Guarda el token obtenido
        tokenActual = token_aux;  // Restaura el token actual
        tokenPeeked = 1;  // Marca que se ha peekeado
    }
    return;
}

// Implementación para consumir el token anticipado
void consumeToken() {
    if (tokenPeeked) {  
        tokenActual = proximoToken;  // Avanzamos usando el token peekeado
        tokenPeeked = 0;  // Reseteamos el flag
    } else {
        getNextToken();  // Si no hay peek, avanzamos normal
    }
}

int match(tokenType tipo_buscado) {

    peekNextToken();  // Miramos el siguiente token
    
    // Comparamos si el token coincide con el esperado
    if (proximoToken.type != tipo_buscado) {
        //printf("este es el tokenType: %d\n" , proximoToken.type);
        return 0;
    } else {
        consumeToken();  // Consumimos el token si es el correcto
        return 1;
    }
}



char* obtenerCadena(){
    return tokenActual.value.string;
}

int obtenerNumero(){
    return tokenActual.value.number;
}