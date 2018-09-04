/****************************************************************************
 *                                                                          *
 * Filename: 22-arregloDeListas2.c                                          *
 *                                                                          *
 * Purpose : Ejemplo de arreglo de listas en Standard C.   			    	*
 *                                                                          *
 * History : Fecha                                                          *
 *           21-05-2018                                                     *
 *																    		*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Segunda parte del ejemplo de arreglo de listas. En el ejemplo anterior, enviamos la dirección de
//memoria del i-esimo elemento del arreglo a los distintos modulos, mediante un for. En este ejemplo,
//enviaremos directamente el arreglo, y que cada modulo procese cada lista dentro del mismo.


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
void cargarProducto(struct Producto *p);							//Carga un producto con datos
void inicializarListas(struct Lista **arreglo);					//Inicializa cada lista del arreglo de listas
void insertarOrdenado(struct Lista **lista, struct Producto p);	//Inserta ordenado en la lista
void cargarListaArreglo(struct Lista **arreglo);					//Carga los datos en cada lista del arreglo
void mostrarLista(struct Lista **arreglo);						//Muestra cada una de las listas del arreglo

//--------------------

int main(){
	struct Lista *arregloListas[5];		//Defino el arreglo
	inicializarListas(arregloListas);	//Invoco la funcion que lo inicializa
	mostrarLista(arregloListas);		//Invoco la funcion que lo muestra (vacia)
	cargarListaArreglo(arregloListas);	//Invoco la funcion que lo carga con datos
	mostrarLista(arregloListas);		//Invoco la funcion que lo muestra (ahora cargado)
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

void inicializarListas(struct Lista **arreglo){	//Recibe como parametro el arreglo
	for (int j=0; j<5; j++){	//Itera por cada lista del arreglo
		arreglo[j]= 0;		//La inicializa
	}
}

void insertarOrdenado(struct Lista **lista, struct Producto p){
	struct Lista *nuevo=malloc(sizeof(struct Lista));	//Defino el nuevo nodo
	struct Lista *ant;	//Defino el nodo anterior
	struct Lista *act;	//Defino el nodo actual
	nuevo->dato=p;		//Cargo producto en nuevo
	nuevo->ps=0;			//Inicializo ps de nuevo en NIL
	if (*lista==0){		//La lista esta vacia, no hace falta moverme
		*lista=nuevo;
	}
	else{				//La lista no esta vacia, busco el punto de insercion
		ant=0;			//Puntero al nodo anterior
		act=*lista;		//Puntero al nodo actual
		while ((act!=0) && (act->dato.codigo < nuevo->dato.codigo)){
			ant=act;
			act=act->ps;
		}
		if (ant==0){		//Si ant es NIL, inserto al principio
			nuevo->ps= act;
			*lista=nuevo;
		}
		else{			//Debo insertar en el medio de dos nodos
			nuevo->ps=act;
			ant->ps=nuevo;
		}
	}
}

void cargarListaArreglo(struct Lista **arreglo){
	char respuesta;
	struct Producto p;
	for (int j=0; j<5; j++){	//Itero por cada lista del arreglo
		printf("Lista %d\n", j+1);
		respuesta= 'S';
		while( (respuesta != 'N') && (respuesta != 'n') ){
			cargarProducto(&p);	//Cargo un producto
			insertarOrdenado(&arreglo[j], p);	//Lo inserto en la lista que estoy trabajando
			getchar();
			printf("¿Desea cargar otro producto? S/N\n");
			scanf("%c", &respuesta);
			_clrscr();
		}
	}
}

void mostrarLista(struct Lista **arreglo){
	struct Lista *act;
	for (int j=0; j<5; j++){	//Itero por cada lista
		act= arreglo[j];		//Genero un actual con la lista que estoy trabajando
		printf("Datos de lista %d\n", j+1);
		while (act != 0){		//Mientras el actual no sea nil, itero
			printf("Codigo: %d\n", act->dato.codigo);
			printf("Nombre: %s\n", act->dato.nombre);
			printf("Stock: %d\n", act->dato.stock);
			act= act->ps;
		}
		_getch();
		_clrscr();
	}
}	
