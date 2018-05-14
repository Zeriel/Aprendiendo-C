/****************************************************************************
 *                                                                          *
 * Filename: tp5Modularizacion.c                                            *
 *                                                                          *
 * Purpose : Ejercicios del TP5 de algoritmos en Standard C.                *
 *                                                                          *
 * History : Fecha                                                          *
 *           22-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//No encontre un buen ejercicio para ejemplificar un uso extensivo de procedimientos
//y funciones dentro de la practica 5, por lo que voy a utilizar la base del ejercicio
//visto en tp4Registro.c para armar un enunciado completo.

//El enunciado a resolver entonces sera:

//"Desarrollar un algoritmo que permita cargar las habitaciones de un hotel (5 para fines practicos)
//las cuales posee: numero de habitacion (utilizaremos el indice del arreglo), capacidad (2, 4 o 6),
//tipo (estandar, confort, premium), precio y estado (disponible/ocupado)

//El programa debera permitir:
//		1) Asignar habitaciones disponibles.
//		2) Facturar habitaciones ocupadas. 
//		3) Listar habitaciones disponibles.

//Sera obligatorio el uso de un menu principal y la aplicacion de modularizacion."

//No se explicaran extensivamente cosas ya mencionadas en el ejercicio teorico respecto a 
//funciones de C, por lo que se recomienda repasarlo si no se tiene claro el manejo de
//parametros en C.


#include<stdio.h>
#include<conio.h>
#include<string.h>

//DEFINICION DEL TIPO REGISTRO

struct Habitacion{					
	int capacidad;
	char tipo[8];
	float precio;
	char estado;
};

//DECLARACION DE PROCEDIMIENTOS Y FUNCIONES

void cargaInicial(struct Habitacion hotel[5]){
	printf("Carga inicial de datos del hotel");
	_getch();
	_clrscr();
	for (int i=0; i<5; i++){
		printf("Habitacion: %d\n", i+1);
		printf("Ingrese capacidad: ");
		scanf("%d", &hotel[i].capacidad);
		_clrscr();
		printf("Ingrese tipo: ");
		scanf("%s", hotel[i].tipo);		//Recordar que los strings no llevan ampersand (&)
		_clrscr();
		printf("Ingrese precio: ");
		scanf("%f", &hotel[i].precio);
		hotel[i].estado='D';
		_clrscr();
	}
}

int hayDesocupado(struct Habitacion hotel[5]){	//Funcion que devuelve TRUE (0) si no existen habitaciones disponibles 
	struct Habitacion h2[5];				//o FALSE (!0) caso contrario
	int i, contador=0;
	for (i=0; i<5; i++){					//Pasaje "por copia". Ver procedimiento "listar" para mas detalle							
		h2[i]=hotel[i];
	}
	for (i=0; i<5; i++){
		if (h2[i].estado=='O'){
			contador++;
		}
	}
	if (contador==5){
		return 0;
	}
	else{
		return 1;
	}
}

void asignar(struct Habitacion hotel[5]){
	int cap, i;
	char tipo[10];

	if(hayDesocupado(hotel)){
		printf("Ingrese capacidad de habitacion a buscar: ");
		scanf("%d", &cap);
		_clrscr();
		printf("Ingrese tipo de habitacion: ");
		scanf("%s", tipo);
		_clrscr();
		i=0;
		while ((i<5) && ((hotel[i].capacidad!=cap) || (strcmp(hotel[i].tipo, tipo)!=0) || (hotel[i].estado!='D'))){
			i++;		//Recorro el hotel y busco la habitacion con las caracteristicas que solicicte, si no lo encuentra
		}				//saldra con un indice i mayor al tamaño del array, con lo que sabre que no encontro habitacion
		if (i==5){
			printf("No se encontro habitacion disponible con esas caracteristicas");
		}
		else{
			hotel[i].estado='O';	//Encontro habitacion, por lo que la pondre en estado "OCUPADO"
			printf("Habitacion asignada: %d", i+1);
		}
	}
	else{
		printf("No hay habitaciones disponibles");
	}
	_getch();
	_clrscr();
}

void facturar(struct Habitacion hotel[5]){
	int i, dias;

	printf("Ingrese habitacion a facturar: ");
	scanf("%d", &i);
	i--;		//El usuario elegira una opcion de 1-5, pero el arreglo va de 0-4, asique lo corregimos con este decremento
	if (i>=0 && i<5){
		if (hotel[i].estado=='D'){	//Evaluo que la habitacion este ocupada, ya que no puedo facturar una habitacion disponible
			printf("La habitacion no esta ocupada. No puede facturarse");
		}
		else{
			printf("Ingrese dias que estuvo de estadia: ");
			scanf("%d", &dias);
			_clrscr();
			printf("Debe abonar un monto de $..............%.2f", dias*hotel[i].precio);
			hotel[i].estado='D';	//Como facture la habitacion, la vuelvo a poner disponible
		}
	}
	else{
		printf("La habitacion ingresada no existe");
	}
	_getch();
	_clrscr();
}

void listar(struct Habitacion hotel[5]){ //Como no necesito modificar el array, lo pasare por copia (ver comentario siguiente)
	struct Habitacion h2[5];
	int i;
	for (i=0; i<5; i++){
		h2[i]=hotel[i];		//En C los arrays no pueden pasarse por copia, por lo que duplico el array para forzar una "copia"
	}
	if(hayDesocupado(h2)){		//Invoco la funcion booleana en la comparacion. Recordar bool en C: 0-FALSE, 1 u otro valor-TRUE 
		for (i=0; i<5; i++){
			if(h2[i].estado=='D'){
				printf("Habitacion: %d\n", i+1);
				printf("Capacidad: %d\n", h2[i].capacidad);
				printf("Tipo: %s\n", h2[i].tipo);
				printf("Precio por dia: %.2f\n", h2[i].precio);
				printf("-----------------------\n");
				printf("\n");
				_getch();
			}
		}
	}
	else{
		printf("No hay habitaciones disponibles");
		_getch();
	}
	_clrscr();
}

//VARIABLES GLOBALES
int resp;
struct Habitacion hot[5];

//MAIN
int main(){
	cargaInicial(hot);
	resp=9;
	while (resp!=0){
		printf("MENU PRINCIPAL: ADMINISTACION DE HOTEL\n");
		printf("--------------------------------------\n");
		printf("\n");
		printf("1) Asignar habitacion\n");
		printf("2) Facturar habitacion\n");
		printf("3) Listar habitaciones disponibles\n");
		printf("\n");
		printf("0) Salir\n");
		printf("\n");
		printf("\n");
		printf("Elija una opcion: ");
		scanf("%d", &resp);
		_clrscr();
		switch(resp){
			case 1:
				asignar(hot);
				break;
			case 2:
				facturar(hot);
				break;
			case 3:
				listar(hot);
				break;
			case 0:
				printf("Terminando ejecucion");
				_getch();
				break;
			default:
				printf("Ingreso una opcion incorrecta");
				_getch();
				break;
		}
		_clrscr();
	}
}
