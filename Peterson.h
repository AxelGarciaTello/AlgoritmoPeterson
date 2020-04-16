#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>

//Definición de las palabras reservadas
#define FALSE 0
#define TRUE 1
#define N 2

//Cabeceras de las funciones
void regionCritica(int tiempo);
void regionNoCritica(int tiempo);
void entrarRegionCritica(int proceso, int *interesado, int *turno);
void salirRegionCritica(int proceso, int *interesado);
