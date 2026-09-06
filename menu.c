#include <stdio.h>
#include "menu.h"
#define COLOR_ROJO     "\x1b[31m"
#define COLOR_VERDE    "\x1b[32m"
#define COLOR_AMARILLO "\x1b[33m"
#define COLOR_RESET    "\x1b[0m"

int mostrarMenu(char texto[], int n){
    int opcion;
    do {
       printf("%s ",texto);
       scanf("%d", &opcion);
       if (opcion < 1 || opcion > n)
        printf("\n%s[!] Error: opcion no valida...%s\n", COLOR_ROJO, COLOR_RESET);
        while(getchar() != '\n');
   } while (opcion < 1 || opcion > n);
   return opcion;
}