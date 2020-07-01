#include "LinkedList.h"
#include "Vuelos.h"
#include "Pilotos.h"
#include <stdio.h>
#include <stdlib.h>
int parser_FlightsFromText(FILE* pFile, LinkedList* pArrayListFlights);
int parser_FlightsToText(FILE* pFile , LinkedList* pArrayList);
int parser_PilotsToText(FILE* pFile, LinkedList* myPilotsList);
int parser_PilotsFromText(FILE* pFile, LinkedList* myPilotsList);
