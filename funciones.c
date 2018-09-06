#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float operando(){
    float numero;
    printf("Ingrese un operando\n");
    scanf("%f", &numero);
    system("cls");
    return numero;
    /*Funcion para pedir un operando*/
}

float suma(float operando1, float operando2){
    float resultado;
    resultado = operando1+operando2;
    return resultado;
}


float resta(float operando1, float operando2){
    float resultado;
    resultado = operando1-operando2;
    return resultado;
}

float multiplicacion(float operando1, float operando2){
    float resultado;
    resultado = operando1*operando2;
    return resultado;
}


float division(float operando1, float operando2){
    float resultado;
    resultado = operando1/operando2;
    return resultado;
}

int getInt(int rango1, int rango2, char texto[], char textoError[]){
    int valida=0;
    int numero;

    while( valida == 0)
    {
        printf("%s\n", texto);
        scanf("%d", &numero);

        if(numero < rango1 || numero > rango2)
        {
            printf("%s El rango es de [%d a %d]\n",textoError, rango1, rango2);
        }
        else
        {
            valida=1;
        }
    }
    return numero;
}


float factorial (float numero){
    long respuesta;

    if (numero == 1)
    {
        return 1;
    }
    else
    {
        respuesta = numero * factorial (numero-1);
        return respuesta;
    }
}


void validarFactorial (float numero1){
    long entero;
    long resultado;
    entero = numero1;

    if (numero1 - entero != 0){
        printf("No se puede realizar el factorial de un numero con coma\n");
    }
    else{
        if (numero1 <= -1){
            printf("No se puede realizar el factorial de un numero negativo o de cero\n");
        }
        else if(numero1 == 0){
              printf("El factorial de 0 es = 1\n");

        }

        else{
        resultado = factorial(numero1);
        printf("El factorial de %f es = %ld\n",numero1,resultado);
        }
    }

    /* Valida que el mumero ingresado sea entero y positivo y realiza el factorial llamando a la funcion factorial*/
    }

