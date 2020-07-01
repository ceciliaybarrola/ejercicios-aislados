
#include "Inputs.h"

int UserMenue(void)
{
    int option;

    printf( "MENU DE OPCIONES\n"
           "1. Leer archivo de texto.\n"
            "2. Imprimir vuelos\n"
            "3. Cantidad pasajeros totales\n"
            "4. Cantidad pasajeros a irlanda\n"
            "5. Cargar los vuelos cortos en un archivo\n"
            "6. Listar los vuelos a portugal\n"
            "7. Lista de vuelos sin Alex\n"
            "8. Filtrar vuelos\n"
            "9. Conoce a los pilotos de nuestra aerolinea\n"
            "10. Salir\n\n");

    option=GetInt("Ingrese una opcion: ","No es una opcion valida, reingrese la opcion: ",1,10);

    return option;
}

float GetFloat(char message[], char errorMessage[], float min, float max)
{
    float floatNumber;
    char stringNum[200];
    //pido datos
    printf("%s", message);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';

    floatNumber=atof(stringNum);

    while(IsAnfloatNumber(stringNum)!=1|| floatNumber<min || floatNumber>max)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';

        floatNumber=atof(stringNum);
    }
    return floatNumber;
}
int IsAnfloatNumber(char charArray[])
{
    int i=0;
    int ret=1;
    int dotsCounter=0;

    if(charArray[0]=='\0'||charArray[0]=='.'||charArray[strlen(charArray)-1]=='.'){
        ret=0;
    }
    else{
        if(charArray[0]=='-'){
         i=1;
        }
    }
    for( ;charArray[i]!='\0' ;i++)
    {
         if(charArray[i]<'0'||charArray[i]>'9')
        {
            if(charArray[i]!= '.'||dotsCounter!=0)
            {
               ret=0;
               break;
            }
            else{
                dotsCounter++;
            }
        }
    }
    return ret;
}

void getName(char charArray[], char message[], char errorMessage[])
{
    printf("%s", message);
    fflush(stdin);
    //__fpurge(stdin);
    fgets(charArray, 51, stdin);

    charArray[strlen(charArray)-1] = '\0';

    while(IsAnAlphabetString(charArray)==1)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        //__fpurge(stdin);
        fgets(charArray, 51, stdin);
        charArray[strlen(charArray)-1] = '\0';
    }

}
int IsAnAlphabetString(char charArray[])
{
    int i;
    int flag=0;

    for(i=0; charArray[i]!='\0'; i++)
    {
        if((charArray[i]<'a' || charArray[i]>'z') && (charArray[i]<'A' || charArray[i]>'Z'))
        {
            flag=1;
            break;
        }
    }
    return flag;
}
void getString(char charArray[], char message[])
{
        printf("%s", message);
    fflush(stdin);
    //__fpurge(stdin);
    fgets(charArray, 100, stdin);

    charArray[strlen(charArray)-1] = '\0';
}




int GetId(int maxId)
{
    maxId++;
    return maxId;
}

int GetInt(char message[], char errorMessage[], int min, int max)
{
    int num;
    char stringNum[200];
    //pido datos
    printf("%s", message);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';
    //convierto a stringNum a un numero int
    num=atoi(stringNum);
    //si la funcion IsAnumber es distinto a 1 omito las siguentescondiciones porque no es un numero
    //si pasa la primer condicion es porque es un numero y el la variable 'num' tiene un valor numerico valido
    //valida si esta en el rango y de no ser asi entra en el while para repetir el proceso
    while(IsAnIntNumber(stringNum)!=1|| num<min || num>max)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';

        num=atoi(stringNum);
    }
    return num;

}
int IsAnIntNumber(char charArray[])
{
    int i=0;
    int ret=1;

     if(charArray[0]=='-'){
        i=1;
    }
    for( ; charArray[i]!='\0' ;i++)
    {
        if(charArray[i]<'0'||charArray[i]>'9')
        {
            ret=0;
            break;
        }
    }

    return ret;
}
int GetUnsignedInt(char message[], char errorMessage[])
{
    int num;
    char stringNum[200];
    //pido datos
    printf("%s", message);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';

    //si la funcion IsAnumber es distinto a 1 omito no es un numero

    while(IsAnUnsignedIntNumber(stringNum)!=1)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';
    }
     //convierto a stringNum a un numero int
     num=atoi(stringNum);

    return num;



}
int IsAnUnsignedIntNumber(char charArray[])
{
    int i;
    int ret=1;

    if(charArray[0]=='\0')
    {
        ret=0;
    }

    for(i=0 ; charArray[i]!='\0' ;i++)
    {
        if(charArray[i]<'0'||charArray[i]>'9')
        {
            ret=0;
            break;
        }
    }
    return ret;
}
int FunctionReturnMessagesWithDefault(int* id,int* flagMenue,int ret, char message_3[], char message_2[], char message_1[], char message0[], char defaultMessage[])
{
    int Return=0;

    switch(ret){
    case -3:
        printf("%s\n",message_3);
        break;
    case -2:
        printf("%s\n",message_2);
        *id=0;
        *flagMenue=1;
        break;
    case -1:
        printf("%s\n",message_1);
        break;
    case 0:
        printf("%s\n",message0);
        break;
    default:
        *flagMenue=1;
        printf("%s\n",defaultMessage);
        *id=ret;
    }

    return Return;

}
void FunctionReturnMessages(int ret, char message_2[], char message_1[], char message0[], char message1[])
{
    switch(ret){
        case 0:
            printf("%s\n", message0);
            break;
        case 1:
            printf("%s\n", message1);
            break;
        case -1:
            printf("%s\n", message_1);
            break;
        case -2:
            printf("%s\n", message_2);
            break;

    }
}


