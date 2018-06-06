/****************************************************************************
 *                                                                          *
 * Filename: archivo2.c                                                     *
 *                                                                          *
 * Purpose : Ejemplo de uso de archivos en Standard C.                      *
 *                                                                          *
 * History : Fecha                                                          *
 *           13-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//En el ejemplo anterior vimos como escribir y leer un archivo en forma secuencial, ahora veremos como
//operarlo con acceso directo. Esto nos dara varias ventajas, como el uso de "fseek" para encontrar un
//elemento n.
//
//La funcion que ya mencionamos anteriormente, "fseek", coloca el puntero del archivo en el elemento
//que queremos obtener, para luego leerlo facilmente con un fread. El fseek funciona de la siguiente
//forma:
//
//	fseek(Archivo, Offset, Whence);
//
//-Archivo: 	Es el puntero al archivo, nuestra  variable asignada al archivo.
//-Offset:		Es la cantidad de bytes a saltear hasta llegar a nuestro elemento. Se calcula como n*sizeof(elemento),
//				donde n es el numero de elemento que queremos obtener (n=0 nos retorna el primer elemento, n=1 el segundo,
//				y asi).
//-Whence:		O posicion inicial, es la posicion del archivo desde donde haremos el desplazamiento hasta nuestro
//				elemento, siendo 0 el inicio del archivo (BOF - Beginning Of File).
//
//Para este ejercicio, trabajaremos ya con una lista de personas, la cual cargaremos para luego guardar en un archivo
//y mostrar dichos datos guardados.


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Persona{
	char nombre[20];
	int edad;
	int dni;

};

struct Lista{			//Defino la lista
	struct Persona dato;
	struct Lista *ps;
};

void cargarPersona(struct Persona *p);
void inicializarLista(struct Lista **l);
void insertarOrdenado(struct Lista **l, struct Persona p);

//---MAIN------------------------------------------------

int main(){
	struct Lista *L;
	struct Lista *aux;	//Para recorrer la lista y almacenar en el archivo
	struct Persona p;
	int i, valorSEEK;	//Para usar en el FSEEK
	FILE *archivo;	//Defino mi archivo
	
	inicializarLista(&L);
	printf("Iniciando carga de 5 personas\n");
	for (int i=0; i<5; i++){
		printf("Persona %d\n----\n", i+1);
		cargarPersona(&p);
		insertarOrdenado(&L, p);
	}

	//Recorro la lista y almaceno cada elemento en el archivo
	archivo = fopen("archivos/ejemplo2.dat", "w");	//Abro mi archivo en modo escritura
	aux= L;
	while (aux != 0){
		p= aux->dato;
		fwrite(&p, sizeof(struct Persona), 1, archivo);
		aux= aux->ps;
	}
	fclose(archivo);
	//El archivo ya esta cargado, recorro el mismo en modo lectura para obtener los datos
	archivo = fopen("archivos/ejemplo2.dat", "r");
	printf("Datos cargados en el archivo:\n-----------------\n");
	i=1;
    while(fread(&p, sizeof(struct Persona), 1, archivo)){
        printf ("Elemento %d:\n--Nombre = %s\n--Edad = %d\n--DNI: %d\n\n", i, p.nombre, p.edad, p.dni);
		i++;
		_getch();
	}

	//Como es un archivo de acceso directo, podemos usar la funcion FSEEK
	printf("Ingrese que persona desea visualizar (1-5): ");
	scanf("%d", &valorSEEK);
	_clrscr();
	valorSEEK--;	//Le decremento un valor porque el archivo lista de 0-4, no de 1-5
	fseek(archivo, valorSEEK*sizeof(struct Persona), 0);
	if (fread(&p, sizeof(struct Persona), 1, archivo) == 0){
		printf("La persona de posicion %d no existe", valorSEEK);
	}
	else{
		printf ("Eligio persona %d:\n\n--Nombre = %s\n--Edad = %d\n--DNI: %d\n\n", valorSEEK+1, p.nombre, p.edad, p.dni);
	}
	_getch();
	_clrscr();
}	

//-------------------------------------------------------

void cargarPersona(struct Persona *p){
	printf("Ingrese nombre: ");
	scanf("%s", p->nombre);	//String, sin ampersand
	_clrscr();
	printf("Ingrese edad: ");
	scanf("%d", &p->edad); 
	_clrscr();
	printf("Ingrese DNI: ");
	scanf("%d", &p->dni);
	_clrscr();
}

void inicializarLista(struct Lista **l){
	*l= 0;
}

void insertarOrdenado(struct Lista **l, struct Persona p){
	struct Lista *nuevo=malloc(sizeof(struct Lista));	//Defino el nuevo nodo
	struct Lista *ant;	//Defino el nodo anterior
	struct Lista *act;	//Defino el nodo actual
	nuevo->dato=p;		//Cargo persona en nuevo
	nuevo->ps=0;		//Inicializo ps de nuevo en NIL
	if (*l==0){			//La lista esta vacia, no hace falta moverme
		*l=nuevo;
	}
	else{				//La lista no esta vacia, busco el punto de insercion
		ant=0;			//Puntero al nodo anterior
		act=*l;			//Puntero al nodo actual
		while ((act!=0) && (act->dato.nombre < nuevo->dato.nombre)){
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

