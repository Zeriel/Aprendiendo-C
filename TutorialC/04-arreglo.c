/****************************************************************************
 *                                                                          *
 * Filename: 04-arreglo.c                                                   *
 *                                                                          *
 * Purpose : Ejemplo de arrays en Standard C.                               *
 *                                                                          *
 * History : Fecha                                                          *
 *           18-07-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include <conio.h>

int vecNum[5], matNum[2][2], i, j;  //Defino un vector y una matriz de tipo entero

int main(){
	printf("Ejemplo de uso de arreglo tipo vector\n");
	for (i=0; i<5; i++){    		//Realizo una carga del vector
		printf("Vector posicion: %d\n", i);
		printf("Ingrese valor entero: ");
		scanf("%d", &vecNum[i]);	//Notese que en el scan el vector va con & porque use los []
		_clrscr();					//Con los strings (que son arrays tambien) no usamos [] ni &
	}
	for (i=0; i<5; i++){			//Realizo un muestreo del vector
		printf("Vector posición: %d valor asignado: %d", i, vecNum[i]);
		_getch();
		_clrscr();
	}
	printf("Ejemplo de uso de arreglo tipo matriz\n");
	for (i=0; i<2; i++){			//Itero por fila
		for (j=0; j<2; j++){		//Itero por columna
		printf("Matriz posicion: %d %d\n", i,j);
		printf("Ingrese valor entero: ");
		scanf("%d", &matNum[i][j]);
		_clrscr();
		}
	}
	for (i=0; i<2; i++){			//Realizo un muestreo de la matriz
		for (j=0; j<2; j++){
		printf("Matriz posicion: %d %d valor asignado: %d\n", i, j, matNum[i][j]);
		_getch();
		_clrscr();
		}
	}
	return 0;
}
