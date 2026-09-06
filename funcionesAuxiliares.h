#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

// PROGRAMA 1 -------------------------------------------------------------------------------------

int solicitaBase(char concepto[], int n);
int validaNumero(char numero[], int base);
void solicitaNumero(int baseOrigen, char numero[]);
void imprimirNumero(int baseOrigen, int baseDestino, char numeroFinal[], char numeroInicial[]);

// PROGRAMA 2 -------------------------------------------------------------------------------------

void convierteBinario(int numero, int numeroBinario[]);
void solicitaBinario(int numeroBinario[]);
void complementoDos(int numeroBinario[]);
int obtenerDecimal(int binario[]);
void imprimirFila(const char* etiqueta, int binario[]);
void imprimirOperacion(int binario1[], int binario2[], int resultado[]);

#endif