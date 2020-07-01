#ifndef vuelos_H_INCLUDED
#define vuelos_H_INCLUDED
#include "LinkedList.h"

typedef struct{
 int idVuelo;
 int idAvion;
 int idPiloto;
 char fecha[100];
 char destino[100];
 int cantPasajeros;
 int horaDespegue;
 int horaLlegada;

}eVuelos;

eVuelos* Vuelos_NuevoParametros(char idVuelo[], char idAvion[],char idPiloto[], char fecha[], char destino[], char cantPasajeros[], char horaDespegue[], char horaLlegada[]);
eVuelos* Vuelos_Nuevo();
int contarPasajerosTotales(void* element);
int contarPasajeros_Irlanda(void* element);

int vuelos_ListarUnVuelo(eVuelos* vuelo, LinkedList* myPilotsList);

int vuelos_setIdVuelo(eVuelos* vuelo, int idVuelo);
int vuelos_setIdAvion(eVuelos* vuelo, int idAvion);
int vuelos_setIdPiloto(eVuelos* vuelo, int idPiloto);
int vuelos_setFecha(eVuelos* vuelo, char* fecha);
int vuelos_setDestino(eVuelos* vuelo, char* destino);
int vuelos_setCantPasajeros(eVuelos* vuelo, int cantPasajeros);
int vuelos_setHoraDespegue(eVuelos* vuelo, int horaDespegue);
int vuelos_setHoraLlegada(eVuelos* vuelo, int horaLlegada);
/**********************************/
int vuelos_getIdVuelo(eVuelos* vuelo, int* idVuelo);
int vuelos_getIdAvion(eVuelos* vuelo, int* idAvion);
int vuelos_getIdPiloto(eVuelos* vuelo, int* idPiloto);
int vuelos_getFecha(eVuelos* vuelo, char* fecha);
int vuelos_getDestino(eVuelos* vuelo, char* destino);
int vuelos_getCantPasajeros(eVuelos* vuelo, int* cantPasajeros);
int vuelos_getHoraDespegue(eVuelos* vuelo, int* horaDespegue);
int vuelos_getHoraLlegada(eVuelos* vuelo, int* horaLlegada);


int filtroVuelosCortos(void* element);
int filtroVuelosPortugal(void* element);
int filtroVuelosSinAlex(void* element);


int filtroVuelosPortugalParametro(void* element, char cadena[]);
int filtroParametroVuelosSinAlex(void* element, char cadena[]);
int filtroParametroVuelos(void* element, char cadena[]);
#endif
