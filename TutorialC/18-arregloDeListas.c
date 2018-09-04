/****************************************************************************
 *                                                                          *
 * Filename: 21-arregloDeListas.c                                           *
 *                                                                          *
 * Purpose : Ejemplo de arreglo de listas en Standard C.   					*
 *                                                                          *
 * History : Fecha                                                          *
 *           21-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//El arreglo de listas se define como cualquier otro arreglo: indicando el tamaño entre corchetes.
//Mediante un indice, podemos acceder a cada lista dentro del arreglo para trabajar individualmente.
//
//En esta primer parte, trabajaremos el arreglo de lista desde la aplicacion, enviando como parametro
//a los distintos modulos la direccion de memoria del i-esimo elemento del arreglo, de modo que cada
//modulo trabaja con una lista simple. Tendremos entonces la invocacion de los modulos dentro de un
//for por cada lista de nuestro arreglo.


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

void cargarProducto(struct Producto *p);					//Carga un producto con datos
void inicializarLista(struct Lista **l);					//Inicializa la i-esima lista enviada como parametro
void insertarOrdenado(struct Lista **l, struct Producto p);	//Inserta ordenado en la lista enviada como parametro
void cargarListaArreglo(struct Lista **l, int pos);			//Carga los datos en la lista dada. 'pos' es solo informativo
void mostrarLista(struct Lista **l, int pos);				//Muestra la i-esima lista enviada como parametro. 'pos es informativo

//--------------------

//MAIN-------------------------------------------------------------------------------------
int main(){
	int i;
	//Aclaracion: la variable "i" es enviada como segundo parametro solo para indicar el numero de
	//lista operando, no es bajo ningun concepto funcional necesario para la correcta ejecucion.
	struct Lista *arregloListas[5];
	for (i=0; i<5; i++){	//Inicializo cada lista en NIL
		inicializarLista(&arregloListas[i]);	//Notese como envio la i-esima lista
	}
	for (i=0; i<5; i++){	//Muestro cada lista vacia
		mostrarLista(&arregloListas[i], i);
	}
	for (i=0; i<5; i++){	//Cargo datos en cada
		cargarListaArreglo(&arregloListas[i], i);
	}
	_getch();
	for (i=0; i<5; i++){	//Muestro cada lista cargada
		mostrarLista(&arregloListas[i], i);
	}
}

//PROCEDIMIENTOS-----------------------------------------------------------------------

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

void inicializarLista(struct Lista **l){
	*l=0;
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

void cargarListaArreglo(struct Lista **l, int pos){
	char respuesta = 'S';
	struct Producto p;
	printf("Lista %d\n", pos);
	while(respuesta == 'S'){
		cargarProducto(&p);
		insertarOrdenado(l, p);
		getchar();
		printf("¿Desea cargar otro producto? S/N\n");
		scanf("%c", &respuesta);
		_clrscr();
	}
}

void mostrarLista(struct Lista **l, int pos){
	struct Lista *aux;
	if (*l == 0){
		printf("La lista %d esta vacia", pos);
		_getch();
	}
	else{
		aux= *l;
		printf("Datos de la lista %d\n-------\n", pos);
		while (aux != 0){
			printf("Codigo: %d\n", aux->dato.codigo);
			printf("Nombre: %s\n", aux->dato.nombre);
			printf("Stock: %d\n\n", aux->dato.stock);
			aux= aux->ps;
			_getch();
		}
	}
	_clrscr();
}
