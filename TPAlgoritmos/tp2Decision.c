/****************************************************************************
 *                                                                          *
 * Filename: tp2Decision.c                                                  *
 *                                                                          *
 * Purpose : Ejercicios del TP2 de algoritmos en Standard C.                *
 *                                                                          *
 * History : Fecha                                                          *
 *           16-07-2017														* 
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include <conio.h>

float num1, num2, num3, num4, res, cantDolares, precioDolar, monto, impuesto;


int main(){
	/*Ejercicio 2: 4 numeros reales, notificar signo de la suma*/
	printf("Ejercicio 2\n");
	printf("Ingrese el primer numero: ");
	scanf("%f", &num1);
	_clrscr();
	printf("Ingrese el segundo numero: ");
	scanf("%f", &num2);
	_clrscr();
	printf("Ingrese el tercer numero: ");
	scanf("%f", &num3);
	_clrscr();
	printf("Ingrese el cuarto numero: ");
	scanf("%f", &num4);
	_clrscr();
	res= num1+num2+num3+num4;
	if (res>0){
		printf("La suma es mayor a 0 y es: ");
		printf("%6f", res);
	}
	else if (res==0) {
		printf("La suma es igual a 0");
	}
	else {
		printf("La suma es menor a 0 y es: ");
		printf("%6f", res);
	}
	_getch();
	_clrscr();

	/*Ejercicio 4: compra de dolares en el banco*/
	printf("Ejercicio 4\n");
	printf("Bienvenido. Ingrese precio actual del dolar: ");
	scanf("%f", &precioDolar);
	printf("\nIngrese la cantidad de dolares a comprar: ");
	scanf("%f", &cantDolares);
	monto= cantDolares*precioDolar;
	_clrscr();
	if (cantDolares<=510) {
		impuesto=0;
	}
	else if (cantDolares>510 && cantDolares <1501) {
		impuesto= monto*0.02;
	}
	else if (cantDolares >=1501 && cantDolares<3501) {
		impuesto= monto*0.025;
	}
	else {
		impuesto= monto*0.04;
	}
	printf("----------------------------------------------\n");
	printf("Monto a comprar de dolares: %.2f", cantDolares);
	printf("\nPrecio actual del dolar:    %.2f", precioDolar);
	printf("\nMonto a pagar en pesos:     %.2f", monto);
	printf("\nImpuesto al dolar:          %.2f", impuesto);
	printf("\nTotal a abonar:             %.2f", monto+impuesto);
	printf("\n----------------------------------------------");
	_getch();
	_clrscr();
}
