#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "MisFunciones.h"


int controller_ListEmployee(LinkedList* pArrayListEmployee){
    int i;
    Employee* casteo;
    if(pArrayListEmployee == NULL){
        printf("No se pudo abrir");
    }
    else{
        for(i=0; i<ll_len(pArrayListEmployee); i++){
            casteo=ll_get(pArrayListEmployee, i);
            printf("%d %s %d %d\n", casteo->id, casteo->nombre, casteo->horasTrabajadas, casteo->sueldo);

        }
    }
    return 1;
}


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    FILE* f;
    int aux;
    //int aux2;

    f = fopen (path, "r");


    if(f == NULL){
        aux = 0;
        printf("Problemas al crear el archivo de texto\n");
        system("pause");
    }
    else{
         aux = 1;
         printf("Archivo de texto abierto con exito\n");
         aux= parser_EmployeeFromText(f , pArrayListEmployee);
         system("pause");
    }
    return aux;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){

    FILE* f;
    int auxiliar;

    f= fopen(path, "rb");

    if(f==NULL){
        auxiliar=0;
        printf("Problemas al crear el archivo de texto\n");
        system("pause");
    }
    else{
        auxiliar=1;
        auxiliar= parser_EmployeeFromBinary(f , pArrayListEmployee);
        printf("Archivo de texto abierto con exito\n");
        system("pause");
    }

    return auxiliar;
}


int controller_addEmployee(LinkedList* pArrayListEmployee){

    Employee* empleadoNuevo;
    empleadoNuevo =(void*)employee_new();
    int id, sueldo, horasTrabajadas;
    char nombre[128];
    int aux;

    do{
        aux=getInt(&id,"Ingrese la ID\n","El id no esta dentro de los parametros \n", 0, 99999999);
    }while(aux==-1);

    do{
        aux=getInt(&sueldo,"Ingrese el sueldo\n","El sueldo no esta dentro de los parametros \n", 0, 99999999);
    }while(aux==-1);

    do{
        aux=getInt(&horasTrabajadas,"Ingrese la cantidad de horas trabajadas\n","La cantidad de horas trabajadas no esta dentro de los parametros\n", 0, 99999999);
    }while(aux==-1);

    do{
        aux=getString(nombre,"Ingrese el nombre del empleado\n","El nombre no esta dentro de los parametros\n", 0, 128);
    }while(aux==-1);

    employee_setId(empleadoNuevo, id);
    employee_setNombre(empleadoNuevo, nombre);
    employee_setHorasTrabajadas(empleadoNuevo, horasTrabajadas);
    employee_setSueldo(empleadoNuevo, sueldo);

    ll_add(pArrayListEmployee, empleadoNuevo);

    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee){
    int aModificar;
    int opcion =0;
    Employee* empleado;

    char nuevoNombre;
    int* nuevoSueldo;
    int* nuevaCantHoras;
    int aux;
    int aux2;

    controller_ListEmployee(pArrayListEmployee);

    printf("Ingrese el ID que desea modificar\n");
    scanf("%d",&aModificar);

    empleado = ll_get(pArrayListEmployee, (aModificar-1));

    do{
    printf("¿Que desea modificar?\n");
    printf("1- Nombre\n");
    printf("2- Cantidad de horas trabajadas\n");
    printf("3- Sueldo\n");
    printf("4- Salir\n");

    scanf("%d", &opcion);

        switch(opcion){
            case 1:
                system("cls");
                aux=getString(&nuevoNombre,"Ingrese el nuevo nombre: ","Error el nombre no cumple los parametros",0,128);
                aux2=employee_setNombre(empleado,&nuevoNombre);
                    if(aux==0 &&aux2==1){
                        printf("\nNombre cambiado con exito\n\n");
                    }
                break;
            case 2:
                system("cls");
                aux=getInt(&nuevaCantHoras,"Ingrese la nueva cantidad de horas trabajadas: ","Error no cumple los parametros",0,99999999);
                aux2=employee_setHorasTrabajadas(empleado,nuevaCantHoras);
                    if(aux==0 && aux2==1){
                        printf("\nHoras trabajadas cambiado con exito\n\n");
                    }
                break;
            case 3:
                system("cls");
                aux=getInt(&nuevoSueldo,"Ingrese el nuevo sueldo: ","Error no cumple los parametros",0,99999999);
                aux2=employee_setSueldo(empleado,nuevoSueldo);
                    if(aux==0 && aux2==1){
                        printf("\nSueldo cambiado con exito\n\n");
                    }
                break;
            case 4:
                system("cls");
                opcion=4;
                break;
        }
    }while(opcion!=4);

    return 1;
}



int controller_removeEmployee(LinkedList* pArrayListEmployee){
    int aBorrar,i, largo, confirma;
    int flag=0;
    Employee* empleado;
    controller_ListEmployee(pArrayListEmployee);
    largo = ll_len(pArrayListEmployee);

    printf("Ingrese el ID que desea eliminar\n");
    scanf("%d", &aBorrar);

    for(i=0;i<largo;i++){
        empleado= ll_get(pArrayListEmployee, i);
        if(empleado->id == aBorrar ){
            printf("Esta seguro de que desea eliminar ?\n1--->Si\n2--->No\n");
            scanf("%d",&confirma );
            if(confirma ==1){
                empleado=ll_pop(pArrayListEmployee,i);
                printf("Se llamaba %s habia trabajado %d horas por un sueldo de %d \n\n",empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
                flag=1;
                break;
            }
            else{
                flag=0;
                break;
            }
        }
    }

    if(flag ==1){
        printf("Empleado eliminado con exito\n");
    }
    else{
        printf("No se logro eliminar al id %d\n",aBorrar);
    }
    return 1;
}



int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int opcion;

    printf("----------Menu de Ordenamientos----------\n\n");

    do{
    printf("Ingrese el criterio de ordenamiento\n");
    printf("1-->ID de menor a mayor\n2-->ID de mayor a menor\n");
    printf("3-->Horas de trabajo de menor a mayor\n4-->Horas de trabajo de mayor a menor\n");
    printf("5-->Sueldo de menor a mayor\n6-->Sueldo de mayor a menor\n");
    printf("7-->Nombre de la A-Z\n8-->Nombre de la Z-A\n9-->Salir\n");
    scanf("%d",&opcion);
    printf("\n\n");
        switch (opcion){
        case 1:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroID,1);/// de menor a mayor
            printf("Listado Ordenado\n");
            break;
        case 2:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroID,0);///de mayor a menor
            printf("Listado Ordenado\n");
            break;
        case 3:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroHoras,1);/// de menor a mayor este tarda un monton
            printf("Listado Ordenado\n");
            break;
        case 4:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroHoras,0);///de mayor a menor
            printf("Listado Ordenado\n");
            break;
        case 5:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroSueldo,1);/// de menor a mayor
            printf("Listado Ordenado\n");
            break;
        case 6:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaEnteroSueldo,0);///de mayor a menor
            printf("Listado Ordenado\n");
            break;
        case 7:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaCadenaNombre,1);/// de menor a mayor
            printf("Listado Ordenado\n");
            break;
        case 8:
            printf("Ordenando...\nAguarde....\n");
            ll_sort(pArrayListEmployee,employee_OrdenaCadenaNombre,0);///de mayor a menor
            printf("Listado Ordenado\n");
            break;
        case 9:
            controller_ListEmployee(pArrayListEmployee);
            break;
        }
    }while(opcion != 10);

    return 1;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int i, largo;
    int retorno=0;
    FILE* f;
    Employee* empleado;

    f= fopen(path, "w");
    if(f != NULL){
        largo=ll_len(pArrayListEmployee);
        for(i=0; i<largo; i++){
            empleado= ll_get(pArrayListEmployee, i);
            fprintf(f,"%d,%s,%d,%d\n",empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        }
        printf("Archivo guardado\n\n");
        retorno=1;
    }
    else{
        printf("No se pudo guardar el archivo\n");
        retorno=0;
    }
    fclose(f);
    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    int i;
    int retorno=0;
    int largo;
    FILE* f;
    Employee* empleado;

    f=fopen(path, "wb");
    if(f != NULL){
        largo= ll_len(pArrayListEmployee);
        for(i=0;i<largo;i++){
            empleado=ll_get(pArrayListEmployee, i);
            fwrite(empleado,sizeof(Employee),1,f);
        }
        printf("Archivo binario guardado con exito\n");
        system("pause");
        retorno=1;

    }
    else{
        printf("No se pudo guardar el archivo\n");
        system("pause");
        retorno=0;
    }

    fclose(f);
    return retorno;
}

