/****************************************************************************
 *                                                                          *
 * Filename: 15-lista.c                                                     *
 *                                                                          *
 * Purpose : Ejemplo de uso de listas simples en Standard C.                *
 *                                                                          *
 * History : Fecha                                                          *
 *           23-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Las listas en C son muy similares a las ya vistas en pseudocodigo o Pascal, ya
//que son un registro con los datos del mismo y un campo extra que es el puntero
//al nodo siguiente.
//
//A diferencia de Pascal, en C no declararemos por separado un nodo registro y un
//puntero al mismo, sino que declaramos el registro tipo nodo y dentro directamente
//declaramos el puntero siguiente que sera el que usaremos para acceder.
//
//Para trabajar con listas, necesitaremos una nueva libreria, <stdlib.h>, la cual
//nos dara funciones para operar en la memoria del sistema.
//De esas funciones, por ahora, usaremos:
//
//	malloc() --> 	Memory Allocation, reserva la cantidad de bytes especificados como
//					parametro en la memoria RAM para almacenar el nodo.
//
//	free() -->		Libera el espacio previamente alojado con malloc.
//
//Tambien a tener en cuenta: la manera de acceder a un campo del nodo de la lista es
//con "->".

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>	//La nueva libreria.

struct nodo{				//Nodo de la lista.
	int numero;
	struct nodo *siguiente;	//Definicion del puntero a la lista.
};

int i;

int main(){
	struct nodo *L;		//Creo mi puntero a la lista L
	struct nodo *aux;	//Este sera el aux para recorrerla, lo veremos mas abajo 	.
	L=(struct nodo *) malloc(sizeof(struct nodo)); //IMPORTANTE: creo un nuevo nodo en la lista L reservando el espacio para el mismo con malloc.
	L->siguiente=0;	//Pongo en NULL (0 en C) el puntero siguiente del nodo
	L->numero=5;	//Pongo valor 5 en el campo numero del nodo
	//
	//Hasta ahora, se creo un nodo de la lista, ahora se vera como agregar mas nodos y recorrerlos usando un
	//puntero conductor o auxiliar
	//
	aux=L;
    if (aux!=0){
        while(aux->siguiente!= 0){	//Repetimos mientras el aux no sea NIL
            aux=aux->siguiente;		//Nos movemos por la lista
        }
    }
    //Creamos un nodo al final de la lista
    aux->siguiente = malloc( sizeof(struct nodo) );  

    aux = aux->siguiente; 

    if (aux==0){
        printf( "Sin memoria" );
		_getch();
        return 0;		//Caera aca si no habia memoria para el registro
    }
    //Inicializamos el nuevo nodo
    aux->siguiente = 0;         
    aux->numero = 42;
    //
	//Hasta ahora creamos una lista con dos nodos cargados. Ahora
	//recorreremos la lista y mostraremos sus datos
	//
	aux=L;
	i=1;
	printf("Mostrando datos cargados en la lista");
	_getch();
	_clrscr();
	while(aux!=0){
		printf("Nodo: %d\n", i);
		printf("Numero en nodo: %d\n", aux->numero);
		printf("\n");
		_getch();
		aux=aux->siguiente;
		i++;
	}
	return 0;
}
