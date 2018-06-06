/****************************************************************************
 *                                                                          *
 * Filename: 11-recursion.c                                                 *
 *                                                                          *
 * Purpose : Ejemplo de modulos recursivos en Standard C.                   *
 *                                                                          *
 * History : Fecha                                                          *
 *           23-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//La recursion en C no difiere en nada con la recursion vista tanto en pseudocodigo como en
//el lenguaje Pascal. Basta con adaptarse a la sintaxis de C y su manejo de funciones y
//procedimientos.

//Como ejemplo recursivo, veremos el calculo del factorial de un numero dado.

#include<stdio.h>
#include<conio.h>

//FUNCION RECURSIVA

int factorial(int x){			//Paso el numero que quiero calcular por copia.
	if (x==0){					//Primero chequeo el caso base, en el factorial es x=0.
		return 1;				//El factorial de 0 es 1.
	}
	else{						//Si no llegue a 0, invoco recursivamente a factorial con x-1
		return x*factorial(x-1);	//IMPORTANTE: Esta es la llamada recursiva a la funcion, es decir,
	}								//una autoinvocacion.
}


//MAIN

int main(){
	int num;
	printf("Calculo de factorial mediante funcion recursiva\n");
	printf("Ingrese un numero: ");
	scanf("%d", &num);
	printf("El factorial de %d es: %d", num, factorial(num));	//Invoco a la funcion recursiva
	_getch();
	_clrscr();
	return 0;
}
