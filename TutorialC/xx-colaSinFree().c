/****************************************************************************
 *                                                                          *
 * Filename: 20-colaSinFree().c                                    			*
 *                                                                          *
 * Purpose : Ejemplo de uso de listas tipo cola en Standard C.              *
 *                                                                          *
 * History : Fecha                                                          *
 *           18-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Similar al ejemplo anterior, en este ejercicio veremos como operar una lista bajo el modo de acceso FIFO, es decir,
//una cola.
//
//Recordando las operaciones de una cola:
//
//	- Encolar		-> Inserta un elemento al principio de la cola.
//	- Desencolar	-> Desencola el ultimo elemento de la cola.
// 	- Es vacía		-> Retorna TRUE si la cola no tiene elementos, FALSE caso contrario.
//	- Copiar cola	-> Genera una copia de la cola de trabajo.
//
//Como dato para la cola, usaremos un registro "proceso" con sus respectivos datos.
//
//Nuevamente, el objetivo del ejemplo es realizar un ABM con menu de opciones para poder aplicar todas
//las funciones de cola.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Proceso{			//El proceso que almacena la cola
	int id;
	char nombre[20];
	char prioridad[15];
	char estado[15];
};

struct lCola{			//Definicion de la lista de la cola
	struct Proceso dato;
	struct lCola *ps;
};

struct Cola{			//El registro que maneja los punteros de cola
	struct lCola *pini;	// - Puntero al inicio
	struct lCola *pfin;	// - Puntero al final
};


//Operaciones de pila
void inicializarCola(struct Cola *c);
void encolar(struct Cola *c, struct Proceso p);
void desencolar(struct Cola *c, struct Proceso *p);
int esVacia(struct Cola c);
void copiarCola(struct Cola *cola1, struct Cola *cola2);

void obtenerProceso(struct Cola c, struct Proceso *p);

//Operaciones del programa
void cargarProceso (struct Proceso *p);
void agregarProceso(struct Cola *c);
void mostrarProcesos(struct Cola c);
void modificarProceso(struct Cola *c);
void eliminarProceso(struct Cola *c);

int main(){
	struct Cola c;			//La cola de trabajo
	struct Cola copia;		//La copia de la pila de trabajo
	int r;					//Respuesta para el menu
	inicializarCola(&c);
	inicializarCola(&copia);
	do{
		printf("MENU PRINCIPAL\n");
		printf("----------------\n");
		printf("1) Agregar proceso\n");
		printf("2) Mostrar procesos\n");
		printf("3) Modificar proceso\n");
		printf("4) Eliminar proceso\n");
		printf("5) Generar copia de cola\n");
		printf("6) Mostrar procesos en copia de cola\n\n");
		printf("0) Salir\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &r);
		_clrscr();
		switch(r){
			case 1:
				agregarProceso(&c);
				break;
			case 2:
				mostrarProcesos(c);
				break;
			case 3:
				modificarProceso(&c);trata
				break;
			case 4:
				eliminarProceso(&c);
				break;
			case 5:
				copiarCola(&copia, &c);
				break;
			case 6:
				mostrarProcesos(copia);
				break;
			default:
				break;
		}
		_clrscr();
	}while (r!=0);
	return 0;

}

void inicializarCola(struct Cola *c){
	c->pini=0;
	c->pfin=0;
}

void encolar(struct Cola *c, struct Proceso p){
	struct lCola *nuevo=malloc(sizeof(struct lCola));	//Genera nuevo nodo
	nuevo->dato= p;
	nuevo->ps= c->pini;
	c->pini= nuevo;		//Corrijo el puntero al primer nodo
	if (c->pfin == 0){	//Es el primer elemento, por ende el final
		c->pfin= nuevo;		//Corrijo el ultimo nodo
	}
}

void desencolar(struct Cola *c, struct Proceso *p){
	struct lCola *aux=malloc(sizeof(struct lCola));	//Defino aux
	*p= c->pfin->dato;		//Retorno el dato del ultimo nodo
	if (c->pini == c->pfin){	//Es el unico elemento
		c->pini= 0;
		c->pfin= 0;
	}
	else{
		aux= c->pini;
		while (aux->ps != c->pfin){	//Recorro hasta el anteultimo elemento
			aux= aux->ps;
		}
		c->pfin= aux;	//Redefino el ultimo nodo con el anteultimo
		//aux= aux->ps;
		//c->pfin->ps= 0;
	}
	//free(aux);		//Elimino el ultimo nodo
}

int esVacia(struct Cola c){
	int vacia;
	if (c.pini==0){
		vacia= 1;	//Es vacia = TRUE
	}
	else{
		vacia= 0;	//Es vacia = FALSE
	}
	return vacia;
}

void copiarCola(struct Cola *cola1, struct Cola *cola2){
	struct Cola aux;	//Declaro cola auxiliar
	struct Proceso p;
	inicializarCola(&aux);
	if (esVacia(*cola2)){
		printf("La cola esta vacia");
	}
	else{
		while (!esVacia(*cola2)){	//Desapilo pila original y apilo en aux
			desencolar(cola2, &p);
			encolar(cola1, p);
			encolar(&aux, p);
		}
		*cola2= aux;	//Reensamblo la cola original
	}
}

//Operaciones del programa
void cargarProceso (struct Proceso *p){
	printf("Ingrese ID: ");
	scanf("%d", &p->id);
	_clrscr();
	printf("Ingrese nombre: ");
	scanf("%s", p->nombre);
	_clrscr();
	printf("Ingrese prioridad: ");
	scanf("%s", p->prioridad);
	_clrscr();
	printf("Ingrese estado: ");
	scanf("%s", p->estado);
	_clrscr();
}

void agregarProceso(struct Cola *c){
	struct Proceso p;
	cargarProceso(&p);
	encolar(c, p);		//Encola el proceso cargado
	printf("Proceso cargado");
	_getch();
	_clrscr();
}
void mostrarProcesos(struct Cola c){
	struct Proceso p;
	int i=1;
	if (esVacia(c)){
		printf("La cola esta vacia");
		_getch();
	}
	else{
		while(!esVacia(c)){
			desencolar(&c, &p);	//Obtiene proceso de la cola
			printf("PROCESO %d\n------------\n", i);
			printf("ID: %d\n", p.id);
			printf("Nombre: %s\n", p.nombre);
			printf("Prioridad: %s\n", p.prioridad);
			printf("Estado: %s\n", p.estado);
			printf("-----------------------\n\n");
			_getch();
			i++;
		}
	}
	_clrscr();
}

void modificarProceso(struct Cola *c){
	struct Cola aux;
	struct Proceso p;
	int encontro=0;
	int id;
	inicializarCola(&aux);
	if (esVacia(*c)){
		printf("La cola esta vacia");
		_getch();
	}
	else{
		printf("Ingrese ID de libro a modificar: ");
		scanf("%d", &id);
		_clrscr();
		while (!esVacia(*c)){
			desencolar(c, &p);
			if (p.id!=id){	//Si no cumple la condicion, lo vuelvo a encolar
				encolar(&aux, p);
			}
			else{				//Si cumple tengo que modificarlo
				encontro=1;
				printf("Preparando para procesar nuevos datos\n");
				cargarProceso(&p);	//Modifico el proceso
				encolar(&aux, p);	//Encolo con el proceso modificado

			}
		}
		*c=aux;
		if (encontro == 0){
			printf("No se encontro proceso con ID %d", id);
		}
		else{
			printf("Proceso modificado con exito");
		}
		_getch();
		_clrscr();
	}
}

void eliminarProceso(struct Cola *c){
	struct Cola aux;
	struct Proceso p;
	int encontro=0;
	int id;
	inicializarCola(&aux);
	if (esVacia(*c)){
		printf("La cola esta vacia");
		_getch();
	}
	else{
		printf("Ingrese ID del proceso a eliminar: ");
		scanf("%d", &id);
		_clrscr();
		while (!esVacia(*c)){
			desencolar(c, &p);
			if (p.id!=id){		//Si no cumple la condicion, lo vuelvo a encolar
				encolar(&aux, p);
			}
			else{
				encontro=1;
			}
		}
		*c=aux;	//Vuelvo a ensamblar la cola original, sin el elemento borrado
		if (encontro == 0){
			printf("No se encontro proceso con ID %d", id);
		}
		else{
			printf("Proceso eliminado con exito");
		}
		_getch();
		_clrscr();
	}
}
