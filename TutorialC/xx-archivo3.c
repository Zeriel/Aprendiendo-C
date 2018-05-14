/****************************************************************************
 *                                                                          *
 * Filename: archivo3.c                                                     *
 *                                                                          *
 * Purpose : Ejemplo final de archivos en Standard C.                       *
 *                                                                          *
 * History : Fecha                                                          *
 *           13-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Para este ejercicio final, volveremos a utilizar el codigo visto en 17-lista3.c, pero le agregaremos
//un archivo para que los datos persistan en el tiempo.

//Aclaraciones: haremos uso de herramientas que no usamos antes, dada la complejidad de este ejercicio:
//	-fseek (archivo, 0, SEEK_END);	//Me posiciono al final del archivo
//	-tamanio = ftell(archivo);		//Obtengo el tamaño en bytes del archivo
//
//La operatoria anterior sirve para saber si un archivo esta vacio. el fseek nos posiciona al final del archivo, y
//luego ftell nos dice el tamaño en bytes desde el origen del archivo hasta la posicion actual del indice del msimo
//(que es el final del archivo gracias al fseek anterior). Si tamanio es igual a 0, quiere decir que el tamaño
//del archivo es 0 bytes, osea que no esta cargado con ningun dato.
//
//Salvo que cerremos el archivo inmediatamente tras hacer esta operatoria, nuestro indice permanecera en el final
//del archivo, por lo que habra que posicionarlo nuevamente al inicio, mediante:
//
//	-fseek(archivo, 0, 0);

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

//----Nuevas funciones, para operar el archivo
void subirArchivo (struct Lista *l);	//Sube los contenidos de "l" al archivo (pisando los viejos)
void bajarArchivo (struct Lista **l);	//Baja los contenidos del archivo a "l" (pisando los viejos)

FILE *archivo;	//Defino mi archivo

int main(){
	int r, c;
	char respuestaArch;
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
		printf("6) Total de productos cargados\n");
		printf("7) Actualizar archivo con nuevos datos\n");
		printf("8) Cargar datos del archivo localmente\n\n");
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
			case 7:
				printf("Esta tarea reescribira el archivo. ¿Desea continuar? S/N\n");
				getchar();	//Se estaba capturando el caracter ingresado en el menu, con esto lo soluciono
				scanf("%c", &respuestaArch);
				if ((respuestaArch == 's') || (respuestaArch == 'S')){
					_clrscr();
					subirArchivo (l);
				}
				break;
			case 8:
				printf("Esta tarea reescribira la lista local. ¿Desea continuar? S/N\n");
				getchar();	//Se estaba capturando el caracter ingresado en el menu, con esto lo soluciono
				scanf("%c", &respuestaArch);
				if ((respuestaArch == 's') || (respuestaArch == 'S')){
					_clrscr();
					bajarArchivo (&l);
				}
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

//---Funciones de Archivo-------------------------------------------

void subirArchivo (struct Lista *l){
	archivo = fopen("archivos/ejemplo3.dat", "w");
	if (l == 0){
		printf("La lista esta vacia, no hay datos que cargar");
	}
	else{

		while (l!=0){	//l esta pasado por copia, no necesito declarar auxiliares
			fwrite(&l->dato, sizeof(struct Producto), 1, archivo);	//En lugar de crear un producto auxiliar, uso el ->dato
			l=l->ps;
		}
		if (fwrite != 0){	//Valido operacion de I/O
			printf("Los datos se han almacenado de forma correcta");
		}
		else{
			printf("ERROR - Hubo un error en el archivo al intentar guardar los datos");
		}
	}
	fclose(archivo);
	_getch();
}

void bajarArchivo (struct Lista **l){
	int tamanio;
	struct Producto p;
	archivo = fopen("archivos/ejemplo3.dat", "r");
	if (archivo == NULL){
		printf("Error - El archivo no existe o no pudo abrirse");
	}
	else{
		fseek (archivo, 0, SEEK_END);	//Me posiciono al final del archivo
		tamanio = ftell(archivo);		//Obtengo el tamaño en bytes del archivo

		if (tamanio == 0) {				//Tamaño 0, el archivo esta vacio
		    printf("El archivo esta vacio\n");
		}
			else{
			*l=0;
			fseek(archivo, 0, 0);		//Posiciono el indice del archivo en el inicio del mismo
			while(fread(&p, sizeof(struct Producto), 1, archivo)){
				insertarOrdenado(l, p);
				//IMPORTANTE: Estoy enviado l sin ningun *, por lo que es un puntero de puntero, de modo que
				//sea entendido por insertarOrdenado, el cual espera un puntero de lista
			}
			printf("La lista local se ha actualizado de forma correcta");
		}

		fclose(archivo);
	}
	_getch();
}
