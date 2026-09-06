#include <stdio.h>
#include "funcionesAuxiliares.h"
#include <ctype.h>
#define COLOR_ROJO     "\x1b[31m"
#define COLOR_VERDE    "\x1b[32m"
#define COLOR_AMARILLO "\x1b[33m"
#define COLOR_RESET    "\x1b[0m"   

// PROGRAMA 1 -------------------------------------------------------------------------------------

int solicitaBase(char concepto[] , int n){
    int base;
    char terminador;
    int esValido;
    
    do {
        esValido = 0; 
        printf("\nProporciona tu base de %s: ", concepto);
        
        int leidos = scanf("%d%c", &base, &terminador);
        
        if (leidos == 2 && terminador == '\n') {
            if (base >= 2 && base <= n) {
                esValido = 1; 
            } else {
                printf("\n%s [X] ERROR: La base debe estar entre 2 y %d.%s\n\n", COLOR_ROJO, n, COLOR_RESET);
            }
        } 
        else {
            printf("\n%s >>> [X] ERROR: Base no valida (Solo enteros sin decimales) <<<%s\n", COLOR_ROJO, COLOR_RESET);
            while (getchar() != '\n');
        }
        
    } while (!esValido);
    
    return base;
}

int validaNumero(char numero[], int base){
    char arregloBases[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char caracterActual;
    int encontrado;

    for (int i = 0; numero[i] != '\0'; i++) {
        if (numero[i] == '.') {
            continue; 
        }
        
        caracterActual = toupper(numero[i]);
        encontrado = 0; 

        for (int j = 0; j < base; j++) {
            if (caracterActual == arregloBases[j]) {
                encontrado = 1; 
                break; 
            }
        }

        if (encontrado == 0) {
            return 0; 
        }
    }
    return 1;
}

void solicitaNumero(int baseOrigen, char numero[]){
    int control = 0;
    do{
        printf("\nProporciona el numero de base %d: ", baseOrigen);
        scanf("%49s", numero);
        control = validaNumero(numero, baseOrigen);
        if(control == 0){
            printf("\n%s[!] Tu numero no pertenece a la base %d, vuelve a intentarlo%s\n", COLOR_ROJO, baseOrigen, COLOR_RESET);
        }
    }while(!control);
}

void imprimirNumero(int baseOrigen, int baseDestino, char numeroFinal[], char numeroInicial[]){
    printf("\n%s====================================================%s\n", COLOR_VERDE, COLOR_RESET);
    printf(" %s>>> RESULTADO DE LA CONVERSION <<<%s\n", COLOR_AMARILLO, COLOR_RESET);
    printf("%s====================================================%s\n", COLOR_VERDE, COLOR_RESET);
    printf(" Numero original: %s%s%s (Base %d)\n", COLOR_AMARILLO, numeroInicial, COLOR_RESET, baseOrigen);
    printf(" Numero convertido: %s%s%s (Base %d)\n", COLOR_VERDE, numeroFinal, COLOR_RESET, baseDestino);
    printf("%s====================================================%s\n\n", COLOR_VERDE, COLOR_RESET);
}

// PROGRAMA 2 -------------------------------------------------------------------------------------

void complementoDos(int numeroBinario[]){
    //invertimos bits
    for(int i=1 ; i<=5; i++){
        numeroBinario[i] = 1-numeroBinario[i];
    }
    
    //sumamos uno
    int acarreo = 1; 
    int suma;
    
    for(int i = 5; i >= 1; i--) {
        suma = numeroBinario[i] + acarreo;
        if(suma == 2) {
            numeroBinario[i] = 0; 
            acarreo = 1;          
        } else {
            numeroBinario[i] = suma; 
            acarreo = 0;            
            break; 
        }
    }
}

void convierteBinario(int numero, int numeroBinario[]){
    if(numero < 0){
        numeroBinario[0] = 1;
        numero = -numero;
    }else{
        numeroBinario[0] = 0;
    }
    for(int i=5; i>=1; i--){
        numeroBinario[i]= numero % 2;
        numero = numero / 2;
    }
}

void solicitaBinario(int numeroBinario[]){
    int opcion;
    //pedimos el numero
    do {
       printf("\nProporciona el numero que deseas sumar en binario (-32 a 31):");
       scanf("%d", &opcion);
       if (opcion < -32 || opcion > 31)
        printf("\n%s[!] Error: opcion no valida...%s\n", COLOR_ROJO, COLOR_RESET);
        while(getchar() != '\n');
   } while (opcion < -32 || opcion > 31);

   //convertimos a binario 
   convierteBinario(opcion, numeroBinario);
   if(opcion < 0){
    complementoDos(numeroBinario); 
   }
}

int obtenerDecimal(int binario[]) {
    int decimal = 0;
    int multiplicador = 1;
    
    for(int i = 5; i >= 1; i--) {
        decimal += binario[i] * multiplicador;
        multiplicador *= 2; 
    }
    
    if (binario[0] == 1) {
        decimal -= 32;
    }
    
    return decimal;
}

void imprimirFila(const char* etiqueta, int binario[]) {
    int valorDec = obtenerDecimal(binario);
    
    printf("%11s:     ", etiqueta);
    
    printf("%s%d%s  ", COLOR_AMARILLO, binario[0], COLOR_RESET);
    
    printf("%s", COLOR_VERDE);
    for(int i = 1; i <= 5; i++) {
        printf("%d", binario[i]);
        if(i < 5) printf(" "); 
    }
    
    printf("%s  (%d)\n", COLOR_RESET, valorDec);
}

void imprimirOperacion(int binario1[], int binario2[], int resultado[]) {
    printf("\n");
    imprimirFila("Num A", binario1);
    imprimirFila("Num B", binario2);
    
    printf("                 ------------\n");
    
    imprimirFila("Resultado", resultado);
    printf("\n");
}