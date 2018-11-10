#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "MisFunciones.h"



int main()
{

    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

        option = menu();
        switch(option)
        {
            case 1:
                system("cls");
                controller_loadFromText("data.csv",listaEmpleados);///anda
                break;
            case 2:
                system("cls");
                controller_loadFromBinary("dataEnBin.bin",listaEmpleados);///anda
                break;
            case 3:
                controller_addEmployee(listaEmpleados);///anda
                system("pause");
                break;
            case 4:
                system("cls");
                controller_editEmployee(listaEmpleados);///anda
                system("pause");
                break;
            case 5:
                system("cls");
                controller_removeEmployee(listaEmpleados);///anda
                system("pause");
                break;
            case 6:
                system("cls");
                controller_ListEmployee(listaEmpleados);///anda
                system("pause");
                break;
            case 7:
                system("cls");
                controller_sortEmployee(listaEmpleados);///anda
                system("pause");
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.csv" , listaEmpleados);///anda
                system("pause");
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("dataEnBin.bin" , listaEmpleados);///anda
                break;
            case 10:
                system("cls");
                break;
        }
    }while(option != 10);
    return 0;
}

