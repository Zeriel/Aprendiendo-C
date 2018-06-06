/****************************************************************************
 *                                                                          *
 * Filename: 14-arregloDeArreglos2.c                                        *
 *                                                                          *
 * Purpose : Ejemplo de arrays de arrays en Standard C.   					*
 *                                                                          *
 * History : Fecha                                                          *
 *           13-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//En el ejemplo anterior vimos el manejo de un arreglo de arreglos con datos fijos. Ahora
//definiremos arreglos sin cargar datos para que los mismos sean cargados desde la aplicacion.
//Ademas, cada arreglo tendra un tamaño distinto, para demostrar que no necesariamente deben ser
//todos iguales en tamaño.

#include <stdio.h>
#include <conio.h>

void cargarArreglo(int arreglo[], int tamanio);		//Carga un arreglo con datos

void mostrarArreglo(int arreglo[], int tamanio);	//Muestra los datos de un arreglo

int main(){
	int *arrayOfArrays[3];		//Defino un arreglo de tres punteros de tipo entero
	int array1[3];				//Defino el primer arreglo
	int array2[2];				//Defino el segundo arreglo
	int array3[4];				//Defino el tercer
	int *punteroAArray;			//Con esta variable puedo operar cada arreglo
	int tamanio;				//Lo usare para saber hasta donde recorrer

	arrayOfArrays[0] = array1;	//Asigno cada arreglo a una posicion del arreglo padre
	arrayOfArrays[1] = array2;
	arrayOfArrays[2] = array3;

	//--Cargo cada arreglo con datos
	for (int i=0; i<3; i++){	//Un for por cada puntero del arreglo padre
		printf("Arreglo: %d\n", i+1);
		punteroAArray= arrayOfArrays[i];	//Obtengo el arreglo actual al que accedo con i
		if (i==0){			//Es el primer arreglo, tiene tamaño 3
			tamanio= 3;
		}
		else if (i==1){		//Segundo arreglo, tiene tamaño 2
			tamanio= 2;
		}
		else{				//Tercer arreglo, tiene tamaño 4
			tamanio= 4;
		}
		cargarArreglo(punteroAArray, tamanio);	//En cada iteracion, el puntero y el tamaño cambiaran
	}

	//Ya estan cargados los array, recorremos cada uno para imprimir sus datos usando un for igual al anterior

	for (int i=0; i<3; i++){	//Un for por cada puntero del arreglo padre
		printf("Arreglo: %d\n", i+1);
		punteroAArray= arrayOfArrays[i];	//Obtengo el arreglo actual al que accedo con i
		if (i==0){			//Es el primer arreglo tiene tamaño 3
			tamanio= 3;
		}
		else if (i==1){		//Segundo arreglo, tiene tamaño 2
			tamanio= 2;
		}
		else{				//Tercer arreglo, tiene tamaño 4
			tamanio= 4;
		}
		mostrarArreglo(punteroAArray, tamanio);	//En cada iteracion, el puntero y el tamaño cambiaran
	}	
	  return(0);
}


//Defino modulos prototipados

void cargarArreglo(int arreglo[], int tamanio){
	for (int i=0; i<tamanio; i++){
		printf("Posicion %d - Ingrese valor: ", i+1);
		scanf("%d", &arreglo[i]);
		_clrscr();
	}
}

void mostrarArreglo(int arreglo[], int tamanio){
	for (int i=0; i<tamanio; i++){
		printf("Posicion %d - Valor: %d\n", i+1, arreglo[i]);
		_getch();
	}
	_clrscr();
}
