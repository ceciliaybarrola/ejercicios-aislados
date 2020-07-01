#include "parser.h"
#include "Inputs.h"
#include "LinkedList.h"

#include "Pilotos.h"

int controller_Ybarrola_loadFromText(LinkedList* myList, LinkedList* myPilotsList);
int controller_Ybarrola_listFlights(LinkedList* myList, LinkedList* myPilotsList);
int controller_Ybarrola_countTotalPassengers(LinkedList* myList);
int controller_Ybarrola_countPassengersToIreland(LinkedList* myList);
int controller_Ybarrola_filterShortFlights(LinkedList* myList, LinkedList* myPilotsList);
int controller_Ybarrola_ListFligthsToPortugal(LinkedList* myList, LinkedList* myPilotsList);
int controller_Ybarrola_ListFligthsWithoutLifeson(LinkedList* myList, LinkedList* myPilotsList);
int controller_Ybarrola_loadPilotsfromText(LinkedList* myPilotsList);
int controller_Ybarrola_ListFilteredFligths(LinkedList* myList, LinkedList* myPilotsList);
int controller_Ybarrola_listPilotos(LinkedList* myPilotsList);
int controller_Ybarrola_loadPilotstoText(LinkedList* myPilotsList);
