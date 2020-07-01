
#include "Vuelos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Inputs.h"
#include "Pilotos.h"
#include "Controller.h"
eVuelos* Vuelos_Nuevo()
{
    eVuelos* vuelos=(eVuelos*)malloc(sizeof(eVuelos));
    return vuelos;
}

eVuelos* Vuelos_NuevoParametros(char idVuelo[], char idAvion[],char idPiloto[], char fecha[], char destino[], char cantPasajeros[], char horaDespegue[], char horaLlegada[])
{
    eVuelos* vuelos=NULL;

    vuelos=Vuelos_Nuevo();
    if(vuelos!= NULL)
    {
        vuelos_setIdVuelo(vuelos, atoi(idVuelo));
        vuelos_setIdPiloto(vuelos, atoi(idAvion));
        vuelos_setIdAvion(vuelos, atoi(idAvion));
        vuelos_setFecha(vuelos, fecha);
        vuelos_setDestino(vuelos, destino);
        vuelos_setCantPasajeros(vuelos, atoi(cantPasajeros));
        vuelos_setHoraDespegue(vuelos, atoi(horaDespegue));
        vuelos_setHoraLlegada(vuelos, atoi(horaLlegada));

    }
    return vuelos;
}
int vuelos_ListarUnVuelo(eVuelos* vuelo, LinkedList* myPilotsList)
{
     int idVuelo;
     int idAvion;
     int idPiloto;
     char fecha[100];
     char destino[100];
     int cantPasajeros;
     int horaDespegue;
     int horaLlegada;
     int ret=0;
     char nombrePiloto[100];

    if(vuelo != NULL)
    {
        if( vuelos_getIdVuelo(vuelo, &idVuelo)&&
            vuelos_getIdAvion(vuelo, &idAvion) &&
            vuelos_getIdPiloto(vuelo, &idPiloto) &&
            vuelos_getFecha(vuelo, fecha) &&
            vuelos_getDestino(vuelo, destino) &&
            vuelos_getCantPasajeros(vuelo, &cantPasajeros) &&
            vuelos_getHoraDespegue(vuelo, &horaDespegue) &&
            vuelos_getHoraLlegada(vuelo, &horaLlegada) &&
            pilotos_buscarPorId(myPilotsList,idPiloto, nombrePiloto))
        {
            ret=1;
            printf("%6d %6d %20s %15s %15s %6d  %6d %6d\n",idVuelo, idAvion, nombrePiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
        }
    }
    return ret;
}



int vuelos_setIdVuelo(eVuelos* vuelo, int idVuelo)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        vuelo->idVuelo=idVuelo;
        ret=1;
    }
    return ret;
}
int vuelos_setIdAvion(eVuelos* vuelo, int idAvion)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        vuelo->idAvion=idAvion;
        ret=1;
    }
    return ret;
}
int vuelos_setIdPiloto(eVuelos* vuelo, int idPiloto)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        vuelo->idPiloto=idPiloto;
        ret=1;
    }
    return ret;
}
int vuelos_setFecha(eVuelos* vuelo, char* fecha)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        strcpy(vuelo->fecha,fecha);
        ret=1;
    }
    return ret;
}
int vuelos_setDestino(eVuelos* vuelo, char* destino)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        strcpy(vuelo->destino,destino);
        ret=1;
    }
    return ret;
}
int vuelos_setCantPasajeros(eVuelos* vuelo, int cantPasajeros)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        vuelo->cantPasajeros=cantPasajeros;
        ret=1;
    }
    return ret;
}
int vuelos_setHoraDespegue(eVuelos* vuelo, int horaDespegue)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        vuelo->horaDespegue=horaDespegue;
        ret=1;
    }
    return ret;
}int vuelos_setHoraLlegada(eVuelos* vuelo, int horaLlegada)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        vuelo->horaLlegada=horaLlegada;
        ret=1;
    }
    return ret;
}
/**********************************/

int vuelos_getIdVuelo(eVuelos* vuelo, int* idVuelo)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        *idVuelo=vuelo->idVuelo;
        ret=1;
    }
    return ret;
}
int vuelos_getIdAvion(eVuelos* vuelo, int* idAvion)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        *idAvion=vuelo->idAvion;
        ret=1;
    }
    return ret;
}
int vuelos_getIdPiloto(eVuelos* vuelo, int* idPiloto)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        *idPiloto=vuelo->idPiloto;
        ret=1;
    }
    return ret;
}
int vuelos_getFecha(eVuelos* vuelo, char* fecha)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        strcpy(fecha,vuelo->fecha);
        ret=1;
    }
    return ret;
}
int vuelos_getDestino(eVuelos* vuelo, char* destino)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        strcpy(destino,vuelo->destino);
        ret=1;
    }
    return ret;
}
int vuelos_getCantPasajeros(eVuelos* vuelo, int* cantPasajeros)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        *cantPasajeros=vuelo->cantPasajeros;
        ret=1;
    }
    return ret;
}
int vuelos_getHoraDespegue(eVuelos* vuelo, int* horaDespegue)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        *horaDespegue=vuelo->horaDespegue;
        ret=1;
    }
    return ret;
}
int vuelos_getHoraLlegada(eVuelos* vuelo, int* horaLlegada)
{
    int ret=0;
    if(vuelo!=NULL)
    {
        *horaLlegada=vuelo->horaLlegada;
        ret=1;
    }
    return ret;
}
/***************************************/
int contarPasajerosTotales(void* element)
{
    int ret=-1;
    eVuelos* vuelo;
    if(element!=NULL)
    {
        vuelo=(eVuelos*)element;
        vuelos_getCantPasajeros(vuelo, &ret);
    }
    return ret;
}

int contarPasajeros_Irlanda(void* element)
{
    int ret=-1;
    char destino[100];
    eVuelos* vuelo;

    if(element!=NULL)
    {
        vuelo=(eVuelos*)element;
        ret=0;
        vuelos_getDestino(vuelo, destino);
        if(stricmp(destino, "irlanda")==0)
        {
            vuelos_getCantPasajeros(vuelo, &ret);
        }
    }
    return ret;
}
int filtroVuelosCortos(void* element)
{
    eVuelos* vuelo;
    int horaLlegada;
    int horaDespegue;
    int ret=0;
    if(element != NULL)
    {
        vuelo=(eVuelos*)element;
        vuelos_getHoraDespegue(vuelo, &horaDespegue);
        vuelos_getHoraLlegada(vuelo, &horaLlegada);

        if((horaLlegada-horaDespegue)<3)
        {
            ret=1;
        }
    }
    return ret;
}
int filtroVuelosPortugal(void* element)
{
    eVuelos* vuelo;
    char destino[100];
    int ret=0;

    if(element != NULL)
    {
        vuelo=(eVuelos*)element;
        vuelos_getDestino(vuelo, destino);

        if(strcmpi(destino, "Portugal")==0)
        {
            ret=1;
        }
    }
    return ret;
}
int filtroVuelosPortugalParametro(void* element, char cadena[])
{
    eVuelos* vuelo;
    char destino[100];
    int ret=0;

    if(element != NULL && cadena!=NULL)
    {
        vuelo=(eVuelos*)element;
        vuelos_getDestino(vuelo, destino);

        if(strcmpi(destino, cadena)==0)
        {
            ret=1;
        }
    }
    return ret;
}
int filtroVuelosSinAlex(void* element)
{
    eVuelos* vuelo;
    int idPiloto;
    int ret=0;

    if(element != NULL)
    {
        vuelo=(eVuelos*)element;
        vuelos_getIdPiloto(vuelo, &idPiloto);

        if(idPiloto!=1)
        {
            ret=1;
        }
    }
    return ret;
}

int filtroParametroVuelosSinAlex(void* element, char cadena[])
{
    LinkedList* lista=ll_newLinkedList();
    eVuelos* vuelo;
    int idPiloto;
    int ret=0;
    char nombre[100];

    if(element != NULL)
    {
        vuelo=(eVuelos*)element;

        vuelos_getIdPiloto(vuelo, &idPiloto);

        controller_Ybarrola_loadPilotsfromText(lista);//cargo la lista con los pilotos

        pilotos_buscarPorId(lista, idPiloto, nombre);

        if(stricmp(nombre, cadena )!=0)
        {
            ret=1;
        }
    }
    return ret;
}
int filtroParametroVuelos(void* element, char cadena[])
{
    LinkedList* lista=ll_newLinkedList();
    eVuelos* vuelo;
    int idPiloto;
    int ret=0;
    char nombre[100];

    if(element != NULL)
    {
        vuelo=(eVuelos*)element;

        vuelos_getIdPiloto(vuelo, &idPiloto);

        controller_Ybarrola_loadPilotsfromText(lista);
        pilotos_buscarPorId(lista, idPiloto, nombre);

        if(stricmp(nombre, cadena )==0)
        {
            ret=1;
        }
    }
    return ret;
}
/*
int filtroVuelosCortosParametros(void* element, char num[])
{
    eVuelos* vuelo;
    int horaLlegada;
    int horaDespegue;
    int ret=0;
    if(element != NULL)
    {
        vuelo=(eVuelos*)element;


        vuelos_getHoraDespegue(vuelo, &horaDespegue);
        vuelos_getHoraLlegada(vuelo, &horaLlegada);

        if((horaLlegada-horaDespegue)< atoi(num))
        {
            ret=1;
        }
    }
    return ret;
}*/


