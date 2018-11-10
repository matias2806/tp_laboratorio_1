#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"


Employee* employee_new(){

    Employee* puntero;

    puntero = (Employee*) malloc(sizeof (Employee));

    if(puntero !=  NULL){
        puntero->id =0;
        puntero->horasTrabajadas=0;
        puntero->sueldo=0;
        strcpy(puntero->nombre, "");
    }


    return puntero;
}

Employee* employee_newParametros(int* idStr,char* nombreStr,int* horasTrabajadasStr, int* sueldo){
    Employee* aux;

    aux = employee_new();

    if(aux !=  NULL){
        aux->id = *idStr;
        aux->horasTrabajadas = *horasTrabajadasStr;
        aux->sueldo = *sueldo;
        strcpy(aux->nombre, nombreStr);
    }


    return aux;

}

void employee_delete(Employee* lista){

        if(lista !=  NULL){
        lista->id =0;
        lista->horasTrabajadas=0;
        lista->sueldo=0;
        strcpy(lista->nombre, "");
    }

    free(lista);

}


int employee_setId(Employee* lista,int id){
    int todoOk =0;

    if(lista != NULL && id>0){
        lista->id =id;
        todoOk = 1;

    }
    return todoOk;
}
int employee_getId(Employee* lista,int* id){
    int todoOk =0;

    if(lista != NULL && id != NULL)
    {
        *id= lista->id;
        todoOk =1;
    }
    return todoOk;
}



int employee_setNombre(Employee* lista,char* nombre){
    int todoOk =0;

    if(lista != NULL){
        strcpy (lista->nombre, nombre);
        todoOk = 1;

    }
    return todoOk;

}
int employee_getNombre(Employee* lista,char* nombre){
    int todoOk =0;

    if(lista != NULL && nombre != NULL)
    {
        strcpy(nombre, lista->nombre);
        todoOk =1;
    }
    return todoOk;
}



int employee_setHorasTrabajadas(Employee* lista,int horasTrabajadas){
    int todoOk =0;

    if(lista != NULL && horasTrabajadas > 0){
        lista->horasTrabajadas = horasTrabajadas;
        todoOk = 1;

    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* lista,int* horasTrabajadas){
    int todoOk =0;

    if(lista != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = lista->horasTrabajadas;
        todoOk =1;
    }
    return todoOk;

}



int employee_setSueldo(Employee* lista,int sueldo){
    int todoOk =0;

    if(lista != NULL && sueldo > 0){
        lista->sueldo = sueldo;
        todoOk =1;

    }
    return todoOk;
}
int employee_getSueldo(Employee* lista,int* sueldo){
    int todoOk =0;

    if(lista != NULL  && sueldo !=  NULL){
            *sueldo = lista->sueldo;
            todoOk =1;
    }
    return todoOk;
}





int employee_OrdenaEnteroID(void* elementoA, void* elementoB){
    int retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;

    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(empleadoA->id >= empleadoB->id)
    {
        retorno =1 ;
    }
    if(empleadoA->id < empleadoB->id){
        retorno = -1;
    }

return retorno;
}
int employee_OrdenaEnteroHoras(void* elementoA, void* elementoB){
    int retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;

    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(empleadoA->horasTrabajadas > empleadoB->horasTrabajadas)
    {
        retorno =1 ;
    }
    if(empleadoA->horasTrabajadas < empleadoB->horasTrabajadas){
        retorno = -1;
    }

return retorno;
}
int employee_OrdenaEnteroSueldo(void* elementoA, void* elementoB){
    int retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;

    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(empleadoA->sueldo > empleadoB->sueldo)
    {
        retorno =1 ;
    }
    if(empleadoA->sueldo < empleadoB->sueldo){
        retorno = -1;
    }

return retorno;
}
int employee_OrdenaCadenaNombre(void* elementoA, void* elementoB){
    int retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;

    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;



    if(strcmp(empleadoA->nombre, empleadoB->nombre)<0)
    {
        retorno =1 ;
    }
    if(strcmp(empleadoA->nombre, empleadoB->nombre)>0){
        retorno = -1;
    }

return retorno;
}
