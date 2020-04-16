#include "Peterson.h"

int main(void){
  key_t llaveTurno,
        llaveInteresado;
  int shmidTurno,
      shmidInteresado,
      *turno,
      *interesado;
  llaveTurno=ftok("Turno", 'a'); //Llave para la memoria compartida
  //Asignación del tamaño de memoria y permisos
  shmidTurno=shmget(llaveTurno, sizeof(int), IPC_CREAT|0600);
  //asignación de una variable al espacio de memoria
  turno=shmat(shmidTurno, 0, 0);
  /*
    Se repite el mismo proceso en las siguientes tres líneas de código
    pero esta vez para el arreglo 'Interesados'
  */
  llaveInteresado=ftok("Interesado",'b');
  shmidInteresado=shmget(llaveInteresado, sizeof(int)*N, IPC_CREAT|0600);
  interesado=shmat(shmidInteresado, 0, 0);
  *interesado=FALSE;
  *(interesado+1)=FALSE;
  while(1){
    //Simulación del algoritmo
    entrarRegionCritica(0, interesado, turno);
    regionCritica(3);
    salirRegionCritica(0, interesado);
    regionNoCritica(5);
  }
}
