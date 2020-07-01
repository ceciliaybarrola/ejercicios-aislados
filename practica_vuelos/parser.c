#include "parser.h"


int parser_FlightsFromText(FILE* pFile, LinkedList* pArrayListFlights)
{
    eVuelos* auxVuelos;
    char cabecera[100];
    int i=-1;
    int ret=0;

    char idVuelo[100];
    char idAvion[100];
    char idPiloto[100];
    char fecha[100];
    char destino[100];
    char cantPasajeros[100];
    char horaDespegue[100];
    char horaLlegada[100];



    if(pFile!=NULL && pArrayListFlights!=NULL)
    {
        while(!feof(pFile)){
            i++;
            if(i==0){
                fscanf(pFile, "%[^\n]\n",cabecera);
                continue;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            auxVuelos=Vuelos_NuevoParametros(idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);

            ll_add(pArrayListFlights,auxVuelos);
        }
        fclose(pFile);
        ret=1;
    }
    return ret;

}
int parser_FlightsToText(FILE* pFile , LinkedList* pArrayList)
{
    eVuelos* vuelo;
     int idVuelo;
     int idAvion;
     int idPiloto;
     char fecha[100];
     char destino[100];
     int cantPasajeros;
     int horaDespegue;
     int horaLlegada;
     int size;
     int i;
    int ret=0;

    if(pFile != NULL && pArrayList != NULL)
    {
        fprintf(pFile, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada");

        size=ll_len(pArrayList);
        for(i=0; i<size; i++)
        {
            vuelo=(eVuelos*)ll_get(pArrayList, i);

            if( vuelos_getIdVuelo(vuelo, &idVuelo) &&
                vuelos_getIdAvion(vuelo, &idAvion)&&
                vuelos_getIdPiloto(vuelo, &idPiloto) &&
                vuelos_getFecha(vuelo, fecha) &&
                vuelos_getDestino(vuelo, destino) &&
                vuelos_getCantPasajeros(vuelo, &cantPasajeros) &&
                vuelos_getHoraDespegue(vuelo, &horaDespegue) &&
                vuelos_getHoraLlegada(vuelo, &horaLlegada));
            {
                ret=1;
                fprintf(pFile, "%d,%d,%d,%s,%s,%d,%d,%d\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            }
        }
    }
    return ret;
}
int parser_PilotsToText(FILE* pFile, LinkedList* myPilotsList)
{
        ePilotos* piloto;
    char nombre[100];
     int idPiloto;

     int size;
     int i;
    int ret=0;

    if(pFile != NULL && myPilotsList != NULL)
    {
        fprintf(pFile, "idPiloto,nombre\n");

        size=ll_len(myPilotsList);
        for(i=0; i<size; i++)
        {
            piloto=(ePilotos*)ll_get(myPilotsList, i);

            if( pilotos_getIdPiloto(piloto, &idPiloto) &&
                pilotos_getNombre(piloto, nombre));
            {
                ret=1;
                fprintf(pFile, "%d,%s\n", idPiloto, nombre);
            }
        }
    }
    return ret;
}
int parser_PilotsFromText(FILE* pFile, LinkedList* myPilotsList)
{
    ePilotos* piloto;
    char cabecera[100];
    int i=-1;
    int ret=0;
    char idPiloto[100];
    char nombre[100];
    char nombreAux[100];

    if(pFile!=NULL && myPilotsList!=NULL)
    {
        while(!feof(pFile)){
            i++;
            if(i==0){
                fscanf(pFile, "%[^\n]\n",cabecera);
                continue;
            }
            fscanf(pFile, "%[^,],%[^\n]\n", idPiloto, nombre);


          /*  if(pilotos_buscarPorId(myPilotsList, atoi(idPiloto), nombreAux)!= 1)
            {
                piloto=pilotos_newParametros(nombre, atoi(idPiloto));
                ll_add(myPilotsList,piloto);
            }*/

            piloto=pilotos_newParametros(nombre, atoi(idPiloto));
            ll_add(myPilotsList,piloto);

        }
        fclose(pFile);
        ret=1;
    }
    return ret;

}


