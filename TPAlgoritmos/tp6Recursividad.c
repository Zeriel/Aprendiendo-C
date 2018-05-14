/****************************************************************************
 *                                                                          *
 * Filename: tp6Recursion.c                                                 *
 *                                                                          *
 * Purpose : Ejercicios del TP6 de algoritmos en Standard C.                *
 *                                                                          *
 * History : Fecha                                                          *
 *           23-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

#include<stdio.h>
#include<conio.h>

void inicializar(int v[]){
	for (int i=0; i<5; i++){
		printf("Posicion %d. Ingrese valor: ", i+1);
		scanf("%d", &v[i]);
		_clrscr();
	}
}

//FUNCION INCISO a)
int sumaVector(int v[], int tamanio){
	if (tamanio<0){		//Recordar que un array en C comienza en la posicion 0.
		return 0;
	}
	else{
		return v[tamanio]+sumaVector(v, tamanio-1);
	}
}

//FUNCION INCISO b)
int mulTres (int v[], int tamanio){
	int mul=0;				//Declaro una variable local para saber si sumo o no el multiplo
	if (tamanio<0){
		return 0;
	}
	else{
		if (v[tamanio]%3==0){	//En C, la funcion mod para el resto de la division es % (simbolo de porcentaje).
			mul=1;				//Si el valor es multiplo de 3, mul tomara valor 1.
		}
		return mul+mulTres(v, tamanio-1);	//Sumo mul a la llamada recursiva, si era multiplo, entonces valdra 1 y su suma
	}										//sera incremental. Si no era multiplo, sumara 0.
}

//FUNCION INCISO c)
int pares(int v[], int tamanio){
	int esPar=0;
	if (tamanio<0){
		return 0;
	}
	else{
		if (tamanio%2!=0 && v[tamanio]%2==0){
			esPar=1;
		}
		return esPar+pares(v, tamanio-1);
	}
}

int numeros[5];

int main(){
	printf("Ejercicio 8\n");
	printf("Inciso a)\n");
	printf("\n");
	inicializar(numeros);
	printf("La suma de los valores del vector es: %d", sumaVector(numeros, 4));  //Recordar que el arreglo de 5 posiciones
	_getch();																	 //va de 0 a 4.
	_clrscr();
	printf("Inciso b)\n");
	printf("Hay %d multiplos de 3 en el vector", mulTres(numeros, 4));
	_getch();
	_clrscr();
	printf("Inciso c)\n");
	printf("Cantidad de valores pares en posiciones impares: %d", pares(numeros, 4));
	printf("\nRECORDAR QUE EL ARREGLO DE C VA DE LA POSICION 0 A LA 4, NO DE 1 A 5");
	_getch();
	_clrscr();
}
