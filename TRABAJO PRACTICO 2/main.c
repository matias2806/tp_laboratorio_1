#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    char seguir= 's';
    int opcion= 0;
    Employee empleado [TAM];
    initEmployees(empleado, TAM);

    harcodeoEmployee(empleado, TAM);  // PROFESOR ACA TIENE UN HARCODEO PARA CONTROLAR SON SOLO 15 USUARIOS!

    while(seguir == 's')
    {
        printf("1. ALTAS: \n"); //Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero de Id. El resto de los campos se le pedir� al usuario
        printf("2. MODIFICAR: \n");// Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector
        printf("3. BAJA: \n");//Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
        printf("4. INFORMAR: \n");//1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
        printf("5. SALIR: \n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            alta (empleado, TAM);
            system("cls");
            break;
        case 2:
            modificar(empleado, TAM);
            break;
        case 3:
            borrapersona(empleado, TAM);
            break;
        case 4:
            menusDeInformes (empleado, TAM);
            break;
        case 5:
            seguir='n';
            break;
        }
    }
    return 0;
}
