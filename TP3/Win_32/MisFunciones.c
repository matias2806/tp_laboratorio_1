#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"



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




int menu(){

    int opcion;

    system("cls");
    printf("Menu:\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.cvs (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.cvs (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    scanf("%d", &opcion);


    return opcion;
}




