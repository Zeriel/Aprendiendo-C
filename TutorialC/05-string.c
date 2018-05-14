/****************************************************************************
 *                                                                          *
 * Filename: 05-string.c                                                    *
 *                                                                          *
 * Purpose : Explicacion de la libreria <string.h> en Standard C.           *
 *                                                                          *
 * History : Fecha                                                          *
 *           22-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//En C los strings no existen como tal, en su lugar tenemos arrays de caracteres.
//Esto puede generar ciertos problemas cuando queramos realizar operaciones tales como
//cambiar el valor "nombre" de un registro tipo "alumno", por ejemplo, y resulte que 
//logicamente "nombre" es un array de caracteres (un string en C).
//Lo lógico sera realizar una asignacion del tipo:
//
//	alu.nombre="nuevo nombre";
//
//Pero como nombre es un array de caracteres y no un string normal, esta asignacion
//nos dara un error.
//
//Para solucionar esto, primero invocaremos la libreria <string.h> que nos aporta
//varias funciones utiles. Abajo dejare las mas relevantes con su funcionalidad:
//
//strlen(str) --> Retorna el tamaño de "str".
//
//strcmp(str1, str2)   --> Compara str1 con str2. Si son iguales retorna 0, si str1 es mayor retorna
//						   entero mayor a 0, y si str2 es mayor que str1 retorna entero menor a 0.
//
//strcpy(dest, source) --> IMPORTANTE: copia en destino el string fuente "source". Es la manera en
//						   la que podremos asignar un string a un array.
//
//strcat(dest, source) --> Copia al final del destino lo que hay en fuente. Seria un concatenar.
//						   Si el destino tiene "hola" podriamos pasarle como fuente " mundo".
//
//Ademas, tambien tendremos detalles cuando queramos cargar un string con un scanf, ya que los strings,
//al ser internamente una direccion de memoria al primer elemento, no llevan el ampersand (&) porque ya
//estan haciendo referencia a su direccion de memoria.


#include <stdio.h>
#include <conio.h>
#include <string.h>		//Libreria de strings

char palabra[20];		//Declaro un string de 20 caracteres (array de 20 posiciones)

int main(){
	printf("Ingrese un string de 20 maximo: ");
	scanf("%s", palabra);				//Para leer un string no hay problema. Notese que no lleva ampersand
	printf("Ingreso %s\n", palabra);
	strcpy(palabra, "nuevaPalabra");	//Para asignar un valor directamente usaremos la funcion correspondiente
	printf("String cambiado a %s\n", palabra);
	_getch();
	return 0;
}
