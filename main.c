#include <stdio.h>
#include "menu.h"
#include "funcionesPrincipales.h"
#include "funcionesAuxiliares.h"
#define COLOR_ROJO     "\x1b[31m"
#define COLOR_VERDE    "\x1b[32m"
#define COLOR_AMARILLO "\x1b[33m"
#define COLOR_RESET    "\x1b[0m"

int main() {
    int opcion;
    int baseOrigen;
    int baseDestino;
    char numero[50];
    char numeroFinal[50];
    int binario1[6];
    int binario2[6];
    int resultadoSuma[6];
    do {
        opcion = mostrarMenu("\n.......................................................................\n1. Iniciar nueva conversion\n2.Sumador binario 6 bits\n3. Salir\n.......................................................................\nOpcion:",3);
        switch(opcion) {
            case 1:
                baseOrigen= solicitaBase("origen", 16); //solicita base correcta
                baseDestino= solicitaBase("destino", 16); //solicita base correcta
                solicitaNumero(baseOrigen, numero); //solicita el numero y evalua si es correcto, devuelve el numero final (como tal no lo devuelve pero si lo deja en memoria del arreglo numero)
                conversion(numero, baseOrigen, baseDestino, numeroFinal); //hace el proceso de la conversion, primero a decimal luego de decimal al destino,
                imprimirNumero(baseOrigen, baseDestino, numeroFinal, numero);//ps lo imprime
                break;
            case 2:
                solicitaBinario(binario1);
                solicitaBinario(binario2);
                sumarBinarios(binario1, binario2, resultadoSuma);
                imprimirOperacion(binario1, binario2, resultadoSuma);
                break;    
            case 3:
                printf("%sSaliendo del programa...%s\n", COLOR_VERDE, COLOR_RESET);
                break;
            default:
                printf("\n%s[!] Opcion invalida. Intente de nuevo.%s\n", COLOR_ROJO, COLOR_RESET);
        }
    } while(opcion != 3);
    return 0;
}