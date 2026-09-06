#ifndef FUNCIONES_H
#define FUNCIONES_H

// PROGRAMA 1 -------------------------------------------------------------------------------------

float conversion(char numero[], int baseOrigen, int baseDestino, char numeroFinal[]);
float convertirDecimal(char numero[], int baseOrigen);
void convertirBaseDestino(float numeroDecimal, int baseDestino, char numeroFinal[]);

// PROGRAMA 2 -------------------------------------------------------------------------------------

void sumarBinarios(int binario1[], int binario2[], int resultadoSuma[]);
void sumarUnBit(int bitA, int bitB, int acarreoIn, int *suma, int *acarreoOut);

#endif