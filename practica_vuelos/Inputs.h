
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/** \brief show the main menu and ask for an option
 *
 * \param void
 * \return int return the option
 *
 */
int UserMenue(void);

/** \brief it generates an id incremented by one the last generated id
 *
 * \param maxId int: last generated id
 * \return int: returns the last id incremented by one
 *
 */
int GetId(int maxId);

/** \brief ask for a integrer number and I validate it
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param min int: minimum range
 * \param max int: maximum range
 * \return int: delivers a validated integer and within a range
 *
 */
int GetInt(char message[], char errorMessage[], int min, int max);

/** \brief validates that the array entered is an integer
 *
 * \param charArray[] char
 * \return int return 1 if it's ok and 0 if there is an ERROR
 *
 */
int IsAnIntNumber(char charArray[]);

/** \brief ask for a float number and I validate it
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param min float: minimum range
 * \param max float: maximum range
 * \return float: delivers a validated float and within a range
 *
 */
float GetFloat(char message[], char errorMessage[], float min, float max);

/** \brief validates that the array entered is an float
 *
 * \param charArray[] char
 * \return int: return 1 if it's ok and 0 if there is an ERROR
 *
 */
int IsAnfloatNumber(char charArray[]);

/** \brief it receives a string of characters, requests that data of this
 *         type be entered, validates that all its characters are letters
 *         and returns it by reference
 *
 * \param charArray[] char
 * \param mensaje[] char
 * \return void
 *
 */
void getName(char charArray[], char message[], char errorMessage[]);

/** \brief validates that all characters are letters
 *
 * \param charArray[] char
 * \return int: return 1 if it's ok and 0 if there is an ERROR
 *
 */
int IsAnAlphabetString(char charArray[]);

/** \brief validate that it is a natural number
 *
 * \param charArray[] char
 * \return int: return 1 if it's ok and 0 if there is an ERROR
 *
 */
int IsAnUnsignedIntNumber(char charArray[]);

/** \brief ask for a number and validate that it is an unsigned integer
 *
 * \param message[] char
 * \param errorMessage[] char
 * \return int delivers a validated natural number
 *
 */
int GetUnsignedInt(char message[], char errorMessage[]);

/** \brief it shows messages according to the number it receives,
 *         the messages are passed as a parameter. It includes a default on the switch
 *
 * \param int*
 * \param int*
 * \param ret int
 * \param message_3[] char
 * \param message_2[] char
 * \param message_1[] char
 * \param message0[] char
 * \param defaultMessage[] char
 * \return int
 *
 */
int FunctionReturnMessagesWithDefault(int* id, int*,int ret, char message_3[], char message_2[], char message_1[], char message0[], char defaultMessage[]);

/** \brief it shows messages according to the number it receives,
 *         the messages are passed as a parameter
 *
 * \param ret int value returned by a function
 * \param message_2[] char
 * \param message_1[] char
 * \param message0[] char
 * \param message1[] char
 * \return void
 *
 */
void FunctionReturnMessages(int ret, char message_2[], char message_1[], char message0[], char message1[]);

void getString(char charArray[], char message[]);
