#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief
 *
 * \return float va a ser tu operador el 1 y el 2
 *
 */
float operando();



/** \brief realiza una suma de dos flotantes
 *
 * \param operando1 float primer operando
 * \param operando2 float segundo operando
 * \return float el resultado de la suma
 *
 */
float suma(float operando1, float operando2);


/** \brief realiza una resta de dos flotantes
 *
 * \param operando1 float primer operando
 * \param operando2 float segundo operando
 * \return float el resultado de la resta
 *
 */
float resta(float operando1, float operando2);


/** \brief realiza una multiplicacion de dos flotantes
 *
 * \param operando1 float primer operando
 * \param operando2 float segundo operando
 * \return float el resultado de la multiplicacion
 *
 */
float multiplicacion(float operando1, float operando2);



/** \brief realiza una division de dos flotantes
 *
 * \param operando1 float primer operando
 * \param operando2 float segundo operando
 * \return float el resultado de la division
 *
 */
float division(float operando1, float operando2);

/** \brief Te pide un entero y valida que este dentro de un rango y que sea un entero con posible mensaje de entrada y de error
 *
 * \param rango1 int valor minimo
 * \param rango2 int valor maximo
 * \param texto[] char texto de entrada
 * \param textoError[] char texto en caso de que sea error
 * \return int
 *
 */
int getInt(int rango1, int rango2, char texto[], char textoError[]);



/** \brief Realiza el factorial de un numero
 *
 * \param el numero que le vas a calcular el factorial
 * \return el valor del factorial
 *
 */
float factorial (float numero);






/** \brief valida que el numero que te dio el usuario no sea ni 0 ni negativo ni sea un numero con coma
 *
 * \param numero1 float es el numero que te dieron por teclado en base a este se valida que el numero no sea ni un numero con coma, ni negativo ni cero
 * \return void te devuelve un mensaje de error si el numero no pasa la validacion y si el numero pasa la validacion te devuelve un mensaje mostrandote el factorial( funcion factorial)
 *
 */
void validarFactorial (float numero1);
#endif // FUNCIONES_H_INCLUDED
