/****************************************************************************
 *                                                                          *
 * Filename: 12-puntero.c                                                   *
 *                                                                          *
 * Purpose : Ejemplo de uso de variables tipo puntero en Standard C.        *
 *                                                                          *
 * History : Fecha                                                          *
 *           23-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//El manejo de punteros en C no es algo nuevo ya que los pasajes de parametros por
//referencia se hacen mediante el uso de punteros.
//
//Veremos con mas detalle como se operan los punteros, y ademas como se declaran variables
//de tal tipo para ser usadas en la aplicacion.
//
//La declaracion de una variable tipo puntero es:
//
//	tipo *nombrePuntero
//
//Los punteros pueden declararse junto a otros punteros o mezclados con variables del mismo tipo:
//
//	tipo *puntero1, *puntero2, noPuntero

#include<stdio.h>
#include<conio.h>

int num, *puntero;

int main(){
	printf("Ejemplo de uso de punteros\n");
	printf("Ingrese un numero: ");
	scanf("%d", &num);		//Lectura normal de un valor
	_clrscr();
	puntero=&num;			//Asigno a la variable puntero la direccion de num
	printf("Ingreso: %d\nLa variable puntero contiene: %d", num, *puntero);	//Muestro el contenido de num y del puntero
	_getch();																//El puntero se accede con asterisco (*)
	_clrscr();
	*puntero=10;			//Modificamos la informacion de num a traves del puntero a su direccion de memoria
	printf("Ahora la variable 'num' tiene valor: %d", num);
	_getch();
	_clrscr();
	return 0;
}
