#include "Controller.h"
#include "Vuelos.h"
int controller_Ybarrola_loadFromText(LinkedList* myList, LinkedList* myPilotsList)
{
    char path[100]="Vuelos.csv";
    FILE* file;
    int ret=0;

    if(myList!=NULL)
    {
        ll_clear(myList);
        getString(path, "ingrese nombre del archivo: ");
        file=fopen(path, "r");
        if(file!=NULL)
        {
            if(parser_FlightsFromText(file, myList) &&
            controller_Ybarrola_listFlights(myList, myPilotsList))
            {
                ret = 1;
            }
        }
        fclose(file);
    }
    return ret;
}
int controller_Ybarrola_listFlights(LinkedList* myList, LinkedList* myPilotsList)
{
    eVuelos* vuelos;
    int ret=0;
    if(myList!=NULL)
    {
        for(int i=0; i<ll_len(myList); i++)
        {
            vuelos=(eVuelos*)ll_get(myList, i);
            ret=vuelos_ListarUnVuelo(vuelos,myPilotsList);
        }
    }
    return ret;
}
int controller_Ybarrola_countTotalPassengers(LinkedList* myList)
{
    int ret=0;
    if(myList!=NULL && ll_isEmpty(myList)==0)
    {
        ret=ll_count(myList, &contarPasajerosTotales);
        printf("PASAJEROS TOTALES: %d\n", ret);
        ret=1;

    }
    return ret;
}
int controller_Ybarrola_countPassengersToIreland(LinkedList* myList)
{
    int ret=0;
    if(myList!=NULL && ll_isEmpty(myList)==0)
    {
        ret=ll_count(myList, &contarPasajeros_Irlanda);
        printf("PASAJEROS A IRLANDA: %d\n", ret);
        ret=1;

    }
    return ret;
}
int controller_Ybarrola_filterShortFlights(LinkedList* myList, LinkedList* myPilotsList)
{
    int ret=0;
    LinkedList* filteredList;
    FILE* file;
    char path[100];
    if(myList!=NULL)
    {
        //filteredList=ll_filter_parametros(myList, &filtroVuelosCortosParametros, "3");

        filteredList=ll_filter(myList, &filtroVuelosCortos);
        controller_Ybarrola_listFlights(filteredList, myPilotsList);
        getString(path,"Ingrese nombre del archivo a escribir: ");
        file=fopen(path, "w");

        file=fopen(path, "w");
        if(file!=NULL)
        {
            ret=parser_FlightsToText(file, filteredList);
            ll_deleteLinkedList(filteredList);
        }
        fclose(file);
    }
    return ret;
}
int controller_Ybarrola_loadPilotstoText(LinkedList* myPilotsList)
{
    int ret=0;
    FILE* file;
    char path[100]="Pilotos.csv";
    if(myPilotsList!=NULL)
    {
       // getString(path,"Ingrese nombre del archivo a escribir: ");
        file=fopen(path, "w");

        file=fopen(path, "w");
        if(file!=NULL)
        {
            ret=parser_PilotsToText(file, myPilotsList);
        }
        fclose(file);
    }
    return ret;
}
int controller_Ybarrola_loadPilotsfromText(LinkedList* myPilotsList)
{
    int ret=0;
    FILE* file;
    char path[100]="Pilotos.csv";
    if(myPilotsList!=NULL)
    {

        file=fopen(path, "r");
        if(file!=NULL)
        {
            ret=parser_PilotsFromText(file, myPilotsList);
        }
        fclose(file);
    }
    return ret;
}
int controller_Ybarrola_ListFligthsToPortugal(LinkedList* myList, LinkedList* myPilotsList)
{
    int ret=0;
    LinkedList* filteredList;

    if(myList!=NULL)
    {
        filteredList=ll_filter_parametro(myList, &filtroVuelosPortugalParametro, "Portugal");
        if(filteredList!=NULL)
        {
            controller_Ybarrola_listFlights(filteredList, myPilotsList);
            ll_deleteLinkedList(filteredList);
            ret=1;
        }
    }
    return ret;
}
int controller_Ybarrola_ListFligthsWithoutLifeson(LinkedList* myList, LinkedList* myPilotsList)
{
    int ret=0;
    LinkedList* filteredList;

    if(myList!=NULL)
    {
        filteredList=ll_filter_parametro(myList, &filtroParametroVuelosSinAlex, "Alex Lifeson");
        if(filteredList!=NULL)
        {
            controller_Ybarrola_listFlights(filteredList, myPilotsList);
            ll_deleteLinkedList(filteredList);
            ret=1;
        }
    }
    return ret;
}
int controller_Ybarrola_ListFilteredFligths(LinkedList* myList, LinkedList* myPilotsList)
{
    int ret=0;
    LinkedList* filteredList;
    char cadena[100]="Richard Bach";
    char path[100]="Filtro.csv";
    FILE* file;

    if(myList!=NULL)
    {
        controller_Ybarrola_listPilotos(myPilotsList);
        getString(cadena, "Ingrese nombre del piloto: ");
        //getString(path, "Ingrese nombre del archivo: ");

        filteredList=ll_filter_parametro(myList, &filtroParametroVuelos, cadena);

        if(filteredList!=NULL && ll_isEmpty(filteredList)==0)
        {
            controller_Ybarrola_listFlights(filteredList, myPilotsList);

            file=fopen(path, "w");
            if(file!=NULL)
            {
                ret=parser_FlightsToText(file, filteredList);
                ret=1;
            }
            fclose(file);

        }

    }
    return ret;

}
int controller_Ybarrola_listPilotos(LinkedList* myPilotsList)
{
    ePilotos* piloto;
    char nombre[100];
    int id;
    int ret=0;
    if(myPilotsList!=NULL)
    {
        printf("LISTA DE PILOTOS DE NUESTRO AEROPUERTO\n");
        for(int i=0; i<ll_len(myPilotsList); i++)
        {
            piloto= ll_get(myPilotsList, i);
            pilotos_getNombre(piloto,nombre);
            pilotos_getIdPiloto(piloto, &id);

            printf("%20s%8d\n", nombre, id);
        }
        printf("\n");
        ret=1;
    }

    return ret;


}
















