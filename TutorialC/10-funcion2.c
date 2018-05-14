/****************************************************************************
 *                                                                          *
 * Filename: 10-funcion2.c                                                  *
 *                                                                          *
 * Purpose : Ejemplo de uso de funciones con arrays en Standard C.          *
 *                                                                          *
 * History : Fecha                                                          *
 *           22-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//IMPORTANTE: En C no existe el pasaje por copia de un arreglo, ya que los arreglos
//en realidad son punteros al primer valor del arreglo, por lo que
//
//	void procedimiento(int a[])  pasaje de arreglo sin especificar tamaño
//
//y
//
//	void procedimiento(int a[10])  pasaje de arreglo especificando su tamaño
//
//son entendidos por C como
//
//	void procedimiento(int *a)   pasaje del puntero del arreglo
//
//Que es el pasaje del puntero que apunta al primer elemento del array.
//En definitiva, pasar un arreglo como parametro en realidad es pasar el puntero a
//su primer elemento y es asi como lo ve el compilador C, por lo que las anteriores
//formas de pasaje son identicas. Ademas, en la programacion C esta mal visto pasar
//un arreglo con argumentos en el parametro de una funcion.

#include <stdio.h>
#include <conio.h>
#include <string.h>

void inicializar(int vec[]){
	for (int i=0; i<5; i++){  	//Recordemos que la variable indice puede ser declarada en el for
		vec[i]=0;			  	//Este vec se modificara en la funcion que invoca a inicializar
	}
}

void inicializarCopia(int vec[]){
	int vec2[5];
	for (int i=0; i<5; i++){   	//Como no podemos pasar arrays por copia, estoy duplicando el arreglo
		vec2[i]=vec[i];		   	//para no modificar el original. En ultima instancia, esto podria
	}						   	//reemplazar el pasaje por copia en Pascal, de ser necesario
	for (int i=0; i<5; i++){
		vec2[i]=1;				//Este vec es local a la funcion y no se vera reflejado en el main
	}
}

//Para simular el pasaje por copia, declare un arreglo local a la funcion del mismo formato que el
//arreglo que se recibe por parametro, e igualo dicho arreglo al local para operar el local y no el
//referenciado en el parametro. Es una copia desglozada y manual pero en la practica funciona.

//Ahora definire registro y arreglo de registro para testear lo que vimos arriba con otras funciones:

struct Alumno{
	char apellido[15];
	char legajo[10];
	float nota;
};

void inicializarRegistro(struct Alumno vec[3]){ //Modificacion por referencia de un array de registros
	for (int i=0; i<3; i++){  
		strcpy(vec[i].apellido,"jorge");
		strcpy(vec[i].legajo,"05-44244-2");
		vec[i].nota=6;		  
	}
}

void inicializarRegistroCopia(struct Alumno vec[3]){ //Pasaje "por copia" de un array de registros
	struct Alumno vecCopia[3];
	int i;
	for (i=0; i<3; i++){
		vecCopia[i]=vec[i];		//Copio el arreglo para no modificar el original
	}
	for (i=0; i<3; i++){  
		strcpy(vecCopia[i].apellido,"MODIFICADO");
		strcpy(vecCopia[i].legajo,"05-MODI-2");
		vecCopia[i].nota=99;		  
	}
}

void listarRegistro(struct Alumno vec[3]){ 
	for (int i=0; i<3; i++){
		printf("ALUMNO: %d\n", i+1);
		printf("--------------\n");
		printf("Apellido: %s\n", vec[i].apellido);
		printf("Legajo: %s\n", vec[i].legajo);
		printf("Nota: %.2f\n", vec[i].nota);
		_getch();
	}
}

struct Alumno vecAlu[5];

int main(){
	int vecNum[5], i;
	inicializar(vecNum);				//Cargo el arreglo por referencia
	inicializarCopia(vecNum);			//Cargo el arreglo por copia
	for (i=0; i<5; i++){
		printf("Valor del arreglo en i= %d: %d\n", i, vecNum[i]);
	}
	_getch();
	_clrscr();
	inicializarRegistro(vecAlu);		//Cargo el arreglo por referencia
	inicializarRegistroCopia(vecAlu);	//Cargo el arreglo por copia
	listarRegistro(vecAlu);				//Muestro el arreglo, notese que la copia no se muestra
	return 0;
}
