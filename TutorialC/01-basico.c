/****************************************************************************
 *                                                                          *
 * Filename: 01-basico.c                                                    *
 *                                                                          *
 * Purpose : Ejemplo de escritura y lectura en Standard C.                  *
 *                                                                          *
 * History : Fecha                                                          *
 *           16-07-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h> /*incluyo librerias*/
#include <conio.h>

//Declaro variables globales

int num1;
float num2;
char caracter, palabra[10];

//TIPOS:
//int   --> Entero
//float --> Flotante, real
//char  --> Caracter
//tipo [tamaño] --> Array (mas adelante)

//CARACTERES ESPECIALES DE C
//  % --> Es para indicar un tipo de dato esperado
//	%d --> Entero
//	%f --> Float
//	%.xf --> Float con x numeros decimales
//	%c --> Caracter
//	%s --> String

//& y * --> Trabajan sobre la direccion de memoria de la variable, no sobre ella
//	& --> Devuelve la dirección de memoria
//	* --> Modifica el dato en la direccion de memoria (puntero)

//Defino el main del programa

//DETALLE: El compilador lanzara un warning por "old-style function definition" con
//Main. Esto es porque en las nuevas versiones de C, si una funcion no lleva parametros,
//lleva entre parentesis la palabra clave "void". Nostros dejaremos un parentesis vacio
//() para representar la falta de parametros. La advertencia no interferira con la
//compilacion y la aplicacion fucnionara correctamente.

int main(){
	printf("Esto es una impresion en pantalla");
	_getch();   //El readkey
	_clrscr();  //El clear screen
	printf("Ingrese un numero entero: ");
	scanf("%d", &num1); //%d indica que espero recibir un entero, &num1 dice que lo guarde en la
	_clrscr();			//direccion de num1
	printf("Usted ingreso: %d", num1); //Imprimo lo que acabo de cargar
	_getch();
	_clrscr();
	printf("Ingrese un numero real: ");
	scanf("%f", &num2);
	_clrscr();
	printf("Usted ingreso %f", num2);
	_getch();
	_clrscr();
	getchar();
	printf("Demostrando diferenca entre char y string\n"); //el \n deja una linea
	printf("Ingrese un caracter: ");
	scanf("%c", &caracter);  //el %c es para caracter
	_clrscr();
	printf("El caracter ingresado fue %c ", caracter);
	_getch();
	_clrscr();
	printf("Ingrese una cadena de caracteres: ");
	scanf("%s", palabra);  //el %s es para string
	_clrscr();
	printf("La cadena ingresada fue %s ", palabra);
	_getch();
	_clrscr();
	return 0; //convencion de C, indica que el main se ejecuto correctamente
}
