/****************************************************************************
 *                                                                          *
 * Filename: 17-lista3.c                                                    *
 *                                                                          *
 * Purpose : Ejemplo avanzado de uso de listas en Standard C.               *
 *                                                                          *
 * History : Fecha                                                          *
 *           23-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//En este ejemplo se realizara una aplicacion completa empleando listas, para dar
//cierre a lo visto hasta ahora.
//
//Se plantea como ejercicio realizar una aplicacion que permita el abm de productos
//con su codigo, nombre y stock, y que permita consultas varias sobre los mismos.


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Producto{		//Defino Producto
	int codigo;
	char nombre[15];
	int stock;
};

struct Lista{			//Defino la lista
	struct Producto dato;
	struct Lista *ps;
};

//----Defino modulos prototipados
void cargarProducto(struct Producto *p, int codigo);			//Carga un producto con datos
void inicializarLista (struct Lista **l);						//Inicializa la lista en NIL
void insertarOrdenado(struct Lista **l, struct Producto p);		//Inserta de forma ordenada por codigo
void modificarProducto(struct Lista **l);						//Modifica un producto por codigo
void eliminarProducto (struct Lista **l);						//Elimina un producto por codigo
void listarProductos (struct Lista *l);							//Lista los productos cargados
void buscarProducto (struct Lista *l);							//Lista un producto especifico por codigo
int totalProductos (struct Lista *l);							//Retorna el total de productos cargados

int main(){
	int r, c;
	struct Lista *l;		//Declaro la lista
	struct Producto p;		//Declaro el producto que agrego a la lista
	inicializarLista(&l);	//Inicializo la lista
	do{
		printf("MENU PRINCIPAL\n");
		printf("---------------------\n");
		printf("1) Agregar producto\n");
		printf("2) Modificar producto\n");
		printf("3) Eliminar producto\n");
		printf("4) Listar productos\n");
		printf("5) Buscar producto\n");
		printf("6) Total de productos cargados\n\n");
		printf("0) Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &r);
		_clrscr();
		switch(r){
			case 1:
				c= -1;						//Control para saber si el producto existe o no
				cargarProducto(&p,c);		//Cargo el producto
				insertarOrdenado(&l, p);	//Lo inserto ordenado
				break;
			case 2:
				modificarProducto(&l);
				break;
			case 3:
				eliminarProducto(&l);
				break;
			case 4:
				listarProductos(l);
				break;
			case 5:
				buscarProducto(l);
				break;
			case 6:
				printf("El total de productos cargados es: %d", totalProductos(l));
				_getch();
				break;
			case 0: 
				printf("Terminando ejecucion");
				_getch();
				break;
			default:
				printf("Opcion incorrecta ingresada");
				_getch();
				break;
		}
		_clrscr();
	}while (r!=0);
	return 0;
}

void cargarProducto(struct Producto *p, int codigo){
	if (codigo == -1){	//Es la creacion de un producto
		printf("Ingrese codigo: ");
		scanf("%d", &p->codigo);
		_clrscr();
	}
	else{				//Es la modificacion de un producto ya existente. No modifico codigo
		p->codigo= codigo;
	}
	printf("Ingrese nombre: ");
	scanf("%s", p->nombre); //String, sin ampersand
	_clrscr();
	printf("Ingrese stock: ");
	scanf("%d", &p->stock);
	_clrscr();
}

void inicializarLista (struct Lista **l){
	*l=0;			//Lista en NIL
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

void modificarProducto(struct Lista **l){
	struct Lista *act;		//Defino mi auxiliar
	struct Producto p;		//Defino el producto a modificar
	int codigo;				//Codigo con el cual buscar el producto
	act=*l;
	if (*l!=0){				//La lista no esta vacia
		printf("Ingrese codigo de producto a modificar: ");
		scanf("%d", &codigo);
		_clrscr();
		while((act != 0) && (act->dato.codigo != codigo)){	//Busco el producto, si existe
			act=act->ps;
		}
		if (act == 0){		//El producto del codigo dado no existe
			printf("El producto de codigo %d no existe", codigo);
		}
		else{				//Encontro el producto, realiza modificacion
			printf("Ingresando nuevos datos del producto\n");
			cargarProducto(&p, codigo);
			act->dato= p;
			_clrscr();
			printf("Modificacion realizada con exito");
		}
	}
	else{
		printf("La lista esta vacia");
	}
	_getch();
	_clrscr();
}

void eliminarProducto(struct Lista **l){
	struct Lista *act;
	struct Lista *ant;
	int cod;
	if(*l!=0){					//La lista no esta vacia
		ant=0;
		act=*l;
		printf("Ingrese codigo del producto a eliminar: ");
		scanf("%d", &cod);
		_clrscr();
		while((act!=0) && (act->dato.codigo!=cod)){
			ant=act;
			act=act->ps;
		}
		if (act==0){			//El elemento no existe
			printf("El producto de codigo %d no existe", cod);
		}
		else if(ant==0){		//Es el primer elemento
			*l=act->ps;			//Muevo la cabeza de la lista
			free(act);			//Elimino el nodo actual
			printf("Eliminacion realizada con exito");
		}
		else{					//Es un elemento intermedio o final
			ant->ps=act->ps;	//Reacomodo el ps de anterior
			free(act);			//Elimino el nodo actual
			printf("Eliminacion realizada con exito");
		}
	}
	else{
		printf("La lista esta vacia");
	}
	_getch();
	_clrscr();
}

void listarProductos(struct Lista *l){
	int i=1;
	if(l==0){
		printf("La lista esta vacia");
		_getch();
	}
	else{		//Si la lista no esta vacia, recorro cada producto
		while(l!=0){
			printf("Producto numero: %d\n", i);
			printf("Codigo:    %d\n", l->dato.codigo);
			printf("Nombre:    %s\n", l->dato.nombre);
			printf("Stock:     %d\n", l->dato.stock);
			printf("-------------------\n");
			_getch();
			l=l->ps;
			i++;
		}
	}
	_clrscr();
}

void buscarProducto(struct Lista *l){
	int cod;
	if(l==0){
		printf("La lista esta vacia");
		_getch();
	}
	else{
		printf("Ingrese codigo del producto: ");
		scanf("%d", &cod);
		_clrscr();
		while((l!=0) && (l->dato.codigo != cod)){
			l=l->ps;
		}
		if(l==0){	//Si es NIL, no encontro un producto de codigo cod
			printf("El producto de codigo %d no existe", cod);
		}
		else{		//Encontro el producto, lista sus datos
			printf("Datos del producto:\n");
			printf("--------------------\n");
			printf("Codigo:    %d\n", l->dato.codigo);
			printf("Nombre:    %s\n", l->dato.nombre);
			printf("Stock:     %d\n", l->dato.stock);
		}
		_getch();
	}
	_clrscr();
}

int totalProductos(struct Lista *l){
	int contador=0;		//Inicializo contador en 0
	if (l!=0){			
		while (l!=0){
			l=l->ps;
			contador++;	//Incremento por cada elemeneto nuevo que encuentra
		}
	}
	return contador;	//Retorno el total de productos de la lista (0 si no hay productos)
}
