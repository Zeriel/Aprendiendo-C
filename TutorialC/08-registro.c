/****************************************************************************
 *                                                                          *
 * Filename: 08-registro.c                                                  *
 *                                                                          *
 * Purpose : Ejemplo de uso de registro en Standard C.                      *
 *                                                                          *
 * History : Fecha                                                          *
 *           19-07-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Los registros en C son "structs", y sus campos se declaran entre llaves.
//Cada vez que declaremos una variable de tipo registro, la sintanxis para la
//declaracion debera ser:
//
//	struct tipoRegistro nombreVariable
//
//Cabe aclarar que la definicion de un registro lleva punto y coma tras el cierre
//de la llave.

#include <stdio.h>
#include <conio.h>

struct Alumno {				//Definicion de un registro (struct) en C
	char apellido[30];
	char legajo[10];
	int nota;
};							//Punto y coma que cierra la sentencia struct

struct Alumno unAlu;		//Declaracion de una variable "unAlu" tipo registro "Alumno" en C

struct Alumno vecAlu[5];	//Definicion de un array de tipo registro

int i;

int main(){
	printf("Ejemplo de uso de registros (structs) en C");
	_getch();
	_clrscr();
	printf("Ingrese apellido del alumno: ");
	scanf("%s", unAlu.apellido);			//El acceso a un campo de registro es igual en Pascal
	_clrscr();								//Como se carga un string, no se emplea &
	printf("Ingrese legajo del alumno: ");
	scanf("%s", unAlu.legajo);
	_clrscr();
	printf("Ingrese nota del alumno: ");
	scanf("%d", &unAlu.nota);				//Nota es un entero, aca si se usa &
	_clrscr();
	printf("Mostrando datos cargados en el registro\n");
	printf("---------------------------------------\n");
	printf("Nombre: %s\n", unAlu.apellido);
	printf("Legajo: %s\n", unAlu.legajo);
	printf("Nota:   %d", unAlu.nota);
	_getch();
	_clrscr();
	printf("Mismo ejemplo con un vector de alumnos");
	_getch();
	_clrscr();
	for (i=0; i<5; i++){					//Se carga el vector con 5 registros
		printf("Alumno: %d\n", i);
		printf("Ingrese apellido del alumno: ");
		scanf("%s", vecAlu[i].apellido);	//Accedo al campo del registro de la i-esima posicion del arreglo
		_clrscr();
		printf("Ingrese legajo del alumno: ");
		scanf("%s", vecAlu[i].legajo);
		_clrscr();
		printf("Ingrese nota del alumno: ");
		scanf("%d", &vecAlu[i].nota);
		_clrscr();
	}
	for (i=0; i<5; i++){
		printf("Mostrando datos cargados en el alumno %d\n", i);
		printf("---------------------------------------\n");
		printf("Nombre: %s\n", vecAlu[i].apellido);
		printf("Legajo: %s\n", vecAlu[i].legajo);
		printf("Nota:   %d", vecAlu[i].nota);
		_getch();
		_clrscr();
	}
	return 0;
}
