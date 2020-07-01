#include "Pilotos.h"
int pilotos_hardcodear(LinkedList* myList)
{
    ePilotos* piloto;
    int i;
    int idPiloto[10]={1,2,3,4,5,6,7,8,9,9};
    char nombre[10][100]={"Alex Lifeson" ,"Richard Bach","John Kerry","Erwin Rommel","Stephen Coonts","Cecilia" ,"Juana","Pedro","Martin","Martin Tincho"};

    if(myList!=NULL)
    {
       for(i=0;i<10; i++)
       {
           piloto=pilotos_newParametros(nombre[i], idPiloto[i]);
           if(piloto!=NULL)
           {
                ll_add(myList, piloto);
           }
       }
    }
    return 0;
}
ePilotos* pilotos_newParametros(char nombre[], int idPiloto)
{
   ePilotos* piloto= (ePilotos*)malloc(sizeof(ePilotos));
    if(piloto!=NULL)
    {

        pilotos_setIdPiloto(piloto, idPiloto);
        pilotos_setNombre(piloto, nombre);

    }

    return piloto;
}
int pilotos_buscarPorId(LinkedList* myPilotsList,int idPiloto, char nombrePiloto[])
{
    int i;
    int ret=0;
    ePilotos* piloto;
    char nombre[100];
    int id;
    if(myPilotsList != NULL)
    {
        for(i=0; i<ll_len(myPilotsList); i++)
        {
            piloto=ll_get(myPilotsList, i);
            pilotos_getIdPiloto(piloto, &id);

            if(id == idPiloto)
            {
                pilotos_getNombre(piloto,nombre);
                strcpy(nombrePiloto, nombre);
                ret=1;
                break;
            }
        }
    }
    return ret;
}

int pilotos_setIdPiloto(ePilotos* piloto, int idPiloto)
{
    int ret=0;
    if(piloto!=NULL)
    {
        piloto->idPiloto=idPiloto;
        ret=1;
    }
    return ret;
}

int pilotos_getIdPiloto(ePilotos* piloto, int* idPiloto)
{
    int ret=0;
    if(piloto!=NULL)
    {
        *idPiloto=piloto->idPiloto;
        ret=1;
    }
    return ret;

}

int pilotos_getNombre(ePilotos* piloto, char* nombre)
{
    int ret=0;
    if(piloto!=NULL)
    {
        strcpy(nombre,piloto->nombre);
        ret=1;
    }

    return ret;
}

int pilotos_setNombre(ePilotos* piloto, char* nombre)
{
    int ret=0;
    if(piloto!=NULL)
    {
        strcpy(piloto->nombre,nombre);
        ret=1;
    }
    return ret;
}
