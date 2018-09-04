/****************************************************************************
 *                                                                          *
 * Filename: 19-pila.c 			                                            *
 *                                                                          *
 * Purpose : Ejemplo de uso de listas tipo pila en Standard C.              *
 *                                                                          *
 * History : Fecha                                                          *
 *           18-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//En este ejercicio veremos como operar una lista bajo el modo de acceso LIFO, es decir,
//una pila.
//
//Sera un ejemplo muy similar a los anteriores vistos, exceptuando que el manejo de puntero
//lo realizaremos mediante las funcionse predefinidas en la pila, a saber:
//
//	- Apilar		-> Inserta un elemento al principio de la pila.
//	- Desapilar		-> Desapila el primer elemento de la pila.
// 	- Es vacía		-> Retorna TRUE si la pila tiene elementos, FALSE caso contrario.
//	- Copiar pila	-> Genera una copia de la pila de trabajo.
//
//Como dato para la pila, usaremos un registro "libro" con sus respectivos datos.
//
//El objetivo de este ejemplo es realizar un ABM con menu de opciones para poder aplicar todas
//las funciones de pila.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Libro{			//El libro que almacena la pila
	int isbn;
	char titulo[20];
	char genero[15];
	char autor[15];
	float precio;
};

struct Pila{			//Definicion de pila
	struct Libro dato;
	struct Pila *ps;
};

//Operaciones de pila
void inicializarPila(struct Pila **p);
void apilar(struct Pila **p, struct Libro l);
void desapilar(struct Pila **p, struct Libro *l);
int esVacia(struct Pila *p);
void copiarPila(struct Pila **pila1, struct Pila **pila2);

//void obtenerlibro(struct Pila *p, struct Libro *l);
//Lo use para obtener el libro de la pila de forma remota

//Operaciones del programa
void cargarLibro(struct Libro *l);
void agregarLibro(struct Pila **p);
void mostrarLibros(struct Pila **p);
void modificarLibro(struct Pila **p);
void eliminarLibro(struct Pila **p);

int main(){
	struct Pila *p;			//La pila de trabajo
	struct Pila *copia;		//La copia de la pila de trabajo
	int r;					//Respuesta para el menu
	inicializarPila(&p);
	inicializarPila(&copia);
	do{
		printf("MENU PRINCIPAL\n");
		printf("----------------\n");
		printf("1) Agregar libro\n");
		printf("2) Mostrar libros\n");
		printf("3) Modificar libro\n");
		printf("4) Eliminar libro\n");
		printf("5) Generar copia de pila\n");
		printf("6) Mostrar libros en copia de pila\n\n");
		printf("0) Salir\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &r);
		_clrscr();
		switch(r){
			case 1:
				agregarLibro(&p);
				break;
			case 2:
				mostrarLibros(&p);
				break;
			case 3:
				modificarLibro(&p);
				break;
			case 4:
				eliminarLibro(&p);
				break;
			case 5:
				copiarPila(&copia, &p);
				break;
			case 6:
				mostrarLibros(&copia);
				break;
			case 0:
				printf("Terminando ejecucion");
				_getch();
				break;
			default:
				printf("Opcion incorrecta");
				_getch();
				break;
		}
	}while (r!=0);

}

//Operaciones de pila
void inicializarPila(struct Pila **p){
	p=0;
}

void apilar(struct Pila **p, struct Libro l){
	struct Pila *nuevo=malloc(sizeof(struct Pila));	//Genera nuevo nodo
	nuevo->dato=l;		//Asigna libro a "nuevo"
	nuevo->ps=*p;		//Apunta el ps de "nuevo" a la cabecera de pila
	*p=nuevo;			//Apunta la cabecera de pila a "nuevo"
}

void desapilar(struct Pila **p, struct Libro *l){
	struct Pila *aux=*p; //Defino aux porque trabajando sobre **p no logra
	*l= aux->dato;	 	 //entenderse con dato a la derecha de ->
	//obtenerlibro(*p, l);
	*p=aux->ps;
	free(aux);
}

//void obtenerlibro(struct Pila *p, struct Libro *l){
//	*l=p->dato;		//Obtengo el libro de la cabecera de pila
//}

int esVacia(struct Pila *p){
	int vacia;
	if (p==0){
		vacia= 1;	//Es vacia = TRUE
	}
	else{
		vacia= 0;	//Es vacia = FALSE
	}

	return vacia;
}

void copiarPila(struct Pila **p1, struct Pila **p2){
	struct Pila *aux=0;	//Declaro aux de pila. Si no lo hacemos NIL, rompera mas abajo
	struct Libro l;
	if (esVacia(*p2)){
		printf("La pila esta vacia");
	}
	else{
		while (!esVacia(*p2)){	//Desapilo pila original y apilo en aux
			desapilar(p2, &l);
			apilar(&aux, l);
		}
		while (!esVacia(aux)){	//Desapilo aux y apilo en pila original y copia 
			desapilar(&aux, &l);
			apilar(p1, l);
			apilar(p2, l);
		}
		printf("Copia de pila realizada con exito");
	}
	_getch();
	_clrscr();
}

//Operaciones del programa
void cargarLibro (struct Libro *l){
	printf("Ingrese ISBN: ");
	scanf("%d", &l->isbn);
	_clrscr();
	printf("Ingrese titulo: ");
	scanf("%s", l->titulo);
	_clrscr();
	printf("Ingrese autor: ");
	scanf("%s", l->autor);
	_clrscr();
	printf("Ingrese genero: ");
	scanf("%s", l->genero);
	_clrscr();
	printf("Ingrese precio: ");
	scanf("%f", &l->precio);
	_clrscr();
}

void agregarLibro(struct Pila **p){
	struct Libro l;
	cargarLibro(&l);
	apilar(p, l);		//Apila el libro cargado
	printf("Libro cargado");
	_getch();
	_clrscr();
}

void mostrarLibros(struct Pila **p){
	struct Pila *aux=0;
	struct Libro l;
	int i=1;
	if (esVacia(*p)){
		printf("La pila esta vacia");
		_getch();
	}
	else{
		while (!esVacia(*p)){
			desapilar(p, &l);	//Obtiene libro de la pila
			printf("LIBRO %d\n------------\n", i);
			printf("ISBN: %d\n", l.isbn);
			printf("Titulo: %s\n", l.titulo);
			printf("Autor: %s\n", l.autor);
			printf("Genero: %s\n", l.genero);
			printf("Precio: %.2f\n", l.precio);
			printf("-----------------------\n\n");
			_getch();
			i++;
			apilar(&aux, l);
		}
		while (!esVacia(aux)){	//Desapilo y apilo nuevamente para no dejar invertidos a los elementos
			desapilar(&aux, &l);
			apilar(p, l);
		}
	}
	_clrscr();
}

void modificarLibro(struct Pila **p){
	struct Pila *aux=0;
	struct Libro l;
	int encontro=0;
	int isbn;
	if (esVacia(*p)){
		printf("La pila esta vacia");
		_getch();
	}
	else{
		printf("Ingrese ISBN de libro a modificar: ");
		scanf("%d", &isbn);
		_clrscr();
		while (!esVacia(*p)){
			desapilar(p, &l);
			if (l.isbn!=isbn){	//Si no cumple la condicion, lo vuelvo a apilar
				apilar(&aux, l);
			}
			else{				//Si cumple tengo que modificarlo
				encontro=1;
				printf("Preparando para procesar nuevos datos\n");
				cargarLibro(&l);	//Modifico el libro
				apilar(&aux, l);	//Apilo con el libro modificado

			}
		}
		while (!esVacia(aux)){	//Desapilo y apilo nuevamente para no dejar invertidos a los elementos
			desapilar(&aux, &l);
			apilar(p, l);
		}
		if (encontro == 0){
			printf("No se encontro libro con ISBN %d", isbn);
		}
		else{
			printf("Libro modificado con exito");
		}
		_getch();
		_clrscr();
	}
}

void eliminarLibro(struct Pila **p){
	struct Pila *aux=0;
	struct Libro l;
	int encontro=0;
	int isbn;
	if (esVacia(*p)){
		printf("La pila esta vacia");
		_getch();
	}
	else{
		printf("Ingrese ISBN de libro a eliminar: ");
		scanf("%d", &isbn);
		_clrscr();
		while (!esVacia(*p)){
			desapilar(p, &l);
			if (l.isbn!=isbn){	//Si no cumple la condicion, lo vuelvo a apilar
				apilar(&aux, l);
			}
			else{
				encontro=1;
			}
		}
		while (!esVacia(aux)){	//Desapilo y apilo nuevamente para no dejar invertidos a los elementos
			desapilar(&aux, &l);
			apilar(p, l);
		}
		if (encontro == 0){
			printf("No se encontro libro con ISBN %d", isbn);
		}
		else{
			printf("Libro eliminado con exito");
		}
		_getch();
		_clrscr();
	}
}
