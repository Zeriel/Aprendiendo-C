/****************************************************************************
 *                                                                          *
 * Filename: 13-arregloDeArreglos.c                                         *
 *                                                                          *
 * Purpose : Ejemplo de arrays de arrays en Standard C.   					*
 *                                                                          *
 * History : Fecha                                                          *
 *           13-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Retomamos nuevamente a los arreglos en este punto dado que, para poder entender como definir un
//arreglo de arreglos, necesitabamos entender primero el concepto y uso de punteros a memoria.
//
//En C, podemos definir un arreglo que contenga otros arreglos mediante el uso de un arreglo de
//punteros, en donde cada puntero apuntara a un arreglo. Como los arreglos son un tipo de dato
//homogeneo, cada arreglo apuntado por el arreglo padre y dicho arreglo padre deberan ser
//del mismo tipo de dato.
//
//Para poder acceder a los arreglos de nuestro arreglo de arreglos, declararemos un puntero
//del mismo tipo que los arreglos, y lo igualaremos al arreglo de arreglos en la i-esima posicion,
//que sera el arreglo que queramos mostrar. Luego, podremos recorrer este puntero, el cual contiene
//el arreglo que queremos ver.
//
//Si bien los arreglos hijos deben ser del mismo tipo que el arreglo padre, cada uno de los arreglos
//puede tener un tamaño distinto.



#include <stdio.h>
#include <conio.h>

int main(){
	int *arrayOfArrays[3];		//Defino un arreglo de tres punteros de tipo entero
	int array1[3] = {1,2,3};	//Defino el primer arreglo con datos ya cargados
	int array2[3] = {4,5,6};	//Defino el segundo arreglo con datos ya cargados
	int array3[3] = {7,8,9};	//Defino el tercer arreglo con datos ya cargados
	//--Estos arreglos tienen el mismo tamaño (3) pero podrian tener tamaños distintos
	int *punteroAArray;			//Defino la variable puntero que usare para recorrer cada arreglo

	arrayOfArrays[0] = array1;	//Asigno cada arreglo a una posicion del arreglo padre
	arrayOfArrays[1] = array2;
	arrayOfArrays[2] = array3;

	for (int i=0; i<3; i++){	//Un for por cada puntero del arreglo padre
		printf("Arreglo: %d\n", i);
		punteroAArray= arrayOfArrays[i];	//Obtengo el arreglo actual al que accedo con i
		for (int j=0; j<3; j++){			//Recorro dicho arreglo para mostrar los datos
			//Si los arreglos tuvieran tamaños distintos, cada uno llevaria su propio for
			//Como yo los defini a todos iguales, puedo usar el mismo for para recorrerlos a los tres
 			printf("Posicion: %d - Valor: %d\n", j, punteroAArray[j]);
			_getch();
		}
		_clrscr();
	}
	  return(0);
}
