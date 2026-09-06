#include <stdio.h>
#include "funcionesPrincipales.h"
#include <math.h>
#include <ctype.h>
#define COLOR_ROJO     "\x1b[31m"
#define COLOR_VERDE    "\x1b[32m"
#define COLOR_AMARILLO "\x1b[33m"
#define COLOR_RESET    "\x1b[0m"


// PROGRAMA 1 -------------------------------------------------------------------------------------

float convertirDecimal(char numero[], int baseOrigen){
    float numeroDecimal = 0;
    int traduccion;
    int ubicacionPunto = 0;
    int n = 0;
    char caracterActual;
    //buscar el punto 
    while (numero[ubicacionPunto] != '\0' && numero[ubicacionPunto] != '.') {
        ubicacionPunto++;
    }

    //recorremos de derecha a izquierda la parte ENTERA, se traduce y multiplica 
    for(int i = ubicacionPunto - 1 ; i >= 0 ; i--){
        
        caracterActual = toupper(numero[i]);

        if (caracterActual >= '0' && caracterActual <= '9') {
        traduccion = caracterActual - '0';
        } 
        else if (caracterActual >= 'A' && caracterActual <= 'F') {
            traduccion = (caracterActual - 'A') + 10;
        }
        numeroDecimal += traduccion * pow(baseOrigen, n);
        n++;
    }

    //parete DECIMALES
    if (numero[ubicacionPunto] == '.') {
        int nFraccionario = -1;
        
        for (int i = ubicacionPunto + 1; numero[i] != '\0'; i++) {
            char caracterActual = toupper(numero[i]);
            
            if (caracterActual >= '0' && caracterActual <= '9') {
                traduccion = caracterActual - '0';
            } 
            else if (caracterActual >= 'A' && caracterActual <= 'F') {
                traduccion = (caracterActual - 'A') + 10;
            }
            
            numeroDecimal += traduccion * pow(baseOrigen, nFraccionario);
            nFraccionario--; 
        }
    }

    return numeroDecimal;
}

void convertirBaseDestino(float numeroDecimal, int baseDestino, char numeroFinal[]){
    int parteEntera = numeroDecimal;
    float parteDecimal = numeroDecimal - parteEntera;
    int indice = 0;
    int residuo;

    if(parteEntera == 0){
        numeroFinal[indice] = '0';
        indice++;
    }
    else{
        while(parteEntera > 0){
            residuo = parteEntera % baseDestino;

            if (residuo >= 0 && residuo <= 9) {
                numeroFinal[indice] = residuo + '0';
            } 
            else if (residuo >= 10 && residuo <= 15) {
                numeroFinal[indice] = (residuo - 10) + 'A';
            }

            indice++;
            parteEntera = parteEntera / baseDestino;
        }
    }
    
    int inicio = 0;
    int fin = indice - 1;
        while (inicio < fin) {
            char temporal = numeroFinal[inicio];
            numeroFinal[inicio] = numeroFinal[fin];
            numeroFinal[fin] = temporal;
            inicio++;
            fin--;
        }
    
    if (parteDecimal > 0) {
        numeroFinal[indice] = '.';
        indice++;
        
        int limiteDecimales = 5; 
        
        while (parteDecimal > 0 && limiteDecimales > 0) {
            parteDecimal = parteDecimal * baseDestino;
            
            int digitoEntero = (int)parteDecimal; 
            
            if (digitoEntero >= 0 && digitoEntero <= 9) {
                numeroFinal[indice] = digitoEntero + '0';
            } 
            else if (digitoEntero >= 10 && digitoEntero <= 15) {
                numeroFinal[indice] = (digitoEntero - 10) + 'A';
            }
            
            indice++;
            
            parteDecimal = parteDecimal - digitoEntero; 
            limiteDecimales--;
        }
    }

    numeroFinal[indice] = '\0';
}

float conversion(char numero[], int baseOrigen, int baseDestino, char numeroFinal[]){
    float numeroDecimal = 0; 
    numeroDecimal = convertirDecimal(numero, baseOrigen);
    convertirBaseDestino(numeroDecimal, baseDestino, numeroFinal);
}

// PROGRAMA 2 -------------------------------------------------------------------------------------

void sumarUnBit(int bitA, int bitB, int acarreoIn, int *suma, int *acarreoOut){
    int sumaTotal = bitA + bitB + acarreoIn;
    *suma = sumaTotal % 2;
    if(sumaTotal >= 2){
        *acarreoOut = 1;
    }else{
        *acarreoOut = 0;
    }
}

void sumarBinarios(int binario1[], int binario2[], int resultadoSuma[]){
    int acarreo = 0;
    int aux;
    for(int i = 5; i >= 1; i--){
        sumarUnBit(binario1[i],binario2[i],acarreo,&resultadoSuma[i],&acarreo);
    }
    aux = acarreo;
    sumarUnBit(binario1[0], binario2[0], aux, resultadoSuma, &acarreo);
    if(aux != acarreo){
        printf("\n%s[!] ADVERTENCIA: OVERFLOW detectado.%s\n", COLOR_ROJO, COLOR_RESET);
    }

}
