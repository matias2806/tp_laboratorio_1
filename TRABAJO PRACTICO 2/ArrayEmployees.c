#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"

int leerCadena (char cadena[], int tamanio){
    int longi;
    int caracter;

    setbuf(stdin, NULL);
    fgets (cadena, tamanio, stdin);
    longi=strlen(cadena);

    if (cadena[longi-1] == '\n')
    {
        cadena[longi-1] = '\0';
    }
    else
    {
        //vacio el buffer hasta el final (enter)
        while ((caracter = getchar()) != '\n' && caracter != EOF);
    }
    return (strlen(cadena));
}

int initEmployees(Employee* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL || len < 1)
    {
        for(i=0 ; i < len ; i++)
        {
            list[i].isEmpty =0;
        }
        retorno =0;
    }
    return retorno;
}

int buscadorEstados(Employee* list, int len){
    int i;
    int posicionLibre =-1;

    for (i=0; i <len ;i++)
    {
        if(list[i].isEmpty == 0 )
        {
         posicionLibre = i;
         break;
        }
    }
    return posicionLibre;
}

int addEmployee(Employee* list, int len, int id, char name[], char charlastName[],float salary,int sector){
    int posicion;
    int retorno = -1;

    if(list != NULL || len < 1 );
    {
        posicion = buscadorEstados(list, len);

        if(posicion != -1)
        {
            list[posicion].id =id;
            strcpy(list[posicion].name, name);
            strcpy(list[posicion].lastName, charlastName);
            list[posicion].salary = salary;
            list[posicion].sector = sector;
            list[posicion].isEmpty =1;
            retorno = 0;
        }
    }

return retorno;
}

int findEmployeeById(Employee* list, int len,int id){
    int i;
    int retorno =-1 ;
    // if (lista[i].legajo == legajo && lista[i].isEmpty ==0 )
    if(list != NULL  )//|| len > 0
    {
        for (i=0; i< len; i++)
        {
            if (list[i].id == id )
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int alta (Employee* list, int len){
    float salario;
    char nombre[51];
    char apellido[51];
    int sector;
    int ID;
    int posLibre;
    int control;
   // int largo;
    int retorno = -1;
    posLibre= buscadorEstados(list, len);
    if(posLibre !=-1)
    {
        do{
           control = getString(nombre, "Ingrese el nombre del Empleado: ","Error! El nombre del empleado posee mas de 50 caracteres\n",0,50);
        }while(control !=0);

        do{
            control =getString(apellido, "Ingrese el apellido del Empleado: ","Error! El apellido del empleado ccontiene mas de 50 caracteres\n",0,50);
        }while(control!=0);

        do{
            control = getInt(&sector, "Ingrese el sector al cual pertenece (sectores:1-2-3-4-5): ","Error! Solo validos sectores del 1 al 5\n",1,5);
        }while(control != 0 );

        do{
            control= getFloatSinMax(&salario, "Ingrese el sueldo del empleado: ","Error! No puede ingresar un sueldo menor a 0\n",0);
        }while(control != 0 );

        ID = idAutoincrementable(list, len);
        addEmployee(list, len, ID, nombre, apellido,salario,sector);

        retorno = 1;
    }
    return retorno;
}

int idAutoincrementable (Employee* list, int len){
    int i;
    int guardado = 0;

    for(i=0; i<len ; i++)
    {
        if(list[i].id > guardado && list[i].isEmpty != 0)
        {
        guardado = list[i].id;
        }

    }
    return guardado+1;
}

int getFloatSinMax(float* input,char message[],char eMessage[], float lowLimit){
    int retorno = 0;
    printf("%s", message);
    scanf("%f", input);

    if (*input < lowLimit )
    {
        printf("%s", eMessage);
        retorno = -1;
    }

    return retorno;
}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit){
    int retorno = 0;
    setbuf(stdin, NULL);
    printf("%s",message);
    scanf("%d", input);

    if (*input > hiLimit || *input <lowLimit )
    {
        printf("%s", eMessage);
        retorno = -1;
    }
    //if (isdigit())
    return retorno;
}

int getString(char input[],char message[],char eMessage[], int lowLimit, int hiLimit){
    int retorno = 0;
    printf("%s", message);
    setbuf(stdin, NULL);
    gets(input);
    int largo;
    largo=strlen(input);

    if (largo >= hiLimit || largo < lowLimit )
    {
        printf("%s",eMessage);
        retorno = -1;
    }
    return retorno;
}

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit){
    int retorno = 0;
    printf("%s", message);
    scanf("%c", input);

    if (*input > hiLimit || *input < lowLimit )
    {
        printf("%s",eMessage);
        retorno = -1;
    }

    return retorno;
}

void imprimeEstados(Employee* list, int len){
    int i;
    for(i=0 ;i < len ; i++)
    {
        printf ("[%d]=%d ",i,list[i].isEmpty );
    }
    printf("\n");
}

int removeEmployee(Employee* list, int len, int id){
    int retorno =-1;
    int posicion;
    char confirma;

    posicion= findEmployeeById(list,len,id);
    if(posicion==-1)
    {
        printf("No se encontro el ID\n");
        system("pause");
        system("cls");
    }
    else
    {
    imprimeUnaPersona( list, posicion);
    printf("Confirma borrado s/n \n");
    confirma = getche();
    printf("\n");



        if(confirma == 's' && list[posicion].isEmpty == 1 && list[posicion].id == id)
        {
            list[posicion].isEmpty = 0;
            retorno=0;
            system("pause");
            system("cls");
        }
        else
        {
            printf("Operacion Cancelada\n");
            system("pause");
            system("cls");
        }
    }
    return retorno;
}

void borrapersona(Employee* list, int len){
    int i;
    int Aborrar;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == 1)
        {
            imprimeUnaPersona(list, i);
        }
    }

    printf("\n\nIngrese el ID de la persona que usted desea eliminar: ");
    scanf("%d",&Aborrar);
    removeEmployee(list, len, Aborrar);

}

int menuModificar(Employee* list, int len, int id){

    char seguir= 's';
    int opcion;
    int control;
    int posicion;
    char nombre[51];
    char apellido[51];
    int sector;
    float salario;
    int retorno = -1;

    while(seguir == 's')
    {
        printf("MODIFICACION id = %d\n", id);
        printf("1. NOMBRE: \n");
        printf("2. APELLIDO: \n");
        printf("3. SECTOR: \n");
        printf("4. SALARIO: \n");
        printf("5. SALIR: \n");

        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
            do{
                control = getString(nombre, "Ingrese el nuevo nombre del Empleado: ","Error! El nombre del empleado posee mas de 50 caracteres\n",0,50);
            }while(control !=0);

            posicion= findEmployeeById(list,len,id);
            strcpy(list[posicion].name, nombre);

            break;
        case 2:
            do{
                control = getString(apellido, "Ingrese el nuevo apellido del Empleado: ","Error! El apellido del empleado posee mas de 50 caracteres\n",0,50);
            }while(control !=0);

            posicion= findEmployeeById(list,len,id);
            strcpy(list[posicion].lastName, apellido);
            break;
        case 3:
            do{
                control = getInt(&sector, "Ingrese el sector al cual pertenece (sectores:1-2-3-4-5): ","Error! Solo validos sectores del 1 al 5\n",1,5);
            }while(control != 0 );
            posicion= findEmployeeById(list,len,id);
            list[posicion].sector = sector;
            break;
        case 4:
            do{
                control= getFloatSinMax(&salario, "Ingrese el sueldo del empleado: ","Error! No puede ingresar un sueldo menor a 0\n",0);
            }while(control != 0 );
            posicion= findEmployeeById(list,len,id);
            list[posicion].salary = salario;
            break;
        case 5:
            seguir='n';
            retorno =0;
            system("cls");
            break;
        }
    }
    return retorno;
}

void modificar(Employee* list, int len){
    system("cls");
    int id;
    int aux;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == 1)
        {
            imprimeUnaPersona(list, i);
        }
    }

    printf("\n\nIngrese la ID que busca: ");
    scanf("%d", &id);
    imprimeUnaPersona( list, id-1);

    for(i=0; i<len; i++){
        if(list[i].id == id )
        {
            aux=menuModificar(list, len, id);
            break;
        }
    }
    if(aux == -1){
    printf("No se encontro la ID\n");
    //system("cls");
    }
    //system("cls");
}

void mostarTodoslosEmpleados(Employee* list, int len){
    int i;
    for(i=0; i<len; i++){
        if(list[i].isEmpty == 1 )
        {
            printf("Empleado %d nombre: %s\n",list[i].id, list[i].name );
            printf("Empleado %d apellido: %s\n",list[i].id, list[i].lastName );
            printf("Empleado %d sector: %d\n",list[i].id, list[i].sector );
            printf("Empleado %d sueldo: %.2f\n",list[i].id, list[i].salary );
        }
    }
}

void imprimeUnaPersona(Employee* list, int posicion){
     printf("ID:%2.d NOMBRE: %10s APELLIDO: %9s SECTOR: %d SUELDO: %.2f\n",list[posicion].id, list[posicion].name,list[posicion].lastName, list[posicion].sector, list[posicion].salary );
}

void menusDeInformes (Employee* list, int len){
    int opcion;
    int i;
    char seguir = 's';

    while(seguir == 's')
    {
        printf("------ MENU DE INFORMES ------\n\n");
        printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
        printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
        printf("Ingrese una opcion\n");
        printf("3. Salir.\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("LISTADO ORDENADO!\n\n");
            ordenaListadoDeEmpleadosApellido(list, len);
            ordenaListadoDeEmpleadosSector(list, len);
            for(i=0; i<len; i++)
            {
                if(list[i].isEmpty == 1)
                {
                    imprimeUnaPersona(list, i);
                }
            }
            system("pause");
            break;
        case 2:
            InformeSalario(list, len);
            break;
        case 3:
            seguir ='n';
            system("cls");
            break;
        }
    }
}

void ordenaListadoDeEmpleadosApellido(Employee* list, int len){
    Employee aux;
    int i, j;
    for(i=0 ; i<len-1 ; i++)
    {
        for(j=i+1 ; j<len ; j++)
        {
            if(strcmp(list[i].lastName, list[j].lastName)<0) // >0
            {
                aux=list[i];
                list[i]=list[j];
                list[j]= aux;
            }
        }
    }
}

void ordenaListadoDeEmpleadosSector(Employee* list, int len){
    int i, j;
    Employee aux;
    for(i=0 ; i<len-1 ; i++)
    {
        for(j=i+1 ; j<len ; j++)
        {
            if(list[i].sector >= list[j].sector)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]= aux;
            }
        }
    }
}

void InformeSalario(Employee* list, int len){
    system("cls");
    int i;
    float acumulador = 0;
    int contador=0;
    float promedio;
    int acumuladorDeMayorPromedio=0;
    for(i=0; i<len ; i++)
    {
        if(list[i].isEmpty == 1)
        {
            acumulador = list[i].salary + acumulador;
            contador++;
        }
    }
    promedio = acumulador / contador;
    printf("Total de los salarios: %.2f\n",acumulador);
    printf("Cantidad de salarios: %d\n",contador);
    printf("Promedio de salarios: %.2f\n",promedio);

    for(i=0; i<len; i++)
    {
        if (list[i].isEmpty ==1 && list[i].salary > promedio)
        {
            acumuladorDeMayorPromedio++;
        }
    }
    printf("Cantidad de empleados que superan el salario promedio: %d\n\n\n",acumuladorDeMayorPromedio);
    system("pause");
    system("cls");
}

void harcodeoEmployee(Employee* list, int len){
    addEmployee(list, len , 1, "matias", "palmieri", 1234.5 , 01);
    addEmployee(list, len , 2, "cristian", "celano", 10000 , 03);
    addEmployee(list, len , 3, "lorena", "bevilaqua", 5000.75 , 04);
    addEmployee(list, len , 4, "sasha", "losashuto", 111 , 02);
    addEmployee(list, len , 5, "gonzalo", "iglesias", 2000 , 04);
    addEmployee(list, len , 6, "alejandro", "laborde", 10 , 04);
    addEmployee(list, len , 7, "juan roman", "riquelme", 99999 , 05);
    addEmployee(list, len , 8, "martin", "palermo", 222222.22 , 05);
    addEmployee(list, len , 9, "wilmar", "barrios", 55555 , 02);
    addEmployee(list, len , 10, "cristian", "pavon", 77777 , 03);
    addEmployee(list, len , 11, "esteban", "andrada", 1.89 , 01);
    addEmployee(list, len , 12, "naithan", "nandez", 282828 , 05);
    addEmployee(list, len , 13, "pablo", "perez", 888 , 04);
    addEmployee(list, len , 14, "leonardo", "jara", 44.25 , 04);
    addEmployee(list, len , 15, "dario", "benedetto", 10 , 03);
}
