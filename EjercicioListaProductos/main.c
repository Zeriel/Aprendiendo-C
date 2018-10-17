/****************************************************************************
 *                                                                          *
 * Filename: main.c                                                			*
 *                                                                          *
 * Purpose : Ejercicio de practica para la cursada de Algoritmos.           *
 *                                                                          *
 * History : Fecha                                                          *
 *           16-10-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Ejercicio dado a resolver a los alumnos en la clase del dia miercoles 17/10/2018. Esta es la resolucion
//provista desde la catedra, a modo de ejemplo.
//
//Enunciado:
//Diseñar un algoritmo que permita cargar y modificar una lista de Productos. Un producto se compone por
//	- Nombre
//	- Proveedor
//	- Codigo
//	- Precio unitario
//
//El ejercicio consiste en cargar una lista, luego eliminar un producto dado y modificar otro (ambos metodos
//por codigo), y, finalmente, mostrar la lista con los cambios aplicados. Como detalle extra, se mostrara
//la cantidad numerica de productos cargados.

//--LIBRERIAS------------------
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//--ESTRUCTURAS----------------
struct Producto{
	char nombre[15];
	char proveedor[15];
	char codigo[10];
	float precioU;
};

struct Lista{
	struct Producto dato;
	struct Lista *ps;
};

//--MODULOS PROTOTIPADOS-------
void cargarProducto(struct Producto *prod);
void insertarInicio(struct Producto prod, struct Lista **l);	//Doble asterisco, referencia
void listar(struct Lista *l);									//Simple asterisco, copia
void modificar(struct Lista **l);
void eliminar(struct Lista **l);
int cantidadProductos(struct Lista *l);							//Funcion entera, retorna la cantidad

//--MAIN-----------------------
int main(){
	struct Lista *L=0;
	struct Producto p;
	char r='s';
	_clrscr();
	printf("EJERCICIO DE MUESTRA\n--------------------\nPresione una tecla para iniciar...");
	_clrscr();
	//Inicia carga de producto
	while ( (r=='s') || (r=='S') ){
		cargarProducto(&p);		//Ampersand
		insertarInicio(p, &L);
		getchar();
		printf("?Desea cargar otro producto? S/N... ");
		scanf("%c", &r);
		_clrscr();
	}
	//Finaliza carga
	//---
	//Inician puntos del ejercicio:
	listar(L);
	printf("Invocacion del metodo eliminar\n\n");
	eliminar(&L);
	printf("Invocacion del metodo modificar\n\n");
	modificar(&L);
	listar(L);
	printf("La cantidad de productos actualmente cargados es: %d productos", cantidadProductos(L));
	_getch();
	_clrscr();
	printf("Ejecucion terminada, cerrando aplicacion en la siguiente interaccion");
	_getch();
	_clrscr();
	return 0;
}

//--MODULOS DEFINIDOS----------
void cargarProducto(struct Producto *prod){
	printf("Iniciando carga de un producto....\n");
	printf("--------\n Ingrese nombre: ");
	scanf("%s", prod->nombre);		//Es un string, no uso ampersand.
	printf("\n Ingrese proveedor: ");
	scanf("%s", prod->proveedor);
	printf("\n Ingrese codigo: ");
	scanf("%s", prod->codigo);	
	printf("\n Ingrese precio unitario: ");
	scanf("%f", &prod->precioU);	//Uso ampersand, no es string.
	_clrscr();
}

void insertarInicio(struct Producto prod, struct Lista **l){
	struct Lista *nuevo= malloc(sizeof(struct Lista));	//Creo nuevo nodo
	nuevo->dato= prod;									//Cargo el dato
	nuevo->ps= *l;										//Siguiente es la lista
	*l= nuevo;											//La lista es nuevo
}

void listar(struct Lista *l){
	int i=1;
	if ( l==0 ){
		printf("La lista esta vacia");
		_getch();
	}
	else{
		printf("LISTANDO PRODUCTOS\n-------------------\n\n");
		while ( l!=0 ){
			printf("PRODUCTO %d \n", i);
			printf(" - Nombre:     %s\n", l->dato.nombre);
			printf(" - Proveedor:  %s\n", l->dato.proveedor);
			printf(" - Codigo:     %s\n", l->dato.codigo);
			printf(" - Precio unitario: %.2f\n", l->dato.precioU);
			printf("----------------------------\n");
			_getch();
			l=l->ps;	//Puedo moverme por lista porque es una copia de L, no esta referenciada.
			i++;
		}
	}
	_clrscr();
}	
							
void modificar(struct Lista **l){
	char codigo[10];

	struct Lista *act;		//Creo un actual para moverme por la lista L.
	if (*l==0){				//Control para no pedir datos de forma innecesaria.
		printf("No hay productos cargados");
	}
	else{
		act=*l;				//Asigno a actual la direccion de L.
		printf("Ingrese codigo: ");
		scanf("%s", codigo);
		_clrscr();
		while (act!=0 && strcmp(act->dato.codigo,codigo)!=0){ //Evaluo no llegar al final de la lista o encontrar el codigo.
			act=act->ps;	//Me muevo por la lista.
		}
		if (act==0){
			printf("El producto: %s no existe", codigo);
		}
		else{	//Si la lista no es NIL, encontre el codigo ingresado y procedo a modificar sus datos.
			printf("Ingrese nuevo nombre: ");
			scanf("%s", act->dato.nombre);
			_clrscr();
			printf("Ingrese nuevo proveedor: ");
			scanf("%s", act->dato.proveedor);
			_clrscr();
			printf("Ingrese nuevo codigo: ");
			scanf("%s", act->dato.codigo);
			_clrscr();
			printf("Ingrese nuevo precio unitario: ");
			scanf("%f", &act->dato.precioU);
			_clrscr();
			printf("Cambio de datos exitoso");
		}
	}
	_getch();
	_clrscr();
}

void eliminar(struct Lista **l){
	char codigo[10];

	struct Lista *act;	//Defino un actual para moverme por L.
	struct Lista *ant;	//Defino un anterior para poder hacer el enlace si elimino.
	if (*l==0){
		printf("No hay productos cargados");
	}
	else{
		ant=0;			//Anterior debe ser NIL.
		act=*l;			//Actual debe ser L.
		printf("Ingrese codigo: ");
		scanf("%s", codigo);
		_clrscr();
		while (act!=0 && strcmp(act->dato.codigo,codigo)!=0){ //Mientras no llegue al final de la lista o no encuentre el codigo.
			ant=act;	//Anterior se mueve a Actual.
			act=act->ps;	//Actual se mueve a su nodo siguiente.
		}
		if (act==0){	//Si acutal tiene valor NILL, es porque llego al final de la lista y no encontro el codigo.
			printf("No se encontro el producto");
		}
		else{
			if (ant!=0){//Si anterior no es NILL, quiere decir que no estamos eliminando el primer elemento.
				ant->ps=act->ps;
			}
			else{		//Si anterior si era NILL, debemos eliminar el primer elemento corriendo la lista L.
				*l=act->ps;
			}
			free(act);	//Liberamos el espacio en memoria ocupado por el nodo que ya sacamos de la lista.
			printf("Producto: %s eliminado", codigo);
		}
	}
	_getch();
	_clrscr();
}

int cantidadProductos(struct Lista *l){
	int i=0;		//Si nunca entra al while, retorna cero.
	while( l!=0 ){	//Mientras no este vacia la lista.
		i++;		//Cuento un producto.
		l= l->ps;	//Muevo la lista.
	}
	return i;
}
