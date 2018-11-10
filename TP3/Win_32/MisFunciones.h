#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado * \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error * \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char input[],char message[],char eMessage[], int lowLimit, int hiLimit);


/**
* \brief Solicita un número al usuario y lo valida el largo
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloatSinMax(float* input,char message[],char eMessage[], float lowLimit);

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita un caracter al usuario y lo valida * \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error * \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);



/** \brief te muestra un menu
 *
 * \return int te devuelve la opcion que el usuario haya ingresado
 *
 */
int menu();




#endif //FUNCIONES_H_INCLUDED
