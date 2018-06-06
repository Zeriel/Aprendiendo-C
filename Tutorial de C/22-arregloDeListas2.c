/****************************************************************************
 *                                                                          *
 * Filename: 22-arregloDeListas2.c                                          *
 *                                                                          *
 * Purpose : Ejemplo de arreglo de listas en Standard C.   					*
 *                                                                          *
 * History : Fecha                                                          *
 *           21-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/




#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Producto{
	int codigo;
	char nombre[15];
	int stock;
};

struct Lista{
	struct Producto dato;
	struct Lista *ps;
};

//Procedimientos -----

void cargarProducto(struct Producto *p);		//Carga un producto con datos
void inicializarListas(struct Lista **l);		//Inicializa cada lista del arreglo de listas
void insertarOrdenado(struct Lista **l, struct Producto p);	//Inserta ordenado en la lista
void cargarListaArreglo(struct Lista **l, int posicion);					//Carga los datos en la lista dada
void mostrarLista(struct Lista **l, int posicion);		//Muestra cada una de las listas del arreglo

//--------------------

int main(){
	int i;
	struct Lista *L[5];
	for (i=0; i<5; i++){
		//inicializarListas(&L[i]);
		L[i]=0;
	}
	for (i=0; i<5; i++){
		cargarListaArreglo(L, i);
	}
	for (i=0; i<5; i++){
		mostrarLista(L, i);
	}
}

void cargarProducto(struct Producto *p){
	printf("Ingrese codigo: ");
	scanf("%d", &p->codigo);
	_clrscr();
	printf("Ingrese nombre: ");
	scanf("%s", p->nombre); //String, sin ampersand
	_clrscr();
	printf("Ingrese stock: ");
	scanf("%d", &p->stock);
	_clrscr();
}

void inicializarListas(struct Lista **l){
	l=0;
}

void insertarOrdenado(struct Lista **l, struct Producto p){
	struct Lista *nuevo=malloc(sizeof(struct Lista));	//Defino el nuevo nodo
	struct Lista *ant;	//Defino el nodo anterior
	struct Lista *act;	//Defino el nodo actual
	nuevo->dato=p;		//Cargo producto en nuevo
	nuevo->ps=0;		//Inicializo ps de nuevo en NIL
	if (*l==0){			//La lista esta vacia, no hace falta moverme
		*l=nuevo;
	}
	else{				//La lista no esta vacia, busco el punto de insercion
		ant=0;			//Puntero al nodo anterior
		act=*l;			//Puntero al nodo actual
		while ((act!=0) && (act->dato.codigo < nuevo->dato.codigo)){
			ant=act;
			act=act->ps;
		}
		if (ant==0){	//Si ant es NIL, inserto al principio
			nuevo->ps= act;
			*l=nuevo;
		}
		else{			//Debo insertar en el medio de dos nodos
			nuevo->ps=act;
			ant->ps=nuevo;
		}
	}
}

void cargarListaArreglo(struct Lista **l, int posicion){
	char respuesta;
	struct Producto p;
	for (int j=0; j<5; j++){
		printf("Lista %d\n", j+1);
		respuesta= 'S';
		while(respuesta != 'N'){
			cargarProducto(&p);
			insertarOrdenado(&l[j], p);
			getchar();
			printf("¿Desea cargar otro producto? S/N\n");
			scanf("%c", &respuesta);
			_clrscr();
		}
	}
}

void mostrarLista(struct Lista **l, int pos){
	printf("Datos de lista %d\n", pos);
	while (l[pos] != 0){
		printf("Codigo: %d", l[pos]->dato.codigo);
		printf("Nombre: %s", l[pos]->dato.nombre);
		printf("Stock: %d", l[pos]->dato.stock);
	}
}	
