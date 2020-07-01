#ifndef pilotos_H_INCLUDED
#define pilotos_H_INCLUDED
#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
 int idPiloto;
 char nombre[100];

}ePilotos;

int pilotos_hardcodear(LinkedList* myList);
ePilotos* pilotos_newParametros(char nombre[], int idPiloto);
int pilotos_buscarPorId(LinkedList* myPilotsList,int idPiloto, char nombrePiloto[]);
int pilotos_setIdPiloto(ePilotos* piloto, int idPiloto);
int pilotos_getIdPiloto(ePilotos* piloto, int* idPiloto);
int pilotos_setNombre(ePilotos* piloto, char* nombre);
int pilotos_getNombre(ePilotos* piloto, char* nombre);




#endif
