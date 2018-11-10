#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"



/// Parsea los datos de los empleados desde el archivo data.csv (modo texto).
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    int retorno =0;
    Employee* empleado;
    int aux;
    int id;
    char nombre [128];
    int horasTrabajo;
    int sueldo;



    if(pFile != NULL){
        do{
            aux= fscanf(pFile, "%d,%[^,],%d,%d \n", &id, nombre, &horasTrabajo, &sueldo);
            if(aux ==4){
                empleado = (void*)employee_newParametros(&id, nombre, &horasTrabajo,&sueldo);
                ll_add(pArrayListEmployee, empleado);
                retorno = 1;
            }
        }while(!feof(pFile));
    }


    return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    int retorno =0;
    Employee empleado;
    Employee* pEmpleado;
    int aux;


   if(pFile != NULL){
        while(!feof(pFile)){

            aux = fread(&empleado,sizeof(Employee),1,pFile);
            if(aux==1){
                if(feof(pFile)){
                    break;
                }
                else{
                    pEmpleado = (void*)employee_newParametros(&empleado.id, empleado.nombre, &empleado.horasTrabajadas,&empleado.sueldo);
                    ll_add(pArrayListEmployee, pEmpleado);
                }
            }
        }
    }

    return retorno;
}
