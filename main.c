#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    char caracter = 's';
    int opcion=0;
    float op1=0;
    float op2=0;
    float ResultadoSuma;
    float ResultadoResta;
    float ResultadoDivision;
    float ResultadoMultiplicacion;

    while(caracter=='s')
    {
        printf("1. Ingresar 1er operando (A= %.2f)\n", op1);
        printf("2. Ingresar 2do operando (B= %.2f)\n", op2);
        printf("3. Calcular todas las operaciones \n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        opcion=getInt(1,5, "ingrese un valor", "Error! Reingrese el dato.");

        switch(opcion){

            case 1:
                op1=operando();
                break;
            case 2:
                op2=operando();
                break;
            case 3://(suma, resta, multiplicacion div y fact)
                system("cls");
                ResultadoSuma= suma(op1, op2);
                ResultadoResta= resta(op1,op2);
                ResultadoMultiplicacion= multiplicacion(op1,op2);
                ResultadoDivision=division(op1,op2);
                break;
            case 4:
                system ("cls");
                printf("El resultado de %.2f+%.2f es: %f \n",op1,op2,ResultadoSuma);
                printf("El resultado de %.2f-%.2f es: %f \n",op1,op2,ResultadoResta);

                if(op2 ==0)
                {
                    ResultadoDivision=printf("No es posible dividir por cero\n");
                }
                else
                {
                    printf("El resultado de %.2f/%.2f es: %.2f\n",op1,op2,ResultadoDivision);
                }
                printf("El resultado de %.2f*%.2f es: %.2f\n",op1,op2,ResultadoMultiplicacion);
                validarFactorial(op1);
                validarFactorial(op2);
                system("pause");
                system("cls");
                break;
            case 5:
                caracter='n';
                break;
        }
    }
    return 0;
}

