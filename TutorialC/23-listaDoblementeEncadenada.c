/****************************************************************************
 *                                                                          *
 * Filename: 23-listaDoblementeEncadenada.c                                 *
 *                                                                          *
 * Purpose : Ejemplo de listas de doble enlace en Standard C.   			*
 *                                                                          *
 * History : Fecha                                                          *
 *           21-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Las listas doblemente encadeandas son iguales a las ya vistas, con la diferencia que
//tendremos, además del puntero siguiente, un puntero anterior que apunta justamente
//al nodo anterior al actual.
//
//Se vera el ejemplo de 17-lista3.c resuelto con listas doblemente encadenadas.

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
	struct Lista *pant;	//Puntero anterior
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
	struct Lista *aux;	//Defino un auxiliar
	struct Lista *act;	//Defino el nodo actual
	nuevo->dato=p;		//Cargo producto en nuevo
	act= *l;
	while ( (act != 0) && (act->dato.codigo < nuevo->dato.codigo) ){
		act= act->ps;
	}
	if ( (*l == 0) || (act->pant == 0) ){	//Inserto al principio
		nuevo->pant= 0;				//Anterior de nuevo es nil
		nuevo->ps= *l;				//Siguiente de nuevo es L
		*l= nuevo;					//L es nuevo
	}
	else{									//Inserto en el cuerpo
		//Para entender: nuevo se encuentra en medio de actual y auxiliar
		nuevo->ps= act;				//Nuevo apunta a actual, el nodo que le sigue
		aux= act->pant;				//Defino auxiliar como el nodo anterior a actual, para no perderlo
		act->pant= nuevo;			//Piso anterior a actual, redefiniendolo con nuevo
		aux->ps= nuevo;				//El anterior a actual ahora apunta a nuevo
		nuevo->pant= aux;			//El anterior de nuevo apunta al que era anterior a actual
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
	struct Lista *aux;			//Lo usare solo al final
	struct Lista *sig;
	int cod;
	if(*l!=0){					//La lista no esta vacia
		printf("Ingrese codigo del producto a eliminar: ");
		scanf("%d", &cod);
		_clrscr();
		act=*l;
		while( (act!=0) && (act->dato.codigo!=cod) ){
			act=act->ps;
		}
		if (act!=0){			//El elemento existe
			if(act->pant==0){		//Es el primer elemento
				*l=(*l)->ps;			//Muevo la cabeza de la lista
				if (*l != 0){		//Si la cabeza no es nil, hago anterior nil
					(*l)->pant= 0;	//(anterior es el que estoy borrando, y es el primer elemento)
				}
			}
			else{					//Es un elemento intermedio o final
				aux= act->pant;		//Almaceno el anterior al que voy a borrar, para no perderlo
				aux->ps= act->ps;	//Enlazo el anterior y el siguiente a actual, dejandolo fuera de la lista
				if (act->ps != 0){	//Si actual no es el ultimo nodo, enlazo el siguiente con el anterior, dejandolo fuera de la lista
					sig= act->ps;	//Sig lo igualo al nodo que le sigue a actual
					sig->pant= aux;	//Enlazo el que le sigue a actual con el que tiene atras
				}
			}
			free(act);			//Elimino el nodo actual
			printf("Eliminacion realizada con exito");
		}
		else{
			printf("El producto de codigo %d no existe", cod);
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
