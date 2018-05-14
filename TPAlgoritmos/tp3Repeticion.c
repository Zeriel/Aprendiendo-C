/****************************************************************************
 *                                                                          *
 * Filename: tp3Repeticion.c                                                *
 *                                                                          *
 * Purpose : Ejercicios del TP3 de algoritmos en Standard C.                *
 *                                                                          *
 * History : Fecha                                                          *
 *           16-07-2017														* 
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include <conio.h>

int i, nota, totNota;
float promedio;
char res;



int main(){
	/*Ejercicio 1: promedio de notas de 40 alumnos (10 para simplificar)*/
	printf("Ejercicio 1");
	_getch();
	_clrscr();
	for (i=1; i<11; i++) {
		printf("Ingrese nota del alumno %d", i);
		printf(": ");
		scanf("%d", &nota);
		totNota= totNota+nota;
		_clrscr();
	}
	promedio= totNota/10;
	printf("El promedio de las notas es: %.0f", promedio);
	getchar();  //uso getchar para atrapar el ENTER que esta siendo atrapado por el scan de abajo
	_getch();
	_clrscr();

	/*Mismo ejercicio sin conocer la cantidad de alumnos*/

	printf("¿Hay notas para cargar? S/N ");
	scanf("%c", &res);
	i=0;
	promedio=0;
	totNota= 0;
	while (res!= 'n' && res!='N') {
		i++;
		printf("Ingrese nota del alumno %d", i);
		printf(": ");
		scanf("%d", &nota);
		getchar(); //Esto es para solucional el char que agregamos con ENTER, el cual lo toma el scanf
		totNota= totNota+nota;
		_clrscr();
		printf("¿Hay mas notas para cargar? S/N ");
		scanf("%c", &res);
		_clrscr();
	}
	if (i != 0) {
	promedio= totNota/i;
	}
	printf("El promedio de las notas es: %.0f", promedio);
	_getch();
	_clrscr();
}
