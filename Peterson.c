#include "Peterson.h"

//Función para simular la región crítica
void regionCritica(int tiempo){
  int x;
  printf("Proceso en la región crítica\n");
  for(x=1; x<=tiempo; x++){
    printf("Región crítica: %d\n", x);
    sleep(1);
  }
}

//Función para simular la región no crítica
void regionNoCritica(int tiempo){
  int x;
  printf("Proceso en la región no crítica\n");
  for(x=1; x<=tiempo; x++){
    printf("Región no crítica: %d\n", x);
    sleep(1);
  }
}

//Algoritmo de Peterson para entrar a la región crítica (orientado a 2 procesos)
void entrarRegionCritica(int proceso, int *interesado, int *turno){
  int otro=1-proceso;
  *(interesado+proceso)=TRUE;
  *(turno)=proceso;
  while(*(turno)==proceso && *(interesado+otro)==TRUE);
}

//Algoritmo de Peterson para salir de la región crítica
void salirRegionCritica(int proceso, int *interesado){
  *(interesado+proceso)=FALSE;
}
