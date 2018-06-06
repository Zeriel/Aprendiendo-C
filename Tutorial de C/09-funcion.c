/****************************************************************************
 *                                                                          *
 * Filename: 09-funcion.c                                                   *
 *                                                                          *
 * Purpose : Ejemplo de uso de funciones en Standard C.                     *
 *                                                                          *
 * History : Fecha                                                          *
 *           16-07-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//En C, el pasaje por referencia se maneja mediante un pasaje por copia de la direccion de memoria de la
//variable referenciada empleando el ampersand (&), y trabajando al parametro "referenciado" como si fuera
//un puntero (que en realidad lo es) mediante el asterisco (*). Es en practica una referencia como el var de
//pascal pero desglosado en el movimiento de direcciones de memoria de las variables para la referencia. 

//Otra notacion respecto a funciones en C: una manera estandar de definir funciones es colocar un prototipo de
//la funcion antes del main, en donde solo estara el encabezado de la funcion sin implementar y terminara con
//punto y coma (;) luego de la ultima llave, tras esto trabajar el main como si la funcion ya estuviera implementada
//y al terminar el main definir la funcion con su encabezado e implementacion (esta vez no termina con punto y coma).
//
//Esto no quita que podamos declarar funciones directamente antes del main como en Pascal, pero lo marco como nota a
//tener en cuenta para el uso de C. Este tutorial usara la forma estandar de C, el siguiente (funcion2.c) usara la
//forma normal de Pascal para definir funciones y procedimientos.

//DETALLE: Como ya se aclaro para el main en el basico.c, el compilador lanzara un warning por "old-style function
//definition" por cada funcion sin parametros que escribamos, ya que emplearemos el modelo viejo dejando parentesis vacios
//y no la nueva forma que es escribiendo "void" si no hay parametros para esa funcion.

//	Forma que usamos:
//		tipo nombreFuncion()

//	Forma actual:
//		tipo nombreFuncion(void)

#include <stdio.h>
#include <conio.h>

int mult ( int x, int y );  //Funcion que devuelve la multiplicacion de dos numeros enteros

void multReferencia (int x, int y, int *resul);   //Procedimiento que hace lo mismo que mult pero devuelve
												  //el resultado en un parametro por referencia



int main()
{
 	int x;
 	int y;
	int z;
  
  	printf( "Ingrese dos numeros para multiplicarlos: " );
  	scanf( "%d", &x );
 	scanf( "%d", &y );
  	printf( "El producto de los numeros es: %d\n", mult( x, y ) );  //Invoco la funcion, el valor devuelto es asignado al printf
  	_getch(); 
	_clrscr();
	printf("Ahora haremos lo mismo pero por referncia");
	_getch();
	_clrscr();
	multReferencia(x, y, &z);   //Notese como no enviamos la variable sino su direccion en memoria
	printf( "El producto de los numeros es: %d\n", z);  //La variable z por referencia tendra el valor
  	_getch(); 
	_clrscr();
	return 0;
}

int mult (int x, int y)
{
  return x * y;			//Las funciones se asignan su valor con return
}

void multReferencia (int x, int y, int *resul){ //El parametro que enviamos era una direccion, asique la recibimos como puntero
	*resul=x*y;  //De nuevo, notese como operamos con resul como un puntero, asi modificamos por
}				 //referencia al valor de la variable original
