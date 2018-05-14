/****************************************************************************
 *                                                                          *
 * Filename: tp4Arreglo.c                                                   *
 *                                                                          *
 * Purpose : Ejercicios del TP4 de algoritmos en Standard C.                *
 *                                                                          *
 * History : Fecha                                                          *
 *           19-08-2017														* 
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

#include<stdio.h>
#include<conio.h>

int vecEntero[5], matEntero[2][3], i,j, acum=0, valor;

	//vecEntero: defino un vector de 5 posiciones de tipo entero.
	//matEntero: defino una matriz de 2x3 posiciones de tipo entero
	//acum=0: declaro un acumulador con valor inicial 0.


int main(){
	//Ejercicio 1 de vectores:
	printf("Ejercicio 1: uso de vector");
	_getch();
	_clrscr();
	for(i=0; i<5; i++){					 //Carga inicial del vector con 5 enteros
		printf("Posicion: %d - Ingrese valor: ", i+1);   //El +1 es para arrancar desde 1 y no 0
		scanf("%d", &vecEntero[i]);
		_clrscr();
	}
	//Inciso a) Buscar el maximo valor
	for (i=0; i<5; i++){
		if(vecEntero[i]>acum){			 //Evaluo cada elemento con el maximo actual
			acum=vecEntero[i];			 //Si es mayor, lo guardo como nuevo maximo
		}
	}
	printf("El valor maximo es: %d", acum);
	_getch();
	_clrscr();
	//Inciso b) Buscar un valor ingresado por el usuario
	printf("Ingrese valor a buscar: ");
	scanf("%d", &valor);
	_clrscr();
	i=0;								 //Hago i=0 para el while
	while (i<5 && valor!=vecEntero[i]){  //Busco la posicion del valor dado
		i++;
	}
	if(i<5){							 //Si el indice no sobrepaso al vector, encontre el dato
		printf("El valor %d existe. Posicion: %d", valor, i+1);
	}
	else{
		printf("El valor %d no existe", valor);
	}
	_getch();
	_clrscr();

	//Ejercicio 1 de matriz
	printf("Ejercicio 1: uso de matriz");
	_getch();
	_clrscr();
	for (i=0; i<2; i++){
		for (j=0; j<3; j++){			 //Carga inicial de la matriz
			printf("Posicion: %d-%d - Ingrese valor: ", i+1, j+1);
			scanf("%d", &matEntero[i][j]);
			_clrscr();
		}
	}
	//Inciso a) Buscar el minimo valor
	acum=9999; 							 //Reutilizo acum para buscar el minimo
	for (i=0; i<2; i++){
		for (j=0; j<3; j++){
			if(matEntero[i][j] < acum){
				acum=matEntero[i][j];
			}
		}
	}
	printf("El valor minimo es: %d", acum);
	_getch();
	_clrscr();
	//Inciso b) Buscar un valor dado por el usuario
	//Inciso c) Buscar la posicion de un valor dado por el usuario
	printf("Ingrese valor a buscar: ");
	scanf("%d", &valor);
	_clrscr();
	i=0;
	j=0;
	while (i<2 && valor!=matEntero[i][j]){
		if(j==3){
			j=0;
			i++;
		}
		j++;
	}
	if(i<2){
		printf("El valor %d existe. Posicion: %d-%d", valor, i+1, j+1);
	}
	else{
		printf("El valor %d no existe", valor);
	}
	_getch();
	_clrscr();
	//Inciso d) Listado fila x columna
	printf("Listado de la matriz en formato fila columna\n");
	printf("--------------------------------------------\n");
	for (i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("Fila: %d Columna %d Valor: %d\n", i+1, j+1, matEntero[i][j]);
		}
	}
	_getch();
	_clrscr();
	//Inciso e) Listado columna x fila
	printf("Listado de la matriz en formato columna fila\n");
	printf("--------------------------------------------\n");
	for (j=0; j<3; j++){
		for(i=0; i<2; i++){
			printf("Fila: %d Columna %d Valor: %d\n", i+1, j+1, matEntero[i][j]);
		}
	}
	_getch();
	_clrscr();
}
