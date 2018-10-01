
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;


/** \brief vacia el buffer hasta el final
 *
 * \param char va a ser la cadena de caracteres que le pasas
 * \param int va a ser el tamanio de la cadena, es decir, La cantidad de caracteres que va a leer
 * \return el largo de la cadena
 *
 */
int leerCadena (char cadena[], int tamanio);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);


/** \brief
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int buscadorEstados(Employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/
int addEmployee(Employee* list, int len, int id, char name[], char charlastName[],float salary,int sector);



/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/ int findEmployeeById(Employee* list, int len,int id);



/** \brief pide nombre apellido sector y salario
 *
 * \param list Employee* aca se van a guardar los datos
 * \param len int es para armar los for
 * \return 1 en caso de que todo haya salido bien y -1 en caso contrario
 *
 */
int alta (Employee* list, int len);


/**
* \brief Solicita un número al usuario y valida que sea mayor a un minimo
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
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

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado * \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error * \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char input[],char message[],char eMessage[], int lowLimit, int hiLimit);


/** \brief Genera IDS autoincrementables
 *
 * \param list Employee* es el puntero donde se van a guardar lasIDS
 * \param len int es el largo que tendra el puntero de estructura es para armar los for
 * \return te devuelve la id
 *
 */
int idAutoincrementable (Employee* list, int len);


/** \brief Me imprime todos los estados de un puntero 0 vacio 1 ocupado
 *
 * \param list Employee* es el puntero donde estan los estados
 * \param len int es el largo que debe recorrer
 * \return void
 *
 */
void imprimeEstados(Employee* list, int len);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);



/** \brief Muestra a todas los empleados cargados y pide el ID de la que se desea eliminar
 *
 * \param list Employee* de aca busca las personas cargadas
 * \param len int y de aca el largo
 * \return void no devuelve nada
 *
 */
void borrapersona(Employee* list, int len);



/** \brief Es el menu de modificar y es la funcion que pide y almacena el dato nuevo
 *
 * \param list Employee* aca va a agarrar al empleado al cual se quiere modificar y el usuario puede elejjir que campo desea modificar
 * \param len int el largo de la estructura para poder recorrerla completa
 * \param id int el lugar donde va a estar almacenado el empleado que se desea modificar
 * \return int 0 en caso de que el usuario quiera salir (toque opcion 5) o -1 en caso contrario
 *
 */
int menuModificar(Employee* list, int len, int id);


/** \brief esta es la funcion que va en el main es quien pide el ID para que luego se pase a la funcion menuModificar
 *
 * \param list Employee* de aca selecciona a los empleados
 * \param len int y de aca el largo de lo que va a imprimir
 * \return void no devuelve nada
 *
 */
void modificar(Employee* list, int len);

/** \brief imprime todos los empleados de la estructura Employee
 *
 * \param list Employee* de aca selecciona a los empleados
 * \param len int y de aca el largo de lo que va a imprimir
 * \return void no devuelve nada
 *
 */
void mostarTodoslosEmpleados(Employee* list, int len);

/** \brief Imprime una sola persona de la estructura Employee
 *
 * \param list Employee* de aca selecciona a la persona
 * \param posicion int de aca elije la posicion de la persona
 * \return void no devuelve nada
 *
 */
void imprimeUnaPersona(Employee* list, int posicion);


/** \brief unifica todo lo que sea informes y arma lo que es el menu, esta es la funcion que va en el main
 *
 * \param list Employee* la necesita para pasarselas a otras funciones
 * \param len int la necesita para pasarselas a otras funciones
 * \return void no devuelve nada
 *
 */
void menusDeInformes (Employee* list, int len);


/** \brief metodo de burbuja por el campo apellido de la estructura Employee
 *
 * \param list Employee* de aca se va a seleccionar el campo apellido para que sea ordenado
 * \param len int por aca se va a recorrer los sectores
 * \return void no devuleve nada
 *
 */
void ordenaListadoDeEmpleadosApellido(Employee* list, int len);


/** \brief metodo de burbuja por el campo sector de la estructura Employee
 *
 * \param list Employee* de aca se va a seleccionar el campo sector para que sea ordenado
 * \param len int por aca se va a recorrer los sectores
 * \return void no devuelve nada
 *
 */
void ordenaListadoDeEmpleadosSector(Employee* list, int len);

/** \brief Realiza el informe de los salarios (saca total de salario, cantidad de sueldos, promedio y cuantos empleados estan arriba de este mismo)
 *
 * \param list Employee* de aca va a sacar los sueldos
 * \param len int por aca va a recorrer los sueldos de la estructura
 * \return void no devuelve nada
 *
 */
void InformeSalario(Employee* list, int len);

/** \brief Harcodea 15 empleados de la estructura Employee
 *
 * \param list Employee* es donde se van a almacenar lo harcodeado
 * \param len int es para ver si hay o no lugar para que sea aalmacenado
 * \return void no devuelve nada
 *
 */
void harcodeoEmployee(Employee* list, int len);
