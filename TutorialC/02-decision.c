/****************************************************************************
 *                                                                          *
 * Filename: 02-decision.c                                                  *
 *                                                                          *
 * Purpose : Ejemplo de uso de decisión en Standard C.                      *
 *                                                                          *
 * History : Fecha                                                          *
 *           16-07-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include <conio.h>

//OPERADORES LOGICOS EN C
//
//EQUAL -->				==
//NOT EQUAL -->			!=
//NOT -->				!
//AND -->				&&
//OR -->				||
//MENOR/MENOR IGUAL -->	< / <=
//MAYOR/MAYOR IGUAL --> > / >=

int main()
{
	int x;
	int dia;
	printf("Ejemplo de uso de decision en C\n");
	_getch();
	printf("Ingrese un numero: ");
	scanf("%d", &x);
	if (x<0) {				//Este es el IF en C
		printf("%d\n", x);
		printf(" es negativo");
	}
	else if (x==0) {		//A diferencia de Pascal, en C no hay problemas con los punto y coma y el ELSE
		printf("\nEl número es 0");
	}
	else {
		printf("%d", x);
		printf(" es positivo");
	}
	printf("\n");
	_getch();
	printf("Ingrese edad: ");
	scanf("%d", &x);
	printf("\n");
	if (x<18) {
		printf("Es menor de edad\n");
	}
	else if(x>18 && x<40) {		//Operador logico AND
		printf("Es adulto\n");
	}
	else {
		printf("Es adulto mayor\n");
	}
	_getch();
	_clrscr();
	printf("Ingrese un numero de dia de la semana (1-7): ");
	scanf("%d", &dia);
	switch (dia){			//Este es el CASO en C
		case (1):
			printf("Es lunes");
			break;			//Cada opcion del caso lleva un BREAK para salir del mismo
		case 2:
			printf("Es martes");
			
		case 3:
			printf("Es miercoles");
			
		case 4:
			printf("Es jueves");
			
		case 5:
			printf("Es viernes");
			break;
		case 6:
			printf("Es sabado");
			break;
		case 7:
			printf("Es domingo");
			break;	
		default:		//El OTHERWHISE u OTRO CASO es DEFAULT en C
			printf("Dia inexistente");
			break;
	}
	_getch();
	return 0;
}
