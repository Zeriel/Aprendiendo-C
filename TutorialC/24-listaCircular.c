/****************************************************************************
 *                                                                          *
 * Filename: 24-listaCircukar.c 			                                *
 *                                                                          *
 * Purpose : Ejemplo de listas circulares en Standard C.		   			*
 *                                                                          *
 * History : Fecha                                                          *
 *           01-06-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Las listas circulares se caracterizan por tener el ultimo nodo apuntando al
//primero. Mas alla de esta particularidad, se trabajan de la misma forma que
//cualquier lista simple.

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
